#include<bits/stdc++.h>
using namespace std;
void distance(vector<pair<int,int>>a[],int s,int d,int v){
	int i,l,j;
	queue<int>q;
	int distance[v];
	for(i=0;i<v;i++)
		distance[i]=INT_MAX;
	distance[s]=0;
	for(j=0;j<v;j++){
       	q.push(s);
        int visited[v]={0};
	visited[s]=1;
	while(!q.empty()){
		l=q.front();
		q.pop();
		for(i=0;i<a[l].size();i++){
			if(distance[s]+a[l][i].second<distance[a[l][i].first]){
				distance[a[l][i].first]=distance[l]+a[l][i].second;
				if(visited[a[l][i].first]!=1)
					q.push(a[l][i].first);
			}else if(visited[a[l][i].first]=0)
				q.push(a[l][i].first);
		}
	}
	}
	for(i=1;i<v;i++){
		cout<<"the distance betweeen "<<s<<" and "<<i<<" = "<<distance[i]<<endl;
	}

}





int main(){
	cout<<"enter the total no of vertices and edges ";
	int v,e,i,s,d,w;
	cin>>v>>e;
	vector<pair<int,int>>a[v];
	for(i=0;i<e;i++){
		cout<<"enter the vertices in between which edge exist and also enter the weight of that edge ";
		cin>>s>>d>>w;
		a[s].push_back(make_pair(d,w));
	}
	//cout<<a[0][0].second;
	//cout<<a[0][1].second;
	cout<<"enter the source and destination vertice in between which you want distance ";
	cin>>s>>d;
	distance(a,s,d,v);
	return 0;
}
