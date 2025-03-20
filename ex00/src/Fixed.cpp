/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: eeklund <eeklund@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/16 10:35:36 by elleneklund   #+#    #+#                 */
/*   Updated: 2025/03/20 11:55:39 by eeklund       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed() : _fixedPoint(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& F) : _fixedPoint(F.getRawBits())
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& F)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &F)
	{
		this->_fixedPoint = F.getRawBits();
	}
	return (*this);
}

void Fixed::setRawBits( int const raw )
{
	this->_fixedPoint = raw;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixedPoint);
}
