#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    string menuItems[] = {"1. Pizza", "2. Pasta", "3. Steak", "4. Fries", "5. Drink"};
    float prices[] = {7.99, 5.99, 4.99, 2.99, 1.99};
    const int menuSize = 5;
    float taxRate = 0.10;

    cout << "=====================================" << endl;
    cout << "Welcome to our cozy restaurant!" << endl;
    cout << "=====================================\n";
    for (int i = 0; i < menuSize; i++) {
        cout << menuItems[i] << " - $" << fixed << setprecision(2) << prices[i] << endl;
    }

    int choice;
    int quantity;
    float total = 0.0;  // ✅ Fixed here
    char continueOrdering;

    do {
        cout << "\nEnter item number (1-5): ";
        cin >> choice;
        if (choice < 1 || choice > menuSize) {
            cout << "Invalid choice! Please enter a number between 1 and 5.\n";
            continue;
        }

        cout << "Enter quantity: ";
        cin >> quantity;
        if (quantity <= 0) {
            cout << "Invalid quantity! Must be greater than 0.\n";
            continue;
        }

        total += prices[choice - 1] * quantity;

        cout << "Would you like to order more? (y/n): ";
        cin >> continueOrdering;

    } while (continueOrdering == 'y' || continueOrdering == 'Y');

    float tax = total * taxRate;
    float finalTotal = total + tax;

    cout << "\n=== BILL ===\n";
    cout << "Subtotal: $" << fixed << setprecision(2) << total << endl;
    cout << "Tax: $" << fixed << setprecision(2) << tax << endl;
    cout << "Total: $" << fixed << setprecision(2) << finalTotal << endl;
    cout << "Thank you for dining with us!" << endl;

    return 0;
}
