/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:32:37 by phhofman          #+#    #+#             */
/*   Updated: 2025/09/09 13:47:31 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#include <string>

enum class e_scalarType
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    INVALID
};

enum class e_pseudoLiteral
{
    NAN_D,
    POS_INF,
    NEG_INF,
    NANF,
    POS_INFF,
    NEG_INFF,
    NONE
};
std::ostream &operator<<(std::ostream &os, e_scalarType type);
e_pseudoLiteral getPseudoLiteral(const std::string &value);
void printChar(char c, e_pseudoLiteral pl);
void printInt(int i, e_pseudoLiteral pl);
void printFloat(float f);
void printDouble(double d);