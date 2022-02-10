#include <cassert>
#include <iostream>
#include "poly.h"

using namespace std;

const unsigned int poly::SIZEINCR = 5;
// SIZEINCR is the size increment used in expanding
// the dynamic arrays as needed.

poly::poly()
{
// Pre: None.
// Post: A basic "zero" polynomial object is created
// with zero terms.

	nterms = 0;
	terms = new term[MAXSIZE = SIZEINCR];
	variable = 'x';
};

void poly::copy (const poly & p)
{
	// Pre: p is a valid polynomial.
	// Post: p is copied into the implicit parameter.
	
	variable = p.variable;
	nterms = p.nterms;
	terms = new term[MAXSIZE = p.MAXSIZE];
	for (unsigned int i=0; i<nterms; i++)
		terms[i] = p.terms[i];
};

poly::poly (const poly & p) //DEEP COPY SEMANTICS
{
	// Pre: p is a valid polynomial.
	// Post: p is copied into the implicit parameter
	// using "deep copy semantics."

	copy (p);
};

void poly::free (void)
{
	// Pre: The implicit parameter has been allocated.
	// Post: Any necessary deallocation is done.

	nterms = 0;
	delete [] terms;
	terms = NULL;
};

poly::~poly (void)
{
	// Pre: The implicit parameter has been allocated.
	// Post: Any necessary deallocation is done.

	free ();
};

poly & poly::operator= (const poly & p) //DEEP COPY SEMANTICS
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

void poly::expand ()
{
	// Pre: Implicit parameter is a valid polynomial.
	// post: The size of the polynomial store in the implicit
	// parameter is expanded by SIZEINCR while keeping the
	// polynomial value the same.

	termptr p;

	p = new term[MAXSIZE += SIZEINCR];
	for (unsigned int j=0; j<nterms; j++) p[j] = terms[j];
	delete [] terms;
	terms = p;
};

void poly::InsertTermSorted (term t)
{
	// Pre: Implicit parameter is a valid polynomial NOT
	// containing any term with the same exponent as t.
	// Post: The new term t is inserted into the implicit
	// parameter polynomial, making sure the terms are in
	// decreasing order of exponents.  In the process, the
	// polynomial is "expanded" if necessary.
	// Insertion is made by finding the right position,
	// starting at the end; this is good for efficiency of
	// addition, etc.

	int i = nterms-1;
	unsigned int e = t.exp;

	if (nterms == MAXSIZE) expand ();

	nterms++;
	while ((i>=0) && (e > terms[i].exp))
	{
		terms[i+1] = terms[i];
		i--;
	};
	//No two terms may have the same exponent.
	assert ((i<0) || (e != terms[i].exp));
	terms[i+1] = t;
};

void poly::read ()
{
	// Pre: None.
	// Post: A new value is read into the implicit paramter polynomial,
	// per instructions as given out first.  The terms are stored in
	// decreasing order of exponents.  If necessary, the old value is destroyed.

	poly temp;
	int coeff;
	int exp;
	cout << "Input a polynomial by first specifying the variable and then the terms in any order." << endl
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
				temp.InsertTermSorted(term(coeff, exp));
		}
		else
			while (cin && (cin.peek() != '\n')) cin.ignore();
	} while (coeff && (exp >= 0));
	*this = temp; // The assignment operator is being called here!
};

void poly::write() const
{
	// Pre: The implicit parameter is a valid polynomial.
	// Post: The polynomial represented by the implicit parameter is
	// printed out on the standard output.  The variable is used as stored.

	const poly *holdingVariable;
	holdingVariable = this;

	for (int i = 0; i < nterms; i++)
	{
		cout << terms[i].coeff; 

		if (terms[i].exp > 1)
		{
			cout << holdingVariable->variable << terms[i].exp;
		}
		if (terms[i].exp > 0 && terms[i].exp < 2)
		{
			cout << holdingVariable->variable;
		}
		if (terms[i + 1].coeff > 0) 
		{
			cout << " +";
		} 
		if (terms[i].coeff == 0)
		{
			cout << ""; //used to add spaces between
		}
	}
};

poly poly::plus (const poly & right) const
{
	const poly* c; //temp variable
	c = this;
	/*
	if (c->nterms > right.nterms)
	{
		for (int i = 0; i < nterms; i++)
		{

		}
	}
	*/
	return right;
};

poly poly::minus (const poly & right) const
{
	const poly* c; //temp variable
	c = this;
	/*
	if (c->nterms > right.nterms)
	{
		for (int i = 0; i < nterms; i++)
		{

		}
	}
	*/
	return right;
};

float poly::evaluate (float value) const
{
	float result = 0.0;

	for (int i = 0; i < nterms; i++)
	{
		result = result + terms[i].coeff * pow(value, terms[i].exp);
	}
	return result; //a float
};