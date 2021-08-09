// https://www.codechef.com/COOK131B/problems/CHFPLN


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    ll cases, i, ans, len;
    
    // cout << "cases : ";
    cin >> cases;
    
    while (cases --){
        // cout << "len : ";
        ans = 0;
        cin >> len;
        ll arr[len];
        unordered_map<int, int> hashTable;
        // cout << "arr : ";
        for(i = 0; i < len; i ++){
            cin >> arr[i];
            hashTable[arr[i]]++;
        }

        for(auto x: hashTable){
	        if(x.second < ((x.first)-1)){
	            ans += x.second;
	        }
	        else{
	            ans += ((x.first) - 1);
	        }
	    }
	    cout<< ans <<endl;
    }
    
}
