registration
============

Header-only C++ library for type registration and performing basic reflection.

Idea of the library was inspired by boost::serialization and its BOOST_EXPORT_CLASS mechanism.

Features:
1) associate some meaningful information with a type in declarative manner (type registration)
2) getting information by id that was specified during registration
3) getting id by object reference
4) getting information by object reference
5) templates registration (type is registered when a template is instantiated) - now in development

Disadwantages:
1) registration process requires a macro to be called from within a type declaration
  (so using that library one could not simply register a type without it declaration).
2) registered types are required to be of object-type.

For examples see example_cls.hpp example_tmp.hpp and main.cpp