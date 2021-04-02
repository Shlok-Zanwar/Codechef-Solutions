// https://www.codechef.com/MARCH21C/problems/COLGFL4

#include <bits/stdc++.h>


long maximum(long a, long b){
    if(a >= b){
        return a;
    }
    else{
        return b;
    }
}


long minimum(long a, long b){
    if(a <= b){
        return a;
    }
    else{
        return b;
    }
}


int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long noOfCases; 
    std::cin >> noOfCases; 

    while(noOfCases --){

        long people, eggs, chocolates, op, mp, cp, x, y, z, value, line1X, line2X, myY;
        std::cin >> people >> eggs >> chocolates >> op >> mp >> cp;

        myY = eggs + chocolates - 2*people;
        myY = minimum(myY, people);
        bool flag = false;
        long minCount = LONG_MAX;


        for(y = myY; y >= 0; y--){
            line1X = 2*y - chocolates + people;
            line2X = eggs - people + y;
            if(line2X < 0){
                break;
            }
            for(x = maximum(line1X, 0); x <= minimum(people, line2X); x ++){
                if(x + y > people){
                    break;
                }
                z = people - x - y;
                value = ((op*x) + (mp*y) + (cp*z));
                if( value < minCount ){
                    flag = true;
                    minCount = value;
                }
            }
        }
        if(flag){
            std::cout << minCount << "\n";
        }
        else{
            std::cout << "-1\n";
        }
    }
}