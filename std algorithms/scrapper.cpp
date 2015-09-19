#include <bits/stdc++.h>

using namespace std;

#define pb push_back

int mod(int a, int b) {
	return ((a%b)+b)%b;
}

//  ------------------------------------- computes gcd(a,b) -------------------------------------------------------------
int gcd(int a, int b) {
	int tmp;
	while(b){
		a%=b; 
		tmp=a; 
		a=b; 
		b=tmp;
	}
	return a;
}

int extended_euclid(int a, int b, int &x, int &y) {
	int xx = y = 0;
	int yy = x = 1;
	while (b) {
		int q = a/b;
		int t = b; b = a%b; a = t;
		t = xx; xx = x-q*xx; x = t;
		t = yy; yy = y-q*yy; y = t;
	}
	return a;
}

int mod_inverse(int a, int n) {
	int x, y;
	int d = extended_euclid(a, n, x, y);
	if (d > 1) return -1;
	return mod(x,n);
}

void linear_diophantine(int a, int b, int c, int &x, int &y) {
	int d = gcd(a,b);
	if (c%d) {
		x = y = -1;
	} 
	else {
		x = c/d * mod_inverse(a/d, b/d);
		y = (c-a*x)/b;
	}
}

int E[100][2];
vector <int> E2[110];
int vis[110];

void dfs(int u) {
	vis[u] = 1;

	for(int i=0; i<E2[u].size(); i++) {
		if(!vis[E2[u][i]]) {
			dfs(E2[u][i]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) {
		int f, e, a, b;
		cin >> f >> e >> a >> b;
		memset(vis, 0, sizeof(vis));
		for(int i=0; i<=e+1; i++) {
			E2[i].clear();
		}
		for(int i=0; i<e; i++) {
			cin >> E[i][0] >> E[i][1];
			if(E[i][1] <= a && (a-E[i][1])%E[i][0] == 0) {
				E2[i].pb(e);
				E2[e].pb(i);
			}
			if(E[i][1] <= b && (b-E[i][1])%E[i][0] == 0) {
				E2[i].pb(e+1);
				E2[e+1].pb(i);
			}
		}
		for(int i=0; i<e; i++) {
			for(int j=i+1; j<e; j++) {
				int x, y;
				linear_diophantine(E[i][0], E[j][0], E[i][1] - E[j][1], x, y);
				if(E[i][0]*x + E[i][1] >= E[i][1] && E[i][0]*x + E[i][1] <= f-1 && -E[j][0]*y + E[j][1] >= E[j][1] && -E[j][0]*y + E[j][1] <= f-1) {
					E2[i].pb(j);
					E2[j].pb(i);
				}
			}
		}

		dfs(e);
		if(vis[e+1]) {
			cout << "It is possible to move the furniture." << endl;
		}
		else {
			cout << "The furniture cannot be moved." << endl;
		}

	}
}

