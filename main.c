/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:00:39 by waraissi          #+#    #+#             */
/*   Updated: 2023/02/11 21:21:46 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

void    fill_stack(t_vars *vars, char *arg)
{
    int l;

    l = ft_atoi(arg);
    fill_list(vars, l);
}

void    is_duplicated(char **str)
{
    int i;
    int j;

    i = 1;
    while (str[i])
    {
        j = i + 1;
        while (str[j])
        {
            if (!ft_strcmp(str[i], str[j]))
            {
                write(2, "duplicated", 11);
                exit(1);
            }
            j++;
        }
        i++;
    }
}

char    **join_args(t_vars *vars, char **av)
{
    int i;

    i = 0;
    while (av[++i])
    {
        vars->args = ft_strjoin_sep(vars->args, av[i], " ");
    }
    return (ft_split(vars->args, ' '));
}

int main(int ac, char **av)
{
    t_vars  vars;

    if (ac > 2)
    {
        vars.s_args = join_args(&vars, av);
        int i = 0;
        while (vars.s_args[i])
        {
            printf("%s\n", vars.s_args[i]);
            i++;
        }
    }
}
