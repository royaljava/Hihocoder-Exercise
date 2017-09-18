#include<iostream>
using namespace std;

//����next���飬���ÿ��nextֵ��next����
void createNext(char a[1001], int next[1001]) {
	int i, k,rk,j, alen = strlen(a);
	next[0] = -1;
	for (i = 1; i <= alen; i++) {
		k = next[i - 1];
		rk = k;
		while (k != -1 && a[k] != a[i - 1]) {
			k = next[k];
		}
			if (k != -1) {
				next[i] = k+1;
			}
				else
				{
					next[i] = 0;
				}
				
			}
		
	}

//����ģʽ����next�����Լ�Ŀ�괮����Ŀ�괮���б���������ģʽ��ƥ�������
int traverse(char a[1001], char b[1001],int next[1001])
{
	int alen = strlen(a), blen = strlen(b),i=0,j=0,count=0,imark=0;
	while(i < alen) {		
		while(a[i] != b[j]) {
			i++;
			if (j != 0) {
				j = next[j];
			}
		}
		while(a[i] == b[j]) {
				i++;
				j++;
				if (j == blen) {
					count++;
				}
		}
		if (j != 0) {
			j = next[j];
		}
		
	}
	return count;
}

int main() {
	int N,record,i;
	char a[1001], b[1001];
	int	next[1001];
	cout << "����������" << endl;
	cin >> N;
	while (N--) {
		cin >> b>>a;
		createNext(b, next);
		record = traverse(a, b, next);
		cout << record <<endl;
	}
	return 0;
}


