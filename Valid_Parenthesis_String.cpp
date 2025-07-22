class Solution {
public:
    int dp[101][101];
    bool check(string s, int open , int index ,int n){
        if(index==n){
            return open ==0;
        }
        //there are three conditions right 
        //first condition if open (
        if(dp[index][open]!=-1){
            return dp[index][open];
        }
        bool flag = false;
        if(s[index] == '(' ){
            flag |= check(s, open+1, index+1, n);

        }
        //checking for the star case
        else if(s[index]== '*'){
            //there are three choices for the star itself
            if(open >0){
                flag |= check(s,open-1,index+1,n);
            }
            flag |= check(s,open+1,index+1,n);
            flag |= check(s,open, index+1, n);
        }
        else if(open>0){
            flag |= check(s,open-1,index+1,n);
        }
        return dp[index][open] =flag;

    }
    bool checkValidString(string s) {
        int n = s.length();
        memset(dp,-1,sizeof(dp));
        return check(s,0,0,n);

        
    }
};