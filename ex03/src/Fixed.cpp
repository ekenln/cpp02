/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elleneklund <elleneklund@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/16 17:49:53 by elleneklund   #+#    #+#                 */
/*   Updated: 2025/02/16 21:09:51 by elleneklund   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPoint(0) {
	// std::cout << "default constructor called" << std::endl;
}

Fixed::Fixed(int integerValue) : _fixedPoint(integerValue * 256) {
	// std::cout << "int constructor called" << std::endl;
}

Fixed::Fixed(const float floatValue) {
	// std::cout << "float constructor called" << std::endl;
	_fixedPoint =  roundf(floatValue * 256.0f);
}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed& F) : _fixedPoint(F._fixedPoint) {
	std::cout << "copy constructor called" << std::endl;
}

int		Fixed::getFixedPoint( void ) const
{
	return (_fixedPoint);
}


std::ostream&	operator<<(std::ostream& stream, const Fixed& F) {
	stream << F.toFloat();
	return (stream);
}

bool	Fixed::operator>(const Fixed& F) const {
	return (this->_fixedPoint > F._fixedPoint);
}

bool	Fixed::operator<(const Fixed& F) const {
	return (this->_fixedPoint < F._fixedPoint);
}

bool	Fixed::operator>=(const Fixed& F) const {
	return (this->_fixedPoint >= F._fixedPoint);
}

bool	Fixed::operator<=(const Fixed& F) const {
	return (this->_fixedPoint <= F._fixedPoint);
}

bool	Fixed::operator==(const Fixed& F) const {
	return (this->_fixedPoint == F._fixedPoint);
}

bool	Fixed::operator!=(const Fixed& F) const {
	return (this->_fixedPoint != F._fixedPoint);
}


Fixed	Fixed::operator+(const Fixed& F) const {
	Fixed	result;

	result._fixedPoint = this->_fixedPoint + F._fixedPoint;
	return (result);
}

Fixed	Fixed::operator-(const Fixed& F) const {
	Fixed	result;

	result._fixedPoint = this->_fixedPoint - F._fixedPoint;
	return (result);
}

Fixed	Fixed::operator*(const Fixed& F) const {
	Fixed	result;

	result._fixedPoint = (this->_fixedPoint * F._fixedPoint) / 256;
	return (result);
}

Fixed	Fixed::operator/(const Fixed& F) const {
	Fixed	result;

	result._fixedPoint = (this->_fixedPoint * 256) / F._fixedPoint;
	return (result);
}

Fixed&	Fixed::operator++() {
	++(this->_fixedPoint);
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	tmp;

	tmp = *this;
	this->_fixedPoint++;
	return (tmp);
}

Fixed&	Fixed::operator--() {
	--(this->_fixedPoint);
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed	tmp;

	tmp = *this;
	this->_fixedPoint--;
	return (tmp);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b) {
	if (a > b)
		return (b);
	else
		return (a);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) {
	if (a > b)
		return (b);
	else
		return (a);
}

Fixed&	Fixed::max(Fixed& a, Fixed&b) {
	if (a > b)
		return (a);
	else
		return (b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) {
	if (a > b)
		return (a);
	else
		return (b);
}

float	Fixed::toFloat( void ) const
{
	float	rational;

	rational = _fixedPoint / 256.0f;
	return (rational);
}