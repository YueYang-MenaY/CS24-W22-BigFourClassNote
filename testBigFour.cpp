//Lecture 2 Lecture3 

#include <iostream> 
#include <cmath>
#include "testBigFour.h" 

using namespace std; 

int complex::getreal() const{
    return real; 
}
int complex::getimage() const{
    return image; 
}

// ONE: Constructor: sort of suitable for all cases
//initialize in declearation 
complex::complex(int re, int im):real(re), image(im){
     // Swap the sequence of real and image gets a warning
     /* complex(int re=0, int im=0):image(10), real(image){}
         will give 0+10j 
     */
    cout<<"call constructor\n";
} 

//TWO: Destructor 
complex::~complex(){
    /* 
        Everytime when a variable in stack gets out of the memory, destructor called 
        For the pointer pointing to a variable in heap, destructor won't be called to delete that variable 
        Once that variable is deleted, the pointer, which is on stack, will be deleted 
    */
   cout << "destructor is called\n";
}

//THREE: copy constructor 
// takes const complex parameter as reference, if no const or &, compile error 
complex::complex(const complex& c){
    // default: 
    real = c.real;
    image = c.image; 

    cout<<"copy constructor"<<endl; 
}

void complex::print() const{
   if(image>=0){
            cout<<real<<" + "<<image<<"j"<<endl;
        }else{
            cout<<real<<" - "<<-1*image<<"j"<<endl;
        } 
}