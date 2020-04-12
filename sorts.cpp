#include<algorithm>
#include<iostream>
#include<cmath>
#include"sorts.h"

#define MAX 2000000

#define IS_EMPTY(e) (e<0)
#define NONE -1

using namespace std;

void swapValue(int *a, int *b)
{
    int *temp = a;
    a = b;
    b = temp;
    return;
}
//INTROSORT
/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int *begin, int *end)
{
    // Get the left and the right index of the subarray
    // to be sorted
    int left = begin - arr;
    int right = end - arr;

    for (int i = left+1; i <= right; i++)
    {
        int key = arr[i];
        int j = i-1;
       /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= left && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
   }

   return;
}

// A function to partition the array and return
// the partition point
int* partition(int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            // increment index of smaller element
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (arr + i + 1);
}


// A function that find the middle of the
// values pointed by the pointers a, b, c
// and return that pointer
int *medianOfThree(int * a, int * b, int * c)
{
    if (*a < *b && *b < *c)
        return (b);

    if (*a < *c && *c <= *b)
        return (c);

    if (*b <= *a && *a < *c)
        return (a);

    if (*b < *c && *c <= *a)
        return (c);

    if (*c <= *a && *a < *b)
        return (a);

    if (*c <= *b && *b <= *a)
        return (b);
}

// A Utility function to perform intro sort
void introsortUtil(int arr[], int * begin, int * end, int depthLimit)
{
    // Count the number of elements
    int size = end - begin;
    // If partition size is low then do insertion sort
    if (size < 16)
    {
        insertionSort(arr, begin, end);
        return;
    }
    // If the depth is zero use heapsort
    if (depthLimit == 0)
    {
        make_heap(begin, end+1);
        sort_heap(begin, end+1);
        return;
    }
    // Else use a median-of-three concept to
    // find a good pivot
    int * pivot = medianOfThree(begin, begin+size/2, end);
    // Swap the values pointed by the two pointers
    swapValue(pivot, end);
   // Perform Quick Sort
    int * partitionPoint = partition(arr, begin-arr, end-arr);
    introsortUtil(arr, begin, partitionPoint-1, depthLimit - 1);
    introsortUtil(arr, partitionPoint + 1, end, depthLimit - 1);

    return;
}

/* Implementation of introsort*/
void introsort(int arr[], int *begin, int *end)
{
    int depthLimit = 2 * log(end-begin);

    // Perform a recursive Introsort
    introsortUtil(arr, begin, end, depthLimit);

    return;
}
//END INTROSORT

//COUNTING SORT
int getMax(int arr[], int size)
{
    int max = arr[1];
    for(int i = 2; i<=size; i++)
    {
        if(arr[i] > max)
        max = arr[i];
    }

    return max; //the max element from the array
}
void countingSort(int *arr, int n)
{
    int max = getMax(arr, n);
	int *counting = new int[max];
	int k = 0;

	for(int i = 0; i < max; i++)
		counting[i] = 0;

	for(int i = 0; i < n; i++)
		counting[arr[i]]++;

	for(int i = 0; i < max; i++)
	{
		int count = counting[i];
		for(int j = 0; j < count; j++)
		{
			arr[k] = i;
			k++;
		}
	}
}
//END COUNTING SORT

//LIBRARY SORT

void prepareLibrarySort(int epsilon, int n, int S[], int * sLen)
{
    int i;
    *sLen = (1+epsilon)*n;

    for(i=0;i<*sLen;i++)
        S[i] = NONE;
}

int searchFree(int e, int sorted[], int last)
{
    int first = 0;
    int middle;

    while(last>=0 && IS_EMPTY(sorted[last]))
        last --;

    while(first<=last && IS_EMPTY(sorted[first]))
        first ++;

    while(first<=last)
    {
        middle = (first+last)/2;
        if(IS_EMPTY(sorted[middle]))
        {
            int tmp = middle + 1;
            //Look to the right
            while(tmp<last && IS_EMPTY(sorted[tmp]))
                tmp ++;
            if(sorted[tmp]>e)
            {
                tmp = middle - 1;
                while(middle>first && IS_EMPTY(sorted[middle]))
                    middle --;
                //Look to the left
                if(sorted[middle]<e)//Found intermediate position
                    return middle;
                last = middle - 1;
            }
            else
                first = tmp + 1;
        }
        else if(sorted[middle]<e)
            first = middle + 1;

        else
            last = middle - 1;
    }
    //If no position was found return -1 or if a lower position was found, return that
    if(last >= 0 && IS_EMPTY(sorted[last]))
        last --;

    return last;
}

void libSort(int A[], int N, int S[], int EPSILON)
{
    if(N==0)
        return;

    int j, k, step;
    // ------ BASE CASE ------
    //Goal: We want 'goal' elements to be inserted into S, for now..
    int goal = 1;
    //How many elements have already been inserted, its 1 for efficiency
    int pos = 1;
    S[0] = A[0];//We insert element 0 at position 0
    //Initial size of array S
    int sLen = max((1+EPSILON), goal + 1);
    // ------ CONDITION -------
    //What has already been read must be less than the total array size
    while(pos<N)
    {
        // ------ ROUND ------
        //Each round i will end with goal=2^i sorted elements. i starts with 1
        for(j = 0;j < goal;j++)
        {
            //Search where to insert A[pos] (with binary search)
            int insPos = searchFree(A[pos], S, sLen-1);
            //Because our binary search returns us the location of an smaller item than the one we search...
            insPos ++;
            if(!IS_EMPTY(S[insPos]))
            {
                //There is no place where we wanted to insert that element
                int nextFree = insPos + 1;//Search a free space forward
                while(!IS_EMPTY(S[nextFree]))
                    nextFree ++;
                //At 'nextFree' there is a place, translate all elements one position to the right
                if(nextFree >= sLen)
                {//Wait! nextFree is out of bounds
                    insPos--;
                    if(!IS_EMPTY(S[insPos]))
                    {
                        //Search backward
                        nextFree = insPos - 1;
                        while(!IS_EMPTY(S[nextFree]))
                            nextFree--;
                        //Now we translate all the elements to the left
                        while(nextFree < insPos)
                        {
                            S[nextFree] = S[nextFree+1];
                            nextFree++;
                        }
                    }
                }
                else
                {
                    //Now we translate all the elements to the right
                    while(nextFree>insPos)
                    {
                        S[nextFree] = S[nextFree - 1];
                        nextFree--;
                    }
                }
                //Now nextFree is insPos; in other words, insPos is free
            }
            else if(insPos>=sLen)
            {
                //insPos is out of bounds
                //Search a free space backwards
                insPos--;//This place must be between the limits
                int nextFree = insPos - 1;
                while(!IS_EMPTY(S[nextFree]))
                    nextFree --;
                //Now we translate all the elements to the left
                while(nextFree<insPos)
                {
                    S[nextFree] = S[nextFree + 1];
                    nextFree++;
                }
                //Now nextFree is insPos; in other words insPos is free
            }
            S[insPos] = A[pos++];//We insert the element and increment our counter

            if(pos >= N)
                return;//That element was the last, return from the function
        }

        // ----- REBALANCE -----
        //It takes linear time. Tries to spread the elements as much as possible
        for
        (
            j = sLen-1, k = min(goal*(2 + 2*EPSILON), (1 + EPSILON)*N) - 1,
            step = (k + 1)/(j + 1); j >= 0;
            j--, k -= step
        )
        {
            S[k] = S[j];
            S[j] = NONE;
        }

        //In each round insert the double of elements to the sorted array
        // because there will be the double of free spaces after the rebalance
        sLen = min(goal*(2 + 2*EPSILON), N*(1 + EPSILON));
        goal <<= 1;//We increment i
    }
}

void librarySort(int A[], int n)
{
    int epsilon = 1;
    int *S = new int[MAX];
    int sLen, i, j;
    //This takes linear time
    prepareLibrarySort(epsilon, n, S, &sLen);
    //O (n log n)
    libSort(A, n, S, epsilon);
    //This takes linear time
    for(i = 0, j = 0; i < sLen && j < n; i++)
        if(!IS_EMPTY(S[i]))
            A[j++] = S[i];
    delete S;
}

