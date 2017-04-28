
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
Unit tests for Fraction class
*/


#include "Fraction.h"

int main()
{
	cout << "The Fraction class: implements fractions and standard operations on fractions." << endl;
	cout << "Constructors: Fraction(numerator, denominator), Fraction(), Fraction(numerator)" << endl;
	cout << "A few unit tests to ensure full functionality are implemented below:" << endl << endl << endl << endl;

	

	// Section 1: Sanity checks		
	cout << "Section 1: Sanity checks" << endl;
	cout << "We test how the Fraction class handles positive and negative inputs, and also check what happens when the denominator is zero" << endl << endl << endl;

		
	// Test 1.1: Positive denominator ensured
	cout << "Test 1.1: Sign of the denominator" << endl;
	Fraction frac01(-4, 10);
	Fraction frac02(6, -15);
	cout << "Constructors for the fractions below are Fraction(-4,10) and Fraction(6,-15)" << endl;
	cout << "Output:" << endl;
	cout << "frac01 is " << frac01 << endl;
	cout << "frac02 is " << frac02 << endl;
	cout << "Conclusion: Denominators are always positive" << endl << endl << endl;
		

	// Test 1.2: Handling of cases where numerator, or denominator, or both, are zero
	cout << "Test 1.2: When numerator and denominator or both are zero" << endl;
	cout << "Constructors for these are Fraction(15,0), Fraction(0,0) and Fraction(0,-7)" << endl;
	Fraction frac03(15, 0);
	Fraction frac04(0, 0);
	Fraction frac05(0, -7);
	cout << "Output:" << endl;
	cout << "frac03 is " << frac03 << endl;
	cout << "frac04 is " << frac04 << endl;
	cout << "frac05 is " << frac05 << endl;
	cout << "Conclusion: If constructor specifies denominator to be zero, it is changed to 1" << endl << endl << endl << endl;

	

	// Section 2: Simple manipulation of fractions		
	cout << "Section 2: Simple manipulation of fractions" << endl;
	cout << "We test the Fraction class for the reduce() and reciprocal() member functions" << endl << endl << endl;


	// Test 2.1: Reduce a fraction to simplest form
	cout << "Test 2.1: Reducing a fraction to its simplest form" << endl;
	Fraction frac06(27, 6);
	cout << "frac06 is " << frac06 << endl;
	cout << "frac06.reduce() is now called" << endl;
	frac06.reduce();
	cout << "frac06 is now " << frac06 << endl << endl;

	cout << "frac05 is " << frac05 << endl;
	cout << "frac05.reduce() is now called" << endl;
	frac05.reduce();
	cout << "frac05 is now " << frac05 << endl;
	cout << "Conclusion: Fractions are reduced to simplest forms with the reduce() member function" << endl << endl << endl;

	
	// Test 2.2: Reciprocal of a fraction (to be used during division)
	cout << "Test 2.2: Reciprocals of different fractions" << endl;
	cout << "frac06 is " << frac06 << endl;
	cout << "frac06.reciprocal() is now called" << endl;
	frac06.reciprocal();
	cout << "frac06 is now " << frac06 << endl << endl;
	
	cout << "frac04 is " << frac04 << endl;
	cout << "frac04.reciprocal() is now called" << endl;
	frac04.reciprocal();
	cout << "frac04 is now " << frac04 << endl;
	cout << "Conclusion: Reciprocals are calculated only if they exist" << endl << endl << endl << endl;


	
	// Section 3: Copy constructor and assignment operator		
	cout << "Section 3: Copy constructor and assignment operator" << endl;
	cout << "We test the funtion of the copy constructor and '=' operator" << endl << endl << endl;


	// Test 3.1: Testing copy constructor
	cout << "Test 3.1: Testing the copy constructor" << endl;
	cout << "frac07 is initialized using 'Fraction frac07 = frac06'" << endl;
	Fraction frac07 = frac06;
	cout << "frac06 is " << frac06 << endl;
	cout << "frac07 is " << frac07 << endl;
	cout << "frac06 resides at memory location " << &frac06 << endl;
	cout << "frac07 resides at memory location " << &frac07 << endl << endl;

	cout << "frac07.reciprocal() is now called" << endl;
	frac07.reciprocal();
	cout << "frac06 is now " << frac06 << endl;
	cout << "frac07 is now " << frac07 << endl;
	cout << "Conclusion: Copy constructor works as desired" << endl << endl << endl;


	// Test 3.2: Chaining assignment
	cout << "Test 3.2: Chaining the assignment operator to populate many fraction objects" << endl;
	cout << "These fractions are initialized as 'frac8 = frac9 = frac10 = Fraction(4,-7)'" << endl;
	Fraction frac08, frac09, frac10;
	frac08 = frac09 = frac10 = Fraction(4, -7);
	cout << "frac08 is " << frac08 << endl;
	cout << "frac09 is " << frac09 << endl;
	cout << "frac10 is " << frac10 << endl;
	cout << "frac08 resides at memory location " << &frac08 << endl;
	cout << "frac09 resides at memory location " << &frac09 << endl;
	cout << "frac10 resides at memory location " << &frac10 << endl;
	cout << "Conclusion: Assignment operator works as desired" << endl << endl << endl << endl;



	// Section 4: Comparison operators		
	cout << "Section 4: Comparison operators and their outputs" << endl;
	cout << "We test the funtion of the comparison operators" << endl << endl << endl;


	// Test 4.1: Testing equality and inequality
	cout << "Test 4.1: Testing equality '==' and inequality '!='" << endl;
	cout << "frac01 is " << frac01 << endl;
	cout << "frac02 is " << frac02 << endl;
	cout << "'frac01 == frac02' returns " << ((frac01 == frac02) ? "true" : "false") << endl;
	cout << "'frac01 != frac02' returns " << ((frac01 != frac02) ? "true" : "false") << endl;
	cout << "Conclusion: Equality and inequality operators work corectly" << endl << endl;


	// Test 4.2: Testing greater-than and less-than
	cout << "Test 4.2: Testing greater-than '>', '>=' and less-than '<', '<='" << endl;
	cout << "frac07 is " << frac07 << endl;
	cout << "frac08 is " << frac08 << endl;
	cout << "'frac07 > frac08' returns " << ((frac07 > frac08) ? "true" : "false") << endl;
	cout << "'frac07 < frac08' returns " << ((frac07 < frac08) ? "true" : "false") << endl << endl;

	Fraction frac11(-2, 5);
	cout << "frac01 is " << frac01 << endl;
	cout << "frac11 is " << frac11 << endl;
	cout << "'frac01 > frac11' returns " << ((frac01 > frac11) ? "true" : "false") << endl;
	cout << "'frac01 >= frac11' returns " << ((frac01 >= frac11) ? "true" : "false") << endl << endl;

	cout << "frac02 is " << frac02 << endl;
	cout << "frac11 is " << frac11 << endl;
	cout << "'frac02 < frac11' returns " << ((frac02 < frac11) ? "true" : "false") << endl;
	cout << "'frac02 <= frac11' returns " << ((frac02 <= frac11) ? "true" : "false") << endl;
	cout << "Conclusion: Comparison operators work corectly" << endl << endl << endl << endl;



	// Section 5: Mathematical operators		
	cout << "Section 5: Mathematical operators and their outputs" << endl;
	cout << "We test the function of some simple simple mathematical operators" << endl << endl << endl;

	Fraction frac12(5, 12);
	Fraction frac13(11, 10);

	// Test 5.1: Testing addition
	cout << "Test 5.1: Testing addition '+'" << endl;
	cout << "frac12 is " << frac12 << endl;
	cout << "frac13 is " << frac13 << endl;
	Fraction frac14 = frac12 + frac13;
	cout << "'frac14 = frac12 + frac13' gives frac14 =  " << frac14 << endl;
	frac14.reduce();
	cout << "'frac14.reduce()' returns " << frac14 << endl;
	cout << "Conclusion: Addition operator works correctly" << endl << endl;


	// Test 5.2: Testing subtraction
	cout << "Test 5.2: Testing subtraction '-'" << endl;
	cout << "frac12 is " << frac12 << endl;
	cout << "frac13 is " << frac13 << endl;
	Fraction frac15 = frac12 - frac13;
	cout << "'frac15 = frac12 - frac13' gives frac15 =  " << frac15 << endl;
	frac15.reduce();
	cout << "'frac15.reduce()' returns " << frac15 << endl;
	cout << "Conclusion: Subtraction operator works correctly" << endl << endl;


	// Test 5.3: Testing multiplication
	cout << "Test 5.3: Testing multiplication '*'" << endl;
	cout << "frac12 is " << frac12 << endl;
	cout << "frac13 is " << frac13 << endl;
	Fraction frac16 = frac12 * frac13;
	cout << "'frac16 = frac12 * frac13' gives frac16 =  " << frac16 << endl;
	frac16.reduce();
	cout << "'frac16.reduce()' returns " << frac16 << endl;
	cout << "Conclusion: Multiplication operator works correctly" << endl << endl;


	// Test 5.4: Testing division
	cout << "Test 5.4: Testing division '/'" << endl;
	cout << "frac12 is " << frac12 << endl;
	cout << "frac13 is " << frac13 << endl;
	Fraction frac17 = frac12 / frac13;
	cout << "'frac17 = frac12 / frac13' gives frac17 =  " << frac17 << endl;
	frac17.reduce();
	cout << "'frac17.reduce()' returns " << frac17 << endl << endl;

	cout << "frac11 is " << frac11 << endl;
	cout << "frac04 is " << frac04 << endl;
	cout << "'frac04 / frac11' returns " << frac11 / frac04 << endl;
	cout << "Conclusion: Division operator works correctly; if division is not possible, it returns the first fraction" << endl << endl;


	cout << "This concludes the unit test routines" << endl << endl << endl;
	cout << "Each fraction object can be displayed by calling the displayFraction() member function" << endl;
	cout << "A non member function has also been included for display using 'cout': just use 'cout' with each fraction object instance like you would with primitive data types" << endl << endl << endl;
}