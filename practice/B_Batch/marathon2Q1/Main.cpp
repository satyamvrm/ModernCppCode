#include "Operation.cpp"

int main()
{
    int row, col;
    std::cout << "Enter the rows : ";
    std::cin >> row;
    std::cout << "Enter the columns : ";
    std::cin >> col;

/*     int **arr = new int *[row];
    for (int i = 0; i < row; i++)
        arr[i] = new int[col];

    fillData(arr, row, col);
    display(arr, row, col);

    int *SumOfRow = sumOfEachRow(arr, row, col);
    std::cout << "Sum of each row\n";
    for (int i = 0; i < row; i++)
        std::cout << "Row : " << i + 1 << " - " 
                  << SumOfRow[i]<<'\n';
    std::cout << '\n';

    int *MaxElements = MaxOfEachCol(arr, row, col);
    std::cout << "Max of each col\n";
    for (int i = 0; i < col; i++)
        std::cout << "Column : "<<i+1 << " - " << MaxElements[i]<<'\n';
    std::cout << '\n';

    std::cout << "Square of last element : " << SquareOfLastElement(arr, row, col) << '\n';
 */
    float **arr = new float *[row];
    for (int i = 0; i < row; i++)
        arr[i] = new float[col];

    fillData(arr, row, col);
    display(arr, row, col);

    float *SumOfRow = sumOfEachRow(arr, row, col);
    std::cout << "Sum of each row\n";
    for (int i = 0; i < row; i++)
        std::cout << "Row : " << i + 1 << " - " 
                  << SumOfRow[i]<<'\n';
    std::cout << '\n';

    float *MaxElements = MaxOfEachCol(arr, row, col);
    std::cout << "Max of each col\n";
    for (int i = 0; i < col; i++)
        std::cout << "Column : "<<i+1 << " - " << MaxElements[i]<<'\n';
    std::cout << '\n';

    std::cout << "Square of last element : " << SquareOfLastElement(arr, row, col) << '\n';
}