#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef int elementtype;

struct celltype
{
    elementtype element;
    celltype *next;
    celltype *prev;
};

typedef celltype *position;

class Lista
{

protected:
    position l; // wskaźnik do głowy listy

public:
    Lista();  // konstruktor
    ~Lista(); // destruktor

    void Insert(elementtype x, position p);
    void Delete(position p);
    elementtype Retrieve(position p);
    position Locate(elementtype x);
    position First();
    position Next(position p);
    position Previous(position p);
    position END();
    void Print();

    elementtype Top();
    void Pop();
    void Push(elementtype x);
};

Lista::Lista()
{
    l = new celltype;
    l->next = NULL;
}

Lista::~Lista()
{
    position next = l;

    while (next)
    {
        position deleteMe = next;
        next = next->next;
        delete deleteMe;
    }
}

void Lista::Print()
{

    position head = l;

    while (head != END())
    {
        cout << Retrieve(head) << " ";
        head = head->next;
    }
    cout << endl;
}

position Lista::First()
{
    return l;
}

position Lista::END()
{
    position p = l;
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p;
}

position Lista::Next(position p)
{
    return p->next;
}

position Lista::Previous(position p)
{
    position tmp;
    tmp = l;
    while (tmp->next != p)
    {
        tmp = tmp->next;
    }
    return tmp;
}

void Lista::Insert(elementtype x, position p)
{
    position tmp = p->next;
    p->prev = p;
    p->next = new celltype;
    p->next->element = x;
    p->next->next = tmp;
}

void Lista::Delete(position p)
{
    position current = p->next;
    p->next = p->next->next;
    delete current;
}

position Lista::Locate(elementtype x)
{
    position tmp;
    tmp = l;
    while (tmp->next != NULL)
    {
        if (tmp->next->element == x)
            return tmp;
        tmp = tmp->next;
    }
    return tmp;
}

elementtype Lista::Retrieve(position p)
{
    if (p->next != NULL)
        return p->next->element;
}

elementtype Lista::Top()
{
    return Retrieve(First());
}

void Lista::Pop()
{
    Delete(First());
}

void Lista::Push(elementtype x)
{
    Insert(x, First());
}

int main()
{
    Lista stos;

    stos.Push(2);
    stos.Push(8);
    stos.Push(1);
    stos.Push(7);
    stos.Print();

    stos.Pop();
    stos.Print();

    cout << stos.Top() << endl;

    return 0;
}