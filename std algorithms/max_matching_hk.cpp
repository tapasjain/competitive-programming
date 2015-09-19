#define NIL 50001 // less than maxN
#define VI vector<int>

const int maxN = 50010;
const int INF = 1e9;
VI w[maxN];

int n, m, p, i, j, k;
int mr[maxN], mc[maxN], dist[maxN]; 

bool bfs()
{
	int i, v, j, k;
	queue<int> q;
	for(i=0; i<n; i++) {
		if(mr[i] == NIL) {
			dist[i] = 0;
			q.push(i);
		}
		else
			dist[i] = INF;
	}

	dist[NIL] = INF;

	while(!q.empty()) {
		v = q.front(); 
		q.pop();
		if(dist[v] < dist[NIL]) {
			for(j=0, k=w[v].size(); j<k; j++) {
				if(dist[mc[w[v][j]]] == INF) {
					dist[mc[w[v][j]]] = dist[v] + 1;
					q.push(mc[w[v][j]]);
				}
			}
		}
	}
	return (dist[NIL] != INF);
}

bool dfs(int v) {
	if(v != NIL) {
		for(int i=0, j=w[v].size(); i<j; i++) {
			if(dist[mc[w[v][i]]] == dist[v]+1) {
				if(dfs(mc[w[v][i]])) {
					mc[w[v][i]] = v;
					mr[v] = w[v][i];
					return 1;
				}
			}
		}
		dist[v] = INF;
		return 0;
	}
	return 1;
}

int hk() {
	for(int i=0; i<n; i++)
		mr[i] = NIL;
	for(int i=0; i<m; i++)
		mc[i] = NIL;

	int matching = 0;

	while(bfs()) {
		for(int i=0; i<n; i++) {
			if(mr[i]==NIL)
				if(dfs(i))
					matching++;
		}
	}
	return matching;
}

int main() {
	iofast;
	
	cin>>n>>m>>p;

	for(i=0; i<p; i++) {
		cin>>j>>k;
		w[j-1].pb(k-1);
	}

	cout<<hk();
}
