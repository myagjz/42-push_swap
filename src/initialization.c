/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myagiz <myagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:39:30 by myagiz            #+#    #+#             */
/*   Updated: 2023/05/30 13:51:32 by myagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* ft_sub_process:
*	Bu işlev, tırnak işaretleri arasında geçirilmeleri durumunda
*	yığınları çalışır ve sıralar.Bu senaryoda,
*	bu işlev dizeyi alır ve ayrılmış tamsayı
*	oluşturmak için sayıları böler.
*/
t_stack	*ft_sub_process(char **av)
{
	t_stack	*stack_a;
	char	**tmp;
	int		i;
	int		nb;

	stack_a = NULL;
	i = 0;
	tmp = &av[1];
	tmp = ft_split(av[1], 32);
	if (!is_correct_input(tmp))
		exit_error(NULL, NULL);
	while (tmp[i])
	{
		nb = ft_atoi(tmp[i]);
		if (i == 0)
			stack_a = stack_new((int)nb);
		else
			stack_add_bottom(&stack_a, stack_new((int)nb));
		i++;
	}
	free(tmp);
	return (stack_a);
}

/* fill_stack_values/fill_stack:
*	stack_a'yı sağlanan değerlerle doldurur.
*	Değerler tamsayı aralığının dışındaysa, yazdırır ve hata verir ve programdan çıkar.
*/
t_stack	*fill_stack_values(int ac, char **av)
{
	t_stack	*stack_a;

	stack_a = NULL;
	if (ac == 2)
	{
		stack_a = ft_sub_process(av);
		if (is_sorted(stack_a))
			exit_error(NULL, NULL);
		else if (ac == 2 && get_stack_size(stack_a) == 1)
			exit_error(NULL, NULL);
	}
	else
	{
		stack_a = fill_stack(ac, av);
	}
	return (stack_a);
}

t_stack	*fill_stack(int ac, char **av)
{
	t_stack		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	i = 1;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			exit_error(&stack_a, NULL);
		if (i == 1)
			stack_a = stack_new((int)nb);
		else
			stack_add_bottom(&stack_a, stack_new((int)nb));
		i++;
	}
	return (stack_a);
}

/* assign_index:
*	a yığınındaki her değere bir dizin atar. Bu, yığını sıralamak için uygun bir yoldur,
*	çünkü birbirine bitişik olan veya olmayan gerçek değerler yerine
*	dizinler kontrol edilebilir ve karşılaştırılabilir.
*
*		ex. values:		-3	 0	 9	 2
*		indexes:		[1]	[2]	[4]	[3]
*	Dizinler en yüksekten (stack_size) en düşüğe (1) atanır.
*/
void	assign_index(t_stack *stack_a, int stack_size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		value;

	while (--stack_size > 0)
	{
		ptr = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				highest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}
