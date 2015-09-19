#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
const int MOD = 1e9 + 7;

int sum[N<<2], val[N<<2][3], lazyness[N<<2];
int A[N];

void build(int l, int r, int pos) {
	val[pos][0] = val[pos][1] = 0;
	val[pos][2] = 1;

	if(l == r) {
		sum[pos] = A[l];
		return;
	}
	
	int mid = (l+r) >> 1;
	build(l, mid, pos<<1);
	build(mid+1, r, (pos << 1) | 1);
	sum[pos] = sum[pos<<1] + sum[pos<<1 | 1];

	if(sum[pos] >= MOD)
		sum[pos] -= MOD;
}

void update(int l, int r, int pos, int i, int j, int x, int which) {

	if(lazyness[pos] != 0) {
		if(val[pos][0] != 0) {
			sum[pos] = ((r-l+1) * 1ll * val[pos][0]) % MOD;
			if(l != r) {
				val[pos<<1][0]=val[pos<<1|1][0]=val[pos][0];
				val[pos<<1][1]=val[pos<<1|1][1]=0;
				val[pos<<1][2]=val[pos<<1|1][2]=1;
				lazyness[pos<<1]=lazyness[pos<<1|1]=1;
			}
			val[pos][0]=0;
		}
		if(val[pos][2]!=1){
			sum[pos] = (sum[pos] * 1ll * val[pos][2]) % MOD;
			if(l != r) {
				val[pos<<1][1]=(val[pos<<1][1] * 1ll * val[pos][2]) % MOD;
				val[pos<<1|1][1]=(val[pos<<1|1][1] * 1ll * val[pos][2]) % MOD;
				val[pos<<1][2]=(val[pos<<1][2] * 1ll * val[pos][2]) % MOD;
				val[pos<<1|1][2]=(val[pos<<1|1][2] * 1ll * val[pos][2]) % MOD;
				lazyness[pos<<1]=lazyness[pos<<1|1]=1;
			}
			val[pos][2]=1;
		}
		if(val[pos][1]!=0) {
			sum[pos] = sum[pos] + ((r-l+1) * 1ll * val[pos][1])%MOD;
			if(sum[pos] >= MOD)
				sum[pos] -= MOD;
			if(l != r) {
				val[pos<<1][1] += val[pos][1];
				if(val[pos<<1][1] >= MOD)
					val[pos<<1][1] -= MOD;
				val[pos<<1|1][1] += val[pos][1];
				if(val[pos<<1|1][1] >= MOD)
					val[pos<<1|1][1] -= MOD;
				lazyness[pos<<1]=lazyness[pos<<1|1]=1;
			}
			val[pos][1]=0;
		}
		lazyness[pos] = 0;
	}

	if(l>j || r<i)
		return;

	if(l>=i && r<=j) {
		if(which == 0) {
			sum[pos] = ((r-l+1) * 1ll * x) % MOD;
			if(l != r) {
				val[pos<<1][0]=val[pos<<1|1][0]=x;
				val[pos<<1][1]=val[pos<<1|1][1]=0;
				val[pos<<1][2]=val[pos<<1|1][2]=1;
				lazyness[pos<<1]=lazyness[pos<<1|1]=1;
			}
			return;
		}
		else if(which == 1) {
			sum[pos] = sum[pos] + ((r-l+1) * 1ll * x)%MOD;
			if(sum[pos] >= MOD)
				sum[pos] -= MOD;
			if(l != r) {
				val[pos<<1][1] += x;
				if(val[pos<<1][1] >= MOD)
					val[pos<<1][1] -= MOD;
				val[pos<<1|1][1] += x;
				if(val[pos<<1|1][1] >= MOD)
					val[pos<<1|1][1] -= MOD;
				lazyness[pos<<1]=lazyness[pos<<1|1]=1;
			}
			return;
		}
		else {
			sum[pos] = (sum[pos] * 1ll * x) % MOD;
			if(l != r) {
				val[pos<<1][1]=(val[pos<<1][1] * 1ll * x) % MOD;
				val[pos<<1|1][1]=(val[pos<<1|1][1] * 1ll * x) % MOD;
				val[pos<<1][2]=(val[pos<<1][2] * 1ll * x) % MOD;
				val[pos<<1|1][2]=(val[pos<<1|1][2] * 1ll * x) % MOD;
				lazyness[pos<<1]=lazyness[pos<<1|1]=1;
			}
			return;
		}
	}

	int mid = (l+r) >> 1;
	update(l, mid, pos<<1, i, j, x, which);
	update(mid+1, r, pos<<1|1, i, j, x, which);

	sum[pos] = sum[pos<<1] + sum[pos<<1|1];
	if(sum[pos]>=MOD)
		sum[pos]-=MOD;
}

int query(int l, int r, int pos, int i, int j) {
	if(lazyness[pos] != 0) {
		if(val[pos][0] != 0) {
			sum[pos] = ((r-l+1) * 1ll * val[pos][0]) % MOD;
			if(l != r) {
				val[pos<<1][0]=val[pos<<1|1][0]=val[pos][0];
				val[pos<<1][1]=val[pos<<1|1][1]=0;
				val[pos<<1][2]=val[pos<<1|1][2]=1;
				lazyness[pos<<1]=lazyness[pos<<1|1]=1;
			}
			val[pos][0]=0;
		}
		if(val[pos][2]!=1){
			sum[pos] = (sum[pos] * 1ll * val[pos][2]) % MOD;
			if(l != r) {
				val[pos<<1][1]=(val[pos<<1][1] * 1ll * val[pos][2]) % MOD;
				val[pos<<1|1][1]=(val[pos<<1|1][1] * 1ll * val[pos][2]) % MOD;
				val[pos<<1][2]=(val[pos<<1][2] * 1ll * val[pos][2]) % MOD;
				val[pos<<1|1][2]=(val[pos<<1|1][2] * 1ll * val[pos][2]) % MOD;
				lazyness[pos<<1]=lazyness[pos<<1|1]=1;
			}
			val[pos][2]=1;
		}
		if(val[pos][1]!=0) {
			sum[pos] = sum[pos] + ((r-l+1) * 1ll * val[pos][1])%MOD;
			if(sum[pos] >= MOD)
				sum[pos] -= MOD;
			if(l != r) {
				val[pos<<1][1] += val[pos][1];
				if(val[pos<<1][1] >= MOD)
					val[pos<<1][1] -= MOD;
				val[pos<<1|1][1] += val[pos][1];
				if(val[pos<<1|1][1] >= MOD)
					val[pos<<1|1][1] -= MOD;
				lazyness[pos<<1]=lazyness[pos<<1|1]=1;
			}
			val[pos][1]=0;
		}
		lazyness[pos] = 0;
	}

	if(r<i || l>j)
		return 0;
	if(l>=i && r<=j)
		return sum[pos];
	int mid = (l+r) >> 1;
	int a = query(l, mid, pos<<1, i, j);
	a += query(mid+1, r, pos<<1|1, i, j);
	if(a>=MOD)
		a-=MOD;
	return a;
}

int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	for(int i=1; i<=n; i++)
		scanf("%d", &A[i]);

	memset(lazyness, 0, sizeof lazyness);
	build(1, n, 1);

	for(int i=0; i<q; i++) {
		int which, l, r, v;
		cin >> which >> l >> r;
		if(which == 4) {
			cout << query(1,n,1,l,r) << endl;
			continue;
		}
		cin >> v;
		update(1,n,1,l,r,v,which%3);
	}
}