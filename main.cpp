#include <iostream>
#include <string>
#include <sstream>
#include <ios>
#include <iterator>
#include <boost/iterator_adaptors.hpp>
#include <boost/serialization/export.hpp>
#include <boost/serialization/access.hpp>
#include <boost/preprocessor.hpp>

#include "example_cls.hpp"
//#include "example_tpl.hpp"

#define LIST(...) __VA_ARGS__
#define TEST(a, b) a = b



int main()
{
    REGISTER_GET_INFO(fact_cls_tag, "cls_factory_1").reset(new ClsFactory1());
    REGISTER_GET_INFO(fact_cls_tag, "cls_factory_2").reset(new ClsFactory2("qweqweqwe"));

    std::cout << REGISTER_GET_INFO(fact_cls_tag, "cls_factory_1")->work() << std::endl;
    std::cout << REGISTER_GET_INFO(fact_cls_tag, "cls_factory_2")->work() << std::endl;

    ClsFactory1 cls;
    ClsFactory2 cls2("asdasdasd");
    std::cout << REGISTER_GET_INFO(fact_cls_tag, REGISTER_GET_KEY(fact_cls_tag, cls) )->work() << std::endl;
//     std::cout << REGISTER_GET_INFO(fact_cls_tag, REGISTER_GET_KEY(fact_cls_tag, cls2))->work() << std::endl;
//     typedef int                                 traits_type;
//     typedef IFactory<traits_type>               base_type;
//     typedef boost::shared_ptr<base_type>        base_ptr_type;
//     
//     typedef TplFactory1<traits_type>            fact_1_type;
//     typedef TplFactory2<traits_type>            fact_2_type;
//     
//     GET_REG_INFO(fact_tpl_tag, base_ptr_type, "tpl_factory_1").reset(new fact_1_type());
//     GET_REG_INFO(fact_tpl_tag, base_ptr_type, "tpl_factory_2").reset(new fact_2_type());
// // 
//     std::cout << GET_REG_INFO(fact_tpl_tag, base_ptr_type, "tpl_factory_1")->work() << std::endl;
//     std::cout << GET_REG_INFO(fact_tpl_tag, base_ptr_type, "tpl_factory_2")->work() << std::endl;

    return 0;
}
