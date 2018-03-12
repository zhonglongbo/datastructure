#include "Sort.h"

//≤Â»Î≈≈–Ú
void InsertSort(DataType *a,size_t n)
{
    size_t i = 0;
    assert(a);
    for (i=0; i<n-1; ++i)
    {
        int end = i;
        DataType tmp = a[end+1];
        while (end>=0 && a[end] > tmp)
        {
            a[end+1] = a[end];
            end--;
        }

        a[end+1] = tmp;
    }
}

void ShellSort(DataType *a,size_t n)
{
    int gap = n;
    size_t i = 0;
    while (gap>1)
    {
        gap = gap/3 + 1;
        for (i=0; i<n-gap; i++)
        {
            int end = i;
            DataType tmp = a[end+gap];
            while (end >= 0 && a[end] > tmp)
            {
                a[end+gap] = a[end];
                end-= gap;
            }

            a[end+gap] = tmp;
        }
    }
}

//—°‘Ò≈≈–Ú
void static Swap(DataType *a,DataType *b)
{
    DataType c = *a;
    *a = *b;
    *b = c;
}

void SelectSort(DataType *a,size_t n)
{
    size_t left = 0;
    size_t right = n-1;
    assert(a);
    while (left<right)
    {
        DataType min = left;
        DataType max = left;
        size_t i = left;
        for (i=left; i<=right;++i)
        {
            if (a[min] > a[i])
                min = i;
            if (a[max] < a[i])
                max = i;
        }
        Swap(&a[left],&a[min]); 
        if (max == left) //◊Ó¥Û÷µ‘⁄◊Ó◊Û±ﬂ
            max = min;
        Swap(&a[right],&a[max]);
        left++;
        right--;
    }
}

void AdjustDown(DataType *a,size_t n,size_t root)
{
    size_t parent = root;
    size_t child = parent *2+1;
    while (child<n)
    {
        if (a[child]<a[child+1] && child+1 <n)
            child++;
        if(a[parent] < a[child])
            Swap(&a[parent],&a[child]);

        parent = child;
        child = parent*2+1;
    }
}

void HeadSort(DataType *a,size_t n)
{
    size_t i =0;
    size_t end = n-1;
    for (i=(n-2)>>1; i>0; --i)
        AdjustDown(a,n,i);

    while (end)
    {
        Swap(&a[0],&a[end]);
        AdjustDown(a,end,0);
        end--;
    }
}

//Ωªªª≈≈–Ú
void BubbleSort(DataType *a,size_t n)
{
    size_t i,j,flag = 0;
    assert(a);
    for (i=0; i<n-1; i++)
    {
        flag = 0;
        for (j=0; j<n-i-1; j++)
        {
            if (a[j] > a[j+1])
            {
                Swap(&a[j],&a[j+1]);
                flag = -1;
            }
        }
        if (!flag)
            break;
    }
}
void QSort(DataType *a,size_t n);

//πÈ≤¢≈≈–Ú
