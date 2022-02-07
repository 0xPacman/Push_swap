#include "../push_swap.h"

char *ft_addstr(char **str)
{
    char *args;
    int i;
    i = 1;
    args = 0;
    while (str[i])
        {
            if (!args)
                {
                    args = ft_strdup(str[i]);
                    i++;
                }
            else
                {
                    args = ft_strjoin(args, " ");
                    args = ft_strjoin(args, str[i]);
                    i++;
                }
        }
         return (args);
}