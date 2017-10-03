        if (-1 == execvp(argv[0], argv)) {
          perror("execvp");
          printf("  (couldn't find command)\n");
        }
        /* NOT REACHED unless error occurred */
        exit(1);
    } else /* parent:  in parent, childpid was set to pid of child process */
        waitpid(childpid, NULL, 0);  /* wait until child process finishes */
    return;
}

static void interrupt_handler(int sigint){
        if( sigint== SIGINT){
                //printf("^C\n");
                if(childpid!=-999){
                        kill(childpid, SIGINT);
                        childpid=-999;
                }else{
                        exit(1);
                //      pid_t parentpid = getpid();
                //      kill(parentpid, SIGINT);
                }
        }
}

int main(int argc, char *argv[])
{
    char cmd[MAXLINE];
    char *childargv[MAXARGS];
    int childargc;
    signal(SIGINT, interrupt_handler);

    while (1) {
        printf("%% "); /* printf uses %d, %s, %x, etc.  See 'man 3 printf' */
        fflush(stdout); /* flush from output buffer to terminal itself */
        getargs(cmd, &childargc, childargv); /* childargc and childargv are
            output args; on input they have garbage, but getargs sets them. */
        /* Check first for built-in commands. */
        if ( childargc > 0 && strcmp(childargv[0], "exit") == 0 )
            exit(0);
        else if ( childargc > 0 && strcmp(childargv[0], "logout") == 0 )
            exit(0);
        else
            execute(childargc, childargv);
    }
    /* NOT REACHED */
}