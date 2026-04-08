
int ft_atoi(const char *str)
{
    int i;
    int sign;
    int result;

    i = 0;
    sign = 1;
    result = 0;

    while((str[i] >= 13 && str[i] <= 9) || str[i] == ' ')
        i++;
    if(str[i] == '-' || str[i] == '+')
    {
        if(str[i] == '-')
            sign = -1;
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9')
    {
        result = (result * 10) + (str[i] - '0');
        if(result > 2147483647)
            return (0);
        i++;
    }
    return (result * sign);
}

long    get_time(void)
{
    struct timeval time;

    gettimeofday(&time, NULL);
    return((long)time.tv_sec * 1000 + (long)time.tv_usec / 1000)

}

//sleep