#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main() {
    int pipefd[2];  // pipefd[0]: Read end, pipefd[1]: Write end
    pid_t pid;
    char message[] = "Hello from parent!";
    char buffer[100];

    // Δημιουργία του pipe
    if (pipe(pipefd) == -1) {
        perror("Pipe failed");
        return 1;
    }

    // Δημιουργία του child process
    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process
        close(pipefd[1]); // Κλείνουμε το write end του pipe
        read(pipefd[0], buffer, sizeof(buffer)); // Διαβάζουμε το μήνυμα
        printf("Child received: %s\n", buffer);
        close(pipefd[0]); // Κλείνουμε το read end
    } else {
        // Parent process
        close(pipefd[0]); // Κλείνουμε το read end του pipe
        write(pipefd[1], message, strlen(message) + 1); // Στέλνουμε το μήνυμα
        close(pipefd[1]); // Κλείνουμε το write end
    }

    return 0;
}
