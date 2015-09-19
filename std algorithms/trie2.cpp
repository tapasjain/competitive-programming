// Tapas Jain

const int N = 26;
const char first = 'a';

struct trie {
	int words;
	int prefixes;
	trie *edges[N];

	trie() {
		words = prefixes = 0;
		for(int i=0; i<N; i++)
			edges[i] = NULL;
	}

	void addword(char *A) {
		if(!A[0]){
			words++;
			return;
		}
		int j = A[0] - first;
		if(!edges[j])
			edges[j] = new trie;
		prefixes++;
		edges[j]->addword(A+1);
	}

	int nwords(char *A) {
		if(!A[0]) 
			return words;
		int j = A[0] - first;
		if(!edges[j])
			return 0;
		return edges[j]->nwords(A+1);
	}

	int nprefixes(char *A) {
		if(!A[0])
			return prefixes;
		int j = A[0] - first;
		if(!edges[j])
			return 0;
		return edges[j]->nprefixes(A+1);
	}
};