#include <stdio.h>
#include <time.h>

int main() {
    struct timespec ts;
    ts.tv_sec = 0;
    ts.tv_nsec = 500000000;

    for (int i = 0; i < 5; ++i) {
        printf("Tick\n");
        clock_nanosleep(CLOCK_MONOTONIC, 0, &ts, NULL);
    }

    return 0;
}

