/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:58:15 by maralons          #+#    #+#             */
/*   Updated: 2022/04/30 15:12:13 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>

void			ft_putstr_fd(char *s, int fd);

void			ft_putnbr_fd(int n, int fd);

void			ft_putchar_fd(char c, int fd);

unsigned long	ft_strlen(const char *s);
#endif