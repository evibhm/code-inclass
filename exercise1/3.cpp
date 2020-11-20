#include<iostream>

int main(){
    double head, foot, ji, tu;
    std::cout << "Please input the head and the foot:\n";
    std::cin >> head >> foot;
    tu = foot/2 - head;
    ji = head - tu;
    if(tu < 0 || ji < 0 ||  (tu - int(tu)) != 0){
        std::cout << "ERROR\n";
    }else{
        std::cout << "ji = " << ji << " tu = " << tu << std::endl;
    }
    return 0;
}
