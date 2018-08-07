
# 声明一个变量 Source
#使用该变量时 用 $()  ${}来引用一个变量  如 ${SOURce}
#  $(wildcard *.cpp) 调用一个函数
#  wildcard 是函数名   *.cpp是参数  

SOURCE = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp,%.o,$(SOURCE))

# 编译选项	
# CC Compiler Flags  
#export的变量，可以向下传递
export CXXFLAGS=  -g -Wall -std=c++11 -fPIC -lpthread


#默认关闭，通过make 命令注入 make GTEST=ON/OFF
export GTest_HOME=/home/phub/googletest/googletest
export GMock_HOME=/home/phub/googletest/googlemock
export LGTEST = 
export GTEST =OFF
ifeq ($(GTEST), ON)
	export INCLUDES = -I $(GTest_HOME)/include -I $(GMock_HOME)/include
	LGTEST = -lpthread -lrt -L $(GTest_HOME)/lib -lgtest -L ${GMock_HOME}/lib -lgmock
	CXXFLAGS+= -DGTEST $(INCLUDES) 
else
	
endif

# 默认关闭
export MYLDDFILES = 
export GLINUX=OFF
ifeq ($(GLINUX),  ON)
	export MYLDDPATH =/home/phub/gitPro/src/Build
	MYLDDFILES += -L$(MYLDDPATH) -lDataStrutAndAlgoTest   -lSTLTest -lTempleTest -lthreadTest -lza
else
endif


export SHARE   := -fPIC -shared -o
#export 变量可以传到 子makefile当中来
export LpfExport= lpfvarforsubfile

ROOT_DIR=$(shell pwd)
# 手动书写 子目录  也可以用脚本来获得
#+= 


SUB_DIR += ./za

SUB_DIR += ./Build
export BUID_DIR=${ROOT_DIR}/Build
#自动获取
#debug文件夹里的makefile文件需要最后执行，所以这里需要执行的子目录要排除debug文件夹，这里使用awk排除了debug文件夹，读取剩下的文件夹
SUBDIRS=$(shell ls -l | grep ^d | awk '{if($$9 != "debug") print $$9}')

# :=值得一提的是，这种方法，前面的变量不能使用后面的变量，只能使用前面已定义好了的变量
NOTHING :=


#  @使命令在被执行前不被回显。
# 命令 包
#如果 Makefile 中出现一些相同命令序列， 那么我们可以为这些相同的
#命令序列定义一个变量。定义这种命令序列的语法以“define”开始，
# 以“endef”结束，



# $1表示 调用该命令是，传入的第一个参数
define make_subdir
@for subdir in $(SUB_DIR) ; do \
( cd $$subdir && make $1) \
done;
endef


# 编译规则		all 目标依赖于三个 目标 
all: EHO  subFiles  currentFile


#  编译失败就退出   http://blog.csdn.net/zahuopuboss/article/details/46310859


# $@ 自动化变量  
#"$@"表示所有的目标的挨个值，"$<"表示了所有依赖目标的挨 个值。
# 这些奇怪的变量我们叫"自动化变量"，后面会详细讲述
# $< 表示把 依赖取出来 作为值用
#   || exit "$$?" 表示，子目录的makefile 执行出错，就停止编译
subFiles:${SUB_DIR}
	@for dir in $(SUB_DIR); do \
		$(MAKE) -C $$dir   || exit "$$?" ; \
	done 
	echo $@
	echo $<
	echo ${SUB_DIR}


# 注意 all 依赖于 currentFile currentFile依赖于 $(OBJS) 
#$(OBJS) 依赖于每一个。o文件 ，每一个点o文件依赖于 每一个。cpp  由。
#cpp生成。o文件，是调用隐式的推导规则产生的
currentFile:$(OBJS)
#  依赖 所有 $< 生成  $@
#	$(CXX) ${CXXFLAGS}   -o $@  $<
######################
#
#currentFile 这个规则也可以写成
#${SUB_DIR} 
#	$(CXX)  -o $@
#################	



#-rm   *.o  如果没有文件，会返回错误
#-rm  -f *.o  如果没有文件，就会跳过 
.PHONY : clean  EHO install
clean:
	-rm  -f *.o  *.so
	$(call make_subdir , clean) 
	

install :
	-cp  *o   ${BUID_DIR}
	$(call make_subdir , install)



# 我们用“@”字符在命令行前，那么，这个命令将不被 make 回显
EHO:
	echo ${LpfExport}
	@echo ${testvar}
	@echo $(GTEST)
	@echo $(INCLUDES)
	@echo $(SOURCE)
	@echo $(OBJS)
	echo ${CXX}
	echo ${CXXFLAGS}
	echo ${ROOT_DIR}
	echo ${SUB_DIR}
	echo ${SUBDIRS}
	echo ${MAKE} 
	echo ${SHARE}
	echo ${BUID_DIR}