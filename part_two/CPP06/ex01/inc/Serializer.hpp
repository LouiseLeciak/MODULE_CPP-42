/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 07:19:24 by lleciak           #+#    #+#             */
/*   Updated: 2024/12/23 08:23:33 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <stdint.h>
#include <iostream>
#include "Data.hpp"

class Serializer{
    public:
        static uintptr_t   serialize(Data* ptr);
        static Data*       deserialize(uintptr_t raw);
    private:
        Serializer(){};
        ~Serializer(){};
        Serializer(Serializer &copy){(void)copy;};
        Serializer operator=(Serializer &copy){return copy;};
};

#endif