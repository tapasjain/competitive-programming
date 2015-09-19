const int max_n = 100000;
//10^5
// elements in 0 - max_n
int val[max_n];
//point values
int beg[4*max_n], end[4*max_n], seg[4*max_n];

void make_seg(int pos, int start, int finish)
{
	beg[pos] = start;
	end[pos] = finish;
	seg[pos] = 0;
	if(start == finish)
	{
		seg[pos] = val[start];
		return;
	}
	int mid = (start + finishi)/2;
	make_seg(2*pos, start, mid);
	make_seg(2*pos+1, mid+1, finish);
	seg[pos] = seg[2*pos] + seg[2*pos + 1];
}

int query(int pos, int start, int finish)
{
	if(start <= beg[pos] && finish >= end[pos])
		return seg[pos];
	int left = 2*pos;
	int right = left+1;
	if(finish <= end[left])
		return query(left, start, finish);
	if(start >= beg[right])
		return query(right, start, finish);
	int leftans = query(left, start, finish);
	int rightans = query(right, start, finish);
	return leftans + rightans;
}

void update(int pos, int idx, int num)
//update the value at idx (DIFFERENT FROM POS). Recursively: currently at node pos
{
	if(beg[pos] == end[pos])
	// Here it would be equal to idx
	{
		seg[pos] = num;
		// modify value here
		return;
	}
	if(idx >= beg[2*pos + 1])
		update(2*pos + 1, idx, num);
	else
		update(2*pos, idx, num);
	seg[pos] = seg[2*pos] + seg[2*pos+1];
}

int main()
{
	make_seg(1, 0, max_n-1);
}