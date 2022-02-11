//ID 0020267671
//Davis McCue

#include <cassert>
#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

// Type delcarations - NO MEMORY ALLOCATED (EVEN STATICALLY)
struct Part	/*A Part record*/
{
    int ID;
    float Price;
    int Quantity;
};
typedef Part * Partptr;
// Part record pointer type; The type Partptr becomes synonymous with Part *
typedef Partptr* Index;
// The type Index becomes synonymous with Partptr *

int main ()
{
  /* Rudimentary scope control in C/C++ */
  void readdata (Index &, int &);
  void printdata (Index, int);
  void copyindex (Index, Index &, int);
  void sortbyID (Index, int);
  void sortbyPrice (Index, int);
  void deallocate (Index &, int &);
  Index DBindex, IDindex, Priceindex;
  int dbsize;

  readdata (DBindex, dbsize);
  cout << "Original data:" << endl;
  printdata (DBindex, dbsize);
  copyindex (DBindex, IDindex, dbsize);
  sortbyID (IDindex, dbsize);
  cout << "Data sorted by the ID:" << endl;
  printdata (IDindex, dbsize);
  copyindex (DBindex, Priceindex, dbsize);
  sortbyPrice (Priceindex, dbsize);
  cout << "Data sorted by the price:" << endl;
  printdata (Priceindex, dbsize);
  cout << "Data in the original chronological order:" << endl;
  printdata (DBindex, dbsize);
  cout << "Data sorted by the ID:" << endl;
  printdata (IDindex, dbsize);
  deallocate (DBindex, dbsize);
  if (IDindex != nullptr) delete IDindex;
  if (Priceindex != nullptr) delete Priceindex;
};

void eat_white (ifstream & in)
/* Pre: "in" is a valid input file stream.
Post: Any white space skipped over to EOF or the next non-white space character.*/
{
  while ((in.peek()!=EOF) && isspace(in.peek())) in.ignore();
};

void resize (Index & Base, int OLDSIZE, int NEWSIZE)
/* Pre: Base is a (dynamic) Index of size OLDSIZE.
Post: Base is "EXPANDED" OR "SHRUNK" into a new (dynamic) Index of size
NEWSIZE, with data copied appropriately.
IMPORTANT NOTE: If being shrunk, it is assumed that there are only NEWSIZE valid
elements in the original array, and only that many are copied.*/
{
}

void readdata (Index & ptrs, int & size)
/*Pre: ptrs is a pointer that could point to a dynamic array of Part record pointers.
Post: ptrs points to a dynamic pointer array of the right size based on the
input read in from the data file named "p1data".
All the elements of the dynamic array are filled with pointers to dynamically
allocated Part records, which in turn are filled with input data.*/
{
  ifstream dataInput;

  void resize (Index &, int, int);

  //opens file
  dataInput.open("p1data.txt");
  
  //variables
  int i = 0;
  int tempId = 0;
  float tempPrice = 0;
  int tempQaunity = 0;

  Index Readparts = new Partptr[50];

  //open files
  if(dataInput.is_open())
  {
      //start of while loop - reads in data
      while (!dataInput.eof())
      {
          eat_white(dataInput);

          //reads in data
          dataInput >> tempId >> tempPrice >> tempQaunity;

          //allocating a new part for data
          Readparts[i] = new Part;

          //stores the data into readparts that have been allocated.
          Readparts[i]->ID = tempId;
          Readparts[i]->Price = tempPrice;
          Readparts[i]->Quantity = tempQaunity;
          i++;
      }
  }
  //close file 
  dataInput.close();
  //sets read parts to ptrs
  ptrs = Readparts;
  //after counting how many sets size to i
  size = i;
};

void printrec (Part rec)
/*Pre: rec has data.
Post: The data in rec printed out.*/
{
  cout << rec.ID << ' ' << rec.Price << ' ' << rec.Quantity << endl;
};

void printdata (Index ptrs, int size)
/*Pre: The first "size" elements of the array pointed at by ptrs are Part records
containing data.
Post: They are all printed out in the order pointed at.*/
{
  void printrec (Part);
  for (int i=0; i<size; i++) printrec(*ptrs[i]);
};

void copyindex (Index orig, Index & copy, int size)
/*Pre: The first "size" elements of the array pointed at by orig are Part records
containing data.
Post: copy points to a newly allocated dynamic array of pointers (with size elements), and
the elements of this array are copies of the first size elements of orig.*/
{
  //variable 
  Index tempPlaceHolder = new Partptr[size];

  int i;

  for (i = 0; i < size; i++)
  {
      //copes old index to new index with a pointer to the old index
      //creates a new part and starts to set pointer to pointer address per loop of each things
      tempPlaceHolder[i] = orig[i];
  }
  //sets temp variable to copy 
  copy = tempPlaceHolder;

};

int selectsmallestID (Index ptrs, int first, int last)
/*Pre: "first" through "last" elements of the ptrs array are pointers to Part records
containing data.
Post: A value k is returned such that, for i ranging from first to last,
the relation ptrs[k]->ID <= ptrs[i]->ID holds.*/
{
    int i, final;
    final = first;

    for (i = first + 1; i <= last; i++)
    {
        if (ptrs[i]->ID <= ptrs[final]->ID)
        {
            final = i;
        }
    }
    return final;
};

void sortbyID (Index ptrs, int size)
/*Pre: The first "size" elements of the ptrs array are pointers to Part records
containing data.
Post: for i ranging from 1 to size-2, the relation ptrs[i]->ID <= ptrs[i+1]->ID holds.
ONLY POINTERS ARE MOVED.  The Part records THEMSELVES ARE NOT DISTURBED OR MOVED AROUND.*/
{
  //calls function
  int selectsmallestID (Index, int, int);

  //variable 
  int smallestSortedID = 0;
  int i;

  //for-loop begins
  for (i = 0; i < size - 1; i++)
  {
      //stores smallest ID
      smallestSortedID = selectsmallestID(ptrs, i, size - 1);
      //swaps if smallestSorted is found and is smaller then it swaps the 2 
      swap(ptrs[i], ptrs[smallestSortedID]);

  }//end for-loop
};

int selectsmallestPrice (Index ptrs, int first, int last)
/*Pre: "first" through "last" elements of the ptrs array are pointers to Part
records containing data.
Post: A value k is returned such that, for i ranging from first to last,
the relation ptrs[k]->Price <= ptrs[i]->Price holds.*/
{
    int i, final;
    final = first;

    for (i = first + 1; i <= last; i++)
    {
        if (ptrs[i]->Price <= ptrs[final]->Price)
        {
            final = i;
        }
    }
    return final;
};

void sortbyPrice (Index ptrs, int size)
/*Pre: The first "size" elements of the ptrs array are pointers to Part records
containing data.
Post: for i ranging from 1 to size-2, the relation ptrs[i]->Price <= ptrs[i+1]->Price holds.
ONLY POINTERS ARE MOVED.  The Part records THEMSELVES ARE NOT DISTURBED OR MOVED AROUND.*/
{
  int selectsmallestPrice (Index, int, int);

  //variable 
  int smallestSortedID = 0;
  int i;

  //for-loop begins
  for (i = 0; i < size - 1; i++)
  {
      //stores smallest price
      smallestSortedID = selectsmallestPrice(ptrs, i, size - 1);
      //swaps if smallestSorted is found and is smaller then it swaps the 2 
      swap(ptrs[i], ptrs[smallestSortedID]);

  }//end for-loop
};

void deallocate (Index & ptrs, int & size)
/*Pre: ptrs is a pointer pointing to an allocated dynamic array of "size" Part record pointers.
Post: ptrs points to a dynamic pointer array.  The "size" elements of the dynamic array, filled with
pointers to dynamically allocated Part records, are now deallocated, and then the array of
pointers that ptrs points to is itself deallocated, with ptrs reset to nullptr and size reset to 0.*/
{
  for (int i=0; i<size; i++) delete (ptrs[i]);
  delete ptrs;
  ptrs = nullptr;
  size = 0;
};
