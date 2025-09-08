/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:52:56 by phhofman          #+#    #+#             */
/*   Updated: 2025/09/05 14:42:54 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>
#include "utils.hpp"

class ScalarConverter
{
private:
    ScalarConverter();

public:
    ScalarConverter(const ScalarConverter &other);
    const ScalarConverter &operator=(const ScalarConverter &other);
    ~ScalarConverter();
    static void convert(std::string value);
};