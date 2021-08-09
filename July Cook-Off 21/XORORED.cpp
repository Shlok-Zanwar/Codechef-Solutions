// https://www.codechef.com/COOK131B/problems/XORORED


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


string toBinary(ll n, ll binaryLen){
    string r = "", ans = "";
    ll i, toAdd;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    toAdd = binaryLen - r.length();
    // cout << n << " " << r.length() << "\n";
    while(toAdd --){
        r = "0" + r;
    }
    return r;
}


ll areAllOnes(ll len, ll index, string binaryArr[]){
    ll i;
    // cout << index << " ";
    for(i = 0; i < len; i ++){
        if(binaryArr[i][index] == '0'){
            // cout << i << "\n";
            return false;
        }
    }
    // cout << "\n";

    return true;
}


ll isAtleast1one(ll len, ll index, string binaryArr[]){
    ll i;
    for(i = 0; i < len; i ++){
        if(binaryArr[i][index] == '1'){
            return true;
        }
    }

    return false;
}


void solve(ll len, ll arr[], ll maxNum){
    ll binaryLen = ceil(log2(maxNum)) == floor(log2(maxNum)) ? ceil(log2(maxNum)) + 1 : ceil(log2(maxNum)) ; 
    // cout << "binaryLen" << binaryLen << "\n";

    string binaryArr[len], X = "", minValue = "";
    ll i;

    for(i = 0; i < len; i ++){
        binaryArr[i] = toBinary(arr[i], binaryLen);
        // cout << "hi " << arr[i] << " " <<binaryArr[i] << endl;
    }

    for(i = 0; i < binaryLen; i ++){
        // cout << i << "\n" << areAllOnes()
        if(areAllOnes(len, i, binaryArr)){
            X += "1";
            minValue += "0";
        }
        else{
            X += "0";
            if(isAtleast1one(len, i, binaryArr)){
                minValue += "1";
            }
            else{
                minValue += "0";
            }
        }
    }

    cout << stoi(X, 0, 2) << " " << stoi(minValue, 0, 2) << "\n";
    return;
}


ll maximum(ll a, ll b){
    return a >= b ? a : b;
}


int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    ll cases, i, j, len, maxNum;
    
    // cout << "cases : ";
    cin >> cases;
    
    while (cases --){
        // cout << "len : ";
        cin >> len;
        ll arr[len];
        maxNum = 0;

        // cout << "arr : ";
        for(i = 0; i < len; i ++){
            cin >> arr[i];
            maxNum = maximum(maxNum, arr[i]);
        }
        solve(len, arr, maxNum);
    }

}

