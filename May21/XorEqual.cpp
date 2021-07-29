#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// -----------------------------Using bruteforce to find relation------------------------------------------------

// string findBinary(ll num){
//     string ans = "";
//     while(num > 0){
//         ans += to_string(num%2);
//         num = num/2;
//     }

//     return ans;
// }


// string findXor(string str1, string str2){
//     if(str2.length() > str1.length()){
//         str1 = "0" + str1;
//     }
//     string ans = "";
//     for(ll i = 0; i < str1.length(); i ++){
//         if(str1[i] == str2[i]){
//             ans += "0";
//         }
//         else{
//             ans += "1";
//         }
//     }
//     reverse(ans.begin(), ans.end());
//     return ans;
// }


// void printVector(vector<ll> vec){
//     for(ll i = 0; i < vec.size(); i ++){
//         cout << vec[i] << " ";
//     }
//     cout << "\n";
// }

// void xorEquals(ll range){
//     ll i;
//     vector<ll> ans;
//     string str1, str2;
//     for(i = 0; i <= range; i ++){
//         // cout << "\n-----------------------\n";
//         // cout << i << "\n";

//         str1 = findXor(findBinary(i), findBinary(i+1));
//         str2 = findXor(findBinary(i+2), findBinary(i+3));

//         // cout << findBinary(i) << " xor " << findBinary(i + 1) << " = " << str1 << "\n";
//         // cout << findBinary(i + 2) << " xor " << findBinary(i + 3) << " = " << str2 << "\n";

//         if(str1 == str2 || ("0" + str1) == str2){
//             ans.push_back(i);
//         }
//     }

//     cout << "\nx-x-x-x-x-x-x-x-x-x-x-x-x-x-x\n";
//     // printVector(ans);
//     cout << (ans.size());

// }

// -------------------------------------------------------------------------------------------------


//  Cause large constraint
ll power(ll base, ll coeff, ll mod){
    ll res = 1;
 
    base = base % mod;
 
    while (coeff > 0) {
       
        if (coeff & 1)
            res = (res * base) % mod;
 
        coeff = coeff >> 1;
        base = (base * base) % mod;
    }
    return res;
}


int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    ll cases, i, len, actCoeff;
    string coeff;
    // cout << "cases : ";
    cin >> cases;
    
    while (cases --){
        cin >> len;
        len --;
        coeff = to_string(len);
        actCoeff = 0;
        
        for(i = 0; i < coeff.length(); i ++){
            actCoeff = (actCoeff*10 + coeff[i] - '0')%(1000000006);
        }
        
        cout << power(2, actCoeff, 1000000007) << "\n";
    }
	return 0;

}
