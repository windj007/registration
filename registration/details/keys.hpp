#ifndef REGISTRATION_DETAILS_KEYS_HPP
#define REGISTRATION_DETAILS_KEYS_HPP

#include "traits.hpp"
#include "tag.hpp"
#include "register.hpp"

namespace REG_TOP_NS
{
namespace REG_WORK_DECL_NS
{

template<typename ... TArgs>
struct register_keys_t;

} // namespace REG_WORK_DECL_NS
} // namespace REG_TOP_NS

#define REG_GET_KEYS_STRUCT_NAME(tag, targs, type) register_keys_t< REG_GET_TAG(tag, targs), type >
#define REG_GET_KEYS_STRUCT(tag, targs, type) REG_WORK_NS::REG_GET_KEYS_STRUCT_NAME(tag, targs, type)

#define REG_DECL_KEYS_STRUCT(tag, tspec, targs, type, key_value, ...) \
    namespace REG_TOP_NS { namespace REG_WORK_DECL_NS { \
        tspec \
        struct REG_GET_KEYS_STRUCT_NAME(tag, targs, type) \
        { \
            static REG_GET_TRAITS(tag, targs)::reg_key_type key; \
            static int serial; \
        }; \
        tspec REG_GET_TRAITS(tag, targs)::reg_key_type REG_GET_KEYS_STRUCT_NAME(tag, targs, type)::key = key_value; \
        tspec int REG_GET_KEYS_STRUCT_NAME(tag, targs, type)::serial = REG_CALL_REG(tag, targs, key_value, __VA_ARGS__); \
    } }

#endif // REGISTRATION_DETAILS_KEYS_HPP