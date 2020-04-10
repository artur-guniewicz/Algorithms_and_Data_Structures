#include <iostream>
#include <cstdio>

using namespace std;

const int B = 65;

typedef char *elementtype;
struct celltype
{
    elementtype element;
    celltype *next;
};

typedef celltype *position;

class dictionary
{
protected:
    position D[B];

public:
    dictionary();

    ~dictionary();

    void Makenul();

    bool Member(elementtype x); // true gdy należy do słownika, false dy nie

    void Insert(elementtype x); // czyni x elementem słownika

    void Delete(elementtype x);

    int H(elementtype x); // pobiera kod ASCI pierwszego znaku słowa x modulo rozmiar tablicy
};

dictionary::dictionary()
{
    for (int i = 0; i < B; i++)
        D[i] = NULL;
}

bool dictionary::Member(elementtype x)
{
    position current;
    current = D[H(x)];

    while (current != NULL)
    {
        if (current->element == x)
            return true;
        else
            current = current->next;
    }
    return false;
}

void dictionary::Insert(elementtype x)
{
    int bucket;
    position oldheader;

    if (!Member(x))
    {
        bucket = H(x);
        oldheader = D[bucket];
        D[bucket] = new celltype;
        D[bucket]->element = x;
        D[bucket]->next = oldheader;
    }
}

void dictionary::Delete(elementtype x)
{
    position p, current;
    int bucket;
    bucket = H(x);

    if (D[bucket] != NULL)
    {
        if (D[bucket]->element == x)
        {
            p = D[bucket];
            D[bucket] = D[bucket]->next;
            delete p;
        }
        else
        {
            current = D[bucket];

            while (current->next != NULL)
                if ((current->next->element) == x)
                {
                    p = current->next;
                    current->next = current->next->next;
                    delete p;
                    break;
                }
                else
                    current = current->next;
        }
    }
}

dictionary::~dictionary()
{
    position p;
    for (int i = 0; i < B; i++)
    {
        while (D[i] != NULL)
        {
            p = D[i];
            D[i] = D[i]->next;
            delete p;
        }
    }
}

void dictionary::Makenul()
{
    position p;
    for (int i = 0; i < B; i++)
    {
        while (D[i] != NULL)
        {
            p = D[i];
            D[i] = D[i]->next;
            delete p;
        }
    }
}

int dictionary::H(elementtype x)
{
    return (int(x[0])) % B;
}

int main()
{
    dictionary d;

    d.Insert("Ala");
    cout << d.Member("Ala") << endl;
    cout << d.H("Ala") << endl;
    d.Insert("As");
    cout << d.Member("As") << endl;
    cout << d.H("As") << endl;
    cout << d.Member("Ala") << endl;
    cout << d.H("Ala") << endl;
    d.Insert("Guniewicz");
    cout << d.H("Guniewicz") << endl;
    cout << d.Member("Guniewicz") << endl;
    d.Delete("Ala");
    cout << d.Member("As") << endl;
    cout << d.Member("Ala") << endl;
    d.Makenul();
    cout << d.Member("As") << endl;
    cout << d.Member("Guniewicz") << endl;
}