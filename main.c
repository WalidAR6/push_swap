#include "inc/push_swap.h"

int main()
{
    
    t_list *p;
    t_list  *new;
    t_list  *head;
    
    p = ft_lstnew(2);
    new = ft_lstnew(3);
    ft_lstadd_back(&p, new);
    head = p;
    while (head)
    {
        printf("%d\n",head->content);
        head = head->next;
    }
    head = p;
    while (head)
    {
        printf("%d\n",head->content);
        head = head->next;
    }
}