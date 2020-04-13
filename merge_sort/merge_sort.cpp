#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

void merge(int tab[], int l, int m, int r)
{
    int i, j, k;
    int x = m - l + 1;
    int y = r - m;

    int L[x];
    int R[y];

    for (i = 0; i < x; i++)
        L[i] = tab[l + i];

    for (j = 0; j < y; j++)
        R[j] = tab[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < x && j < y)
    {
        if (L[i] <= R[j])
        {
            tab[k] = L[i];
            i++;
        }
        else
        {
            tab[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < x)
    {
        tab[k] = L[i];
        i++;
        k++;
    }

    while (j < y)
    {
        tab[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int tab[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(tab, l, m);
        mergeSort(tab, m + 1, r);

        merge(tab, l, m, r);
    }
}

void print(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << A[i] << " ";

    cout << endl;
}

int main()
{
    int tab[] = {4,3,7,9,0,12,3,10};

    int size = sizeof(tab) / sizeof(tab[0]);

    cout << "Tablica przed sortowaniem: " << endl;
    print(tab, size);

    mergeSort(tab, 0, size - 1);

    cout << endl << "Tablica posortowana: " << endl;
    print(tab, size);

    return 0;
}