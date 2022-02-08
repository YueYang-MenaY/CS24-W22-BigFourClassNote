#include <iostream> 
#include <cmath>
#include "testBigFour.h" 

using namespace std; 

//if we take complex c by value again in other function
// copy constuctor is called, if not, copy constructor will not be called 
void foo(complex c){
    cout<<"foo\n"; 
}

// OPERATOR: cout<< 
// non-member function 
// cout is a type of ostream and need to be called by iostream, because a copy is not allowed 
// the double & hear is neccessary 
ostream& operator<<(ostream& cout,complex& c){
    c.print(); 
    return cout; 
    // with the ostream return type, and line 19 we can add enld; 
}

//OPERATOR: +
// c needs to be called by reference
// this can only be used in the member function 
complex operator+(complex& c1, complex& c2){
    return complex (c1.getreal()+c2.getreal(), c1.getimage()+c2.getimage());
}

int main(){
    // test the operator<<
    complex c1(10,20); 
    cout<<c1<<endl; //cout.operator<<(c1) belongs to ostream class which we can't change

    // test the operator+
    complex c2(30,10), c3;
    c3 = c1+c2; // c3 = operator+(c1, c2)
                // c1.operator+(c2) function belongs to complex 
    cout<< "c3: "<<c3;

    // test the copy constructor 
    complex c4(c3); 
    cout<<"c4: "<<c4;
    complex *c5 = &c3; 
    cout<<"c5: "<<c5<<endl; 
    complex c6(*c5);
    cout<<"c6: "<<c6;

    return 0;
}