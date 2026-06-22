class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n +1);
        vector<int> color_list(n+1 , 0);
        for(const auto& edges : dislikes){
            int a = edges[0];
            int b = edges[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int current_c;
        int m = n;
        vector<int> stack;
        for(int i = 1 ; i <= n ; ++i){
            if(color_list[i] != 0) continue;
            stack.push_back(i);
            color_list[i] = 1;
            while(!stack.empty()){
                int node = stack.back();
                stack.pop_back();
                current_c = color_list[node];
                for(const auto& nodes : adj[node]){
                    if(color_list[nodes] == 0){
                        stack.push_back(nodes);
                        color_list[nodes] = 3 - current_c;
                    }
                    else{
                        if(color_list[nodes] == current_c) return false;
                    }
                }
            }
        }
    return true;  
    }
};