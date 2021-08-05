#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>

struct buffer{
	long type;
	char txt[200];
};

int main(){
	struct buffer msg;
	int id;
	
	key_t key = ftok("key.txt", 'b');	
	id = msgget(key, 0644);
	
	while(1){
		msgrcv(id, &msg, sizeof(msg),1,0);
		printf("%s\n", msg.txt);
	}
}
