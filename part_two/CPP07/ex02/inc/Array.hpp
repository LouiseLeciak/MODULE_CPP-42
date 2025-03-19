/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:08:12 by lleciak           #+#    #+#             */
/*   Updated: 2025/03/19 14:40:21 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
    public:
        Array(): _size(0), _array(_size){};
        Array(unsigned int n){
			_size = n;
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++){
				_array[i] = T();
			}};
        ~Array(){delete[] this->_array;};
		unsigned int size() const {return(this->_size);};
        Array(const Array& copy)
		{
			delete[] _array;
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
			if (i >= this->_size)
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