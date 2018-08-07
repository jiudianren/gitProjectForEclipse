/*
 * zk_test.cpp
 *
 *  Created on: 2018��5��2��
 *      Author: Administrator
 */

/*
 * https://blog.csdn.net/lpshoucsd1/article/details/8984762

 *10.45.7.168:2181
 *
 * */

/*
 * Zookeeper C API ָ����(ͬ�� API ����)
 *
 *
 * */


#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>

#include "zk_test.h"
using std::cout;
using std::string;
using std::endl;

//myRoot Path
string myRPath="/lpf";


#define P_FUNC_NAME(fc_name)  std::cout<<#fc_name<< "=================" <<std::endl


void CheckReturnFlag(int flag)
{

    switch( flag)
    {
        case ZOK:
        {
            cout<<"ZK:operation completed successfully.";
            break;
        }
        case  ZNONODE :
        {
            cout<<"ZK:the node does not exist.";
            break;
        }

        case  ZNOAUTH :
        {
            cout<<"ZK:the client does not have permission.";
            break;
        }

        case  ZBADARGUMENTS:
        {
            cout<<"ZK:Invalid arguments.";
            break;
        }

        case  ZCONNECTIONLOSS:
        {
            cout<<"ZK:Connection to the server has been lost.";
            break;
        }
        case  ZNODEEXISTS:
        {
            cout<<"ZK:The node already exists.";
            break;
        }
        default :
        {
            cout<<" Check the  flag!!!!! ,flag ="<<flag ;
        }

    }

    cout<<endl;
}





void zktest_watcher_g(zhandle_t* zh, int type, int state, const char* path, void* watcherCtx)
{

    cout<<" zktest_watcher_g start ================="<<endl;

    printf("type: %d\n", type);
    printf("state: %d\n", state);
    printf("path: %s\n", path);
    printf("watcherCtx: %s\n", (char *)watcherCtx);

    printf("zktest_watcher_g over ====================\n");

}
//�Լ��ļ�������
void watcher_myself(zhandle_t *zh,int type,int state,const char *path,void *watcherCtx)
{
    cout<<"  !!!watcher_myself ======" <<endl;
    cout<<"  path:%s" <<path <<endl;
    string ss( (char *)watcherCtx);
    cout<< "watcherCtx" << ss <<endl;

}
//ͬ����ʽ�����ڵ�
void create(zhandle_t *zkhandle, const char *str)
{
    char path_buffer[128];
    int bufferlen=sizeof(path_buffer);

    P_FUNC_NAME(create);
    cout<<"creat "<<str<<endl;

    string sValue ("zk_test.cpp");


    /*
     * ��Ϊ������ ZOO_SEQUENCE �� zoo_create �������Ľڵ���������� path �ṩ�����Ʋ�ͬ��
     * �µĽڵ����ƺ����������ţ���path �ַ����� NULL ������
     * path_buffer ��������Ϊ NULL����ʱ path_buffer_len ���� 0��
     *
     *  */
    int flag = zoo_create(zkhandle,str, sValue.c_str(), sValue.size() ,  &ZOO_OPEN_ACL_UNSAFE,0,
                          path_buffer,bufferlen);


    CheckReturnFlag( flag );

    if (flag ==ZOK ||  flag== ZNODEEXISTS)
    {
        cout<<"  node name"<< path_buffer << endl;
    }
    else
    {
        cout<<"  failed "<< path_buffer << endl;
        exit(EXIT_FAILURE);
    }

    P_FUNC_NAME(create);
}
//ͬ����ʽ��ȡ�ڵ�����
void get(zhandle_t* zkhandle  ,const char *str )
{
    P_FUNC_NAME(get);
    cout<<"get " << str << endl;

    const int max_buffer_len = 1024 * 100;
    char buffer1[max_buffer_len] =  { '\0' } ;
    int bufferlen1=sizeof(buffer1);


    Stat  myStat;
    int flag1 =zoo_get(zkhandle, str , 0, buffer1, &bufferlen1,NULL);

    if (flag1 == ZOK)
    {
        printf("the data of the root: %s\n",buffer1);
    }
    P_FUNC_NAME(get);
}
//exists


void exists(zhandle_t *zkhandle,char *str)
{
    int flag = zoo_exists(zkhandle,str, 1, NULL);
}

bool wexists(zhandle_t *zkhandle, const char *str)
{
    P_FUNC_NAME(wexists);
    cout<<" check "<<str <<" exit or not"<<endl;

    string watcherCtx ("this watcherCtx is a string");

    int flag=zoo_wexists(zkhandle, str, watcher_myself, (void *) watcherCtx.c_str(),NULL);
    CheckReturnFlag(flag);
    if( flag == ZOK )
    {
        return true;
    }
    else
    {
        return false;
    }
}

//ͬ����ʽ����ӽڵ���Ϣ
void getChildren(zhandle_t *zkhandle, const char *str)
{
    P_FUNC_NAME(getChildren);
    cout<<"get children of "<<str<<endl;

    struct String_vector strings;
    struct Stat stat;
    int flag  = 0;
    flag  = zoo_wget_children2(zkhandle, str,  watcher_myself, "testgetChildren",  &strings,&stat);
    CheckReturnFlag(flag);
    if (flag ==ZOK)
    {
        int32_t i=0;
        for (;i<strings.count;++i)
            printf("%s\n",strings.data[i]);
    }

    P_FUNC_NAME(getChildren);
}
//��ȡACL��Ϣ
void getACL(zhandle_t *zkhandle,const char *str)
{

    P_FUNC_NAME(getACL);
    cout<<"get ACL of "<< str<<endl;

    struct ACL_vector acl;
    struct Stat stat;
    int flag = zoo_get_acl(zkhandle,str,&acl,&stat);
    if (flag==ZOK)
    {
        printf("-----------------the ACL of %s:------------ \n",str);
        printf("%d\n",acl.count);
        printf("%d\n",acl.data->perms);
        printf("%s\n",acl.data->id.scheme);
        printf("%s\n",acl.data->id.id);
    }

    P_FUNC_NAME(getACL);

}
//ɾ���ڵ�
void mydelete(zhandle_t *zkhandle, const char *str)
{
    P_FUNC_NAME(mydelete);

    int flag  = 0;
    flag= zoo_delete(zkhandle,str,-1);

    CheckReturnFlag( flag);

    P_FUNC_NAME(mydelete);
}

void setWatch( zhandle_t *zkhandle, const char *str )
{
    P_FUNC_NAME(setWatch);
    cout<<"set watch "<< str<<endl;

    const int max_buffer_len = 1024 * 100;
    char buffer1[max_buffer_len] =  { '\0' } ;
    int bufferlen1=sizeof(buffer1);
    string watcherCtx ("this watcherCtx is a string");

//    zoo_get(zkhandle,str , 1, buffer1, &bufferlen1,NULL);
//    zoo_wget(zkhandle,str , watcher_myself, (void *)watcherCtx.c_str(),buffer1, &bufferlen1,NULL);
    zoo_wexists(zkhandle, str, watcher_myself, (void *) watcherCtx.c_str(),NULL);

    P_FUNC_NAME(setWatch);
}


int main(int argc, const char *argv[])
{
    //    const char* host = "10.45.7.168:2181";
    const char* host = "172.18.184.90:2181";
    int timeout = 30000;
    char buffer[512];
    int *bufferlen;

    zoo_set_debug_level(ZOO_LOG_LEVEL_INFO); //������־����,�������һЩ������Ϣ

    void * context = NULL;
    zhandle_t* zkhandle = zookeeper_init( host, zktest_watcher_g, timeout, 0, context , 0);

    if (zkhandle == NULL)
    {
        fprintf(stderr, "Error when connecting to zookeeper servers...\n");
        exit(EXIT_FAILURE);
    }

    setWatch(zkhandle , myRPath.c_str());
    //һ��
    create( zkhandle,  myRPath.c_str() );

    //��ɾ����������watch �ٴ���
    string myCreat="/lpf/gitPro";
    if ( wexists(zkhandle,  myCreat.c_str()) )
    {
        mydelete( zkhandle,  myCreat.c_str() );
    }

    setWatch(zkhandle ,   myCreat.c_str());
    create( zkhandle,  myCreat.c_str() );

    /*������ watch �� API(exists(����) + get(����) + get_children(�ĸ�) = �˸�)
     * */
    get(zkhandle, myRPath.c_str());

    getACL(zkhandle, myCreat.c_str());
    getChildren(zkhandle, myCreat.c_str());
    printf("END. \n");
    printf("Test Wathcher. \n");
}
