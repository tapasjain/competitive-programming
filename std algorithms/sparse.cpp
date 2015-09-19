const int maxN = 1e5 + 10;
const int maxlogN = 20;
int M[maxN][maxlogN];
int logVal[maxN];

void process() {

	int num=2; int val=0;
	for(int i=1; i<n; ) {
		while(i<n && i<num)
			logVal[i++] = val;
		val++; num<<=1;
	}

	for(int i=0; i<n; i++)
		M[i][0] = i;

	for(int j=1; (1<<j)<=n; j++) {
		for(int i=0; i + (1<<j) - 1 < n; i++) {
			if(A[M[i][j-1]] < A[M[i+(1<<(j-1))][j-1]])
				M[i][j] = M[i][j-1];
			else
				M[i][j] = M[i+(1<<(j-1))][j-1];
		}
	}
}

int query(int i, int j) {
	int l = j-i+1;
	return min(A[M[i][logVal[l]]], A[M[j-(1<<(logVal[l]))+1][logVal[l]]]);
	// if(A[M[i][logVal[l]]] <= A[M[j-(1<<(logVal[l]))+1][logVal[l]]])
	// 	return M[i][logVal[l]];
	// else
	// 	return M[j-(1<<(logVal[l]))+1][logVal[l]];
}

