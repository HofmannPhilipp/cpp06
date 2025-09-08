/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 14:04:42 by phhofman          #+#    #+#             */
/*   Updated: 2025/09/05 14:47:55 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {};

Serializer::Serializer(const Serializer &other) : Serializer()
{
    (void)other;
}

const Serializer &Serializer::operator=(const Serializer &other)
{
    (void)other;
    return *this;
}

Serializer::~Serializer() {};

uintptr_t Serializer::serialize(Data *ptr)
{
    uintptr_t res = reinterpret_cast<uintptr_t>(ptr);

    return res;
}

Data *Serializer::deserialize(uintptr_t raw)
{
    Data *ptr = reinterpret_cast<Data *>(raw);

    return ptr;
}