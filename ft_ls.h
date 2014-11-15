/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 14:22:24 by ybarbier          #+#    #+#             */
/*   Updated: 2014/11/15 21:35:26 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <sys/types.h>
# include <uuid/uuid.h>
# include <sys/xattr.h>
# include <time.h>
# include <stdio.h>
# include <string.h>
# include "./libft/includes/libft.h"

typedef unsigned int t_uint;

typedef struct	s_argv
{
	char		**flags;
	char		**files;
	char		**directories;
}				t_argv;

typedef struct s_flags
{
	t_uint		flag_l;
	t_uint		flag_R;
	t_uint		flag_a;
	t_uint		flag_r;
	t_uint		flag_t;
}				t_flags;

void	ft_ls(char *name_dir);
void	set_flags(t_flags *flags);
t_flags	*argv_parse(int argc, const char **argv, t_flags *flags);

#endif