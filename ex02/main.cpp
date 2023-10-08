/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 08:12:28 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/10/08 09:03:09 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib> 
#include <iostream>

Base* generate(void)
{
    srand(time(0));
    int rand_class = (rand() % 3);
    // std::cout << rand_class << std::endl;
    Base *base = new A(); // default
    // 
    if (rand_class == 0)
        base = new A();
    if (rand_class == 1)
        base = new B();
    if (rand_class == 2)
        base = new C();
    // 
    return base;
}

void identify(Base* p)
{
    A *a;
    B *b;
    C *c;

    a = dynamic_cast<A*>(p);
    b = dynamic_cast<B*>(p);
    c = dynamic_cast<C*>(p);
    if (a)
        std::cout << "The Object Has Type : A" << std::endl;
    else if (b)
        std::cout << "The Object Has Type : B" << std::endl;
    else if (c)
        std::cout << "The Object Has Type : C" << std::endl;
    else    
        std::cout << "An error occurred while specifying the type!" << std::endl;
}

void identify(Base& p)
{
    char type = 'X';
    try
    {
        A& a = dynamic_cast<A&>(p);
        (void) a;
        type = 'A';
    }
    catch(const std::exception& e){}
    try
    {
        B& b = dynamic_cast<B&>(p);
        (void) b;
        type = 'B';
    }
    catch(const std::exception& e){}
    try
    {
        C& c = dynamic_cast<C&>(p);
        (void) c;
        type = 'C';
    }
    catch(const std::exception& e){}
    if (type != 'X')
        std::cout << "The Object Has Type : " << type << std::endl;
    else
        std::cout << "An error occurred while specifying the type!" << std::endl;
}

int main(void)
{
    Base *base;
    base = generate();
    identify(base);
    identify(*base);
    delete base;
    return 0;
}
