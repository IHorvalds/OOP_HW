// TemaPOOCroitoru.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Object.h"
#include "Stack.h"
#include <fstream>

std::ifstream file("Text.txt");

int main()
{
    //After every exercise, display the Stack

    std::cout << "1. Read the stack (from a file)" << "\n\n";
    Stack* st = new Stack();
    file >> *st;

    std::cout << *st << "\n\n";


    std::cout << "2. Invert the stack" << "\n\n";
    std::cout << st->reverse() << "\n\n";

    std::cout << "3. Invert it again" << "\n\n";
    std::cout << st->reverse() << "\n\n";

    std::cout << "4. Copy it in a different stack" << "\n\n";

    Stack* newStack = new Stack(*st);
    std::cout << "New stack address:" << (long long int) newStack << "\n";
    std::cout << *newStack << "\n\n";
    std::cout << "Vs old stack address: " << (long long int) st << "\n"; 
    std::cout << *st << "\n\n";

    std::cout << "5. Empty the initial stack" << "\n\n";

    std::cout << "Emptying " << (long long int) st << ": " << st->Empty() << "\n";
    std::cout << "Displaying emptied stack: \n" << *st << "\n";

    std::cout << "Displaying the copy " << (long long int) newStack << ": \n";
    std::cout << *newStack << "\n\n";

    std::cout << "Deleting the stacks\n";
    delete st;
    delete newStack;
    st = NULL;
    newStack = NULL;
    std::cout << (long long int)st << ", " << (long long int)newStack << "\n";

    std::cout << "Hello World!\n"; // I just like it here.

    //Object o, c;
    //std::cin >> o;
    //std::cout << o << '\n';

    //std::cin >> c;
    //std::cout << c << '\n';
    //std::cout << (o == c) << ' ' << (o != c) << (o < c) << (o > c) << (o <= c) << (o >= c);
    return 0;
}

