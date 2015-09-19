#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int N = 1e5 + 10;
const int INF = 1e9 + 7;

int A[27];
char S[N];
map <pair<LL,char>, LL> mymap; 

int main() {
	ios_base::sync_with_stdio(0);
	for(int i=0; i<26; i++)
		cin >> A[i];
	cin >> S;
	LL sum = 0;
	LL ans = 0;
	int len = strlen(S); 
	for(int i=1; i < len; i++) {
		pair<LL, char> p = make_pair(sum, S[i-1]);
		if(mymap.find(p) == mymap.end()) mymap[p] = 1;
		else mymap[p]++;

		p = make_pair(sum, S[i]);
		if(mymap.find(p) != mymap.end())
			ans += mymap[p];

		sum += A[S[i] - 'a'];
	}
	cout << ans << endl;

}