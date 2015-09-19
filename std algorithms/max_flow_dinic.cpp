// Dinic's Algorithm
// O(V^2 E)

const int MAX_E=60003;
const int MAX_V=5003;
int ver[MAX_E],cap[MAX_E],nx[MAX_E],last[MAX_V],ds[MAX_V],st[MAX_V],now[MAX_V],edge_count, S, T, N, M;

inline void reset() {
	memset(nx,-1,sizeof(nx));
	memset(last,-1,sizeof(last));
	edge_count=0;
}

inline void addedge(const int v,const int w,const int capacity,const int reverse_capacity) {
	ver[edge_count]=w; 
	cap[edge_count]=capacity; 
	nx[edge_count]=last[v]; 
	last[v]=edge_count++;
	ver[edge_count]=v; 
	cap[edge_count]=reverse_capacity; 
	nx[edge_count]=last[w]; 
	last[w]=edge_count++;
}

inline bool bfs() {
	memset(ds,-1,sizeof(ds));
	int a,b;
	a=b=0;
	st[0]=T;
	ds[T]=0;
	while (a<=b) {
		int v=st[a++];
		for (int w=last[v];w>=0;w=nx[w]) {
			if (cap[w^1]>0 && ds[ver[w]]==-1){
				st[++b]=ver[w];
				ds[ver[w]]=ds[v]+1;
			}
		}
	}
	return ds[S]>=0;
}

int dfs(int v,int cur) {
	if (v==T) return cur;
	for (int &w=now[v];w>=0;w=nx[w]) {
		if (cap[w]>0 && ds[ver[w]]==ds[v]-1) {
			int d=dfs(ver[w],min(cur,cap[w]));
			if (d) {
				cap[w]-=d;
				cap[w^1]+=d;
				return d;
			}
		}
	}
	return 0;
}

inline ll flow() {
	ll res=0;
	while (bfs()) {
		for (int i=0;i<MAX_V;i++) 
			now[i]=last[i];
		while (1) {
			int tf=dfs(S,INF);
			res+=tf;
			if (!tf) break;
		}
	}
	return res;
}

// int main() {
// 	scanf("%d %d", &N, &M);
// 	int i = M, v, w, cap;
// 	reset();
// 	while (i--) {
// 		scanf("%d %d %d", &v, &w, &cap);
// 		addedge(--v, --w, cap, cap);
// 	}
// 	S = 0, T = N-1;
// 	printf("%lld\n", flow());
// 	return 0;
// }