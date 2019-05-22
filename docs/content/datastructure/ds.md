#
## Data Structure

### Binary Search Tree

<img src="https://www.google.com/url?sa=i&source=images&cd=&ved=2ahUKEwijx5PHs67iAhWFwrwKHQYxBV4QjRx6BAgBEAU&url=https%3A%2F%2Fwww.youtube.com%2Fwatch%3Fv%3D5lQD0IRS8fE&psig=AOvVaw1WGHCsCD2CRGy8ij_6GORx&ust=1558589029544498"
width="50%"
height="50%"
alt="BST Insert a Node Implementation-1"
align=center />

<br>
<img src="https://i2.wp.com/algorithms.tutorialhorizon.com/files/2016/03/Insert-Node-into-Single-Threaded-Binary-Tree.png?ssl=1"
width="50%"
height="50%"
alt="BST Insert a Node Implementation-2"
align=center />


+ [Insert a node in Binary Search Tree Iteratively](https://www.geeksforgeeks.org/insert-a-node-in-binary-search-tree-iteratively/)

```cpp
// C++ program to demonstrate insert operation
// in binary search tree
#include <bits/stdc++.h>
using namespace std;

// BST node
struct Node {
    int key;
    struct Node* left, *right;
};

// Utitlity function to create a new node
Node*
newNode(int data)
{
    Node* temp = new Node;
    temp->key = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// A utility function to insert a new
// Node with given key in BST
Node*
insert(Node* root, int key)
{
    // Create a new Node containing
    // the new element
    Node* newnode = newNode(key);
    // Pointer to start traversing from root and
    // traverses downward path to search
    // where the new node to be inserted
    Node* x = root;
    // Pointer y maintains the trailing
    // pointer of x
    Node* y = NULL;
    while (x != NULL) {
        y = x;
        if (key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    // If the root is NULL i.e the tree is empty
    // The new node is the root node
    if (y == NULL)
        y = newnode;
    // If the new key is less then the leaf node key
    // Assign the new node to be its left child
    else if (key < y->key)
        y->left = newnode;
    // else assign the new node its right child
    else
        y->right = newnode;
    // Returns the pointer where the
    // new node is inserted
    return y;
}

// A utility function to do inorder
// traversal of BST
void
Inorder(Node* root)
{
    if (root == NULL)
        return;
    else {
        Inorder(root->left);
        cout << root->key << " ";
        Inorder(root->right);
    }
}

// Driver code
int
main()
{
    /* Let us create following BST
    	 50
    	/ \
       30  70
      / \  / \
     20 40 60 80 */
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    // Print inoder traversal of the BST
    Inorder(root);
    return 0;
}
```

### Recursion

+ [fibonacci](https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/)

```text
Fn = Fn-1 + Fn-2

F0 = 0 and F1 = 1
```

```text
Method 1 ( Use recursion )
A simple method that is a direct recursive implementation mathematical recurrence relation given
above.
```
```c
#include<stdio.h>
int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n-1) + fib(n-2);
}

int main ()
{
    int n = 9;
    printf("%d", fib(n));
    getchar();
    return 0;
}
```

```text
Method 2 ( Use Dynamic Programming )
We can avoid the repeated work done is the method 1 by storing the Fibonacci numbers calculated so
far.
```
```c
#include<stdio.h>

int fib(int n)
{
    /* Declare an array to store Fibonacci numbers. */
    int f[n+2]; // 1 extra to handle case, n = 0
    int i;

    /* 0th and 1st number of the series are 0 and 1*/
    f[0] = 0;
    f[1] = 1;

    for (i = 2; i <= n; i++)
    {
        /* Add the previous 2 numbers in the series
           and store it */
        f[i] = f[i-1] + f[i-2];
    }

    return f[n];
}

int main ()
{
    int n = 9;
    printf("%d", fib(n));
    getchar();
    return 0;
}
```

+ [tower of hanoi](https://www.geeksforgeeks.org/c-program-for-tower-of-hanoi/)

```text
Take an example for 2 disks :
Let rod 1 = 'A', rod 2 = 'B', rod 3 = 'C'.

Step 1 : Shift first disk from 'A' to 'B'.
Step 2 : Shift second disk from 'A' to 'C'.
Step 3 : Shift first disk from 'B' to 'C'.

The pattern here is :
Shift 'n-1' disks from 'A' to 'B'.
Shift last disk from 'A' to 'C'.
Shift 'n-1' disks from 'B' to 'C'.

Image illustration for 3 disks :
```

<img src="https://cdncontribute.geeksforgeeks.org/wp-content/uploads/tower-of-hanoi.png"
width="50%"
height="50%"
alt="tower of hanoi"
align=center />

```c
#include <stdio.h>

// C recursive function to solve tower of hanoi puzzle
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1)
    {
        printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod);
        return;
    }
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod);
    printf("\n Move disk %d from rod %c to rod %c", n,
            from_rod, to_rod);
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}

int main()
{
    int n = 4; // Number of disks
    towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods
    return 0;
}
```

+ GCD

```text
Program to find GCD or HCF of two numbers:

A simple solution is to find all prime factors of both numbers, then find intersection of all
factors present in both numbers. Finally return product of elements in the intersection.

An efficient solution is to use Euclidean algorithm which is the main algorithm used for this
purpose. The idea is, GCD of two numbers doesn’t change if smaller number is subtracted from a
bigger number.
```

```c
// C program to find GCD of two numbers
#include <stdio.h>

// Recursive function to return gcd of a and b
int gcd(int a, int b)
{
    // Everything divides 0
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    // base case
    if (a == b)
        return a;

    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

// Driver program to test above function
int main()
{
    int a = 98, b = 56;
    printf("GCD of %d and %d is %d ", a, b, gcd(a, b));
    return 0;
}
```

```c
// C program to find GCD of two numbers
#include <stdio.h>

// Recursive function to return gcd of a and b
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Driver program to test above function
int main()
{
    int a = 98, b = 56;
    printf("GCD of %d and %d is %d ", a, b, gcd(a, b));
    return 0;
}
```

### Sort

+ [Selection Sort](https://www.geeksforgeeks.org/selection-sort/)

```text
Runtime: O(n^2) average and worst case, memory: O(1)
```

```c
// C program for implementation of selection sort
#include <stdio.h>

void
swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void
selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++) {
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
void
printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int
main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
```

+ [Merg sort](https://www.geeksforgeeks.org/merge-sort/)

<img src="https://www.geeksforgeeks.org/wp-content/uploads/Merge-Sort-Tutorial.png"
width="50%"
height="50%"
alt="merge sort"
align=center />

```text
Runtime: O(nlog(n)) average and worst case, memory: O(1)
```

```c
/* C program for Merge Sort */
#include<stdlib.h>
#include<stdio.h>

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void
merge(int arr[], int l, int m, int r)
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
        R[j] = arr[m + 1+ j];
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
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
void
mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

/* UTILITY FUNCTIONS */
/* Function to print an array */
void
printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

/* Driver program to test above functions */
int
main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    printf("Given array is \n");
    printArray(arr, arr_size);
    mergeSort(arr, 0, arr_size - 1);
    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}
```

+ [insertion](https://www.geeksforgeeks.org/insertion-sort/)

<img src="https://cdncontribute.geeksforgeeks.org/wp-content/uploads/insertionsort.png"
width="50%"
height="50%"
alt="insertion sort"
align=center />

```c
/* Function to sort an array using insertion sort*/
void
insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i-1;
        /* Move elements of arr[0..i-1], that are
        	greater than key, to one position ahead
        	of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

// A utility function to print an array of size n
void
printArray(int arr[], int n)
{
    int i;
    for (i=0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* Driver program to test insertion sort */
int
main()
{
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr, n);
    printArray(arr, n);
    return 0;
}
```

### Search

+ [Binary Search](https://www.geeksforgeeks.org/binary-search/)

<img src="https://www.geeksforgeeks.org/wp-content/uploads/Binary-Search.png"
width="50%"
height="50%"
alt="binary search"
align=center />

+ Recursive/ lterative implementation of Binary Search

```c
int
binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }
    // We reach here when element is not
    // present in array
    return -1;
}

int
main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? printf("Element is not present in array"):\
        printf("Element is present at index %d", result);
    return 0;
}
```

```c
int
binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
        // Check if x is present at mid
        if (arr[m] == x)
            return m;
        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;
        // If x is smaller, ignore right half
        else
            r = m - 1;
    }
    // if we reach here, then element was
    // not present
    return -1;
}

int
main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? printf("Element is not present" " in array"):\
        printf("Element is present at ""index %d", result);
    return 0;
}

```

### Stack and Queue

+ Conversion of Infix Expressions to Prefix and Postfix

Infix to Postfix
<br>
<img src="http://interactivepython.org/runestone/static/pythonds/_images/moveright.png"
width="50%"
height="50%"
alt="infix to postfix"
align=center />
<br>
Infix to prefix
<br>
<img src="http://interactivepython.org/runestone/static/pythonds/_images/moveleft.png"
width="50%"
height="50%"
alt="infix to prefix"
align=center />
<br>
Infix to prefix and postfix
<br>
<img src="http://interactivepython.org/runestone/static/pythonds/_images/moveleft.png"
width="50%"
height="50%"
alt="infix to prefix and postfix"
align=center />
<br>
How to work in statck
<br>
<img src="http://interactivepython.org/runestone/static/pythonds/_images/intopost.png"
width="70%"
height="70%"
alt="postfix in stack"
align=center />

[Stack | Set 2 (Infix to Postfix)](https://www.geeksforgeeks.org/stack-set-2-infix-to-postfix/)

```c
// C program to convert infix expression to postfix
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Stack type
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

// Stack Operations
struct Stack* createStack( unsigned capacity )
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    if (!stack)
        return NULL;
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    if (!stack->array)
        return NULL;
    return stack;
}

int
isEmpty(struct Stack* stack)
{
    return stack->top == -1 ;
}

char
peek(struct Stack* stack)
{
    return stack->array[stack->top];
}

char
pop(struct Stack* stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--] ;
    return '$';
}

void
push(struct Stack* stack, char op)
{
    stack->array[++stack->top] = op;
}

// A utility function to check if the given character is operand
int
isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

// A utility function to return precedence of a given operator
// Higher returned value means higher precedence
int
Prec(char ch)
{
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

// The main function that converts given infix expression
// to postfix expression.
int
infixToPostfix(char* exp)
{
    int i, k;
    // Create a stack of capacity equal to expression size
    struct Stack* stack = createStack(strlen(exp));
    if (!stack) // See if stack was created successfully
        return -1 ;
    for (i = 0, k = -1; exp[i]; ++i) {
        // If the scanned character is an operand, add it to output.
        if (isOperand(exp[i]))
            exp[++k] = exp[i];
        // If the scanned character is an ‘(‘, push it to the stack.
        else if (exp[i] == '(')
            push(stack, exp[i]);
        // If the scanned character is an ‘)’, pop and output from the stack
        // until an ‘(‘ is encountered.
        else if (exp[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(')
                exp[++k] = pop(stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                return -1; // invalid expression
            else
                pop(stack);
        } else { // an operator is encountered
            while (!isEmpty(stack) && Prec(exp[i]) <= Prec(peek(stack)))
                exp[++k] = pop(stack);
            push(stack, exp[i]);
        }
    }
    // pop all the operators from the stack
    while (!isEmpty(stack))
        exp[++k] = pop(stack );
    exp[++k] = '\0';
    printf( "%sn", exp );
}

// Driver program to test above functions
int
main()
{
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(exp);
    return 0;
}
```

[reference.stack](http://interactivepython.org/runestone/static/pythonds/BasicDS/InfixPrefixandPostfixExpressions.html)

[reference.C Operator Precedence](https://en.cppreference.com/w/c/language/operator_precedence)

+ [Queue using Stacks](https://www.geeksforgeeks.org/stack-set-2-infix-to-postfix/)

<img src="https://www.geeksforgeeks.org/wp-content/uploads/Stack-Queue.png"
width="30%"
height="30%"
alt="Queue and Stack"
align=center />
<br>

```c
#include <stdio.h>
#include <stdlib.h>

/* structure of a stack node */
struct sNode {
    int data;
    struct sNode* next;
};

/* Function to push an item to stack*/
void push(struct sNode** top_ref, int new_data);

/* Function to pop an item from stack*/
int pop(struct sNode** top_ref);

/* structure of queue having two stacks */
struct queue {
    struct sNode* stack1;
    struct sNode* stack2;
};

/* Function to enqueue an item to queue */
void
enQueue(struct queue* q, int x)
{
    push(&q->stack1, x);
}

/* Function to deQueue an item from queue */
int
deQueue(struct queue* q)
{
    int x;
    /* If both stacks are empty then error */
    if (q->stack1 == NULL && q->stack2 == NULL) {
        printf("Q is empty");
        getchar();
        exit(0);
    }
    /* Move elements from stack1 to stack 2 only if
    stack2 is empty */
    if (q->stack2 == NULL) {
        while (q->stack1 != NULL) {
            x = pop(&q->stack1);
            push(&q->stack2, x);
        }
    }
    x = pop(&q->stack2);
    return x;
}

/* Function to push an item to stack*/
void
push(struct sNode** top_ref, int new_data)
{
    /* allocate node */
    struct sNode* new_node = (struct sNode*)malloc(sizeof(struct sNode));
    if (new_node == NULL) {
        printf("Stack overflow \n");
        getchar();
        exit(0);
    }
    /* put in the data */
    new_node->data = new_data;
    /* link the old list off the new node */
    new_node->next = (*top_ref);
    /* move the head to point to the new node */
    (*top_ref) = new_node;
}

/* Function to pop an item from stack*/
int
pop(struct sNode** top_ref)
{
    int res;
    struct sNode* top;
    /*If stack is empty then error */
    if (*top_ref == NULL) {
        printf("Stack underflow \n");
        getchar();
        exit(0);
    } else {
        top = *top_ref;
        res = top->data;
        *top_ref = top->next;
        free(top);
        return res;
    }
}

/* Driver function to test anove functions */
int
main()
{
    /* Create a queue with items 1 2 3*/
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->stack1 = NULL;
    q->stack2 = NULL;
    enQueue(q, 1);
    enQueue(q, 2);
    enQueue(q, 3);
    /* Dequeue items */
    printf("%d ", deQueue(q));
    printf("%d ", deQueue(q));
    printf("%d ", deQueue(q));
    return 0;
}
```

+ [Radix Sort](https://www.geeksforgeeks.org/radix-sort/)

```c
// C++ implementation of Radix Sort
#include<iostream>
using namespace std;

// A utility function to get maximum value in arr[]
int getMax(int arr[], int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int n, int exp)
{
	int output[n]; // output array
	int i, count[10] = {0};

	// Store count of occurrences in count[]
	for (i = 0; i < n; i++)
		count[ (arr[i]/exp)%10 ]++;

	// Change count[i] so that count[i] now contains actual
	// position of this digit in output[]
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Build the output array
	for (i = n - 1; i >= 0; i--)
	{
		output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
		count[ (arr[i]/exp)%10 ]--;
	}

	// Copy the output array to arr[], so that arr[] now
	// contains sorted numbers according to current digit
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void radixsort(int arr[], int n)
{
	// Find the maximum number to know number of digits
	int m = getMax(arr, n);

	// Do counting sort for every digit. Note that instead
	// of passing digit number, exp is passed. exp is 10^i
	// where i is current digit number
	for (int exp = 1; m/exp > 0; exp *= 10)
		countSort(arr, n, exp);
}

// A utility function to print an array
void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

// Driver program to test above functions
int main()
{
	int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
	int n = sizeof(arr)/sizeof(arr[0]);
	radixsort(arr, n);
	print(arr, n);
	return 0;
}
```

### Array

[content](https://www.geeksforgeeks.org/array-data-structure/)

+ One Dimesion Array

A(0: u-1)

```text
Get A(i) address, A(i) = lo + i * d
lo: start address of array
i: index
d: size of data

if arrary is A(t:u), and A(i)=lo + (i-t)*d
```

+ Two Dimensions Array

A[0: u1-1, 0:u2-1], [Reference 2D array](https://www.dyclassroom.com/c/c-pointers-and-two-dimensional-array)

```text
As Row:
Get A(i, j) address, A(i, j) = lo + i*u2d + j*d = lo + (i*u2 + j)*d

As Column:
Get A(i, j) address, A(i, i) = lo + j*u1*d + i*d = lo + (j*u1 + i)*d
```

A(l1:u1, l2:u2)

```text
As Row:
Get A(i, j) address, A(i, j) = lo + (i-l1)*n*d + (j-l2)*d
n = u2-l2+1;

As Column:
Get A(i, j) address, A(i, i) = lo + (j-l2)*m*d + (i-l1)*d
m = u1-l1+1
```

```c
/*Passing a Multidimensional Array*/
void display2DArrayUnknownSizePtrPtr(int** arr, int rows, int cols) {
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            printf("%d ", *(*arr + i*cols + j));
    printf("\n");
}

void display2DArrayUnknownSizePtr(int* arr, int rows, int cols) {
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            printf("%d ", *(arr + (i*cols) + j));
    printf("\n");
}

void main() {
    int matrix[2][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10}
    };
    int* pa = matrix;
    display2DArrayUnknownSizePtrPtr(&pa, 2, 5);
    display2DArrayUnknownSizePtr(matrix, 2, 5);
}
```

+ Dynamically Allocating a Two-Dimensional Array

Allocating Potentially Noncontiguous Memory

<img src="Figure4_15_Noncontiguousallocation.png"
width="70%"
height="70%"
alt="Allocating Potentially Noncontiguous Memory"
align=center />

```c
/*Allocating Potentially Noncontiguous Memory*/
void main()
{
    int rows = 2;
    int columns = 5;
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(columns * sizeof(int));
    }
    for(int i=0; i<rows; i++)
        for(int j=0; j<columns; j++)
            matrix[i][j] = j;
    for(int i=0; i<rows; i++)
        for(int j=0; j<columns; j++)
            printf("%d ", matrix[i][j]);
}
```

Allocating Contiguous Memory

<img src="Figure4_16_Contiguousallocationwithtwomalloccalls.png"
width="70%"
height="70%"
alt="Contiguous allocation with two malloc calls"
align=center />

```c
int rows = 2;
int columns = 5;
int **matrix = (int **)malloc(rows * sizeof(int *));
matrix[0] = (int *) malloc(rows * columns * sizeof(int));
for (int i = 1; i < rows; i++)
    matrix[i] = matrix[0] + i * columns;
```

+ Three Dimesion Array

```text
TODO
```

### Linked List
#### Singly Linked List

[content](https://www.geeksforgeeks.org/data-structures/linked-list/singly-linked-list/)

#### Doubly Linked List

[content](https://www.geeksforgeeks.org/data-structures/linked-list/doubly-linked-list/)

+ Merge two sorted list

```text
Following merge two sorted array concept
```

```c
#include <stdio.h>
#include <stdlib.h>

struct node_t {
    int data;
    struct node_t* next;
};

void
printlist(struct node_t* node)
{
    struct node_t* tmp = node;
    while (tmp) {
        printf("r[%p]->%d\n", tmp, tmp->data);
        tmp = tmp->next;
    }
}

void
pushdata(struct node_t** node, int data)
{
    struct node_t* tmp = *node;
    struct node_t* newnode = \
        (struct node_t*)malloc(sizeof(struct node_t));
    newnode->data = data;
    newnode->next = NULL;
    if (!*node)
        *node = newnode;
    else {
        while (tmp) {
            if (!tmp->next) {
                tmp->next = newnode;
                break;
            }
            tmp = tmp->next;
        }
    }
}

struct node_t* mergelist(struct node_t* p, struct node_t* q)
{
    struct node_t* r = NULL;
    struct node_t* pcur = p, *qcur = q;
    while (pcur && qcur) {
        if (pcur->data < qcur->data) {
            pushdata(&r, pcur->data);
            pcur = pcur->next;
        } else {
            pushdata(&r, qcur->data);
            qcur = qcur->next;
        }
    }
    while (pcur) {
        pushdata(&r, pcur->data);
        pcur=pcur->next;
    }
    while (qcur) {
        pushdata(&r, qcur->data);
        qcur=qcur->next;
    }
    return r;
}

void
main(void)
{
    struct node_t* p = NULL;
    struct node_t* q = NULL;
    struct node_t* r = NULL;
    pushdata(&p, 1);
    pushdata(&p, 2);
    pushdata(&p, 4);
    pushdata(&q, 1);
    pushdata(&q, 3);
    pushdata(&q, 4);
    r = mergelist(p, q);
    printlist(r);
}

```

+ Revert Linked List

<img src="https://www.geeksforgeeks.org/wp-content/uploads/RGIF2.gif"
width="70%"
height="70%"
alt="Revert Linked List"
align=center />

```c
// Iterative C program to reverse a linked list
#include<stdio.h>
#include<stdlib.h>

/* Link list node */
struct Node {
    int data;
    struct Node* next;
};

/* Function to reverse the linked list */
static void
reverse(struct Node** head_ref)
{
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
    struct Node* next = NULL;
    while (current != NULL) {
        // Store next
        next = current->next;
        // Reverse current node's pointer
        current->next = prev;
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

/* Function to push a node */
void
push(struct Node** head_ref, int new_data)
{
    struct Node* new_node =
        (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

/* Function to print linked list */
void
printList(struct Node* head)
{
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

/* Driver program to test above function*/
int
main()
{
    /* Start with the empty list */
    struct Node* head = NULL;
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 85);
    printf("Given linked list\n");
    printList(head);
    reverse(&head);
    printf("\nReversed Linked list \n");
    printList(head);
    getchar();
}

```

+ Using Pointers to Support a Queue

```c
typedef struct _node_t{
    void* data;
    struct _node_t* next;
} node_t;

typedef struct _queue_t {
    node_t* head;
    node_t* tail;
} queue_t;

void*
queue_create(void)
{
    queue_t* queue = (queue_t*)malloc(sizeof(queue_t));
    if (queue) {
        queue->head = NULL;
        queue->tail = NULL;
    }
    return ((queue)? queue: NULL);
}

int
queue_enqueue(void* queue, void* data)
{
    int iret = 0;
    queue_t* qtmp = NULL;
    node_t* node = NULL;
    if (!queue || !data) {
        iret = -1;
        goto exit;
    }
    qtmp = (queue_t*)queue;
    node = (node_t*)malloc(sizeof(node_t));
    node->data = data;
    if (qtmp->head == NULL) {
        qtmp->tail = node;
        node->next = NULL;
    } else
        node->next = qtmp->head;
    qtmp->head = node;
exit:
    return iret;
}

int
queue_dequeue(void* queue, void** data)
{
    int iret = 0;
    queue_t* qtmp = NULL;
    node_t* nodetmp = NULL;
    if (!queue) {
        iret = -1;
        goto exit;
    }
    qtmp = (queue_t*)queue;
    nodetmp = qtmp->head;
    if (qtmp->head == NULL)
        *data = NULL;
    else if (qtmp->head == qtmp->tail) {
        qtmp->head = qtmp->tail = NULL;
        *data = nodetmp->data;
        free(nodetmp);
    } else {
        while (nodetmp->next != qtmp->tail)
            nodetmp = nodetmp->next;
        qtmp->tail = nodetmp;
        nodetmp = nodetmp->next;
        qtmp->tail->next = NULL;
        *data = nodetmp->data;
        free(nodetmp);
    }
exit:
    return (*data)? 1: 0;
}

static int
apgnssinfo_dequeue(struct algocfg_apgnssinfo_t **gnssinfo)
{
    queue_dequeue(mgnssque, (void**)gnssinfo);
    if (!*gnssinfo)
        return STATE_UNAVAILABLE;
    printf("GNSS TAKE %lld %lld ",
            (uint64_t)((*gnssinfo)->latitude*1000000),
            (uint64_t)((*gnssinfo)->longitude*1000000));
    return STATE_AVAILABLE;
}

void
main(void)
{
    int loop = 100;
    void* queue = queue_create();
    int *penq = NULL;
    int *pdeq = NULL;
    for(; loop != 0; loop--) {
        penq = (int*)malloc(sizeof(int));
        *penq = loop;
        printf("enqueue: addr(%p):num(%d)\n", penq, *penq);
        queue_enqueue(queue, penq);
    }
    while(queue_dequeue(queue, (void**)&pdeq)) {
        printf("dequeue: addr(%p):num(%d)\n", pdeq, *pdeq);
        free(pdeq);
        pdeq = NULL;
    }
}
```

`An empty queue`
<br>NULL is returned
<br>`A single node queue`
<br>Handled by the else if statement
<br>`A multiple node queue`
<br>Handled by the else clause

In the latter case, the tmp pointer is advanced node by node until it points to the node
immediately preceding the tail node. Three operations are then performed in the fol‐
lowing sequence:
<br>1. The tail is assigned to the tmp node
<br>2. The tmp pointer is advanced to the next node
<br>3. The tail’s next field is set to NULL to indicate there are no more nodes in the queue


<img src="Figure6_8_dequeuefunctionexample.png"
width="70%"
height="70%"
alt="dequeue function example"
align=center />

+ Using Pointers to Support Linked List

```c
typedef struct _node_t {
    void* data;
    struct _node_t* next;
} node_t;

typedef struct _datalist_t {
    node_t* head;
    node_t* tail;
} datalist_t;

typedef int(*fcompare)(void*, void*);
typedef int(*fgothrough)(void*);

void*
datalist_create(void)
{
    datalist_t* list = (datalist_t*)portmemalloc(sizeof(datalist_t));
    if (list) {
        list->head = NULL;
        list->tail = NULL;
    }
    return ((list)? list: NULL);
}

int
datalist_addhead(void* chain, void* data)
{
    int iret = STATE_AVAILABLE;
    node_t* node = NULL;
    datalist_t* list = (datalist_t*)chain;
    if (!list || !data) {
        iret = -1;
        goto exit;
    }
    node = (node_t*)portmemalloc(sizeof(node_t));
    if (!node) {
        iret = -2;
        goto exit;
    }
    node->data = data;
    if (!list->head) {
        list->tail = node;
        node->next = NULL;
    } else
        node->next = list->head;
    list->head = node;
exit:
    if (!IS_AVAILABLE(iret))
        ALOGE("%s,l:%d,err:%d\n", __FUNCTION__, __LINE__, iret);
    return IS_AVAILABLE(iret);
}

int
datalist_addtail(void* chain, void* data)
{
    int iret = STATE_AVAILABLE;
    node_t* node = NULL;
    datalist_t* list = (datalist_t*)chain;
    if (!list || !data) {
        iret = -1;
        goto exit;
    }
    node = (node_t*)portmemalloc(sizeof(node_t));
    if (!node) {
        iret = -2;
        goto exit;
    }
    node->data = data;
    node->next = NULL;
    if (!list->head)
        list->head = node;
    else
        list->tail->next = node;
    list->tail = node;
exit:
    if (!IS_AVAILABLE(iret))
        ALOGE("%s,l:%d,err:%d\n", __FUNCTION__, __LINE__, iret);
    return IS_AVAILABLE(iret);
}

void*
datalist_getnode(void* chain, fcompare callback, void* data)
{
    int iret = STATE_AVAILABLE;
    datalist_t* list = (datalist_t*)chain;;
    node_t* node = NULL;
    if (!list || !callback || !data) {
        iret = -1;
        goto exit;
    }
    node = list->head;
    while (node) {
        if (callback(node->data, data))
            return node;
        node = node->next;
    }
exit:
    if (!IS_AVAILABLE(iret))
        ALOGE("%s,l:%d,err:%d\n", __FUNCTION__, __LINE__, iret);
    return NULL;
}

void*
datalist_getnodedata(void* node)
{
    int iret = STATE_AVAILABLE;
    node_t* pnode = (node_t*)node;;
    if (!pnode) {
        iret = -1;
        goto exit;
    }
    return pnode->data;
exit:
    if (!IS_AVAILABLE(iret))
        ALOGE("%s,l:%d,err:%d\n", __FUNCTION__, __LINE__, iret);
    return NULL;
}

int
datalist_deletenode(void* chain, void* data)
{
    int iret = STATE_AVAILABLE;
    datalist_t* list = (datalist_t*)chain;
    node_t* node = NULL;
    if (!list || !data) {
        iret = -1;
        goto exit;
    }
    node = (node_t*)data;
    if (node == list->head) {
        if (!list->head->next)
            list->head = list->tail = NULL;
        else
            list->head = list->head->next;
    } else {
        node_t* nodetmp = list->head;
        while (nodetmp && nodetmp->next != node)
            nodetmp = nodetmp->next;
        if (nodetmp)
            nodetmp->next = node->next;
    }
    portmemfree(node);
exit:
    if (!IS_AVAILABLE(iret))
        ALOGE("%s,l:%d,err:%d\n", __FUNCTION__, __LINE__, iret);
    return IS_AVAILABLE(iret);
}

int
datalist_gothrough(void* chain, fgothrough callback)
{
    int iret = STATE_AVAILABLE;
    datalist_t* list = (datalist_t*)chain;
    node_t* current = NULL;
    if (!list || !callback) {
        iret = -1;
        goto exit;
    }
    current = list->head;
    while (current) {
        callback(current->data);
        current = current->next;
    }
exit:
    if (!IS_AVAILABLE(iret))
        ALOGE("%s,l:%d,err:%d\n", __FUNCTION__, __LINE__, iret);
    return IS_AVAILABLE(iret);
}

typedef struct _attributenode {
    int tag_num;
    int (*fptr)(void*);
} attributenode_t;

int
test1(void* data)
{
    printf("%s\n", __FUNCTION__);
    return 0;
}

int
test2(void* data)
{
    printf("%s\n", __FUNCTION__);
    return 0;
}

int
test3(void* data)
{
    printf("%s\n", __FUNCTION__);
    return 0;
}

int
gothrough(void* data)
{
    int iret = STATE_AVAILABLE;
    attributenode_t* ptr = NULL;
    if (!data) {
        iret = -1;
        goto exit;
    }
    ptr = (attributenode_t*)data;
    ptr->fptr(NULL);
exit:
    if (!IS_AVAILABLE(iret))
        ALOGE("%s,l:%d,err:%d\n", __FUNCTION__, __LINE__, iret);
    return IS_AVAILABLE(iret);
}

int
compare_attribute(void* e1, void* e2)
{
    int iret = STATE_UNAVAILABLE;
    attributenode_t* ptr1 = NULL;
    attributenode_t* ptr2 = NULL;
    if (!e1 || !e2) {
        iret = -1;
        goto exit;
    }
    ptr1 = (attributenode_t*)e1;
    ptr2 = (attributenode_t*)e2;
    iret = (ptr1->tag_num == ptr2->tag_num)? STATE_AVAILABLE: STATE_UNAVAILABLE;
exit:
    return IS_AVAILABLE(iret);
}

void
main(void)
{
    void* list = datalist_create();
    void* node = NULL;
    attributenode_t* attri_1 = (attributenode_t*)portmemalloc(sizeof(attributenode_t));
    attributenode_t* attri_2 = (attributenode_t*)portmemalloc(sizeof(attributenode_t));
    attributenode_t* attri_3 = (attributenode_t*)portmemalloc(sizeof(attributenode_t));
    char name[24];

    strcpy(name, "1234");
    printf("%s", name);

    attri_1->tag_num = 1;
    attri_1->fptr = &test1;
    datalist_addhead(list, attri_1);

    attri_2->tag_num = 2;
    attri_2->fptr = &test2;
    datalist_addhead(list, attri_2);

    attri_3->tag_num = 3;
    attri_3->fptr = &test3;
    datalist_addhead(list, attri_3);

    ALOGD("gothroug 1\n");
    datalist_gothrough(list, gothrough);

    node = datalist_getnode(list, compare_attribute, attri_2);
    if (node)
        datalist_deletenode(list, node);

    ALOGD("gothroug 2\n");
    datalist_gothrough(list, gothrough);
}
```

<img src="Figure6_5_Linkedlisttypes.png"
width="70%"
height="70%"
alt="Linked list types"
align=center />

<img src="Figure6_6_addHeadexample.png"
width="70%"
height="70%"
alt="Added Head"
align=center />

In the `addHead` function listed below, memory is first allocated for the node and the data
passed to the function is assigned to the structure’s data field. By passing the data as a
pointer to void, the linked list is able to hold any type of data the user wants to use.

Next, we check to see whether the linked list is empty. If so, we assign the tail pointer to
the node and assign NULL to the node’s next field. If not, the node’s next pointer is
assigned to the list’s head. Regardless, the list’s head is assigned to the node

The `addTail` function is shown below. It starts by allocating memory for a new node
and assigning the data to the data field. Since the node will always be added to the tail,
the node’s next field is assigned to NULL. If the linked list is empty, then the head pointer
will be NULL and head can be assigned to the new node. If it is not NULL, then the tail’s
next pointer is assigned to the new node. Regardless, the linked list’s tail pointer is
assigned to the node


<!---
```c
typedef struct _employee {
    char name[32];
    unsigned char age;
} Employee;

typedef struct _node {
    void* data;
    struct _node* next;
} Node;

typedef struct _linkedList {
    Node* head;
    Node* tail;
    Node* current;
} LinkedList;

typedef void(*DISPLAY)(void*);
typedef int(*COMPARE)(void*, void*);

void initializeList(LinkedList*);   //Initializes the linked list
void addHead(LinkedList*, void*);   //Adds data to the linked list’s head
void addTail(LinkedList*, void*);   //Adds data to the linked list’s tail
void delete (LinkedList*, Node*);   //Removes a node from the linked list
Node* getNode(LinkedList*, COMPARE, void*); //Returns a pointer to the node containing a specific data item
void displayLinkedList(LinkedList*, DISPLAY); //Displays the linked list

int
compareEmployee(Employee* e1, Employee* e2)
{
    return strcmp(e1->name, e2->name);
}

void
displayEmployee(Employee* employee)
{
    printf("%s\t%d\n", employee->name, employee->age);
}

void
initializeList(LinkedList* list)
{
    list->head = NULL;
    list->tail = NULL;
    list->current = NULL;
}

void
addHead(LinkedList* list, void* data)
{
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    if (list->head == NULL) {
        list->tail = node;
        node->next = NULL;
    } else
        node->next = list->head;
    list->head = node;
}

void
addTail(LinkedList* list, void* data)
{
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    if (list->head == NULL)
        list->head = node;
    else
        list->tail->next = node;
    list->tail = node;
}

Node*
getNode(LinkedList* list, COMPARE compare, void* data)
{
    Node* node = list->head;
    while (node != NULL) {
        if (compare(node->data, data) == 0)
            return node;
        node = node->next;
    }
    return NULL;
}

void
delete(LinkedList* list, Node* node)
{
    if (node == list->head) {
        if (list->head->next == NULL)
            list->head = list->tail = NULL;
        else
            list->head = list->head->next;
    } else {
        Node* tmp = list->head;
        while (tmp != NULL && tmp->next != node)
            tmp = tmp->next;
        if (tmp != NULL)
            tmp->next = node->next;
    }
    free(node);
}

void
displayLinkedList(LinkedList* list, DISPLAY display)
{
    printf(" \nLinked List\n" );
    Node* current = list->head;
    while (current != NULL) {
        display(current->data);
        current = current->next;
    }
}

void
main(void)
{
    LinkedList linkedList;
    Employee* samuel = (Employee*) malloc(sizeof(Employee));
    strcpy(samuel->name, "Samuel" );
    samuel->age = 32;
    Employee* sally = (Employee*) malloc(sizeof(Employee));
    strcpy(sally->name, "Sally" );
    sally->age = 28;
    Employee* susan = (Employee*) malloc(sizeof(Employee));
    strcpy(susan->name, "Susan" );
    susan->age = 45;
    initializeList(&linkedList);
    addHead(&linkedList, samuel);
    addHead(&linkedList, sally);
    addHead(&linkedList, susan);
    addTail(&linkedList, susan);
    addTail(&linkedList, sally);
    addTail(&linkedList, samuel);
    displayLinkedList(&linkedList, (DISPLAY)displayEmployee);
    /*
        The output of this sequence follows:
        Linked List
        Susan 45
        Sally 28
        Samuel 32
    */
    /*perform comparisons*/
    Node* node = getNode(&linkedList,
            (int (*)(void*, void*))compareEmployee, sally);
    delete (&linkedList, node);
}
```
-->

## Question

+ [Data Structure Using C 1.3.1.a](https://www.geeksforgeeks.org/sum-of-the-series-1-12-123-1234-1234-n/)

```c
for (i = 1; i <= n; i++)
    for(j = i; j <=n; j++)
        for (k = j; k <=n; k++)
            x++;    // x = ?
```
n = 3
i = (1,2,3)
j = ((1,2,3), (2,3), (4))
k = (((1,2,3), (2,3), (3)), ((2,3), (3)), (3))
x = (3+2+1)+(2+1)+1
x=10


