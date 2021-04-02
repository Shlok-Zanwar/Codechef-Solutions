// https://www.codechef.com/MARCH21C/problems/IRSTXOR

#include <bits/stdc++.h>
using namespace std;

string toBinary(int n)
{
    std::string r;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    return r;
}


int whatIsIt(char a, char b){
    if(a == b){
        return 0;
    }
    else{
        return 1;
    }
}


int main(){
    long noOfCases;
    cin >> noOfCases;
    long c, i, j, d_low, d, temp, maximum, current;

    while(noOfCases --){
        cin >> c;
        d = int(log2(c)) + 1;

        string c_binary = toBinary(c);
        
        maximum = 0;
        d_low = pow(2, (d-1));

        // for(i = 0; i < d_low; i++ ){
            string check_binary = toBinary(d_low - 1);
            temp = c_binary.size() - check_binary.size();
            // cout << temp << endl;

            current = 0;

            while(temp --){
                check_binary = "0" + check_binary;
            }
        

            // cout << i << " " << check_binary << endl;

            for(j = 0; j < d; j++){
                    
                if(whatIsIt(check_binary[j], c_binary[j]) == 1){
                    current += pow(2, d-j-1);
                }
            }

            // cout << current << endl;

            maximum = max(maximum, current*(d_low-1));

        // }

        cout << maximum << endl;

    }

}