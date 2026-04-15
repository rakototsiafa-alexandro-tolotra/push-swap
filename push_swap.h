/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotot <arakotot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:08:30 by herasoan          #+#    #+#             */
/*   Updated: 2026/04/16 01:00:09 by arakotot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef enum e_strategy
{
	STRATEGY_SIMPLE,
	STRATEGY_MEDIUM,
	STRATEGY_COMPLEX,
	STRATEGY_ADAPTIVE
}	t_strategy;

typedef struct s_ops
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_ops;

typedef struct s_opts
{
	t_strategy	strategy;
	int			bench;
	t_ops		ops;
}	t_opts;

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	**a;
	t_node	**b;
}	t_stack;

/* Parsing & Erreurs */
void	free_stack(t_node **stack);
void	free_matrix(char **matrix);
void	parse_arguments(t_node **a, int *argc, char ***argv, t_opts *opts);
void	error_exit(t_node **a, char **matrix);
int		is_numeric(char *str);
long	ft_atol(const char *str);
int		check_duplicate(t_node *a, int n);

/* Opérations de base (moteurs, sans affichage) */
void	swap(t_node **stack);
void	push(t_node **src, t_node **dest);
void	rotate(t_node **stack);
void	rev_rotate(t_node **stack);

/* Commandes (affichent l'opération via ft_printf) */
void	sa(t_node **a, t_opts *opts);
void	sb(t_node **b, t_opts *opts);
void	ss(t_node **a, t_node **b, t_opts *opts);
void	pa(t_node **b, t_node **a, t_opts *opts);
void	pb(t_node **a, t_node **b, t_opts *opts);
void	ra(t_node **a, t_opts *opts);
void	rb(t_node **b, t_opts *opts);
void	rr(t_node **a, t_node **b, t_opts *opts);
void	rra(t_node **a, t_opts *opts);
void	rrb(t_node **b, t_opts *opts);
void	rrr(t_node **a, t_node **b, t_opts *opts);

/* Utilitaires pile */
void	append_node(t_node **stack, int n);
int		get_stack_size(t_node *stack);
int		get_min_pos(t_node *stack);
int		get_max_pos(t_node *stack);
void	index_stack(t_node *stack);
int		ft_sqrt(int number);

/* Algorithmes de tri */
void	sort_simple(t_stack *s, t_opts *opts);
void	sort_medium(t_stack *s, t_opts *opts);
void	sort_complex(t_stack *s, t_opts *opts);
void	sort_adaptive(t_stack *s, t_opts *opts);

/* Mesure du désordre */
double	compute_disorder(t_node *stack_a);
void	print_disorder(double disorder);

/* sort_simple_utils */
void	sort_three(t_node **a, t_opts *opts);
void	sort_small(t_node **a, t_opts *opts, int size);
void	rotate_min_to_top(t_node **a, t_opts *opts, int size);
void	insert_from_b(t_node **a, t_node **b, t_opts *opts);

/* sort_medium_utils */
void	push_chunks_to_b(t_stack *s, t_opts *opts, int size, int chunk_size);
void	push_max_to_a(t_node **a, t_node **b, t_opts *opts);

/* options */
int		is_strategy_flags(char *arg);
void	apply_flag(char *arg, t_opts *opts);
void	parse_flags(int *argc, char ***argv, t_opts *opts);

/* bench */
void	print_bench(t_opts *opts, double disorder);
void	get_strategy_info(t_strategy strat, char **name, char **complexity);
void	write_int_stderr(int n);

#endif