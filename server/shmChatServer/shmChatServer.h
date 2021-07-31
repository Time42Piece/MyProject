/*************************************************************************
	> File Name: shmChatServer.h
	> Author: Mccree
	> Mail: MccreeHero@163.com
	> Created Time: Wed 28 Jul 2021 04:03:17 PM CST
 ************************************************************************/

#ifndef _SHMCHATSERVER_H
#define _SHMCHATSERVER_H

#include "common.h"

namespace server {

struct client {
	sockaddr_in address;
	int connfd;
	pid_t pid;
	int pipefd[2];
};

class shmChatServer {
public:
	shmChatServer(char *_ip, int _port) : ip(_ip), port(_port), 
		share_mem((char*)0), data((client*)0), sub_process((int*)0), 
		user_count(0), stop_child(false) {}
	~shmChatServer();

	int init();
	int run();

private:
	static int setnoblocking(int fd);

private:
	static constexpr int USER_LIMIT = 5;
	static constexpr int BUFFER_SIZE = 1024;
	static constexpr int FD_LIMIT = 65535;
	static constexpr int MAX_EVENT_NUMBER = 1024;
	static constexpr int PROCESS_LIMIT = 65535;

private:
	static constexpr char *shm_name = "/my_shm";
	char *ip;
	int port;
	int epollfd;
	int sig_pipefd[2];
	int listenfd;
	int shmfd;
	char *share_mem;
	client *users;
	int *sub_process;
	int user_count;
	bool stop_child;

};

}

#endif
