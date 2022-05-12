#include <iostream>
#include <stddef.h>
#include <stdio.h>
#include "Pair.hpp"
#include "Fraction.hpp"
using namespace std;

int main() {
    try
    {
        int f, s;
        cout << " Set the integer "; cin >> f;
        cout << " Set the fraction "; cin >> s;
        Fraction n1(f, s);
        cout << "The number is ";
        Display(n1);
        
        
        Fraction n2;
        Read(n2);
        cout << "The number is ";
        Display(n2);
        
        Fraction nmultiplication;
        nmultiplication = n1 * n2;
        cout << " Multiplication: ";
        Display(nmultiplication);
        
        if (n1 > n2)
        {
            cout << " n1 > n2" << endl;
        }
    }
    catch (MyException* e)
    {
        cerr << e->What() << endl;
    }
    catch (MyException& e)
    {
        cerr << e.What() << endl;
    }
    catch (Exception* e)
    {
        cerr << e->What() << endl;
    }
    catch (Exception& e)
    {
        cerr << e.What() << endl;
    }
    catch (invalid_argument e)
    {
        cerr << e.what() << endl;
    }
    
    try
    {
        int a, b;
        cout << " First number: "; cin >> a;
        cout << " Second number: "; cin >> b;
        Pair p1(a, b);
        cout << "The number is ";
        cout << p1;
        
        Pair p2;
        cout << "Set the number ";
        cin >> p2;
        cout << "The number is ";
        cout << p2;
    
    }
    catch (MyException* e)
    {
        cerr << e->What() << endl;
    }
    catch (MyException& e)
    {
        cerr << e.What() << endl;
    }
    catch (Exception* e)
    {
        cerr << e->What() << endl;
    }
    catch (Exception& e)
    {
        cerr << e.What() << endl;
    }
    catch (invalid_argument e)
    {
        cerr << e.what() << endl;
    }
    return 0;
}


