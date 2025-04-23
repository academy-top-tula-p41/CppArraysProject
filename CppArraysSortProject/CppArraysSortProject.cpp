#include <iostream>

void ArrayInit(int* array, int size)
{
    srand(time(nullptr));

    for (int i{}; i < size; i++)
        array[i] = rand() % 100;
}

void Swap(int& a, int& b)
{
    int temp = a;
    a = b; 
    b = temp;
}

void ArrayPrint(int* array, int size)
{
    for (int i{}; i < size; i++)
        std::cout << array[i] << " ";
    std::cout << "\n";
}

int ArrayMinIndex(int* array, int size)
{
    int minIndex{};
    for (int i{ 1 }; i < size; i++)
        if (array[i] < array[minIndex])
            minIndex = i;
    return minIndex;
}

void ArraySelectSort(int* array, int size)
{
    for (int i{}; i < size - 1; i++)
    {
        int minIndex = ArrayMinIndex(array + i, size - i) + i;
        Swap(array[i], array[minIndex]);
    }
}

void ArrayBubbleSort(int* array, int size)
{
    for (int i{}; i < size - 1; i++)
    {
        bool isSort{ true };
        for (int j{ size - 1 }; j > i; j--)
            if (array[j] < array[j - 1])
            {
                Swap(array[j], array[j - 1]);
                isSort = false;
            }
        if (isSort)
            break;
    }
}

void ArrayCocktailSort(int* array, int size)
{
    bool isSort;
    int top{};
    int bottom{ size - 1 };

    while (top < bottom)
    {
        isSort = true;
        for (int i{ bottom }; i > top; i--)
            if (array[i] < array[i - 1])
            {
                Swap(array[i], array[i - 1]);
                isSort = false;
            }
        if (isSort)
            break;
        top++;

        isSort = true;
        for(int i{ top }; i < bottom; i++)
            if (array[i] > array[i + 1])
            {
                Swap(array[i], array[i + 1]);
                isSort = false;
            }
        if (isSort)
            break;
        bottom--;
    }
}

int main()
{
    int size{ 20 };
    int* array = new int[size] {};

    ArrayInit(array, size);
    ArrayPrint(array, size);

    //ArraySelectSort(array, size);
    //ArrayBubbleSort(array, size);
    ArrayCocktailSort(array, size);
    ArrayPrint(array, size);
}
