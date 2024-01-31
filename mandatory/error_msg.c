/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:07:15 by ahomari           #+#    #+#             */
/*   Updated: 2024/01/31 18:07:17 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void    error_msg(char *str)
{
    perror(str);
    exit(1);
}
int     print_msg(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        write (2, &str[i], 1);
        i++;
    }
    return (1);
}