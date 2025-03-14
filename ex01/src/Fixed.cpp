/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: eeklund <eeklund@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/16 10:35:36 by elleneklund   #+#    #+#                 */
/*   Updated: 2025/03/14 15:40:04 by eeklund       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed() : _fixedPoint(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int integerValue) : _fixedPoint(integerValue * 256) {
	std::cout << "int constructor called" << std::endl;
}

Fixed::Fixed(const float floatValue) {
	std::cout << "float constructor called" << std::endl;
	_fixedPoint =  (floatValue * 256.0f);
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
		this->_fixedPoint = F._fixedPoint;
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed& F)
{
	// std::cout << "output stream assignment operator called" << std::endl;
	os << F.toFloat(); 
	return (os);
}

float	Fixed::toFloat( void ) const
{
	// int		integer;
	// float	fractional;
	float	rational;

	// integer = toInt();
	// fractional = (_fixedPoint & ((1 << _fractionalBits) - 1)) * (1.0f / (1 << _fractionalBits));
	// rational = integer + fractional;
	rational = (float)_fixedPoint / (1 << _fractionalBits);
	return (rational);
}

int Fixed::toInt( void ) const
{
	int result;

	result = _fixedPoint >> _fractionalBits;
	return (result);
}