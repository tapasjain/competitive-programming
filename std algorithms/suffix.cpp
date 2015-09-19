const int MaxN = 1e5 + 10;
const int MLogN = 20;
int P[MLogN][MaxN];

struct str {
	int nr[2]; int p;
};
str L[MaxN];
int LCP[MaxN];
char A[MaxN];
// length of string
int N;
// Save largest stp
int stp, cnt; 

int cmp(str a, str b) {
	return a.nr[0]==b.nr[0] ? (a.nr[1]<b.nr[1] ? 1 : 0) : (a.nr[0]<b.nr[0] ? 1 : 0);
}

void suffix() {
	for(int i=0; i<N; i++) 
		P[0][i] = A[i] - 'a';

	for(stp=1, cnt=1; cnt<N; stp++, cnt*=2) {
		for(int i=0; i<N; i++) {
			L[i].nr[0] = P[stp-1][i];
			L[i].nr[1] = i+cnt<N ? P[stp-1][i+cnt] : -1;
			L[i].p = i;
		}
		sort(L, L+N, cmp);
		for(int i=0; i<N; i++)
			P[stp][L[i].p] = i>0 && L[i].nr[0]==L[i-1].nr[0] && L[i].nr[1]==L[i-1].nr[1] ? P[stp][L[i-1].p] : i;
	}
}

int findLCP(int x, int y) {
	int ret = 0;
	if(x==y) return N-x;
	for(int k=stp-1; k>=0 && x<N && y<N; k--) {
		if(P[k][x] == P[k][y]) {
			x+=(1<<k); y+=(1<<k);
			ret += (1<<k);
		}
	}
	return ret;
}

void fillLCP() {
	for(int i=0; i+1<N; i++)
		LCP[i] = findLCP(L[i].p, L[i+1].p);
}
