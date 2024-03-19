#include <iostream>
#include <vector>
using namespace std;

class Lagrange
{
public:
    float value;
    vector<int> x;
    vector<int> y;
};

void inputTableValues(Lagrange *obj)
{
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;

    cout << "Enter the values of x:" << endl;
    obj->x.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> obj->x[i];
    }

    cout << "Enter the values of y:" << endl;
    obj->y.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> obj->y[i];
    }

    cout << "Displaying Table with data points" << endl;
    cout << "x  |\t";
    for (int i = 0; i < n; i++)
    {
        cout << obj->x[i] << "\t";
    }
    cout << endl;
    cout << "y  |\t";
    for (int i = 0; i < n; i++)
    {
        cout << obj->y[i] << "\t";
    }
    cout << endl;
}

void lagrangesInterpolation(Lagrange *obj)
{
    float result = 0;
    for (int i = 0; i < obj->x.size(); i++)
    {
        float term = obj->y[i];
        for (int j = 0; j < obj->x.size(); j++)
        {
            if (j != i)
            {
                term = term * (obj->value - obj->x[j]) / (obj->x[i] - obj->x[j]);
            }
        }
        result += term;
    }

    cout << "The value of y when x is " << obj->value << " is " << result << endl;
}

int main()
{
    Lagrange *ex = new Lagrange;
    inputTableValues(ex);
    cout << "Enter the value of x for interpolation: ";
    cin >> ex->value;
    lagrangesInterpolation(ex);
    return 0;
}
