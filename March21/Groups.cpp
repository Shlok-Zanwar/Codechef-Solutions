// https://www.codechef.com/MARCH21C/problems/GROUPS

#include <iostream>
using namespace std;

int main() {
	long noOfCases, i, groups;
	cin >> noOfCases;
	
	string seating;
	
	while(noOfCases --){
	    cin >> seating;
	    groups = 0;
	    
	    for(i = 0; i < seating.length(); i++ ){
	        if(seating[i] == '1'){
	            while(true){
	                if(i == seating.length()){
	                    groups ++;
	                    break;
	                }
	                if(seating[i+1] == '0'){
	                    groups ++;
	                    break;
	                }
	                i++;
	            }
	        }
	    }
	    
	    cout << groups << endl;
	    
	}
	
	return 0;
}
