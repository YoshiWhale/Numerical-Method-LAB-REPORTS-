#include <iostream>
using namespace std;

void algebricExpressionObtain(int *a, int *b, int *c)
{
    cout << " To obtain required algebric expression ax^2+ bx + c " << endl;
    cout << "Enter a, b and c " << endl;
    cin >> *a >> *b >> *c;
    cout << " The obtained equation is " << *a << "x^2 +" << *b << "x + " << *c << endl;
}

void obtainY(int arr[], int a, int b, int c)
{
    for (int i = 0; i < 6; i++)
    {

        arr[i] = a * (i ^ 2) + b * i + c;
    };

    cout << " x : "
         << " 0  |"
         << " 1  |"
         << " 2  |"
         << " 3  |"
         << " 4 |"
         << " 5 |" << endl;
    cout << " y : "
         << " " << arr[0] << "   |" << arr[1] << "  |" << arr[2] << "  | " << arr[3] << "  |" << arr[4] << " | " << arr[5] << "|" << endl;
}

int main()
{
    int a, b, c;
    int fx[5];
    float x0, x1;

    algebricExpressionObtain(&a, &b, &c);
    obtainY(fx, a, b, c);

    // getting the initial values

    for (int i = 0; i < 5; i++)
    {
        if (fx[i] < 0 && fx[i + 1] > 0)
        {
            x0 = i;
            x1 = i+1;
            cout << "the initial values are " << endl
                 << "x0 : " << x0 << endl
                 << "x1 : " << x1 << endl;
            break;
        }
        else if (fx[i + 1] < 0 && fx[i] > 0)
        {
            x0 = i;
            x1 = i+1;
            cout << "the initial values are " << endl
                 << "x0 : " << x0 << endl
                 << "x1 : " << x1 << endl;
            break;
        }
    }

    //  secant method begins

    float xII, fxn, fxn_1;

    for (int i = 1; i < 10; i++)
    {
        fxn = a * (x1 * x1) + b * x1 + c;
        fxn_1 = a * (x0 * x0) + b * x0 + c;
        xII = (fxn * x0 + fxn_1 * x1) / (fxn - fxn_1);
        cout << "| n = " << i << " |\t"
             << "x" << i + 1 << " = " << xII << " | " << endl;
        x0 = x1;
        x1 = xII;
    }
    cout << " Name : Pragyan Shrestha " << endl << " roll no : 10" << endl;

    return 0;
}
