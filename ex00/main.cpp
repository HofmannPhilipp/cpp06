/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 08:51:06 by phhofman          #+#    #+#             */
/*   Updated: 2025/09/08 10:48:47 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <string>
#include <iostream>

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <argument>\n";
        return 1;
    }
    std::string input = argv[1];
    ScalarConverter::convert(input);
}