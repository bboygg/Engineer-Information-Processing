# 2. 소프트웨어 개발

## 데이터 입,출력 구현

### 자료구조
효율적인 프로그램을 작성할 때 가장 우선적인 고려사항은 저장 공간의 효율성과 실행시간의 신속성이다. 자료 구조는 프로그램에서 사용하기 위한 자료를 기억장치의 공간 내에 저장하는 방법과 저장된 그룹 내에 존재하는 자료 간의 고나계, 처리 방법등을 연구 분석하는 것을 말한다.

### 자료구조의 분류

- Linear Structure
    - Array
    - Linear List
        - Contiguous List
        - Linked List
    - Stack
    - Queue
    - Deque
- Non-Linear Structure
    - Tree
    - Graph

### 선형리스트(Linear List)
선형 리스트는 일정한 순서에 의해 나열된 자료구조이다.

- 선형리스트는 배열을 이용하는 연속리스트와 포인터를 이용하는 연결 리스트로 구분된다.

> *포인터(Pointer)*
포인터는 현재의 위치에서 다음 노드의 위치를 알려주는 요소.
>- 프론터 포인터
    리스트를 구성하는 최초의 노드위치를 가리키는 요소
>- 널 포인터
    다음 노드가 없음을 나타내는 포인터로, 일반적으로 마지막 노드의 링크 부분에 0, ^, \0 등의 기호를 입력하여 표시


### 연결리스트(Linked List)
- 연결리스트는 자료들을 반드시 연속적으로 배열시키지는 않고 임의의 기억공간에 기억시키되, 자료 항목의 순서에 따라 노드의 포인터 부분을 이용하여 서로 연결시킨 자료구조이다.
- 연결 리스트는 노드의 삽입, 삭제 작업이 용이하다.
- 기억 공간이 연속적으로 놓여 있지 않아도 저장할 수있다.
- 연결 리스트는 연결을 위한 링크 부분이 필요하기 때문에 순차 리스트에 비해 기억 공간의 이용 효율이 좋지 않다.
- 연결을 위한 포인터를 찾는 시간이 필요하기 때문에 접근속도가 느리다.
- 중간 노드 연결이 끊어지면 그 다음 노드를 찾기 힘들다.

#### 스택(Stack)
스택은 리스트의 한 쪽 끝으로만 자료의 삽입, 삭제 작업이 이루어 지는 자료구조다.
- 가장 나중에 삽입된 자료가 가장 먼저 삭제되는 후입선출(LIFO)방식으로 자료를 처리한다.
- 스택의 모든 기억 공간이 꽉 채워져 있는 상태에서 데이터가 삽입되면 오버플로가 발생하며, 더 이상 삭제할 데이터가 없는 상태에서 데이터를 삭제하면 언더플로가 발생한다.
- 한쪽으로만 입출력이 가능하다.
- 인터럽트 처리, 서브루틴 호출 작업 등에 응용된다.

*Basic Operations for Stack*
```c
// push() - Pushing(storing) an element on the stack
void push(int data) {
   if(!isFull()) {
      top = top + 1;   
      stack[top] = data;
   } else {
      printf("Could not insert data, Stack is full.\n");
   }
}
// pop() - Removing(accessing) and eleemnt from the stack
int pop(int data) {

   if(!isempty()) {
      data = stack[top];
      top = top - 1;   
      return data; //pop operation return deleted data.
   } else {
      printf("Could not retrieve data, Stack is empty.\n");
   }
}

```


#### 큐(Queue)
큐는 리스트의 한쪽에서 삽입 작업이 이루어지고 다른 한쪽에서는 삭제 작업이 이루어지도록 구성한 자료 구조이다.
- 한쪽으로는 입력만, 다른 한쪽으로는 출력만 가능함
- 큐는 가장 먼저 삽입된 자료가 가장 먼저 삭제되는 선입선출(FIFO) 방식으로 처리한다.
- 큐는 시작과 끝을 표시하는 두 개의 포인터가 있다.
    - 프론트 포인터: 가장 먼저 삽입된 자료의 기억공간을 가리키는 포인터로, 삭제 작업을 할 때 사용한다.
    - 리어 포인터: 가장 마지막에 삽입된 자료가 위치한 기억공간을 가리키는 포인터로, 삽입 작업을 할 때 사용한다.
- 큐는 운영체제의 작업 스케쥴링에 사용한다.

#### 데크(Deque)
- 선형 리스트의 양쪽 끝에서 삽입과 삭제가 모두 가능한 자료구조이다. 


### 정렬(Sort)

#### 삽입 정렬
삽입정렬은 가장 간단한 정렬 방식으로 이미 순서화된 파일에 새로운 하나의 레코드를 순서에 맞게 삽입시켜 정렬한다.
- 두 번째 키와 첫 번째 키를 비교해 순서대로 나열(1회전)하고, 이어서 세 번째 키를 첫번 째, 두번 째 키와 비교해 순서대로 나열(2회전)하고, 계속해서 n번째 키를 앞의 n-1개의 키와 비교하여 알맞은 순서에 삽입하여 정렬하는 방식이다.
- 평균과 최악 모두 수행 시간 복잡도는 O(n^2)이다.

```c
// C program for insertion sort
#include <math.h>
#include <stdio.h>
 
/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
 
// A utility function to print an array of size n
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
/* Driver program to test insertion sort */
int main()
{
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    insertionSort(arr, n);
    printArray(arr, n);
 
    return 0;
}
```

#### 쉘 정렬
쉘 정렬은 삽입 정렬을 확장시킨 개념이다.
- 입력 파일을 어떤 매개변수(h)의 값으로 서브파일을 구성하고, 각 서브파일을 Insertion 정렬방식으로 순서 배열하는 과정을 반복하는 정렬 방식.
- 입력 파일이 부분적으로 정렬되어 있는 경우에 유리한 방식
- 평귝 수행시간 복잡도는 O(n^1.5)이고, 최악의 수행 시간 복잡도는 O(n^2)이다.
```c
// C++ implementation of Shell Sort
#include  <iostream>
using namespace std;
 
/* function to sort arr using shellSort */
int shellSort(int arr[], int n)
{
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted
        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];
 
            // shift earlier gap-sorted elements up until the correct
            // location for a[i] is found
            int j;           
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
             
            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
    return 0;
}
 
void printArray(int arr[], int n)
{
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
}
 
int main()
{
    int arr[] = {12, 34, 54, 2, 3}, i;
    int n = sizeof(arr)/sizeof(arr[0]);
 
    cout << "Array before sorting: \n";
    printArray(arr, n);
 
    shellSort(arr, n);
 
    cout << "\nArray after sorting: \n";
    printArray(arr, n);
 
    return 0;
}
```




#### 선택정렬
선택정렬은 n개의 레코드 중에서 최소값을 찾아 첫 번째 레코드 위치에 놓고, 나머지 n-1개 중에서 다시 최소값을 찾아 두번째 레코드 위치에 놓는 방식을 반복하여 정렬하는 방식이다. 
- 평균과 최악 모두 수행시간 복잡도는 O(n^2)이다.

```c
// C program for implementation of selection sort
#include <stdio.h>
  
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
  
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
  
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
  
        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}
  
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
  
// Driver program to test above functions
int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}

```

버블정렬(Bubble Sort)
- 버블 정렬은 주어진 파일에서 인접한 두 개의 레코드 키 값을 비교하여 그 크기에 따라 레코드 위치를 서로 교환하는 정렬방식이다.
- 계속 정렬 여부를 플래그 비트로 결정한다.
- 평균과 최악 모두 수행 시간 복잡도는 O(n^2)이다.
```c
// C program for implementation of Bubble sort
#include <stdio.h>
 
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
// A function to implement bubble sort
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
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
// Driver program to test above functions
int main()
{
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
```
#### 퀵정렬
퀵 정렬은 레코드의 많은 자료 이동을 없애고 하나의 파일을 부분적으로 나누어 가면서 정렬하는 방법으로 키를 기준으로 작은 값은 왼쪽에, 큰 값은 오른쪽 서브파일로 분해시키는 방식으로 정렬한다.
- 위치에 관계없이 임의의 키를 분할 원소로 사용할 수 있다.
- 정렬 방식 중에서 가장 빠른 방식이다.
- 프로그램에서 되부름을 이용하기 때문에 스택이 필요하다.
- 분할과 정복을 통해 자료를 정렬한다.
    - 분할: 기준값이 피봇을 중심으로 정렬할 자료들을 2개의 부분집합으로 나눈다.
    - 정복: 부분집합의 원소들 중 피봇보다 작은 원소들은 왼쪽, 피봇보다 큰 원소들은 오른쪽 부분집합으로 정렬한다. *부분집압의 크기가 더 이상 나누어 질 수없을 때까지 분할과 정복을 반복 수행한다.
- 평균수행시간 복잡도는 O(nlog2n)이고, 최악의 수행시간 복잡도는O(n^2)
```c++
/* C++ implementation of QuickSort */
#include <bits/stdc++.h>
using namespace std;
 
// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
 
    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
 
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
 
// Driver Code
int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}
 
// This code is contributed by rathbhupendra

```

#### 힙정렬
힙 정렬은 전이진 트리를 이용한 정렬 방식이다.
- 구성된 전이진 트리를 Heap tree로 변환하여 정렬한다.
- 평균과 최악 모두 시간 복잡도는 O(nlog2n)이다.
```c++
// C++ program for implementation of Heap Sort
#include <iostream>

using namespace std;

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i)
{
	int largest = i; // Initialize largest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i) {
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify(arr, n, largest);
	}
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// One by one extract an element from heap
	for (int i = n - 1; i > 0; i--) {
		// Move current root to end
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}

/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

// Driver code
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);

	heapSort(arr, n);

	cout << "Sorted array is \n";
	printArray(arr, n);
}

```

#### 2-Way 합병 정렬
이미 정렬되어 있는 두 개의 파일을 한 개의 파일로 합병하는 정렬 방식이다. 
- 두 개의 키들을 한쌍으로 하여 각 쌍에 대하여 순서를 정한다.
- 순서대로 정렬된 각 쌍의 키들을 합병하여 하나의 정렬된 서브리스트로 만든다.
- 위 과정에서 정렬된 서브리스트들을 하나의 정렬된 파일이 될 때까지 반복한다.
- 평균과 최악 모두 시간 복잡도는 O(log2n)이다.
```c
/* C program for Merge Sort */
#include <stdio.h>
#include <stdlib.h>

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	int L[n1], R[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	are any */
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
	if (l < r) {
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		int m = l + (r - l) / 2;

		// Sort first and second halves
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

/* Driver code */
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	printf("Given array is \n");
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	printf("\nSorted array is \n");
	printArray(arr, arr_size);
	return 0;
}

```


## 통합 구현


## 제품 소프트웨어 패키징



## 애플리케이션 테스트관리

### 통합테스트(Integration Test)
통합 테스트는 단위 테스트가 끝난 모듈을 통합하는 과정에서 발생하는 오류 및 결함을 찾는 테스트 기법이다.

#### 하향식 통합테스트(Top Down Integration Test)
하향식 통합 테스트는 프로그램의 상위 모듈에서 하위 모듈 방향으로 ㅌ오합하면서 테스트하는 기법이다.

- 테스트 초기부터 사용자에게 시스템 구조를 보여줄 수있다.
- 상위 모듈에서는 테스트 케이스를 사용하기 어렵다.
- 절차
    - 주요 제어 모듈은 작성된 프로그램을 사용하고, 주요 제어 모듈의 종속 모듈들은 스텁(STUB)으로 대체한다.
    - 깊이 우선 또는 넓이 우선 등의 통합 방ㅅ기에 따라 하위 모듈인 스텁들이 한번에 하나씩 실제 모듈로 교체된다.
    - 모듈이 통합될 때마다 테스트를 실시한다.
    - 새로운 오류가 발생하지 않음을 보증하기 위해 회귀 테스트를 실시한다.

#### 상향식 통합 테스트(Bottom Up Integration Test)
상향식 통합 테스트는 프로그램의 하위 모듈에서 상위 모듈 방향으로 통합하면서 테스트하는 기법이다.

- 가장 하위 단계의 모듈부터 통합 및 테스트가 수행되므로 스텁은 필요하지 않지만, 하나의 주요 제어 모듈과 관련된 종속 모듈의 그룹인 클러스터가 필요하다.
- 절차
    - 하위 모듈을 클러스트로 결합한다.
    - 상위 모듈에서 데이터의 입,출력을 확인하기 위해 더미 모듈인 드라이버를 작성한다.
    - 통합된 클러스터 단위로 테스트한다.
    - 테스트가 완료되면 클러스터는 프로그램 구조의 상위로 이동하여 결합하고 드라이버는 실제 모듈로 대체된다.



> 테스트 스텁(Test Stub)
제어 모듈이 호출하는 타 모듈의 기능을 단순히 수행하는 도구로, 일시적으로 필요한 조건만을 가지고 있는 시험용 모듈입니다.

> 테스트 드라이버(Test Driver)
테스트 드라이버는 테스트 대상의 하위 모듈을 호출하고, 파라미터를 전달하고, 모듈 테스트를 수행 후의 결과를 도출하는 도구입니다.

> [Differences betwen test stub and test driver](https://www.quora.com/What-is-the-difference-between-stubs-and-drivers-in-software-testing)
>
> Stubs are dummy modules that always used to simulate the low level modules.
>
>Stubs are the called programs.
>
>Stubs are used when sub programs are under construction.
>
>Stubs are used in top down approach
>
>Drivers are dummy modules that always used to simulate the high level modules.
>
>Drivers are the calling programs.
>
>Drivers are only used when main programs are under construction.
>
>Drivers are used in bottom up integration.





## 인터페이스 구현

### 인터페이스 구현
인터페이스 구현은 송.수신 시스템 간의 데이터 교환 및 처리를 실현해 주는 작업을 의미한다.

### 데이터 통신을 이용한 인터페이스 구현
데이터 통신을 이용한 인터페이스 구현은 애플리케이션 영역에서 인터페이스 형식에 맞춘 데이터 포맷을 인터페이스 대상으로 전송하고 이를 수신 측에서 파싱하여 해석하는 방식이다.
> 파싱(Parsing)
파싱은 주어진 문장이 정의된 문법 구조에 따라 완전한 문장으로 사용될 수 있는가를 확인하는 작업을 말합니다.

- 주로 JSON이나 XML 형식의 데이터 포맷을 사용해서 인터페이스를 구현한다.

> JSON / XML / AJAX ??
JSON(Javascript Object Notation)
JSON은 속성-값 쌍(Attribute-Value Pairs)으로 이루어진 데이터 객체를 전달하기 위해 사람이 읽을 수 있는 텍스트를 사용하는 개방형 표준 포맷입니다.
*비동기 처리에 사용되는  AJAX에서 XML 을 대체하여 사용되고 있습니다.
>
>XML(eXtensible Markup Lanuage)
XML은 특수한 목적을 갖는 마크업 언어를 만드는데 사용되는 다목적 마크업언어입니다.
*웹 페이지의 기본형식인 HTML의 문법이 각 웹 브라우저에서 상호 호환적이지 못하다는 문제와 SGML의 복잡함을 해결하기 위하여 개발되었습니다.
>
>AJAX(Asynchronous JavaScript and XML)
자바 스크립트 등을 이용하여 클라이언트와 서버 간에 XML 데이터를 교환 및 제어함으로써 이용자가 웹 페이지와 자유롭게 상호 작용할 수있도록 하는 비동기 통신 기술.
>
>YAML
XML, C, 파이썬, 펄, RFC2822에서 정의된 e-mail 양식에서 개념을 얻어 만들어진 '사람이 쉽게 읽을 수 있는' 데이터 직렬화 양식이다.
YAML이라는 이름은 'YAML Ain't Markup Language'라는 재귀적인 이름에서 유래되었다. 원래YAML의 뜻은 'Yet Another Markup Language'였으나, YAML의 핵심은 문서 마크업이 아닌 데이터 중심에 있다는 것을 보여주기 위해 이름을 바꾸었다. 오늘날 XML과 JSON이 데이터 직렬화에 주로 쓰이기 시작하면서, 많은 사람들이 YAML을 '가벼운 마크업 언어'로 사용하려 하고 있다.




