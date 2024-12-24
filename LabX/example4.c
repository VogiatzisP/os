#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main() {
    pid_t pid;
    int file;

    // Άνοιγμα αρχείου για εγγραφή
    file = open("pids.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (file < 0) {
        perror("Failed to open file");
        return 1;
    }

    // Δημιουργία child process
    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process
        dprintf(file, "Child process PID: %d\n", getpid());
    } else {
        // Parent process
        dprintf(file, "Parent process PID: %d\n", getpid());

        // Περιμένουμε το child process να τερματίσει
        wait(NULL);
    }

    // Κλείσιμο του αρχείου
    close(file);

    return 0;
}
