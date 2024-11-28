#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct client{
	int id;
	char msg[424242];
} t_client;

t_client clients[1024];
char buffRead[424242], buffWrite[424262]; // +20
int max=0, nextId=0;
fd_set activeFds, readFds, writeFds;

void err(char *str){
	write(2, str, strlen(str));
	exit(1);
}

void sendMsg(int sendFd){
	for (int fd = 0; fd <= max; fd++){
		if (FD_ISSET(fd, &writeFds) && fd != sendFd)
			write(fd, buffWrite, strlen(buffWrite));
	}
}

int main(int ac, char **av){
	if (ac != 2)
		err("Wrong number of arguments\n");
	int sockfd = max = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
		err("Fatal error\n");
	FD_ZERO(&activeFds);
	FD_SET(sockfd, &activeFds);

	struct sockaddr_in servaddr;
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(av[1]));
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
		err("Fatal error\n");
	if (listen(sockfd, 10) != 0)
		err("Fatal error\n");

	while (1){
		readFds = writeFds = activeFds;
		if (select(max + 1, &readFds, &writeFds, NULL, NULL) < 0)
			continue;

		for (int fd = 0; fd <= max; fd++){
			if (!FD_ISSET(fd, &readFds))
				continue;
			if (fd == sockfd){
				int clientSock = accept(sockfd, NULL, NULL);
				max = (clientSock > max) ? clientSock : max;
				clients[clientSock].id = nextId++;
				bzero(clients[clientSock].msg, strlen(clients[clientSock].msg));
				FD_SET(clientSock, &activeFds);
				sprintf(buffWrite, "server: client %d just arrived\n", clients[clientSock].id);
				sendMsg(clientSock);
				break;
			}
			int read = recv(fd, buffRead, sizeof(buffRead), 0);
			if (read <= 0){
				sprintf(buffWrite, "server: client %d just left\n", clients[fd].id);
				sendMsg(fd);
				FD_CLR(fd, &activeFds);
				close(fd);
				break;
			}
			else{
				for (int i = 0, j = strlen(clients[fd].msg); i < read; i++, j++){
					clients[fd].msg[j] = buffRead[i];
					if (clients[fd].msg[j] == '\n'){
						clients[fd].msg[j] = 0;
						sprintf(buffWrite, "client %d: %s\n", clients[fd].id, clients[fd].msg);
						sendMsg(fd);
						bzero(clients[fd].msg, strlen(clients[fd].msg));
						j = -1;
					}
				}
				break;
			}
		}
	}
}
