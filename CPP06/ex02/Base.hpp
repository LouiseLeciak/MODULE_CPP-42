/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 08:40:25 by lleciak           #+#    #+#             */
/*   Updated: 2025/02/19 13:51:03 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP


class Base {
public:
	virtual ~Base() {};
};

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif
