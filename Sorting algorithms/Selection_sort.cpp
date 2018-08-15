
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

void selection_sort(int array[], int size)
{
    int i, j , min_index;
    for(i = 0; i < size-1; ++i)
    {
        min_index = i;
        for(j = i+1; j < size; ++j)
        {
            if(array[j] < array[min_index])
            {
                min_index = j;
            }
        }
        swap(&array[min_index], &array[i]);
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
    selection_sort(array, size);
    cout << "The sorted array is : \n";
    print_array(array, size);
    return 0;
}
