/*
 * TestM.cpp
 *
 *  Created on: 2018年5月9日
 *      Author: Administrator
 */



#include "Deal.h"
#include "Show.h"
#include <algorithm>
using namespace std;

bool CheckGameOver( int data [SCALE][SCALE] )
{
    bool bRet= true;

    for(int i =0 ;i <SCALE ;i++ )
    {
        for( int k =0; k<SCALE; k++)
        {
            if(  data[i][k] ==0)
            {
                bRet =false;
                break;

            }
        }
    }
    return bRet;
}

void DealData(DIRCT dir, int data [SCALE][SCALE], GINFO  & info )
{


    switch (dir)
    {
        case  DIRCT::RIGHT :
        {
            DealRight(data);
            break;
        }

        case  DIRCT::LEFT :
        {
            DealLeft(data);
            break;
        }

        case  DIRCT::UP :
        {
            DealUp(data);
            break;
        }

        case  DIRCT::DOWN :
        {
            DealDown(data);
            break;
        }
    }


    DealInfo(data, info);
    GenerateNewEle(data, dir );

}


void DealInput( int data [SCALE][SCALE], GINFO  & info)
{
    char input="h";
    DIRCT dir=DIRCT::RIGHT;
    while(cin.get(input) )
    {
        switch(input)
        {
            case 'q':
            case 'Q':
            {
                cout<<"It is goning to exit."<<endl;
                exit(0);
                break;
            }

            case 'j':
            case 'J':
            {
                dir=DIRCT::LEFT;
                break;
            }

            case 'i':
            case 'I':
            {
                dir=DIRCT::UP;
                break;
            }

            case 'K':
            case 'k':
            {
                dir=DIRCT::DOWN;
                break;
            }
            case 'L':
            case 'l':
            {
                dir=DIRCT::RIGHT;
                break;
            }


            case 'r':
            case 'R':
            {
                Reset(data, info);
                break;
            }
        }


        DealData( dir, data, info );
        show(data, info);

        auto it =info.find(GINFO_INDEX::ALIVE );
        if(  it != info.end() &&  it->second == 0)
        {
            cout<<"ATTION:  G.A.M.E. O.V.E.R !!!  "<<endl;
        }

        cout<<"input again:  "<<endl;
    }
}

//从上次处理的另外一个角上生成新的元素，应该综合两次操作来生成
/*
 * 新元素放置区域 计算
 *
 *
 * */
void GenerateNewEle(int data [SCALE][SCALE], DIRCT dir )
{

    cout<<"TODO GenerateNewEle"<<endl;
    AREA area = GetTheArea(dir);
    InsertCorner( area, data);
}



void InsertCorner(  AREA area ,  int data [SCALE][SCALE])
{
    //现在定点产生，后续优化成在可用区间随机化产生
    int noUse=0;
    int & temp = noUse;

    switch(area )
    {
        case  AREA::LEFTUP :
        {
            temp  =   data[0][0];
            if( temp !=0)
            {
                cout<<"!!! checke the GetTheArea() ";
                exit(0);
            }
            temp =2;
            break;
        }
        case  AREA::LEFTDOWN :
        {
            data[SCALE-1][0];


            break;
        }
        case  AREA::RIGHTUP :
        {
            temp  =  data[0][SCALE-1];
            break;
        }
        case  AREA::RIGHTDOWN :
        {
            temp  =   data[SCALE-1][SCALE-1];
            break;
        }
    }

    if( temp !=0)
    {
        cout<<"!!! checke the GetTheArea() ";
        exit(0);
    }
    temp =2;

}

AREA GetTheArea(DIRCT dir, bool bClear )
{

    /*决定在哪个区域，产生新元素*/
    static deque<int> dirs;
    static  AREA oldAre = 0;

    if ( bClear)
    {
        dirs.clear();
        oldAre =0;
    }
    if( dirs.size() == 2)
    {
        dirs.pop_front();
    }
    else if ( dirs.size() > 2)
    {
        cout<<"Erro !!!"<<endl;
    }
    dirs.push_back(dir);

    //第一步之后
    if(dirs.size() ==1)
    {
        return AREA::LEFTUP;
    }


#if ( DEBUG == 1)
    cout<<" [1]: "<< GetDirtString( (DIRCT)dirs[0]) ;
    cout<<" [2]: "<< GetDirtString( (DIRCT)dirs[0]);
    cout<<" odeaer: "<< GetAreaString( oldAre);
#endif


    int area = 0;

    //两步一样 ，返回原值
    if( dirs[0]== dirs[1] )
    {
        area=oldAre;
    }
    else
    {
        switch( dirs[0])
        {
            case DIRCT::DOWN :
            {
                if( dirs[1] == DIRCT::RIGHT )
                {
                    area =AREA::LEFTUP;
                }
                else if( dirs[1] == DIRCT::LEFT )
                {
                    area =AREA::LEFTUP;
                }
                else if( dirs[1] == DIRCT::UP )
                {
                    if(  oldAre == AREA::LEFTUP)
                    {
                        area =LEFTDOWN;
                    }
                    else if (  oldAre == AREA::RIGHTUP)
                    {
                        area =RIGHTDOWN;
                    }
                }
                break;
            }

            case DIRCT::UP :
            {
                if( dirs[1] == DIRCT::RIGHT )
                {
                    area =AREA::LEFTDOWN;
                }
                else if( dirs[1] == DIRCT::LEFT )
                {
                    area =AREA::RIGHTDOWN;
                }
                else if( dirs[1] == DIRCT::DOWN )
                {
                    if(  oldAre == AREA::LEFTDOWN)
                    {
                        area =LEFTUP;
                    }
                    else if (  oldAre == AREA::RIGHTDOWN)
                    {
                        area =RIGHTUP;
                    }
                }
                break;
            }



            case DIRCT::RIGHT :
            {
                if( dirs[1] == DIRCT::UP )
                {
                    area =AREA::LEFTDOWN;
                }
                else if( dirs[1] == DIRCT::DOWN )
                {
                    area =AREA::LEFTUP;
                }
                else if( dirs[1] == DIRCT::LEFT )
                {
                    if(  oldAre == AREA::LEFTDOWN)
                    {
                        area =AREA::RIGHTDOWN;
                    }
                    else if (  oldAre == AREA::LEFTUP)
                    {
                        area =AREA::RIGHTUP;
                    }
                }
                break;
            }


            case DIRCT::LEFT :
            {
                if( dirs[1] == DIRCT::UP )
                {
                    area =AREA::RIGHTDOWN;
                }
                else if( dirs[1] == DIRCT::DOWN )
                {
                    area =AREA::RIGHTUP;
                }
                else if( dirs[1] == DIRCT::RIGHT )
                {
                    if(  oldAre == AREA::RIGHTDOWN)
                    {
                        area =AREA::LEFTDOWN;
                    }
                    else if (  oldAre == AREA::RIGHTUP)
                    {
                        area =AREA::LEFTUP;
                    }
                }
                break;
            }

        }
    }

    oldAre = area;

#if ( DEBUG == 1)
    cout<<" Result AREA: "<< GetAreaString( oldAre);
    cout<<endl;
#endif
    return area;
}


void Reset(int data [SCALE][SCALE], GINFO  & info)
{

    cout<<"TODO reset"<<endl;

}
void DealInfo(int data [SCALE][SCALE], GINFO  & info)
{

    //cout<<"DealInfo"<<endl;
    int totoal =0;
    int max=0;

    for(int i =0 ;i <SCALE ;i++ )
    {
        for( int k =0; k<SCALE; k++)
        {
            if( data[i][k] >max )
            {
                max =data[i][k];
            }

            totoal +=  data[i][k];
        }
    }

    auto it =info.find(GINFO_INDEX::Socre );
    if(   it != info.end())
    {
        it->second= totoal;
    }

    it =info.find(GINFO_INDEX::Max );
    if(  it != info.end())
    {
        it->second= max;
    }

    it =info.find(GINFO_INDEX::Step );
    if(  it != info.end())
    {
        it->second +=1;
    }

    if( CheckGameOver(data) )
    {
        it =info.find(GINFO_INDEX::ALIVE );
        if(  it != info.end())
        {
            it->second = 0;
        }

    }

}




void DealRight( int data [SCALE][SCALE] )
{

    cout<<"DealRight"<<endl;
    for(int i =0 ;i <SCALE ;i++ )
    {
        vector<int> aim;
        for( int k =0; k<SCALE; k++)
        {
            aim.push_back( data[i][k]);
        }
        Merge(aim);
        for(int j=0; j<SCALE; j++)
        {
            data[i][j] =aim[j];
        }
    }
}


void DealLeft( int data [SCALE][SCALE] )
{

    cout<<"DealLeft"<<endl;
    for(int i =0 ;i <SCALE ;i++ )
    {
        vector<int> aim;
        for( int k = SCALE -1; k>=0 ; k --)
        {
            aim.push_back( data[i][k]);
        }

        Merge(aim);
        for(int j = SCALE -1 ; j >=0; j--)
        {
            data[i][j] =aim[SCALE-1-j];
        }
    }
}

void DealDown( int data [SCALE][SCALE] )
{
    cout<<"DealDowns"<<endl;
    for(int i =0 ;i <SCALE ;i++ )
    {
        vector<int> aim;
        for( int k =0; k<SCALE; k++)
        {
            aim.push_back( data[k][i]);
        }
        Merge(aim);
        for(int j=0; j<SCALE; j++)
        {
            data[j][i] =aim[j];
        }
    }
}


void DealUp( int data [SCALE][SCALE] )
{

    cout<<"DealUp"<<endl;
    for(int i =0 ;i <SCALE ;i++ )
    {
        vector<int> aim;
        for( int k = SCALE -1; k>=0 ; k --)
        {
            aim.push_back( data[k][i]);
        }

        Merge(aim);
        for(int j = SCALE -1 ; j >=0; j--)
        {
            data[j][i] =aim[SCALE-1-j];
        }
    }
}

void inital( int data [SCALE][SCALE]  )
{
    for (int i =0 ;i < SCALE; i++)
    {
        for (int j =0 ;j  < SCALE; j++)
        {
            data[i][j]=2;
        }
    }
}

void Print( vector<int> & aim )
{
    if(aim.size() == 0)
    {
        return;
    }
    for(auto ele : aim)
    {
        cout<<ele <<" ";
    }
    cout<<endl;
}




void ClearZero( vector<int> & aim)
{
    std::vector<int>::iterator itFind;
    while (  (itFind=std::find( aim.begin(),aim.end(), 0))  != aim.end() )
    {
        aim.erase(itFind);
    }

}

//从后往前 merge
void Merge( vector<int> & aim)
{
#define DEBUG 1

    int OriginLen= aim.size();


#if ( DEBUG == 1)
    cout<<"Befor Mergee: ";
    Print(aim);
#endif

    ClearZero(aim);

#if ( DEBUG == 1)
    cout<<"MOVE: ";
    Print(aim);
#endif



    while( aim.size() > 0)
    {
        int Len= aim.size();
        int i = Len-1;

        if (i == 0)
        {
            break;
        }

        for(; i >= 1 ;i--)
        {
            if( aim[i-1]==aim[i] )
            {
                aim[i] += aim[i-1];
                aim[i-1]=0;
                ClearZero(aim);
                break;
            }
        }

        if (i == 0)
        {
            break;
        }
    }

#if ( DEBUG == 1)
    cout<<"AFTER: ";
    Print(aim);
#endif

    if( OriginLen > aim.size()   )
    {
        aim.insert( aim.begin(),  OriginLen- aim.size() ,0);
    }

#if ( DEBUG == 1)
    cout<<"MERGED: ";
    Print(aim);
#endif
}


//从前往后 merge会出问题
/*
 * 比如
 * 2 2 2 2 2
 * --》
 * 0 0 0 8 2
 * 从后往前
 * 0， 0， 2 8
 * */
void Merge2(vector<int> & aim)
{

#if ( DEBUG == 1)
    cout<<"Befor Mergee: ";
    Print(aim);
#endif

    int Len= aim.size();
    while( true)
    {
        int i=0;
        for( ; i < Len-1 ; i++)
        {
            if ( aim[i]!= 0 )
            {
                bool flag = false;
                for(int  j=i+1; j<Len; j++)
                {
                    if( aim[j]==0)
                    {
                        aim[j] = aim[i];
                        aim[i] = 0;
                        flag= true;
                        continue;
                    }
                    else if( aim[i] == aim[j])
                    {
                        aim[j] += aim[i];
                        aim[i] = 0;
                        flag= true;
                        break;
                    }
                    else
                    {
                        break;
                    }
                }

                if(flag )
                {
                    break;
                }
            }

        }
        if( i == Len-1 )
        {
            break;
        }

    }

#if ( DEBUG == 1)
    cout<<"Mergeed: ";
    Print(aim);
#endif
}

