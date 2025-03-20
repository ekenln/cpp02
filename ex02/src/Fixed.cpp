/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: eeklund <eeklund@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/16 17:49:53 by elleneklund   #+#    #+#                 */
/*   Updated: 2025/03/20 12:08:53 by eeklund       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed() : _fixedPoint(0) {
	// std::cout << "default constructor called" << std::endl;
}

Fixed::Fixed(int integerValue) : _fixedPoint(integerValue << _fractionalBits) {
	// std::cout << "int constructor called" << std::endl;
}

Fixed::Fixed(const float floatValue) {
	// std::cout << "float constructor called" << std::endl;
	_fixedPoint = roundf(floatValue * (1 << _fractionalBits));
}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed& F) : _fixedPoint(F.getRawBits()) {
	// std::cout << "copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& F)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &F)
	{
		this->_fixedPoint = F.getRawBits();
	}
	return (*this);
}

int	Fixed::getFixedPoint( void ) const
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

	result._fixedPoint = (this->_fixedPoint * F._fixedPoint) >> _fractionalBits;
	return (result);
}

Fixed	Fixed::operator/(const Fixed& F) const {
	Fixed	result;

	result._fixedPoint = (this->_fixedPoint << _fractionalBits) / F._fixedPoint;
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

void Fixed::setRawBits( int const raw )
{
	this->_fixedPoint = raw;
}

int	Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits function called" << std::endl;
	return (_fixedPoint);
}

int Fixed::toInt( void ) const
{
	int result;

	result = _fixedPoint >> _fractionalBits;
	return (result);
}

float	Fixed::toFloat( void ) const
{
	float	rational;

	rational = (float)_fixedPoint / (1 << _fractionalBits);
	return (rational);
}