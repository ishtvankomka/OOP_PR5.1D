#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include "Exception.h"
#include "MyException.h"
using namespace std;

class Pair {
    long int first;
    unsigned short int second;
public:
    Pair ();
    Pair (int, int);
    Pair (const Pair&);
    Pair& operator = (const Pair&);

    operator string() const;
    friend ostream& operator << (ostream& out, const Pair&);
    friend istream& operator >> (istream& in, Pair&);
    
    void set_first(long int value) { first = value; };
    void set_second(int value);
    long int get_first() const { return first; };
    unsigned short int get_second() const { return second; };
    
    friend bool operator > (const Pair&, const Pair);
};
