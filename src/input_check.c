/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myagiz <myagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:15:55 by myagiz            #+#    #+#             */
/*   Updated: 2023/04/29 17:21:56 by myagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* arg_is_number:
*   Bağımsız değişkenin bir sayı olup olmadığını kontrol eder. +1 1 ve -1 geçerli sayılardır.
*   Dönüş: Argüman bir sayıysa 1, değilse 0.
*/
static int	arg_is_number(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]) && av[i + 1] != '\0')
		i++;
	while (av[i] && is_digit(av[i]))
		i++;
	if (av[i] != '\0' && !is_digit(av[i]))
		return (0);
	return (1);
}

/* have_duplicates:
*   Bağımsız değişken listesinde yinelenen sayılar olup olmadığını kontrol eder.
*   Dönüş: Yinelenen bulunursa 1, yoksa 0.
*/
static int	have_duplicates(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if (j != i && nbstr_cmp(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/* arg_is_zero:
*   0 +0 -0 tekrardan ve 0 0000 +000 -00000000'den kaçınmak için 
*	bağımsız değişkenin 0 olduğunu kontrol eder.
*   Dönüş: Bağımsız değişken sıfırsa 1, sıfırdan başka bir şey içeriyorsa 0.
*/
static int	arg_is_zero(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]))
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

/* is_correct_input:
*   Verilen bağımsız değişkenlerin yinelemeler olmadan tüm sayılar olup olmadığını kontrol eder.
*   Dönüş: Bağımsız değişkenler geçerliyse 1, değilse 0.
*/
int	is_correct_input(char **av)
{
	int	i;
	int	nb_zeros;

	nb_zeros = 0;
	i = 1;
	while (av[i])
	{
		if (!arg_is_number(av[i]))
			return (0);
		nb_zeros += arg_is_zero(av[i]);
		i++;
	}
	if (nb_zeros > 1)
		return (0);
	if (have_duplicates(av))
		return (0);
	return (1);
}
