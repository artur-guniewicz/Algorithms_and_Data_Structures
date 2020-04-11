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
    void Duplicate();
    void Purge();
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
    else
        return 1;
}

void Lista::Duplicate()
{
    Lista l2;
    position tmp1 = l, tmp2 = l;

    while (tmp1->next != NULL)
    {
        l2.Insert(tmp1->next->element, l2.END());
        tmp1 = tmp1->next;
    }

    while (tmp2->next != NULL)
    {
        l2.Insert(tmp2->next->element, l2.END());
        tmp2 = tmp2->next;
    }

    l2.Insert(2, END());
    l2.Print();
}

void Lista::Purge()
{
    position tmp1, tmp2, duplicate;
    tmp1 = l;

    while (tmp1 != NULL && tmp1->next != NULL)
    {
        tmp2 = tmp1;

        while (tmp2->next != NULL)
        {
            if (tmp1->element == tmp2->next->element)
            {
                duplicate = tmp2->next;
                tmp2->next = tmp2->next->next;
                delete duplicate;
            }

            else
                tmp2 = tmp2->next;
        }

        tmp1 = tmp1->next;
    }
}

int main()
{
    cout << "LISTA PIERWSZA: " << endl;

    Lista l;

    l.Insert(5, l.First());
    l.Print();

    l.Insert(2, l.First());
    l.Print();

    l.Insert(1, l.Next(l.First()));
    l.Print();

    cout << endl
         << "LISTA DRUGA: " << endl;

    Lista l2;

    l2.Insert(100, l2.First());
    l2.Print();

    for (int i = 0; i < 3; i++)
        l2.Insert(i, l2.First());
    l2.Print();

    l2.Insert(20, l2.Previous(l2.END()));
    l2.Print();

    l2.Delete(l2.Locate(20));
    l2.Print();

    cout << endl
         << "LISTA TRZECIA: " << endl;

    Lista l3;

    l3.Insert(1, l3.First());
    l3.Insert(2, l3.First());
    l3.Insert(1, l3.First());
    l3.Insert(4, l3.First());
    l3.Insert(2, l3.First());
    l3.Print();

    cout << "Lista zduplikowana: " << endl;

    l3.Duplicate();

    cout << "Lista bez duplikatów: " << endl;

    l3.Purge();
    l3.Print();

    return 0;
}