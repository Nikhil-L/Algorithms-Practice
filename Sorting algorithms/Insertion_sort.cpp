
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

void insertion_sort(int array[], int size)
{
    int i, j, key;
    for(i = 1; i < size; ++i)
    {
        key = array[i];
        j = i-1;
         while (j >= 0 && array[j] > key)
       {
           array[j+1] = array[j];
           j = j-1;
       }
       array[j+1] = key;
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
    insertion_sort(array, size);
    cout << "The sorted array is : \n";
    print_array(array, size);
    return 0;
}

