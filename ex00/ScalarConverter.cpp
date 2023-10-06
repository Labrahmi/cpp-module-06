/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:16:30 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/10/06 18:32:36 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

double ScalarConverter::double_form = 0.0;
float ScalarConverter::float_form = 0.0f;
char ScalarConverter::char_form = 0;
int ScalarConverter::int_form = 0;
char ScalarConverter::sign = 'p';
literal_type ScalarConverter::type = e_ERR;

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

literal_type ScalarConverter::setLetType(std::string &string)
{
	size_t pos;
	ScalarConverter::sign = 'p';
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
				ScalarConverter::sign = 'n';
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

void ScalarConverter::store_char(std::string &string)
{
	char value = static_cast<char>(string[0]);
	ScalarConverter::char_form = static_cast<char>(value);
	ScalarConverter::int_form = static_cast<int>(value);
	ScalarConverter::float_form = static_cast<float>(value);
	ScalarConverter::double_form = static_cast<double>(value);
}
void ScalarConverter::store_int(std::string &string)
{
	int value;
	int sign = static_cast<int>((ScalarConverter::sign == 'p') ? 1 : -1);
	if ((string == "2147483648") && (sign == -1))
		value = static_cast<int>(-2147483648);
	else
	{
		int int_prototype;
		std::stringstream ss(string);
		if (ss >> int_prototype)
			value = static_cast<int>(std::strtol(string.c_str(), NULL, 10) * sign);
		else
		{
			std::cout << "Unexpected error while storing an integer, program exited!" << std::endl;
			exit(EXIT_FAILURE);
		}
	}
	ScalarConverter::char_form = static_cast<char>(0);
	if (value >= 0 && value <= 255)
		ScalarConverter::char_form = static_cast<char>(value);
	ScalarConverter::int_form = static_cast<int>(value);
	ScalarConverter::float_form = static_cast<float>(value);
	ScalarConverter::double_form = static_cast<double>(value);
}

void ScalarConverter::store_float(std::string &string)
{
	float float_prototype;
	float value;
	int sign = static_cast<int>((ScalarConverter::sign == 'p') ? 1 : -1);
	std::stringstream ss(string.substr(0, string.length() - 1));
	if (ss >> float_prototype)
	{
		value = static_cast<float>(std::strtol(string.c_str(), NULL, 10) * sign);
		std::cout << value << "\n";
		exit(10);
	}
	else
	{
		std::cout << "Unexpected error while storing a float, program exited!" << std::endl;
		exit(EXIT_FAILURE);
	}
	ScalarConverter::char_form = static_cast<char>(0);
	if (value >= 0 && value <= 255)
		ScalarConverter::char_form = static_cast<char>(value);
	ScalarConverter::int_form = static_cast<int>(value);
	ScalarConverter::float_form = static_cast<float>(value);
	ScalarConverter::double_form = static_cast<double>(value);
}
void ScalarConverter::store_double(std::string &string)
{
	double double_prototype;
	double value;
	int sign = static_cast<int>((ScalarConverter::sign == 'p') ? 1 : -1);
	std::stringstream ss(string);
	if (ss >> double_prototype)
	{
		value = static_cast<double>(std::strtol(string.c_str(), NULL, 10) * sign);
	}
	else
	{
		std::cout << "Unexpected error while storing a double, program exited!" << std::endl;
		exit(EXIT_FAILURE);
	}
	ScalarConverter::char_form = static_cast<char>(0);
	if (value >= 0 && value <= 255)
		ScalarConverter::char_form = static_cast<char>(value);
	ScalarConverter::int_form = static_cast<int>(value);
	ScalarConverter::float_form = static_cast<float>(value);
	ScalarConverter::double_form = static_cast<double>(value);
}

void ScalarConverter::print_literal(void)
{
	std::string dot_zero;
	if ((ScalarConverter::float_form) == (static_cast<int>(ScalarConverter::float_form)))
		dot_zero = ".0";
	if (isprint(ScalarConverter::char_form))
		std::cout << "char:   " << ScalarConverter::char_form << std::endl;
	else
		std::cout << "char:   " << "Non displayable" << std::endl;
	std::cout << "int:    " << ScalarConverter::int_form << std::endl;
	std::cout << "float:  " << ScalarConverter::float_form << dot_zero << "f" << std::endl;
	std::cout << "double: " << ScalarConverter::double_form << std::endl;
}

void ScalarConverter::convert(std::string string)
{
	ScalarConverter::type = ScalarConverter::setLetType(string);
	switch (ScalarConverter::type)
	{
	case e_CHAR:
		ScalarConverter::store_char(string);
		break;
	case e_INT:
		ScalarConverter::store_int(string);
		break;
	case e_FLOAT:
		ScalarConverter::store_float(string);
		break;
	case e_DOUBLE:
		ScalarConverter::store_double(string);
		break;
	case e_ERR:
		std::cout << "Invalid Literal Format!" << std::endl;
		exit(EXIT_FAILURE);
	}
	print_literal();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */