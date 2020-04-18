#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

const int maxlength = 50;

typedef int elementtype;
typedef int position;

class Kolejka
{
protected:
    elementtype Queue[maxlength];
    position Front; // Indeks elementu czołowego
    position Rear;  // Indeks ostatniego elementu

public:
    Kolejka(){};
    ~Kolejka(){};
    int AddOne(int i);
    void Init();
    void Enqueue(elementtype x);
    void Dequeue();
    elementtype FrontElem();
    void Makenul();
    bool Empty();
};

int Kolejka::AddOne(int i) // zwiększa modulo rozmiar tablicy o 1
{
    return ((i + 1) % maxlength);
}

void Kolejka::Init() // tworzy obiekt i inicjuje zmienne Front oraz Rear aby kolejka była pusta
{
    Front = 0;
    Rear = maxlength - 1;
}

void Kolejka::Enqueue(elementtype x) // wstawaia element na koniec kolejki
{
    if (AddOne(AddOne(Rear)) != Front) // jeśli kolejka nie jest pełna
    {
        Rear = AddOne(Rear);
        Queue[Rear] = x;
    }
}

void Kolejka::Dequeue() // usuwa element z poczatku kolejki
{
    if (!Empty())
        Front = AddOne(Front);
}

elementtype Kolejka::FrontElem() // zwraca pierwszy element kolejki
{
    if (!Empty())
        return Queue[Front];
}

void Kolejka::Makenul() // czyści kolejkę
{

    Front = 0;
    Rear = maxlength - 1;
}

bool Kolejka::Empty() // sprawdza czy kolejka jest pusta (tak -> true, nie -> false)
{
    return (AddOne(Rear) == Front);
}

int main()
{
    Kolejka k;

    cout << "Tworzę pustą kolejkę" << endl;
    k.Init();
    cout << "Czy kolejka jest pusta?: " << k.Empty() << endl;
    cout << endl;

    cout << "Dodaję element 5 do kolejki" << endl;
    k.Enqueue(5);
    cout << "Czy kolejka jest pusta?: " << k.Empty() << endl;
    cout << "Element na początku kolejki: " << k.FrontElem() << endl;
    cout << endl;

    cout << "Usuwam ostatni element z kolejki" << endl;
    k.Dequeue();
    cout << "Czy kolejka jest pusta?: " << k.Empty() << endl;
    cout << endl;

    cout << "Dodaję elementy 5, 3, 2 do kolejki" << endl;
    k.Enqueue(5);
    k.Enqueue(3);
    k.Enqueue(2);
    cout << "Element na początku kolejki: " << k.FrontElem() << endl;
    cout << endl;

    cout << "Dodaję element 1 do kolejki" << endl;
    k.Enqueue(1);
    cout << "Element na początku kolejki: " << k.FrontElem() << endl;
    cout << endl;

    cout << "Usuwam element z kolejki" << endl;
    k.Dequeue();
    cout << "Element na początku kolejki: " << k.FrontElem() << endl;
    cout << endl;

    cout << "Dodaję element 6 do kolejki" << endl;
    k.Enqueue(6);
    cout << "Element na początku kolejki: " << k.FrontElem() << endl;
    cout << endl;

    cout << "Usuwam dwa elementy z kolejki" << endl;
    k.Dequeue();
    k.Dequeue();
    cout << "Element na początku kolejki: " << k.FrontElem() << endl;
    cout << endl;

    cout << "Czyszczę kolejkę" << endl;
    k.Makenul();
    cout << "Czy kolejka jest pusta?: " << k.Empty() << endl;

    return 0;
}

// TEST
//
// Empty()
// Enqueue(5)
// Empty()
// Front()
// Dequeue()
// Empty()
// Enqueue(4)
// Enqueue(3)
// Enqueue(2)
// Front()
// Enqueue(1)
// Front()
// Dequeue()
// Front()
// Enqueue(6)
// Front()
// Dequeue()
// Dequeue()
// Front()
// Makenull()
// Empty()