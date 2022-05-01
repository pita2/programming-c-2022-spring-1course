#include<iostream>
#include"LinkedList.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    LinkedList a;
    cout << a << endl;
    a.pushTail(1);
    a.pushTail(2);
    a.pushTail(3);
    a.pushTail(4);
    a.pushHead(0);
    a.pushHead(-1);
    cout << a << endl;
    
    a.insert(4, 4);
    cout << a << endl;
    a.extract(4);
    cout << a << endl;
    
    a.swap(0, 3);
    cout << a << endl;
    
    return EXIT_SUCCESS;
}
