#ifndef REGISTRATION_DETAIL_REG_CLS_HPP
#define REGISTRATION_DETAIL_REG_CLS_HPP

#include "traits.hpp"
#include "access.hpp"
#include "keys.hpp"
#include "tag.hpp"

#define REG_REGISTER(tag, key_type, value_type) \
    REG_DECL_TAG(tag) \
    REG_DECL_TRAITS(tag, key_type, value_type) \
    REG_DECL_ACCESS(tag)

#define REG_BASE_CLASS(tag, type) \
    private: \
        virtual REG_GET_TRAITS(tag)::reg_key_type __register_get_key() const = 0; \
        friend struct REG_GET_ACCESS(tag);

#define REG_CLASS_IMPL(tag, type, key_value, ...) \
    class type; \
    REG_DECL_KEYS_STRUCT(tag, type, key_value, __VA_ARGS__)

#define REG_CLASS(tag, type) \
    private: \
        virtual REG_GET_TRAITS(tag)::reg_key_type __register_get_key() const \
            { return REG_GET_KEYS_STRUCT(tag, type)::key; }\
        friend struct REG_GET_ACCESS(tag);

#define REG_GET_INFO(tag, key) \
    REG_GET_REGISTER(tag).get(key)

#define REG_GET_KEY(tag, object) \
    REG_GET_ACCESS(tag)::get_key(object)

#define REG_IS_REG(tag, key) \
    REG_GET_REGISTER(tag).is_registered(key)


#endif // REGISTRATION_DETAIL_REG_CLS_HPP