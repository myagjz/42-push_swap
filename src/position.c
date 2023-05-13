/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myagiz <myagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:01:13 by myagiz            #+#    #+#             */
/*   Updated: 2023/04/29 17:15:24 by myagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* get_position:
*	Bir yığının her elemanına yukarıdan aşağıya artan sırada bir konum atar.
*
*	Example stack:
*		value:		 3	 0	 9	 1
*		index:		[3]	[1]	[4]	[2]
*		position:	<0>	<1>	<2>	<3>
*
*	Bu, belirli bir sayıyı belirli bir konuma taşımanın maliyetini hesaplamak için kullanılır. 
*	Yukarıdaki örnek yığın b ise, maliyeti a'yı yığınlamak için ilk öğeyi itecek hiçbir şey (0).
*	Bununla birlikte, üçüncü konumdaki en yüksek değer olan 9'u zorlamak istiyorsak, 
*	bu 9'u a yığınına itmeden önce b'nin üstüne getirmek 2 ekstra hamleye mal olur.
*/
static void	get_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

/* get_lowest_index_position:
*	Bir yığın içindeki en düşük dizine sahip öğenin geçerli konumunu alır.
*/
int	get_lowest_index_position(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_index;
	int		lowest_pos;

	tmp = *stack;
	lowest_index = INT_MAX;
	get_position(stack);
	lowest_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}

/* get_target:
*	B yığınındaki bir öğenin verilen dizini için A yığınındaki en iyi hedef konumu seçer. 
*	Önce B öğesinin dizininin uygun olup olmadığını kontrol eder.
*	A yığınında daha büyük bir dizine sahip bir öğe olup olmadığını 
*	kontrol ederek A yığınındaki öğeler arasında bir yere yerleştirilebilir. 
*	Değilse, A'daki en küçük indekse sahip elemanı bulur ve onu hedef konum olarak atar.
*
*	--- Example:
*		target_pos starts at INT_MAX
*		B index: 3
*		A contains indexes: 9 4 2 1 0
*		9 > 3 && 9 < INT_MAX 	: target_pos updated to 9
*		4 > 3 && 4 < 9 			: target pos updated to 4
*		2 < 3 && 2 < 4			: no update!
*
*	Bu nedenle, en yakın dizin olduğu için, hedef_pos'un dizin 4'ün konumu olması gerekir.
*
*	--- Example:
*		target_pos starts at INT_MAX
*		B index: 20
*		A contains indexes: 16 4 3
*		16 < 20					: no update! target_pos = INT_MAX
*		4  < 20					: no update! target_pos = INT_MAX
*		3  < 20					: no update! target_pos = INT_MAX
*
*	... target_pos, INT MAX'ta kalıyor, stratejileri değiştirmeniz gerekiyor.
*
*		16 < 20					: target_pos updated to 20
*		4  < 20					: target_pos updated to 4
*		3  < 20					: target_pos updated to 3
*
*	Bu nedenle, hedef_pos, yığının "sonu" olduğundan, dizin 3'ün konumu olmalıdır.
*/
static int	get_target(t_stack **a, int b_idx,
								int target_idx, int target_pos)
{
	t_stack	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index > b_idx && tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (target_idx != INT_MAX)
		return (target_pos);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (target_pos);
}

/* get_target_position:
*	A yığınındaki her öğeye A yığınında bir hedef konum atar. 
*	Hedef konum, B'deki öğenin doğru şekilde sıralanması için ulaşması gereken noktadır. 
*	Bu konum, her öğeyi yığın A'daki hedef konumuna taşımanın maliyetini hesaplamak için kullanılacaktır.
*/
void	get_target_position(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	int		target_pos;

	tmp_b = *b;
	get_position(a);
	get_position(b);
	target_pos = 0;
	while (tmp_b)
	{
		target_pos = get_target(a, tmp_b->index, INT_MAX, target_pos);
		tmp_b->target_pos = target_pos;
		tmp_b = tmp_b->next;
	}
}
