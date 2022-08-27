// C program to implement recursive Binary Search
#include <stdio.h>

// A recursive binary search function. It returns
// location of x in given array arr[l..r] is present,
// otherwise -1
int binarySearch(int arr[], int n, const int x)
{
    if (n > 0) {
        int mid = n / 2;

        if (x == arr[mid])
            return 1;

        if (x < arr[mid])
            return binarySearch(arr, mid, x);

        return binarySearch(&arr[mid + 1], n - mid - 1, x);
    }

    // We reach here when element is not
    // present in array
    return 0;
}

int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = binarySearch(arr, n, x);
    (result == 0) ? printf("Element is not present in array\n")
                : printf("Element is presentint the array\n");
    return 0;
}

