# CppDependencyInjection

This project is created for an [article](https://medium.com/@zdonik/effective-dependency-injection-in-cpp-debc030f23ae) I have written on Medium. It showcases different ways dependency injection can be effectively achieved using C++.

The methods that are explored here are:

* Interface inheritance
* Template parameter
* Concepts
* Proxy
* CRTP

## Structure

The main project is itself divided into multiple subprojects, each implementing the described dependency injection methods.

Each subproject contains source files and tests. The functionality is written with the help of TDD and tests reflect that.
