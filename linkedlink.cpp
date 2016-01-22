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

    // searching
    for(; ptr->nextNode() && ptr->nextNode()->getFirst() < whom->getFirst(); ptr = ptr->nextNode());

    // if not found, insert at the end
    if(!ptr)
    {
        ptr->nextNode() = whom;
        return;
    }
    // or just set it in between nodes
    whom->nextNode() = ptr->nextNode();
    ptr->nextNode() = whom;
}

void linkedList::erase(void *whom)
{
    baseNode *ptr = anchor->nextNode(), *bye;
    for(; ptr->nextNode() && ptr->nextNode() < whom; ptr = ptr->nextNode());
    if(!ptr->nextNode() || ptr->nextNode() != whom)
        throw NOT_FOUND;
    bye = ptr->nextNode();
    ptr->nextNode() = bye->nextNode();
    delete bye;
    qty--;
}
