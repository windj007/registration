#ifndef REGISTRATION_DETAILS_ACCESS_HPP
#define REGISTRATION_DETAILS_ACCESS_HPP

#include "traits.hpp"

namespace REG_TOP_NS
{
namespace REG_WORK_DECL_NS
{
    
template<typename ...TArgs>
struct access_t;

} // namespace REG_WORK_DECL_NS
} // namespace REG_TOP_NS


#define REG_GET_ACCESS_NAME(tag, targs) access_t< REG_GET_TAG(tag, targs) >

#define REG_GET_ACCESS(tag, targs) REG_WORK_NS::REG_GET_ACCESS_NAME(tag, targs)

#define REG_DECL_ACCESS(tag, tspec, targs) \
    namespace REG_TOP_NS { namespace REG_WORK_DECL_NS { \
        tspec \
        struct REG_GET_ACCESS_NAME(tag, targs) \
        { \
            template<typename TType> \
            static REG_GET_TRAITS(tag, targs)::reg_key_type get_key(const TType &obj) \
                { return obj.__register_get_key(); } \
        }; \
    } }

#endif // REGISTRATION_DETAILS_ACCESS_HPP