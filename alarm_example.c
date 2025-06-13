#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handler(int sig) {
    write(STDOUT_FILENO, "Alarm!\n", 7);
}

int main() {
    signal(SIGALRM, handler);
    alarm(2);

    while (1) pause();
}

