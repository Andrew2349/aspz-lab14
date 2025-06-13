#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main() {
    struct timespec rt_prev = {0, 0};
    struct timespec rt_curr;
    struct timespec mono_curr;

    while (1) {
        clock_gettime(CLOCK_REALTIME, &rt_curr);
        clock_gettime(CLOCK_MONOTONIC, &mono_curr);

        if (rt_prev.tv_sec != 0) {
            long diff = rt_curr.tv_sec - rt_prev.tv_sec;
            if (diff > 2 || diff < 0) {
                printf(">>> Time jump detected! CLOCK_REALTIME changed by %ld seconds <<<\n", diff);
            }
        }

        printf("CLOCK_REALTIME: %ld.%09ld | CLOCK_MONOTONIC: %ld.%09ld\n",
               rt_curr.tv_sec, rt_curr.tv_nsec,
               mono_curr.tv_sec, mono_curr.tv_nsec);

        rt_prev = rt_curr;
        sleep(1);
    }

    return 0;
}

