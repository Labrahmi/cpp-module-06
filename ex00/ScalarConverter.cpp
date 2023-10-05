/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:16:30 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/10/05 18:10:15 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>

typedef enum
{
	e_CHAR,
	e_INT,
	e_FLOAT,
	e_DOUBLE,
	e_ERR
} literal_type;

typedef struct s_literal
{
	double double_form;
	float float_form;
	char char_form;
	int int_form;
	char sign;
	literal_type type;
} t_literal;

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScalarConverter::~ScalarConverter()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs)
{
	if (this != &rhs)
	{
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

int check_err(std::string &string)
{
	int i = 0;
	int f_count = 0;
	int dot_count = 0;
	int strange_count = 0;
	int gen_err = 0;
	while (string[i])
	{
		if (string[i] == 'f')
			f_count++;
		if (string[i] == '.')
			dot_count++;
		if (((string[i] >= '0' && string[i] <= '9') == 0) && string[i] != '.' && string[i] != 'f')
			strange_count++;
		i++;
	}
	gen_err = (string[i - 1]) && (string[i - 1] == '.');
	return ((strange_count > 0) || (f_count > 1) || (dot_count > 1) || (gen_err));
}

literal_type setLetType(std::string &string, t_literal &literal)
{
	size_t pos;
	literal.sign = 'p';
	if (string.length() == 1)
	{
		if (string[0] >= '0' && string[0] <= '9')
			return e_INT;
		return e_CHAR;
	}
	else if (string.length() > 1)
	{
		if (string[0] == '-' || string[0] == '+')
		{
			if (string.length() == 1)
				return e_ERR;
			if (string[0] == '-')
				literal.sign = 'n';
			string = string.substr(1, (string.length() - 1));
		}
		if (check_err(string))
			return e_ERR;
		if (string.find(".") == std::string::npos)
		{
			if (string.find("f") != std::string::npos)
				return e_ERR;
			return e_INT;
		}
		else
		{
			pos = string.find("f");
			if (pos == std::string::npos)
			{
				if (string[0] == '.')
					return e_ERR;
				return e_DOUBLE;
			}
			else
			{
				if (string[pos - 1] && string[pos - 1] == '.')
					return e_ERR;
				return e_FLOAT;
			}
		}
	}
	return e_ERR;
}

void store_char(t_literal &literal, std::string &string)
{
	char value = string[0];
	literal.char_form = static_cast<char>(value);
	literal.int_form = static_cast<int>(value);
	literal.float_form = static_cast<float>(value);
	literal.double_form = static_cast<double>(value);
}
void store_int(t_literal &literal, std::string &string)
{
	int sign = (literal.sign == 'p') ? 1 : -1;
	int value = std::stoi(string) * (sign);
	literal.char_form = static_cast<char>(value);
	literal.int_form = static_cast<int>(value);
	literal.float_form = static_cast<float>(value);
	literal.double_form = static_cast<double>(value);
}
void store_float(t_literal &literal, std::string &string)
{
	int sign = (literal.sign == 'p') ? 1 : -1;
	float value = std::stod(string) * (sign);
	literal.char_form = static_cast<char>(value);
	literal.int_form = static_cast<int>(value);
	literal.float_form = static_cast<float>(value);
	literal.double_form = static_cast<double>(value);
}
void store_double(t_literal &literal, std::string &string)
{
	int sign = (literal.sign == 'p') ? 1 : -1;
	double value = std::stod(string) * (sign);
	literal.char_form = static_cast<char>(value);
	literal.int_form = static_cast<int>(value);
	literal.float_form = static_cast<float>(value);
	literal.double_form = static_cast<double>(value);
}

void print_literal(t_literal &literal)
{
	if (isprint(literal.char_form))
		std::cout << "char:   " << literal.char_form << std::endl;
	else
		std::cout << "char:   " << "Non displayable" << std::endl;
	std::cout << "int:    " << literal.int_form << std::endl;
	std::cout << "float:  " << literal.float_form << std::endl;
	std::cout << "double: " << literal.double_form << std::endl;
}

void ScalarConverter::convert(std::string string)
{
	t_literal literal;
	literal.type = setLetType(string, literal);
	switch (literal.type)
	{
	case e_CHAR:
		store_char(literal, string);
		break;
	case e_INT:
		store_int(literal, string);
		break;
	case e_FLOAT:
		store_float(literal, string);
		break;
	case e_DOUBLE:
		store_double(literal, string);
		break;
	case e_ERR:
		std::cout << "Invalid Literal Format!" << std::endl;
		return;
		break;
	}
	print_literal(literal);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */