// https://www.codechef.com/COOK131B/problems/MODEQUAL

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


bool isItPossible(ll toMake, ll from){
    ll i;
    if(from%(from-toMake) == toMake){
        return true;
    }
    else{
        return false;
    }
    // for(i = from; i > 0; i --){
    //     if(from%i == toMake){
    //         return true;
    //     }
    // }
    // return false;
}


ll solve(ll len, ll arr[]){
    ll i, noOfMin = 0;

    for(i = 1; i < len; i ++){
        if(arr[i] != arr[0]){
            break;
        }
    }
    noOfMin = i;

    for(i ; i < len; i ++){
        if(!isItPossible(arr[0], arr[i])){
            return len;
        }
    }

    return len - noOfMin;
}


int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    ll cases, i, j, len, noOfMin;
    
    // cout << "cases : ";
    cin >> cases;
    
    while (cases --){
        // cout << "len : ";
        cin >> len;
        ll arr[len];
        
        // cout << "arr : ";
        for(i = 0; i < len; i ++){
            cin >> arr[i];
        }
        sort(arr, arr + len);
        cout << solve(len, arr) << "\n";

    }

}