#include <iostream>
using namespace std;

void mergeSort(int arr[], int low, int high);
void merge(int arr[], int low, int mid, int mid1, int high);

// Perform mergeSort to sort an array of integers.
// Inputs:
//   arr is the input array of arrSize integers.
//   low and high are the indices to sort to/from, e.g. 0 arrSize-1 to sort entire array
// Postcondition:
//   arr[low] ... arr[high] will contain the original values, sorted in increasing order.
void mergeSort(int arr[], int low, int high)
{
	// Base case
	if (low < high)
	{
		int mid = low + (high - low) / 2;	  //This avoids overflow when low, high are too large
		mergeSort(arr, low, mid);			   // Recursively partition left side of array until each subarray is length 1
		mergeSort(arr, (mid + 1), high);	   // Recursively partition right side of array until each subarray is length 1
		merge(arr, low, mid, (mid + 1), high); // Recursively merge left and right partitions
	}
}

// Perform a merge of two sorted sub-arrays.
// Inputs:
//   arr is the input array on which to perform a merge.
//   low-mid and mid1-high are the two sub-arrays to merge.
// Precondition:
//   arr[low]...arr[mid] is sorted in increasing order.
//   arr[mid1]...arr[high] is sorted in increasing order.
//   These should be disjoint, contiguous sub-arrays too.
// Postcondition:
//   arr[low]...arr[high] is sorted in increasing.
void merge(int arr[], int low, int mid, int mid1, int high)
{
	// Initialize Indices
	int arrIndex1 = low;
	int arrIndex2 = mid1;

	// Create temp array
	int arrSize = (high - low) + 1;
	int tempArr[arrSize];
	int tempArrIndex = low;

	// While both subarrays contain unmerged elements
	while (arrIndex1 <= mid && arrIndex2 <= high)
	{
		if (arr[arrIndex1] <= arr[arrIndex2])
		{
			tempArr[tempArrIndex] = arr[arrIndex1];
			arrIndex1++;
		}
		else
		{
			tempArr[tempArrIndex] = arr[arrIndex2];
			arrIndex2++;
		}
		tempArrIndex++;
	}

	// If subArray1 has unmerged items
	while (arrIndex1 <= mid)
	{
		tempArr[tempArrIndex] = arr[arrIndex1];
		arrIndex1++;
		tempArrIndex++;
	}

	// If subArray2 has unmerged items
	while (arrIndex2 <= high)
	{
		tempArr[tempArrIndex] = arr[arrIndex2];
		arrIndex2++;
		tempArrIndex++;
	}

	for (int i = low; i <= high; i++)
	{
		arr[i] = tempArr[i];
	}
}

// A driver program to test mergeSort.
// Reads in a number of integers (number, then sequence of values).
// Sorts using mergeSort.
// Prints the values in sorted order.
int main(void)
{
	int n;

	// Get the number of values.
	//	cout << "Enter the number of values to be sorted:" << endl;
	cin >> n;

	// Create array in dynamic memory.
	int *values;
	values = new int[n];

	for (int i = 0; i < n; i++)
	{
		// cout << "Enter a number:" << endl;
		cin >> values[i];
	}

	// Call mergeSort to sort entire array.
	mergeSort(values, 0, n - 1);

	// Print values, should be sorted.
	for (int i = 0; i < n; i++)
	{
		cout << values[i] << " ";
	}
	cout << endl;

	// Free up memory.  Note use of delete [], since this is an array.
	delete[] values;

	return 0;
}
