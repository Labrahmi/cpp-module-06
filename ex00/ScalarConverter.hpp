/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:16:35 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/10/06 18:28:09 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

typedef enum
{
	e_CHAR,
	e_INT,
	e_FLOAT,
	e_DOUBLE,
	e_ERR
} literal_type;

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(ScalarConverter const &src);
	static double double_form;
	static float float_form;
	static char char_form;
	static int int_form;
	static char sign;
	static literal_type type;
	//
	static void store_char(std::string &string);
	static void store_int(std::string &string);
	static void store_float(std::string &string);
	static void store_double(std::string &string);
	static void print_literal(void);
	static literal_type setLetType(std::string &string);
	//
public:
	~ScalarConverter();
	ScalarConverter &operator=(ScalarConverter const &rhs);
	//
	static void convert(std::string string);
	//
};

#endif /* ************************************************* SCALARCONVERTER_H */