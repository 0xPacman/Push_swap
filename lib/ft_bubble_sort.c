#include "../push_swap.h"

void swap(int *x, int *y)
{
    int temp = 0;
    temp = *x;
    *x = *y;
    *y = temp;
}

void ft_bubble_sort(int tab[], int n)
{
   int i;
   int j;
   i = 0;
   while (i < n-1)
    {
        j = 0;
        while (j < n-i-1)
        {
            if (tab[j] > tab[j+1])
                swap(&tab[j], &tab[j+1]);
            j++;
        }
    i++;
    }
}
