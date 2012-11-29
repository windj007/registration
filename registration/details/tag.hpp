#ifndef REGISTRATION_DETAILS_TAG_HPP
#define REGISTRATION_DETAILS_TAG_HPP

#include "config.hpp"

#define REG_DECL_TAG(tag, tspec) \
    namespace REG_TOP_NS { namespace REG_WORK_DECL_NS { \
        tspec \
        struct tag {}; \
    } }

#define REG_GET_TAG(tag, targs) REG_WORK_NS::tag<targs>

#endif // REGISTRATION_DETAILS_TAG_HPP