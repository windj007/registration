#include <iostream>
#include <boost/serialization/export.hpp>
#include <boost/serialization/access.hpp>

#define TESTING_CLASSES
//#define TESTING_TEMPLATES


#if defined(TESTING_CLASSES)
#include "example_cls.hpp"

void cls_test()
{
    REG_GET_INFO(fact_cls_tag, "cls_factory_1").reset(new ClsFactory1());
    REG_GET_INFO(fact_cls_tag, "cls_factory_2").reset(new ClsFactory2("qweqweqwe"));

    std::cout << REG_GET_INFO(fact_cls_tag, "cls_factory_1")->work() << std::endl;
    std::cout << REG_GET_INFO(fact_cls_tag, "cls_factory_2")->work() << std::endl;

    ClsFactory1 cls;
    ClsFactory2 cls2("asdasdasd");
    std::cout << REG_GET_KEY(fact_cls_tag, cls) << " : "
        << REG_GET_INFO(fact_cls_tag, REG_GET_KEY(fact_cls_tag, cls))->work() << std::endl;
    std::cout << REG_GET_KEY(fact_cls_tag, cls2) << " : "
        << REG_GET_INFO(fact_cls_tag, REG_GET_KEY(fact_cls_tag, cls2))->work() << std::endl;
}
#endif

#if defined(TESTING_TEMPLATES)

void tpl_test()
{
     typedef int                                 traits_type;
     typedef IFactory<traits_type>               base_type;
     typedef boost::shared_ptr<base_type>        base_ptr_type;

     typedef TplFactory1<traits_type>            fact_1_type;
//     typedef TplFactory2<traits_type>            fact_2_type;
//
//     GET_REG_INFO(fact_tpl_tag, base_ptr_type, "tpl_factory_1").reset(new fact_1_type());
//     GET_REG_INFO(fact_tpl_tag, base_ptr_type, "tpl_factory_2").reset(new fact_2_type());
// //
//     std::cout << GET_REG_INFO(fact_tpl_tag, base_ptr_type, "tpl_factory_1")->work() << std::endl;
//     std::cout << GET_REG_INFO(fact_tpl_tag, base_ptr_type, "tpl_factory_2")->work() << std::endl;
}
#endif


int main()
{
#if defined(TESTING_CLASSES)
    cls_test();
#endif

#if defined(TESTING_TEMPLATES)
    tpl_test();
#endif
    return 0;
}
