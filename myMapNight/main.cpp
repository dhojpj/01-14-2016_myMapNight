#include <iostream>
#include "node.h"
using namespace std;

int main()
{
    node<char,int>* n = new node<char,int>('c',1);

    cout << n->getFirst() << endl;
    cout << n->theKey() << endl;
    cout << n->theValue() << endl << endl;


    cout << n << endl;
    cin >> *n;

    cout << *n << endl;


    cout << "This is not me " << *n << " isn't it?\n";


//    cout << n->getFirst() << endl;
//    cout << n->theKey() << endl;
//    cout << n->theValue() << endl << endl;


    return 0;
}

