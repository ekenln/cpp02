/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: eeklund <eeklund@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/16 10:35:36 by elleneklund   #+#    #+#                 */
/*   Updated: 2025/03/20 12:06:21 by eeklund       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed() : _fixedPoint(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int integerValue) : _fixedPoint(integerValue << _fractionalBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatValue) {
	std::cout << "Float constructor called" << std::endl;
	_fixedPoint =  roundf((floatValue * (1 << _fractionalBits)));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& F)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = F;
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

std::ostream& operator<<(std::ostream& os, const Fixed& F)
{
	os << F.toFloat(); 
	return (os);
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

float	Fixed::toFloat( void ) const
{
	float	rational;

	rational = (float)_fixedPoint / (1 << _fractionalBits);
	return (rational);
}

int Fixed::toInt( void ) const
{
	int result;

	result = _fixedPoint >> _fractionalBits;
	return (result);
}
