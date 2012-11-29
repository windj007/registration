#ifndef REGISTRATION_DETAILS_TRAITS_HPP
#define REGISTRATION_DETAILS_TRAITS_HPP

#include "config.hpp"

#define REG_GET_TRAITS_NAME(tag) REG_GET_DECL_NAME(register_traits, tag)

#define REG_GET_TRAITS(tag) REG_WORK_NS::REG_GET_TRAITS_NAME(tag)

#define REG_GET_TRAITS_TMPL(tag, args) REG_WORK_NS::REG_GET_TRAITS_NAME(tag)<args>

#define REG_DECL_TRAITS_TMPL(tag, key_type, value_type, template_spec) \
    namespace REG_TOP_NS { namespace REG_WORK_DECL_NS { \
        template_spec \
        struct REG_GET_TRAITS_NAME(tag) \
        { \
            typedef key_type            reg_key_type; \
            typedef value_type          reg_value_type; \
        }; \
    } }

#define REG_DECL_TRAITS(tag, key_type, value_type) \
    REG_DECL_TRAITS_TMPL(tag, key_type, value_type,)

#endif // REGISTRATION_DETAILS_TRAITS_HPP