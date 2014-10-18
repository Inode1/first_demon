/*
 * server.h
 *
 *  Created on: Oct 16, 2014
 *      Author: ivan
 */

#ifndef SERVER_H_
#define SERVER_H_
#define PORT "4000"
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
#define BACKLOG 10     // как много может быть ожидающих соединений
#define MAXDATASIZE 1024
#endif /* SERVER_H_ */
