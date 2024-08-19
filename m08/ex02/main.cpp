/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:55:52 by apimikov          #+#    #+#             */
/*   Updated: 2024/08/19 12:59:53 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <forward_list>
#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
 
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
 
    mstack.pop();
    std::cout << mstack.size() << std::endl;
 
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
 
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack);
    std::stack<int> new_mut;
    new_mut = s;
    new_mut.push(42);
    std::cout << "mstack.size()=" << mstack.size() << std::endl;
    std::cout << "new_mut.size()=" << new_mut.size() << std::endl;

    
    return 0;
}