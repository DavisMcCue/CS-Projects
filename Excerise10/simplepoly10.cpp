//0020267671


#include <cassert>
#include <iostream>
#include "simplepoly10.h"

using namespace std;

const unsigned int SimplePoly::SIZEINCR = 5;
// SIZEINCR is the size increment used in expanding
// the dynamic arrays as needed.

SimplePoly::SimplePoly()
{
// Pre: None.
// Post: A basic "zero" polynomial object is created
// with zero terms.  Variable is assumed to be x.

	variable = 'x';
	LargestExp = -1;
	terms = new term[CAPACITY = SIZEINCR];
};

void SimplePoly::copy(const SimplePoly& p)
{
	// Pre: p is a valid polynomial.
	// Post: p is DEEP-COPIED into the implicit parameter.

	variable = p.variable;
	LargestExp = p.LargestExp;
	terms = new term[CAPACITY = p.CAPACITY];
	for (int i = 0; i <= LargestExp; i++)
		terms[i] = p.terms[i];
};

SimplePoly::SimplePoly (const SimplePoly & p) //DEEP COPY SEMANTICS
{
	// Pre: p is a valid polynomial.
	// Post: p is copied into the implicit parameter
	// using "deep copy semantics."

	copy (p);
};

/* The following conversion constructor is new */
SimplePoly::SimplePoly (int c) // Simple conversion constructor for the constant term
{
	variable = 'x';
	terms = new term[CAPACITY = SIZEINCR];
	LargestExp = 0;
	terms[0] = term(c);  // Set coeff = c for exp = 0
};

void SimplePoly::free(void)
{
	// Pre: The implicit parameter has been allocated.
	// Post: Any necessary deallocation is done.

	//Nothing to do with "variable" here.
	LargestExp = -1;
	delete[] terms;
	terms = nullptr;
};

SimplePoly::~SimplePoly (void)
{
	// Pre: The implicit parameter has been allocated.
	// Post: Any necessary deallocation is done.

	free ();
};

SimplePoly & SimplePoly::operator= (const SimplePoly & p) //DEEP COPY SEMANTICS
{
	// Pre: p is a valid polynomial.
	// Post: The value of p is assigned to the implicit parameter
	// by "deep copy semantics."  Any necessary deallocation is
	// done along the way.

	if (this != &p)
	{
		free ();
		copy (p);
	};
	return (*this);
};

void SimplePoly::expand (unsigned int LargeExp)
{
	// Pre: Implicit parameter is a valid polynomial.  LargeExp is
	// a new exponent that needs to be accommpdated through expansion.
	// post: The size of the polynomial store in the implicit
	// parameter is expanded to the lowest multiple of SIZEINCR that
	// can accommodate a term with the LargeExp, while keeping the
	// polynomial value the same.

	termptr p;

	CAPACITY = (LargeExp / SIZEINCR + 1) * SIZEINCR;
	p = new term[CAPACITY];
	for (int j=0; j<=LargestExp; j++) p[j] = terms[j];
	delete [] terms;
	terms = p;
};

void SimplePoly::InsertTerm (int coef, int exp)
{
	// Pre: Implicit parameter is a valid polynomial NOT
	// containing any term with the same exponent as exp.
	// Post: A new term corresponding to the given coefficient coef
	// and exponent exp is inserted into the implicit parameter polynomial.
	// In the process, the polynomial is "expanded" if necessary.

	if (coef)
	{
		assert((exp >= CAPACITY) || (terms[exp].coeff == 0));
		// There is no term with the same exponent and a non-zero coefficient
		// already present.

		if (exp >= CAPACITY) expand(exp);

		terms[exp].coeff = coef;
		if ((coef != 0) && (exp > LargestExp)) LargestExp = exp;
	}
};

void SimplePoly::read ()
{
	// Pre: None.
	// Post: A new value is read into the implicit paramter polynomial, per
	// instructions as given out first.  If needed, the old value is destroyed.

	SimplePoly temp;
	int coeff;
	int exp;
	cout << "Input a polynomial by specifying the variable and all terms in any order." << endl
		<< "Each term is specified by an integer coefficient and" << endl
		<< "a non-negative integer exponent." << endl
		<< "Indicate END by specifying a dummy term with" << endl
		<< "a zero coefficient and/or a negative exponent." << endl;
	cin >> temp.variable;
	do
	{
		cin >> coeff;
		if (coeff)
		{
			cin >> exp;
			if (exp >= 0)
				temp.InsertTerm (coeff, exp);
		}
		else
			while (cin && (cin.peek() != '\n')) cin. ignore();
	} while (coeff && (exp >= 0));
	*this = temp; // The assignment operator is being called here!
};

void SimplePoly::write() const
{
	// Pre: The implicit parameter is a valid polynomial (possibly zero).
	// Post: The polynomial represented by the implicit parameter is
	// printed out on the standard output.  The variable is used as stored.
	
// *DO: FILL IN WITH AN APPROPRIATE IMPLEMENTATION
	cout << "write called" << endl;
};

SimplePoly SimplePoly::plus (const SimplePoly & right) const
{
	// Pre: The implicit parameter and the parameter right are valid
	// ploynomials.
	// Post: The sum of the two parameters is returned by plus.

// *DO: FILL IN WITH AN APPROPRIATE IMPLEMENTATION
/* The return statement below is included just so this method compiles
   for the midwau check, but must be REPLACED with proper code. */
	cout << "plus called" << endl;
	return (SimplePoly());
};

SimplePoly SimplePoly::minus (const SimplePoly & right) const
{
	// Pre: The implicit parameter and the parameter right are valid
	// ploynomials.
	// Post: The difference of the two parameters is returned by minus.
	// The polynomial right is subtracted from the implicit parameter.
	
// *DO: FILL IN WITH AN APPROPRIATE IMPLEMENTATION
/* The return statement below is included just so this method compiles
   for the midwau check, but must be REPLACED with proper code. */
	cout << "minus called" << endl;
	return (SimplePoly());
};

float SimplePoly::evaluate (float value) const
{
	// Pre: The implicit parameter is a valid polynomial.
	// Post: The value of the polynomial with the value substituted for the variable is returned.

// *DO: FILL IN WITH AN APPROPRIATE IMPLEMENTATION
/* The return statement below is included just so this method compiles
   for the midwau check, but must be REPLACED with proper code. */
	cout << "evaluate called" << endl;
	return (0.0);
}

std::ostream& operator<< (ostream& output, const SimplePoly& outSP)
{
	outSP.write();

	return output;
}

std::istream& operator>> (istream& input, SimplePoly& inSP)
{
	inSP.read();

	return input;
}