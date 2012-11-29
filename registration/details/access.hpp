#ifndef REGISTRATION_DETAILS_ACCESS_HPP
#define REGISTRATION_DETAILS_ACCESS_HPP

#include "traits.hpp"

#define REG_GET_ACCESS_NAME(tag) REG_GET_DECL_NAME(access, tag)

#define REG_GET_ACCESS(tag) REG_WORK_NS::REG_GET_ACCESS_NAME(tag)

#define REG_DECL_ACCESS(tag) \
    namespace REG_TOP_NS { namespace REG_WORK_DECL_NS { \
        struct REG_GET_ACCESS_NAME(tag) \
        { \
            template<typename TType> \
            static REG_GET_TRAITS(tag)::reg_key_type get_key(const TType &obj) \
                { return obj.__register_get_key(); } \
        }; \
    } }

#endif // REGISTRATION_DETAILS_ACCESS_HPP