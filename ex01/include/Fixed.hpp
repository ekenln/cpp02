/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: eeklund <eeklund@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/16 10:32:55 by elleneklund   #+#    #+#                 */
/*   Updated: 2025/03/19 13:34:29 by eeklund       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

/*
Relative Difference= 
∣a−b∣ / max(∣a∣,∣b∣)
​

By multiplying by 
2^8 = 256, you're shifting the decimal point 8 places to the right to convert a fractional number into an integer
*/

class Fixed {

private:

	static const int	_fractionalBits = 8;
	int					_fixedPoint;

public:

	Fixed();
	Fixed(const int integerValue);
	Fixed(const float floatValue);
	~Fixed();
	Fixed( const Fixed& oldObj );

	Fixed& operator=(const Fixed& F);

	float	toFloat( void ) const;
	int		toInt( void ) const;
	void	setRawBits( int const raw );
	int 	getRawBits( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& F);

#endif