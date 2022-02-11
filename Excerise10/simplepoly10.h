//0020267671

#include <iostream>

#ifndef SIMPLEPOLY_H
#define SIMPLEPOLY_H

class SimplePoly
{
public:
	SimplePoly(); // the default constructor
	SimplePoly(const SimplePoly&); // the copy constructor (creates a deep copy)
	SimplePoly(int); // Simple conversion constructor for the constant term
	~SimplePoly(); // the destructor

	SimplePoly& operator= (const SimplePoly&); // the assignment operator (creates a deep copy)

	void read();
	// Read a value for the polynomial per preset convention
	void write() const;
	// Write out the polynomial to look close to usual written form:
	// Terms are written out in increasing (or decreasing) order; each
	// term appears with its coefficient followed by the variable, which
	// is then followed by the exponent, with special cases appropriately
	// handled for positive and negative coefficients whether they appear
	// at the front or later, coeffients of 1 or -1, exponents that are
	// positive, negative, or zero printed as usually written.
	// All in all, polynomials look as they are usually written, with the
	// only exception being, the exponents, if any, are written NOT as
	// superscripts, but flush with the rest of the line after the variable.
	SimplePoly plus(const SimplePoly&) const;
	// Return the sum of the TWO polynomials
	SimplePoly minus(const SimplePoly&) const;
	// Return the difference of the TWO polynomials
	float evaluate(float) const;
	// Return the evaluation of the poly at the parameter value

	friend std::istream& operator>> (std::istream& input, SimplePoly& inSP);

	friend std::ostream& operator<< (std::ostream& output, const SimplePoly& outSP);

	SimplePoly operator+(const SimplePoly& right)
	{
			return plus(right);
	};

	SimplePoly operator-(const SimplePoly& right)
	{
		return minus(right);
	};

private:
	struct term
	{
		int coeff;
		term(): coeff(0) {}; // only purpose is  to facilitate array declaration.
		term(int c) : coeff(c) {};
		char sign() const { return ((coeff < 0) ? '-' : ((coeff == 0) ? '0' : '+')); };
	};
	typedef term* termptr;
	static const unsigned int SIZEINCR;
	// Class-wide constant size increment used by "expand".
	int LargestExp; // The largest exponent in the polynomial; -1 means no terms
	unsigned int CAPACITY; // Maximum possible number of terms >= LargestExp+1
	termptr terms; // Base pointer for the dynamic array of terms
	char variable; // The variable of the polynomial

	void copy(const SimplePoly&); // used by the copy constructor/assignment operator
	void free(); // used by the destructor / assignment operator
	void InsertTerm(int c, int e);
	// Insert the term with coefficient c and exponent e, expanding the dynamic
	// "terms" array, if necessary.
	void expand(unsigned int); // Expand the terms array by SIZEINCR
};
#endif