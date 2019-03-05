#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int>g[],int v,int s){
	stack<int>a;
	int visited[v]={0};
	a.push(s);
	int l,i,j;
	visited[s]=1;
	int parent[v];
	parent[s]=s;
	while(!a.empty()){
		l=a.top();
		a.pop();
	//	cout<<"this is pop during stack "<<l<<endl;
		for(i=0;i<g[l].size();i++){
			//cout<<"the node is "<<g[l][i]<<endl;
			if(visited[g[l][i]]!=1){
				visited[g[l][i]]=1;
				a.push(g[l][i]);
				parent[g[l][i]]=l;
			//	cout<<"node and parent is "<<g[l][i]<<" and "<<parent[g[l][i]]<<endl;
			}
			else if(visited[g[l][i]]==1&&parent[l]!=g[l][i]){
				cout<<"cycle detected"<<endl;
			//	cout<<" in second if condition the node and parent node is "<<g[l][i]<<" and "<<parent[g[l][i]]<<endl;
				return;
			}
		}
	}
	cout<<"no cycle detected";
	return;
}

int main(){
	int i,j,v,e;
	cout<<"enter the total no of edges and vertices ";
	cin>>e>>v;
	int s,d;
	vector<int>g[v];
	for(i=0;i<e;i++){
		cout<<"enter the vertices in between edge exist  ";
		cin>>s>>d;
		g[s].push_back(d);
		g[d].push_back(s);
	}
	while(1){
	cout<<"enter the source vertice ";
	cin>>s;
	dfs(g,v,s);
	}
	return 0;
}
