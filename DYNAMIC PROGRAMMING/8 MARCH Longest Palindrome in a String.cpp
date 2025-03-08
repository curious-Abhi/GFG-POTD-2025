class Solution {
    public:
    
    int length(int left,int right,string &s){
        int len=0;
        while(left>=0 && right<s.size()){
            if(s[left]==s[right]){
                len+=2;
                left--;
                right++;
            }else break;
        }
        return len;
    }
      string longestPalindrome(string &s) {
          // code here
          int n=s.size();
          int maxLength=1;
          int start=0;
          
          //odd
          for(int i=0;i<n;i++){
              int len=1+length(i-1,i+1,s);
              if(len>maxLength){
                  maxLength=max(len,maxLength);
                  start=i-len/2;
              }
          }
          
          //even
            for(int i=1;i<n;i++){
              int len=length(i-1,i,s);
              if(len>maxLength){
                  maxLength=max(len,maxLength);
                  start=i-len/2;
              }
          }
          
          return s.substr(start,maxLength);
      }
  };