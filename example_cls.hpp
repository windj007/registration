#ifndef EXAMPLE_CLS_HPP
#define EXAMPLE_CLS_HPP

#include "register.hpp"

// ******************************** interface **********************************
class IClsFactory;

REGISTER_REGISTER(
      fact_cls_tag
    , std::string
    , boost::shared_ptr<IClsFactory>
);

class IClsFactory
{
public:
    virtual std::string work() const = 0;

    REGISTER_BASE_CLASS(fact_cls_tag, IClsFactory)
};


// ******************************** factory 1 **********************************
class ClsFactory1;

REGISTER_CLASS_IMPL(fact_cls_tag, ClsFactory1, "cls_factory_1")

class ClsFactory1
    : public IClsFactory
{
public:
    typedef IClsFactory                 base_type;

    std::string work() const
    {
        return "Cls1";
    }

    REGISTER_CLASS(fact_cls_tag, ClsFactory1)
};




// ******************************** factory 2 **********************************
class ClsFactory2;

REGISTER_CLASS_IMPL(fact_cls_tag, ClsFactory2, "cls_factory_2")

class ClsFactory2
    : public IClsFactory
{
public:
    typedef IClsFactory                 base_type;

    ClsFactory2(std::string value)
        : m_value(value)
    { }

    std::string work() const
    {
        return m_value + " Cls2";
    }
private:
    std::string m_value;

    REGISTER_CLASS(fact_cls_tag, ClsFactory2)
};




#endif // EXAMPLE_CLS_HPP
