#include <iostream>
#include <ostream>
#include <list>
#include <map>

using namespace std;

typedef pair<double, int> term;

class Polynomial: public list<term> {
public:
    void addterm(double factor, int times) {
        if (factor == 0) {
            return;
        }
        for(auto it = begin(); it != end(); it++) {
            if (it->second > times) {
                insert(it, term(factor, times));
                return;
            } else if (it->second == times) {
                it->first += factor;
                return;
            }
        }
        push_back(term(factor, times));
    }
    Polynomial operator+(Polynomial& other) {
        Polynomial result;
        auto ti = this->begin();
        auto oi = other.begin();
        while (ti != this->end() && oi != other.end()) {
            if (ti->second == oi->second) {
                result.addterm(ti->first + oi->first, ti->second);
                ti++;
                oi++;
            } else if (ti->second < oi->second) {
                result.push_back(*ti);
                ti++;
            } else {
                result.push_back(*oi);
                oi++;
            }
        }
        while (ti != this->end()) {
            result.push_back(*ti);
            ti++;
        }
        while (oi != other.end()) {
            result.push_back(*oi);
            oi++;
        }
        return result;
    }
    friend ostream& operator<<(ostream& os, Polynomial p) {
        auto print = [&os](double factor, int times){   
            if (factor != 0) {
                if (times == 0) {
                    os << factor;
                } else if (factor == 1) {
                    if (times == 1) {
                        os << "x";
                    } else {
                        os << "x^" << times;
                    }
                } else if (factor == -1) {
                    if (times == 1) {
                        os << "-x";
                    } else {
                        os << "-x^" << times;
                    }
                } else {
                    if (times == 1) {
                        os << factor <<"x";
                    } else {
                        os << factor << "x^" << times;
                    }
                }
            }
        };
        print(p.back().first, p.back().second);
        auto i = p.rbegin();
        i++;
        for (; i != p.rend(); i++) {
            if (i->first > 0) {
                os << "+";
            }
            print(i->first, i->second);
        }
        return os;
    }
};

int main()
{
    Polynomial p[2];
    for (int n = 0; n < 2; ++n) {
        cout << "请输入第" << n + 1 << "个多项式：" << endl;
        int size;
        cout << "请输入多项式的项数：" << endl;
        cin >> size;
        for (int i = 0; i < size; ++i) {
            double factor;
            int times;
            cout << "输入第" << i + 1 << "项的系数和指数" << endl;
            cin >> factor >> times;
            p[n].addterm(factor, times);
        }
        cout << p[n] << endl;
    }
    cout << "最后的多项式为：" << p[0] + p[1] << endl;
    return 0;
}