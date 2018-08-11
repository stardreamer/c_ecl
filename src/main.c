#include <stdio.h>
#include <sys/resource.h>
#include <string.h>
#include <stdlib.h>
#include "nav.h"
#include <time.h>
#include <sys/time.h>

double time_diff(struct timeval x , struct timeval y)
{
    double x_ms , y_ms , diff;

    x_ms = (double)x.tv_sec*1000000 + (double)x.tv_usec;
    y_ms = (double)y.tv_sec*1000000 + (double)y.tv_usec;

    diff = (double)y_ms - (double)x_ms;

    return diff;
}

void main(int argc, char **argv)
{
    if (argc >= 2)
    {
        struct timeval before , after;
        gettimeofday(&before , NULL);
        int descriptor;
        struct rusage r_usage;
        getrusage(RUSAGE_SELF,&r_usage);
        printf("Memory usage = %ld|CPU time: %ld.%06ld sec user, %ld.%06ld sec system\n",r_usage.ru_maxrss,r_usage.ru_utime.tv_sec, r_usage.ru_utime.tv_usec, r_usage.ru_stime.tv_sec, r_usage.ru_stime.tv_usec);
        get_file_descriptor(argv[1], &descriptor);
        getrusage(RUSAGE_SELF,&r_usage);
        printf("Memory usage = %ld|CPU time: %ld.%06ld sec user, %ld.%06ld sec system\n",r_usage.ru_maxrss,r_usage.ru_utime.tv_sec, r_usage.ru_utime.tv_usec, r_usage.ru_stime.tv_sec, r_usage.ru_stime.tv_usec);
        HeaderArray arre;
        
        get_headers(descriptor, &arre);

        getrusage(RUSAGE_SELF,&r_usage);
        printf("Memory usage = %ld|CPU time: %ld.%06ld sec user, %ld.%06ld sec system\n",r_usage.ru_maxrss,r_usage.ru_utime.tv_sec, r_usage.ru_utime.tv_usec, r_usage.ru_stime.tv_sec, r_usage.ru_stime.tv_usec);
        gettimeofday(&after , NULL);
        printf("Total elapsed time: %lf s\n", time_diff(before , after)/1e6);
        printf("%d\n", arre.length);
    }

}