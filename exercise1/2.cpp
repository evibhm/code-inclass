#include<iostream>
#include<cmath>

const double PI = acos(-1.0);

int main(){
    double radius, volume, weight;
    std::cout << "Please input the radius of the ball " << std::endl;
    std::cin >> radius;
    volume = 4.0 / 3 * PI * radius * radius * radius;
    weight = 4.0 * PI * radius * radius; 
    std::cout << "volume = " << volume << " weight = " << weight << std::endl;
    return 0;
}
