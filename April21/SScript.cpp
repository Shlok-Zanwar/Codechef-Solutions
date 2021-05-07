#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int noOfCases, i, cnt, len, k;
	string str;
	cin >> noOfCases;
	
	while(noOfCases --){
	    cin >> len >> k;
	    cin >> str;
	    cnt = 0;
	    for(i =0; i < str.length(); i ++){
	       if(str[i] == '*'){
	           cnt ++ ;
	       }
	       else{
	           cnt = 0;
	       }
	       
	       if(cnt == k){
	           cout << "YES\n";
	           break;
	       }
	    }
	    
	    if(i == str.length()){
	        cout << "NO\n";
	    }
	    
	    
	}
	return 0;
}