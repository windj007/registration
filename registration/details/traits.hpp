#ifndef REGISTRATION_DETAILS_TRAITS_HPP
#define REGISTRATION_DETAILS_TRAITS_HPP

#include "config.hpp"
#include "tag.hpp"

namespace REG_TOP_NS
{
namespace REG_WORK_DECL_NS
{

template<typename ...TArgs>
struct register_traits_t;

} // namespace REG_WORK_DECL_NS
} // namespace REG_TOP_NS

#define REG_GET_TRAITS_NAME(tag, targs) \
    register_traits_t<REG_GET_TAG(tag, targs), targs>

#define REG_GET_TRAITS(tag, targs) REG_WORK_NS::REG_GET_TRAITS_NAME(tag, targs)

#define REG_DECL_TRAITS(tag, key_type, value_type, tspec, targs) \
    namespace REG_TOP_NS { namespace REG_WORK_DECL_NS { \
        tspec \
        struct REG_GET_TRAITS_NAME(tag, targs) \
        { \
            typedef key_type            reg_key_type; \
            typedef value_type          reg_value_type; \
        }; \
    } }

#endif // REGISTRATION_DETAILS_TRAITS_HPP