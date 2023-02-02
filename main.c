#include "inc/push_swap.h"

int main()
{
    t_vars p;
    t_vars new;
    // t_list  *head;
    
    p.list = ft_lstnew(2);
    new.list = ft_lstnew(3);
    ft_lstadd_back(&p.list, new.list);
    while (p.list)
    {
        printf("%d\n", p.list->content);
        p.list = p.list->next;
    }
    // head = p;
    // while (head)
    // {
    //     printf("%d\n",head->content);
    //     head = head->next;
    // }
    // head = p;
    // while (head)
    // {
    //     printf("%d\n",head->content);
    //     head = head->next;
    // }
}