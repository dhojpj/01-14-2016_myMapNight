#include <iostream>
#include "myMap.h"

using namespace std;

int main ()
{
    cout<<"Starting the demonstration program"<<endl;

    myMap<char,string> mymap;

    cout<<"Safely declared a myMap"<<endl;


//    cin >> mymap;

    mymap['a']="an element";
    mymap['b']="another element";
    mymap['c']=mymap['b']; // memory


//    cout << "mymap['a'] is " << mymap['a'] << endl;
//    cout << "mymap['b'] is " << mymap['b'] << endl;
//    cout << "mymap['c'] is " << mymap['c'] << endl;
//    cout << "mymap['d'] is " << mymap['d'] << endl; // inserts empty node

    cout << mymap << endl;
    cout << "mymap now contains " << mymap.size() << " elements.\n\n";



    mymap.erase('a'); // 'b' or 'c' doesn't work
//    mymap.erase('c');
//    mymap.erase('b');

    cout << "deleted a" << endl;

//    mymap.clear();

    cout << mymap << endl;

    cout << "mymap now contains " << mymap.size() << " elements.\n\n";







//    myMap<string,int> mymap2;

//    mymap2["one"]= 1;
//    mymap2["two"]= 2;
//    mymap2["three"]= mymap2["two"]; // memory

////    cout << "mymap2[\"one\"] is " << mymap2["one"] << endl;
////    cout << "mymap2[\"two\"] is " << mymap2["two"] << endl;
////    cout << "mymap2[\"three\"] is " << mymap2["three"] << endl;
////    cout << "mymap2[\"four\"] is " << mymap2["four"] << endl;

//    cout << "mymap2 now contains " << mymap2.size() << " elements.\n\n";


//    cout << mymap2 << endl;

//    mymap2.erase("one"); // not erasing node "one" node

//        cout << "mymap2 now contains " << mymap2.size() << " elements.\n\n";
//        cout << mymap2 << endl;

//    mymap2.clear();

//    cout << "mymap2 now contains " << mymap2.size() << " elements.\n\n";


//    cin >> mymap2;

//    cout << "mymap2 now contains " << mymap2.size() << " elements.\n\n";



//    cout << mymap2 << endl;

    return 0;
}
