#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int>g[],int v,int s){
	stack<int>a;
	int visited[v]={0};
	a.push(s);
	int l,i,j;
	visited[s]=1;
	while(!a.empty()){
		l=a.top();
		a.pop();
		cout<<l<<" ";
		for(i=0;i<g[l].size();i++){
			if(visited[g[l][i]]!=1){
				visited[g[l][i]]=1;
				a.push(g[l][i]);
			}
		}
	}
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
