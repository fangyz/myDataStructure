/*
�������������˼����ÿ�ν��������е�һ����¼�������������к��ʵĵط��Ա�֤��������Ȼ����
��������ɷ�Ϊֱ�Ӳ��������۰�������򡢶�·���������ϣ������
*/


#include"sort.h"

/*ֱ�Ӳ�������ÿ�δ���������ѡ���һ�����뵽�������С�
����ʱ�临�Ӷȣ�������������������������ƶ����Ƚϴ���Ϊn-1��
������������һ������ģ�n-1��ѭ���У�ÿ�ζ�Ҫ�ƶ�i+1�Σ��Ƚϴ���Ϊi    ��ʱ�临�Ӷ���O(n^2)��
���������Ļ����϶���Ҫִ��n�εģ�ÿ��ִ��ʱ�Ƚ����ƶ�������n��һ�׺�������ƽ��ʱ�临�Ӷ�Ҳ��O(n^2)��
ȱ����ʱ�临�Ӷ�Ϊn^2,Ч�ʽϵͣ��Ľ��ɴ�2���ط��Ľ���һ���ǱȽϴ���һ�����ƶ�������
*/
void DirectInsertSort(int *a, int length)
{
	if (a == NULL || length < 0)
		return;
	int i,index;
	int value;
	//����i��ѭ����ÿ��ѭ����i���뵽0~i-1����������
		for (i = 1; i < length; i++){
			if (a[i] < a[i - 1])
			{
				index = i;
				value = a[index];
				while (value<a[index-1]&&index>0)
				{
					a[index] = a[index - 1];
					index--;
				}
				a[index] = value;
			}
		}
}


//�۰�������򣬾�������������ȡ�����ݲ��뵽������ʱ�����۰��˼�룬ÿ���Ǻ��������м�������бȽϡ�
//������ֻ�Ǽ����˱ȽϵĴ������ƶ�����û�м��٣���ʱ�临�Ӷ���ȻΪO(n^2)��
void HalfInsertSort(int *a, int length)
{
	int i;
	int start = 0, end = 0, mid = 0;
	int currentIndex = 0;
	int temp = 0;
	if (a == NULL || length <= 0)
		return;
	for (i = 1; i<length; i++)
	{
		currentIndex = i;
		temp = a[i];
		end = i;
		mid = end;
		//Ŀ�����ҵ�һ��λ��mid��a[mid]>temp��a[mid-1]��С�ڻ����temp��
		while (end>start&&temp<a[end - 1])
		{
			mid = (start + end) / 2;
			if (a[mid]>temp)
				end = mid;
			else
			{
				if (start == mid)
				{
					mid++;
					break;
				}
				start = mid;
			}
		}
		for (; currentIndex>mid; currentIndex--)
			a[currentIndex] = a[currentIndex - 1];
		a[currentIndex] = temp;
	}
}

/*ϣ��������һ�ַ�������������Ļ���˼�����£�
1.ȡһ��������d1Ϊ�����������������������Ϊd1�顣����������k(k=0,1,2..d1-1)����: k,k+d1,k+2d1....��Ϊһ�����ֱ�Ӳ�������
2.��d1�����һ��ֱ�Ӳ����������ѡȡ�µ�����d2<d1�������з����������ֱ��dn=1��������������һ�β�������
˼����
�տ�ʼ�Ӵ�ϣ����������е��鷳����������˼����ͻᷢ��ϣ�������ֱ�Ӳ�������ʱ�临�Ӷȵ͡�����ѭ��������������n-2���ˣ����ǽ�����Ĵ�����
����ÿһ��ѭ��ʱ����Ϊ��Ȼ��ֱ�Ӳ��������Ӷ���Ȼ��O(n^2)���������ڽ��з������ڵ�n�Ѿ���С�ˣ���Tn������Ҳ���С��
���һ���һ�㣬ֱ�Ӳ���������ص�������Խ�������ƶ��Ƚϴ���Խ�٣�ϣ��������Խ��������Խ�������Ч�ʻ�����ߡ�
�������Ϸ���ϣ�������ʱ�临�Ӷ���һ�����������ĺ������������ż�������ʱ�临�Ӷȣ�lbd*d*O((length/d)^2)
���Կ϶���������O(n^2)���O(n)�����ٶȽ����ڿ�������
*/

//���ｫ����d��ʼ��Ϊlength��һ�룬֮��ÿ�μ���ֱ��1
void ShellSort(int *a, int length){
	int d;				//��������
	int i, j;
	int temp;		//�ݴ���
	int index;		//��Ҫ�����λ��
	if (a == NULL || length <= 0)
		return;
	//����lbd��ѭ��
	for (d = length / 2; d>0; d = d / 2)
	{
		//ֱ�Ӳ��������ѭ������
		for (i = 0; i<d; i++)
		{
			//��ʼֱ�Ӳ�������
			for (j = i + d; j<length; j = j + d)
			{
				index = j - d;
				temp = a[j];
				while (temp<a[index] && index >= 0)
				{
					a[index + d] = a[index];
					index = index - d;
				}
				a[index + d] = temp;
			}
		}
	}
}


//���õ�ϣ������
void BetterShellSort(int *a, int length){
	int d;//��Ϊ����
	int i, j;
	int index, value;//ֱ�Ӳ���������Ҫ�õ��ı���
	for (d = length / 2; d >= 1; d = d / 2)
	{
		//�Ż���˼����Ҫ����������Ƕ�ÿһ�����鵥������forѭ������ȥִ�У�������Щ������ʵ������һ�������ϵģ�ֻҪ��ӵ�ֵ��ͬ��Ȼ����ÿ����ͬ���Ա���бȽϡ�
		for (j = d; j < length; j++){
			if (a[j] < a[j - d]){
				value = a[j];
				index = j;
				while (a[index-d]>value&&index>0)
				{
					a[index] = a[index - d];
					index = index - d;
				}
				a[index] = value;
			}
		}
	}
}