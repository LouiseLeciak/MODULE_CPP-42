/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:08:12 by lleciak           #+#    #+#             */
/*   Updated: 2024/12/18 12:27:09 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
    public:
        Array(): _size(0), _array(size){};
        Array(unsigned int n): _size(n), _array(new T[n]){};
        ~Array(){delete[] this->_array;};
		unsigned int size() const {return(this->_size);};
        Array(const Array& copy)
		{
			this->_array = NULL;
			*this = copy;
		};
        Array &operator=(const Array& copy)
		{
			if (this->_array)
				delete [] this->_array;
			if (copy.size() > 0)
			{
				this->_size = copy.size();
				this->_array = new T[copy.size()];
				for (unsigned int i = 0; i < copy.size(); i++)
					this->_array[i] = copy._array[i];
			}
			return (*this);
		};
        T &operator[](unsigned int i)
		{
			if (i < 0 || i >= this->_size)
				throw OutOfBoundException();
			return (this->_array[i]);
		};

            class OutOfBoundException: public std::exception
            {
                public:
                    const char* what() const throw(){return "Exception: index out of bound.";};
            };
    private:
        unsigned int _size;
        T*  _array;
};

#endif