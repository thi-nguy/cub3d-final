/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 11:46:50 by thi-nguy          #+#    #+#             */
/*   Updated: 2020/09/22 11:30:27 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>

#include "../libft/libft.h"
//----------- Open this on when compiling on Linux-----------
// #include "../minilibx-linux/mlx.h"
// #include "../minilibx-linux/mlx_int.h"
//-----------------------------------------------------------

#include "constant.h"
#include "struct.h"

void    check_argument(int ac, char** av, int* save);
void    get_fd(char* arg, t_info* info);
int     parse(t_info* info);
int read_line_into_linked_list(t_list** head_llist, int fd);
int   free_memory(t_info* info, int return_code);

int parse_info(t_info* info);
int parse_resolution(t_list** lst);
t_list*  get_node(t_list** llist, char* item);
t_list* ft_lstfind(t_list*lst, char* item, int f(const char *, char *));
int lst_find_item(const char *content, char* x);
void   free_array(char** array);


#endif
