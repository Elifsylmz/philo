#include "philo.h"


int main(void)
{
    struct timeval tv;
    if(gettimeofday(&tv, NULL) < 0)
    {
        perror("gettimeofday");
        exit(EXIT_FAILURE);
    }

    printf("current time is %ld seconds + %ld microseconds\n", tv.tv_sec, tv.tv_usec);
}