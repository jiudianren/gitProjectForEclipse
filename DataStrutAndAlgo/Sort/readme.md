https://www.cnblogs.com/zyb428/p/5673738.html

https://www.cnblogs.com/maluning/p/7944809.html

1 ð�ݣ� 
����˼�룺�Ƚ����ڵ������������ǰ�߱Ⱥ��ߴ�����н�����ÿһ�����������ѡ��һ��δ�������������ŵ�������档


2.��������
��������˼��:ѡȡһ����׼Ԫ�أ�ͨ��Ϊ�������һ��Ԫ�أ����ߵ�һ��Ԫ�أ�����ǰ���������飬������С�ڻ�׼Ԫ�ص�Ԫ��ʱ����������ߵ�һ�����ڻ�׼Ԫ�ص�Ԫ�ؽ��н����������÷��β��Դ��Ѿ��ֺõ������зֱ�������ϲ��裬ֱ��������ɡ���ͼ��ʾ��������̡�



4 ֱ�Ӳ�������
��������˼�룺�ͽ�������ͬ���������ý��н���������������һ����ʱ�����洢��ǰֵ����ǰ���Ԫ�رȺ����ʱ���ȰѺ����Ԫ�ش�����ʱ������ǰ��Ԫ�ص�ֵ�ŵ�����Ԫ��λ�ã��ٵ�������ֵ���뵽���ʵ�����λ��
	



4 ϣ��(shell)����
��������˼��Ϊ��ֱ�Ӳ��������˼��������һ����С����dk,�տ�ʼdk����Ϊn/2�����в��������������dk=dk/2,�ٽ��в�������ֱ��dkΪ1ʱ������һ�β������򣬴�ʱ�����������


ֱ��ѡ������
����˼�룺����ѡ��������С�����ŵ������ǰ�档���ȴ�����ĵڶ���Ԫ�ؿ�ʼ����������ҳ���С�����ŵ���һ��λ�á��ٴ�ʣ���������ҳ���С�����ŵ��ڶ���λ�á��Դ����ƣ�ֱ����������

	void SelectSort(elemtype R[], int n) {
	    int i, j, m;
	    elemtype t;
	    for (i = 0; i < n - 1; i++) {
	        m = i;
	        for (j = i + 1; j < n; j++)
	            if (R[j] < R[m]) m = j;
	        if (m != i) {
	            t = R[i];
	            R[i] = R[m];
	            R[m] = t;
	        }
	    }
	}