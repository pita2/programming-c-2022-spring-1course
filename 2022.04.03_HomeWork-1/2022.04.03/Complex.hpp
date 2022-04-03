#pragma once
#include <iostream>
class Complex
{
private:
    double re;
    double im;
    
public:
    Complex(double re = 0, double im = 0);
    Complex(const Complex& complex);
    ~Complex();
    
    double getRe();
    void setRe(double re);
    
    double getIm();
    void setIm(double im);
    
    void set(double re, double im);
    
    double abs();
    
    double arg();
    
    void roots(int n, std::ostream& stream);
    
    Complex reverse();
    
    void operator=(const Complex& complex);
    friend Complex operator+(const Complex& complex1, const Complex& complex2);
    friend Complex operator-(const Complex& complex1, const Complex& complex2);
    friend Complex operator/(Complex& complex1, Complex& complex2);
    friend Complex operator*(const Complex& complex1, const Complex& complex2);
    friend Complex operator*(double d, const Complex& complex);
    friend Complex operator*(const Complex& complex, double d);
    
    friend std::ostream& operator<<(std::ostream& stream, const Complex& complex);
    

};


