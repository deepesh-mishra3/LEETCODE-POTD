class Solution {
    public:
        // Recursive function to search the word in the grid
        bool search(vector<vector<char>>& board, string& word, int i, int j, int index) {
            // Base case: if the entire word is matched
            if (index == word.size()) {
                return true;
            }
            
            // Boundary conditions and character mismatch check
            if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index]) {
                return false;
            }
            
            // Mark the current cell as visited by using a special character
            char temp = board[i][j];
            board[i][j] = '#';  // Use '#' to mark the visited cell
            
            // Explore all 4 possible directions
            bool found = search(board, word, i + 1, j, index + 1) ||  // Down
                         search(board, word, i - 1, j, index + 1) ||  // Up
                         search(board, word, i, j + 1, index + 1) ||  // Right
                         search(board, word, i, j - 1, index + 1);    // Left
            
            // Restore the original character after backtracking
            board[i][j] = temp;
            
            return found;
        }
    
        bool exist(vector<vector<char>>& board, string word) {
            int m = board.size(), n = board[0].size();
            
            // Start from every cell in the grid
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    // Start DFS if the first character matches
                    if (board[i][j] == word[0] && search(board, word, i, j, 0)) {
                        return true;
                    }
                }
            }
            return false;
        }
    };
    