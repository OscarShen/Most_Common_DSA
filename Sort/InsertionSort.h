#pragma once

#include <vector>

void insertionSort(std::vector<int> &v, int beg, int end)
{
	for (int i = beg + 1; i != end; ++i)
	{
		//�ȴ洢�������Ԫ�أ���Ϊ������λ�õĹ����У�����Ԫ����Ҫ�ƶ��������λ��
		//���ƶ������У����ֵ�ᱻ���ǵ�
		int t = v[i];
		int j = i - 1;
		for (; j >= 0 && t < v[j]; --j)
			v[j + 1] = v[j];
		v[j + 1] = t;
	}
}