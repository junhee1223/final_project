#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>

struct msgbuf {
	long mtype;
	char msgtxt[200];
};

int main(void) {

	struct msgbuf msg;
	int msgid;
	key_t key;

	if((key=ftok("messagesend.c",'b'))== -1) {
		perror("key");
		exit(1);
	}

	if((msgid = msgget(key,0644))==-1) {
		perror("msgid");
		exit(1);
	}


	//for( ; ;) {
	while(1){
		if(msgrcv(msgid,&msg,sizeof(msg),1,0)==-1) {
			perror("msgrcv");
			exit(1);
		}
		if(strcmp(msg.msgtxt, "fuck") == 0) {
			printf("orignal: %s change: **** \n", msg.msgtxt);
		}else if(strcmp(msg.msgtxt, "ass") == 0) {
			printf("orignal: %s change: *** \n", msg.msgtxt);
		}else if(strcmp(msg.msgtxt, "nigger") == 0) {
			printf("orignal: %s change: ****** \n", msg.msgtxt);
		}else if(strcmp(msg.msgtxt, "damn") == 0) {
			printf("orignal: %s change: **** \n", msg.msgtxt);
		}else if(strcmp(msg.msgtxt, "bitch") == 0) {
			printf("orignal: %s change: ***** \n", msg.msgtxt);
		}else
		printf("%s\n",msg.msgtxt);
	};


	return 0;
}		 
