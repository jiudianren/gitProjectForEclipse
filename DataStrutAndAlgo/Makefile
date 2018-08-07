# 声明一个变量 Source
#使用该变量时 用 $()  ${}来引用一个变量  如 ${SOURce}
#  $(wildcard *.cpp) 调用一个函数
#  wildcard 是函数名   *.cpp是参数  

SOURCE = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp,%.o,$(SOURCE))

# 编译选项	
# CC Compiler Flags  
#export的变量，可以向下传递
export CXXFLAGS=  -g -Wall -std=c++11   
export SHARE   := -fPIC -shared -o


# 默认关闭
export GLINUX=ON
ifeq ($(GLINUX),  ON)
else
endif

TARGET  := DataStructAndAlgo

currentFile:$(OBJS)

# 编译规则		
all: 
	echo $(SOURCE)
	echo $(OBJS)
	currentFile


PHONY : clean install EHO
clean :
	-rm    *.o 


install:EHO
	$(CXX) ${CXXFLAGS}  ${LGTEST}  -lpthread -o ${TARGET}  $(OBJS)   

EHO:
	@echo $(INCLUDES)
	@echo $(SOURCE)
	@echo $(OBJS)
	echo ${CXX}
	echo ${CXXFLAGS}
	echo ${ROOT_DIR}
	echo ${MAKE} 
	echo ${BUID_DIR}


