#include <iostream>
using namespace std;

void algebricExpressionObtain(int *a, int *b, int *c)
{
    cout << " To obtain required algebric expression ax^2+ bx + c " << endl;
    cout << "Enter a, b and c " << endl;
    cin >> *a >> *b >> *c;
    cout << " The obtained equation is " << *a << "x^2 +" << *b << "x + " << *c << endl;
}

void initialXValues(int *x1, int *x2, int a, int b)
{
    *x1 = a;
    *x2 = b;
    cout << "The initial values of x and y is " << a << ", " << b << endl;
}

int main()
{
    int a, b, c;
    int x1, x2;
    int fx[5];
    algebricExpressionObtain(&a, &b, &c);
    initialXValues(&x2, &x2, 0, 1);

        return 0;
}
