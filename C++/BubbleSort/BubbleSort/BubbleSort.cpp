// BubbleSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place   
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}

/* Function to print an array */
void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// Driver program to test above functions
int main()
{
	int timer = GetTickCount();
	int arr[] = { 4, 17, 79, 52, 56, 19, 21, 22, 3, 12, 30, 33, 81, 99, 85, 28, 24, 26, 27, 20, 44, 32, 35, 24, 39, 43, 41, 46, 56, 62, 22, 20, 69, 18 };
	int n = sizeof(arr) / sizeof(arr[0]);
	bubbleSort(arr, n);
	printf("Sorted array: \n");
	printArray(arr, n);
	
	timer = GetTickCount() - timer;

	printf("Bubble sort Time: %d ms", timer);

	return 0;
}