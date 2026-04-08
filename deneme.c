#include "philo.h"


// int main(void)
// {
//     struct timeval tv;
//     if(gettimeofday(&tv, NULL) < 0)
//     {
//         perror("gettimeofday");
//         exit(EXIT_FAILURE);
//     }

//     printf("current time is %ld seconds + %ld microseconds\n", tv.tv_sec, tv.tv_usec);
// }

int main(int argc, char **argv)
{
    t_data data;

    if (!parse_args(&data, argc, argv))
        return 1;
    
    printf("nb_philos   = %d\n", data.nb_philos);
    printf("time_to_die = %ld\n", data.time_to_die);
    printf("time_to_eat = %ld\n", data.time_to_eat);
    printf("time_to_sleep = %ld\n", data.time_to_sleep);
    printf("must_eat    = %d\n", data.must_eat);

    return 0;
}