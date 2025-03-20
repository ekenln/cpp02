/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eeklund <eeklund@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/16 17:54:36 by elleneklund   #+#    #+#                 */
/*   Updated: 2025/03/20 12:09:49 by eeklund       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void) 
{
	Fixed a;
	Fixed c(42.42f);
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed d(b);

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;

	// Assignment operator
	c = Fixed(1234.4321f);
	std::cout << "\nAfter assignment, a = " << a << std::endl;

	std::cout << "\nComparison operators:" << std::endl;
	std::cout << "b > c: " << (b > c) << std::endl;
	std::cout << "b < c: " << (b < c) << std::endl;
	std::cout << "b >= d: " << (b >= d) << std::endl;
	std::cout << "b <= d: " << (b <= d) << std::endl;
	std::cout << "b == d: " << (b == d) << std::endl;
	std::cout << "b != c: " << (b != c) << std::endl;

	std::cout << "\nArithmetic operators:" << std::endl;
	std::cout << "b(" <<b<<") + c(" << c<< ") = " << (b + c) << std::endl;
	std::cout << "b(" <<b<<") - c(" << c<< ") = " << (b - c) << std::endl;
	std::cout << "b(" <<b<<") * c(" << c<< ") = " << (b * c) << std::endl;
	std::cout << "b(" <<b<<") / c(" << c<< ") = " << (b / c) << std::endl;

	std::cout << "\nIncrement and Decrement operators:" << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "a with pre-increment applied: " << ++a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a with post increment should be same as above: " << a++ << std::endl;
	std::cout << "a after incremnt: " << a << std::endl;
	std::cout << "a with pre-decrement applied = " << --a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a with post decrement should be same as above: " << a-- << std::endl;
	std::cout << "a after decrement: " << a << std::endl;

	std::cout << "\nMin and Max functions:" << std::endl;
	std::cout << "min(b, c) = " << Fixed::min( b, c ) << std::endl;
	std::cout << "max(b, c) = " << Fixed::max( b, c ) << std::endl;
	std::cout << "max(a, b) = " << Fixed::max( a, b ) << std::endl;

	return 0;
}


//main from the subject
// int main( void ) {
// Fixed a;
// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
// std::cout << a << std::endl;
// std::cout << ++a << std::endl;
// std::cout << a << std::endl;
// std::cout << a++ << std::endl;
// std::cout << a << std::endl;
// std::cout << b << std::endl;
// std::cout << Fixed::max( a, b ) << std::endl;
// return 0;
// }