#include <iostream>
using namespace std;

//ÿ��ħ����λ����
struct mega
{
	int init;
	int limit;
	int refresh;
};

struct operation
{
	int t;
	int numberstart;
	int numberend;
};

//�������β�����ħ���ָ��ĺ���
void refreshMega(mega unit[100],operation a,operation b) 
{
	int i;
	for (i = a.numberstart; i <= a.numberend; i++)
	{
		unit[i].init = (unit[i].refresh*(b.t - a.t)) 
			< unit[i].limit ? (unit[i].refresh*(b.t - a.t) ): unit[i].limit;
	}

}

//�������պ���
int absorbMega(mega unit[1000], int unitlen, operation op[1000], int oplen)
{
	int absorbRecord=0,i,j;
	//Ϊ��һ�β�����ʼ��
	for (i = 1; i <= unitlen; i++)
	{
		unit[i].init = (unit[i].init + unit[i].refresh*(op[1].t))
			< unit[i].limit ? (unit[i].init + unit[i].refresh*(op[1].t)) : unit[i].limit;
		cout << unit[i].init << endl;
	}

	for (i = op[1].numberstart; i <= op[1].numberend; i++)
	{	
		absorbRecord += unit[i].init;
	}

	for(int i=1;i<=oplen-1;i++)
	{
		refreshMega(unit, op[i], op[i + 1]);
		for (j = op[i + 1].numberstart; j <= op[i + 1].numberend; j++)
		{
			absorbRecord += unit[j].init;
			cout << unit[j].init << endl;
		}
	}
	return absorbRecord;
}

void main()
{
	mega unit[1000];   //��ʼ��ħ����λ
	int unitlen,i,j;      //ħ����λ����
	operation op[1000];  //��ʼ������
	int oplen;        //��ʼ����������  
	cin >> unitlen;
	
	//ѭ��ʵ�ִ�1��ʼ�洢ħ����λħ����ֵ�������0��
	i = 1;
	j = unitlen;
	while (j--)
	{
		cin >> unit[i].init>>unit[i].limit>>unit[i].refresh;       
		i++;
	}

	cin >> oplen;
	//ѭ��ʵ�ֲ�����1�洢
	i = 1;
	j = oplen;
	while (j--)
	{
		cin >> op[i].t >> op[i].numberstart >> op[i].numberend;
		i++;
	}
	cout<<absorbMega(unit, unitlen, op, oplen)<<endl;
	system("pause");
}