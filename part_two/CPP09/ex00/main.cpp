/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:33:33 by lleciak           #+#    #+#             */
/*   Updated: 2025/02/28 12:08:00 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitcoinExchange.hpp"

int    main(int argc, char* argv[]){

	std::map<std::string, long double>  data;

	if (argc != 2){
		std::cout << "Invalid input." <<std::endl;
		return 0;
	}
	data = store_data();
	get_result(data, argv[1]);
	return (1);
}