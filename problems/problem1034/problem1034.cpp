#include <iostream>
using namespace std;

//每个魔法单位储能
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

//计算两次操作间魔法恢复的函数
void refreshMega(mega unit[100],operation a,operation b) 
{
	int i;
	for (i = a.numberstart; i <= a.numberend; i++)
	{
		unit[i].init = (unit[i].refresh*(b.t - a.t)) 
			< unit[i].limit ? (unit[i].refresh*(b.t - a.t) ): unit[i].limit;
	}

}

//计算吸收函数
int absorbMega(mega unit[1000], int unitlen, operation op[1000], int oplen)
{
	int absorbRecord=0,i,j;
	//为第一次操作初始化
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
	mega unit[1000];   //初始化魔法单位
	int unitlen,i,j;      //魔法单位数量
	operation op[1000];  //初始化操作
	int oplen;        //初始化操作数量  
	cin >> unitlen;
	
	//循环实现从1开始存储魔法单位魔力数值（避免从0）
	i = 1;
	j = unitlen;
	while (j--)
	{
		cin >> unit[i].init>>unit[i].limit>>unit[i].refresh;       
		i++;
	}

	cin >> oplen;
	//循环实现操作从1存储
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