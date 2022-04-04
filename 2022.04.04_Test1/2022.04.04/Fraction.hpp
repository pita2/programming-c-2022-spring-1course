#pragma once
#include <iostream>
class Fraction
{
private:
    long long numerator;
    long long denominator;
    
public:
    Fraction(long long numerator = 0, long long denominator = 1);
    Fraction(const Fraction& fraction);
    ~Fraction();
    
    double getNumerator();
    void setNumerator(long long numerator);
    
    double getDenominator();
    void setDenominator(long long denominator);
    
    void set(long long numerator, long long denominator);
    
    Fraction abs();
    
    void normalize();
    
    Fraction reverse();
    
    Fraction deg(int n);
    
    friend std::ostream& operator<<(std::ostream& stream, const Fraction& fraction);
    
    void operator=(const Fraction& fraction);
    friend Fraction operator+(const Fraction& fraction1, const Fraction& fraction2);
    friend Fraction operator-(const Fraction& fraction1, const Fraction& fraction2);
    friend Fraction operator/(const Fraction& fraction1, const Fraction& fraction2);
    friend Fraction operator*(const Fraction& fraction1, const Fraction& fraction2);
    friend Fraction operator*(long long d, const Fraction& fraction);
    friend Fraction operator*(const Fraction& fraction, long long d);
    
    friend bool operator<(const Fraction& fraction1, const Fraction& fraction2);
    friend bool operator>(const Fraction& fraction1, const Fraction& fraction2);
    friend bool operator<=(const Fraction& fraction1, const Fraction& fraction2);
    friend bool operator>=(const Fraction& fraction1, const Fraction& fraction2);
    friend bool operator==(const Fraction& fraction1, const Fraction& fraction2);
};
