
// Edmonds Karp adjacency matrix 
// O(min(V E^2, maxflow * E))
// vertices 0 to n-1

#define maxn 5000
#define INF 1000000000

int source, sink, n;
int capc [maxn][maxn], vis[maxn], par[maxn];


bool bfs() {
	queue < int > q;
	memset(vis, 0, sizeof vis);
	q.push(source);
	vis[source] = 1;
	while(!q.empty()) {
		int u = q.front();
		q.pop();

		if(u == sink)
			return 1;

		for(int i=0; i<n; i++)
			if(!vis[i] && capc[u][i]>0) {
				vis[i] = 1;
				q.push(i);
				par[i] = u;
			}
	}
	return 0;
}

int edmond() {
	int flow = 0;
	while(bfs()) {
		int pres = INF;

		for(int i=sink; i != source; i=par[i])
			pres = min(pres, capc[par[i]][i]);
		
		for(int i=sink; i != source; i=par[i]) {
			capc[par[i]][i] -= pres;
			capc[i][par[i]] += pres;
		}

		flow += pres;
	}

	return flow;
}
