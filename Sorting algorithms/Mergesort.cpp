#include<iostream>
using namespace std;

void print_array(int array[], int size)
{
    int i;
    for(i = 0; i < size; ++i)
    {
        cout << array[i] << " ";
    }
}

/// Merges two subarrays of arr[].
///First subarray is arr[l..m]
/// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int nl = m - l + 1;
    int nr =  r - m;

    /* create temp arrays */
    int L[nl], R[nr];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < nl; i++)
        L[i] = arr[l + i];
    for (j = 0; j < nr; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < nl && j < nr)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < nl)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < nr)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void merge_sort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        merge_sort(arr, l, m);
        merge_sort(arr, m+1, r);

        merge(arr, l, m, r);
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
    merge_sort(array, 0, size);
    cout << "The sorted array is : \n";
    print_array(array, size);
    return 0;
}
