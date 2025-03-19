class Solution {
    public:
        int divide(int dividend, int divisor) {
               long   ans=0;
                bool sign=true;
                if(dividend==divisor) return 1;
                if(dividend>=0&&divisor<0) sign=false;
                if(dividend<=0&&divisor>0) sign =false;
                long  m=abs(static_cast<long>(dividend));
                long  n=abs(static_cast<long>(divisor));
                   while(m>=n){
                    int count=0;
                    while(m>=(n<<(count+1))){
                        count+=1;
                    }
                    ans+=(1<<(count));
                    m-=(n<<(count));
                   }
                   if(ans==(1<<31)&&sign) return INT_MAX;
                   if(ans==(1<<31)&&!sign) return INT_MIN;
                return sign?ans:-ans;
    
        }
    };