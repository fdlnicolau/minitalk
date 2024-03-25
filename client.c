#include <unistd.h>
#include <signal.h>

void send_signal(int pid, unsigned char octet)
{
    int count_bit;
    unsigned char octect_tmp;
    int bit_value;

    count_bit = 0;
    octect_tmp = octect;
    bit_value = 0;

    while(count_bit < 8)
    {
        bit_value = (octect_tmp >> (7 - count_bit)) & 1;
    }
}