//LCA
int n,m;
int T[maxN],P[maxN][maxL],L[maxN];

void doDFS(int p,int v,int level){
	T[v] = p;
	L[v] = level;
	for(int i=0;i<arr[v].size();i++){
		if(arr[v][i] != p)
			doDFS(v,arr[v][i],level+1);
	}
}

void makeLCAtable(){
	doDFS(-1,1,0); //-1 is parent of root(1)
	memset(P,-1,sizeof P);
	for(int i=1;i <= n;i++)
		P[i][0] = T[i];
	for(int j=1;1<<j < n; j++)
		for(int i=1;i<=n;i++)
			if(P[i][j-1] != -1) 
				P[i][j] = P[P[i][j-1]][j-1];
}

int LCA(int x, int y){
	if(L[x] < L[y]) 
		return (LCA(y, x));

	int log;
	for(log = 1; 1<< log <= L[x];log++); // log is log(L[x]) floor
	
	log--;
	
	for (int i = log ; i >= 0; i--)
		if(L[x] - (1<<i) >= L[y])
			x = P[x][i];
	
	if(x==y)
		return x;
	
	for(int i=log;i >= 0; i--)
		if(P[x][i] != -1 && P[x][i] != P[y][i])
			x = P[x][i] , y = P[y][i];
	
	return T[x];
}

int ancestor(int v,int k){
	if(k==0)
		return v;
	int log = 1;
	while(1 << log <= k)
		log++;
	log--;
	
	return ancestor(P[v][log],k-(1<<log));
}

int main(){
	int tests=fcin();
	int x,y;
	while(tests--){
		n = fcin();
		m = fcin();
		arr.resize(n+1);
		for(int i=0;i<n-1;i++){
			x = fcin();
			y = fcin();
			arr[x].pb(y);
			arr[y].pb(x);
		}
		makeLCAtable();
		while (m--) {
			x = fcin();
			y = fcin();
			cout << ancestor(x,y) << endl;
		}
	}
}