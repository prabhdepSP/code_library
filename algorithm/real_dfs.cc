#include <bits/stdc++.h>
using namespace std;
void dfs(unordered_map<int,unordered_set<int>>& adjList,int num_vertex,int start){
	stack<int> dfs_stack;
	bool visited[num_vertex];
	for(int i=0;i<num_vertex;i++) visited[i] = false;
	dfs_stack.push(start);
	visited[start] = true;
	while(!dfs_stack.empty()){
		int elt = dfs_stack.top();
		auto itr = adjList.find(elt);
		unordered_set<int> tmp = itr->second;
		auto itr2 = tmp.begin();
		dfs_stack.pop();
		while(itr2 != tmp.end()){
			if(!visited[*itr2]) {
				dfs_stack.push(*itr2);
				visited[*itr2] = true;
			}
			itr2++;
		}
		cout<<elt<<" ";
	}
}
void make_adjList(unordered_map<int,unordered_set<int>>& adjList,int num_edge){
	int u,v;
	while(num_edge--){
		cout<<"nter edge :";
		cin>>u;
		cin>>v;
		cout<<""<<endl;
		adjList[u].insert(v);
		adjList[v].insert(u);
	}
}
int main(void){
	int num_vertex,num_edge;
	cout<<"nter number of vertex :";
	cin>>num_vertex;
	cout<<""<<endl;
	cout<<"nter number of edges :";
	cin>>num_edge;
	cout<<""<<endl;
	unordered_map<int,unordered_set<int>> adjList;
	make_adjList(adjList,num_edge);
	dfs(adjList,num_vertex,2);
}
