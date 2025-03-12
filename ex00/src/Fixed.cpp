/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elleneklund <elleneklund@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/16 10:35:36 by elleneklund   #+#    #+#                 */
/*   Updated: 2025/03/12 10:47:08 by elleneklund   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed() : _fixedPoint(4) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& F) : _fixedPoint(F._fixedPoint)
{
	std::cout << "Copy constructor called" << std::endl;
	// _fixedPoint = F._fixedPoint;
}

Fixed& Fixed::operator=(const Fixed& F)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &F)
	{
		this->_fixedPoint = F.getRawBits(); // why not just F._fixedPoint
	}
	return (*this);
}

void Fixed::setRawBits( int const raw )
{
	this->_fixedPoint = raw;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits function called" << std::endl;
	return (_fixedPoint);
}

float	Fixed::getFloat( void ) const
{
	float	rational;

	rational = _fixedPoint / pow(2.0f ,_fractionalBits);
	return (rational);
}

