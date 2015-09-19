//Merge Sort (Bad Space complexity ie., nlogn can be easily made O(n) space )
int* merge(int a[],int x,int b[],int y) //merging with n efficiency
{
	int* arr;
	int i=0,u=0,v=0;
	arr=new int[x+y];
	for(i=0;u<x&&v<y;i++)
	{
		if(a[u]<b[v])arr[i]=a[u++];
		else arr[i]=b[v++];
	}
	while(u<x){arr[i]=a[u];i++;u++;}
	while(v<y){arr[i]=b[v];i++;v++;}
	return arr;
}

int* mergesort(int *arr,int n) //recursion with log n iterations
{
	if(n==1)return arr;
	return merge(mergesort(arr,n/2),n/2,mergesort(arr+n/2,n-n/2),n-n/2);
}
