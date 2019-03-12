/*
 * XY.cpp
 *
 *  Created on: 2019年3月12日
 *      Author: lian.pengfei
 */




/*x,y
 * x只能走当前的y步，就是从x走到x+y
 * y只能走当前的x步，就是从y走到y+x
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
