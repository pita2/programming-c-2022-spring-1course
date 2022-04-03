#include "Complex.hpp"
#include <cmath>

const double PI = 3.141592653589793;

Complex::Complex(double re, double im) : re(re), im(im) {};

Complex::Complex(const Complex& complex) : re(complex.re), im(complex.im) {};

Complex::~Complex()
{
    this->re = 0;
    this->im = 0;
};

double Complex::getRe()
{
    return this->re;
}
void Complex::setRe(double re)
{
    this->re = re;
}

double Complex::getIm()
{
    return this->im;
}
void Complex::setIm(double im)
{
    this->im = im;
}

void Complex::set(double re, double im)
{
    this->re = re;
    this->im = im;
}

Complex Complex::reverse()
{
    Complex a_ = Complex(this->re, this->im * (-1));
    Complex rev = Complex(this->re / (this->re * this->re + this->im * this->im), this->im * (-1) / (this->re * this->re + this->im * this->im));
    return rev;
}

double Complex::abs()
{
    return sqrt(this->re * this->re + this->im * this->im);
}

double Complex::arg()
{
    return atan( this->im / this->re);
}

void Complex::operator=(const Complex& complex)
{
    this->re = complex.re;
    this->im = complex.im;
}

void Complex::roots(int n, std::ostream& stream)
{
    Complex a(this->re, this->im);
    double fi = a.arg();
    double z = a.abs();
    for (int k = 0; k < n; ++k)
    {
        Complex r( pow(z, 1.0/n) * cos((fi * 2*PI*k) / n) , pow(z, 1.0/n) * sin((fi * 2*PI*k) / n) );
        std::cout << r << std::endl;
    }
}

Complex operator+(const Complex& complex1, const Complex& complex2)
{
    return Complex(complex1.re + complex2.re, complex1.im + complex2.im);
}

Complex operator-(const Complex& complex1, const Complex& complex2)
{
    return Complex(complex1.re - complex2.re, complex1.im - complex2.im);
}

Complex operator*(const Complex& complex1, const Complex& complex2)
{
    return Complex(complex1.re * complex2.re - complex1.im * complex2.im, complex1.re * complex2.im + complex1.im * complex2.re);
}

Complex operator*(double d, const Complex& complex)
{
    return Complex(d * complex.re, d * complex.im);
}

Complex operator*(const Complex& complex, double d)
{
    return Complex(d * complex.re, d * complex.im);
}

Complex operator/(Complex& complex1, Complex& complex2)
{
    return Complex(complex1 * complex2.reverse());
}

std::ostream& operator<<(std::ostream& stream, const Complex& complex)
{
    if (complex.im < 0)
    {
        if (complex.im == -1)
        {
            stream << complex.re << " -" << "i" << std::endl;
        }
        else
        {
            stream << complex.re << " " << complex.im << "i" << std::endl;
        }
            
    }
    if (complex.im == 0)
    {
        stream << complex.re << std::endl;
    }
    if (complex.im > 0)
    {
        if (complex.im == 1)
        {
            stream << complex.re << " +" << "i" << std::endl;
        }
        else
        {
            stream << complex.re << " +" << complex.im << "i" << std::endl;
        }
    }
    return stream;
}

