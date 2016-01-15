#include <iostream>
#include "node.h"
using namespace std;

int main()
{
    //    cout << "Hello World!" << endl;

    //    baseNode *bn = new baseNode;

    node<char,int>* n = new node<char,int>('c',1);

    cout << n->getFirst() << endl;
//    cout << n->theKey() << endl;
    cout << n->theKey() << endl;
    cout << n->theValue() << endl << endl;




    return 0;
}

