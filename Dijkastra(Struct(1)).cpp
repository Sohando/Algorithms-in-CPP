    #include <cstdio>
    #include <iostream>
    #include <vector>
    #include <climits>
    #include <queue>
    using namespace std;
    vector < vector <int> > graph;
    vector < vector <int> > weight;
    vector < int> cost;
    int N;
    struct cmp
    {
      bool operator()(const int &lhs, const int &rhs) const
      {
        return cost[lhs] > cost[rhs];
      }
    };
    int min(int a,int b)
    {
    	if(a<b)
    		return a;
    	return b;
    }
    priority_queue <int,vector<int>,cmp> pq;
    int dijkstra(int from,int to)
    {
    	vector <bool> visited(N,false);
    	visited[from] = true;
    	cost [from] = 0;
    	pq.push(from);
    	while(!pq.empty() && !visited[to])
    	{
    		int current = pq.top();
    		pq.pop();
    		visited[current] = true;
    		for(int i=0;i<graph[current].size();i++)
    		{	
    			if(!visited[graph[current][i]])
    			{
    				cost[graph[current][i]] = min( cost[graph[current][i]] ,cost[current] + weight[current][i]);
    				pq.push(graph[current][i]);
    			}
    		}
    	}
    	return cost[to];
    }
    int main()
    {
    	int n,a,b,c;
    	cin>>n;
    	N = n;
    	for(int i=0;i<n;i++)
    	{
    		graph.push_back(vector <int> ());
    		weight.push_back(vector <int> ());
    		cost.push_back(INT_MAX);
    	}
    	cin>>a>>b>>c;
    	
    	while(a!=-1 || b!=-1)
    	{
    		graph[a].push_back(b);
    		weight[a].push_back(c);
    		cin>>a>>b>>c;
    	}
    	
    	cin>>a>>b;
    	while(a!=-1 || b!=-1)
    	{
    		cout<<dijkstra(a,b)<<endl;
    		cin>>a>>b;
    	}
    	
    }
