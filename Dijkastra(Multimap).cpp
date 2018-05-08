    int dijkstra(int s){
    	for (int i=0; i<MAXN; i++){
    		dist[i] = INT_MAX;
    	}
    	dist[s] = 0;
    	multimap<int,int> pq;
    	multimap<int,int>::iterator it;
    	pq.insert(multimap<int,int>::value_type(0,s));
     
    	while(!pq.empty()){
    		it = pq.begin();
    		int u = (*it).second; int cost_to_u = (*it).first;
    		if (cost_to_u<=dist[u]){
    		int out_degree = Al[u].size();
    		for (int i=0; i<out_degree; i++){
    			int v = Al[u][i];
    			int new_cost = cost_to_u + cost[u][v];
    			if (new_cost<dist[v]){
    				dist[v] = new_cost;
    				pq.insert(multimap<int,int>::value_type(dist[v],v));
    			}
    		}
    		}
    		pq.erase(it);
    	}
    	return 0;
    }
