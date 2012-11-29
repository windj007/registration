#ifndef REGISTRATION_DETAILS_REGISTER_HPP
#define REGISTRATION_DETAILS_REGISTER_HPP

#include "errors.hpp"
#include "singleton.hpp"

#include "traits.hpp"

#include <boost/thread/shared_mutex.hpp>
#include <boost/thread/locks.hpp>

#include <map>

namespace REG_TOP_NS
{
namespace REG_DETAILS_NS
{

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

    size_t reg(const key_type &key, const value_type &value)
    {
        if (is_registered(key))
            throw register_error(key + " is already registered!");

        unique_lock lock(m_info_mtx);
        m_info[key] = value;
        return m_info.size();
    }

    const value_type &get(const key_type &key) const
    {
        if (!is_registered(key))
            throw register_error(key + " is not registered!");

        shared_lock lock(m_info_mtx);
        return m_info[key];
    }

    value_type &get(const key_type &key)
    {
        if (!is_registered(key))
            throw register_error(key + " is not registered!");

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

    mutable mutex_type                                  m_info_mtx;
    std::map<key_type, value_type>                      m_info;
};

} // namespace REG_DETAILS_NS
} // namespace REG_TOP_NS

#define REG_GET_REGISTER(tag) \
    REG_UTILS_NS::Singleton< \
          REG_UTILS_NS::Register< \
              REG_GET_TAG(tag) \
            , REG_GET_TRAITS(tag)::reg_key_type \
            , REG_GET_TRAITS(tag)::reg_value_type \
          > \
    >::instance()

#define REG_CALL_REG(tag, key, ...) \
    REG_GET_REGISTER(tag).reg( \
          key \
        , REG_GET_TRAITS(tag)::reg_value_type(__VA_ARGS__) \
    )

#endif // REGISTRATION_DETAILS_REGISTER_HPP