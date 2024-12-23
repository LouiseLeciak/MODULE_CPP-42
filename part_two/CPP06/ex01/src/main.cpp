/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 08:14:17 by lleciak           #+#    #+#             */
/*   Updated: 2024/12/23 08:27:18 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"
#include "../inc/Data.hpp"

int main(void){
    Data        data;
    uintptr_t   raw;
    Data*       ptr;


    data.c  = '@';
    data.i  = 2;
    data.s  = "Hello world!";

    raw = Serializer::serialize(&data);
    ptr = Serializer::deserialize(raw);
    
    std::cout << "char: " << ptr->c << std::endl;
    std::cout << "int: " << ptr->i << std::endl;
    std::cout << "string: " << ptr->s << std::endl;
}