#include "linkedlink.h"
#include <iostream>
linkedList::linkedList()
{
    qty = 0;
    maxQty = 50;
    anchor = new baseNode;
}


linkedList::~linkedList()
{
    qty = 0;
    maxQty = 0;
}

bool linkedList::empty()
{
  return !qty;
}

bool linkedList::full()
{
  return !(maxQty - qty);
}

unsigned int linkedList::size()
{
    return qty;
}

unsigned int linkedList::max_size()
{
    return maxQty;
}


// had to fix the insert
void linkedList::insert(baseNode *whom)
{
    qty++;

    baseNode *ptr = anchor;

    // searching if nextNode exists and its first less than whom's first
    for(; ptr->nextNode() && ptr->nextNode()->getFirst() < whom->getFirst(); ptr = ptr->nextNode());

    // if not found, insert at the end
    if(!ptr)
    {
        ptr->nextNode() = whom;
//        return;
    }
    else
    {
        // or just set it in between nodes
        whom->nextNode() = ptr->nextNode();
        ptr->nextNode() = whom;
    }
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void linkedList::erase(void *whom)
{
    baseNode *ptr = anchor, *bye;

    // finds the address of whom
//    std::cout << ptr->nextNode() << std::endl;
//    std::cout << whom << std::endl;

//    std::cin.get();
    // if pointer exists and next < whom
    // why go through this again if already found the key?

    // iterators through to get the previous address
    for(; ptr->nextNode() && (ptr->nextNode() < whom); ptr = ptr->nextNode());
//    {
//        std::cout << "iterator = " << ptr->nextNode() << std::endl;
//        std::cout << "whom parameter = " << whom << std::endl;
//        std::cin.get();
//    }

//    std::cout << "done\n";

//    std::cout << "iterator = " << ptr << std::endl;
//    std::cout << "whom parameter = " << whom << std::endl;
//    std::cout << "iterator->next = " << ptr->nextNode() << std::endl;


//    std::cin.get();

    // if previous node does not exist, something is weird
    if(!ptr)
    {
        throw NOT_FOUND;
//        return;
    }

    bye = ptr->nextNode(); // bye is the whom address to be deleted
    ptr->nextNode() = bye->nextNode(); // the next nextnode is the one after bye



    delete bye;


    qty--;
}
