/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 14:04:42 by phhofman          #+#    #+#             */
/*   Updated: 2025/09/04 15:02:14 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {};

ScalarConverter::ScalarConverter(const ScalarConverter &other) : ScalarConverter()
{
    (void)other;
}

const ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {};

std::ostream &operator<<(std::ostream &os, SCALARTYPES type)
{
    switch (type)
    {
    case INT:
        return os << "INT";
    case FLOAT:
        return os << "FLOAT";
    case DOUBLE:
        return os << "DOUBLE";
    case INVALID:
        return os << "INVALID";
    default:
        return os << "Unknwon type";
    }
}

void displayChar(char c)
{
    std::cout << "char: ";
    if (!std::isprint(c))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << c << std::endl;
}

bool isNumber(const std::string &s)
{
    try
    {
        std::stod(s);
        return true;
    }
    catch (std::invalid_argument &)
    {
        return false;
    }
    catch (std::out_of_range &)
    {
        return false;
    }
}

// void displayPrimitaveTypes(char c, int i, float f, double d)
// {

//     displayChar(c);
//     std::cout << "float :" << f << std::endl;
//     std::cout << "double :" << d << std::endl;
// }

SCALARTYPES getScalarType(const std::string &value)
{
    size_t len = value.length();

    // Char check
    if (len == 1 && !std::isdigit(value[0]))
        return CHAR;

    // Int check
    if (value.find('.') == std::string::npos && isNumber(value))
        return INT;

    // Float check
    if (value.back() == 'f' && isNumber(value.substr(0, len - 1)))
        return FLOAT;

    // Double check
    if (isNumber(value))
        return DOUBLE;

    return INVALID;
}

void ScalarConverter::convert(std::string value)
{
    std::cout << getScalarType(value) << std::endl;
}
