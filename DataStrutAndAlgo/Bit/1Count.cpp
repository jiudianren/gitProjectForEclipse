/*
 * 1Count.cpp
 *
 *  Created on: 2018��11��7��
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



//˼·����xת��Ϊ2���ƣ������е�1�ĸ�����
//�ٶ�x=6����Ϊ2��
//�ٶ�x = 9999����Ϊ8��



