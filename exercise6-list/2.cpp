#include <iostream>
#include <list>
#include <string>

using namespace std;

class Card {
private:
    static size_t card_id_setted;
    size_t card_id;
    string name;
    string phone_number;
    double balance;
    double point;
public:
    explicit Card(string&& name, string&& phone_number, double money){
        this->name = name;
        this->phone_number = phone_number;
        this->card_id = card_id_setted++;
        this->point = 0;
        this->balance = money;
    }
    explicit Card(string& name, string& phone_number, double money){
        this->name = name;
        this->phone_number = phone_number;
        this->card_id = card_id_setted++;
        this->point = 0;
        this->balance = money;
    }
    bool bill(double money) {
        if (balance < money) {
            cerr << "ERROR: 余额不足" << endl;
            return false;
        }
        balance -= money;
        return true;
    }
    void rePoint(double point) {
        this->point += point;
    }
    void consume(double money, double point) {
        if (bill(money)) {
            rePoint(point);
            cout << name << "本次消费金额和积分如下：" << endl;
            cout << money << "元，" << point << "分" << endl;
        }
    }
};

size_t Card::card_id_setted = 100000000;

typedef list<Card> CardSet;

int main()
{
    CardSet cards;
    cards.push_back(Card("张华", "10086", 5000));
    cards.push_back(Card("何欢", "10010", 10000));
    cards.front().consume(531, 100);
    cards.back().consume(472, 110);
    return 0;
}