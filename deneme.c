// #include "philo.h"


// // int main(void)
// // {
// //     struct timeval tv;
// //     if(gettimeofday(&tv, NULL) < 0)
// //     {
// //         perror("gettimeofday");
// //         exit(EXIT_FAILURE);
// //     }

// //     printf("current time is %ld seconds + %ld microseconds\n", tv.tv_sec, tv.tv_usec);
// // }

// int main(int argc, char **argv)
// {
//     t_data  data;
//     t_philo *philos;
//     int     i;

//     // --- Test 1: arg parsing ---
//     if (!parse_args(&data, argc, argv))
//         return (1);
//     printf("=== ARGS ===\n");
//     printf("nb_philos     = %d\n", data.nb_philos);
//     printf("time_to_die   = %ld\n", data.time_to_die);
//     printf("time_to_eat   = %ld\n", data.time_to_eat);
//     printf("time_to_sleep = %ld\n", data.time_to_sleep);
//     printf("must_eat      = %d\n", data.must_eat);

//     // --- Test 2: init ---
//     if (!init_all(&philos, &data))
//     {
//         printf("init_all FAILED\n");
//         return (1);
//     }
//     printf("\n=== PHILOS ===\n");
//     i = 0;
//     while (i < data.nb_philos)
//     {
//         printf("P%d | left_fork=%p | right_fork=%p | last_meal=%ld\n",
//             philos[i].id,
//             (void *)philos[i].left_fork,
//             (void *)philos[i].right_fork,
//             philos[i].last_meal);
//         i++;
//     }

//     // --- Test 3: timing ---
//     printf("\n=== TIMING ===\n");
//     printf("start_time = %ld\n", data.start_time);
//     printf("sleeping 200ms...\n");
//     sleep_ms(200);
//     printf("elapsed    = %ldms\n", get_time() - data.start_time);

//     // --- Test 4: fork pointers (circular check) ---
//     printf("\n=== FORK LINKS ===\n");
//     i = 0;
//     while (i < data.nb_philos)
//     {
//         printf("P%d left=%p  right=%p  %s\n",
//             philos[i].id,
//             (void *)philos[i].left_fork,
//             (void *)philos[i].right_fork,
//             philos[i].left_fork != philos[i].right_fork
//                 ? "OK" : "SAME FORK (1 philo case)");
//         i++;
//     }

//     free(philos);
//     return (0);
// }