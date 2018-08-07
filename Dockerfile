FROM ubuntu:latest
 
 
#no git 
MAINTAINER  jiudiaren <lianpengfei12@foxmail.com>
 
RUN apt-get update
RUN apt-get -y install g++ cmake 
RUN  mkdir -p  /home/git/gitProjectForEclipse/src
COPY src  /home/git/gitProjectForEclipse/src/
RUN  mkdir  /home/git/gitProjectForEclipse/src/build

WORKDIR  /home/git/gitProjectForEclipse/src/build
RUN     cmake -DCMAKE_INSTALL_PREFIX=./ -DCMAKE_BUILD_TYPE=Debug -DCMAKE_C_COMPILER=`which gcc` -DCMAKE_CXX_COMPILER=`which c++` ..
RUN     make install
ENV     LD_LIBRARY_PATH  /home/git/gitProjectForEclipse/src/build/lib:$LD_LIBRARY_PATH

CMD ["/home/git/gitProjectForEclipse/src/build/bin/main"]