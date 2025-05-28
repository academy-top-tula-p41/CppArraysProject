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

void ArrayQuickSortReq(int* array, int begin, int end)
{
    int left{ begin };
    int right{ end };
    int pivot{ array[(begin + end) / 2] };

    std::cout << "begin: " << begin << "\n";
    std::cout << "end: " << end << "\n";
    std::cout << "pivot: " << pivot << "\n";

    do
    {
        while(array[left] < pivot) left++;
        while (array[right] > pivot) right--;

        if (left <= right)
        {
            Swap(array[left], array[right]);
            left++;
            right--;
        }
    } while (left <= right);
    ArrayPrint(array, 20);
    
    if (begin < right)
        ArrayQuickSortReq(array, begin, right);
    if (left < end)
        ArrayQuickSortReq(array, left, end);
}

void ArrayQuickSort(int* array, int size)
{
    ArrayQuickSortReq(array, 0, size - 1);
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

void Heapify(int* array, int size, int indexParent)
{
    int indexLeft = 2 * indexParent + 1;
    int indexRight = 2 * indexParent + 2;

    int indexLargest = indexLeft;
    if (indexRight < size && array[indexLargest] < array[indexRight])
        indexLargest = indexRight;

    if (indexLargest < size && array[indexLargest] > array[indexParent])
    {
        Swap(array[indexLargest], array[indexParent]);
        Heapify(array, size, indexLargest);
    }
}

void ArrayHeapSort(int* array, int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        Heapify(array, size, i);

    for (int isize = size - 1; isize >= 0; isize--)
    {
        Swap(array[0], array[isize]);
        Heapify(array, isize, 0);
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
    //ArrayCocktailSort(array, size);
    //ArrayQuickSort(array, size);

    ArrayHeapSort(array, size);

    ArrayPrint(array, size);
}
