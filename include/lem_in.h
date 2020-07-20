/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:38:15 by mbiliaie          #+#    #+#             */
/*   Updated: 2019/01/29 16:38:20 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define NL write (1, "\n", 1)

# include "../libft/libft.h"

struct					s_tech
{
	char				*hyphen;
	char				*enter_title;
	char				*finish_title;
};

struct					s_edge
{
	struct s_vertex		*enter;
	int					z;
	struct s_edge		*fwd;
	struct s_vertex		*finish;
	struct s_edge		*bwd;
};

struct					s_start
{
	short				show_ways;
	short				show_man;
	char				*ways_flag;
	char				*man_flag;
	char				*use_txt;
	char				*man_txt;
	int					z;
};

struct					s_print
{
	char				*title;
	char				*l;
	char				*r;
	char				*edge;
	char				sp;
	char				lb;
	char				h;
	void				*n;
	short int			x;
	short int			result;
};

struct					s_gen
{
	long				runners_enter;
	long				runners_no;
	int					i;
	struct s_vertex		*vertices;
	struct s_vertex		*enter;
	struct s_edge		*edges;
	long				depth_scale;
	struct s_way		*ways;
	struct s_place		*all_places;
	long				runners_finish;
	struct s_move		*moves;
	struct s_vertex		*finish;
	char				z;
};

struct					s_step
{
	long int			short_way;
	long int			now_way;
	long int			lim;
	long int			z;
	void				*n;
};

typedef enum
{
	IMD,
	ENTER,
	FINISH,
	WRONG
}	t_cat;

struct					s_txt
{
	long				index;
	struct s_txt		*fwd;
	char				*obj;
};

struct					s_vertex
{
	char				i;
	struct s_vertex		*fwd;
	char				*title;
	long long			cx;
	long				exit_edges;
	long long			cy;
	long				depth_scale;
	long				entry_edges;
	t_cat				status;
	long				runners_no;
};

struct					s_way
{
	long				distance;
	struct s_edge		*top;
	struct s_way		*fwd;
	int					x;
};

struct					s_place
{
	struct s_vertex		*vrt;
	long				runners_no;
	struct s_place		*fwd;
	int					x;
	char				a;
};

struct					s_move
{
	struct s_move		*fwd;
	short int			a;
	struct s_place		*all_places;
};

struct					s_layout
{
	struct s_vertex		*vrt;
	long int			i;
	struct s_layout		*fwd;
	char				z;
};

short int				display_error(char *s);
int						way_to_exit_separation(struct s_gen *gen,
	struct s_edge *e);
short					clear_vertices(struct s_vertex **now);
short					general_mem_clear(struct s_gen **gen);
struct s_gen			*set_start_values(struct s_gen *gen);
t_cat					make_new_vertex(struct s_gen *gen, char *object,
						t_cat status);
long long int			ati_ext(char *f);
struct s_way			*create_path(short x);
size_t					load_edge(struct s_gen *gen, struct s_edge *e);
short int				make_ways(struct s_gen *gen);
struct s_way			*prepare_way(short x);
int						main_scale_algo(struct s_gen *gen);
short					layout_load_connected_items(struct s_gen *gen,
						struct s_layout **layout, struct s_vertex *vrt);
int						layout_load_item(struct s_layout **lt,
						struct s_layout *item);
struct s_layout			*layout_give_top(struct s_layout **lt);
struct s_edge			*make_edge(struct s_gen *g, char *s, void *n, short x);
struct s_vertex			*make_vertex(char *a, t_cat status);
char					*get_errors_text(char *str);
struct s_txt			*process_gnl_input(struct s_txt **txt);
int						load_str(struct s_txt **txt, struct s_txt *string);
struct s_gen			*general_upload(struct s_txt **txt, short int vs);
short int				upload_farm(struct s_gen *gen,
						struct s_txt **point_now, struct s_txt **txt);
struct s_edge			*set_edge_start_values(struct s_vertex *enter,
						struct s_vertex *finish);
size_t					upload_edges(struct s_gen *gen, struct s_txt **current,
						struct s_txt **txt, short int vs);
struct s_way			*add_path(struct s_gen *gen, struct s_way *w,
						struct s_way *now);
int						mem_clear(char ***mem_area);
int						check_correct_edge(struct s_gen *g, struct s_edge *e);
short					instruction_check(char *a);
short int				note_check(char *a);
short int				upload_vertices(struct s_gen *gen,
						struct s_txt **point_now, struct s_txt **txt);
short int				vertice_check(char *a);
short					vertice_title_check(char *a);
int						scale_edges(struct s_gen *gen);
int						calculate_all_edges(struct s_gen *gen);
struct s_vertex			*look_for_vertex(struct s_gen *gen, char *title);
short int				clear_text(struct s_txt **txt);
struct s_edge			*look_for_edge(struct s_gen *gen,
						struct s_vertex *enter, struct s_vertex *finish);
short int				erase_blind_alleys(struct s_gen *gen);
int						erase_edge(struct s_gen *gen, struct s_edge *e,
						struct s_edge *now);
struct s_edge			*suspend_edge(struct s_gen *gen, struct s_edge *e);
int						erase_entry_separations(struct s_gen *gen);
short int				erase_one_entry_separation(struct s_gen *gen,
						struct s_vertex *vrt);
short					erase_entry_edges(struct s_gen *gen, struct s_edge *e);
long int				erase_exit_separations(struct s_gen *gen);
short					erase_one_exit_separation(struct s_gen *gen,
						struct s_vertex *vrt);
short int				make_ways(struct s_gen *gen);
short int				erase_blind_alleys(struct s_gen *gen);
size_t					way_load_edge(struct s_way *w, struct s_edge *e);
struct s_txt			*prepare_str(char *object, size_t l);
struct s_place			*move_make_place(int ant_number, struct s_vertex *room);
short int				move_load_place(struct s_gen *gen, struct s_place *pl);
int						clear_ways(struct s_way **current);
struct s_place			*move_ant_from_start(struct s_gen *gen,
						struct s_way *way, int x);
short					clear_places(struct s_place **now);
short int				clear_edges(struct s_edge **now);
int						do_moves(struct s_gen *gen);
long					runners_make_entering_run(struct s_gen *gen);
int						make_ways_run(struct s_gen *gen);
short					make_one_way_run(struct s_gen *gen,
						struct s_way *path, int bz);
long					count_shift(struct s_gen *gen, struct s_way *path);
short int				display_all_places(struct s_gen *gen);
short					check_args (struct s_start a, int num_arg, char **str);
long int				way_distance(struct s_gen *g, struct s_edge *e, int d);
short int				clear_moves(struct s_move **now);
int						erase_exit_edges(struct s_gen *gen, struct s_edge *e);
short int				check_whole_number(char *str);
short					launch_algo(struct s_txt *strings,
						struct s_gen *gen, short show_ways);
int						erase_edge(struct s_gen *gen, struct s_edge *e,
						struct s_edge *now);
short					display_strings(struct s_txt *txt);
int						general_dispatch(struct s_txt *txt, short show_ways,
						struct s_gen *gen);
struct s_layout			*layout_make_item(struct s_vertex *vrt);
int						check_correct_vertex(struct s_gen *gen,
						struct s_vertex *vertex);
t_cat					give_status(char *str);
int						display_ways(struct s_gen *gen);
long					word_count(char *str, char c);
long					letter_count(char *str, char c);
#endif
