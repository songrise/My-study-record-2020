#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

void Msort(ElementType A[], ElementType TempArr[], int left, int right);
void MergeSort(ElementType A[], int N);
void Merge(ElementType A[], ElementType TmpArr[], int Lpos, int Rpos, int RightEnd);

void showArr(int *arr, int len)
{
    printf("[");
    for (size_t i = 0; i < len; i++)
    {
        printf("%d", arr[i]);
        if (i != len - 1)
            printf(", ");
    }
    printf("]\n");
}

int main(int argc, char const *argv[])
{
    int array[] = {1, 8, 3, 2, 6, 5, 4, 9, 7};
    showArr(array, 9);
    MergeSort(array, 9);
    showArr(array, 9);

    return 0;
}

void Msort(ElementType A[], ElementType TempArr[], int left, int right)
{
    int center;

    if (left < right)
    {
        center = (left + right) / 2;
        Msort(A, TempArr, left, center);
        Msort(A, TempArr, center + 1, right);
        Merge(A, TempArr, left, center + 1, right);
    }
}

void MergeSort(ElementType A[], int N)
{
    //driver function of Msort.
    ElementType *TmpArray;
    TmpArray = malloc(N * sizeof(ElementType));
    if (TmpArray != NULL)
    {
        Msort(A, TmpArray, 0, N - 1);
        free(TmpArray);
    }
    else
    {
        printf("Out of Space!!");
        exit(-1);
    }
}

void Merge(ElementType A[], ElementType TmpArr[], int Lpos, int Rpos, int RightEnd)
{
    int i, LeftEnd, NumElements, TempPos;

    LeftEnd = Rpos - 1;
    TempPos = Lpos;
    NumElements = RightEnd - Lpos + 1;
    //main loop

    while (Lpos <= LeftEnd && Rpos <= RightEnd)
    {
        if (A[Lpos] <= A[Rpos])
        {
            TmpArr[TempPos++] = A[Lpos++];
        }
        else
        {
            TmpArr[TempPos++] = A[Rpos++];
        }
    }
    //left or right reaches end, add remaining element of another array

    while (Lpos <= LeftEnd)
    {
        TmpArr[TempPos++] = A[Lpos++];
    }
    while (Rpos <= RightEnd)
    {
        TmpArr[TempPos++] = A[Rpos++];
    }

    //copy temppArr back
    for (size_t i = 0; i < NumElements; i++, RightEnd--)
    {
        A[RightEnd] = TmpArr[RightEnd];
    }
}
