/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:15:19 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/10/08 07:48:49 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>

typedef struct 
{
	std::string name;
	std::string mother_name;
	std::string father_name;
	std::string brother_name;
	std::string sister_name;
	int salary;
	int age;
	double avg_1;
	double avg_2;
	double avg_3;
	double avg_4;
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