class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            int s=grid.size();
            vector<int>hash( s*s,0 );
            for(int i=0;i<grid.size();i++){
                for(auto k:grid[i]){
                    hash[k-1]++;
                }
            }  
            vector<int>ans;     
            int rep=0;
            int mis=0;
           for(int i=0;i<hash.size();i++){
            if(hash[i]>1) rep=i+1;
            if(hash[i]==0) mis=i+1;
           }
            ans.push_back(rep);
            ans.push_back(mis);
            return ans;
        }
    };