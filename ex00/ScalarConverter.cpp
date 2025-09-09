/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 14:04:42 by phhofman          #+#    #+#             */
/*   Updated: 2025/09/09 13:06:20 by phhofman         ###   ########.fr       */
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

void displayChar(const std::string &value)
{
    char c = static_cast<char>(value[0]);
    int i = static_cast<int>(c);
    float f = static_cast<float>(c);
    double d = static_cast<double>(c);
    printChar(c, getPseudoLiteral(value));
    printInt(i, getPseudoLiteral(value));
    printFloat(f);
    printDouble(d);
}

void displayInt(const std::string &value)
{
    int i = static_cast<int>(std::stod(value));
    char c = static_cast<char>(i);
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);
    if (i < 0 || i > 127)
        printChar(c, EPseudoLiteral::NAN_D);
    else
        printChar(c, getPseudoLiteral(value));

    printInt(i, getPseudoLiteral(value));
    printFloat(f);
    printDouble(d);
}

void displayFloat(const std::string &value)
{

    float f = static_cast<float>(std::stod(value));
    int i = static_cast<int>(f);
    char c = static_cast<char>(f);
    double d = static_cast<double>(f);
    printChar(c, getPseudoLiteral(value));
    printInt(i, getPseudoLiteral(value));
    printFloat(f);
    printDouble(d);
}
void displayDouble(const std::string &value)
{

    double d = static_cast<double>(std::stod(value));
    float f = static_cast<float>(d);
    int i = static_cast<int>(d);
    char c = static_cast<char>(d);
    printChar(c, getPseudoLiteral(value));
    printInt(i, getPseudoLiteral(value));
    printFloat(f);
    printDouble(d);
}

bool isNumber(const std::string &s)
{
    try
    {
        size_t pos;
        std::stod(s, &pos);
        if (pos == s.length())
            return true;
        return false;
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

void displayPrimitaveTypes(std::string value, EScalarType type)
{
    if (type == EScalarType::CHAR)
    {
        displayChar(value);
    }
    if (type == EScalarType::INT)
    {
        displayInt(value);
    }
    if (type == EScalarType::FLOAT)
    {
        displayFloat(value);
    }
    if (type == EScalarType::DOUBLE)
    {
        displayDouble(value);
    }
}

EScalarType getScalarType(const std::string &value)
{
    size_t len = value.length();
    EPseudoLiteral pseudoLiteral = getPseudoLiteral(value);
    bool isNum = isNumber(value);
    size_t dotPos = value.find('.');

    // Char check
    if (len == 1 && !std::isdigit(value[0]))
        return EScalarType::CHAR;

    // Int check
    if (pseudoLiteral == EPseudoLiteral::NONE && dotPos == std::string::npos && isNum)
        return EScalarType::INT;

    // Float check
    if ((dotPos != std::string::npos || pseudoLiteral != EPseudoLiteral::NONE) && value.back() == 'f' && isNumber(value.substr(0, len - 1)))
        return EScalarType::FLOAT;

    // Double check
    if ((dotPos != std::string::npos || pseudoLiteral != EPseudoLiteral::NONE) && isNum)
        return EScalarType::DOUBLE;

    return EScalarType::INVALID;
}

void ScalarConverter::convert(std::string value)
{
    EScalarType type = getScalarType(value);
    if (type == EScalarType::INVALID)
    {
        std::cout << "Invalid value" << std::endl;
        return;
    }
    displayPrimitaveTypes(value, type);
}
