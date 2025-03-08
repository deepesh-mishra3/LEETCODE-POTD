class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            int j=0;
            int white=0;
            int ans=INT_MAX;
            for(int i=0;i<blocks.size();i++){
                if(blocks[i]=='W') white++;
                k--;
                if(k==0) {ans=min(white,ans);
                
                if(blocks[j]=='W') white--;
                j++;
                k++;}
                
    
                
                
            }
            return ans;
        }
    };