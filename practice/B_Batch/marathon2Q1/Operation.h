#ifndef OPERATION_H
#define OPERATION_H

#include <iostream>

// void fillData(int **arr, int row, int col);
// void display(int **arr, int row, int col);
// int *sumOfEachRow(int **arr, int row, int col);
// int *MaxOfEachCol(int **arr, int row, int col);
// int SquareOfLastElement(int **arr, int row, int col);

template <typename T>
void fillData(T **arr, int row, int col);

template <typename T>
extern void display(T **arr, int row, int col);

template <typename T>
extern T *sumOfEachRow(T **arr, int row, int col);

template <typename T>
extern T *MaxOfEachCol(T **arr, int row, int col);

template <typename T>
extern T SquareOfLastElement(T **arr, int row, int col);

#endif // OPERATION_H
