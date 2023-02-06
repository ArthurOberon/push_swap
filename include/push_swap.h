/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:56:32 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/06 09:44:55 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define OPTIMIZE_R 90
# define OPTIMIZE_RR 91

# include <unistd.h>
# include <stdlib.h>

# include <stdio.h> // \/!\ CAUTION !!!!! /!\/

typedef struct s_list
{
	struct s_list	*next;
	struct s_list	*prev;
	int				value;
	int				index;
}	t_list;

typedef struct s_instruction
{
	struct s_instruction	*next;
	struct s_instruction	*prev;
	char					*operation;
	char					*invert_operation;
}	t_instruction;

typedef struct s_push_swap
{
	t_list			**pile_a;
	t_list			**pile_b;
	t_instruction	**instructions;
}	t_push_swap;

// |====================|
// |======= MOVE =======|
// |====================|

void			ft_move(char *operation, t_push_swap list_pack);
void			ft_move_temporary(char *operation, t_push_swap list_pack,
					t_instruction **lst_instruction);

// |=====================|
// |======= UTILS =======|
// |=====================|

int				ft_isdigit(int c);
int				ft_isspace(char c);

// |=====================|
// |======= INDEX =======|
// |=====================|

void			ft_init_index(t_list **lst);

// |=====================|
// |======= PILES =======|
// |=====================|

int				ft_is_ascending(t_list *lst);
int				ft_calcul_gap(t_list *start_a, t_list *end_a,
					t_list *start_b, t_list *end_b);

void			ft_go_to_element_pile(t_list **start, t_list *dst);

t_list			*ft_get_the_n_element_pile(t_list *start, int n);

// |======================|
// |======= OTHERS =======|
// |======================|

char			*get_next_line(int fd);

// |======================|
// |======= PARSE ========|
// |======================|

int				ft_parse(char *str, t_list **lst);

// |=========================|
// |======= MERGE_STR =======|
// |=========================|

char			*ft_str_merge(char **str, int space, int size);

// |===========================|
// |======= PILES_UTILS =======|
// |===========================|

int				ft_lstsize(t_list *lst);
int				ft_lstsize_instruction(t_instruction *lst);

void			ft_lstclear(t_list **lst);
void			ft_lstadd_back(t_list **lst, t_list *new);

t_list			*ft_lstmoveout(t_list **lst);

// |==========================|
// |======= OPERATIONS =======|
// |==========================|

void			ft_do_operation(char *str, t_list **lst_a, t_list **lst_b);

// |==========================|
// |======= PILES_MOVE =======|
// |==========================|

void			ft_move_to_top_pile_a(t_push_swap list_pack, t_list *element);
void			ft_move_to_top_pile_b(t_push_swap list_pack, t_list *element,
					t_instruction **lst_instruction);

// |============================|
// |======= CALCUL_MOVE ========|
// |============================|

int				ft_find_optimize_rotation(t_list **lst,
					t_list *lst_destination);

void			ft_calcul_move(t_push_swap list_pack);

// |=============================|
// |======= PILES_MIN_MAX =======|
// |=============================|

t_list			*ft_find_element_min(t_list *lst);
t_list			*ft_find_element_max(t_list *lst);

t_instruction	*ft_push_before_min(t_push_swap list_pack,
					t_instruction **tmp_instruction);
t_instruction	*ft_push_after_max(t_push_swap list_pack,
					t_instruction **tmp_instruction);

// |==============================|
// |======= PILES_ORDERING =======|
// |==============================|

void			ft_get_order(t_push_swap list_pack);

// |===============================|
// |======= PRINT_FUNCTIONS =======|
// |===============================|

void			ft_putnbr(int nb);
void			ft_putchar(char c);
void			ft_putstr(char	*s);
void			ft_print_instruction(t_instruction *lst);

size_t			ft_strlen(const char *s);

// |=================================|
// |======= LIST_INSTRUCTIONS =======|
// |=================================|

void			ft_find_combination_move(t_instruction **lst);

// |=======================================|
// |======= LIST_INSTRUCTIONS_UTILS =======|
// |=======================================|

void			ft_lstclear_instruction(t_instruction **lst);
void			ft_lstadd_back_instruction(t_instruction **lst,
					t_instruction *new);
void			ft_add_instruction(char *operation,
					t_instruction **lst_instruction);

char			*ft_invert_operation(char *operation);

t_instruction	*ft_lstnew_instruction(char *operation);

// |========================================|
// |======= CREATE_LIST_INSTRUCTIONS =======|
// |========================================|

t_instruction	*ft_create_list_instruction(void);

//==========================================

// |=========================|
// |======= TEMPORARY =======|
// |=========================|

void			ft_print_tab(char **tab);
void			ft_print_list(t_list **lst);
void			ft_print_new_element(t_list *tmp);
void			ft_print_tab_int(int *tab, int size);
void			ft_print_list_one_line(t_list **lst);
void			ft_print_piles(char *str, t_push_swap p);
void			ft_print_list_instruction(t_instruction **lst);
void			ft_print_new_element_instruction(t_instruction *tmp);
void			ft_print_list_instruction_one_line(t_instruction **lst);

#endif
