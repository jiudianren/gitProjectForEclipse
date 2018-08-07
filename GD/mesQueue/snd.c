/*
 * snd.c
 *
 *  Created on: 2016年8月8日
 *      Author: Administrator
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/msg.h>
#define MAX_TEXT 512

#define MSGKEY 1024
struct my_msg_st {
	long int my_msg_type;
	char some_text[MAX_TEXT];
};
int main()
{
	int i = 10;
	int running = 1;
	struct my_msg_st some_data;
	int msgid;
	char buffer[BUFSIZ];
	msgid = msgget(MSGKEY, 0666 | IPC_CREAT);//0666表示相关的权限
	if (msgid == -1) {
		fprintf(stderr, "msgget failed with error: %d\n", errno);
		exit(EXIT_FAILURE);
	}
	while(running) {
		printf("Enter some text: %d", BUFSIZ);
		fgets(buffer, BUFSIZ, stdin);
		some_data.my_msg_type = i--;
		printf("msg_type %d .   ",some_data.my_msg_type);
		strcpy(some_data.some_text, buffer);

		if (msgsnd(msgid, (void *)&some_data, MAX_TEXT, 0) == -1) {
			fprintf(stderr, "msgsnd failed\n");
			exit(EXIT_FAILURE);
		}
		if (strncmp(buffer, "end", 3) == 0) {
			running = 0;
		}
	}
	exit(EXIT_SUCCESS);
}
