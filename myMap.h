#ifndef MYMAP_H
#define MYMAP_H
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "linkedlink.h"
#include "node.h"

template<typename K, typename V>
class myMap : public linkedList
{
public:
    myMap(unsigned int size = 500)
    {
        maxQty = size;
        anchor = new baseNode;
    }
    ~myMap();
    myMap(const myMap<K,V> &other);
    myMap<K,V>& operator=(const myMap<K,V> &other);

    V& operator[](const K& index);
    const V& operator[](const K& index) const;
    void insert(const K& key, const V& value);
    void erase(K key);
    void clear();

    template<typename k, typename v>
    friend
    ostream& operator<<(ostream &out, const myMap<k,v> &other);

    template<typename k, typename v>
    friend
    istream& operator>>(istream &in, myMap<k,v> &other);

private:

    void copy(const myMap<K,V> &other);
    void nukem();
    baseNode * find(const K& index);
};

template<typename K, typename V>
myMap<K,V>::~myMap()
{
    delete anchor;
    nukem();
}

template<typename K, typename V>
myMap<K,V>::myMap(const myMap<K,V> &other)
{
    copy(other);
}

template<typename K, typename V>
myMap<K,V>& myMap<K,V>::operator=(const myMap<K,V> &other)
{
    if(this != *other)
    {
        nukem();
        copy(other);
    }
    return *this;
}

template<typename K, typename V>
baseNode* myMap<K,V>::find(const K& index)
{
    baseNode *ptr = anchor->nextNode();

    for(;ptr && *(K*)(ptr->getFirst()) != index; ptr = ptr->nextNode());

    if(!ptr)
        throw NOT_FOUND;

    return ptr;
}

// returning value
// this doesn't get called...
template<typename K, typename V>
const V& myMap<K,V>::operator[](const K& index) const
{
    baseNode *ptr;

    ptr = find(index);
    if(!ptr)
        throw NOT_FOUND;

    return ((node<K,V>*)ptr)->theValue();
}


// if blank, puts the value into the node and returns it
template<typename K, typename V>
V& myMap<K,V>::operator[](const K& index)
{
    baseNode *ptr;

    try
    {
        ptr = find(index);
    }
    catch(...)
    {
        // create if nothing is found
        V value;
        node<K,V>* x = new node<K,V>(index, value);
        ptr = x; // parent can take a child pointer
        linkedList::insert(ptr);
    }


    return ((node<K,V>*)ptr)->theValue();
}

template<typename K, typename V>
void myMap<K,V>::insert(const K& key, const V& value)
{
    node<K,V> *ptr = new node<K,V>(key,value);
    linkedList::insert(ptr); // static function
}


template<typename K, typename V>
void myMap<K,V>::erase(K key)
{
    //    void *whom = f; //HINT: Here is an "issue"
    baseNode *f;

    try
    {
        f = find(key);
    }
    catch(...)
    {
        cout << "Error: Key not found\n";
//        exit(101);
    }

    try
    {
        linkedList::erase(f);
    }
    catch(...)
    {
        cout << "Error: Nothing to erase\n";
    }


}

template<typename K, typename V>
void myMap<K,V>::clear()
{
    nukem();
}

template<typename K, typename V>
void myMap<K,V>::copy(const myMap<K,V> &other)
{
    baseNode *ptr = other.anchor.nextNode();
    for(; ptr; ptr = ptr->nextNode())
        insert(((node<K,V>*)ptr)->getFirst(),
               ((node<K,V>*)ptr)->theKey());
}

template<typename K, typename V>
void myMap<K,V>::nukem()
{
    baseNode *ptr = anchor, *bye;
    while(ptr->nextNode())
    {
        bye = ptr->nextNode();
        ptr = ptr->nextNode();
        delete bye;
    }
    anchor->nextNode() = NULL;
    qty = 0;
}

template<typename k, typename v>
ostream& operator<<(ostream &out, const myMap<k,v> &other)
{
    baseNode *ptr = other.anchor->nextNode();
    for(; ptr; ptr=ptr->nextNode())
        out<<*(node<k,v>*)ptr << std::endl;
    return out;
}

template<typename k, typename v>
istream& operator>>(istream &in, myMap<k,v> &other)
{
    node<k,v> newNode;
    while(in>>newNode)
        insert(newNode.theKey(), newNode.theValue());
    return in;
}

#endif // MYMAP_H
