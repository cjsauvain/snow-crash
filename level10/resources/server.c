#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>

int	main(int argc, char **argv)
{
	int					fd;
	struct sockaddr_in	src_addr;
	fd_set				readset;
	char				buffer[100];

	if (argc == 1)
	{
		printf("Usage: ./server file\n");
		return 1;
	}
	fd = socket(2, SOCK_STREAM, 0);
	if (fd == -1)
	{
		perror("socket");
		return 1;
	}
	src_addr.sin_family = 2;
	src_addr.sin_port = htons(6969);
	src_addr.sin_addr.s_addr = INADDR_ANY;
	if (bind(fd, (const struct sockaddr *)&src_addr, sizeof(src_addr)) == -1)
	{
		perror("bind");
		close(fd);
		exit(1);
	}
	if (listen(fd, 10) == -1)
	{
		perror("listen");
		close(fd);
		exit(1);
	}
	if (accept(fd, NULL, NULL) == -1)
	{
		perror("accept");
		close(fd);
		exit(1);
	}
	unlink(argv[1]);
	symlink(argv[1], "/home/user/level10/token"); //symlink doesn't work for the moment
	if (recv(fd, buffer, sizeof(buffer), 0) == -1)
	{
		perror("recv");
		close(fd);
		exit(1);
	}
	printf("flag = %s\n", buffer);
}
