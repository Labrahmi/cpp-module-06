/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:15:15 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/10/07 15:51:42 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer &src)
{
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Serializer::~Serializer()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Serializer &Serializer::operator=(Serializer const &rhs)
{
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

uintptr_t Serializer::serialize(Data* ptr)
{
	
}
Data* Serializer::deserialize(uintptr_t raw)
{
	
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */