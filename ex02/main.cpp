/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 08:51:06 by phhofman          #+#    #+#             */
/*   Updated: 2025/09/08 16:00:44 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <random>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
    Base *randomPointer;
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dist(1, 3);

    switch (dist(gen))
    {
    case 1:
        randomPointer = new A();
        break;
    case 2:
        randomPointer = new B();
        break;
    case 3:
        randomPointer = new C();
        break;

    default:
        break;
    }
    return randomPointer;
}

void identify(Base *p)
{
    A *a = dynamic_cast<A *>(p);
    if (a)
    {
        std::cout << "Type: A" << std::endl;
        return;
    }
    B *b = dynamic_cast<B *>(p);
    if (b)
    {
        std::cout << "Type: B" << std::endl;
        return;
    }
    C *c = dynamic_cast<C *>(p);
    if (c)
    {
        std::cout << "Type: C" << std::endl;
        return;
    }
}

void identify(Base &p)
{
    try
    {
        A &a = dynamic_cast<A &>(p);
        (void)a;
        std::cout << "Type: A" << std::endl;
        return;
    }
    catch (std::bad_cast &)
    {
    }

    try
    {
        B &b = dynamic_cast<B &>(p);
        (void)b;
        std::cout << "Type: B" << std::endl;
        return;
    }
    catch (std::bad_cast &)
    {
    }

    try
    {
        C &c = dynamic_cast<C &>(p);
        (void)c;
        std::cout << "Type: C" << std::endl;
        return;
    }
    catch (std::bad_cast &)
    {
    }
}

int main(void)
{
    std::cout << "===== Test 1: Random Generation =====" << std::endl;

    // Generate multiple random objects and identify
    for (int i = 0; i < 5; i++)
    {
        Base *p = generate();
        std::cout << "Object " << i + 1 << ": ";
        identify(p);
        delete p;
    }

    std::cout << "\n===== Test 2: Manual Creation =====" << std::endl;

    // Manually create A
    Base *a = new A();
    std::cout << "Created: A -> ";
    identify(a);
    delete a;

    // Manually create B
    Base *b = new B();
    std::cout << "Created: B -> ";
    identify(b);
    delete b;

    // Manually create C
    Base *c = new C();
    std::cout << "Created: C -> ";
    identify(c);
    delete c;

    std::cout << "\n===== Test 3: Identification via Reference =====" << std::endl;

    // Manually create objects
    A a_obj;
    B b_obj;
    C c_obj;

    // Identify by reference
    std::cout << "Reference test - A: ";
    identify(a_obj); // Base& parameter

    std::cout << "Reference test - B: ";
    identify(b_obj); // Base& parameter

    std::cout << "Reference test - C: ";
    identify(c_obj); // Base& parameter

    std::cout << "\n===== All Tests Completed =====" << std::endl;
    return 0;
}