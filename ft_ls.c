/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 14:22:15 by ybarbier          #+#    #+#             */
/*   Updated: 2014/11/15 15:45:37 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls(char *name_dir)
{
	DIR *dir;
	struct dirent *ent;
	// struct stat *buf;

	// stat(name_dir, buf);
	
	
	if ((dir = opendir(name_dir)))
	{
		while ((ent = readdir(dir)))
		{
			// ft_putnbr(ent->d_type);
			// ft_putstr("\n");
			ft_putstr(ent->d_name);
			ft_putstr("\n");
		}
	}
}
