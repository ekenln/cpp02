/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eeklund <eeklund@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/15 13:43:01 by elleneklund   #+#    #+#                 */
/*   Updated: 2025/03/20 11:49:14 by eeklund       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

int main( void ) 
{
	Fixed a;
	Fixed b( a );
	Fixed c;

	c = b;

	std::cout << "a: " << a.getRawBits() << std::endl;
	std::cout << "b: " << b.getRawBits() << std::endl;
	std::cout << "c: " << c.getRawBits() << std::endl;

	return (0);
}