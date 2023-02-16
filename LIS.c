#include <stdio.h>
#include <string.h>

int max(int *arr)
{
    int i = 0;
    int max = 0;

    while (i <= 3)
    {
        if (arr[i] >= max)
        {
            max = arr[i];
        }
        i++;
    }
    return (max);
}

int main()
{
    int arr[] = {1,2,4,3};
    int lis[] = {1,1,1,1};
    int i;
    int j;
    int is;

    i = 0;
    j = 1;
    while (i <= 3)
    {
        while (j <= 3)
        {
            if (arr[i] < arr[j])
            {
                lis[j] = lis[i] + 1;
            }
            j++;
        }
        i++;
    }
    printf("%d\n",lis[0]);
    printf("%d\n",lis[1]);
    printf("%d\n",lis[2]);
    printf("%d\n",lis[3]);
    is = max(lis);
    // printf("%d\n",is);
    
}