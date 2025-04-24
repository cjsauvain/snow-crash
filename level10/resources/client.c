#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int	main(void)
{
	int					fd;
	struct sockaddr_in	addr;
	char				buffer[] = "Bonjour";

	fd = socket(2, SOCK_STREAM, 0);
	if (fd == -1)
	{
		perror("socket");
		exit(1);
	}
	memset(&addr, 0, sizeof(addr));
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_family = 2;
	addr.sin_port = htons(6969);
	if (connect(fd, (const struct sockaddr *)&addr, 16) == -1)
	{
		perror("connect");
		close(fd);
		exit(1);
	}
	printf("connected...\n");
	write(fd, buffer, sizeof(buffer));
}
