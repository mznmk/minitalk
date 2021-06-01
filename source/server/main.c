/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 21:28:42 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/02 00:49:03 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/server.h"

int		g_receive_signal;
bool	g_terminate_flag;

/*!
** @brief	exit server
** @param	vars		structure server variables
** @param	message		wanna print message
** @param	success		true: success / false: failure
** @return	none
*/
void	exit_server(t_server_vars *vars, char *message, bool success)
{
	free_recieve_message(vars);
	if (success)
	{
		print_success_message(message);
		exit(EXIT_SUCCESS);
	}
	else
	{
		print_failure_message(message);
		exit(EXIT_FAILURE);
	}
}

/*!
** @brief	check argument
** @param	argc	argument count
** @param	argv	argument contents
** @return	none
*/
static void	check_argument(int argc, char **argv, t_server_vars *vars)
{
	(void)argv;
	if (argc != 1)
		exit_server(vars, USAGE_MSG_HEADER USAGE_MSG_DESCRIPTION, false);
}

// /*!
// ** @brief	initialize server
// ** @param	none
// ** @return	none
// */
// static void	init_server(void)
// {
// 	g_receive_signal = 0;
// 	g_terminate_flag = false;
// 	print_pid("server", getpid());
// 	set_signal();
// }

/*!
** @brief	main (server entry point)
** @param	argc	argument count
** @param	argv	argument contents
** @return	status
*/
int	main(int argc, char **argv)
{
	t_server_vars	vars;

	init_server_vars(&vars);
	check_argument(argc, argv, &vars);
	g_receive_signal = 0;
	g_terminate_flag = false;
	print_pid("server", getpid());
	set_signal();
	while (1)
	{
		if (g_receive_signal == SIGUSR1 || g_receive_signal == SIGUSR2)
			recieve_bit(&vars, g_receive_signal);
		if (g_terminate_flag)
			exit_server(&vars, "\nterminating...", true);
		pause();
	}
	return (EXIT_SUCCESS);
}
