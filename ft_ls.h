/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 14:22:24 by ybarbier          #+#    #+#             */
/*   Updated: 2014/11/17 20:07:41 by ybarbier         ###   ########.fr       */
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

typedef struct 			s_list_ls
{
	// void			*content;
	// size_t 			content_size;
	struct stat			stat;
	t_uint				is_dir;
	struct s_list_ls	*prev;
	struct s_list_ls	*next;
}						t_list_ls;

typedef struct s_flags
{
	t_uint		flag_l;
	t_uint		flag_R;
	t_uint		flag_a;
	t_uint		flag_r;
	t_uint		flag_t;
	t_uint		flag_error;
}				t_flags;

typedef struct		s_arg
{
	// t_list_ls		*files;
	// t_list_ls		*dirs;
	t_list_ls		*ls_arg;
	t_flags			*flags;
}					t_arg;

void		ft_ls(char *name_dir);
void		set_flags(t_flags *flags);
t_flags		*arg_parse(int argc, const char **argv, t_flags *flags);
t_list_ls	*ft_lst_d_new(void);
t_list_ls	*ft_lst_new(void);
void	ft_lst_add(t_list_ls **alst, t_list_ls *new);

#endif