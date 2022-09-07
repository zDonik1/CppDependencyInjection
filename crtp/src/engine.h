/**************************************************************************
 *
 *   @author Doniyorbek Tokhirov <tokhirovdoniyor@gmail.com>
 *   @date 01/09/2022
 *
 *************************************************************************/

#pragma once

template<typename DerivedEngine>
class Engine
{
public:
    inline auto start() { return derived().start(); }

private:
    // private c-tor and derived friend prevents instantiation
    // and makes sure specialization of base class is of derived class
    // which prevents bugs like this: class Derived : public Base<OtherDerived> {}
    Engine() = default;
    friend DerivedEngine;

    inline auto &derived() { return static_cast<DerivedEngine &>(*this); }
};
