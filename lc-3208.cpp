class Solution {
    public:
        int numberOfAlternatingGroups(vector<int>& colors, int k) {
            colors.insert(colors.end(),colors.begin(),colors.begin()+k-1);
            int ans=0,i=0;
            for(int j=1;j<colors.size();j++){
                   if(colors[j]==colors[j-1]) {
                    i=j;
                    continue;
                   }
                   else{
                       if((j-i+1)==k) {
                        ans++;
                        i++;
                       }
                   }
            }
            return ans;
        }
    };