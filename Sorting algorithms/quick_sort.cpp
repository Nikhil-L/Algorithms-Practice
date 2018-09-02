
#include<iostream>
#include<stdlib.h> 
using namespace std;

void print_array(int array[], int size)
{
    int i;
    for(i = 0; i < size; ++i)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int a[], int low, int high)
{
	int pivot = a[high];
	int i = low - 1;
	
	for(int j = low; j <= high - 1; j++)
	{
		if(a[j] <= pivot)
		{
			i++;
			swap(&a[i], &a[j]);
		}
	}
	swap(&a[i+1], &a[high]);
	return (i + 1);
}

void quick_sort(int a[], int low, int high)
{
	if(low < high)
	{
		int p = partition(a, low, high);
	
		quick_sort(a, low, p - 1);
		quick_sort(a, p + 1, high);
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
    quick_sort(array, 0, size - 1);
    cout << "The sorted array is : ";
    print_array(array, size);
    return 0;
}
