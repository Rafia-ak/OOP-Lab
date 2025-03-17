#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee {
public:
    string id;
    string name;

    Employee(string employeeId, string employeeName) : id(employeeId), name(employeeName) {}

    virtual void displayInfo() const {
        cout << "Employee ID: " << id << ", Name: " << name << endl;
    }

    virtual ~Employee() {}
};

class IOrderTaker {
public:
    virtual void takeOrder() = 0;
    virtual ~IOrderTaker() {}
};

class IOrderPreparer {
public:
    virtual void prepareOrder() = 0;
    virtual ~IOrderPreparer() {}
};

class IBiller {
public:
    virtual void generateBill() = 0;
    virtual ~IBiller() {}
};

class Waiter : public Employee, public IOrderTaker {
public:
    Waiter(string id, string name) : Employee(id, name) {}

    void takeOrder() override {
        cout << name << " is taking the order." << endl;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        cout << "Role: Waiter (Order Taker)" << endl;
    }
};

class Chef : public Employee, public IOrderPreparer {
public:
    Chef(string id, string name) : Employee(id, name) {}

    void prepareOrder() override {
        cout << name << " is preparing the order." << endl;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        cout << "Role: Chef (Order Preparer)" << endl;
    }
};

class Cashier : public Employee, public IBiller {
public:
    Cashier(string id, string name) : Employee(id, name) {}

    void generateBill() override {
        cout << name << " is generating the bill." << endl;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        cout << "Role: Cashier (Biller)" << endl;
    }
};

class Manager : public Employee, public IOrderTaker, public IBiller {
public:
    Manager(string id, string name) : Employee(id, name) {}

    void takeOrder() override {
        cout << name << " is taking the order." << endl;
    }

    void generateBill() override {
        cout << name << " is generating the bill." << endl;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        cout << "Role: Manager (Order Taker, Biller)" << endl;
    }
};

class Menu {
public:
    virtual double calculateTotalCost() const = 0;
    virtual ~Menu() {}
};

class FoodMenu : public Menu {
private:
    double foodCost;

public:
    FoodMenu(double cost) : foodCost(cost) {}

    double calculateTotalCost() const override {
        return foodCost;
    }
};

class BeverageMenu : public Menu {
private:
    double beverageCost;
    const double beverageTax = 0.15;

public:
    BeverageMenu(double cost) : beverageCost(cost) {}

    double calculateTotalCost() const override {
        return beverageCost + (beverageCost * beverageTax);
    }
};

void showEmployeeRoles(vector<Employee*> employees) {
    for (auto& emp : employees) {
        emp->displayInfo();
    }
}

void demonstrateOrderTaking(vector<IOrderTaker*> orderTakers) {
    for (auto& orderTaker : orderTakers) {
        orderTaker->takeOrder();
    }
}

void demonstrateBilling(vector<IBiller*> billers) {
    for (auto& biller : billers) {
        biller->generateBill();
    }
}

int main() {
    Waiter waiter("W001", "John");
    Chef chef("C001", "Alice");
    Cashier cashier("K001", "Bob");
    Manager manager("M001", "Eve");

    vector<Employee*> employees = { &waiter, &chef, &cashier, &manager };
    showEmployeeRoles(employees);

    vector<IOrderTaker*> orderTakers = { &waiter, &manager };
    demonstrateOrderTaking(orderTakers);

    vector<IBiller*> billers = { &cashier, &manager };
    demonstrateBilling(billers);

    FoodMenu foodMenu(100);
    BeverageMenu beverageMenu(50);

    cout << "Total cost of food menu: $" << foodMenu.calculateTotalCost() << endl;
    cout << "Total cost of beverage menu: $" << beverageMenu.calculateTotalCost() << endl;

    return 0;
}

