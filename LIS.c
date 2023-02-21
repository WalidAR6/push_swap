#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int max(int x, int y)
{
    if (x > y)
        return x;
    else if (x < y)
        return y;
    else if (x == y)
        return (x);
    return (0);
}

void find_lis(int *arr, int *lis, int *pos)
{
    int i;
    int j;

    i = 1;
    while (i < 11)
    {
        j = 0;
        while (j < i)
        {
            if (arr[j] < arr[i])
            {
                if (lis[j] + 1 > lis[i])
                {
                    lis[i] = lis[j] + 1;
                    pos[i] = j;
                }
            }
            j++;
        }
        i++;
    }
}

int get_lis(int *arr)
{
    int i = 0;
    int max = arr[i];

    while (i < 11)
    {
        if (arr[i] < arr[i + 1] && arr[i + 1] > max)
            max = arr[i + 1];
        i++;
    }
    return (max);
}

int get_li_pos(int *arr)
{
    int i;

    i = 0;
    while (i < 11)
    {
        if (arr[i] == get_lis(arr))
            break;
        i++;
    }
    return (i);
}

int get_next_pos(int *arr, int num)
{
    int i;

    i = 0;
    while (i < 11)
    {
        if (arr[i] == num)
            break;
        i++;
    }
    return (i);
}

void fill_res(int *arr, int *lis, int *res, int *pos)
{
    int li;
    int i;
    int l_po;
    int p;

    i = 1;
    li = get_li_pos(arr);
    res[0] = arr[li];
    l_po = pos[li];
    while (i < 6)
    {
        res[i] = arr[l_po];
        p = get_next_pos(arr, arr[l_po]);
        l_po = pos[p];
        i++;
    }
}

int main()
{
    int arr[] = {0,4,12,2,10,6,9,13,11,7,15};
    int lis[] = {1,1,1,1,1,1,1,1,1,1,1};
    int pos[] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    int *res;
    int i;

    res = malloc(sizeof(int) * 6);
    if (!res)
        return (0);
    find_lis(arr, lis, pos);
    fill_res(arr,lis,res,pos);
    i = 0;
    while (i < 6)
    {
        // printf("index:%d ==> %d and pos is %d\n",i,lis[i],pos[i]);
        printf("%d\n",res[i]);
        i++;
    }
    return (0);
}