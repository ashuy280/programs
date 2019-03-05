#include<bits/stdc++.h>
using namespace std;
int findminvertex(int v,int distance[],int visited[]){
	int min=-1,i;
	for(i=0;i<v;i++){
		if(visited[i]==0 && (min==-1||distance[i]<distance[min])){
			min=i;
		//	cout<<"for i = "<<i<<" the min is "<<min<<endl;
			
		/*	for(int j=0;j<v;j++){
				cout<<" i am going to print  "<<j <<" th node which is "<<visited[j]<<endl;
			//cout<<"the distance of i and distance of min is "<<distance[i]<<" and "<<distance[min]<<endl;
                        }*/
		}
	}
//cout<<"the final value of min is "<<min<<endl;
return min;
}
void dijkstra(vector<pair<int,int>>a[],int s,int d,int v){
	int visited[v]={0};
        int i,j,k,min;
	int distance[v];
	for(i=0;i<v;i++)
		distance[i]=INT_MAX;
	distance[s]=0;
	for(i=0;i<v-1;i++){
		min=findminvertex(v,distance,visited);
		visited[min]=1;
	//	cout<<"the min and visited min is "<<min<<" and "<<visited[min]<<endl;
		for(j=0;j<a[min].size();j++){
			if(distance[a[min][j].first]>distance[min]+a[min][j].second)
				distance[a[min][j].first]=distance[min]+a[min][j].second;
		}
	//	cout<<"the value of i and min and distance is "<<i<<" and "<<min<<"  "<<distance[min]<<endl;
	}

	for(i=0;i<v;i++)
		cout<<"the distance between "<<s<<" and "<<i<<" = "<<distance[i]<<endl;
}

int main(){
	cout<<"enter the no of vertices and edges";
	int v,e,i,j,s,d,w;
	cin>>v>>e;
	vector<pair<int,int>>a[v];
	for(i=0;i<e;i++){
		cout<<"enter the vertices in between which edge is exist and also enter the distance between them ";
		cin>>s>>d>>w;
		a[s].push_back(make_pair(d,w));
	}
	cout<<"enter the source and destination in between which you want distance ";
	cin>>s>>d;
	dijkstra(a,s,d,v);
	return 0;
}
