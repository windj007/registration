#ifndef REGISTRATION_DETAILS_ERRORS_HPP
#define REGISTRATION_DETAILS_ERRORS_HPP

#include "config.hpp"

#include <stdexcept>

namespace REG_TOP_NS
{
namespace REG_DETAILS_NS
{

class register_error
    : public std::runtime_error
{
public:
    typedef std::runtime_error                  base_type;

    register_error(const std::string &what)
        : base_type(what)
    { }
};

} // namespace REG_DETAILS_NS
} // namespace REG_TOP_NS

#endif // REGISTRATION_DETAILS_ERRORS_HPP