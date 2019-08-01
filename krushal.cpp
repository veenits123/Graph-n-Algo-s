#include <bits/stdc++.h>
using namespace std;

const int N=100001;
int parent[N],sz[N];

struct node{
		int src,dest,weight;
};

bool comp(node edge1,node edge2){
	return edge1.weight<edge2.weight;
}

int get_parent(int x){
	if (parent[x]==x){
		return x;
	}
	else{
		return parent[x]=get_parent(parent[x]);
	}
}

void unite(int x,int y){
	int par_x=get_parent(x);
	int par_y=get_parent(y);
	if (par_x!=par_y){
		parent[par_y]=par_x;
		sz[par_x]+=sz[par_y];
		sz[par_y]=0;
	}
}

void init(){
	for (int i=0;i<N;i++){
		parent[i]=i;
		sz[i]=1;
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	node edge[m];
	for (int i=0;i<m;i++){
		cin>>edge[i].src>>edge[i].dest>>edge[i].weight;
	}
	sort(edge,edge+m,comp);
	node out[n-1];
	init();
	int mst_weight=0;
	int i=0,cur=0;
	while(cur<n-1){
		int to=edge[i].src;
		int from=edge[i].dest;
		if (get_parent(to)!=get_parent(from)){
			//mst_weight+=edge[i].weight;
			
			unite(to,from);
			out[cur]=edge[i];
			cur++;
		}
		i++;
	}
	//cout<<mst_weight;
	for (int i=0;i<n-1;i++){
		cout<<out[i].src<<"-->"<<out[i].dest<<" weight is "<<out[i].weight<<endl;
	}
	return 0;
}
