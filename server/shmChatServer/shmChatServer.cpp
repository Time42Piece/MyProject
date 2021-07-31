/*************************************************************************
	> File Name: server_shm_chat.cpp
	> Author: Mccree
	> Mail: MccreeHero@163.com
	> Created Time: Wed 28 Jul 2021 03:42:13 PM CST
 ************************************************************************/

#include "shmChatServer.h"

namespace server {

shmChatServer::~shmChatServer() {
	close(sig_pipefd[0]);
	close(sig_pipefd[1]);
	close(listenfd);
	close(epollfd);
	shm_unlink(shm_name);
	delete[] users;
	delete[] sub_process;
}

int shmChatServer::init() {
	return 0;
}

int shmChatServer::run() {
	return 0;
}

static int setnoblocking(int fd) {
	return 0;
}

}