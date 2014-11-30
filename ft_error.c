/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 17:23:42 by ybarbier          #+#    #+#             */
/*   Updated: 2014/11/30 17:23:43 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*Exit if error Malloc*/
void ft_exit(void)
{
    exit(1);
}

void ft_error(char *str_error)
{
    ft_putstr(TITLE);
    ft_putstr(": ");
    perror(str_error);
}

void ft_error_exit(char *str_error)
{
    ft_error(str_error);
    exit(1);
}

void ft_error_flags(char flag)
{
    ft_putstr(TITLE);
    ft_putstr(": ");
    ft_putstr(" illegal option -- ");
    ft_putchar(flag);
    ft_putchar('\n');
    ft_putstr("usage: ");
    ft_putstr(TITLE);
    ft_putendl(" [-lRart] [file ...]");
    exit(1);
}
