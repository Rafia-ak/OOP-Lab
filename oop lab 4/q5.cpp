#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class MenuItem {
public:
    string name, type;
    double price;

    MenuItem(string n, string t, double p) : name(n), type(t), price(p) {}
};

class CoffeeShop {
private:
    string name;
    vector<MenuItem> menu;
    vector<string> orders;

public:
    CoffeeShop(string shopName, vector<MenuItem> menuItems) : name(shopName), menu(menuItems) {}

    string addOrder(string itemName) {
        for (const auto& item : menu) {
            if (item.name == itemName) {
                orders.push_back(itemName);
                return "Order added: " + itemName;
            }
        }
        return "This item is currently unavailable: " + itemName;
    }

    string fulfillOrder() {
        if (!orders.empty()) {
            string item = orders.front();
            orders.erase(orders.begin());
            return "The " + item + " is ready";
        }
        return "All orders have been fulfilled";
    }

    void listOrders() {
        if (orders.empty()) {
            cout << "No pending orders.\n";
        } else {
            cout << "Pending Orders:\n";
            for (const auto& order : orders) {
                cout << "- " << order << "\n";
            }
        }
    }

    double dueAmount() {
        double total = 0;
        for (const auto& order : orders) {
            for (const auto& item : menu) {
                if (item.name == order) {
                    total += item.price;
                }
            }
        }
        return total;
    }

    string cheapestItem() {
        if (menu.empty()) return "No items available.";
        MenuItem cheapest = menu[0];
        for (const auto& item : menu) {
            if (item.price < cheapest.price) {
                cheapest = item;
            }
        }
        return cheapest.name;
    }

    void drinksOnly() {
        cout << "Available Drinks:\n";
        for (const auto& item : menu) {
            if (item.type == "drink") {
                cout << "- " << item.name << "\n";
            }
        }
    }

    void foodOnly() {
        cout << "Available Foods:\n";
        for (const auto& item : menu) {
            if (item.type == "food") {
                cout << "- " << item.name << "\n";
            }
        }
    }
};

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cout << "Usage: " << argv[0] << " <shop_name> <order1> <order2> ...\n";
        return 1;
    }

    string shopName = argv[1];

    vector<MenuItem> menu = {
        MenuItem("Coffee", "drink", 2.5),
        MenuItem("Tea", "drink", 2.0),
        MenuItem("Sandwich", "food", 5.0),
        MenuItem("Cake", "food", 3.5)
    };

    CoffeeShop shop(shopName, menu);

    cout << "Welcome to " << shopName << "!\n";

    for (int i = 2; i < argc; i++) {
        cout << shop.addOrder(argv[i]) << "\n";
    }

    shop.listOrders();
    cout << "Total Due: $" << shop.dueAmount() << "\n";
    cout << "Cheapest Item: " << shop.cheapestItem() << "\n";

    shop.drinksOnly();
    shop.foodOnly();

    return 0;
}
