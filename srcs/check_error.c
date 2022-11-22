/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 08:46:48 by vferraro          #+#    #+#             */
/*   Updated: 2022/11/22 08:55:08 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/************************************************
* Gere le message d'erreur et exit le programme *
************************************************/
void	critical_errors(char *str)
{
	ft_printf("\n--------------------------\n\n%s\
%s\n--------------------------\n\n", ERROR, str);
	exit(EXIT_FAILURE);
}

/******************************************************************
**	verifier que mon fichier a lire est un .*cub et rien d'autre **
*******************************************************************/
void	check_file(char *str)
{
	char	*compare;
	int		len;

	len = ft_strlen(str);
	if (!str)
		return ;
	compare = ft_strnstr(str, "*.cub", len);
	if (compare && ft_strlen(compare) == 5)
	{
		return ;
	}
	critical_errors(ERR_FILE);
}
