#include "philo.h"

int ft_atoi(const char *str)
{
    int i;
    int sign;
    long result;

    i = 0;
    sign = 1;
    result = 0;

    while((str[i] >= 8 && str[i] <= 13) || str[i] == ' ')
        i++;
    if(str[i] == '-' || str[i] == '+')
    {
        if(str[i] == '-')
            sign = -1;
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9')
    {
        if (result > (2147483647 / 10) || 
            (result == 2147483647 / 10 && (str[i] - '0') > 7))
            return (-1);
        result = (result * 10) + (str[i] - '0');
        i++;
    }
    return ((int)result * sign);
}

long    get_time(void)
{
    struct timeval time;

    gettimeofday(&time, NULL);
    return((long)time.tv_sec * 1000 + (long)time.tv_usec / 1000);

}

void    ft_usleep(long ms)
{
    long start;

    start = get_time();
    while ((get_time() - start) < ms)
        usleep(100);
}