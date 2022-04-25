/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: indoming <indoming@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 09:55:37 by indoming          #+#    #+#             */
/*   Updated: 2022/04/22 13:51:33 by indoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stdlib.h"
# include "libft/include/libft.h"
# include "libft/include/ft_printf.h"
# include <stdio.h>

int		main(int argc, char *argv[]);
void	ft_push_swap(char **argv);
//ERRORS
int		ft_number_count(char **argv);
int		ft_ps_atoi(const char *str, int *a);
void	check_rep(int *a, int num);
void	ft_error(int *str);
//SORTING
int		sorted(int *a, int ncount);
int		check_mov_min(int *a, int *b, int ncount, int ncount_b);
int		check_mov_max(int *a, int *b, int ncount, int ncount_b);
void	do_min(int *a, int *b, int ncount, int ncount_b);
void	do_max(int *a, int *b, int ncount, int ncount_b);
//Dawn
void	dawn(int **a, int **b, int ncount);
void	order_2(int *a);
void	order_3(int *a, int ncount);
void	order_some(int *a, int *b, int ncount);
//MOVEMENTS
//Mov1
void	sa(int *a);
void	sb(int *b);
void	pa(int *a, int *b, int ncount_b, int ncount);
void	pb(int *a, int *b, int ncount_b, int ncount);
//Mov2
void	ra(int *a, int ncount);
void	rb(int *b, int ncount_b);
void	rra(int *a, int ncount);
void	rrb(int *b, int ncount_b);
//Mov3
void	ss(int *a, int *b);
void	rr(int *a, int *b, int ncount, int ncount_b);
void	rrr(int *a, int *b, int ncount, int ncount_b);
//Utils
int		get_min(int *a, int ncount);
void	min_to_0(int *a, int min, int ncount);
int		get_upper(int *a, int i);
void	order_a_lot_2(int *a, int *b, int i, int count);
int		get_lower(int *a, int i);
//Utils2
int		get_mid_value(int *a, int items);
void	to_the_top_b(int *b, int j, int i);
void	to_the_top_a(int *a, int j, int i);
int		get_mid_2(int *a, int i, int lower, int mid);
int		get_mid(int *a, int i, int mid);
//Index
void	change_index(int *a, int items);
int		*sort_a_to_index(int *sorted, int *a, int items, int i);
int		get_index(int number, int items, int *sorted);

#endif
