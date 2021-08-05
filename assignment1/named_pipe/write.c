//named pipes
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	mkfifo("myfifo", 0777);
	
	printf("opening..\n");	
	
	char arr[100];
	scanf("%s", arr);
	
	int fd = open("myfifo", O_WRONLY);
	
	write(fd, arr, sizeof(arr));
	close(fd);
	return 0;
}
