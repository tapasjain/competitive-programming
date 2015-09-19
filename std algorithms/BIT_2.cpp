//NICE BIT
#define ll long long
typedef struct struct_fenwick{
	int size, memory;
	ll *data;
}FenwickTree;

FenwickTree FenwickTreeNew(int memory){
	FenwickTree res;
	res.memory=memory; 
	res.data=(ll*)malloc(memory*sizeof(ll));
	return res;
}

void FenwickTreeDelete(FenwickTree *t){free(t->data);}

void FenwickTreeInit(FenwickTree *t, int size){int i; t->size=size; for(i=0;i<size;i++) t->data[i]=0;}

void FenwickTreeAdd(FenwickTree *t,int k,ll add){while(k<t->size)t->data[k]+=add, k|=k+1;}

ll FenwickTreeGet(FenwickTree *t,int k){
	ll res=0; 
	while(k>=0) res+=t->data[k],k=(k&(k+1))-1;
	return res;
}

FenwickTree bit = FenwickTreeNew(50000); //Creation with memory = 500000
FenwickTreeInit(&bit,n); //Initialisation with size = n
FenwickTreeGet(&bit,idx); //Get idx val
FenwickTreeAdd(&bit,x,y); //Add y at position x