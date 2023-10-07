/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:15:19 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/10/07 15:51:04 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>

typedef struct 
{
	std::string name;
	double cashMoney;
	int age;
} Data;


class Serializer
{
	
private:
	Serializer();
	Serializer(Serializer const &src);

public:
	~Serializer();
	Serializer &operator=(Serializer const &rhs);
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif /* ****************************************************** SERIALIZER_H */