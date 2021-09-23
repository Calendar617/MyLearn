#include "qsort.h"

/*
ѡ��Key,�����в�ֳ����Σ���֤���С��key,�Ҳ����key����key���м�ֵ����
�������Ҳ�ֱ�������ѭ��ִ�в��裬ֱ�����е����������������
�ݹ�ʵ��
�ǵݹ�ʵ�֣���stack��¼ÿ��������left,right
�����Ż�
1.����ȡ�з�
  ѡ��key,ѡ�����е�һ���м䣬��� ����ֵ���м�ֵ
2.ֱ�Ӳ��뷨
  ������бȽ�С������ֱ��ʹ�ò�������
*/
int qsort::paritition(vector<int>& data, int left, int right)
{
	int key = data[left];
	while (left < right)
	{
		while (left < right && data[right] >= key)
		{
			--right;
		}
		data[left] = data[right];
		while (left < right && data[left] <= key)
		{
			++left;
		}
		data[right] = data[left];
	}
	data[left] = key;
	return left;
}

void qsort::sort(vector<int>& data, int left, int right)
{
	if (left < right)
	{
		int key = paritition(data, left, right);
		sort(data, left, key - 1);
		sort(data, key + 1, right);
	}
}
