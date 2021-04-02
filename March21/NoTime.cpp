// https://www.codechef.com/MARCH21C/problems/NOTIME/

#include <iostream>
using namespace std;

int main() {
	long noOfCases, hoursLeft, hoursNeeded, temp;
	cin >> noOfCases >> hoursNeeded >> hoursLeft;
	
	string ans = "NO";
	
	while(noOfCases --){
	    cin >> temp;
	    if(hoursLeft + temp >= hoursNeeded){
	        ans = "YES";
	    }
	}
	
	cout << ans << endl;
	return 0;
}
