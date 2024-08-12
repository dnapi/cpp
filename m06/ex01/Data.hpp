/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 09:43:58 by apimikov          #+#    #+#             */
/*   Updated: 2024/08/12 09:44:01 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

class Data{
	public:
		int data;
		Data();
		Data(int);
		~Data();
		Data(const Data&);
		Data& operator=(const Data&);
};

#endif
