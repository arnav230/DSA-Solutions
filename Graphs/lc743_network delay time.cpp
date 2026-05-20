class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> adj(n+1);
        for (auto &t : times) {
            adj[t[0]].push_back({t[1], t[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        vector<int> dist(n+1, 1e9);
        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {

            auto [time, node] = pq.top();
            pq.pop();

            if (time > dist[node]) continue;

            for (auto &p : adj[node]) {
                int nbr = p.first;
                int w   = p.second;

                if (dist[node] + w < dist[nbr]) {
                    dist[nbr] = dist[node] + w;
                    pq.push({dist[nbr], nbr});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == 1e9) return -1;    
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};
