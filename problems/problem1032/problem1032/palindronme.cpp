#include<iostream>
using namespace std;

int palindrome(char a[1000]) {
	int i, j, k, clen,m,n,max,maxi,b[1000];
	char c[1000];

	//通过两个for循环实现数值填充
	for (i = 1; i < 2*strlen(a); i=i+2) {
		c[i] = a[i / 2];
	}
	for (i = 0; i < 2*strlen(a)+2; i = i + 2) {
		c[i] = '0';
	}
	c[2 * strlen(a)+1] = '\0';
	//通过嵌套for循环实现回文串输出
	clen = strlen(c);
	b[0] = 1;
	b[1] = 3;
	j = 1;
	maxi = 1;
	max = 3;
	for (i = 2; i < clen; i++) {
		k=(b[2*j-i]) > (b[i] - 2*(i - j)) ?( b[2 * j - i]): (b[i] - 2 * (i - j));
		m =i-(k-1)/2;
		n = i+(k-1)/ 2;
			while (m >= 0 && n < clen&&c[m] == c[n]) {
				m--;
				n++;
			}
			b[i] = 2*(i - m)-1;
			
			
			if ((b[i] / 2 + i) >= (b[j] / 2 + j)) {
				j = i;
			}
			
			if (b[i] > max) {
				max = b[i];
				maxi = i;
			}
	}
		return (b[maxi] - 1) / 2;


}

void main() {
	int k;
	char a[1000];
	int b[1000];
	cin >> a;
	k = palindrome(a);
	cout << k << endl;
	system("pause");
}