struct edge {
	int x, y;
	int l;
};
const int N = 1e5 + 10;
const int E = 1e5 + 10;
edge e[E];	
int parent[N]; int _rank[N]; 
int par(int x) {
	if (parent[x]==x) return x;
	return parent[x]=par(parent[x]); // Path Compression
}

void merge(int x,int y) {
	int px = par(x);
	int py = par(y);

	if(_rank[px] > _rank[py])
		parent[py] = px;
	else
		parent[px] = py;
	
	if(_rank[px] == _rank[py])
		_rank[py]++;
}

void kruskal(int n, int m) {

	for(int i=0; i<n; i++)
		parent[i] = i, _rank[i] = 0;

	for(int i=0, t=0; t<n-1; i++) {
		if(par(e[i].x) != par(e[i].y)) {
			merge(e[i].x,e[i].y);
			cost+=e[i].l;
			t++;
		}
	}
}