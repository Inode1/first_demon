/*
 * my_telnet_help.h
 *
 *  Created on: Oct 16, 2014
 *      Author: ivan
 */

#ifndef MY_TELNET_HELP_H_
#define MY_TELNET_HELP_H_
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/types.h>


#include <sys/ipc.h>


#include <sys/msg.h>
#define MSGSZ     256
typedef struct msg {
         long    mtype;
         char    mtext[MSGSZ];
         }msgbuf;


#endif /* MY_TELNET_HELP_H_ */
