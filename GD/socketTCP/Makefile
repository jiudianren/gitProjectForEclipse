all:sst  cct


#sst cct IS MAIN FOR SHOW 

sst:pthread_server.c
	gcc -g -Wall pthread_server.c  -o sst  -lpthread

cct:pthread_client.c
	gcc  -g pthread_client.c   -o cct


#ss:ser.c
#	gcc  -g ser.c  -o ss  
#
#cc:clie.c
#	gcc  -g clie.c   -o cc

clean:
	rm -f ss	cc  sst cct