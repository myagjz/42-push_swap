/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myagiz <myagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:56:02 by myagiz            #+#    #+#             */
/*   Updated: 2023/04/29 16:57:44 by myagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* push:
*	Kaynak yığınının üst öğesini hedef yığının en üstüne iter.
*/
static void	push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

/* do_pa:
*	b yığınının üst elemanını a yığınının üstüne iter.
*	Standart çıktıya "pa" yazdırır.
*/
void	do_pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_putstr("pa\n");
}

/* do_pb:
*	a yığınının üst elemanını b yığınının üstüne iter.
*	Standart çıktıya "pb" yazdırır.
*/
void	do_pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr("pb\n");
}
