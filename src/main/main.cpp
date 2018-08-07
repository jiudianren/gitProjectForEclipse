
/*
 * ubuntu 提示找不到 io.h头文件
 *  find /usr/include -name "io.h"
/usr/include/x86_64-linux-gnu/sys/io.h

access 的头文件是#include <unistd.h> 不是 io.h
/usr/include下没有，但是在/usr/include/sys下有，我把io.h复制到了/usr/include下，就行了

  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <string>
#if 0
#include "za/Tip.h"
#include "za/virtualFuction.h"
#include "za/struct.h"
#include "za/PointerAndRef.h"
#include "za/duck.h"
#include "za/FuncPointer.h"
#include "za/SmartPointer.h"
#include "za/testiostream.h"
#include "za/char.h"
#include "za/Define.h"
#include "za/test.h"
#include "za/MyMapTest.h"
#include "za/copyControl.h"
#include "za/Diameter.h"
#include "za/LeftRef.h"
#include "za/CallBack.h"
#include "za/VirtualTest2.h"
#include "za/SmarPoint11.h"
#include "za/debugTest.h"
#include "za/OpreatorReload.h"
#include "za/TypeInfo.h"
#include "za/zaa.h"
#include "za/bind.h"
#include "za/testTuple.h"
#include "za/DateTest.h"
#include "za/MostVexingParse.h"

#endif
#include "Huanchongqu.h"

int main( int argc, char **argv)
{

	mainHCQ();
	return 1;
}
