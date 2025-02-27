#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct MenuItem{
    string name;
    double price;
    string type;
};

class CoffeeShop{
public:
    const string Name;
    vector<MenuItem> Menu;
    vector<string> orders;

    CoffeeShop(string shopName, vector<MenuItem> menuItems) : Name(shopName), Menu(menuItems) {}

    string addOrder(string item) {
        for (const auto& menuItem : Menu) {
            if (menuItem.name == item) {
                orders.push_back(item);
                return "Order added!";
            }
        }
        return "This item is currently unavailable!";
    }

    string fulfillOrder(){
        if (!orders.empty()) {
            string item = orders.front();
            orders.erase(orders.begin());
            return "The " + item + " is ready!";
        }
        return "All orders have been fulfilled";
    }

    vector<string> listOrders(){
        return orders;
    }

    double dueAmount(){
        double total = 0;
        for (const auto& order : orders){
            for (const auto& menuItem : Menu){
                if (menuItem.name == order) {
                    total += menuItem.price;
                }
            }
        }
        return total;
    }

    string cheapestItem(){
        if (Menu.empty()) return "";
        MenuItem cheapest = Menu[0];
        for (const auto& menuItem : Menu){
            if (menuItem.price < cheapest.price){
                cheapest = menuItem;
            }
        }
        return cheapest.name;
    }

    vector<string> drinksOnly(){
        vector<string> drinks;
        for (const auto& menuItem : Menu){
            if (menuItem.type == "drink"){
                drinks.push_back(menuItem.name);
            }
        }
        return drinks;
    }

    vector<string> foodOnly() {
        vector<string> foods;
        for (const auto& menuItem : Menu) {
            if (menuItem.type == "food") {
                foods.push_back(menuItem.name);
            }
        }
        return foods;
    }
};

int main(){
    vector<MenuItem> menu = {
        {"Coffee", 2.5, "drink"},
        {"Tea", 2.0, "drink"},
        {"Sandwich", 5.0, "food"},
        {"Cake", 4.0, "food"}
    };
    
    CoffeeShop shop("Rafia's_Cafe", menu);
    shop.addOrder("Coffee");
    shop.addOrder("Cake");
    cout << shop.fulfillOrder() << "\n";
    cout << "Total due: " << shop.dueAmount() << "\n";
    cout << "Cheapest item: " << shop.cheapestItem() << "\n";
    
    return 0;
}
