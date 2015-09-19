#include <bits/stdc++.h>
using namespace std;

const int N = 2010;
int A[N][N];
int pre[N], suf[N];
char S[N];

int main() {
	cin >> S;
	int len = strlen(S);

	for(int i=0; i<len; i++)
		A[i][i] = 1;

	for(int i=0; i+1<len; i++)
		A[i][i+1] = (S[i] == S[i+1]) ? 1 : 0;

	for(int i=len-1; i>=0; i--) {
		for(int j=i+2; j<len; j++) {
			A[i][j] = (S[i]==S[j] && A[i+1][j-1]) ? 1 : 0;
		}
	}

	for(int i=0; i<len; i++) {
		pre[i] = 0;
		for(int j=0; j<=i; j++) {
			pre[i] += A[j][i];
		}
	}

	for(int i=len-1; i>=0; i--) {
		suf[i] = 0;
		for(int j=i; j<len; j++)
			suf[i] += A[i][j];
	}

	for(int i=1; i<len; i++)
		pre[i] += pre[i-1];
	// for(int i=len-2; i>=0; i--) 
	// 	suf[i] += suf[i+1];


	long long ans = 0;

	for(int i=0; i+1<len; i++) {
		ans += pre[i] * 1ll * suf[i+1];
	}

	cout << ans << endl;

}