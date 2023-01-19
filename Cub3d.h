/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjaimi <aanjaimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:36:02 by hlalouli          #+#    #+#             */
/*   Updated: 2023/01/19 03:54:10 by aanjaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "./get_next_line/get_next_line.h"

# define IMG_SIZE 10
# define SIZE_MINI 10
# define WIDTH 1920
# define HEIGHT 1080
# define STR_WIDTH 1

enum	e_wall
{
	EA,
	NO,
	WE,
	SO
};

typedef struct s_rays
{
	double	x;
	double	y;
	double	dis;
	int		ver;
	double	cor;
	double	ang;
	int		up;
	int		down;
	int		right;
	int		left;
}	t_rays;

typedef struct s_3d
{
	double	dist_pro;
	double	cor_dis;
	int		wall_strip_h;
	double	project_wall_h;
	double	wall_tp_p;
	double	wall_bot_p;
}	t_3d;

typedef struct s_ray
{
	double	xstep_hor;
	double	ystep_hor;
	double	xstep_ver;
	double	ystep_ver;
	double	xinter_hor;
	double	yinter_hor;
	double	xinter_ver;
	double	yinter_ver;
	double	next_hor_touch_x;
	double	next_hor_touch_y;
	double	next_ver_touch_x;
	double	next_ver_touch_y;
	int		is_down;
	int		is_up;
	int		is_right;
	int		is_left;
	int		i;
	int		j;
}t_ray;

typedef struct s_dda
{
	double		x;
	double		y;
	double		dx;
	double		dy;
	double		inc_x;
	double		inc_y;
	double		steps;
}t_dda;

typedef struct s_player
{
	double	x1;
	double	y1;
	double	x2;
	double	y2;
	double	turn_dir;
	double	walk_dir;
	double	side_dir;
	double	rotation_angle;
	double	ray_angle;
	double	walk_speed;
	double	turn_speed;
	int		color;
}t_player;

typedef struct s_map
{
	int		n;
	int		s;
	int		e;
	int		w;
	int		no;
	int		so;
	int		we;
	int		ea;
	int		c;
	int		f;
}				t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_var
{
	int		i;
	int		j;
	int		k;
	int		fd;
	char	*line;
	int		somme;
	int		a;
	char	**d;
	int		win_height;
	int		win_width;
	int		win_height_mini;
	int		win_width_mini;
	void	*mlx;
	void	*win;
	t_img	img_mini;	
	t_img	img_map;
}	t_var;

typedef struct s_text
{
	int		bpp;
	int		ln;
	int		en;
	char	*dst;
	int		path_img_width;
	int		path_img_heigth;
}	t_text;

typedef struct s_data
{
	double			fov_angle;
	int				steps_count;
	int				p_i;
	int				p_j;
	double			x;
	double			y;
	int				num_rays;
	int				ray_color;
	int				square_color;
	double			hor_dis;
	double			ver_dis;
	double			dis;
	int				scal;
	unsigned int	ceil_color;
	unsigned int	floor_color;
	unsigned int	wall_color;
	double			max_dis;
	double			first_pos;
	t_text			texture_img[4];
	void			*img;
	t_rays			*rays;
	t_map			map;
	t_var			var;
	t_player		ply;
	t_ray			ray;
	t_3d			prj;
	long long		mouse;

}				t_data;

int		check_extension(char *name_map);
void	init1(t_data *data);
void	init2(t_data *data);
void	initialisation(t_data *data);
int		somme_players(t_data *data);
void	*ft_calloc(size_t count, size_t size);
char	**ft_split(char *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_count(char *s, char c);
void	check_path(char *name, char	*line, t_data *data, int flag);
void	error_msg(char *str);
long	check_non_num(char *str);
void	check_line(char *line, t_data *data);
char	*ft_strchr(const char *s, int c);
void	check_color(char *line, char *line1, t_data *data, int flag);
char	**check_doc(char *name_path, t_data *data);
char	**alloc_map(int a, int somme, t_var var, char	*name_map);
void	line_num(char *line);
char	*free_and_null(char	*line, int fd);
int		open_fd(char	*name);
void	check_which_one(char *s, t_data *data);
void	check_numb(t_data *data);
int		is_valid_format(char	**tab);
int		check_player(t_data *data, char	**tab);
void	check_map(t_data *data, char	**tab);
void	ft_free(char **tab);
void	protected(char *file);
int		is_valid_formats(char	**tab);
int		is_valid_formate(char	**tab);
int		is_valid_formatn(char	**tab);
int		is_valid_formatw(char	**tab);
void	protected_array(char **file);
int		init_window(t_data *data);
int		ft_count_height(char	**str);
void	find_p(t_data *data);
int		check_next_tile(t_data *data, char direction, char tile);
void	move_player(t_data *data, char direction);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	my_mlx_pixel_put_map(t_data *data, int x, int y, int color);
int		handle_keypress(int keysym, t_data *data);
void	ft_reset(t_data *data, char direction);
int		handle_keyrelease(int keysym, t_data *data);
int		handle_btnrealease(int keycode, t_var *var);
void	ft_put(t_data *data, int x, int y, int color);
void	ft_put_mini(t_data *data, int x, int y, int color);
void	draw_circle(t_data *data, int x, int y, int r);
int		render_map(t_data *data);
void	render_player(t_data *data, int r);
int		render(t_data *data);
void	loop_mlx(t_data *data);
int		wall(char *wall);
void	dda(t_data *data, double x, double y);
void	draw_case(t_data *data, int color);
void	square(t_data *data, int x, int y, int color);
double	next_x_pos(t_data *data);
double	next_y_pos(t_data *data);
double	next_x_pos_side(t_data *data);
double	next_y_pos_side(t_data *data);
void	check_wall_ray(t_data *data, double x, double y, double angle);
void	set_rotation(t_data *data, char c);
double	mod(double x, double y);
double	calcule_dis(double x1, double y1, double x2, double y2);
void	calcule_distances(t_data *data);
void	check_hor_int(t_data *data, double x, double y, double ray_angle);
void	check_ver_int(t_data *data, double x, double y, double ray_angle);
void	boucle_for_wall_hor(t_data *data);
void	boucle_for_wall_ver(t_data *data);
void	check_dir_ray(t_data *data, double ray_angle);
void	render_wall_3d(t_data *data);
void	render_rays(t_data *data);
void	clear_color_buffer(t_data *data, int color);
int		create_trgb(int t, int r, int g, int b);
void	img_no(t_data *data, int i, int j, int x);
void	img_so(t_data *data, int i, int j, int x);
void	img_we(t_data *data, int i, int j, int x);
void	img_ea(t_data *data, int i, int j, int x);
int		calc_x(t_data *data, int i, int dir);
int		handle_mouse(int x, int y, t_data *data);
void	unit_mlx_p(t_data *data);

#endif
