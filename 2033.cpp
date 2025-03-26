class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            vector<int> arr;
            for (int i = 0; i < grid.size(); ++i) {
                for (int j = 0; j < grid[0].size(); ++j) {
                    arr.push_back(grid[i][j]);
                }
            }
            sort(arr.begin(), arr.end());
    
            int n = arr.size();
            int median = arr[n / 2];
            int count =0;
            for(int i=0;i<grid.size();i++){
                for(int j=0;j<grid[0].size();j++){
                     int diff =abs(grid[i][j]-median);
                     if((diff%x)!=0)  return -1;  
                     count+=(diff/x);
                }
            }
            return count;
        }
    };