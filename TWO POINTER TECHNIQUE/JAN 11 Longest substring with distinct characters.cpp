class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
       int n=s.size();
       int maxLength=0;
       int lastSeen[26];
       
       for(int i=0;i<26;i++){
           lastSeen[i]=-1;
       }
       int start=0;
       
       for(int end=0;end<n;end++){
           int charIndex=s[end]-'a';
           
           if(lastSeen[charIndex]>=start){
               start=lastSeen[charIndex]+1;
           }
           lastSeen[charIndex]=end;
           maxLength=max(maxLength,end-start+1);
       }
       return maxLength;
    }
};