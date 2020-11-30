#include <iostream>
#include <cstdio>

int main()
{
    int priceMap[9][10] = {
        10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
        10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
        10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
        10, 10, 20, 20, 20, 20, 20, 20, 10, 10,
        10, 10, 20, 20, 20, 20, 20, 20, 10, 10,
        10, 10, 20, 20, 20, 20, 20, 20, 10, 10,
        20, 20, 30, 30, 40, 40, 30, 30, 20, 20,
        20, 30, 30, 40, 50, 50, 40, 30, 30, 20,
        30, 40, 50, 50, 50, 50, 50, 50, 40, 30
    };
    std::cout << "******************************************\n"
              << "*****  Welcome to BUYTICKETS system *****\n"
              << "******************************************\n";
    while (true) {
        char oper;
        std::cout << "\nThe operator is as follows:\n"
                  << "******************************************\n"
                  << "operator 0: Quit the BUYTICKETS system.\n"
                  << "operator 1: Order a seats in the theater.\n"
                  << "operator 2: Buy a ticket in given price.\n"
                  << "******************************************\n"
                  << "Please input the operator order:";
        oper = getchar();
        switch (oper) {
            case '0': {
                return 0;
            }
            case '1': {
                int x, y;
                int tickerNum;
                std::cout << "\nHow many tickets do you want to buy? ";
                std::cin >> tickerNum;
                while (tickerNum) {
                    std::cout << "\nPlease input the seat you want:";
                    std::cin >> x >> y;
                    --x;
                    --y;
                    if (priceMap[x][y]) {
                        std::cout << "I have reserved it for you!\n";
                        priceMap[x][y] = 0;
                        --tickerNum;
                    } else {
                        std::cout << "Sorry, the seat has ordered by other people, please choose another seat.";
                    }
                    if (tickerNum) {
                        std::cout << "You need " << tickerNum << " more tickets\n";
                    }
                }
                break;
            }
            case '2': {
                int ticketPrice;
                int cnt = 0;
                std::cout << "Please input the price of seat you want:";
                std::cin >> ticketPrice;
                for (int i = 0; i < 9; ++i) {
                    for (int j = 0; j < 10; ++j) {
                        if (ticketPrice == priceMap[i][j]) {
                            std::cout << "(" << i + 1 << ", " << j + 1 << ") ";
                            ++cnt;
                        }
                        if (cnt % 10 == 0 && cnt) {
                            std::cout << std::endl;
                        }
                    }
                }
                if (!cnt) {
                    std::cout << "The price " << ticketPrice << "yuan ticket has sold out.\n";
                    continue;
                }
                break;
            }
            default: {
                std::cout << "operater Invalid!\n";
                continue;
            }
        }
    }
    return 0;
}