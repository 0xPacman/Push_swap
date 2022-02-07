#include "../push_swap.h"

void ft_is_valid(char *str)
{
    int i;
    i = 0;
    while(str[i])
    {
        if(((str[i] == '-' || str[i] == '+')&& ft_isdigit(str[i+1])))
            i++;
        if(!ft_isdigit(str[i]))
            ft_error_handler();
        i++;
    }
}