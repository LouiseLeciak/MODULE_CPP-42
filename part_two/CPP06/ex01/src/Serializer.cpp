/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:38:33 by lleciak           #+#    #+#             */
/*   Updated: 2025/02/19 12:34:37 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"

uintptr_t Serializer::serialize(Data *ptr){
	uintptr_t	p = reinterpret_cast<uintptr_t>(ptr);
    return (p);
}
Data*   Serializer::deserialize(uintptr_t raw){
	Data*	d = reinterpret_cast<Data*>(raw);
    return (d);
}