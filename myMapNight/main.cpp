#include <iostream>
#include "myMap.h"

using namespace std;

int main ()
{
    cout<<"Starting the demonstration program"<<endl;

//    myMap<char,string>* mymap = new myMap<char,string>;

    myMap<char,string> mymap;

    cout<<"Safely declared a myMap"<<endl;


    mymap['a']="an element";
    mymap['b']="another element";
    mymap['c']=mymap['b'];


    cout << "mymap['a'] is " << mymap['a'] << endl;
    cout << "mymap['b'] is " << mymap['b'] << endl;
    cout << "mymap['c'] is " << mymap['c'] << endl;
    cout << "mymap['d'] is " << mymap['d'] << endl;

    cout << "mymap now contains " << mymap.size() << " elements.\n";

    myMap<string,int> mymap2;

    mymap2["one"]= 1;
    mymap2["two"]= 2;
    mymap2["three"]= mymap2["two"];

    cout << "mymap2[\"one\"] is " << mymap2["one"] << endl;
    cout << "mymap2[\"two\"] is " << mymap2["two"] << endl;
    cout << "mymap2[\"three\"] is " << mymap2["three"] << endl;
    cout << "mymap2[\"four\"] is " << mymap2["four"] << endl;

    cout << "mymap2 now contains " << mymap2.size() << " elements.\n";

    return 0;
}
