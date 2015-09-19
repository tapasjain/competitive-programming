const int MOD = 1e9 + 7;
int A[100];

int fib(int n, int &x, int &y) {
	int f = n;
	int i;
	for(i=0; f>0; i++) {
		A[i] = (f&1); f>>=1;
	}
	i--;

	int prev=0; int pres=1;
	while(i--) {
		int temp = pres;
		pres = ((prev*1ll*2 + 1ll*pres) * 1ll * pres) % MOD;
		prev = (prev*1ll*prev + temp*1ll*temp) % MOD;
		if(A[i]) {
			swap(prev, pres);
			pres += prev;
			if(pres >= MOD)
				pres -= MOD;
		}
	}
	x=prev; y=pres;
	return y;
}