// http://articles.leetcode.com/2011/11/longest-palindromic-substring-part-ii.html
int MaxN = 2e5 + 10;
int N;
char A[MaxN];
int P[MaxN];

void pre() {
	for(int i=N-1; i>=0; i--)
		A[2*(i+1)] = A[i];
	for(int i=0; i<=N; i++)
		A[2*i+1] = '#';
	A[0]='^'; A[2*N+2]='$'; A[2*N+3]='\0';
	N=2*N+3;
}

// returns the center of the longest palindrome. for its length search for P[ans]
int longest_palindrome() {
	pre();
	int c=0; int r=0; 
	for(int i=1; i<N-1; i++) {
		int mirror = 2*c-i;
		P[i] = r>i ? min(r-i,P[mirror]) : 0;
		while(A[i+1+P[i]]==A[i-1-P[i]])
			P[i]++;
		if(i+P[i] > r) {
			c=i; r=i+P[i];
		}
	}
	int maxlen=0; int centeri=0;
	for(int i=1; i<n-1; i++) {
		if(P[i]>maxlen) {
			maxlen=P[i]; centeri=i;
		}
	}
	return centeri;
}