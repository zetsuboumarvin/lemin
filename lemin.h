/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 20:00:10 by clianne           #+#    #+#             */
/*   Updated: 2020/01/08 12:14:38 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# define LEMIN_USAGE "usage: lem_in < [map_file_name]\n"
# define LEMIN_ERROR "ERROR\n"
# define LM_MAX 4000000

# include "printf/ft_printf.h"
# include <stdlib.h>
# include <fcntl.h>

/*
** room: 0 - start, 1 - end
*/

struct s_rconn;

typedef struct		s_room
{
	char			*room_name;
	int				x;
	int				y;
	int				room_type;
	struct s_rconn	*lnks;
	struct s_room	*split_room;
	int				split;
	int				ant;
	int				ant_num;
	struct s_room	*anc;
	int				weight;
	int				inp_weight;
	int				out_weight;
	int				visited;
	struct s_room	*inp_anc;
	struct s_room	*out_anc;
	struct s_room	*prev;
	struct s_room	*next;
}					t_room;

/*
** room links & a deck for Dijkstra algo
*/

typedef struct		s_rconn
{
	t_room			*room;
	int				weight;
	t_room			*dest;
	struct s_rconn	*prev;
	struct s_rconn	*next;
}					t_rconn;

/*
** the list of paths
*/

typedef struct		s_path
{
	t_rconn			*lnks;
	size_t			is_intersect;
	int				length;
	int				med;
	struct s_path	*prev;
	struct s_path	*next;
}					t_path;

/*
** the deck for Dijkstra algo
*/

typedef struct		s_rdeck
{
	t_room			*room;
	struct s_rdeck	*next;
}					t_rdeck;

size_t				ft_isint(char *s);
void				str_print_and_del(char **s);

int					map_read(t_room **map);
void				map_free(t_room **map);
void				map_del(t_room **map);
t_room				*map_push_back(t_room **head, char **els, int room_type);
t_room				*map_create_elem(char **els, int room_type);
int					map_validation(t_room *head);

size_t				conn_add(t_room *rooms[2]);
t_rconn				*conn_create_elem(t_room *room, int weight);
void				conn_push_back(t_rconn **head, t_room *rconn, int weight);
void				conn_push_front(t_rconn **head, t_room *rconn, int weight);
void				conn_lst_del(t_rconn **rconn);
void				conn_del_front(t_rconn **head);
void				conn_del_room_from_lnks(t_room *l_room, t_room *room);
void				conn_do_del25lines(t_rconn *before, t_rconn *next,
	t_room *node);

size_t				room_create(t_room **map, char *line, int *room_type);
t_room				*room_find_by_name(t_room *map, char *room_name);
t_room				*room_find_by_room(t_rconn *head, t_room *node);
size_t				room_check_xy(char **els);
t_room				*room_split(t_room *map, t_rconn *conn_to_split);
t_rconn				*room_is_splitted(t_room *top);
void				ins_in_lnks(t_room *l_room, t_room *room, int weight);

size_t				tube_create(t_room **map, char *line);

t_room				*find_node(t_room **map, int type);
void				ant_run(t_room *start, t_room *end);
void				ant_save(t_room *head, int q_ant);
int					count_length_rooms(t_room **map);
t_rconn				*find_backward(t_room *top);
t_rconn				*bford(t_room **map);
int					reverse_suur(t_rconn *start, t_room **map);
int					check_effect(t_path **sol, t_room **map, int print);
int					check_end_anc(t_room *top);

t_path				*path_create_elem(t_rconn *rconn);
void				path_push_back(t_path **head, t_rconn *rconn);
void				path_lst_del(t_path **head_path, size_t is_rconn_del);
t_path				*path_get_last_elem(t_path *head);
t_path				*path_copy(t_path **src);
void				path_drop(t_path **head_path, t_path *to_del);
void				path_oper_intersection(t_path **path_head, t_rconn *result);
size_t				path_check_intersection(t_rconn *path_1, t_rconn *path_2);
void				path_sort_by_length(t_path **path);
void				path_calc_med(t_path *path);
void				path_length_count(t_path *path);
void				path_lst_print(t_path *sol, size_t options);
void				path_print(t_rconn *lnks, size_t options, size_t idx,
	int len);

void				do_alg_quick_sort(t_path *left, t_path *right);
t_rconn				*do_alg_dijkstra(t_room **map);

#endif
