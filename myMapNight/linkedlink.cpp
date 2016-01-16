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


void linkedList::insert(baseNode *whom)
{
    std::cout << "linkedList insert\n";
    if (!qty)
    {
        anchor = whom;
    }
    else
    {
        qty++;
        // going to get the anchor's next node
        baseNode *ptr = anchor;

        // searching
        for(; ptr->nextNode() && ptr->nextNode()->getFirst() < whom->getFirst(); ptr = ptr->nextNode());

        // if not found, insert at the end
        if(!ptr)
        {
//                qty++;
            ptr->nextNode() = whom;
            return;
        }
        whom->nextNode() = ptr->nextNode();
        ptr->nextNode() = whom;
    }
//    qty++;
}

void linkedList::erase(void *whom)
{
    baseNode *ptr = anchor, *bye;
    for(; ptr->nextNode() && ptr->nextNode() < whom; ptr = ptr->nextNode());
    if(!ptr->nextNode() || ptr->nextNode()->getFirst() != whom)
        throw NOT_FOUND;
    bye = ptr->nextNode();
    ptr->nextNode() = bye->nextNode();
    delete bye;
    qty--;
}
