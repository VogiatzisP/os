#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

// Signal handler για το child process
void signal_handler(int sig) {
    if (sig == SIGUSR1) {
        printf("Child: Received SIGUSR1 signal from parent.\n");
    }
}

int main() {
    pid_t pid;

    // Δημιουργία του child process
    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child: Waiting for signal...\n");

        // Εγγραφή του signal handler
        signal(SIGUSR1, signal_handler);

        // Αναμονή για σήμα
        pause(); // Το process αναστέλλεται μέχρι να λάβει σήμα
    } else {
        // Parent process
        sleep(1); // Μικρή καθυστέρηση για να προλάβει το child να μπει σε αναμονή
        printf("Parent: Sending SIGUSR1 signal to child (PID=%d).\n", pid);
        kill(pid, SIGUSR1); // Αποστολή σήματος SIGUSR1 στο child
    }

    return 0;
}
