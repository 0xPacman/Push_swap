#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list {
    int nb;
    int index;
    struct s_list *next;
    int flag;
  //  struct s_list *prev;
} t_list;

typedef struct s_data {
    int min;
    int max;
    int mid;
    int flag;
    int count;
    char *str;
    char **arg;
    int *sorted;
} t_data;

char    *ft_addstr(char **str);
size_t  ft_strlen(const char *s);
char    *ft_strjoin(char const *s1, char const *s2);
char    **ft_split(char const *s, char c, t_data *data);
void    *ft_memset(void *s, int c, size_t n);
int     ft_isspace(int c);
int     ft_isdigit(int c);
void    *ft_calloc(size_t count, size_t size);
void    ft_bzero(void   *s, size_t n);
int     ft_atoi(const char *str);
char    *ft_strncpy(char *dst, const char *src, size_t n);
char    *ft_strndup(const char *s, size_t n);
int     ft_strcmp(const char *s1, const char *s2);
char    *ft_strdup(const char *s1);
void    ft_error_handler(void);
int	    ft_lstsize(t_list **lst);
t_list	*ft_lstnew(int nb);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstlast(t_list *lst);
void	  ft_lstiter(t_list *lst, void (*f)(void *));
void	  ft_lstdelone(t_list *lst, void (*del)(void *));
void	  ft_lstclear(t_list **lst, void (*del)(void *));
void	  ft_lstadd_front(t_list **lst, t_list *newlst);
void	  ft_lstadd_back(t_list **lst, t_list *newlst);
void    ft_get_index(t_list *stack, int *sorted, int n);
t_list  *ft_find_min(t_list **stack);
t_list  *ft_find_max(t_list **stack);
int     ft_find_in_stack(t_list **stack, t_list *to_find);
int     ft_check_stack(t_list **stack, int n);
void    ft_sort(t_list **stack, t_list **stack_b, int n);
void    sa(t_list **stack);
void    sb(t_list **stack);
void    ss(t_list **stack_a, t_list **stack_b);
void    ra(t_list **stack);
void    rb(t_list **stack);
void    rr(t_list **stack_a, t_list **stack_b);
void    rra(t_list **stack);
void    rrb(t_list **stack);
void    pa(t_list **stack_a, t_list **stack_b);
void    pb(t_list **stack_a, t_list **stack_b);
void    ft_sort_2(t_list **stack);
void    ft_sort_3(t_list **stack);
void    ft_sort_4(t_list **stack_a, t_list **stack_b);
void    ft_sort_5(t_list **stack_a, t_list **stack_b);
void    ft_sort_all(t_list **stack_a, t_list **stack_b, int n);


#endif
