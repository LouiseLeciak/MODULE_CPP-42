/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:38:33 by lleciak           #+#    #+#             */
/*   Updated: 2025/02/17 11:38:50 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"

uintptr_t Serializer::serialize(Data *ptr){
    return (reinterpret_cast<uintptr_t>(ptr));
}
Data*   Serializer::deserialize(uintptr_t raw){
    return (reinterpret_cast<Data *>(raw));
}