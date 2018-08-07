export GTest_HOME=/home/phub/googletest/googletest
export GMock_HOME=/home/phub/googletest/googlemock

echo $GTest_HOME
echo $GMock_HOME
export PATH=$GTest_HOME/lib:$GMock_HOME/lib:$PATH

echo $PATH
export C_INCLUDE_PATH=$GMock_HOME/include:$GTest_HOME/include:$C_INCLUDE_PATH
export CPLUS_INCLUDE_PATH=$GMock_HOME/include:$GTest_HOME/include:$CPLUS_INCLUDE_PATH
# ¾²Ì¬Á´½Ó¿â
echo   jinttailianjikeku 
export LIBRARY_PATH=$GMock_HOME/lib:$GTest_HOME/lib:$LIBRARY_PATH
echo $LIBRARY_PATH
# ¶¯Ì¬Á´½Ó¿â
echo dongtailianjieku
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH
echo $LD_LIBRARY_PATH
echo 'g++  -I /home/phub/googletest/googletest/include -I /home/phub/googletest/googlemock/include   -o sm SimpleTest.cpp Simple1.o -lgtest  -lgmock -lrt -lpthread'