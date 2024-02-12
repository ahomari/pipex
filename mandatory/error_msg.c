/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:07:15 by ahomari           #+#    #+#             */
/*   Updated: 2024/02/12 15:56:53 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	print_msg(char *str)
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

void	error_msg(int num, char *str)
{
	if (num == -1)
	{
		perror(str);
		exit(1);
	}
	else if (num == -2)
		print_msg(str);
}
