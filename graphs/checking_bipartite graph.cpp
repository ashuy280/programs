#include<bits/stdc++.h>
using namespace std;
void bfs(vector<int>a[],int s,int ss){
	if(s==0)
		return;
	int i,j,l;
	queue<int>p;
	vector<int>colour(s);
	p.push(ss);
	int v[s];
	for(i=0;i<s;i++){
		v[i]=0;
		colour[i]=-1;
	}
	v[ss]=1;
	colour[ss]=1;
	while(!p.empty()){
	l=p.front();
	p.pop();
	//cout<<l<<"  ";
	for(i=0;i<a[l].size();i++){
		if(v[a[l][i]]!=1){
			p.push(a[l][i]);
			v[a[l][i]]=1;
			colour[a[l][i]]=1-colour[l];
	        }
		else if(colour[a[l][i]]==colour[l]){
			cout<<"This is not biportite graph"<<endl;
			return;

		}
	}
        }
	cout<<"This is biportite graph"<<endl;
}



int main(){
	int i,v,s,e,d;
	cout<<"enter the no of edges and vertices ";
	cin>>e>>v;
	vector<int>a[v];
	for(i=0;i<e;i++){
		cout<<"enter the vertices in between which node exist  ";
		cin>>s>>d;
		a[s].push_back(d);
		a[d].push_back(s);
	}
	bfs(a,v,0);
	return 0;
}
