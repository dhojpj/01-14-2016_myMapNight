#ifndef BASENODE_H
#define BASENODE_H

#include <cstdlib>

class baseNode
{
public:
    baseNode();


    // these are all virtual, therefore they will be declared in the derived classes
    virtual ~baseNode();
    virtual baseNode& operator=(const baseNode &other);

    virtual bool operator<(const baseNode &x) const;
    virtual bool operator<=(const baseNode &x) const;
    virtual bool operator>(const baseNode &x)const;
    virtual bool operator>=(const baseNode &x)const;
    virtual bool operator==(const baseNode &x) const;
    virtual bool operator!=(const baseNode &x) const;
    baseNode*& nextNode();
    void * getFirst() const;
    void setFirst(void *ptr);

protected:
    void *first;
    baseNode *next;

private:

};

#endif // BASENODE_H
