class Solution {
public:
    //lets convert it to a dp code
    //we have a string of length 100 
    //dp[index][open] now the maximum open can be the length of the string
    /*int dp[101][101];

    bool solve(int idx, int open, string& s, int n){
        if(idx >=n){
            return open == 0;
        }
        if(dp[idx][open]!=-1){
            return dp[idx][open];
        }
        bool flag = false;
        //first case 
        if(s[idx] == '*'){
            if(open>0){
                flag |= solve(idx+1,open-1,s,n);//special check condition to avoid the case like ))((
            }
            flag |= solve(idx+1,open+1,s,n);
            flag |= solve(idx+1,open,s,n);

        }
        else if(s[idx] == '('){
            flag |= solve(idx+1,open+1,s,n);
        }
        else if(s[idx] == ')' && open >0){//special check condition to avoid the case like ))((
            flag |= solve(idx+1,open-1,s,n);

        }
        return dp[idx][open] =flag;
    }*/
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<bool>>dp(n+1,vector<bool>(n+1,false));
        //the base case that came from the memoization or the recursion 
        dp[n][0] = true;
        for(int i =n-1;i>=0;i--){//explained in the video 
            for(int open =0;open<=n;open++){
                bool flag = false;
                if(s[i]=='*'){
                    flag |= dp[i+1][open+1];//considering it as a (
                    if(open >0){
                        flag |= dp[i+1][open-1]; //consedring it as a closed bracket
                    }
                    flag |= dp[i+1][open];

                }
                else{
                    if(s[i]== '('){
                        flag |= dp[i+1][open+1];
                    }
                    else if(open >0){
                        flag |= dp[i+1][open-1];
                    }
                }
                dp[i][open] = flag;
            }
        }
        return dp[0][0];

    }
};
