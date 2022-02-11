// Id: 0020267671
//Davis McCue

#include <iostream>

using namespace std;

void eat_white(istream& in)
/* Pre: "in" is a valid input file stream.
Post: Any white space skipped over to EOF or the next non-white space character.*/
{
	while ((in.peek() != EOF) && isspace(in.peek())) in.ignore();
};

// *DO* Define a function to return a value of (or better yet,
// a reference to) the distance between cities i and j.
// tri2d is the array that stores the distances efficiently
// and NC is the number of cities.
int& element(int* tri2d, int NC, int i, int j)
{
	if (j == 0)
	{
		if (i == NC - 1)
			return tri2d[0];

		else
			return tri2d[(i + 1) * (i)];
	}

	else
	{
		return tri2d[i * j];
	}
};

// *DO* Define a function to print the ENTIRE distance chart,
// for ALL pairs of cities (you may use the above function).
// tri2d is the array that stores the distances efficiently
// and NC is the number of cities.
// NOTE that there are NC*NC pairs of cities and you are to
// print distances for all those pairs, although you do not
// explicitly store all of them!
void printtri(int* tri2d, int NC)
{
	for (int i = NC - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (j == 0)
			{
				if (i == NC - 1)
					cout << "10" << " ";

				else
					cout << tri2d[(i + 1) * (i)] + 10 << " ";
			}

			else
			{
				cout << tri2d[i * j] << " ";
			}
		}
		cout << endl;
	}
};

int main()
{
	int* tri2d;
	int NC;

	cin >> NC;
	tri2d = new int[NC * (NC - 1) / 2];

	// *DO* SIMILAR TO 2d.cpp, read and set up the distances in the
	// single-dimensional array.  Store distance between each pair of 
	// cities only once. (DO NOT duplicate for i-j and also j-i!)

	int tempVal = 0;

	for (int i = NC - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			tempVal += 10;

			tri2d[i * j] = tempVal;
		}
	}

	printtri(tri2d, NC);

	char command;
	do
	{
		int i, j, val;

		eat_white(cin);
		cin >> command;
		if ((command == 's') || (command == 'S'))
		{
			cin >> i >> j >> val;
			// *DO* set the value for the distance between cities i and j,
			// BUT ONLY as appropriate (e.g., not stored if i equals j).

			if (i != j)
				tri2d[i * j] = val;

			else
				tri2d[i * j] = 0;
		}
		else if ((command == 'g') || (command == 'G'))
		{
			cin >> i >> j;
			cout << "The distance from city " << i << " to city "
				<< j << " is " << element(tri2d, NC, i, j) << endl;
		}
		else if ((command == 'p') || (command == 'P'))
		{
			cout << "Reporting distance chart:" << endl;
			printtri(tri2d, NC);
		}
		else if ((command != 'd') && (command != 'D'))
			cout << "Please enter a valid command (s/S, g/G, p/P, or d/D): " << endl;
	} while ((command != 'd') && (command != 'D'));

	return(0);
};
