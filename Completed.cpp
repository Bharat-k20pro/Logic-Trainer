#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;
/*
***********************************************Functions**************************************************
*/
int NOT(int);
int OR(int,int);
int AND(int,int);
int NOR(int,int);
int NAND(int,int);
int XOR(int,int);
int XNOR(int,int);
/*
***********************************************Base Class**************************************************
*/
class Base{
  public:
    void get_data()
    {

      cout << "*************************WELCOME TO OUR SMALL PROJECT OF LOGIC GATES IMPLEMENTATION*************************" << endl;
      cout << "\n1. Press 1 for NOT gate." << endl;
      cout << "2. Press 2 for OR gate." << endl;
      cout << "3. Press 3 for AND gate." << endl;
      cout << "4. Press 4 for NOR gate." << endl;
      cout << "5. Press 5 for NAND gate." << endl;
      cout << "6. Press 6 for XOR gate." << endl;
      cout << "7. Press 7 for XNOR gate." << endl;
      cout << "8. Press 8 for exit." << endl;
      cout << "Enter your choice : ";
      cin >> choice;
      system("CLS");
      if(choice<8 && choice>0){
        I_interface();
      }
      else if(choice==8){
        exit(0);
      }
      else{
        cout << "Wrong Choice" << endl;
        system("CLS");
        get_data();
      }
    }
  protected:
    int choice;
    int choice1;
    void I_interface(){
      cout << "1. Press 1 for implementation." << endl;
      cout << "2. Press 2 for Truth Table." << endl;
      cout << "3. Press 3 to back." << endl;
      cout << "Enter your choice : ";
      cin >> choice1;
      system("CLS");
      switch(choice1)
    {
        case 1: implementation();
        break;
        case 2: tableruth();
        break;
        case 3: get_data();
        break;
        default: cout << "Invalid choice....." << endl;
        break;
    }
      }

   void implementation()
   {
     int x, y, z, b;
     cout << "*************************Implementation*************************"<<endl;
    if(choice==1)
    {
        cout << "\nInput : ";
        cin >> x;
        if(x==0 || x==1)
        {
        z = NOT(x);
        cout << "Output : " << z << endl;
        }
        else
        {
            cout << "Invalid Input......." << endl;
        }
    }
    else
    {
      cout << "\nInput 1 : ";
      cin  >> x;
      cout << "Input 2 : ";
      cin >> y;
        if((x==0 || x==1) && (y==0 || y==1) )
    {
        switch(choice)
        {
        case 2: z = OR(x,y);
        break;
        case 3: z = AND(x,y);
        break;
        case 4: z = NOR(x,y);
        break;
        case 5: z = NAND(x,y);
        break;
        case 6: z = XOR(x,y);
        break;
        case 7: z = XNOR(x,y);
        break;
        }
        cout << "Output : " << z << endl;
    }
    else
    {
        cout << "Invalid input......" << endl;
    }
    }
    cout << "Enter 8 to go back......" << endl;
    cout << "Enter 9 to go on interface....." << endl;
    cout << "Enter 0 to exit";
    cin >> b;
    system("CLS");
    if(b==8)
    {
        I_interface();
    }
    else if(b==9)
    {
        get_data();
    }
    else
    {
        exit(0);
    }
   }
   void tableruth()
   {
     cout << "*************************Truth Table*************************" << endl;
    switch(choice){
        case 1: cout<<"\nA"<<setw(9)<<"Not(A)"<<endl;
                cout<<"1"<<setw(7)<<NOT(1)<<endl;
                cout<<"0"<<setw(7)<<NOT(0)<<endl;
                break;
        case 2: truthtable(&OR);
                break;
        case 3: truthtable(&AND);
                break;
        case 4: truthtable(&NOR);
                break;
        case 5: truthtable(&NAND);
                break;
        case 6: truthtable(&XOR);
                break;
        case 7: truthtable(&XNOR);
                break;
    }
    int choicer;
    cout<<"Press 8 to go back....."<<endl;
    cout<<"Press 9 to go on interface....."<<endl;
    cout<<"Press 0 to exit.......";
    cin>>choicer;
    system("CLS");
    if(choicer==8)
        {
        I_interface();
    }
    else if(choicer==9)
        {
        get_data();
    }
    else
    {
        exit(0);
    }
   }
   void truthtable(int (*logic)(int,int))
{

    cout<<"\nA"<<setw(7)<<"B"<<setw(7)<<"Y"<<endl;
    cout<<"0"<<setw(7)<<"0"<<setw(7)<<logic(0,0)<<endl;
    cout<<"0"<<setw(7)<<"1"<<setw(7)<<logic(0,1)<<endl;
    cout<<"1"<<setw(7)<<"0"<<setw(7)<<logic(1,0)<<endl;
    cout<<"1"<<setw(7)<<"1"<<setw(7)<<logic(1,1)<<endl;
}
};

/*
  ***************************************Main Function***********************************
*/
int main() {
Base b1;
b1.get_data();
return 0;
}
/*
***************************************Function Declaration************************************
*/
int NOT(int value)
    {
      int invert;
      invert = (value==1) ? (0) : (1);
      return invert;
    }

    int OR(int n, int m)
    {
      if(n==1 && m==1)
      {
        return 1;
      }
      else
      {
        return n+m;
      }
    }

    int AND(int x, int y)
    {
      return x*y;
    }

    int NOR(int value, int value1)
    {
      int oring = OR(value, value1);
      oring = NOT(oring);
      return oring;
    }

    int NAND(int x, int y)
    {
        int Val;
        Val = AND(x,y);
        Val = NOT(Val);
        return Val;
    }

   int XOR(int n, int m)
   {
      int xoring = OR(AND(NOT(n), m), AND(n, NOT(m)));
      return xoring;
   }

   int XNOR(int n, int m)
   {
     int xnoring = OR(AND(n, m), AND(NOT(n), NOT(m)));
     return xnoring;
   }
