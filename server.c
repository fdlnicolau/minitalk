#include <signal.h>

void process_signal(int sendsignal)
{
    static unsigned char buffer; // almacena los bits recibidos
    static int received_signal_count; // num de señales recibidas

    buffer = 0;
    received_signal_count = 0;

    if(sedsignal == SIGUSR1)
        buffer |= 1;
    received_signal_count ++;

    if(received_signal_count == 8)
    {
        ft_printf("%c", buffer);
        received_signal_count = 0;
        buffer = 0;
    }
    else
    {
        buffer << 1;
    }
}

int main(void)
{
    ft_printf("El PID de nuestro fantastico cliente es chanchanchan...: %i\n", getpid())
    signal(SIGURSR1, process_signal);
    signal(SIGURSR2, process_signal);
    while (1)
        pause();
    return(0);
}