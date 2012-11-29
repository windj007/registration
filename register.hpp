#ifndef REGISTER_HPP
#define REGISTER_HPP


#include <boost/preprocessor/cat.hpp>

// ************************** common macros ************************************



// *********************** classes registration ********************************


// *********************** template registration *******************************
#define REGISTER_TEMPLATE_REGISTER(tag, key_type, template_args, type_name, value_type) \
    template<template_args> class type_name; \
    REGISTER_DECLARE_TAG(tag) \
    REGISTER_DECLARE_REG_TRAITS_TMPL(tag, template<template_args>, key_type, value_type) \
    REGISTER_DECLARE_ACCESS_TMPL(tag)

#define REGISTER_TEMPLATE_REGISTER_IMPL(tag, template_args) \
    private: static REGISTER_GET_TRAITS(tag)<template_args> __register_instantiate_tmpl_traits;

#define REGISTER_TEMPLATE(tag) \
    private: static int __register_serial_ ## tag

#define REGISTER_TEMPLATE_IMPL(tag, template_params, impl_type, reg_info_type, key, ...) \
    template<template_params> int impl_type::__register_serial_ ## tag = \
        REGISTER_CALL_REG(tag, REGISTER_DEFAULT_KEY_TYPE, reg_info_type, key, __VA_ARGS__)


#endif // REGISTER_HPP
