#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if(a==b || b==c || a==c){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
	// your code goes here
	return 0;
}
