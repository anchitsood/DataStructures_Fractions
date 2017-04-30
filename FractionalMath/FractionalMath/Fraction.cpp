/* ////////////////////////////////////////////////////////////
File Name: Fraction.cpp
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

#include "Fraction.h"

using namespace std;


int Fraction::getNumerator() const
{
	return this->_numerator_;
}
int Fraction::getDenominator() const
{
	return this->_denominator_;
}
int Fraction::getAbsNumerator() const
{
	return this->_abs_numerator_;
}
void Fraction::setNumerator(int input_numerator)
{
	this->_numerator_ = input_numerator;
}
void Fraction::setDenominator(int input_denominator)
{
	this->_denominator_ = ((input_denominator == 0) ? 1 : input_denominator);
}
void Fraction::setAbsNumerator(int input_abs_numerator)
{
	this->_abs_numerator_ = input_abs_numerator;
}


int Fraction::gcd(int abs_numerator, int abs_denominator) const
{
	return ((abs_denominator == 0) ? abs_numerator : gcd(abs_denominator, abs_numerator % abs_denominator));
}
void Fraction::reduce()
{
	int divisor = gcd(this->getAbsNumerator(), this->getDenominator());
	if (divisor != 0)
	{
		this->setNumerator(this->getNumerator() / divisor);
		this->setDenominator(this->getDenominator() / divisor);

		this->setAbsNumerator(this->getAbsNumerator() / divisor);
	}
	else
	{
		// this case is not possible
		// denominator can never be zero: this has been enforced in the constructor
		// ergo, there is no case where both numerator and denominator are zero

		// do nothing
	}
}
void Fraction::reciprocal()
{
	if (this->getNumerator() == 0)
	{
		// do nothing, no reciprocal possible
		return;
	}

	int sign = (this->getNumerator() * this->getDenominator());
	sign = sign / abs(sign);

	int temp = abs(this->getNumerator());
	this->setNumerator(sign * abs(this->getDenominator()));
	this->setDenominator(temp);
}
double Fraction::getDecimalValue() const
{
	return (double(this->getNumerator()) / double(this->getDenominator()));
}


Fraction::Fraction()
{
	this->setNumerator(0);
	this->setDenominator(0);

	this->setAbsNumerator(0);
}
Fraction::Fraction(int input_numerator, int input_denominator)
{
	this->setNumerator(input_numerator);
	this->setDenominator(input_denominator);

	this->setAbsNumerator(abs(input_numerator));

	// manage the special case which makes the denominator negative
	if (this->getDenominator() < 0)
	{
		this->setNumerator(-1 * this->getNumerator());
		this->setDenominator(-1 * this->getDenominator());
	}
}
Fraction::Fraction(int input_numerator)
{
	this->setNumerator(input_numerator);
	this->setDenominator(1);
	
	this->setAbsNumerator(abs(input_numerator));
}
Fraction::~Fraction()
{
	this->setNumerator(0);
	this->setDenominator(0);

	this->setAbsNumerator(0);
}
Fraction::Fraction(const Fraction& incoming)
{
	if (&incoming != this)
	{
		this->setNumerator(incoming.getNumerator());
		this->setDenominator(incoming.getDenominator());

		this->setAbsNumerator(incoming.getAbsNumerator());
	}
	else
	{
		// do nothing
	}
}


void Fraction::displayFraction() const
{
	cout << this->getNumerator() << "/" << this->getDenominator();
}
void Fraction::displayDecimal() const
{
	cout << this->getDecimalValue();
}


Fraction& Fraction::operator=(const Fraction& incoming)
{
	if (&incoming != this)
	{
		this->setNumerator(incoming.getNumerator());
		this->setDenominator(incoming.getDenominator());

		this->setAbsNumerator(incoming.getAbsNumerator()); 
	}
	else
	{
		// do nothing
	}

	return *this;
}

const bool Fraction::operator==(const Fraction& incoming) const
{
	return ((*this - incoming).getNumerator() == 0);
}
const bool Fraction::operator!=(const Fraction& incoming) const
{
	return (!(*this == incoming));
}
const bool Fraction::operator>(const Fraction& incoming) const
{
	return ((*this - incoming).getNumerator() > 0);
}
const bool Fraction::operator<(const Fraction& incoming) const
{
	return ((*this - incoming).getNumerator() < 0);
}
const bool Fraction::operator>=(const Fraction& incoming) const
{
	return ((*this > incoming) || (*this == incoming));
}
const bool Fraction::operator<=(const Fraction& incoming) const
{
	return ((*this < incoming) || (*this == incoming));
}
const Fraction Fraction::operator+(const Fraction& incoming) const
{
	return Fraction(((this->getNumerator() * incoming.getDenominator()) + (this->getDenominator() * incoming.getNumerator())), (this->getDenominator() * incoming.getDenominator()));
}
const Fraction Fraction::operator-(const Fraction& incoming) const
{
	return Fraction(((this->getNumerator() * incoming.getDenominator()) - (this->getDenominator() * incoming.getNumerator())), (this->getDenominator() * incoming.getDenominator()));
}
const Fraction Fraction::operator*(const Fraction& incoming) const
{
	return Fraction((this->getNumerator() * incoming.getNumerator()), (this->getDenominator() * incoming.getDenominator()));
}
const Fraction Fraction::operator/(const Fraction& incoming) const
{
	if (incoming.getNumerator() == 0)
	{
		// division not possible, return same value
		// do nothing
		return *this;
	}
	else
	{
		return Fraction((this->getNumerator() * incoming.getDenominator()), (this->getDenominator() * incoming.getNumerator()));
	}
}

Fraction& Fraction::operator+=(const Fraction& incoming)
{
	this->setNumerator((this->getNumerator() * incoming.getDenominator()) + (this->getDenominator() * incoming.getNumerator()));
	this->setDenominator(this->getDenominator() * incoming.getDenominator());

	this->setAbsNumerator(abs(this->getNumerator()));

	return *this;
}
Fraction& Fraction::operator-=(const Fraction& incoming)
{
	this->setNumerator((this->getNumerator() * incoming.getDenominator()) - (this->getDenominator() * incoming.getNumerator()));
	this->setDenominator(this->getDenominator() * incoming.getDenominator());

	this->setAbsNumerator(abs(this->getNumerator()));

	return *this;
}
Fraction& Fraction::operator*=(const Fraction& incoming)
{
	this->setNumerator(this->getNumerator() * incoming.getNumerator());
	this->setDenominator(this->getDenominator() * incoming.getDenominator());

	this->setAbsNumerator(abs(this->getNumerator()));

	return *this;
}
Fraction& Fraction::operator/=(const Fraction& incoming)
{
	if (incoming.getNumerator() != 0)
	{
		this->setNumerator(this->getNumerator() * incoming.getDenominator());
		this->setDenominator(this->getDenominator() * incoming.getNumerator());

		this->setAbsNumerator(abs(this->getNumerator()));

		// manage the special case which makes the denominator become negative
		if (this->getDenominator() < 0)
		{
			this->setNumerator(-1 * this->getNumerator());
			this->setDenominator(-1 * this->getDenominator());
		}
	}

	else
	{
		// division not possible
		// do nothing
	}

	return *this;
}


Fraction::operator double() const
{
	return (this->getDecimalValue());
}
Fraction::operator float() const
{
	return (float(this->getDecimalValue()));
}


ostream& operator<<(ostream& ostrm, Fraction fraction)
{
	return (ostrm << fraction.getNumerator() << "/" << fraction.getDenominator());
}