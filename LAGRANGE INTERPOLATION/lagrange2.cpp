#include <iostream>
using namespace std;
#include <vector>

class lagrange
{
public:
    // int a=6;
    float value;
    int x[4];
    int y[4];
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
    for (int i = 0; i < 4; i++)
    {
        cin >> obj->x[i];
    }
    cout << " Enter the values of y : " << endl;
    for (int i = 0; i < 4; i++)
    {
        cin >> obj->y[i];
    }

    cout << " Displaying Table with data points" << endl;
    cout << "x  |\t";
    for (int i = 0; i < 4; i++)
    {
        cout << obj->x[i] << "\t";
    }
    cout << endl;
    cout << "y  |\t";
    for (int i = 0; i < 4; i++)
    {
        cout << obj->y[i] << "\t";
    }
}

void lagrangesInterpolation(lagrange *obj)
{
    float numerator, denominator;
    cout << endl
         << " Enter the value 'x' for which value of 'y' you want " << endl;
    cin >> obj->value;
    float thing = 0;

    float prod = 1;
    // for numerator
    for (int i = 0; i < 4; i++)
    {
        prod = prod * (obj->value - obj->x[i]);
    }

    numerator = (obj->value - obj->x[0]) * (obj->value - obj->x[1]) * (obj->value - obj->x[2]) * (obj->value - obj->x[3]);
    for (int i = 0; i < 4; i++)
    {
        denominator = (obj->x[i] - obj->x[0]) * (obj->x[i] - obj->x[1]) * (obj->x[i] - obj->x[2]) * (obj->x[i] - obj->x[3]);
        thing = thing + obj->y[i] * (numerator * (obj->x[i] - obj->x[i]) / denominator * (obj->value - obj->x[i]));
    }
    // obj->value = x;

    cout << " The the value of y when x is " << obj->value << " is " << thing << endl;
}
int main()
{
    lagrange *ex = new lagrange;
    inputTableValues(ex);
    lagrangesInterpolation(ex);
    return 0;
}