/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myagiz <myagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:38:31 by myagiz            #+#    #+#             */
/*   Updated: 2023/05/29 14:54:24 by myagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* do_rev_rotate_both:
*	Ters, biri yerine oturana kadar hem A hem de B yığınını döndürür.
*	Verilen maliyet negatiftir çünkü her iki konum da kendi yığınlarının alt yarısındadır.
*	Yığınlar döndürüldükçe maliyet artar, biri 0'a ulaştığında yığın mümkün olduğu kadar
*	döndürülür ve en üst konum doğrudur.
*/
static void	do_rev_rotate_both(t_stack **a, t_stack **b,int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		do_rrr(a, b);
	}
}

/* do_rotate_both:
*	Biri yerine oturana kadar hem A hem de B yığınını döndürür.
*	Her iki konum da kendi yığınlarının üst yarısında yer aldığından,
*	verilen maliyet pozitiftir. Yığınlar döndürüldükçe maliyet azalır,
*	biri 0'a ulaştığında yığın mümkün olduğu kadar döndürülür ve en üst konum doğrudur.
*/
static void	do_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		do_rr(a, b);
	}
}

/* do_rotate_a:
*	A yığınını konumuna gelene kadar döndürür.
*	Maliyet negatifse, yığın ters döndürülür, pozitifse döndürülür.
*/
static void	do_rotate_a(t_stack **a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			do_ra(a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			do_rra(a);
			(*cost)++;
		}
	}
}

/* do_rotate_b:
*	Yığın B'yi konumuna gelene kadar döndürür.
*	Maliyet negatifse, yığın ters döndürülür, pozitifse döndürülür.
*/
static void	do_rotate_b(t_stack **b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			do_rb(b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			do_rrb(b);
			(*cost)++;
		}
	}
}

/* do_move:
*	B yığın elemanını A yığınında doğru konuma getirmek için hangi hareketin yapılacağını seçer.
*	Yığını A ve B'yi konuma taşımanın maliyeti eşleşirse (yani her ikisi de pozitifin negatifi),
*	ikisi de aynı anda döndürülecek veya tersine döndürülecektir.
*	Sonunda üst B öğesini üst yığın A'ya itmeden önce ayrı ayrı döndürülebilirler.
*/
void	do_move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_rev_rotate_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rotate_both(a, b, &cost_a, &cost_b);
	do_rotate_a(a, &cost_a);
	do_rotate_b(b, &cost_b);
	do_pa(a, b);
}
