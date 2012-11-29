#ifndef REGISTRATION_DETAILS_TAG_HPP
#define REGISTRATION_DETAILS_TAG_HPP

#include "config.hpp"

#define REG_DECL_TAG(tag) \
    namespace REG_TOP_NS { namespace REG_WORK_DECL_NS { \
        struct tag {}; \
    } }

#define REG_GET_TAG(tag) REG_WORK_NS::tag

#endif // REGISTRATION_DETAILS_TAG_HPP