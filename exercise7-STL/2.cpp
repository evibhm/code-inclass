#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>

using namespace std;

multimap<string, string> AddressBook;

inline void read_data()
{
    const char* filename = "contact_data.txt";
    fstream fin(filename);
    string name;
    string number;
    while (fin >> name >> number) {
        AddressBook.insert({name, number});
    }
}

inline void add_contact()
{
    string name, number;
    cout << "新联系人的名字是：";
    cin >> name;
    cout << "新联系人的号码是：";
    cin >> number;
    AddressBook.insert({name, number});
    cout << "添加成功" << endl;
}

inline void delete_contact()
{
    string name;
    cout << "想要删除的联系人姓名是：";
    cin >> name;
    auto target = AddressBook.find(name);
    if (target != AddressBook.end()) {
        int counts = AddressBook.count(name);\
        vector<std::multimap<std::__cxx11::string, std::__cxx11::string>::iterator> iters;
        while (counts--) {
            iters.emplace_back(target++);
        }
        while (!iters.empty()) {
            cout << "查找到" << name << "的电话号码如下："  << endl;
            for (int i = 0; i < iters.size(); ++i) {
                cout << "\t" << i + 1 << ". 姓名：" << iters[i]->first << " 联系号码：" << iters[i]->second << endl;
            }
            int op;
            cout << "请选择要删除的号码的序号（输入 0 删除全部）：";
            cin >> op;
            if (op <= 0) {
                AddressBook.erase(name);
                cout << "删除成功" << endl;
                return;
            } else if (op <= iters.size()) {
                AddressBook.erase(iters[op-1]);
                iters.erase(iters.begin() + (op - 1));
                cout << "删除成功，是否继续删除（0, 1）?";
                cin >> op;
                if (!op) {
                    return;
                }
            } else {
                cout << "ERROR: OUT OF RANGE!" << endl;
                return;
            }
        }
    } else {
        cout << "通讯录里找不到此人";
    }
}

void search_contact()
{
    string name;
    cout << "请输入要查找的联系人的姓名：";
    cin >> name;
    auto target = AddressBook.find(name);
    if (target != AddressBook.end()) {
        int counts = AddressBook.count(name);
        while (counts--) {
            cout << "姓名：" << target->first << " 联系号码：" << target->second << endl;
            target++;
        }
    } else {
        cout << "通讯录里找不到此人";
    }
}

int main()
{
    read_data();
    while(true) {
        cout << "***通讯录管理***" << endl;
        cout << "   1. 新建联系人" << endl;
        cout << "   2. 搜索联系人" << endl;
        cout << "   3. 删除联系人" << endl;
        cout << "***菜单到此结束***" << endl;
        int op;
        cin >> op;
        if (op == 1) {
            add_contact();
        } else if (op == 2) {
            search_contact();
        } else if (op == 3) {
            delete_contact();
        } else {
            cout << "欢迎下次再见" << endl;
            return 0;
        }
        getchar();
        getchar();
    }
}