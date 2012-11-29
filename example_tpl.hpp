#ifndef EXAMPLE_TPL_HPP
#define EXAMPLE_TPL_HPP

#include "register.hpp"

// ******************************** interface **********************************
struct fact_tpl_tag {};

template<
    typename TTraits
>
class IFactory
{
public:
    typedef IFactory<TTraits>           this_type;

    virtual std::string work() const = 0;

//     REGISTER_BASE_(
//           fact_tpl_tag
//         , this_type
//     );
};

// ******************************** factory 1 **********************************
template<
    typename TTraits
>
class TplFactory1
    : public IFactory<TTraits>
{
public:
    typedef TTraits                     traits_type;
    typedef IFactory<traits_type>       base_type;
    typedef TplFactory1<traits_type>    this_type;

    virtual std::string work() const
    {
        return "Tpl1";
    }

    REGISTER_TEMPLATE(fact_tpl_tag);
};

REGISTER_TEMPLATE_IMPL(
      fact_tpl_tag
    , REGISTER_UTILS_QUOTE(typename TTraits)
    , TplFactory1<TTraits>
    , boost::shared_ptr< IFactory<TTraits> >
    , "tpl_factory_1"
)

// ******************************** factory 2 **********************************
template<
    typename TTraits
>
class TplFactory2
    : public IFactory<TTraits>
{
public:
    typedef TTraits                     traits_type;
    typedef IFactory<traits_type>       base_type;
    typedef TplFactory2<traits_type>    this_type;

    virtual std::string work() const
    {
        return "Tpl2";
    }

    REGISTER_TEMPLATE(fact_tpl_tag);
};

REGISTER_TEMPLATE_IMPL(
      fact_tpl_tag
    , REGISTER_UTILS_QUOTE(typename TTraits)
    , TplFactory2<TTraits>
    , boost::shared_ptr< IFactory<TTraits> >
    , "tpl_factory_2"
)

#endif // EXAMPLE_TPL_HPP
