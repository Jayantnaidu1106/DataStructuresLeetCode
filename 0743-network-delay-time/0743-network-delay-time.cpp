class Solution {
public:
    typedef pair<int,int> P;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n + 1);
        for(auto &e : times){
            int u = e[0];
            int v = e[1];;
            int w = e[2];
            adj[u].push_back({v,w});
        }
        vector<int> dist(n + 1,1e9);
        priority_queue<P,vector<P>,greater<P>> pq;
        dist[k]= 0;
        pq.push({0,k});
        while(!pq.empty()){
            auto [d , node] = pq.top();
            pq.pop();

            if(d > dist[node]) continue;

            for(auto &it : adj[node]){
                int adjNode = it.first;
                int edgeW = it.second;
                if(d + edgeW < dist[adjNode]){
                    dist[adjNode] = d + edgeW;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        int mxi = INT_MIN;
        for(int i = 1; i <= n ;i++){
            if(dist[i] == 1e9) return -1;
            if(dist[i] > mxi){
                mxi = dist[i];
            }
        }
        if(mxi == 1e9) return -1;
        return mxi;
    }
};