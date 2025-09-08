/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:24:06 by phhofman          #+#    #+#             */
/*   Updated: 2025/09/05 14:50:07 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

std::ostream &operator<<(std::ostream &os, EScalarType type)
{
    switch (type)
    {
    case EScalarType::INT:
        return os << "INT";
    case EScalarType::CHAR:
        return os << "CHAR";
    case EScalarType::FLOAT:
        return os << "FLOAT";
    case EScalarType::DOUBLE:
        return os << "DOUBLE";
    case EScalarType::INVALID:
        return os << "INVALID";
    default:
        return os << "Unkwnon type";
    }
}

EPseudoLiteral getPseudoLiteral(const std::string &value)
{
    if (value == "nan")
        return EPseudoLiteral::NAN_D;
    if (value == "+inf")
        return EPseudoLiteral::POS_INF;
    if (value == "-inf")
        return EPseudoLiteral::NEG_INF;
    if (value == "nanf")
        return EPseudoLiteral::NANF;
    if (value == "+inff")
        return EPseudoLiteral::POS_INFF;
    if (value == "-inff")
        return EPseudoLiteral::NEG_INFF;
    return EPseudoLiteral::NONE;
}

void printChar(char c, EPseudoLiteral pl)
{
    std::cout << "Char     : ";
    if (pl != EPseudoLiteral::NONE)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(c))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << c << std::endl;
}

void printInt(int i, EPseudoLiteral pl)
{
    std::cout << "Int       : ";
    if (pl != EPseudoLiteral::NONE)
        std::cout << "impossible" << std::endl;
    else
        std::cout << i << std::endl;
}

void printFloat(float f)
{
    std::cout << "Float     : ";
    if (std::floor(f) == f)
        std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    else
        std::cout << std::defaultfloat << f << "f" << std::endl;
}

void printDouble(double d)
{
    std::cout << "Double    : ";
    if (std::floor(d) == d)
        std::cout << std::fixed << std::setprecision(1) << d << std::endl;
    else
        std::cout << std::defaultfloat << d << std::endl;
}