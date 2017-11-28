/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 11:07:10 by mjoubert          #+#    #+#             */
/*   Updated: 2017/11/27 22:18:42 by areid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#define BUF_SIZE 21
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft.h"

typedef struct		s_struct
{
	int				x_min;
	int				x_max;
	int				y_min;
	int				y_max;
}					t_struct;

typedef	struct		s_res
{
	char			**res_dom;
	char			letter;
	int				width;
	int				height;
	struct s_res	*next;
	struct s_res	*previous;
}					l_res;		

l_res 				*ft_read(char *av);
void				ft_error();
l_res				*ft_stock(char **res, l_res **alst, char let,t_struct lims);
int					ft_test2(char *str);
size_t				ft_test1(char *str);
char				**ft_tet_red(char **full, t_struct lims, char c);
int					ft_solver(char **board, l_res *alst);
char				**ft_board_calc(int board_size);
void				ft_print_map(char **board);
#endif
