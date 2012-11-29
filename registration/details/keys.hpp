#ifndef REGISTRATION_DETAILS_KEYS_HPP
#define REGISTRATION_DETAILS_KEYS_HPP

#include "traits.hpp"
#include "tag.hpp"
#include "register.hpp"

namespace REG_TOP_NS
{
namespace REG_WORK_DECL_NS
{

template<typename TTag, typename TType>
struct register_keys_t;

} // namespace REG_WORK_DECL_NS
} // namespace REG_TOP_NS

#define REG_GET_KEYS_STRUCT_NAME(tag, type) register_keys_t< REG_GET_TAG(tag), type >
#define REG_GET_KEYS_STRUCT(tag, type) REG_WORK_NS::REG_GET_KEYS_STRUCT_NAME(tag, type)

#define REG_DECL_KEYS_STRUCT(tag, type, key_value, ...) \
    namespace REG_TOP_NS { namespace REG_WORK_DECL_NS { \
        template<> \
        struct REG_GET_KEYS_STRUCT_NAME(tag, type) \
        { \
            static REG_GET_TRAITS(tag)::reg_key_type key; \
            static int serial; \
        }; \
        REG_GET_TRAITS(tag)::reg_key_type REG_GET_KEYS_STRUCT_NAME(tag, type)::key = key_value; \
        int REG_GET_KEYS_STRUCT_NAME(tag, type)::serial = REG_CALL_REG(tag, key_value, __VA_ARGS__); \
    } }

#endif // REGISTRATION_DETAILS_KEYS_HPP