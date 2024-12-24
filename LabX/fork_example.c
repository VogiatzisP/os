#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    for (int i = 0; i < 3; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            // Αν αποτύχει το fork
            perror("Fork failed");
            return 1;
        } else if (pid == 0) {
            // Το child process
            printf("Child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
            return 0; // Τερματισμός child για να μην δημιουργήσει child
        }
    }

    // Παύση του parent για να διασφαλίσουμε την εκτέλεση
    sleep(1);

    return 0;
}
