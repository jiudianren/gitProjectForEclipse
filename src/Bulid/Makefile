
SOURCE = $(wildcard *.o)
TARGET  := MyEci

# 编译规则		
all: EHO $(OBJS)  
#	$(CXX) ${CXXFLAGS}  -o  $(OBJS)

PHONY : clean install EHO
clean :
	-rm   *.so  *.o ${TARGET}


SOURCE_SO = $(wildcard *.so)

# 生成 。so文件
install:EHO
	$(CXX) ${CXXFLAGS} -lpthread -o ${TARGET}  $(SOURCE)  ${SOURCE_SO}   $(LGTEST)
	mv  *.so $(TARGET) ../

EHO:
	echo ${GLINUX}
	@echo $(LGTEST)
	@echo $(GTest_HOME)
	echo ${LpfExport}
	@echo $(SOURCE)
	@echo $(OBJS)
	echo $(MYLDDFILES)
	echo ${CXXFLAGS}
	echo ${SHARE}
	echo "this build ,nothing to make for makeall"