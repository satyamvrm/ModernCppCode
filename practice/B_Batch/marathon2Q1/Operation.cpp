#include "Operation.h"

// void fillData(int **arr, int row, int col)
// {
//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < col; j++)
//         {
//             std::cout << "Enter the " << i + 1 << ',' << j + 1 << " : ";
//             std::cin >> arr[i][j];
//         }
//     }
// }

// void display(int **arr, int row, int col)
// {
//     std::cout << "\nMatrix : : \n";
//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < col; j++)
//         {
//             std::cout << '\t'<<arr[i][j];
//         }
//         std::cout<<'\n';
//     }
//     std::cout<<'\n';
// }

// int *sumOfEachRow(int **arr, int row, int col)
// {
//     int *result = new int[row];
//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < col; j++)
//         {
//             result[i] += arr[i][j];
//         }
//     }
//     return result;
// }

// int *MaxOfEachCol(int **arr, int row, int col)
// {
//     int *result = new int[col];
//     for (int i = 0; i < col; i++)
//     {
//         result[i] = arr[0][i];
//         for (int j = 0; j < row; j++)
//         {
//             if (result[i] < arr[j][i])
//                 result[i] = arr[j][i];
//         }
//     }
//     return result;
// }

// int SquareOfLastElement(int **arr, int row, int col)
// {
//     return (arr[row-1][col-1]*arr[row-1][col-1]);
// }

template <typename T>
void fillData(T **arr, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            std::cout << "Enter the " << i + 1 << ',' << j + 1 << " : ";
            std::cin >> arr[i][j];
        }
    }
}
template <typename T>
void display(T **arr, int row, int col)
{
    std::cout << "\nMatrix : : \n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            std::cout << '\t' << arr[i][j];
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

template <typename T>
T *sumOfEachRow(T **arr, int row, int col)
{
    T *result = new T[row];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            result[i] += arr[i][j];
        }
    }
    return result;
}

template <typename T>
T *MaxOfEachCol(T **arr, int row, int col)
{
    T *result = new T[col];
    for (int i = 0; i < col; i++)
    {
        result[i] = arr[0][i];
        for (int j = 0; j < row; j++)
        {
            if (result[i] < arr[j][i])
                result[i] = arr[j][i];
        }
    }
    return result;
}

template <typename T>
T SquareOfLastElement(T **arr, int row, int col)
{
    return (arr[row - 1][col - 1] * arr[row - 1][col - 1]);
}

// Explicit Instantiation
// template void fillData(int **arr, int row, int col);
// template void display(int **arr, int row, int col);
// template int *sumOfEachRow(int **arr, int row, int col);
// template int *MaxOfEachCol(int **arr, int row, int col);
// template int SquareOfLastElement(int **arr, int row, int col);

// template void fillData(float **arr, int row, int col);
// template void display(float **arr, int row, int col);
// template float *sumOfEachRow(float **arr, int row, int col);
// template float *MaxOfEachCol(float **arr, int row, int col);
// template float SquareOfLastElement(float **arr, int row, int col);

