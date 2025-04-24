#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>

int	main()
{
	int			server_fd;
	int			client_fd;
	struct sockaddr_in	src_addr;
	char			buffer[100];

	server_fd = socket(2, SOCK_STREAM, 0);
	if (server_fd == -1)
	{
		perror("socket");
		return 1;
	}
	src_addr.sin_family = 2;
	src_addr.sin_port = htons(6969);
	src_addr.sin_addr.s_addr = INADDR_ANY;
	if (bind(server_fd, (const struct sockaddr *)&src_addr, sizeof(src_addr)) == -1)
	{
		perror("bind");
		close(server_fd);
		exit(1);
	}
	if (listen(server_fd, 10) == -1)
	{
		perror("listen");
		close(server_fd);
		exit(1);
	}
	while (1)
	{
		client_fd = accept(server_fd, NULL, NULL);
		if (client_fd == -1)
		{
			perror("accept");
			close(server_fd);
			exit(1);
		}
		if (recv(client_fd, buffer, sizeof(buffer), 0) == -1)
		{
			perror("recv");
			close(server_fd);
			close(client_fd);
			exit(1);
		}
		if (recv(client_fd, buffer, sizeof(buffer), 0) == -1)
		{
			perror("recv");
			close(server_fd);
			close(client_fd);
			exit(1);
		}
		if (strlen(buffer) > strlen(".*( )*.\nflag"))
		{
			printf("%s\n", buffer);
			close(server_fd);
			close(client_fd);
			exit(0);
		}
		close(client_fd);
	}
}
