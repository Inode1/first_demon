/*
 ============================================================================
 Name        : demon.c
 Author      : Ivan
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/msg.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <syslog.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>
#include <time.h>
int server_setup(int);
static int msgid;
static int pid_second_deamon;
static int pid_third_deamon;
#define PIDFILENAME2 "/tmp/second_deamon.pid"
#define PIDFILENAME3 "/var/run/third_deamon.pid"

void Read_PID_File(char* Filename,int *param)
{
    FILE* f;

    f = fopen(Filename, "r");
    if (f)
    {
        fscanf(f,"%u",param);
        fclose(f);
    }}
void recv_msg_from_third_deamon(){
	Read_PID_File(PIDFILENAME3,&pid_third_deamon);
	kill(pid_third_deamon,SIGALRM);
	signal(SIGALRM,recv_msg_from_third_deamon);


}
void clean(){

	Read_PID_File(PIDFILENAME2,&pid_second_deamon);
	unlink(PIDFILENAME2);
	kill(pid_second_deamon,SIGKILL);
	msgctl(msgid, IPC_RMID, 0);
	kill(0,SIGTERM);
	exit(0);

}



int main(int argc, char** argv)
{	//Работа по создании очереди и демона
	key_t key;
	key=5555;
	int sid,pid;
	char buf[20];

    // создаем потомка
    pid = fork();
    if (pid < 0) {
                   exit(EXIT_FAILURE);
           	   	   }
    if (pid > 0) {
                   exit(EXIT_SUCCESS);
           	   	   }
     umask(0);
     sid=setsid();
     chdir("/");
     close(STDIN_FILENO);
     close(STDOUT_FILENO);
     close(STDERR_FILENO);
     if ((msgid = msgget(key,IPC_CREAT | 0666)) < 0) {
                         exit(1);
     }

     signal(SIGALRM,recv_msg_from_third_deamon);
     signal(SIGINT,clean);
     server_setup(msgid);
     exit(0);

}

