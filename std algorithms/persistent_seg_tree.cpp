// this calculates the kth min in an array
// suppose b/w l & r -> ask for query(root[r], l==0?null:root[l-1], 0, maxi, k)

// for(int i=0; i<n; i++)
// {
// 	// Build a tree for each prefix using segment tree of previous prefix
// 	root[i] = (i == 0 ? null : root[i-1])->insert( 0, maxi, M[a[i]] );
// }

const int MaxN = 1e5 + 10;

struct node {
	int count;
	node *left, *right;
	node(int _count, node *_left, node *_right) : count(_count), left(_left), right(_right) {}
	node* insert(int l, int r, int w);
};

node *null = new node(0, NULL, NULL);

node::node* insert(int l, int r, int w) {
	if(l<=w && w<r) {
		if(l+1==r) {
			return new node(this->count+1, null, null);
		}
		int m = (l+r)>>1;
		return new node(this->count+1, this->left->insert(l,m,w), this->right->insert(m,r,w));
	}
	return this;
}


int query(node *a, node *b, int l, int r, int k) {
	if(l+1 == r)
		return l;

	int count = a->left->count - b->left->count;
	int m = (l+r)>>1;

	if(count>=k)
		return query(a->left, b->left, l, m, k);
	return query(a->right, b->right, m, r, k-count);
}

node *root[MaxN];

