/*
 * 1Count.cpp
 *
 *  Created on: 2018年11月7日
 *      Author: lian.pengfei
 */



    int func(x)
    {
        int countx = 0;
        while(x)
        {
            countx ++;
            x = x&(x-1);
        }
        return countx;
    }



//思路：将x转化为2进制，看含有的1的个数。
//假定x=6，答案为2；
//假定x = 9999，答案为8。



