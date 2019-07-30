#include <bits/stdc++.h>
using namespace std;

const int N=100005;
vector <int> graph[N];
int visited[N];
vector <int> order;

//depth first search
void dfs(int cur){
	//cout<<cur<<endl;
	visited[cur]=1;
	for (int i=0;i<graph[cur].size();i++){
		int start=graph[cur][i];
		if (visited[start]==1){
			continue;
		}
		dfs(start);		
	}
}

//breadth first search
void bfs(int source){
	queue <int> q;
	q.push(source);
	while(!q.empty()){
		int cur=q.front();
		q.pop();
		if (visited[cur]==1){
			continue;
		}
		cout<<cur<<endl;
		visited[cur]=1;
		for (int i=0;i<graph[cur].size();i++){
			int to=graph[cur][i];
			q.push(to);
		}
	}				
}

bool is_connected(int n,int source){
	bfs(source);
	for (int i=1;i<=n;i++){
		if (visited[i]==0){
			return false;
		}
	}
	return true;
}

bool is_cyclic(int n,int par){
	visited[n]=1;
	for (int i=0;i<graph[n].size();i++){
		int go=graph[n][i];
		if (visited[i]==1 and go!=par){
			return true;
		}
		else if(!visited[go]){
			return is_cyclic(go,n);
		}
	}
	return false;
}

int connected_comp(int n){
	int cnt=0;
	for (int i=1;i<=n;i++){
		if (!visited[i]){
			dfs(i);
			cnt++;
		}
	}
	return cnt;	
}

//topological sorting
void dfs1(int n){
	//cout<<n<<" ";
	visited[n]=1;
	for (int i=0;i<graph[n].size();i++){
		int to=graph[n][i];
		if (visited[to]==1){
			continue;
		}
		dfs1(to);
	}
	order.push_back(n);
}
int main(){
	int n,m;
	cin>>n>>m;
	
	for (int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		graph[x].push_back(y);
		//graph[y].push_back(x);	
	}
	//int source;
	//cin>>source;
	//dfs1(source);
	//bfs(source);
	//cout<<(is_connected(n,source)?"YES":"NO");
	//cout<<(is_cyclic(source,0)?"YES":"NO");
	//cout<<connected_comp(n);
	for (int i=0;i<=n;i++){
		if (visited[i]==1){
			continue;
		}
		dfs1(i);
	}
	int sz=order.size();
	for (int i=0;i<sz;i++){
		cout<<order[sz-i-1]<<" ";
	}
	return 0;
}
