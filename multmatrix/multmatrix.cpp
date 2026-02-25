#include <iostream>
#include <string>
#include <array>
#include <fstream>
#include <iomanip>

using namespace std;



bool MakeMatrix(istream& file, float matrix[3][3], bool check)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (!(file >> matrix[i][j]))
            {
                return false;
            }
        }
    }
    if (check) 
    {
        char c;
        if (file >> c)
        {
            return false;
        }
    }
    return true;
}



void multiplyMatrices(const float A[3][3], const float B[3][3], float C[3][3]) {
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            C[i][j] = 0;
            for (int k = 0; k < 3; k++) 
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}


void PrintMatrix(float matrix[3][3])
{

    cout << fixed << setprecision(3);
    
    for (int i = 0; i < 3; i++)
    {
        cout << "\n";
        for (int j = 0; j < 3; j++)
        {
            cout << matrix[i][j] << " ";
        }
    }
}



bool ChoiseInputType(int argc, char* argv[], float matrix_1[3][3], float matrix_2[3][3], int &flag)
{
    switch (argc)
    {
    case 1:
        if (!MakeMatrix(cin, matrix_1, false))
        {
            cout << "ERROR";
            return false;
        }
        if (!MakeMatrix(cin, matrix_2, false))
        {
            cout << "ERROR";
            return false;
        }
        return true;

    case 3:
    {
        ifstream first_file(argv[1]);
        if (!first_file.is_open())
        {
            cout << "ERROR";
            flag = 1;
            return false;
        }
        ifstream second_file(argv[2]);
        if (!second_file.is_open())
        {
            cout << "ERROR";
            flag = 1;
            return false;
        }
        if (!MakeMatrix(first_file, matrix_1, true))
        {
            cout << "ERROR";
            flag = 1;
            return false;
        }
        if (!MakeMatrix(second_file, matrix_2, true))
        {
            cout << "ERROR";
            flag = 1;
            return false;
        }
        return true;
    }
    default:
        cout << "ERROR: Неверный ввод";
        return false;
    }
}



int main(int argc, char* argv[])
{
    int flag = 0;
    float matrix_A[3][3], matrix_B[3][3], matrix_result[3][3];
    if (!ChoiseInputType(argc, argv, matrix_A, matrix_B, flag))
    {
        cout << flag;
        if (flag == 0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }

    multiplyMatrices(matrix_A, matrix_B, matrix_result);
    
    PrintMatrix(matrix_result);

    return 0;
}


