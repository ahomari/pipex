/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:56:42 by ahomari           #+#    #+#             */
/*   Updated: 2024/02/10 20:40:51 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

static void	print_msg_bonus(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write (2, &str[i], 1);
		i++;
	}
	exit(1);
}

void	error_msg_bonus(int num, char *str)
{
	if (num == -1)
	{
		perror(str);
		exit(1);
	}
	else if (num == -2)
		print_msg_bonus(str);
}
