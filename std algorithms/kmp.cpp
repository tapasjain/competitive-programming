const int max_n = (int)1e6;
int pi[max_n];
char P[max_n], T[max_n];
int n,m;

// Pattern and string T is stored from 1 not 0.

void table()
{
	pi[0] = -1;
	int k = -1;
	for(int i = 1; i <= m; i++) {
		while(k >= 0 && P[k+1] != P[i])
			k = pi[k];
		pi[i] = ++k;
	}
}

void kmp()
{
	int k = 0;
	for(int i = 1; i <= n; i++) {
		while(k >= 0 && P[k+1] != T[i])
			k = pi[k];
		k++;
		if(k == m) {
			cout << i-m+1 << endl;
			k = pi[k];
		}
	}
}

int main(){
	int N;
	while(scanf("%d",&N) != EOF){
		scanf("%s",P+1);
		scanf("%s",T+1);
		n = strlen(T+1);
		m = strlen(P+1);
		table();
		kmp();
		cout << endl;
	}
}