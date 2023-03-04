/*
Author: My Tran
Filename: QuickSort.cpp
Date: 12/18/2022
Desc.: Implementation of QuickSort algorithm on array of integers
*/
#include<iostream>
#include<vector>

//Function prototypes:
void QuickSort(std::vector<int>&, int, int);
int Partition(std::vector<int>&, int, int);
void Swap(std::vector<int>&, int, int);

int main()
{
	std::vector<int> v = { 5, 6, 3, 7, 8, 4 };

	QuickSort(v, 0, 5);

	for (int i : v)
	{
		std::cout << i << " ";
	}

	return 0;
}

//O(n*logn) to O(n^2)
/*
Purpose:	Performs quicksort on array
Pre:		Takes arguments arr (array), upper and lower bound indices (init and end)
Post:		Section of arr from init to end are sorted
*/
void QuickSort(std::vector<int>& arr, int init, int end)
{
	if (init < end)
	{
		//get pivot for recursive QuickSort
		int pivot = Partition(arr, init, end);

		//Perform QuickSort on first half of the given array
		QuickSort(arr, init, pivot);

		//Perform QuickSort on second half of the given array
		QuickSort(arr, pivot + 1, end);
	}
}

//O(n)
/*
Purpose:	Partitions array into portions for Quicksort
Pre:		Takes arguments arr (array), upper and lower bound indices (init and end)
Post:		Partitioned array at pivot where values to left are less and to right are greater
*/
int Partition(std::vector<int>& arr, int init, int end)
{
	//pivot is selected from the first val in list
	int pivot = arr.at((init+end)/2);
	int lhs = init;
	int rhs = end;

	while (true)
	{
		//scan r->l in the array to find a value <= the pivot
		while (arr.at(rhs) > pivot)
		{
			rhs--;
		}
		//scan l->r to find a value >= the pivot
		while (arr.at(lhs) < pivot)
		{
			lhs++;
		}

		//if duplicates, take lhs
		if (arr.at(lhs) == arr.at(rhs))
		{
			return lhs;
		}
		//while the lhs index is still before the rhs index, perform swaps and continue scans
		else if (lhs < rhs)
		{
			Swap(arr, lhs, rhs);
		}
		else
		{
			return rhs;
		}
	}
}

//O(1)
/*
Purpose:	Swaps 2 values in an array
Pre:		Take array arguement, and two indices of type int
Post:		Values at posA and posB are swapped in arr
*/
void Swap(std::vector<int>&arr, int posA, int posB)
{
	//temp =  a, a = b, b = a swapping operation
	int temp = arr.at(posA);
	arr.at(posA) = arr.at(posB);
	arr.at(posB) = temp;
}