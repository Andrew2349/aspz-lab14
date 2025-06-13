#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

void handler(int sig) {
    write(STDOUT_FILENO, "Tick (setitimer)\n", 17);
}

int main() {
    struct itimerval timer;

    signal(SIGALRM, handler);

    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;

    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);

    while (1) pause();
}

