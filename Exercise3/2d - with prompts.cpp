#include <iostream>

using namespace std;

void eat_white (istream & in)
/* Pre: "in" is a valid input file stream.
Post: Any white space skipped over to EOF or the next non-white space character.*/
{
  while ((in.peek()!=EOF) && isspace(in.peek())) in.ignore();
};

inline int & element (int* twod, int dim2, int row, int col)
{ return twod[dim2*row+col]; }

void print2d (int * rect2d, int d1, int d2)
{
  for (int i=0; i<d1; i++)
    for (int j=0; j<d2; j++)
      {
	cout << rect2d[d2*i+j];
	if (j<d2-1) cout << "\t";
	else cout << endl;
      };
}

int main ()
{
  int * rect2d;
  int d1,d2;

  cout << "Enter size of dimension #1: ";
  cin >> d1;
  cout << endl << "Enter size of dimension #2: ";
  cin >> d2;

  rect2d = new int[d1*d2];

  cout << endl
    << "Now enter " << d1 <<" rows, each with " << d2 << " values:" << endl;

  for (int i=0; i<d1; i++)
    for (int j=0; j<d2; j++)
      cin >> rect2d[d2*i+j];

  char command;
  cout << endl
       << "If you want to get or set any particular element, input" << endl
       << "g (for get) or s (for set) followed by row and column" << endl
       << "(with zero-based indexing) and an integer value (for s)," << endl
       << "p to print the whole array, or d (for done) to end:" << endl;
  do
    {
      int i, j, val;
      
      eat_white(cin);
      cin >> command;
      if ((command == 's')||(command == 'S'))
	{
	  cin >> i >> j >> val;
	  element (rect2d, d2, i, j) = val;
	  cout << endl
	       << "Done setting the element at [" << i <<"," << j << "] to "
	       << val << "." << endl << "Next command: ";
	}
      else if ((command == 'g') || (command == 'G'))
	{
	  cin >> i >> j;
	  cout << endl << "The element at [" << i <<"," << j << "] is ";
	  cout << element (rect2d, d2, i, j) << "." << endl << "Next command: ";
	}
      else if ((command == 'p') || (command == 'P'))
	{
	  cout<< endl
	      << "Reporting values stored in the 2-d array, row by row:"<< endl;
	  print2d (rect2d, d1, d2);
	  cout << "Next command: ";
	}
      else if ((command != 'd') && (command != 'D'))
	cout << endl << "Please enter a valid command (s, S, g, G, d, or D): ";
    } while ((command != 'd') && (command != 'D'));

  return(0);
};
