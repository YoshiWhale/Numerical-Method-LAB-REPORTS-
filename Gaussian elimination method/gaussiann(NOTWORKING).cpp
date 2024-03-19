#include <iostream>
using namespace std;

class GE
{
public:
    float matrixA[3][4];

    void inputMatrix(GE *obj)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << " Element  "
                     << "[" << i << "]"
                     << "[" << j << "]"
                     << " : ";
                cin >> obj->matrixA[i][j];
                // obj->matrixA[i][j] = matrixA[i][j];
            }
        }
    }

    void inputConstant(GE *obj)
    {
        cout << " Enter the constants. " << endl;
        cout << " Constant 1 : ";
        cin >> obj->matrixA[0][3];
        cout << " Constant 2 : ";
        cin >> obj->matrixA[1][3];
        cout << " Constant 3 : ";
        cin >> obj->matrixA[2][3];
    }

    void rowoperations(GE *obj)
    {
        float a00, b11, c22; // values to divide the rows respectively
        a00 = obj->matrixA[0][0];
        b11 = obj->matrixA[1][1];
        c22 = obj->matrixA[2][2];

        // for first row operations
        for (int i = 0; i < 4; i++)
        {
            obj->matrixA[0][i] = obj->matrixA[0][i] / a00;
        }

        for (int i = 0; i < 4; i++)
        {
            obj->matrixA[1][i] = obj->matrixA[1][i] - (obj->matrixA[0][i] * obj->matrixA[1][0]);
        }
        for (int i = 0; i < 4; i++)
        {
            obj->matrixA[2][i] = obj->matrixA[2][i] - (obj->matrixA[0][i] * obj->matrixA[2][0]);
        }

        // for second row operations
        for (int i = 1; i < 4; i++)
        {
            obj->matrixA[1][i] = obj->matrixA[1][i] / b11;
        }

        // performing column for the operations
        for (int i = 0; i < 4; i++)
        {
            obj->matrixA[2][i] = obj->matrixA[2][i] - (obj->matrixA[1][i] * obj->matrixA[2][1]);
        }

        for (int i = 0; i < 4; i++)
        {
            obj->matrixA[2][i] = obj->matrixA[2][i] / c22;
        }
    };

    //  displaying matrix

    void displayMatrixA(GE *objs)
    {
        cout << " Displaying Matrix " << endl;
        for (int i = 0; i < 3; i++)
        {
            
            cout << " | ";
            {
                for (int j = 0; j < 4; j++)
                {
                    cout << objs->matrixA[i][j] << "\t";
                }
                cout << " | " << endl;
            }
        }
    }


    void ObtainValues(GE *obj)
    {
        float x1, x2, x3;
        cout << " The obtained equations are " << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << obj->matrixA[i][0] << "x + " << obj->matrixA[i][1] << " y + " << obj->matrixA[i][2] << "= " << obj->matrixA[i][3]<< endl;
        }
        cout << "Solving the above equations we get :" << endl;
        x3 = obj->matrixA[2][3];
        x2 = obj->matrixA[1][3] - obj->matrixA[1][2] * x3;
        x1 = obj->matrixA[0][4] - (obj->matrixA[0][1] * x2 + obj->matrixA[0][2] * x3);

       
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
        cout << "x3 = " << x3 << endl;
    };
};

int main()
{
    GE *mat = new GE();
    mat->inputMatrix(mat);
    mat->inputConstant(mat);
    mat->displayMatrixA(mat);
    mat->rowoperations(mat);

    cout << " ---After row operations ---" <<endl;

    mat->displayMatrixA(mat);
    mat->ObtainValues(mat);

        return 0;
}