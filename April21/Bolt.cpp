#include <iostream>
using namespace std;

double round(double var){
    double value = (int)(var * 100 + .5);
    return (double)value / 100;
}

int main() {
	// your code goes here
	long long noOfCases, i;
	double a, b, c, s;
	string str;
	cin >> noOfCases;
	
	while(noOfCases --){
	    cin >> a >> b >> c >> s;
	    if(round(100/ (a*b*c*s)) < 9.58){
	        cout << "YES\n";
	    }
	    else{
	        cout << "NO\n";
	    }
	    
	}
	return 0;
}