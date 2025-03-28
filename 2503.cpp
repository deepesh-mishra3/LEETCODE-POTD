
class Solution {
    public:
        vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
            int m = grid.size(), n = grid[0].size();
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};
    
         
            vector<pair<int, pair<int, int>>> cells;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    cells.push_back({grid[i][j], {i, j}});
                }
            }
    
            
            sort(cells.begin(), cells.end());
    
           
            vector<int> parent(m * n), size(m * n, 1);
            iota(parent.begin(), parent.end(), 0);
    
            function<int(int)> find = [&](int x) {
                if (parent[x] == x) return x;
                return parent[x] = find(parent[x]);
            };
    
            auto unite = [&](int a, int b) {
                int pa = find(a), pb = find(b);
                if (pa != pb) {
                    if (size[pa] < size[pb]) swap(pa, pb);
                    parent[pb] = pa;
                    size[pa] += size[pb];
                }
            };
    
            vector<int> res(queries.size(), 0);
            vector<pair<int, int>> queryWithIdx;
            
            for (int i = 0; i < queries.size(); i++) {
                queryWithIdx.push_back({queries[i], i});
            }
            
           
            sort(queryWithIdx.begin(), queryWithIdx.end());
    
            int totalConnected = 0, k = 0;
    
            
            for (auto &[qVal, idx] : queryWithIdx) {
              
                while (k < cells.size() && cells[k].first < qVal) {
                    int row = cells[k].second.first, col = cells[k].second.second;
                    int cellIdx = row * n + col;
                    for (int i = 0; i < 4; ++i) {
                        int newRow = row + dx[i], newCol = col + dy[i];
                        if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && grid[newRow][newCol] < qVal) {
                            int newIdx = newRow * n + newCol;
                            unite(cellIdx, newIdx);
                        }
                    }
                    totalConnected++;
                    k++;
                }
    
               
                if (grid[0][0] < qVal) {
                    res[idx] = size[find(0)];
                } else {
                    res[idx] = 0;
                }
            }
    
            return res;
        }
    };
    