/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 08:51:06 by phhofman          #+#    #+#             */
/*   Updated: 2025/09/09 13:14:04 by phhofman         ###   ########.fr       */
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

    std::cout << "Original address      : " << &d << std::endl;

    uintptr_t raw = Serializer::serialize(&d);
    std::cout << "Serialized (uintptr_t): " << raw << std::endl;

    Data *restored = Serializer::deserialize(raw);
    std::cout << "Restored address      : " << restored << std::endl;
    std::cout << "Restored content      : age=" << restored->age
              << ", name=" << restored->name
              << std::endl;
}