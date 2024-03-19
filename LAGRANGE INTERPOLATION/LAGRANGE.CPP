#include <iostream>
using namespace std;
#include <vector>

class lagrange
{
public:
    int a = 4;
    float value;
    float x[4];
    float y[4];
    // vector<int> x;
    // vector<int> y;
    // lagrange()
    // {
    //     cout << " Enter the no of data points that you want " << endl;
    //     cin >> a;
    //     x.resize(a);
    //     y.resize(a);
    // }
};

void inputTableValues(lagrange *obj)
{
    cout << " Enter the values of x : " << endl;
    for (int i = 0; i < obj->a; i++)
    {
        cin >> obj->x[i];
    }
    cout << " Enter the values of y : " << endl;
    for (int i = 0; i < obj->a; i++)
    {
        cin >> obj->y[i];
    }

    cout << " Displaying Table with data points" << endl;
    cout << "x  |\t";
    for (int i = 0; i < obj->a; i++)
    {
        cout << obj->x[i] << "\t";
    }
    cout << endl;
    cout << "y  |\t";
    for (int i = 0; i < obj->a; i++)
    {
        cout << obj->y[i] << "\t";
    }
}

// void lagrangesInterpolation(lagrange *obj)
// {
//     cout << " Enter the value 'x' for which value of 'y' you want " << endl;
//     cin >> obj->value;
//     int x = 0;

//     float prod = 1;
//     // for numerator
//     for (int i = 0; i < obj->a; i++)
//     {
//         prod = prod * (obj->value - obj->x[i]);
//     }
//     // for denominator

//     for (int i = 0; i < obj->a; i++)
//     {
//         x = x + obj->y[i] * ((prod) / (obj->x[i] - obj->x[0]) * (obj->x[i] - obj->x[1]) * (obj->x[i] - obj->x[2]) * (obj->x[i] - obj->x[4]) * (obj->x[i] - obj->x[5]));
//     }
//     // obj->value = x;

//     cout << " The the value of y when x is :" << obj -> value << "is "<< x <<endl;
// }

void interpolation(lagrange *obj)
{
    int value;
    float result = 0, term = 1;
    cout << endl
         << " value for interpolation " << endl;
    cin >> value;

    for (int i = 0; i < 4; i++)
    {
        term = obj->y[i];
        for (int j = 0; j < 4; j++)
        {
            if (i != j)
            {
                term = term * ((value - obj->x[j]) / (obj->x[i] - obj->x[j]));
            }
        }
        result = result + term;
    }
    cout << " The required value when 'x' =" << value << " is " << result << endl;
}
int main()
{
    lagrange *ex = new lagrange;
    inputTableValues(ex);
    interpolation(ex);
    return 0;
}