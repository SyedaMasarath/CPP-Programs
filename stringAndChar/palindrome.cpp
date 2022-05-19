#include<vector>
#include<iostream>
#include<math.h>
using namespace std;
    bool valid(char ch){
        
        if((ch>='a'&& ch<='z') || (ch>='A'&& ch<='Z') || (ch>='0'&& ch<='9')){
            return 1;  
        }
        return 0; 
}
    
    char toLowerCase(char ch){
        if((ch>='a'&& ch<='z') || (ch>='0'&& ch<='9')){
            return ch;
        }  
        else{
            char temp = ch - 'A'+'a';
            return temp;
        }
    }
    
    bool check(string s){
        int start=0;
        int end=s.length()-1;
        
        while(start<=end){
            
            if(s[start] != s[end]){
               return 0;
            }
            else{
                start++;
                end++;
            }
        }
        return 1;   
}
    bool isPalindrome(string s) {
  
        string temp="";
        
        for(int j=0; j<s.length() ;j++){
            if(valid(s[j])){
                temp.push_back(s[j]);
            }
        }
        
        for(int i=0;i<temp.length();i++){
            temp[i]= toLowerCase(temp[i]);
        }
        
        return check(temp);
    }
