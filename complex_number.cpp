#include <iostream>
using namespace std;

class Complex
{
    private:
        int real;
        int imaginary;
    
    public:
        void getDetails();
        void displayDetails();
};

void Complex::getDetails()
{
    cout << "Enter real part of number: ";
    cin >> real;
    cout << "Enter imaginary part of number: ";
    cin >> imaginary;
}

void Complex::displayDetails()
{
    cout << real << "+" << imaginary << "i" << endl;
}

int main()
{
    Complex com[10];
    for(int i=0; i<10; i++){
        cout << "\nFor number " << i+1 << endl;
        com[i].getDetails();
    }

    cout << "\n\nAll complex numbers: " << endl;
    for(int i=0; i<10; i++){
        com[i].displayDetails();
    }
    return 0;
}