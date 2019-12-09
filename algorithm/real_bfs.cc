#include <bits/stdc++.h>
using namespace std;
void make_adjList(unordered_map<int,unordered_set<int>>& adjList,int num_edge){
	int u,v;
	while(num_edge--){
		cout<<"ter edge: ";
		cin>>u>>v;
		cout<<""<<endl;
		adjList[u].insert(v);
		adjList[v].insert(u);
	}
}
void dfs(unordered_map<int,unordered_set<int>>& adjList,int num_vertex,int start){
	queue<int> bfsq;
	bool visited[num_vertex];
	bfsq.push(start);
	visited[start] = true;
	while(!bfsq.empty()){
		int elt = bfsq.front();
		auto itr1 = adjList.find(elt);
		unordered_set<int> tmp = itr1->second;
		auto itr2 = tmp.begin();
		while(itr2 !=tmp.end()){
			if(visited[*itr2] == false){
			       	bfsq.push(*itr2);
				visited[*itr2] = true;
			}
			itr2++;
		}
		bfsq.pop();
		cout<<elt<<"\n";	
	}	
}
int main(void){
	int num_vertex,num_edge;
	cout<<"enter no of vertex: ";
	cin>>num_vertex;
	cout<<""<<endl;
	cout<<"enter no of edge: ";
	cin>>num_edge;
	cout<<"enter starting vertex: ";
	int start;
	cin>>start;
	cout<<""<<endl;
	cout<<""<<endl;
	unordered_map<int,unordered_set<int>> adjList;
	make_adjList(adjList,num_edge);
	cout<<""<<endl;
	dfs(adjList,num_vertex,start);
}

