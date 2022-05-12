#include "Pair.hpp"
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<sstream>
#include<iostream>

Pair::Pair()
{
    set_first(0);
    set_second(0);
}

Pair::Pair(int f, int s)
{
    if (s < 0)
    {
        throw Exception("invalid_argument: The value less than 0!");
    }
    set_first((long)f);
    set_second((unsigned short)s);
}

void Pair::set_second(int value)
{
    if (value < 0)
    {
        throw MyException("Exception: The value less than 0!");
    }
    else
    {
        second = (unsigned short)value;
    }
}

Pair::Pair(const Pair& p)
{
    first = p.first;
    second = p.second;
}

Pair& Pair::operator = (const Pair& p)
{
    first = p.first;
    second = p.second;
    return *this;
}

Pair::operator string() const
{
    stringstream a;
    a << get_first() << "," << get_second() << endl;
    return a.str();
}

ostream& operator << (ostream& out, const Pair& p)
{
    out << string(p);
    return out;
}

istream& operator >> (istream& in, Pair& p)
{
    int a, b;
    cout << " First number: "; cin >> a;
    cout << " Second number: "; cin >> b;
    if (b < 0)
    {
        throw invalid_argument("MyException: The value less than 0!");
    }
    p.set_first((long)a);
    p.set_second((unsigned short)b);
    return in;
}

bool operator > (const Pair& p1, const Pair p2)
{
    if(p1.get_first() > p2.get_first()
       ||
       (p1.get_first() > p2.get_first() && p1.get_second() > p2.get_second()))
    {
        return true;
    }
    else
    {
        return false;
    }
}
