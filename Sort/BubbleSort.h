#pragma once

#include <vector>

void bubbleSort(std::vector<int> &v, size_t beg, size_t end)
{
	bool sorted = false;
	while (!sorted)
	{
		//�������һ�˱�����û�з���Ԫ�صĽ�������ô֤��������Ȼ���򣬿�����ֹ����
		sorted = true;
		for (size_t i = beg + 1; i < end; ++i)
		{
			if (v[i] < v[i - 1])
			{
				using std::swap;
				swap(v[i - 1], v[i]);
				sorted = false;
			}
		}
		//�������򲿷ֿ�������һ�����ȣ���Ϊһ��ð�ݺ����Ԫ���Ѿ�λ
		--end;
	}
}