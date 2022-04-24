#include <iostream>
#include <random>
#include <ctime>
#include "ArrayList.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    srand(time(0));
    ArrayList a;
    for (int i = 0; i < 10; ++i)
    {
        a.pushend(rand() % 100);
    }

    cout << a << endl;

    a.sort();
    cout << a << endl;
    
    a.insert(20, 7);
    cout << a << endl;
    a.sort();
    cout << a << endl;

    return EXIT_SUCCESS;
}
