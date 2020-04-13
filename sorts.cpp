#include"sorts.h"

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
void countingSort(vector<int> arr, int n)
{
    // Map to store the frequency
    // of the array elements
    std::map<int, int> freqMap;
    for (auto i = arr.begin(); i != arr.end(); i++)
    {
        freqMap[*i]++;
    }

    int i = 0;

    // For every element of the map
    for (auto it : freqMap)
    {
        // Value of the element
        int val = it.first;

        // Its frequency
        int freq = it.second;
        for (int j = 0; j < freq; j++)
            arr[i++] = val;
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

void libSort(int * arr, int N, int S[], int EPSILON)
{
    if(N==0)
        return;

    int j, k, step;
    // ------ BASE CASE ------
    //Goal: We want 'goal' elements to be inserted into S, for now..
    int goal = 1;
    //How many elements have already been inserted, its 1 for efficiency
    int pos = 1;
    S[0] = arr[0];//We insert element 0 at position 0
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
            int insPos = searchFree(arr[pos], S, sLen-1);
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
            S[insPos] = arr[pos++];//We insert the element and increment our counter

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

void librarySort(int * arr, int n)
{
    int epsilon = 1;
    int *S = new int[MAX];
    int sLen, i, j;
    //This takes linear time
    prepareLibrarySort(epsilon, n, S, &sLen);
    //O (n log n)
    libSort(arr, n, S, epsilon);
    //This takes linear time
    for(i = 0, j = 0; i < sLen && j < n; i++)
        if(!IS_EMPTY(S[i]))
            arr[j++] = S[i];
    delete S;
}

//SMOOTH SORT
void smoothsort (int * arr, int _n)

   /**
    **  Sorts the given array in ascending order.
    **
    **    Usage: smoothsort (<array>, <size>)
    **
    **    Where: <array> pointer to the first element of the array in question.
    **            <size> length of the array to be sorted.
    **
    **
    **/
{
    if (!(arr && _n))
        return;

    unsigned long long p = 1;
    LeonardoNumber b;

    for (unsigned q = 0; ++q < _n ; ++p)
        if (p % 8 == 3)
        {
            sift (arr, q - 1, b);
            ++++b;
            p >>= 2;
        }
        else if (p % 4 == 1)
        {
            if (q + ~b < _n)
                sift (arr, q - 1, b);
            else
                trinkle (arr, q - 1, p, b);

            for (p <<= 1; --b > 1; p <<= 1);
        }
        trinkle (arr, _n - 1, p, b);

        for (--p; _n-- > 1; --p)
            if (b == 1)
                for ( ; !(p % 2); p >>= 1)
                    ++b;

        else if (b >= 3)
        {
            if (p)
                semitrinkle (arr, _n - b.gap (), p, b);

            --b;
            p <<= 1;
            ++p;

            semitrinkle (arr, _n - 1, p, b);
            --b; p <<= 1; ++p;
        }

      return;
}
inline void sift (int * arr, unsigned _r, LeonardoNumber _b) throw ()

       /**
        **  Sifts up the root of the stretch in question.
        **
        **    Usage: sift (<array>, <root>, <number>)
        **
        **    Where:     <array> Pointer to the first element of the array in
        **                       question.
        **                <root> Index of the root of the array in question.
        **              <number> Current Leonardo number.
        **
        **
        **/
{
    unsigned r2;

    while (_b >= 3)
    {
        if (arr [_r - _b.gap ()] >= arr [_r - 1])
            r2 = _r - _b.gap ();
        else
        {
            r2 = _r - 1;
            --_b;
        }

        if (arr [_r] >= arr [r2])
            break;
        else
        {
            swap(arr [_r], arr [r2]); _r = r2; --_b;
        }
    }

    return;
}


inline void semitrinkle (
    int * arr,
    unsigned _r,
    unsigned long long _p,
    LeonardoNumber _b
) throw ()

       /**
        **  Trinkles the roots of the stretches of a given array and root when the
        **  adjacent stretches are trusty.
        **
        **    Usage: semitrinkle (<array>, <root>, <standard_concat>, <number>)
        **
        **    Where:           <array> Pointer to the first element of the array in
        **                             question.
        **                      <root> Index of the root of the array in question.
        **           <standard_concat> Standard concatenation's codification.
        **                    <number> Current Leonardo number.
        **
        **
        **/
{
    if (arr [_r - ~_b] >= arr [_r])
    {
        swap(arr [_r], arr [_r - ~_b]);
        trinkle (arr, _r - ~_b, _p, _b);
    }

    return;
}


inline void trinkle (
    int * arr,
    unsigned _r,
    unsigned long long _p,
    LeonardoNumber _b
) throw ()

       /**
        **  Trinkles the roots of the stretches of a given array and root.
        **
        **    Usage: trinkle (<array>, <root>, <standard_concat>, <number>)
        **
        **    Where:           <array> Pointer to the first element of the array in
        **                             question.
        **                      <root> Index of the root of the array in question.
        **           <standard_concat> Standard concatenation's codification.
        **                    <number> Current Leonardo number.
        **
        **
        **/
{
    while (_p)
    {
        for ( ; !(_p % 2); _p >>= 1)
            ++_b;

        if (!--_p || (arr [_r] >= arr [_r - _b]))
            break;
        else if (_b == 1)
        {
            swap(arr [_r], arr [_r - _b]); _r -= _b;
        }

        else if (_b >= 3)
        {
            unsigned r2 = _r - _b.gap (), r3 = _r - _b;
            if (arr [_r - 1] >= arr [r2])
            {
                r2 = _r - 1;
                _p <<= 1;
                --_b;
            }
            if (arr [r3] >= arr [r2])
            {
                swap(arr [_r], arr [r3]);
                _r = r3;
            }
            else
            {
                swap(arr [_r], arr [r2]);
                _r = r2; --_b;
                break;
            }
        }
    }
    sift(arr, _r, _b);

    return;
}
//END SMOOTH SORT
