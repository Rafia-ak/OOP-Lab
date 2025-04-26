#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class User {
public:
    string user_id, first_name, last_name, address, email;
    User() {}
    User(string uid, string fname, string lname, string addr, string mail)
        : user_id(uid), first_name(fname), last_name(lname), address(addr), email(mail) {}
    void save() {
        ofstream file("users.txt", ios::app);
        file << user_id << " " << first_name << " " << last_name << " " << address << " " << email << endl;
        file.close();
    }
};

class Product {
public:
    string product_id, product_name, description;
    int price;
    Product() {}
    Product(string pid, string pname, string desc, int p)
        : product_id(pid), product_name(pname), description(desc), price(p) {}
    void save() {
        ofstream file("products.txt", ios::app);
        file << product_id << " " << product_name << " " << description << " " << price << endl;
        file.close();
    }
};

class Order {
public:
    string order_id, user_id, product_id;
    int total_paid;
    Order() {}
    Order(string oid, string uid, string pid, int paid)
        : order_id(oid), user_id(uid), product_id(pid), total_paid(paid) {}
    void save() {
        ofstream file("orders.txt", ios::app);
        file << order_id << " " << user_id << " " << product_id << " " << total_paid << endl;
        file.close();
    }
};

int main() {
    vector<User> users = {
        User("u1", "Linus", "Torvalds", "Address1", "linus@email.com"),
        User("u2", "Ada", "Lovelace", "Address2", "ada@email.com")
    };
    vector<Product> products = {
        Product("p1", "Laptop", "HighPerfLaptop", 1200),
        Product("p2", "Mouse", "WirelessMouse", 30),
        Product("p3", "Keyboard", "MechanicalKeyboard", 80)
    };
    vector<Order> orders = {
        Order("o1", "u1", "p1", 1200),
        Order("o2", "u1", "p2", 30),
        Order("o3", "u2", "p3", 80)
    };

    ofstream f1("users.txt"), f2("products.txt"), f3("orders.txt");
    f1.close(); f2.close(); f3.close();
    for (auto &u : users) u.save();
    for (auto &p : products) p.save();
    for (auto &o : orders) o.save();

    string target_user = "Linus";
    string target_user_id = "";

    ifstream file("users.txt");
    while (!file.eof()) {
        string uid, fname, lname, addr, mail;
        file >> uid >> fname >> lname >> addr >> mail;
        if (fname == target_user) {
            target_user_id = uid;
            break;
        }
    }
    file.close();

    vector<string> product_ids;
    ifstream file2("orders.txt");
    while (!file2.eof()) {
        string oid, uid, pid;
        int paid;
        file2 >> oid >> uid >> pid >> paid;
        if (uid == target_user_id) {
            product_ids.push_back(pid);
        }
    }
    file2.close();

    ifstream file3("products.txt");
    while (!file3.eof()) {
        string pid, pname, desc;
        int price;
        file3 >> pid >> pname >> desc >> price;
        for (auto &id : product_ids) {
            if (pid == id) {
                cout << pname << endl;
            }
        }
    }
    file3.close();

    return 0;
}
