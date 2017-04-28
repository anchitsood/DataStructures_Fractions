//Hi Anchit,
//
//I’m writing in regard to your application for software engineer position at MathWorks.Thank you for applying for the position.As a next step in the process, I’d like to ask you to do the coding exercise described below.
//
//Implement in C++ a Fraction class that supports the following operations, including unit test verifying their functionality :
//addition
//subtraction
//multiplication
//division
//equality, non - equality
//greater than, less than
//display
//If possible, please send me your solution by 9 AM on 2nd May, 2017 (Tue.).If you need more time for some reasons please let me know.Once we have received your solution, we will make decision on the next step of the interview process and communicate accordingly.
//
//I look forward to hearing from you.
//
//Regards
//Yuki Saito


#include <stdio.h>
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
	Fraction(const Fraction &incoming);	// copy constructor
	
	// functions to manipulate and edit a fraction object
	void reduce();						// reduce a fraction by dividing numerator and denominator by gcd
	void reciprocal();					// convert fraction into its reciprocal
	void displayFraction() const;		// display a fraction
	void displayDecimal() const;		// display decimal form of the fraction
	
	// operator definitions for fraction objects
	Fraction &operator=(const Fraction &incoming);			// assignment
	bool operator==(const Fraction &incoming) const;		// equality
	bool operator!=(const Fraction &incoming) const;		// inequality
	bool operator>(const Fraction &incoming) const;			// greater-than
	bool operator<(const Fraction &incoming) const;			// less-than
	bool operator>=(const Fraction &incoming) const;		// greater-than or equal
	bool operator<=(const Fraction &incoming) const;		// less-than or equal
	Fraction operator+(const Fraction &incoming) const;		// addition
	Fraction operator-(const Fraction &incoming) const;		// subtraction
	Fraction operator*(const Fraction &incoming) const;		// multiplication
	Fraction operator/(const Fraction &incoming) const;		// division

	// explicit casts
	operator double() const;	// explicit cast to double
	operator float() const;		// explicit cast to float
	// operator int() const;
	// This is dangerous because we lose information about the denominator, so removing this
};



// included for ease of use with cout
ostream &operator<<(ostream &ostrm, Fraction fraction);
