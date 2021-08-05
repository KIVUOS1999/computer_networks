#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	char store[100];
	int fd = open("myfifo", O_RDONLY);
	read(fd, store, sizeof(store));
	close(fd);
	printf("%s", store);
}
