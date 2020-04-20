#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

const int maxlegth = 20;

typedef int elementtype;
typedef int position;

class Stos
{

protected:
    elementtype S[maxlegth];
    position Top; //szczyt stosu

public:
    Stos();
    ~Stos();

    void Push(elementtype x);
    void Pop();
    elementtype TopElem();
    bool Empty();
    void Makenul();
    void Print();
};

Stos::Stos(void)
{
    Top = -1;
}

void Stos::Push(elementtype x)
{
    if (Top < maxlegth - 1)
    {
        Top++;
        S[Top] = x;
    }
}

void Stos::Pop()
{
    if (Top >= 0)
        Top--;
}

elementtype Stos::TopElem()
{
    if (Top >= 0)
        return S[Top];
}

bool Stos::Empty()
{
    if(Top == -1) return true;
    else return false;
}

void Stos::Makenul()
{
    Top = -1;
}

void Stos::Print()
{
    int x = Top;
    while(x != -1)
    {
        cout << S[x] << " ";
        x--;
    }
    cout << endl;
}

int main()
{
    Stos *S = new Stos;

    cout << "Czy pusty? -> " << S->Empty() << endl;

    S->Push(5);

    cout << "Top element: " << S->TopElem() << endl;

    cout << "Czy pusty? -> " << S->Empty() << endl;

    S->Pop();

    cout << "Czy pusty? -> " << S->Empty() << endl;

    cout << "Dodaję 2, 3, 4, 5, 6, 7: " << endl;

    S->Push(2);
    S->Push(3);
    S->Push(4);
    S->Push(5);
    S->Push(6);
    S->Push(7);

    S->Print();

    cout << "Top element: " << S->TopElem() << endl;

    cout << "Czyszczę stos: " << endl;
    S->Makenul();

    cout << "Czy pusty? -> " << S->Empty() << endl;

    return 0;
}

// TEST:
// Empty()
// Push(5)
// Top_Elem()
// Empty()
// Pop()
// Empty()
// Push(2)
// Push(3)
// TopElem()
// Makenull()
// Empty()