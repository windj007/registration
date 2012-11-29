#ifndef REGISTRATION_DETAILS_SINGLETON_HPP
#define REGISTRATION_DETAILS_SINGLETON_HPP

#include "config.hpp"

#include <boost/shared_ptr.hpp>
#include <boost/thread/once.hpp>

namespace REG_TOP_NS
{
namespace REG_DETAILS_NS
{

template<
      typename T
>
class Singleton
{
public:
    typedef T                                           value_type;
    typedef Singleton<value_type>                       this_type;

    static value_type &instance()
    {
        boost::call_once(s_init_flag, &this_type::initialize);
        return *s_instance;
    }

private:
    typedef boost::shared_ptr<value_type>               value_ptr_type;

    static value_ptr_type                               s_instance;
    static boost::once_flag                             s_init_flag;

    Singleton()
    {
    }

    static void initialize()
    {
        s_instance.reset(new value_type());
    }
};

// rsuvorov: CWTFH: crazy-WTF-hack!!!
// as a result s_instance is initialized once in initialize()
// instead of twice in initialize and here
template<typename TType>
typename Singleton<TType>::value_ptr_type
Singleton<TType>::s_instance = Singleton<TType>::s_instance;

template<typename TType>
boost::once_flag
Singleton<TType>::s_init_flag;

} // namespace REG_DETAILS_NS
} // namespace REG_TOP_NS

#endif // REGISTRATION_DETAILS_SINGLETON_HPP
