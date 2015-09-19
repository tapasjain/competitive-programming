//----------------TRIE
struct node
{
	char val;int deg,depth;
	vector<node> children;
	node(char i='\0',int d=0,int od=0)
	{
		val=i;deg=od;depth=d;
	}
};

struct trie
{
	node top;
	trie()
	{
		top = node('\0',0,2);
	}
	void insert(char *arr)
	{
		int i,j,flag;
		node* temp = &top;
		for(i=0;i<strlen(arr);i++)
		{
			flag=0;
			for(j=0;j<temp->children.size();j++)
			{
				if(arr[i]==temp->children[j].val)
				{
					flag=1;temp = &(temp->children[j]);temp->deg++;break;
				}
			}
			if(flag==0)
			{
				temp->children.pb(node(arr[i],temp->depth+1,1));temp=&(temp->children[temp->children.size()-1]);
			}
		}
	}
	int dfs(node temp)
	{
		if(temp.deg<2) return 0;
		int maxm=temp.depth;
		for(int i=0;i<temp.children.size();i++)
		{
			maxm = max(dfs(temp.children[i]),maxm);
		}
		return maxm;
	}
};