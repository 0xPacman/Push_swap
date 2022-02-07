#include "../push_swap.h"
int ft_is_sign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}
void ft_is_valid(char *str)
{
    int i;
    i = 0;
    while(str[i])
    {
        if((ft_is_sign(str[i]) && ft_isdigit(str[i + 1]) && !ft_is_sign(str[i + 2])))
            i++;
        if(!ft_isdigit(str[i]))
            ft_error_handler();
        i++;
    }
}