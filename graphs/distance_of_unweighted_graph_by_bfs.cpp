#include<bits/stdc++.h>
using namespace std;
void bfs(vector<int>a[],int s,int des,int ss){
	if(s==0)
		return;
	int i,j,l;
	vector<int>dis(s);
	dis[ss]=0;
	queue<int>p;
	p.push(ss);
	int v[s];
	for(i=0;i<s;i++)
		v[i]=0;
	v[ss]=1;
	while(!p.empty()){
	l=p.front();
	if(l==des){
		cout<<"the distance is "<<dis[l]<<endl;
		return;	
	}
	p.pop();
	//cout<<l<<"  ";
	for(i=0;i<a[l].size();i++){
		if(v[a[l][i]]!=1){
			p.push(a[l][i]);
			v[a[l][i]]=1;
			dis[a[l][i]]=dis[l]+1;
	        }
	}
        }
	cout<<"no path exist ";
}



int main(){
	int i,v,s,e,d,aa,bb;
	cout<<"enter the no of edges and vertices ";
	cin>>e>>v;
	vector<int>a[v];
	for(i=0;i<e;i++){
		cout<<"enter the vertices in between which node exist  ";
		cin>>s>>d;
		a[s].push_back(d);
		a[d].push_back(s);
	}
	while(1){
	cout<<"enter the source and destination in between which u want distance ";
        cin>>aa>>bb;
	bfs(a,v,bb,aa);
	}
	return 0;
}
