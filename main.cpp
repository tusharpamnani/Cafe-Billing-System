#include <iostream>
#include <iomanip>
#include <vector>

struct MenuItem {
    std::string name;
    double price;
};

class Cafe {
public:
    Cafe() {
        menuItems = {
            {"Chocolate Shake", 119.0},
            {"Oreo Shake", 119.0},
            {"Choco Seduction", 139.0},
            {"Rose Shake", 119.0},
            {"Mango Shake", 119.0},
            {"Strawberry Shake", 119.0},
            {"Iced Tea", 89.0},
            {"Peach Iced Tea", 89.0},
            {"Virgin Long Island Iced Tea", 109.0},
            {"Blue Lagoon", 89.0},
            {"Mojito", 99.0},
            {"Kiss on the Beach", 109.0}
        };
    }

    void displayMenu() const {
        std::cout << "##### Welcome to Asterisc Cafe! #####" << std::endl;
        std::cout << "Menu:" << std::endl;
        int i = 1;
        for (const auto& item : menuItems) {
            std::cout << i << " " << item.name << " " << item.price << "/-" << std::endl;
            i++;
        }
        std::cout << "0 Exit" << std::endl;
    }

    void takeOrder() {
        int choice, quantity;
        do {
            displayMenu();
            std::cout << "Enter your Choice : ";
            std::cin >> choice;

            if (choice == 0) {
                break;
            } else if (choice < 1 || choice > menuItems.size()) {
                std::cout << "Invalid choice. Please try again." << std::endl;
                continue;
            }

            std::cout << "Enter the Quantity : ";
            std::cin >> quantity;

            if (quantity <= 0) {
                std::cout << "Invalid quantity. Please try again." << std::endl;
                continue;
            }

            order.push_back({menuItems[choice - 1].name, quantity, menuItems[choice - 1].price});

        } while (choice != 0);
    }

    void generateBill() const {
        if (order.empty()) {
            std::cout << "No order to generate a bill." << std::endl;
            return;
        }

        std::cout << "::::: Your Bill :::::" << std::endl;
        std::cout << std::left << std::setw(6) << "Sr.No." << std::setw(15) << "Item"
                  << std::setw(6) << "Qty" << std::setw(6) << "Rate" << std::setw(10) << "Sub Total" << std::endl;
        std::cout << "##############################################" << std::endl;
        int i = 1;
        double total = 0;
        for (const auto& item : order) {
            double subTotal = item.quantity * item.rate;
            std::cout << std::left << std::setw(6) << i << std::setw(15) << item.name
                      << std::setw(6) << item.quantity << std::setw(6) << item.rate
                      << std::setw(10) << subTotal << "/-" << std::endl;
            total += subTotal;
            i++;
        }
        std::cout << "##############################################" << std::endl;
        std::cout << std::right << std::setw(39) << "Grand Total: " << total << "/-" << std::endl;

        handlePayment(total);
    }

    void handlePayment(double total) const {
        double cash;
        do {
            std::cout << "Enter Your Cash: ";
            std::cin >> cash;

            if (cash < total) {
                std::cout << "Please pay " << std::fixed << std::setprecision(2) << total - cash << " Rs. more" << std::endl;
                total -= cash; 
            } else {
                std::cout << "Return Amount: " << std::fixed << std::setprecision(2) << cash - total << "/-" << std::endl;
                break;
            }
        } while (true);

        std::cout << "##### Thank You! #######" << std::endl;
        std::cout << "**************************************************************" << std::endl;
        std::cout << "Please Visit Us Again" << std::endl;
        std::cout << "*********************" << std::endl;
    }

    void run() {
        takeOrder();
        generateBill();
    }

private:
    std::vector<MenuItem> menuItems;

    struct OrderItem {
        std::string name;
        int quantity;
        double rate;
    };

    std::vector<OrderItem> order;
};

int main() {
    Cafe cafe;
    cafe.run();
    return 0;
}
