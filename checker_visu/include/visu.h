/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:17:52 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/13 16:52:51 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

	// int		bpp; /* bits per pixel */

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rect;

// typedef struct s_list
// {
// 	struct s_list	*next;
// 	struct s_list	*prev;
// 	int				value;
// }	t_list;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_list	*lst;
	int		value_max;
	int		size_lst;
}	t_data;

// // |================|
// // |===== LIST =====|
// // |================|

// int		ft_lstsize(t_list *lst);

// void	ft_lstclear(t_list **lst);
// void	ft_lstadd_back(t_list **lst, t_list *new);

// t_list	*ft_lstlast(t_list *lst);
// t_list	*ft_lstnew(int value);

// |==================|
// |===== RENDER =====|
// |==================|

int		render(t_data *data);

// |===================|
// |===== HANDLER =====|
// |===================|

int		handle_keypress(int keysym, t_data *data);

// |======================|
// |===== VISU_UTILS =====|
// |======================|

int		ft_find_value_max(t_list *lst, int *size);

// |========================|
// |===== RENDER_UTILS =====|
// |========================|

void	render_background(t_img *img, int color);
int		render_rect(t_img *img, t_rect rect);
int		ft_size_width(int n, int max);

int		visu(t_list **pile_a, t_list **pile_b, t_instruction **lst_instruction);

void	img_pix_put(t_img *img, int x, int y, int color);

#endif
