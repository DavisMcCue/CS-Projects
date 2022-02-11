// COMMONLY NEEDED DIRECTIVES AND DECLARATIONS

#include <iostream>
using namespace std;

// CLASS DECLARATION

class DB
{
public:
  void store ();
  void viewChronologically ();
  void sortbyPartID ();
  void viewbyPartID ();
  void viewbyPrice();
  void sortbyPrice();

private:
  class Part // This "public class" could also be a "struct" instead.
  {
  public:
    int ID;
    float Price;
    int Quantity;
    Part (void): ID(0), Price(0), Quantity(0) {};
    Part(int Partnum, float rate, int quant) : ID(Partnum), Price(rate), Quantity(quant) {};  // DO: Initialize appropriately.
    // DO: Can you ALSO think of initializing it in a different way?
    void store ()
    {
        cout << "Enter ID: ";
        cin >> ID;
        cout << "Enter Unit Price: ";
        cin >> Price;
        cout << "Enter Inventory Quantity: ";
        cin >> Quantity;
    };
    void print () {cout << "Part ID: " << ID << " Unit Price = " << Price << " Inventory = " << Quantity << endl;};
  };
  Part inv[3];
  Part* IDp[3];
  void swap (Part * &, Part * &);
};

// CLASS DEFINITION

void DB::store ()
{
  cout << "Input ID, price, and quantity for three parts, as prompted" << endl;
  for (int i = 0; i < 3; i++)
  {
      cout << "Part " << (i + 1) << ":" << endl;
      inv[i].store();
      IDp[i] = &inv[i];
  };
  cout << "Thank you. The Three parts have been securely stored in the database." << endl;
};

void DB::viewChronologically ()
{
  cout << "The three items in the database (in chronological order) are: " << endl;
  for (int i = 0; i < 3; i++) inv[i].print();
};

// DO: Fill in the definition for the swap method in the DB class:
void DB::swap(Part*& a, Part*& b)
{
    Part *temp1 = a;
    a = b;
    b = temp1;
};

void DB::sortbyPartID ()
{
  if (IDp[0]->ID > IDp[1]->ID) swap (IDp[0], IDp[1]);
  if (IDp[1]->ID > IDp[2]->ID)
    {
      swap (IDp[1], IDp[2]);
      if (IDp[0]->ID > IDp[1]->ID) swap (IDp[0], IDp[1]);
    }
};

void DB::viewbyPartID ()
{
    cout << "The three items in the database (ordered by Part ID) are: " << endl;
    for (int i = 0; i < 3; i++)
    {
        IDp[i]->print();
    }
};

void DB::sortbyPrice()
{
    if (IDp[0]->Price > IDp[1]->Price) swap(IDp[0], IDp[1]);
    if (IDp[1]->Price > IDp[2]->Price)
    {
        swap(IDp[1], IDp[2]);
        if (IDp[0]->Price > IDp[1]->Price) swap(IDp[0], IDp[1]);
    }
};

void DB::viewbyPrice()
{
    cout << "The three items in the database (sorted Price) are: " << endl;
    for (int i = 0; i < 3; i++)
    {
        IDp[i]->print();
    }
}

int main ()
{
  DB DB1;
  //Part A
  DB1.store();
  DB1.sortbyPartID();
  DB1.viewbyPartID();
  DB1.viewChronologically();
  
  //Part B
  DB1.sortbyPrice();
  DB1.viewbyPrice();
  DB1.sortbyPartID();
  DB1.viewbyPartID();
  DB1.viewChronologically();
  
  cout << "Have a good day!  Bye!" << endl;
  exit (0);
};
