/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 21:28:42 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/01 00:06:29 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/client.h"

/*!
** @brief	exit client
** @param	error_message:	wanna print error message
** @return	none
*/
void	exit_client(char *error_message)
{
	print_error_message(error_message);
	exit(EXIT_FAILURE);
}

/*!
** @brief	main (entry point)
** @param	argc	argument count
** @param	argv	argument contents
** @return	status
*/
int	main(int argc, char **argv)
{
	int32_t		pid_server;
	int32_t		pid_client;

	check_argument(argc, argv);
	pid_server = ft_atoi(argv[1]);
	pid_client = getpid();
	send_bit_pid(pid_server, pid_client);
	send_bit_message(pid_server, argv[2]);

	return (EXIT_SUCCESS);
}
