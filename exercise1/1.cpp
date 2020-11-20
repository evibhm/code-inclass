#include<iostream>
#include<cmath>

int main(){
    double x;
    std::cin >> x;
    if(x >= 1 && x < 2){
        std::cout << (3*x + 5);
    }else if(x >= 2 && x < 3){
        std::cout << (2*sin(x) - 1);
    }else if(x >= 3 && x < 5){
        std::cout << sqrt(1 + x*x);
    }else if(x >=5 && x < 8){
        std::cout << (x*x - 2*x + 5);
    }
    return 0;
}
