/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:10:05 by lnicolau          #+#    #+#             */
/*   Updated: 2024/03/25 13:10:05 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "./libft/libft.h"
#include "./libft/ft_printf.h"

void process_signal(int sendsignal, siginfo_t *info, void *ucontext)
{
    (void)ucontext;
    static unsigned char buff;
    static int received_signal_count;
    static int client_pid = 0;

    if (client_pid == 0) {
        client_pid = info->si_pid;
        ft_printf("Mensaje enviado por el cliente: PID %d\n", client_pid);
    }

    buff |= (sendsignal == SIGUSR1);
    received_signal_count++;
    if (received_signal_count == 8)
    {
        ft_printf("%c", buff);
        if (buff == '\0')
            ft_printf("\n");
        received_signal_count = 0;
        buff = 0;
    }
    else
        buff <<= 1;
}

int main(void)
{
    ft_printf("PID: %i\n", getpid());

    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = process_signal;

    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    while (1)
        pause();
    return (0);
}