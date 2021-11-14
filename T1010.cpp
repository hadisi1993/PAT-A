#include<iostream>
#include<cmath>
#include<string>
#include<cctype>
using namespace std;
//�������һ��ʼ�����ͨ����ⷽ����ý⣬�����Ƚϸ��ӣ�������ѧ֪ʶҲ�����������ñ�����һ��
//�������һ�£��������ܳ��ֵ��������long long���ͻ��ǿ���װ�µģ�����û��Ҫ���ַ����ô������
//��һ��������ֻ��ʮ��֣���radix��ߵ�100��19�֣���ߵ�1000��������
//�����������35�����г�����LL�ͱ�ʾ�Ŀ���
//ʹ����unsigned long long,����û���κθı�
//�����һ���ж�����������Ҫ�ӱȵ�ǰ���г��ֵ����󣬷�����Ϊ21��
//�ô���������û���κα仯
//����������Ҫ�ö��ַ�ȥ��,����û���뵽
//������������ؼ����⣬һ���Ƕ��ַ����Ͻ絽���Ƕ��٣����о����������ǲ��ǻᳬ��LL������
//�ο����ϵĴ���Ͳ��ͣ����������ύ�����Ƿ��֣�����Ŀ���Ե������radix������������ǲ��������
//��ô�������ͼ��ˣ�������һ������ʱ�����������͵����ϴ����������
//���ַ����Ͻ��Ƕ����ܣ���ϸ�������Եó����Ͻ粻�ܴ��ڸ�������֪����
typedef long long LL;
int main()
{
	LL t1 = 0, t2 = 0;
	string str1, str2;
	int tag, radix;
	cin >> str1 >> str2 >> tag >> radix;        //���������ַ�����tag�ͻ���
	if (tag == 2)         //���tag==2������������(�ַ���)
	{
		string str;
		str = str1;
		str1 = str2;
		str2 = str;
	}
	//ȷ�����ַ������½�
	LL index = 0, low, high;
	int flag = 0;  // �ж�������ǲ��Ǵ���
	for (int i = 0; i<str2.length(); i++)
	{
		LL tmp = isdigit(str2[i]) ? str2[i] - '0' : (str2[i] - 'a' + 10);
		index = max(index, tmp + 1);
	}
	low = index;      //�½�
	// printf("low:  %d\n",low);
	index = 0;
	for (int i = 0; i<str1.length(); i++)
	{
		index = index*radix + (isdigit(str1[i]) ? str1[i] - '0' : (str1[i] - 'a' + 10));
		//printf("%d\n",index);
	}
	high = index + 1;   // �Ͻ�
	t1 = index;
	LL mid = (low + high) / 2;
	//printf("mid: %d",mid);
	while (low <= high)
	{
		t2 = 0;
		for (int i = 0; i<str2.length(); i++)
		{
			t2 = t2*mid + (isdigit(str2[i]) ? str2[i] - '0' : (str2[i] - 'a' + 10));
			//  printf("t2:%d\n",t2);
			if (t2<0)
				break;
		}
		//printf("%d\n",t2);
		if (t2<0 || t2>t1)
		{
			high = mid - 1;
			mid = (high + low) / 2;
			//printf("mid:  %d\n",mid);
		}
		else if (t2<t1)
		{
			low = mid + 1;
			mid = (high + low) / 2;
		}
		else if (t1 == t2)
		{
			flag = 1;
			printf("%d\n", mid);
			return 0;
		}
	}
	if (!flag)
		printf("Impossible\n");     // �����������
	return 0;
}
