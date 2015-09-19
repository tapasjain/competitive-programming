const int MaxN = 1e5 + 10;
int BIT[MaxN];

// array in 1 to n (not 0 to n-1)
void update(int incr, int idx) { // increments "array value" at position idx by "incr"
	int pos = idx;
	while(pos < MaxN) {
		BIT[pos] += incr;
		pos += pos & (-pos);
	}
}
// finds "prefix sum" of elements from 1 to idx.
int query(int idx) {
	int pos = idx;
	int sum = 0;
	while(pos > 0) {
		sum += BIT[pos];
		pos -= pos & (-pos);
	}
	return sum;
}