//LCP + SUFFIX
long long P[MAXL][MAXN];
long long N, stp, cnt;
//stp is number of steps done so far
//cnt is gonna be the length of the substring
struct str{long long nr[2];long long p;};
bool operator<(str a,str b){ return a.nr[0]<b.nr[0] || (a.nr[0]==b.nr[0] && a.nr[1]<b.nr[1]); }
str L[MAXN];
long long A[MAXN];

void suffix(){
	//N = strlen(A);
	for(long long i=0;i<N;i++)P[0][i] = 1000+ A[i];
	// initial ranks
	for(stp = 1, cnt = 1; (cnt >> 1) < N ; stp++ , cnt <<= 1){
		for(long long i = 0; i<N; i++){
			L[i].nr[0] = P[stp-1][i];
			L[i].nr[1] = i+cnt < N ? P[stp-1][i+cnt] : -1; //-1 is implimentaion of fake null characters
			L[i].p = i;
		}
		sort(L,L+N);
		for(long long i = 0;i<N;i++) // generating new ranks
			P[stp][L[i].p] = i>0 && L[i-1].nr[0] == L[i].nr[0] && L[i-1].nr[1] == L[i].nr[1] ? P[stp][L[i-1].p] : i;
	}
}

// lcp code
long long lcp(long long x,long long y){
	x = L[x].p, y = L[y].p;
	long long ans = 0;
	for ( long long k = stp-1 ; x < N && y < N && k >=0; k--) {
		if(P[k][x] == P[k][y]) ans += (1<<k) , x += (1<<k) , y += (1<<k);
	}
	return ans;
}

//make LCP array
long long LCP[MAXN];

void makeLCP(){
	for(long long k = 1;k<N;k++)LCP[k] = lcp(k,k-1);
}

long long unique(){
	long long ans = N-L[0].p;
	for(long long i = 1;i < N;i++)ans =(ans + N-L[i].p -lcp(i,i-1))%mod;
	return ans;
}

long long U(){
	if(N == 1)return 1;
	suffix();
	return unique() % mod;
}

int main(){
	long long t = fcin();
	long long x,prev;
	while (t--) {
		long long n = fcin();
		cin>>prev;
		for(long long i=1;i<n;i++){
			cin>>x;
			A[i-1] = x-prev;
			prev = x;
		}
		N = n-1;
		if(N == 0) cout << 0 << endl;
		else cout << U() << endl;
	}
}