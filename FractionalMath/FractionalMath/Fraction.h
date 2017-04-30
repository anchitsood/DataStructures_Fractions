/* ////////////////////////////////////////////////////////////
File Name: Fraction.h
Copyright (c) 2016 Anchit Sood (sood.anchit@gmail.com).  All rights reserved.
Redistribution and use in source and binary forms, with or without modification, 
are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, 
   this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice, 
   this list of conditions and the following disclaimer in the documentation 
   and/or other materials provided with the distribution.
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
//////////////////////////////////////////////////////////// */



//Implement in C++ a Fraction class that supports the following operations, including unit test verifying their functionality :
//addition
//subtraction
//multiplication
//division
//equality, non - equality
//greater than, less than
//display



/*
Author: Anchit Sood
Date: 4/27/2017
License: GNU GPLv3
Fraction class
*/


#include <math.h>
#include <stdio.h>
#include <iostream>

using namespace std;


class Fraction
{
private:
	// private resouces
	// member variables
	int _numerator_;
	int _denominator_;
	int _abs_numerator_;	// to help calculate gcd without worrying about sign



protected:
	// protected resources
	// getters and setters
	void setNumerator(int input_numerator);
	void setDenominator(int input_denominator);
	int getAbsNumerator() const;
	void setAbsNumerator(int input_abs_numerator);

	// helper functions
	int gcd(int abs_numerator, int abs_denominator) const;		// calculate gcd
	double getDecimalValue() const;								// get double value of fraction



public:
	// public resources
	// getters and setters
	int getNumerator() const;
	int getDenominator() const;

	// constructors and destructor
	Fraction(int input_numerator, int input_denominator);
	Fraction(int input_numerator);
	Fraction();
	~Fraction();
	Fraction(const Fraction& incoming);	// copy constructor
	
	// functions to manipulate and edit a fraction object
	void reduce();						// reduce a fraction by dividing numerator and denominator by gcd
	void reciprocal();					// convert fraction into its reciprocal
	void displayFraction() const;		// display a fraction
	void displayDecimal() const;		// display decimal form of the fraction
	
	// operator definitions for fraction objects
	Fraction& operator=(const Fraction& incoming);					// copy/assignment operator
	
	const bool operator==(const Fraction& incoming) const;			// equality
	const bool operator!=(const Fraction& incoming) const;			// inequality
	const bool operator>(const Fraction& incoming) const;			// greater-than
	const bool operator<(const Fraction& incoming) const;			// less-than
	const bool operator>=(const Fraction& incoming) const;			// greater-than or equal
	const bool operator<=(const Fraction& incoming) const;			// less-than or equal
	const Fraction operator+(const Fraction& incoming) const;		// addition
	const Fraction operator-(const Fraction& incoming) const;		// subtraction
	const Fraction operator*(const Fraction& incoming) const;		// multiplication
	const Fraction operator/(const Fraction& incoming) const;		// division

	Fraction& operator+=(const Fraction& incoming);					// compound addition operator
	Fraction& operator-=(const Fraction& incoming);					// compound subtraction operator
	Fraction& operator*=(const Fraction& incoming);					// compound multiplication operator
	Fraction& operator/=(const Fraction& incoming);					// compound division operator


	// explicit casts
	operator double() const;	// explicit cast to double
	operator float() const;		// explicit cast to float
	// operator int() const;
	// This is dangerous because we lose information about the denominator, so removing this int() cast
};



// included for ease of use with cout
ostream& operator<<(ostream& ostrm, Fraction fraction);
