/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:32:37 by phhofman          #+#    #+#             */
/*   Updated: 2025/09/08 13:58:24 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#include <string>

enum class EScalarType
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    INVALID
};

enum class EPseudoLiteral
{
    NAN_D,
    POS_INF,
    NEG_INF,
    NANF,
    POS_INFF,
    NEG_INFF,
    NONE
};
std::ostream &operator<<(std::ostream &os, EScalarType type);
EPseudoLiteral getPseudoLiteral(const std::string &value);
void printChar(char c, EPseudoLiteral pl);
void printInt(int i, EPseudoLiteral pl);
void printFloat(float f);
void printDouble(double d);