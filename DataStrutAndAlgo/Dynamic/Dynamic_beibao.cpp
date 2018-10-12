

#include "Dynamic_beibao.h"

#include <iostream>
#include <fstream>
using namespace std;
/*
 * https://www.cnblogs.com/sdjl/articles/1274312.html
 * */

/*
 * ����Ƕ�̬�滮��
 * ���С������ӽṹ�������������ص��������߽硱�͡��������������
 * ���㷢��������˼��������߱����ĸ����ʵĻ���
 * ��ô��ϲ�㣬��������Ѿ��ҵ��˶�̬�滮�ķ���
 *
 *       �����ṩ�������ĳ���Դ�������������⣬���ṩ�������ݸ������ϰ��
       �����ļ���Ϊ��beibao.in������Ϊ�������ʵ���Ͼ��Ǳ������⣬���Բ��������ļ����ͱ���ԭ���ɡ�
       �����ļ���һ��������������һ���ǹ��������������ɽ������������ڶ������ܹ����ֵĽ������
       �����ļ��ĵ�2��n+1��ÿ��������������i�е��������ֱ��ʾ��i-1�������Ҫ�������Ϳ��Եõ��Ľ�������
       ����ļ���һ����������ʾ�ܹ��õ�������������

       ����������

       100 5
       77 92
       22 22
       29 87
       50 46
       99 90

       ���������
       133
  */


const int max_n = 100;//����֧�ֵ��������
const int max_people = 10000;//����֧�ֵ��������


int n;//�����
int peopleTotal;//���������ڽ��ӵ�����
int peopleNeed[max_n];//ÿ�������Ҫ������
int gold[max_n];//ÿ������ܹ��ڳ����Ľ�����
int maxGold[max_people][max_n];//maxGold[i][j]������i������ǰj������ܹ��õ�����������������-1ʱ��ʾδ֪

//��ʼ������
void init()
{
    ifstream inputFile("beibao.in");
    inputFile>>peopleTotal>>n;
    for(int i=0; i<n; i++)
        inputFile>>peopleNeed[i]>>gold[i];

    inputFile.close();

    for(int i=0; i<=peopleTotal; i++)
        for(int j=0; j<n; j++)
            maxGold[i][j] = -1;//����-1ʱ��ʾδ֪ [��Ӧ��̬�滮�еġ�������¼��]

}

//����ڽ���people���˺�ǰmineNum�����ʱ�ܹ��õ�������������ע�⡰ǰ���ٸ���Ҳ�Ǵ�0��ʼ��ŵ�
int GetMaxGold(int people, int mineNum)
{

    cout<<"GetMaxGold start "<< "People : "<< people <<" minNum: "<< mineNum <<std::endl;
    //�������ص���������
    int retMaxGold;

    //�������������������  [��Ӧ��̬�滮�еġ�������¼��]
    if(maxGold[people][mineNum] != -1)
    {
        //��ñ���������ֵ
        retMaxGold = maxGold[people][mineNum];
    }
    else if(mineNum == 0)//�������һ�����ʱ [��Ӧ��̬�滮�еġ��߽硱]
    {
        //�������������㹻�����������
        if(people >= peopleNeed[mineNum])
        {
            //�õ������ֵ�����������Ľ�����
            retMaxGold = gold[mineNum];
        }
        else//������Ψһ��һ�����Ҳ���ܿ���
        {
            //�õ������ֵΪ0������
            retMaxGold = 0;
        }
    }
    else if(people >= peopleNeed[mineNum])//����������˹������������ [��Ӧ��̬�滮�еġ������ӽṹ��]
    {
        //���ǿ����벻�������������ȡ���ֵ
        retMaxGold = max(
                          GetMaxGold(people - peopleNeed[mineNum],mineNum -1) + gold[mineNum],
                          GetMaxGold(people,mineNum - 1)
                         );
    }
    else//����������˲�������������� [��Ӧ��̬�滮�еġ������ӽṹ��]
    {
        //�����ǲ����ɵ����
        retMaxGold  = GetMaxGold(people,mineNum - 1);
    }

    //������¼
    maxGold[people][mineNum] = retMaxGold;

    cout<<"GetMaxGold end "<< "People : "<< people <<" minNum: "<< mineNum <<"retMaxGold: "<<retMaxGold <<std::endl;
    return retMaxGold;
}

int mainBeiBao()
{
    //��ʼ������
    cout<<"mainBeiBao =============start "<<std::endl;
    init();
    //�������peopleTotal���˺�n������ܹ���õ������������ٴ����ѱ�Ŵ�0��ʼ���������һ�������Ϊn-1
    cout<<GetMaxGold(peopleTotal,n-1)<<std::endl;
    cout<<"mainBeiBao =============end"<<std::endl;
    return 0;
}
