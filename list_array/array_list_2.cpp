#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef int elementtype, position;

const int maxlength = 10;

struct List
{
    elementtype elements[maxlength];
    int last; //indeks ostatniego elementu listy
};

void print(List l);

position END(List l)
{
    return l.last + 1;
}

position First(List l)
{
    return 0;
}

position Next(position p, List l)
{
    if ((p > l.last) || (p < 0))
        return -1;
    else
        return p + 1;
}

position Previous(position p, List l)
{
    if ((p > l.last + 1) || (p < 0))
        return -1;
    else
        return p - 1;
}

position Locate(elementtype x, List l)
{ //zwraca pozycje x w l, gdy nie ma x w l zwraca end(l)
    int i = 0;
    while ((i <= l.last) && (l.elements[i] != x))
        i++;
    return i;
}

elementtype Retrieve(position p, List l)
{
    const elementtype min = -1000000;

    if ((p > l.last) || (p < 0))
        return min;
    else
        return l.elements[p];
}

bool Insert(int x, position p, List &l)
{
    if (l.last >= maxlength)
        return false; //brak miejsca w tablicy
    else if ((p > l.last + 1) || (p < 0))
        return false; // pozycja nie istnieje
    else
    {
        for (int i = l.last; i >= p; i--)
            l.elements[i + 1] = l.elements[i];

        l.elements[p] = x;
        l.last = l.last + 1;

        return true;
    }
}

bool Delete(position p, List &l)
{
    if ((p > l.last) || (p < 0))
        return false;
    else
    {
        for (int i = p; i < l.last; i++)
            l.elements[i] = l.elements[i + 1];

        l.last--;
        return true;
    }
}

bool Duplicate(List l)
{
    List l2;
    l2.last = (2 * l.last) + 1;

    for(int i = 0; i <= l.last; i++)
        l2.elements[i] = l.elements[i];

    for(int i = l.last + 1; i <= l2.last; i++)
        l2.elements[i] = l.elements[i-(l.last+1)];

    print(l2);

    return true;
}

bool Purge(List l)
{
    for(int i = 0; i <= l.last; i++)
    {
        for(int j = i + 1; j <= l.last; j++)
        {
            if(l.elements[i] == l.elements[j])
                Delete(j, l);
        }
    }

    print(l);

    return true;
}

void print(List l)
{
    position i = First(l);

    while (i != END(l))
    {
        cout << " " << Retrieve(i, l);
        i = Next(i, l);
    }

    cout << endl;
}

int main()
{
    List l;
    l.last = -1;

    Insert(100, First(l), l);
    print(l);

    for (int i = 0; i < 3; i++)
        Insert(i, First(l), l);
    print(l);

    Insert(2, Previous(END(l), l), l);
    cout << "Pierwotna lista tablicowa: " << endl;
    print(l);

    cout << "Zdublowana lista tablicowa: " << endl;
    Duplicate(l);

    Insert(2, First(l), l);

    cout << "Lista tablicowa bez dubli: " << endl;
    Purge(l);

    return 0;
}