#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

#define N 10 // wielkość tablicy do posortowania

int selection_sort(int n, int t[])
{
    int i, j, k, counter = 0;

    for (i = 0; i < n; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            counter++;
            if (t[j] < t[k])
            {
                k = j;
            }
        }

        swap(t[k], t[i]);
    }

    return counter;
}

int main()
{
    int tab[N], counter;

    srand(time(NULL));

    for (int i = 0; i < N; i++)
    {
        tab[i] = rand() % N; // przypadek optymistyczny: tab[i] = i; pesypistyczny tab[i] = N-i-1;
        cout << tab[i] << " ";
    }

    cout << endl;

    counter = selection_sort(N, tab);

    for (int i = 0; i < N; i++)
        cout << tab[i] << " ";

    cout << endl;
    cout << endl;
    cout << "Ilość wykonań:  " << counter << endl;

    return 0;
}
