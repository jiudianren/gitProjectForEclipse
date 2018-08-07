SOURCE = $(wildcard *.cpp)

OBJS = $(patsubst %.cpp,%.o,$(SOURCE))

TARGET  := libTempleTest.so

# 编译规则		
all: EHO $(OBJS)  
	echo $(SOURCE)
	echo $(OBJS)
#	$(CXX) ${CXXFLAGS}  -o  $(OBJS)

PHONY : clean install EHO
clean :
	-rm    *.o *so

# 生成 。so文件
install:EHO
	$(CXX) ${CXXFLAGS}  ${SHARE} ${TARGET}  $(OBJS)
	cp   *.so  ${BUID_DIR}

EHO:
	echo ${LpfExport}
	@echo $(SOURCE)
	@echo $(OBJS)
	echo ${CXXFLAGS}
	echo ${SHARE}