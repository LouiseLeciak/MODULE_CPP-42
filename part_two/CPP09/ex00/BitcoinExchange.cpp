/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:26:50 by lleciak           #+#    #+#             */
/*   Updated: 2025/02/28 13:56:53 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <stdlib.h>
#include <sstream>

long double price(long double value, long double demand) {
    if (value == 0.0 || demand == 0.0)
        return (0.0);
    return (value * demand);
}

long double my_strtold(std::string str)
{
	std::stringstream stm(str);
	long double ld;
    
	stm >> ld;
	return (ld);
};


std::map<std::string, long double>store_data()
{
    std::string					        line;
    std::ifstream                       infile("./data.csv");
    std::map<std::string, long double>  data;
    
    infile.is_open();
	if (!infile.is_open()){
		std::cerr << "error opening file." << std::endl;
	}
	while (std::getline(infile, line, '\n')){
        data[line.substr(0, line.find(","))] = my_strtold(line.substr(line.find(",") + 1, std::string::npos));
    }
	infile.close();
    return (data);
}

long double get_price(std::map<std::string, long double> data, std::string line){
    std::map<std::string, long double>::iterator i = data.begin();
    std::string date = line.substr(0, line.find(" | "));
    long double demand = my_strtold(line.substr(line.find(" | ") + 3, std::string::npos));
    long double value = 0.0;
    
	while (i != data.end()){
        if (i->first >= date){
            if (i->first > date)
                i--;
            value = i->second;
            return(price(value, demand));
        }
        i++;
    }
    return(-1);
}

bool	valid_date(std::string date)// if false "error date not available"
{
	std::string tmp = date.substr(0, date.find("-"));
    
	if (my_strtold(tmp) < 2009 || date < "2009-01-02")
		return false;
	tmp = date.substr(date.find("-") + 1, 2);
	if (my_strtold(tmp) < 0 || my_strtold(tmp) > 12)
		return false;
	tmp = date.substr(date.find("-") + 1, 5);
	tmp = tmp.substr(tmp.find("-") + 1, tmp.find("-"));
	if (my_strtold(tmp) < 0 || my_strtold(tmp) > 31)
		return false;
	return true;
};

int invalid_demand(std::string line){
    std::string demand = line.substr(line.find(" | ") + 3,  std::string::npos);
    if (my_strtold(demand) > 1000)
        return -1;
    if (my_strtold(demand) < 0)
        return -2;
    return (0);
}

void	get_result(std::map<std::string, long double> data, char *text){
    std::ifstream   demand(text);
    std::string     line;
    int             i = 0;

    demand.is_open();
	if (!demand.is_open()){
		std::cerr << "error opening file." << std::endl;}
    std::cout << "date | value" << std::endl;
    while (demand.good())
    {
        std::getline(demand, line);
        if (i > 0 && valid_date(line.substr(0, line.find(" | ")))){
            if (i > 0 && invalid_demand(line) == -1)
                std::cout << "Error: too large a number." << std::endl;
            else if (i > 0 && invalid_demand(line) == -2)
                std::cout << "Error: not a positive number." << std::endl;
            else
                {std::cout << line.substr(0, line.find(" | "));
                std::cout << " => " << line.substr(line.find(" | ") + 3,  std::string::npos);
                std::cout << " = " << get_price(data, line) << std::endl;}
        }
        else if (i > 0)
            std::cout << "Error: Bad input => " << line.substr(0, line.find(" | ")) << std::endl;
        line.clear();
        i++;
    }
}
