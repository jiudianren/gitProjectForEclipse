##CHECKED_VERSION=FR3|FILE_PATH=BASEDIR/hash/
include ../Makefile.incl

clean:
	rm -f *.o  libhash.$(TRUESUFFIX)

ALL_OBJS=table.o SimpleMemPool.o

all_objs: $(ALL_OBJS)

all:	$(ALL_OBJS)
	$(AR) libhash.$(TRUESUFFIX)  $(ALL_OBJS)  $(DBLIBS) 
	echo $(VERID) >> libhash.$(TRUESUFFIX)

install: all
	cp -rf *.$(TRUESUFFIX)  $(PROJECT_DIR)/lib
