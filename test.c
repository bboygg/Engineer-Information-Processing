#include <stdio.h>



void main()
{
    char arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr);
    int m = sizeof(arr[0]);
    printf("%d ", n);
    printf("%d ", m);
}