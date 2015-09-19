// ---------- Strongly Connected Components
//Initialize deg[] and adjList[][] before calling SCC()
const int maxNode = 5000;
int deg[maxNode];
int adjList[maxNode][maxNode];
int component[maxNode];
// what is component number of vertex v
int compSize[maxNode];
// how many vertices in comp c
int totalSCC;
// how many total components found
bool adjComp[maxNode][maxNode]; // adjacency matrix for components
int dfsNum[maxNode], minDfsNum[maxNode], dfsNext;
int currentComp[maxNode], currentSize;
bool inComp[maxNode];

void dfs(int u)
{
	if( dfsNum[u] >= 0) return;
	minDfsNum[u] = dfsNum[u] = dfsNext++;
	currentComp[currentSize++] = u;
	inComp[u] = true;
	// Insert u in current component
	for(int i = 0; i < deg[u]; i++)
	{
		int v = adjList[u][i];
		dfs(v);
		if( inComp[v] )
		// Check is only for cross edges
		minDfsNum[u] = min (minDfsNum[u], minDfsNum[v] );
	}
	if( minDfsNum[u] == dfsNum[u] )
	// New component found
	{
		while(true)
		{
			int v = currentComp[--currentSize];
			component[v] = totalSCC;
			compSize[totalSCC] ++;
			inComp[v] = false;
			if( u == v) break;
		}
		totalSCC ++;
	}
}

void scc(int N)
{
	memset( dfsNum, -1, sizeof dfsNum);
	memset( compSize, 0, sizeof compSize);
	memset( inComp, false, sizeof inComp);
	// dfsNum also works as visited array
	currentSize = dfsNext = totalSCC = 0;
	for( int i = 0; i < N; i++ )
		if( dfsNum[i] < 0) dfs( i );
	for(int i=0;i<N;i++)
		for(int j=0;j<deg[i];j++)
			if(component[i] != component[ adjList[i][j] ])
				adjComp[ component[i] ][ component[adjList[i][j]] ] = true;
}