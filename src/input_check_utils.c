/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myagiz <myagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:39:58 by myagiz            #+#    #+#             */
/*   Updated: 2023/05/29 14:57:39 by myagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* is_digit:
*   Karakterin rakam olup olmadığını kontrol eder.
*   Dönüş: Karakter bir rakam ise 1, değilse 0.
*/
int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/* is_sign:
*   Karakterin sayı işareti mi, + mı yoksa - mi olduğunu kontrol eder.
*   Dönüş: Karakter bir işaret ise 1, değilse 0.
*/
int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

/* nbstr_cmp:
*   Aynı olup olmadıklarını kontrol etmek için iki rakam dizisini karşılaştırır.
*   Dizelerden biri '+' işaretiyle başlıyorsa, yok sayılır ve sayı dizisinin geri kalanı kontrol edilir.
*   Bu öyle ki +123 == 123 ama -123 != 123.
*   Dönüş: Dizeler eşleşirse 0, eşleşmezse başka bir değer.
*/
int	nbstr_cmp(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
			i++;
	}
	else
	{
		if (s2[j] == '+')
			j++;
	}
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}
