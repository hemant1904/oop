#include <iostream>
using namespace std;

class complex {
    float real;
    float imag;

public:
    complex() {
        real = 0;
        imag = 0;
    }

    friend istream& operator>>(istream& is, complex& t);
    friend ostream& operator<<(ostream& os, complex& t);

    complex operator+(complex& t) {
        complex ans;
        ans.real = real + t.real;
        ans.imag = imag + t.imag;
        return ans;
    }

    complex operator*(complex& t) {
        complex ans;
        ans.real = (real * t.real) - (imag * t.imag);
        ans.imag = (real * t.imag) + (imag * t.real);
        return ans;
    }
};

istream& operator>>(istream& is, complex& t) {
    cout << "Enter the real part : " << endl;
    cin >> t.real;
    cout << "Enter the imaginary part : " << endl;
    cin >> t.imag;
    return is;
}

ostream& operator<<(ostream& os, complex& t) {
    cout << t.real;
    cout << " + " << t.imag << "i" << endl;
    return os;
}

int main() {
    complex a1, a2, a3, a4;

    cout << "Default constructor is invoked : " << endl;
    cout << a1;

    cout << "Enter first complex number : " << endl;
    cin >> a1;

    cout << "Enter second complex number : " << endl;
    cin >> a2;

    cout << "First complex number is : " << a1 << endl;
    cout << "Second complex number is : " << a2 << endl;

    a3 = a1 + a2;
    cout << "Addition of two complex numbers is : " << a3 << endl;

    a4 = a1 * a2;
    cout << "Multiplication of two complex numbers is : " << a4 << endl;

    return 0;
}

