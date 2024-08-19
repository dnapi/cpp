/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:41:41 by apimikov          #+#    #+#             */
/*   Updated: 2024/08/19 13:39:13 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template<typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container>
{
public:
	using iterator = typename std::stack<T>::container_type::iterator;
	using const_iterator = typename std::stack<T>::container_type::const_iterator;
	using reverse_iterator = typename std::stack<T>::container_type::reverse_iterator;

	MutantStack(void) = default;
	~MutantStack(void) = default;

	iterator	begin(void){
		return this->c.begin();
	}
	iterator	end(void){
		return this->c.end();
	}
	const_iterator	cbegin(void) const{
		return this->c.cbegin();
	}
	const_iterator	cend(void) const{
		return this->c.cend();
	}
private:
    MutantStack(const MutantStack &) = default;
    MutantStack& operator=(const MutantStack&) = default;
};


#endif
