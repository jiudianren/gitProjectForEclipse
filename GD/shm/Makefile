all:shmr shmw
shmr:shmread.c shmdata.h
	gcc shmread.c shmdata.h -o shmr

shmw:shmwrite.c
	gcc shmwrite.c  shmdata.h -o shmw

clean:
	rm -f shmr	shmw  