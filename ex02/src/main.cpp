/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: elleneklund <elleneklund@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/16 17:54:36 by elleneklund   #+#    #+#                 */
/*   Updated: 2025/03/12 10:55:23 by elleneklund   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) 
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "\na with default constructor: " << a << std::endl;
	std::cout << "a with preincrement applied: " << ++a << std::endl;
	std::cout << "just a: " << a << std::endl;
	std::cout << "a with post increment should be same as above: " << a++ << std::endl;
	std::cout << "a after incremnt: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "max of a or b: " << Fixed::max( a, b ) << std::endl;
	std::cout << "min of a or b: " << Fixed::min( a, b ) << std::endl;

	return 0;
}