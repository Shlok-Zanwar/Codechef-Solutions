// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;

// vector <int> factors(int x) {
//     // We will store all factors in `result`
//     vector <int> result;
//     int i = 1;
//     // This will loop from 1 to int(sqrt(x))
//     while(i*i <= x) {
//         // Check if i divides x without leaving a remainder
//         if(x % i == 0) {
//             result.push_back(i);
//             // Handle the case explained in the 4th
//             if(x/i != i) {
//                 result.push_back(x/i);
//             }
//         }
//         i++;
//     }
//     sort(result.begin(), result.end());
//     return result;
// }




// int main(){
//     // ios_base::sync_with_stdio(false);
//     // cin.tie(NULL);

//     ll cases, i, k, len, myEnd;
    
//     cout << "cases : ";
//     cin >> cases;
    
//     while (cases --){
//         cin >> k;
//         myEnd = 4*k + 1;


//     }

// }






#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll k;
        cin>>k;
        ll s=0;
        for(ll i = 1; i <= 2*k + 1; i ++){
            cout << k + i*i << " ";
        }
        cout << endl << " ";

        for(ll i=1;i<=2*k ;i++)
        {
            cout << gcd(2*i+1, k+(i+1)*(i+1)) << "  ";
            s+=gcd(2*i+1, k+(i+1)*(i+1));
        }
        cout << "\n\n";
        cout<<s<<"\n";
    }
    return 0;
}

//  3  5  7  3  1  1  15  1  1  21  1  25  3  1  1  3  35  1  3  1  1  15  1  7  3  1  5  3  1  1  21  5  1  3  1  1  75  7  1  3  1  5  3  1  7  3  5  1  3  1  1  105  1  1  3  1  5  3  7  1  3  25  1  3  1  7  15  1  1  3  1  5  21  1  1  3  5  1  3  7  1  15  1  1  3  1  175  3  1  1  3  5  1  21  1  1  15  1  1  3  7  5  3  1  1  3  5  7  3  1  1  75  1  1  21  1  5  3  1  1  3  35  1  3  1  1  15  1  7  3  1  5  3  1  1  21  25  1  3  1  1  15  7  1  3  1  5  3  1  7  3  5  1  3  1  1  105  1  1  3  1  25  3  7  1  3  5  1  3  1  7  15  1  1  3  1  5  21  1  1  3  5  1  3  7  1  75  1  1  3  1  35  3  1  1  3  5  1  21  1  1  15  1  1  3  7  5  3  1  1  3  25  7  3  1  1  15  1  1  21  1  5  3  1  1  3  35  1  3  1  1  15  1  7  3  1  25  3  1  1  21  5  1  3  1  1  15  7  1  3  1  5  3  1  7  3  5  1  3  1  1  525