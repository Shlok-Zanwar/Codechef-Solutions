// https://www.codechef.com/MARCH21C/problems/SPACEARR

#include <bits/stdc++.h>
using namespace std;

int main() {
	long noOfCases, len, i;
	cin >> noOfCases;
	
	while(noOfCases -- ){
	    cin >> len;
	    long arr[len + 1], sum = 0, n;
	    arr[0] = 0;
	    
	    for(i = 1; i <= len; i++){
	        cin >> arr[i];
	        sum += arr[i];
	    }
	    
	    
	    sort(arr, arr + len + 1);
	    
	    for(i = 0; i <= len; i++){
	        if(arr[i] > i){
	            break;
	        }
	    }
	    
	    if(i == len + 1){
	        n = ((len)*(len + 1)) / 2;
	        if((n - sum)%2 == 1 ){
	            cout << "First" << endl;
	        }
	        else{
	            cout << "Second" << endl;
	        }
	    }
	    else{
	        cout << "Second" << endl;
	    }
	    
	}
	
	return 0;
}