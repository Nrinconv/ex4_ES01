#include <stdio.h>
#include <stdlib.h>

void max_heapify(int *a, int i, int n);
void heapsort(int *a, int n);
void build_maxheap(int *a, int n);

void max_heapify(int *a, int i, int n)
{
    int j, temp;
    temp = a[i];
    j = 2 * i + 1;
    while (j < n)
    {
        if (j + 1 < n && a[j + 1] > a[j])
            j = j + 1;
        if (temp >= a[j])
            break;
        else
        {
            a[i] = a[j];
            i = j;
            j = 2 * i + 1;
        }
    }
    a[i] = temp;
}

void heapsort(int *a, int n)
{
    int i, temp;
    for (i = n - 1; i > 0; i--)
    {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        max_heapify(a, 0, i);
    }
}

void build_maxheap(int *a, int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
    {
        max_heapify(a, i, n);
    }
}

int main()
{
    int arrays[5][50];
    int sizes[5];
    int i, j;

    // Initialize arrays and sizes
    for (i = 0; i < 5; i++) {
        sizes[i] = 50;
        for (j = 0; j < 50; j++) {
            if (i == 0) {
                arrays[i][j] = j + 1;
            } else if (i == 1) {
                arrays[i][j] = 50 - j;
            } else if (i == 2) {
                arrays[i][j] = 1;
            } else if (i == 3) {
                arrays[i][j] = j + 1;
                if (j > 25) {
                    arrays[i][j] = 50 - j;
                }
            } else if (i == 4) {
                arrays[i][j] = j + 1;
                if (j > 25) {
                    arrays[i][j] = 50 - j;
                }
            }
        }
    }

    // Loop through each array
    for (i = 0; i < 5; i++) {
        printf("Array %d: ", i + 1);
        // Print the array
        for (j = 0; j < sizes[i]; j++) {
            printf("%d ", arrays[i][j]);
        }
        printf("\n");

        // Build the max heap
        build_maxheap(arrays[i], sizes[i]);
        // Sort the array using heap sort
        heapsort(arrays[i], sizes[i]);

        printf("Array %d sorted: ", i + 1);
        // Print the sorted array
        for (j = 0; j < sizes[i]; j++) {
            printf("%d ", arrays[i][j]);
        }
        printf("\n\n");
    }

    return 0;
}
