/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:24:06 by phhofman          #+#    #+#             */
/*   Updated: 2025/09/09 13:50:17 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

std::ostream &operator<<(std::ostream &os, e_scalarType type)
{
    switch (type)
    {
    case e_scalarType::INT:
        return os << "INT";
    case e_scalarType::CHAR:
        return os << "CHAR";
    case e_scalarType::FLOAT:
        return os << "FLOAT";
    case e_scalarType::DOUBLE:
        return os << "DOUBLE";
    case e_scalarType::INVALID:
        return os << "INVALID";
    default:
        return os << "Unkwnon type";
    }
}

e_pseudoLiteral getPseudoLiteral(const std::string &value)
{
    if (value == "nan")
        return e_pseudoLiteral::NAN_D;
    if (value == "+inf")
        return e_pseudoLiteral::POS_INF;
    if (value == "-inf")
        return e_pseudoLiteral::NEG_INF;
    if (value == "nanf")
        return e_pseudoLiteral::NANF;
    if (value == "+inff")
        return e_pseudoLiteral::POS_INFF;
    if (value == "-inff")
        return e_pseudoLiteral::NEG_INFF;
    return e_pseudoLiteral::NONE;
}

void printChar(char c, e_pseudoLiteral pl)
{
    std::cout << "Char      : ";
    if (pl != e_pseudoLiteral::NONE)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(c))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << c << std::endl;
}

void printInt(int i, e_pseudoLiteral pl)
{
    std::cout << "Int       : ";
    if (pl != e_pseudoLiteral::NONE)
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
        std::cout << f << "f" << std::endl;
}

void printDouble(double d)
{
    std::cout << "Double    : ";
    if (std::floor(d) == d)
        std::cout << std::fixed << std::setprecision(1) << d << std::endl;
    else
        std::cout << d << std::endl;
}