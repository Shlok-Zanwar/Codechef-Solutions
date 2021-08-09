// https://www.codechef.com/COOK131B/problems/CHFGCD

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int solve(ll num1, ll num2){
    if(gcd(num1, num2) != 1){
        return 0;
    }

    if(num1%2 == 1 && num2%2 == 1){
        if(gcd(num1 + 1, num2) != 1){
            return 1;
        }
        else if(gcd(num1, num2 + 1) != 1){
            return 1;
        }
        else{
            return 2;
        }
    }
    else{
        return 1;
    }
}



int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    ll cases, num1, num2;
    
    // cout << "cases : ";
    cin >> cases;
    
    while (cases --){
        cin >> num1 >> num2;
        cout << solve(num1, num2) << "\n";
    }

}

