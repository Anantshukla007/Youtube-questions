class Solution {
public: 
int M = 1e9+7;
/*
    
    int dp[1001][1001];//storage 
    int solve(int num, int &x, int n){
        
        if(n==0){
            return 1;//found 1 way
        }
       
        if(n<0){
            return 0;//false case not possible
        }

        if(dp[n][num] != -1){
            return dp[n][num];
        }
        int power = pow(num,x);
        if(power>n){
            return 0;//again false case because power can not be greater then n
        }
        int take = solve(num+1,x,n-power);
        int skip = solve(num+1,x,n);//no change

        return  dp[n][num] = (take+skip)%M;
    }*/
    int numberOfWays(int n, int x) {
       // memset(dp,-1,sizeof(dp));
        //return solve(1,x,n);

        vector<int>dp(n+1,0);//the number of ways to make sum i 
        dp[0]=1;//base case we know from recursion
        int num =1;


        while(true){
            int power = pow(num,x);
            if(power>n){
                break;//failure can not check any further
            }
            for(int i =n;i>=power;i--){
                dp[i]=(dp[i]+dp[i-power])%M;//int take = solve(num+1,x,n-power);
            }
            num++;

        }
        return dp[n];//holding all the answer
        
    }
};