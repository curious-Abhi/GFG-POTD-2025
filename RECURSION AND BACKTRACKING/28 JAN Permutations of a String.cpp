class Solution {
  public:
  vector<string>res;
   void permute(string &s, string &curr,vector<bool>&vis){
        //base case 
        if(curr.size()==s.size()){
            res.push_back(curr);
            return;
        }
        
        for(int i=0;i<s.size();i++){
            if(vis[i] || (i>0 && s[i]==s[i-1]&&!vis[i-1])) continue;
            vis[i]=true;
                curr+=s[i];
                permute(s,curr,vis);
                
                curr.pop_back();
                vis[i]=false;
        }
    }
    vector<string> findPermutation(string &s) {
        // Code here there
       sort(s.begin(),s.end());
       string curr="";
       vector<bool>vis(s.size(),false);
       permute(s,curr,vis);
       return res;
    }
};