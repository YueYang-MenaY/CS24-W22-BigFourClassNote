
#include<iostream>

class complex{
    private:
        int real; 
        int image;

    public: 
        void print() const; 
        int getreal() const;
        int getimage() const;

        complex(int re=0, int im=0);

        ~complex(); 

        complex(const complex& c); 
};
