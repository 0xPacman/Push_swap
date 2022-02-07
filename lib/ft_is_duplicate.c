#include "../push_swap.h"

void ft_is_duplicate(char **str)
{
    int i;
    int args;
    int j;

    j = 0;
    i = 0;
    args = 0;
    while(str[args])
    {
        ft_is_valid(str[args]);
        args++;
    }
    while (i < args)
        {
            j = i + 1;
            while (j < args)
                {
                    if(!ft_strcmp(str[i], str[j]))
                        ft_error_handler();
                    j++;
                }
            i++;
        }
}