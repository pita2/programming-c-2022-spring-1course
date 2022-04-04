#include "Fraction.hpp"
#include <cmath>

Fraction::Fraction(long long numerator, long long denominator) : numerator(numerator), denominator(denominator)
{
    this->normalize();
};

Fraction::Fraction(const Fraction& fraction) : numerator(fraction.numerator), denominator(fraction.denominator) {};

Fraction::~Fraction()
{
    this->numerator = 0;
    this->denominator = 1;
};

double Fraction::getNumerator()
{
    return this->numerator;
}
void Fraction::setNumerator(long long numerator)
{
    this->numerator = numerator;
}

double Fraction::getDenominator()
{
    return this->denominator;
}
void Fraction::setDenominator(long long denominator)
{
    this->denominator = denominator;
}

void Fraction::set(long long numerator, long long denominator)
{
    this->numerator = numerator;
    this->denominator = denominator;
}

Fraction Fraction::abs()
{
    return Fraction(::abs(this->numerator), ::abs(this->denominator));
}

void Fraction::normalize()
{
    long long a = this->numerator;
    long long b = this->denominator;
    if (a < 0)
    {
        a = -a;
    }
    if (b < 0)
    {
        b = -b;
    }
    if (a < b)
    {
        std::swap(a, b);
    }
    while (b != 0) {
        a %= b;
        std::swap (a, b);
    }
    long long nod = a;
    if (this->numerator < 0 && this->denominator < 0)
    {
        this->numerator = this->numerator / nod * (-1);
        this->denominator = this->denominator / nod * (-1);
    }
    else if (this->numerator >= 0 && this->denominator < 0)
    {
        this->numerator = this->numerator / nod * (-1);
        this->denominator = this->denominator / nod * (-1);
    }
    else
    {
        this->numerator = this->numerator / nod;
        this->denominator = this->denominator / nod;
    }
}

Fraction Fraction::reverse()
{
    Fraction a(this->denominator, this->numerator);
    a.normalize();
    return a;
}

Fraction Fraction::deg(int n)
{
    Fraction p = (*this);
    for (int i = 0; i < n - 1; ++i)
    {
        p = p * (*this);
    }
    return p;
}

std::ostream& operator<<(std::ostream& stream, const Fraction& fraction)
{
    Fraction a(fraction.numerator, fraction.denominator);
    a.normalize();
    if (a.numerator == 0)
    {
        stream << a.numerator << std::endl;
    }
    if (a.denominator == 1)
    {
        stream << a.numerator << std::endl;
    }
    else
    {
        stream << a.numerator << "/" << a.denominator;
    }
    return stream;
}

void Fraction::operator=(const Fraction& fraction)
{
    this->numerator = fraction.numerator;
    this->denominator = fraction.denominator;
}

Fraction operator+(const Fraction& fraction1, const Fraction& fraction2)
{
    Fraction a(fraction1.numerator * fraction2.denominator + fraction2.numerator * fraction1.denominator, fraction1.denominator * fraction2.denominator);
    a.normalize();
    return a;
}

Fraction operator-(const Fraction& fraction1, const Fraction& fraction2)
{
    Fraction a(fraction1.numerator * fraction2.denominator - fraction2.numerator * fraction1.denominator, fraction1.denominator * fraction2.denominator);
    a.normalize();
    return a;
}

Fraction operator/(const Fraction& fraction1, const Fraction& fraction2)
{
    Fraction a(fraction1.numerator * fraction2.denominator, fraction1.denominator * fraction2.numerator);
    a.normalize();
    return a;
}

Fraction operator*(const Fraction& fraction1, const Fraction& fraction2)
{
    Fraction a(fraction1.numerator * fraction2.numerator, fraction1.denominator * fraction2.denominator);
    a.normalize();
    return a;
}

Fraction operator*(long long d, const Fraction& fraction)
{
    Fraction a(fraction.numerator * d, fraction.denominator);
    a.normalize();
    return a;
}

Fraction operator*(const Fraction& fraction, long long d)
{
    Fraction a(fraction.numerator * d, fraction.denominator);
    a.normalize();
    return a;
}

bool operator<(const Fraction& fraction1, const Fraction& fraction2)
{
    if (fraction1.numerator * fraction2.denominator < fraction1.denominator * fraction2.numerator)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

bool operator>(const Fraction& fraction1, const Fraction& fraction2)
{
    if (fraction1.numerator * fraction2.denominator > fraction1.denominator * fraction2.numerator)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

bool operator<=(const Fraction& fraction1, const Fraction& fraction2)
{
    if (fraction1.numerator * fraction2.denominator <= fraction1.denominator * fraction2.numerator)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

bool operator>=(const Fraction& fraction1, const Fraction& fraction2)
{
    if (fraction1.numerator * fraction2.denominator >= fraction1.denominator * fraction2.numerator)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

bool operator==(const Fraction& fraction1, const Fraction& fraction2)
{
    if (fraction1.numerator * fraction2.denominator == fraction1.denominator * fraction2.numerator)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
