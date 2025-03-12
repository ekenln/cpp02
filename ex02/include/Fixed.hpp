/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: elleneklund <elleneklund@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/16 17:52:21 by elleneklund   #+#    #+#                 */
/*   Updated: 2025/03/12 10:53:46 by elleneklund   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {

private:
	int					_fixedPoint;
	static const int	_fractionalBits = 8;

public:
	Fixed();
	Fixed( const int integerValue );
	Fixed( const float floatValue );
	~Fixed();
	Fixed(const Fixed& F); //copy constructor
	
	//overloading relational operators
	bool	operator>(const Fixed& F) const;
	bool	operator<(const Fixed& F) const;
	bool	operator>=(const Fixed& F) const;
	bool	operator<=(const Fixed& F) const;
	bool	operator==(const Fixed& F) const;
	bool	operator!=(const Fixed& F) const;

	//arithmetic operators +, -, *, and / should it return reference to fixed? or a new instance like that? UNCLEAR
	Fixed	operator+(const Fixed& F) const;
	Fixed	operator-(const Fixed& F) const;
	Fixed	operator*(const Fixed& F) const;
	Fixed	operator/(const Fixed& F) const;

	//increment decrement pre and post
	Fixed&	operator++();
	Fixed	operator++(int);
	Fixed&	operator--();
	Fixed	operator--(int);

	static Fixed&		min(Fixed& a, Fixed& b);
	static const Fixed&	min(const Fixed& a, const Fixed& b);
	static Fixed&		max(Fixed& a, Fixed&b);
	static const Fixed&	max(const Fixed& a, const Fixed& b);

	int		getFixedPoint( void ) const;
	float	toFloat( void ) const;

};

std::ostream&	operator<<(std::ostream& stream, const Fixed& F);

#endif