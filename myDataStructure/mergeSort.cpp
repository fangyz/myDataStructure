//�鲢����ָ���ǽ��������������ϵ��������кϲ���һ���������У����������Ա�������ʵ�֡�

/*�������裺
1.���ȿɽ��������п�����n������Ϊ1���������У�
2.���Ž��������зֳ�n/2������Ϊ2��1�����У�����n/2�����н�������õ�n/2������ĳ���Ϊ2��1���������У�
3.�ظ��ڶ�����ֱ���õ��������еĳ���ΪnΪֹ��

���Ͽ��Կ����ܹ��ᾭ��lbn�λ��֣�ÿ�λ��ֺ�Ҫ�Ƚ�n�Σ���ʱ�临�Ӷ�Ϊnlbn��
*/

#include"sort.h"


//���������Ŀ�ľ�����first��last��֮������ݱ������ģ�ǰ����first��mid��mid��last֮��������Ѿ��������
void Merge(int *a, int first, int mid, int last)
{
	//start1Ϊ��һ�����еĿ�ʼ������end1Ϊ��һ�����еĽ�������
	//start2Ϊ��һ�����еĿ�ʼ������end2Ϊ��һ�����еĽ�������
	int start1 = first, end1 = mid;
	int start2 = mid + 1, end2 = last;
	int k = 0, i = 0;
	//��ʱ���飬�����洢first��last�����������
	int *temp = new int[last - first + 1];
	//ִ�����whileѭ����ɱ�֤������һ�������Ѿ�ȫ������temp��
	while (start1 <= end1 && start2 <= end2)
	{
		if (a[start1] <= a[start2])
			temp[k++] = a[start1++];
		else
			temp[k++] = a[start2++];
	}

	//֮����Ҫ���������2��while������Ϊ�п��������whileִ��ʱ��
	//��һ�����е�����ֵȫ���ȵڶ���С����ôִ�����ʱ��û�н�start1��end2������ֵȫ����ֵ��temp
	//����while����С�ڵ�������Ϊ��start1=end1ʱ��ǰstart1��ֵ��û�д���temp��
	while (start1 <= end1)
		temp[k++] = a[start1++];
	while (start2 <= end2)
		temp[k++] = a[start2++];

	//����ڽ�temp��ֵ��ֵ��a
	for (i = 0; i < k; i++)
		a[first + i] = temp[i];
	delete[]temp;
}

//��������ķ���
void InitSort(int a[], int first, int last)
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		InitSort(a, first, mid);//�������
		InitSort(a, mid + 1, last);//�ұ�����
		Merge(a, first, mid, last);//�ϲ�������������
	}
}

//�鲢����
void MergeSort(int* a, int length)
{
	InitSort(a, 0, length - 1);
}






