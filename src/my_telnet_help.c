/*
 * my_telnet_help.c
 *
 *  Created on: Oct 16, 2014
 *      Author: ivan
 */
#include "my_telnet_help.h"

void print_usage(int socket_fd){
	char *message="print /get software ip.address login password        take software list,\n \t\t\t\twhere password for ssh\n";
	write(socket_fd , message , strlen(message));

}
int my_telnet_help(int socket_fd,int msgid){

	char client_message[2048];
	char *stok;
	print_usage(socket_fd);
	recv(socket_fd , client_message , 2048 , 0);
	msgbuf my_request;
	msgbuf repl;
	my_request.mtype=1;
	sprintf(my_request.mtext,"%d ",socket_fd);

	strcat(my_request.mtext,client_message);
	fprintf(stderr,"%s",my_request.mtext);
	int len=strlen(my_request.mtext+1);
	write(socket_fd , "WAIT.....\n" , strlen("WAIT.....\n"));
	msgsnd(msgid, &my_request,len , IPC_NOWAIT);
	fprintf(stderr,"%s",strerror(errno));
	msgrcv(msgid, &repl, MSGSZ, socket_fd, 0);
	if(!strcmp(repl.mtext,"Error")){
		write(socket_fd , "Error" , strlen("Error"));
		return 0;}
	fprintf(stderr,"%s",repl.mtext);
	int fd = open(repl.mtext, O_RDONLY);
	char buf[1024];
	int buflen;
	while((buflen = read(fd, buf, 1024)) > 0)
	{
	    write(socket_fd, buf, buflen);
	}
	write(socket_fd , "END..............\n" , strlen("END..............\n"));
	close(fd);

return 0;

}
