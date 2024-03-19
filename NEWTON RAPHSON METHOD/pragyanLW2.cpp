#include <iostream>
using namespace std;

// for the equation

void equation(int *coff)
{

    cout << "Enter the coefficient of x^2" << endl;
    cin >> coff[0];
    cout << "Enter the coefficient of x" << endl;
    cin >> coff[1];
    cout << "Enter the constant" << endl;
    cin >> coff[2];

    cout << "Given equation is :" << endl
         << coff[0] << "x^2 + " << coff[1] << "x + " << coff[2] << endl;
}

// for f(xi)

double forFxi(double *xi, int *coff)
{

    return coff[0] * (*xi) * (*xi) + coff[1] * (*xi) + coff[2];
}

// derivative of f(xi)

double forDerivativeFxi(double *xi, int *coff)
{

    return 2 * coff[0] * (*xi) + coff[1];
}

int main()
{

    // trial and error method start

    double xN, xP, xi, xii, fxi, derivativeoffxi, fxii;
    int error, y[5], coff[3];

    equation(coff);

    cout << "x | 0 | 1 | 2 | 3 | 4 |" << endl;

    for (int i = 0; i < 5; i++)
    {
        y[i] = coff[0] * i * i + coff[1] * i + coff[2];
    }

    cout << "y"
         << "| " << y[0] << "| " << y[1] << "|" << y[2] << "  |" << y[3] << " | " << y[4] << "| " << endl;

    // trial and error method end;

    // initilizing xi start

    for (int i = 0; i < 5; i++)
    {
        if (y[i] > 0 && y[i + 1] < 0)
        {
            xP = i;
            xN = i + 1;
            break;
        }
        else if (y[i] < 0 && y[i + 1] > 0)
        {
            xN = i;
            xP = i + 1;
            break;
        }
        else
        {
            continue;
        }
    }

    if (xP > xN)
    {
        xi = xN;
    }
    else
    {
        xi = xP;
    }

    cout << " The value of xi :" << xi << endl;

    // xi initilization finish

    // creating the final table

    for (int i = 0; i < 5; i++)
    {
        fxi = forFxi(&xi, coff);
        derivativeoffxi = forDerivativeFxi(&xi, coff);
        xii = xi - (fxi / derivativeoffxi);
        fxii = forFxi(&xii, coff);

        cout << "Iteration :\t" << i + 1 << "| xi : " << xi << "\t| x(i+1) :\t" << xii << "\t|f(x(i+1))\t" << fxii << endl;
        xi = xii;
    }

    cout << "Therefore the approximate  root is " << xii << endl;

    return 0;
}