#include <iostream>

using namespace std;

int potega(int x, int y);

int main()
{
    int a, b;

    cout << "Podaj podstawę: ";
    cin >> a;
    cout << "Podaj wykładnik: ";
    cin >> b;

    cout << a << "^" << b << " = " << potega(a,b) << endl;

    return 0;
}

int potega(int x, int n)
{
    if(n==0)
    {
        return 1;
    }
    else if(n%2 != 0)
    {
        return x * potega(x, n-1);
    }
    else
    {
        return potega(x, n/2) * potega(x, n/2);
    }
}