/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:00:39 by waraissi          #+#    #+#             */
/*   Updated: 2023/03/06 21:17:32 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int main(int ac, char **av)
{
    t_vars  vars;

    if (ac > 1)
    {
        vars.s_args = join_args(&vars, av);
        validate_args(&vars);
        fill_stack(&vars);
        if (ft_lstsize(vars.stack_a) == 1)
            return (0);
        dup_num(&vars);
        ft_sorting(&vars);
        // printf("-----------stack_a-------------\n");
        // while (vars.stack_a)
        // {
        //     printf("%d\n",vars.stack_a->content);
        //     printf("index --> %d\n",vars.stack_a->index);
        //     vars.stack_a = vars.stack_a->next;
        // }
        // printf("-----------stack_b-------------\n");
        // while (vars.stack_b)
        // {
        //     printf("%d\n",vars.stack_b->content);
        //     printf("index --> %d\n",vars.stack_b->index);
        //     printf("num of moves --> %d\n",vars.stack_b->num_moves);
        //     vars.stack_b = vars.stack_b->next;
        // }
    }
}
