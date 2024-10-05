#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char** argv)
{
	if(argc < 2){
		perror("Please provide Filename");
		exit(EXIT_FAILURE);
	}

	if(argc >= 6){
		perror("Please enter arguments as intended");
		exit(EXIT_FAILURE);
	}
	const char* filename = argv[1];
	const unsigned int BUFFER_SIZE = 70000;
	char buffer[BUFFER_SIZE];
	int i_fd = open(filename, O_RDWR);
	unsigned int bytes_read;
	if(i_fd == -1)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	bytes_read = read(i_fd, buffer, BUFFER_SIZE);
	if(bytes_read == -1) {
		perror("Error reading file");
		exit(EXIT_FAILURE);
	}
	close(i_fd);

	char to_find = ';';
	char to_replace = '\n';
	int remove = 0;

	if (argc >= 3)
		to_find = argv[2][0];
	if (argc >= 4)
		to_replace = argv[3][0];
	if (argc >= 5)
		remove = argv[4][0] - 48;

	int written = 0;
	printf(" to replace is %d\n",to_replace);

	for(int i = 0 ; i < bytes_read + written; i++)
	{
		if(buffer[i] == to_find)
		{

			if(bytes_read + written + 1 > BUFFER_SIZE)
			{
				perror("Please increase BUFFER_SIZE");
				exit(-1);
			}
			if (remove)
			{
				buffer[i] = to_replace;
				printf("argv is 1 and replacing\n");
				continue;
			}
			for(int j = bytes_read + written; i < j; j--)
				buffer[j] = buffer[j - 1];
			buffer[i + 1] = to_replace;
			written += 1;

			printf("replacing with protecting\n");
		}
	}
	buffer[bytes_read + written] = '\0';
	int o_fd = open("parsedfile.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if(o_fd == -1)
	{
		perror("Error creating file");
		exit(EXIT_FAILURE);
	}
	printf("%s\n",buffer);
	printf("%d\n",bytes_read);
	int check = write(o_fd, buffer, bytes_read + written - 1);
	if (check == -1)
	{
		perror("Error writing to file");
		exit(EXIT_FAILURE);
	}
	close(o_fd);
}
