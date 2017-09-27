#pragma once

#include <string>

int* buildNext(const char *str);

#ifdef KMP__

//KMP
int match(const char *p, const char *s)
{
	int *next = buildNext(p);
	//����ע��һ��Ҫ�Ȱ�size()���ص�ֵ��int�ͱ��棬�������Ƚϵ�ʱ��������
	//��Ϊ���ǵ�i����һ��ֵ��-1������һ��ͨ���
	int m = strlen(p), n = strlen(s);
	int i = 0, j = 0;
	while (i < m && j < n)
	{
		//i < 0 �������Ӧ����next���е�ͨ���-1��Ҳ���ǱȽϲ�����ģʽ����ͷ���¿�ʼ���˲���֮��iΪ0��j�ݽ�һ��
		if (i < 0 || p[i] == s[j])
		{
			++i; ++j;
		}
		else
		{
			//�ҵ�iӦ�û��˵���λ��
			i = next[i];
		}
	}
	delete[]next;

	return j - i;
}

#ifdef KMP_OPTIMIZE

int* buildNext(const char *p)
{
	int m = strlen(p);
	int *next = new int[m];

	int i = 0;
	int t = next[0] = -1;

	while (i < m - 1)
	{
		if (t < 0 || p[i] == p[t])
		{
			++i; ++t;
			next[i] = (p[i] != p[t] ? t : next[t]);
		}
		else
		{
			t = next[t];
		}
	}

	return next;
}

#else

int* buildNext(const char *p)
{
	int m = strlen(p);
	int i = 0;
	int *next = new int[m];
	int t = next[0] = -1;

	while (i < m - 1)
	{
		if (t < 0 || p[i] == p[t])
		{
			++i; ++t;
			next[i] = t;
		}
		else
		{
			t = next[t];
		}
	}

	return next;
}

#endif

#else

//brute
int match(const char *p, const char *s)
{
	int sp = strlen(p), ss = strlen(s);
	int i = 0, j = 0;

	while (i < sp && j < ss)
	{
		if (p[i] == s[j])
		{
			++i; ++j;
		}
		else
		{
			j = j - i + 1;
			i = 0;
		}
	}
	return j - i;
}

#endif