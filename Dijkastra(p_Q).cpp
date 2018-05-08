    typedef pair<int, int> ii;   //The Only Macros I use...usually
    typedef vector<int> vi;
    vector<vector< ii > > graph;
     
    int n;
    vi dist;
     
    void dijkstra(int s)
    {
        dist.assign( graph.size() , 100000 ); dist[s] = 0;
        priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push({0, s});
     
        while(!pq.empty())
        {
            ii v = pq.top(); pq.pop();
     
            for(int i = 0 ; v.first < dist[v.second] && i < graph[v.second].size(); i++)
            {
                ii u = graph[v.second][i];
     
                if(dist[v.second] + u.second < dist[u.first])
                    pq.push({dist[u.first] = dist[v.second] + u.second, u.first});
            }
     
        }
    }
