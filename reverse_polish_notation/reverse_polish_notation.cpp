#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>

using namespace std;

const int maxLegth = 100;
typedef string elementType;
typedef int position;

class Stack
{
private:
    elementType arr[maxLegth];
    position top;

protected:
    Stack()
    {
        top = -1;
    }

    void push(elementType x)
    {
        if (top != maxLegth)
        {
            top++;
            arr[top] = x;
        }
        else
        {
            cout << "\tStos jest pelny - metoda push()" << endl;
        }
    }

    void pop()
    {
        if (top != -1)
        {
            top--;
        }
        else
        {
            cout << "\tStos jest pusty - metoda pop()" << endl;
        }
    }

    elementType topElement()
    {
        if (top != -1)
        {
            return arr[top];
        }
        else
        {
            cout << "\tStos jest pusty - metoda topElement()" << endl;
            return NULL;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }

    void makeNull()
    {
        top = -1;
    }
};

class ONPclass : Stack
{
private:
    string sentence;

public:
    void setSentence()
    {
        cout << "Wprowadz wyrazenie" << endl;
        getline(cin, sentence);
    }

    bool checkSentece()
    {
        char x = sentence[sentence.length() - 1];
        if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '~')
            return true;
        else
            return false;
    }

    void calculateONP()
    {
        int numberBool = true;
        int number = 0;
        int numberFirst;
        int numberSecound;

        for (int i = 0; i <= (sentence.length() - 1); i++)
        {
            if (sentence[i] >= 48 && sentence[i] <= 57)
            { //0,1,2, ... ,9
                if (numberBool)
                {
                    number = sentence[i] - 48;
                    numberBool = false;
                }
                else
                {
                    number = 10 * number + sentence[i] - 48;
                }
            }
            else if (sentence[i] == ' ')
            {
                if (numberBool == false)
                {
                    push(to_string(number));
                    numberBool = true;
                }
            }
            else if (sentence[i] == '~')
            {
                numberFirst = stoi(topElement());
                pop();
                push(to_string(-numberFirst));
            }
            else
            {
                numberFirst = stoi(topElement());
                pop();
                numberSecound = stoi(topElement());
                pop();

                switch (sentence[i])
                {
                case '+':
                    push(to_string(numberSecound + numberFirst));
                    break;

                case '-':
                    push(to_string(numberSecound - numberFirst));
                    break;

                case '*':
                    push(to_string(numberSecound * numberFirst));
                    break;

                case '/':
                    push(to_string(numberSecound / numberFirst));
                    break;

                case '^':
                    push(to_string(pow(numberSecound, numberFirst)));
                    break;
                }
            }
        }
        cout << "Wynik: " << topElement() << endl
             << endl;
        pop();
    }

    int priorityCheck(char s)
    {
        switch (s)
        {
        case '(':
            return 0;
            break;

        case '+':
            return 1;
            break;

        case '-':
            return 1;
            break;

        case ')':
            return 1;
            break;

        case '*':
            return 2;
            break;

        case '/':
            return 2;
            break;

        case '^':
            return 3;
            break;

        case '~':
            return 4;
            break;
        }
        return -1;
    }

    void convertToONP()
    {
        string output = "";

        for (int i = 0; i <= (sentence.length() - 1); i++)
        {
            if ((sentence[i] >= 48 && sentence[i] <= 57) ||
                (sentence[i] >= 97 && sentence[i] <= 122) ||
                (sentence[i] >= 65 && sentence[i] <= 90))
            { //liczba lub nazwa zmiennej

                output = output + sentence[i];
            }
            else
            {
                if (output[output.length() - 1] != ' ')
                {
                    output = output + ' ';
                }

                if (sentence[i] == '(')
                {
                    push("(");
                }
                else if (sentence[i] == ')')
                {
                    while (topElement() != "(")
                    {
                        output = output + topElement();
                        if (output[output.length() - 1] != ' ')
                        {
                            output = output + ' ';
                        }
                        pop();
                    }
                    pop();
                }
                else
                {
                    if (isEmpty() || (priorityCheck(topElement()[0]) < priorityCheck(sentence[i])))
                    {
                        if ((sentence[i] == '-' && i == 0) || (sentence[i] == '-' && (sentence[i - 1] == '(')))
                        {
                            string send(1, '~');
                            push(send);
                        }
                        else
                        {
                            string send(1, sentence[i]);
                            push(send);
                        }
                    }
                    else
                    {
                        while (!isEmpty() && priorityCheck(topElement()[0]) >= priorityCheck(sentence[i]))
                        {
                            output = output + topElement();
                            if (output[output.length() - 1] != ' ')
                            {
                                output = output + ' ';
                            }
                            pop();
                        }
                        if ((sentence[i] == '-' && i == 0) || (sentence[i] == '-' && (sentence[i - 1] == '(')))
                        {
                            string send(1, '~');
                            push(send);
                        }
                        else
                        {
                            string send(1, sentence[i]);
                            push(send);
                        }
                    }
                }
            }
        }

        while (!isEmpty())
        {
            if (output[output.length() - 1] != ' ')
            {
                output = output + ' ';
            }
            output = output + topElement();
            pop();
        }

        cout << "ONP: " << output << endl
             << endl;
    }
};

int main()
{
    ONPclass ONP;

    cout << "Maksymalna mozliwa dlugosc wprowadzanych wyrazen wynosi " << maxLegth << " elementow" << endl;

    while (true)
    {
        ONP.setSentence();
        if (ONP.checkSentece())
        {
            ONP.calculateONP();
        }
        else
        {
            ONP.convertToONP();
        }
    }

    return 0;
}
