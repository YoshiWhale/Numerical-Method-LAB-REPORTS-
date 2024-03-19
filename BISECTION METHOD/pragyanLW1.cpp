#include <iostream>
#include <cmath>
using namespace std;
#define error 0.001;

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

// for the bisection xR

double root(double *a, double *b)
{
    return (*a + *b) / 2;
}

// for f(xr)

double forFXR(double *xR, int *coff)
{

    return coff[0] * (*xR) * (*xR) + coff[1] * (*xR) + coff[2];
}

// for remark

int main()
{

    // trial and error method start

    double xN, xP, xR, fxR, e = 1;
    int y[5], coff[3];

    equation(coff);

    // finding xN and xP
    cout << "x | 0 | 1 | 2 | 3 | 4 |" << endl;

    for (int i = 0; i < 5; i++)
    {
        y[i] = coff[0] * i * i + coff[1] * i + coff[2];
    }

    cout << "y"
         << "| " << y[0] << "| " << y[1] << "|" << y[2] << "  |" << y[3] << " | " << y[4] << "| " << endl;

    // trial and error method end;

    // initilizing xN xP

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

    cout << "xN :" << xN << endl;
    cout << "xP :" << xP << endl;

    // xN and xP initilization finish

    double Previous_xR = 0;
    int i = 1;
    cout << "Iteration :\t"
         << "| xP : "
         << "\t| xN :\t"
         << "\t|Root\t"
         << "\t|f(xr)\t" << fxR << endl;
    while (fabs(e) > 0.001)
    {
        xR = root(&xN, &xP);
        fxR = forFXR(&xR, coff);

        if (fxR > 0)
        {
            xP = xR;
        }
        else
        {
            xN = xR;
        }
        e = fabs(Previous_xR - xR);
        Previous_xR = xR;
        i++;
    }

    cout << "Therefore the approximate  root is " << xR;

    return 0;
}