#ifndef REGISTRATION_DETAILS_CONFIG_HPP
#define REGISTRATION_DETAILS_CONFIG_HPP

#define REG_TOP_NS                      registration
#define REG_DETAILS_NS                  details
#define REG_WORK_DECL_NS                decl

#define REG_UTILS_NS                    ::REG_TOP_NS::REG_DETAILS_NS
#define REG_WORK_NS                     ::REG_TOP_NS::REG_WORK_DECL_NS

#define REG_GET_DECL_NAME(name, tag)    name ## _for_ ## tag

#endif // REGISTRATION_DETAILS_CONFIG_HPP