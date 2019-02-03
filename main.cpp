#include <iostream>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <cstdio>
#include <ctime> // For the time() and srand() functions

using namespace std::chrono;
using std::cout;
using std::cerr;
/*
    Task: Fill an array of 5000 Elements with random numbers,
          then print every 500th number to the console.
          (i + 1) % 500
*/
const int ARRAYSIZE = 5000;

void staticArrayFunction();
void dynamicArrayFunction();

int main ()
{
    srand(time(0)); // Seeds PRNG
    
    // Static Array Function Test
    auto start1 = high_resolution_clock::now();
    staticArrayFunction();
    auto stop1 = high_resolution_clock::now();
    auto d1 = duration_cast<microseconds>(stop1 - start1);
    cout << "\nThe static array function took " << d1.count()
         << " microseconds to execute.\n\n";

    // Dynarray Function Test
    auto start2 = high_resolution_clock::now();
    dynamicArrayFunction();
    auto stop2 = high_resolution_clock::now();
    auto d2 = duration_cast<microseconds>(stop2 - start2);
    cout << "\nThe dynarray function took " << d2.count()
         << " microseconds to execute.\n";
    
    cout << "\nHot damn.\nThe dynarray was actually "
         << std::setprecision(2) << std::fixed
         << (1.0 - (static_cast<double>(d2.count()) / d1.count())) * 100
         << "\% faster than the static array!\n";
    return 0;
}

// Uses a statically allocated Array
void staticArrayFunction()
{
    cout << "Static Array Function called.\n";
    int staticArray[ARRAYSIZE];
    for (int i = 0; i < ARRAYSIZE; i++)
    {
        staticArray[i] = rand() % 100 + 1;
        if (!((i + 1) % 500))
            cout << staticArray[i] << ' ';
    }
}

// Uses Dynamically Allocated Array, dubbed "DYNARRAY"
void dynamicArrayFunction()
{
    cout << "Dynarray Function called.\n";
    int* dynarray = new int[ARRAYSIZE];
    for (int i = 0; i < ARRAYSIZE; i++)
    {
        dynarray[i] = rand() % 100 + 1;
        if (!((i + 1) % 500))
            cout << dynarray[i] << ' ';
    } 
    delete [] dynarray;
    dynarray = nullptr;
}
