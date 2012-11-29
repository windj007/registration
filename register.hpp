#ifndef REGISTER_HPP
#define REGISTER_HPP

#include "singleton.hpp"

#include <boost/shared_ptr.hpp>
#include <boost/thread/once.hpp>

#include <boost/thread/shared_mutex.hpp>
#include <boost/thread/locks.hpp>

#include <boost/preprocessor/cat.hpp>

#include <map>

template<class TTag, class TRegInfo >
struct register_traits_t;
template<
      typename TTag
    , typename TKey
    , typename TValue
>
class Register
{
public:
    typedef TTag                                        tag_type;
    typedef TKey                                        key_type;
    typedef TValue                                      value_type;
    typedef Register<tag_type, key_type, value_type>    this_type;
    typedef boost::shared_ptr<this_type>                ptr_type;

    size_t reg(const key_type &key, const value_type &value)
    {
        unique_lock lock(m_info_mtx);
        m_info[key] = value;
        return m_info.size();
    }

    const value_type &get(const key_type &key) const
    {
        shared_lock lock(m_info_mtx);
        return m_info[key];
    }

    value_type &get(const key_type &key)
    {
        shared_lock lock(m_info_mtx);
        return m_info[key];
    }

    bool is_registered(const key_type &key) const
    {
        shared_lock lock(m_info_mtx);
        return m_info.find(key) != m_info.end();
    }

private:
    typedef boost::shared_mutex                         mutex_type;
    typedef boost::unique_lock<mutex_type>              unique_lock;
    typedef boost::shared_lock<mutex_type>              shared_lock;

    mutex_type                                          m_info_mtx;
    std::map<key_type, value_type>                      m_info;
};

namespace registration {

namespace results {

template<typename TTag>
struct register_traits_t;

template<typename TTag, typename TType>
struct register_keys_t;

template<typename TTag>
struct access;

} // namespace results
} // namespace registration


// ************************** configuration ************************************
#define REGISTER_NS registration
#define REGISTER_DETAILS_NS results
#define REGISTER_RESULTS_NS ::REGISTER_NS::REGISTER_DETAILS_NS
#define REGISTER_REG_TRAITS_NAME register_traits_t

#define REGISTER_UTILS_QUOTE(...) __VA_ARGS__


// ************************** implementation ***********************************
#define REGISTER_GET_TAG(tag) REGISTER_RESULTS_NS::tag
#define REGISTER_GET_TRAITS(tag) \
    REGISTER_RESULTS_NS::REGISTER_REG_TRAITS_NAME< REGISTER_GET_TAG(tag) >

#define REGISTER_GET_REGISTER(tag) \
    Singleton< \
          Register< \
              REGISTER_GET_TAG(tag) \
            , REGISTER_GET_TRAITS(tag)::reg_key_type \
            , REGISTER_GET_TRAITS(tag)::reg_value_type \
          > \
    >::instance()

#define REGISTER_CALL_REG(tag, key, ...) \
    REGISTER_GET_REGISTER(tag).reg( \
          key \
        , REGISTER_GET_TRAITS(tag)::reg_value_type(__VA_ARGS__) \
    )

#define REGISTER_GET_KEYS_STRUCT(tag, type) \
    REGISTER_RESULTS_NS::register_keys_t<REGISTER_GET_TAG(tag), type>

#define REGISTER_GET_ACCESS(tag) \
    REGISTER_RESULTS_NS::access<REGISTER_GET_TAG(tag)>

// ************************** common macros ************************************
#define REGISTER_REGISTER(tag, key_type, value_type) \
    namespace REGISTER_NS { namespace REGISTER_DETAILS_NS { \
        struct tag {}; \
        template<> \
        struct register_traits_t<tag> \
        { \
            typedef key_type            reg_key_type; \
            typedef value_type          reg_value_type; \
        }; \
        template<> \
        struct access<REGISTER_GET_TAG(tag)> \
        { \
            template<typename TType> \
            static REGISTER_GET_TRAITS(tag)::reg_key_type get_key(const TType &obj) \
                { return obj.__register_get_key(); } \
        }; \
    } }

#define REGISTER_GET_INFO(tag, key) \
    REGISTER_GET_REGISTER(tag).get(key)

#define REGISTER_GET_KEY(tag, object) \
    REGISTER_GET_ACCESS(tag)::get_key(object)

#define REGISTER_IS_REG(tag, key) \
    REGISTER_GET_REGISTER(tag).is_registered(key)


// *********************** classes registration ********************************
#define REGISTER_BASE_CLASS(tag, type) \
    private: \
        virtual REGISTER_GET_TRAITS(tag)::reg_key_type __register_get_key() const = 0; \
        friend struct REGISTER_GET_ACCESS(tag);

#define REGISTER_CLASS(tag, type) \
    private: \
        virtual REGISTER_GET_TRAITS(tag)::reg_key_type __register_get_key() const \
            { return REGISTER_GET_KEYS_STRUCT(tag, type)::key; }\
        friend struct REGISTER_GET_ACCESS(tag);

        // REGISTER_GET_KEYS_STRUCT(tag, type)::register_key; } 

#define REGISTER_CLASS_IMPL(tag, type, key_value, ...) \
    class type; \
    namespace REGISTER_NS { namespace REGISTER_DETAILS_NS { \
        template<> \
        struct register_keys_t< REGISTER_GET_TAG(tag), type > \
        { \
            static REGISTER_GET_TRAITS(tag)::reg_key_type key; \
            static int serial; \
        }; \
        REGISTER_GET_TRAITS(tag)::reg_key_type register_keys_t< REGISTER_GET_TAG(tag), type >::key = key_value; \
        int register_keys_t< REGISTER_GET_TAG(tag), type >::serial = REGISTER_CALL_REG(tag, key_value, __VA_ARGS__); \
    } }

// *********************** template registration *******************************
#define REGISTER_TEMPLATE(tag) \
    private: static int __register_serial_ ## tag

#define REGISTER_TEMPLATE_IMPL(tag, template_params, impl_type, reg_info_type, key, ...) \
    template<template_params> int impl_type::__register_serial_ ## tag = \
        REGISTER_CALL_REG(tag, REGISTER_DEFAULT_KEY_TYPE, reg_info_type, key, __VA_ARGS__)


#endif // REGISTER_HPP
