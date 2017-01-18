#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main(int nargs, char *args[])
{
    int my_pipe[2];
    char a1[256];
    char a2[256];
    char comm[256];
    pipe(my_pipe);
    pid_t pid = fork();
    if (pid > 0) {
        printf("Parent PID = %d\n", getpid());
        close(my_pipe[0]);
        strcpy(a1, args[1]);
        write(my_pipe[1], a1, (strlen(a1)+1));
        wait(NULL);
        //printf("For echo, child process should send \"Hello World!\" as an argument in exec()\n");
    }
    else if (pid == 0) {
        close(my_pipe[1]);
        read(my_pipe[0], a2, sizeof(a2));
        printf("Child PID = %d\n", getpid());
        strcat(comm,"/bin/");
        strcat(comm, a2);
        char *a = comm;
        char *b = a2;
        if(strcmp(a2,"echo") == 0)
        {
            execl("/bin/echo","echo","Hello","World!", NULL);
        }
        else{
            execl(a, b, 0, NULL);
        }
        exit(0);
    }    
    return 0;
}