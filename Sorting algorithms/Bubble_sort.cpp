
#include<iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(int array[], int size)
{
    int i;
    for(i = 0; i < size; ++i)
    {
        cout << array[i] << " ";
    }
}

void bubble_sort(int array[], int size)
{
    int i, j;
    for(i = 0; i < size-1; ++i)
    {
        for(j = 0; j < size - i - 1; ++j)
        {
            if(array[j] > array[j+1])
            {
                swap(&array[j], &array[j+1]);
            }
        }
    }
}

int main()
{
    int size, i;
    cout << "Enter the number of array elements : ";
    cin >> size;
    int array[size];
    cout << "Enter the individual array elements : " << endl;
    for(i = 0; i < size; ++i)
    {
        cin >> array[i];
    }
    bubble_sort(array, size);
    cout << "The sorted array is : \n";
    print_array(array, size);
    return 0;
}

