#include <stdio.h>

int tree_array_size = 20;
int heap_size = 0;
const int INF = 100000;

void swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

int get_right_child(int A[], int index)
{
    if ((((2 * index) + 1) < tree_array_size) && (index >= 1))
        return (2 * index) + 1;
    return -1;
}

int get_left_child(int A[], int index)
{
    if (((2 * index) < tree_array_size) && (index >= 1))
        return 2 * index;
    return -1;
}

int get_parent(int A[], int index)
{
    if ((index > 1) && (index < tree_array_size))
    {
        return index / 2;
    }
    return -1;
}

void min_heapify(int A[], int index)
{
    int left_child_index = get_left_child(A, index);
    int right_child_index = get_right_child(A, index);

    int smallest = index;

    if ((left_child_index <= heap_size) && (left_child_index > 0))
    {
        if (A[left_child_index] < A[smallest])
        {
            smallest = left_child_index;
        }
    }

    if ((right_child_index <= heap_size && (right_child_index > 0)))
    {
        if (A[right_child_index] < A[smallest])
        {
            smallest = right_child_index;
        }
    }

    if (smallest != index)
    {
        swap(&A[index], &A[smallest]);
        min_heapify(A, smallest);
    }
}

int minimum(int A[])
{
    return A[1];
}

void decrease_key(int A[], int index, int key)
{
    A[index] = key;
    while ((index > 1) && (A[get_parent(A, index)] > A[index]))
    {
        swap(&A[index], &A[get_parent(A, index)]);
        index = get_parent(A, index);
    }
}

void insert(int A[], int key)
{
    heap_size++;
    A[heap_size] = INF;
    decrease_key(A, heap_size, key);
}

void print_heap(int A[])
{
    int i;
    for (i = 1; i <= heap_size; i++)
    {
        printf("%d  ", A[i]);
    }
    printf("\n");
}

int main()
{
    int A[tree_array_size];
    insert(A, 45);
    insert(A, 24);
    insert(A, 73);
    insert(A, 36);
    insert(A, 65);
    insert(A, 87);
    insert(A, 94);
    insert(A, 18);
    insert(A, 88);

    printf("Min-Heap-: ");

    print_heap(A);
    printf("\n");

    printf("Min-Heap after insertion-: ");

    insert(A, 35);
    insert(A, 77);
    print_heap(A);

    return 0;
}