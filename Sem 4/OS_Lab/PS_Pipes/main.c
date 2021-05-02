#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int fd1[2], fd2[2];
    int pid;

    char *wc_args[] = {"wc", NULL};
    char *grep_args[] = {"grep", "--binary-files=text", "-i", "hai", NULL};
    char *cat_args[] = {"cat", "file.txt", NULL};

    pipe(fd1);
    pipe(fd2);

    pid = fork();
    if (pid < 0)
        perror("Error in creating child process");
    else if (pid == 0)
    {
        close(fd1[1]);
        close(fd2[0]);

        dup2(fd1[0], 0);
        dup2(fd2[1], 1);

        close(fd1[0]);
        close(fd2[1]);

        execvp(*grep_args, grep_args);
    }
    else
    {
        char c;
        close(fd1[0]);
        close(fd2[1]);

        dup2(fd2[0], 0);
        close(fd2[0]);

        int pid2 = fork();
        if (pid2 < 0)
            perror("Child creation failed !");
        else if (pid2 == 0)
        {
            dup2(fd1[1], 1);
            close(fd1[1]);
            execvp(*cat_args, cat_args);
        }
        else
            close(fd1[1]);

        wait(NULL);
        execvp(*wc_args, wc_args);
    }
}