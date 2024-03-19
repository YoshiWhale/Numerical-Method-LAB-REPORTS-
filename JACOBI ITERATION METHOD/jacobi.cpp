#include <iostream>
using namespace std;

class jacobi
{
public:
    float a[3], b[3], c[3], constant[3];
    float ax[3], bx[3], cx[3];

    float x = 0, y = 0, z = 0;
};

void enterCoeff(jacobi *obj)
{
    for (int i = 0; i < 3; i++)
    {
        cout << " Input 3 coeffients for equation and the constant" << i + 1 << endl;

        cin >> obj->a[i];

        cin >> obj->b[i];

        cin >> obj->c[i];

        cin >> obj->constant[i];
    }
}

void displayEquations(jacobi *obj)
{
    for (int i = 0; i < 3; i++)
    {
        cout << " equation " << i + 1 << endl;
        cout << obj->a[i] << " x + " << obj->b[i] << " y + " << obj->c[i] << " z = " << obj->constant[i] << endl;
    }
}

void jacobiCoeff(jacobi *obj)
{
    for (int i = 0; i < 3; i++)
    {
        if (obj->a[i] > obj->b[i] + obj->c[i])
        {
            obj->b[i] = -obj->b[i];
            obj->c[i] = -obj->c[i];

            // for the equations
            obj->ax[0] = obj->a[i];
            obj->bx[0] = obj->b[i];
            obj->cx[0] = obj->c[i];
        }
        else if (obj->b[i] > obj->a[i] + obj->c[i])
        {
            obj->a[i] = -obj->a[i];
            obj->c[i] = -obj->c[i];

            // for the equations

            obj->ax[1] = obj->a[i];
            obj->bx[1] = obj->b[i];
            obj->cx[1] = obj->c[i];
        }
        else
        {
            obj->b[i] = -obj->b[i];
            obj->a[i] = -obj->a[i];
            // for the equations

            obj->ax[2] = obj->a[i];
            obj->bx[2] = obj->b[i];
            obj->cx[2] = obj->c[i];
        }
    }
}

// for the iterative equation of x
float fx(jacobi *obj)
{
    float result;
    result = (obj->constant[0] + ((obj->bx[0] * (obj->y) + obj->cx[0] * (obj->z)))) / obj->ax[0];
    // obj->x = result;
    return result;
};

// for the iterative equation of x
float fy(jacobi *obj)
{
    float result;
    result = (obj->constant[1] + ((obj->ax[1] * (obj->x) + obj->cx[1] * (obj->z)))) / obj->bx[1];
    // obj->y = result;
    return result;
};
// for the iterative equation of x
float fz(jacobi *obj)
{
    float result;
    result = (obj->constant[2] + (obj->bx[2] * (obj->y) + obj->ax[2] * (obj->x))) / obj->cx[2];
    // obj->z = result;
    return result;
};

// this is another iteration
// void fx(jacobi *obj)
// {
//     obj->x = (obj->bx[1]*(obj->y) + obj->cx[1]*(obj->z)) / obj->ax[1];
// };

// // for the iterative equation of x
// void fy(jacobi *obj)
// {
//     obj->y = (obj->ax[1] + obj->cx[1]) / obj->bx[1];
// };
// // for the iterative equation of x
// void fz(jacobi *obj)
// {
//     obj->z = (obj->bx[1]*(obj->y) + obj->ax[1]*(obj->x)) / obj->cx[1];
// };

void displayIterativeEqn(jacobi *obj)
{
    cout << " Required Equations used for iterations are :" << endl;

    cout << "x = " << " " << obj->constant[0]<<" -( " <<obj->bx[0] << " y +" << obj->cx[0] << "z )"
         << "/" << obj->ax[0] << endl;
    cout << "y =  "<< obj->constant[1]<< "-(" << obj->ax[1] << " x +" << obj->cx[1] << "z )"
         << "/" << obj->bx[1] << endl;
    cout << "z =  " << obj->constant[2] << " - "<<obj->bx[2] << " y +" << obj->ax[2] << "z )"
         << "/" << obj->cx[2] << endl;
}

int main()
{

    jacobi *lab = new jacobi;
    enterCoeff(lab);
    displayEquations(lab);
    jacobiCoeff(lab);
    // displayEquations(&lab);
    displayIterativeEqn(lab);

    cout << "------ Jacobi Iteration Begins -----" << endl;

    for (int i = 0; i < 3; i++)
    {
        // lab->x = fx(lab);
        // lab->y = fy(lab);
        // lab->z = fz(lab);

        cout
            << "iteration ; " << i << " x = " << fx(lab) << "\t y = " << fy(lab) << "\t z = " << fz(lab) << endl;
            lab->x= fx(lab);
            lab->y= fy(lab);
            lab->z= fz(lab);
    }

    return 0;
}