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

    i = 0;
    while (i < 7)
    {
        if (i + 1 == 7)
            j = 0;
        else
            j = i + 1;
        int tmp = arr[i];
        while (j <= 7 && arr[i] != arr[j])
        {
            if (tmp < arr[j])
            {
                lis[i] = lis[i] + 1;
                tmp = arr[j];
            }
            j++;
            if (j == 7)
                j = 0;
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


int lar_elem(int *arr)
{
    int i = 1;
    int max = arr[0];
    while (i < 7)
    {
        if (arr[i + 1] > arr[i] && max < arr[i + 1])
            max = arr[i + 1];
        i++;
    }
    return (max);
}

int lar_pos(int *arr)
{
    int i = 0;
    int max = lar_elem(arr);
    while (i < 7)
    {
        if (arr[i] == max)
            break;
        i++;
    }
    return (i);
}

void fill_res(int *arr, int *lis, int *res, int *pos)
{
    int max_pos = lar_pos(lis);
    int i = 1;
    res[0] = arr[max_pos];
    int tmp = arr[max_pos];
    while (i < 4)
    {
        int j = 0;
        while (j < 7)
        {
            if (arr[j] > tmp)
            {
                tmp = arr[j];
                break;
            }
            j++;
        }
        res[i] = tmp;
        i++;
    }
}

int main()
{
    int arr[] = {5,3,11,8,1,100,2};
    int lis[] = {1,1,1,1,1,1,1};
    int pos[] = {-1,-1,-1,-1,-1,-1,-1};
    int *res;
    int i;

    res = malloc(sizeof(int) * 4);
    if (!res)
        return (0);
    find_lis(arr, lis, pos);
    fill_res(arr,lis,res,pos);
    i = 0;
    while (i < 4)
    {
        // printf("index:%d ==> %d\n",i,lis[i]);
        printf("%d\n",res[i]);
        i++;
    }
    return (0);
}