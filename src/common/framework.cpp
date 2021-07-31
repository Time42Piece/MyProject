/*************************************************************************
	> File Name: main.cpp
	> Author: Mccree
	> Mail: MccreeHero@163.com
	> Created Time: Wed 28 Jul 2021 03:55:30 PM CST
 ************************************************************************/

#include "shmChatServer.h"

int main(int argc, char *argv[]) {
	if (argc <= 2) {
		printf("usage : %s ip_address port_number\n", basename(argv[0]));
		return 1;
	}
	server::shmChatServer server(argv[1], atoi(argv[2]));
	server.init();
	server.run();
	
	return 0;
}