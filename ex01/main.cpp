/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 08:51:06 by phhofman          #+#    #+#             */
/*   Updated: 2025/09/08 13:25:37 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "data.hpp"
#include <string>
#include <iostream>

int main(void)
{
    Data d;

    d.age = 27;
    d.name = "Philipp";

    std::cout << "Data pointer address  :" << &d << std::endl;
    uintptr_t raw = Serializer::serialize(&d);
    std::cout << "Data serialized       :" << raw << std::endl;
    std::cout << "Data deserialized     :" << Serializer::deserialize(raw) << std::endl;
}