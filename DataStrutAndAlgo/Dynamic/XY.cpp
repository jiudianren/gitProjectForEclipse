/*
 * XY.cpp
 *
 *  Created on: 2019��3��12��
 *      Author: lian.pengfei
 */




/*x,y
 * xֻ���ߵ�ǰ��y�������Ǵ�x�ߵ�x+y
 * yֻ���ߵ�ǰ��x�������Ǵ�y�ߵ�y+x
 *
 * */



bool step( int x,int y ,int xx ,int yy)
{
    if(x > xx ||  y >yy)
    {
        return false;
    }

    if( x==xx && y== yy)
    {
        return true;
    }

    bool bRet = false;
    int temp = x+y;
    if( temp <= xx)
    {
        x=temp;
        bRet =  step(x,y ,xx,yy );
    }

    if(!bRet )
    {
         y=temp;
        bRet=  step(x,y ,xx,yy );
    }
    return ret;
}
