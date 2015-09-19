int n,q,bs=1<<17,seg[1<<18][3],flag[1<<18];//bs=base size
void init() //Initialise seg tree
{
	int i;
	for(i=bs;i<bs+n;i++)
	{
		seg[i][0]=1;//Initial Values
	}
	for(i=bs-1;i>0;i--)
	{
		seg[i][0]=seg[i<<1][0]+seg[i<<1|1][0];//Change it to required function like max,gcd,etc
	}
}

void prop(int node,int L,int R) //Lazy Propagation
{
	int temp;
	if(flag[node]==1)
	{
		//Updating Value at node
		temp=seg[node][0];
		seg[node][0]=seg[node][2];
		seg[node][2]=seg[node][1];
		seg[node][1]=temp;
		//Flag children
		if(L!=R)
		{
			flag[node<<1]++;flag[node<<1]%=3;
			flag[node<<1|1]++;flag[node<<1|1]%=3;
		}
	}
	else if(flag[node]==2)
	{
		//Updating Value at node
		temp=seg[node][0];
		seg[node][0]=seg[node][1];
		seg[node][1]=seg[node][2];
		seg[node][2]=temp;
		//Flag children
		if(L!=R){
			flag[node<<1]+=2;flag[node<<1]%=3;
			flag[node<<1|1]+=2;flag[node<<1|1]%=3;
		}
	}

	flag[node]=0;
}

void rupdate(int node)
{
	seg[node][0]=seg[node<<1][0]+seg[node<<1|1][0];
	seg[node][1]=seg[node<<1][1]+seg[node<<1|1][1];
	seg[node][2]=seg[node<<1][2]+seg[node<<1|1][2];
}

void update(int node,int l,int r,int L,int R)
{
	if (flag[node])
	{
		prop(node,L,R); //Lazy Propagation
	}
	int M = (L+R)>>1;
	if(l>r) return;//Used for decoy updates
	if (l==L && r==R)
	{
		flag[node]++;
		prop(node,L,R);
	}
	else if(r<=M)
	{
		update(node<<1,l,r,L,M);
		update(node<<1|1,1,0,M+1,R);//Decoy update to remove flags
		rupdate(node);
		//Updating Values while traversing up
	}
	else if(l>M)
	{
		update(node<<1,1,0,L,M);//Decoy update to remove flags
		update(node<<1|1,l,r,M+1,R);
		rupdate(node);
		//Updating Values while traversing up
	}
	else
	{
		update(node<<1,l,M,L,M);
		update(node<<1|1,M+1,r,M+1,R);
		rupdate(node);
		//Updating Values while traversing up
	}
}

int query(int node,int l,int r,int L,int R)
{
	if (flag[node]) prop(node,L,R); //Lazy Propagation
	int M = (L+R)>>1;
	if (l==L && r==R) return seg[node][0]; //Return Value
	else if(r<=M) return query(node<<1,l,r,L,M);
	else if(l>M) return query(node<<1|1,l,r,M+1,R);
	else return query(node<<1,l,M,L,M)+query(node<<1|1,M+1,r,M+1,R); //Split and Merge
}