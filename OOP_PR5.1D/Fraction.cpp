#include "Fraction.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdlib>
using namespace std;

Fraction::Fraction()
{
    set_first(0);
    set_second(0);
}

Fraction::Fraction(int i, int f)
{
    if (f < 0)
    {
        throw Exception("invalid_argument: The value less than 0!");
    }
    set_first((long)i);
    set_second((unsigned short)f);
}

Fraction::Fraction(const Fraction& f)
{
    *this = f;
}

Fraction& Fraction::operator = (const Fraction& f) {
    set_first(f.get_first());
    set_second(f.get_second());
    return *this;
}

istream& operator >> (istream& in, Fraction& a)
{
    int f, s;
    cout << " Set the integer "; cin >> f;
    cout << " Set the fraction "; cin >> s;
    if (s < 0)
    {
        throw MyException("MyException: The value less than 0!");
    }
    a.set_first((long)f);
    a.set_second((unsigned short)s);
    return in;
}

ostream& operator << (ostream& out, const Fraction& a)
{
    out << string(a);
    return out;
}

Fraction::operator string () const
{
    stringstream a;
    a << get_first() << "." << get_second() << endl;
    return a.str();
}

void Read(Fraction& a)
{
    cout << "Set the number:" << endl; cin >> a;
}

void Display(Fraction& a)
{
    cout << a;
}

double toNumber(string str)
{
    double number;
    istringstream ( str ) >> number;
    return number;
}

double convertToDouble(Fraction& a)
{
    return toNumber(string(a));
}

Fraction toFraction(double n)
{
    stringstream s;
    s << n;

    string str = s.str();
    char* dup = strdup(str.data());

    string integer_a = strtok(dup, ".");
    string fraction_a = strtok(0, "");
    free(dup);
    Fraction nn;
    long int integer_b;
    istringstream(integer_a) >> integer_b;
    nn.set_first(integer_b);

    unsigned short int fraction_b;
    istringstream(fraction_a) >> fraction_b;
    nn.set_second(fraction_b);

    return nn;
}

Fraction operator + (Fraction& a, Fraction& b)
{
    double sum =  convertToDouble(a) + convertToDouble(b);
    return toFraction(sum);
}

Fraction operator * (Fraction& a, Fraction& b)
{
    double a1 = convertToDouble(a);
    double b1 = convertToDouble(b);
    if(a1 == 0)
    {
        throw invalid_argument("invalid_argument: multiplication of 0 is equal 0!");
    }
    if(b1 == 0)
    {
        throw invalid_argument("Exception: multiplication of 0 is equal 0!");
    }
    double sum =  a1  * b1;
    return toFraction(sum);
}
