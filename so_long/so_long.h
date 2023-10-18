/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeong <hjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 10:58:54 by hjeong            #+#    #+#             */
/*   Updated: 2022/07/09 19:28:53 by hjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./mlx/mlx.h"

typedef enum s_enum
{
	A_KEY = 0,
	S_KEY = 1,
	D_KEY = 2,
	W_KEY = 13,
	ESC_KEY = 53,
	KEY_PRESS = 2,
	KEY_EXIT = 17
}	t_enum;

typedef struct s_location
{
	int	x;
	int	y;
}	t_location;

typedef struct s_imgdata
{
	void	*wall;
	void	*rabbit;
	void	*carrot;
	void	*back;
	void	*door;
}	t_imgdata;

typedef struct s_mlxdata
{
	void		*mlx;
	void		*win;
	char		**map;
	int			width;
	int			height;
	int			carrot;
	int			m_count;
	t_imgdata	imgdata;
	t_location	loc;
}	t_mlxdata;

void			error_print(char *str);
t_mlxdata		*data_init(void);
int				exit_game(t_mlxdata *data);

void			map_init(char *argv, t_mlxdata *data);
void			map_check(t_mlxdata *data);
void			wall_check(t_mlxdata *data);
void			cep_check(t_mlxdata *data, int wid, int hei, int c);
char			*ft_strnstr(const char *haystack, const char *needle, \
				size_t len);

void			image_init(t_mlxdata *data);
void			put_image(t_mlxdata *d, int wid, int hei);

int				key_press(int keycode, t_mlxdata *data);
void			x_move_character(int x, t_mlxdata *d);
void			y_move_character(int y, t_mlxdata *d);
void			print_count(t_mlxdata *data);

int				ft_strlen(const char *s);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strdup(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			*ft_memcpy(void *dest, const void *src, size_t n);

char			**ft_split(char const *s, char c);
int				ft_count(char const *s, char c);
int				ft_splitlen(char const *s, char c);
char			**ft_splitfree(char **split, int index);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

void			ft_putchar(char c);
void			ft_putnbr(long n);
int				ft_digit(int n);
void			*ft_memset(void *s, int c, size_t n);
char			*ft_itoa(int n);

#endif