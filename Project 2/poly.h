#ifndef POLY_H
#define POLY_H

class poly
{
public:
	poly(); // the default constructor
	poly(const poly&); // the copy constructor (creates a deep copy)
	~poly(); // the destructor
	poly& operator= (const poly&); // the assignment operator (creates a deep copy)

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
	poly plus(const poly&) const;
	// Return the sum of the TWO polynomials
	poly minus(const poly&) const;
	// Return the difference of the TWO polynomials
	float evaluate(float) const;
	// Return the evaluation of the poly at the parameter value

private:
	struct term
	{
		int coeff;
		unsigned int exp;
		term() {}; // only purpose is  to facilitate array declaration.
		term(int c, unsigned int e) : coeff(c), exp(e) {};
		char sign() const { return ((coeff < 0) ? '-' : ((coeff == 0) ? '0' : '+')); };
	};
	typedef term* termptr;
	static const unsigned int SIZEINCR;
	// Class-wide constant size increment used by "expand".
	unsigned int MAXSIZE; // Current maximum number of possible terms
	unsigned int nterms; // Current actual number of terms
	termptr terms; // Base pointer for the dynamic array of terms
	char variable; // The variable of the polynomial

	void copy(const poly&); // used by the copy constructor/assignment operator
	void free(); // used by the destructor / assignment operator
	void InsertTermSorted(term);
	// Insert the term so the terms remain sorted, expanding the dynamic
	// "terms" array, if necessary.
	void expand(); // Expand the terms array by SIZEINCR
};
#endif
