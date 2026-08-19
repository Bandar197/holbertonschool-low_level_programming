#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * close_fd - closes a file descriptor
 * @fd: file descriptor
 */
void close_fd(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * open_from - opens source file
 * @name: file name
 *
 * Return: file descriptor
 */
int open_from(char *name)
{
	int fd;

	fd = open(name, O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't read from file %s\n", name);
		exit(98);
	}
	return (fd);
}

/**
 * open_to - opens destination file
 * @name: file name
 *
 * Return: file descriptor
 */
int open_to(char *name)
{
	int fd;

	fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", name);
		exit(99);
	}
	return (fd);
}

/**
 * copy_file - copies file content
 * @from: source file descriptor
 * @to: destination file descriptor
 * @from_name: source file name
 * @to_name: destination file name
 */
void copy_file(int from, int to, char *from_name, char *to_name)
{
	char buffer[1024];
	ssize_t r, w;

	while ((r = read(from, buffer, 1024)) > 0)
	{
		w = write(to, buffer, r);
		if (w != r)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", to_name);
			exit(99);
		}
	}
	if (r == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't read from file %s\n", from_name);
		exit(98);
	}
}

/**
 * main - copies a file
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	fd_from = open_from(argv[1]);
	fd_to = open_to(argv[2]);
	copy_file(fd_from, fd_to, argv[1], argv[2]);
	close_fd(fd_from);
	close_fd(fd_to);
	return (0);
}
