/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 11:20:09 by seyu              #+#    #+#             */
/*   Updated: 2021/02/01 22:42:05 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

int	mini_echo(int argc, char **argv);
int	mini_cd(int argc, char **argv);
int	mini_pwd(void);
int	mini_export(int argc, char **argv);
int	mini_unset(int argc, char **argv);
int	mini_env(void);
int	mini_exit(int argc, char **argv, int piped);

#endif
