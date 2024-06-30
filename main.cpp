//
//  main.cpp
//  parent order screen
//
//  Created by Harshdeep Singh on 25/06/2024.
//
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include<fstream>

using namespace std;
struct recentparent{
    string name;
    string contact;
};
struct recentstaff{
    string name;
    string contact;
};

struct Details {
    string name;
    char gender;
    string DOB;
    string contact;
    string visacardnumber;
    string visacardexpiry;
    string password;
    string username;
};
 void orderScreen();
const string ADMIN_USERNAME = "admin@thelunchspot";
const string ADMIN_PASSWORD = "admin123";

vector<Details> parentinfo; // Vector to store Details of multiple parents
vector<Details> staffinfo;
vector<string> complaintlist;
vector<string> reviewlist;
struct Recentparent{
    vector<recentparent> recentparent;
    string name;
};
void password_check(Details& temp) {
    string password;
    cout << "Enter your password (no spaces allowed): ";
    getline(cin, temp.password);
    cout << "Confirm your password: ";
    getline(cin, password);
    if (password == temp.password) {
        cout << "You have successfully registered!" << endl;
    } else {
        cout << "Your passwords do not match! Please try again." << endl;
        password_check(temp); // Recursive call to try again
    }
}

void parent_registration() {
    Details temp;

    cout << "Enter full name: ";
    getline(cin, temp.name);

    cout << "Enter gender (M for male / F for female): ";
    cin >> temp.gender;
    cin.ignore(); // Clear the newline character from the input buffer

    cout << "Enter date of birth (DOB): ";
    getline(cin, temp.DOB);

    cout << "Enter contact number: ";
    getline(cin, temp.contact);

    cout << "Enter Visa card number: ";
    getline(cin, temp.visacardnumber);

    cout << "Enter Visa card expiry date: ";
    getline(cin, temp.visacardexpiry);

    cout << "Enter your username: ";
    getline(cin, temp.username);

    password_check(temp);

    parentinfo.push_back(temp);

    cout << "\nPlease check registered details" << endl;
    for (int i = 0; i < parentinfo.size(); i++) {
        if (temp.username == parentinfo[i].username) {
            cout << "Full name: " << parentinfo[i].name << endl;
            cout << "Gender: " << parentinfo[i].gender << endl;
            cout << "Date of Birth: " << parentinfo[i].DOB << endl;
            cout << "Contact number: " << parentinfo[i].contact << endl;
            cout << "Visa card number: " << parentinfo[i].visacardnumber << endl;
            cout << "Visa card expiry date: " << parentinfo[i].visacardexpiry << endl;
            cout << "Username: " << parentinfo[i].username << endl;
            cout << "--------------------------------------" << endl;
        }
    }
}

void parentlogin_here() {
    string username, password;
    cout << "Enter your username: ";
    cin >> username;
    
    cin.ignore(); // Clear the newline character from the input buffer
    
    bool user_found = false;
    for (auto& parent : parentinfo) {
        if (username == parent.username) {
            user_found = true;
            cout << "Enter your password: ";
            getline(cin, password);
            if (password == parent.password) {
                int task;
                cout << "Hello! " << parent.name << ", you logged in successfully!" << endl;
                    Recentparent rparent;
                    rparent.name.push_back(parent.name);
                
//                printHeading();
                cout << "**Welcome to Parent screen**" << endl;
                cout << "1.Order food\n2.Weekly Menu\n3.Today's Menu\n4.Complaint Screen\n";
                cout << "Enter the task you want to do\n";
                cin >> task;
                switch (task){
                    case 1: orderScreen();
//                    case 4:parentcomplaint();
                }
            }
            else {
                cout << "Incorrect password! Please try again." << endl;
                // Ideally, you should implement a limited number of retries to avoid infinite loop
            }
            break;
            
        }
    }
    if (!user_found) {
        cout << "You have entered the wrong username! Please try again!" << endl;
        // Implement a limited number of retries to avoid infinite loop
    }
}
void login_registerparent() {
        int option1;
        cout << "1. Login" << endl << "2. Registration" << endl;
        cout << "Enter 1 for Login and 2 for Registration: ";
        cin >> option1;
        cin.ignore(); // Clear the newline character from the input buffer
        if (option1 == 1) {
            parentlogin_here();
        } else if (option1 == 2) {
            parent_registration();
        } else {
            cout << "Please enter a valid option!" << endl;
            login_registerparent();
        }
    }

using namespace std;
struct MenuItem {
    string name;
    double price;
};

struct OrderItem {
    string name;
    double price;
    int quantity;
    string date= __DATE__;
};

struct Bill {
    vector<OrderItem> items;
    double total;
    string date;
    
};

const int NUM_DAYS = 5;
const int NUM_DRINKS = 4;
const int NUM_CATEGORIES = 8;

vector<vector<MenuItem>> menu = {
    {{"Classic Cheeseburger", 8.00}, {"Margherita Pizza", 10.00}, {"Grilled Chicken Sandwich", 9.00}, {"Sweet Potato Fries", 4.00}, {"Scrambled Eggs with smoked salmon", 7.00}, {"Pad Thai with shrimp", 12.00}, {"Greek Wrap", 8.00}, {"Tomato Basil Soup", 5.00}},
    {{"BBQ Bacon Burger", 9.50}, {"Pepperoni Pizza", 11.00}, {"Turkey Club Sandwich", 8.50}, {"Curly Fries", 4.00}, {"Eggs Benedict", 9.00}, {"Spaghetti Carbonara", 11.00}, {"Buffalo Chicken Wrap", 8.50}, {"Chicken Noodle Soup", 6.00}},
    {{"Mushroom Swiss Burger", 9.00}, {"Veggie Pizza", 10.00}, {"BLT Sandwich", 7.50}, {"Parmesan Truffle Fries", 5.00}, {"Omelette with spinach, mushrooms, and goat cheese", 7.00}, {"Ramen with pork", 12.00}, {"Falafel Wrap", 7.50}, {"Butternut Squash Soup", 6.00}},
    {{"Spicy Black Bean Burger", 8.50}, {"Hawaiian Pizza", 11.00}, {"Roast Beef Sandwich", 9.00}, {"Waffle Fries", 4.50}, {"Shakshuka", 8.00}, {"Lo Mein with chicken", 11.00}, {"BBQ Pulled Pork Wrap", 8.50}, {"French Onion Soup", 6.50}},
    {{"Blue Cheese Burger", 9.50}, {"Meat Lovers Pizza", 12.00}, {"Caprese Sandwich", 8.00}, {"Chili Cheese Fries", 5.00}, {"Frittata", 7.50}, {"Pesto Pasta", 10.00}, {"Grilled Veggie Wrap", 7.50}, {"Minestrone Soup", 6.00}}
};

vector<string> weekdays = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };
vector<string> categories = { "Burger", "Pizza", "Sandwich", "Fries", "Eggs", "Noodles", "Wraps", "Soup" };
vector<string> drinks = { "Fruit Juice", "Energy Drink", "Soft Drink", "Hydration Drink" };
vector<double> drinkPrices = { 2.50, 3.00, 2.00, 3.50 };

// Global variable to save orders
vector<Bill> pendingpaymentOrders;
vector<Bill> savedOrders;

// Function to get the current day of the week (1 for Monday, ..., 7 for Sunday)
int getCurrentDayOfWeek() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    return (ltm->tm_wday == 0) ? 7 : ltm->tm_wday;
}
string getcurrentDate(){
    string date= __DATE__;
    return string(date);
}
void displayMenu() {
    for (int day = 0; day < NUM_DAYS; day++) {
        cout << weekdays[day] << ":" << endl;
        cout << "+------------------------------+" << endl;
        for (int category = 0; category < NUM_CATEGORIES; category++) {
            cout << "| " << left << setw(20) << categories[category] << ": " << menu[day][category].name << " ($" << fixed << setprecision(2) << menu[day][category].price << ")" << endl;
        }
        cout << "+------------------------------+" << endl;
    }
}

void changeMenu() {
    int day, column;
    cout << "Enter the day index (1-5) of which you want to change the menu: ";
    cin >> day;

    if (day < 1 || day > NUM_DAYS) {
        cout << "Invalid day index. Please try again." << endl;
        return;
    }
    
    cout << "Enter the column index (1-8) of the item you want to change: ";
    cin >> column;

    if (column < 1 || column > NUM_CATEGORIES) {
        cout << "Invalid column index. Please try again." << endl;
        return;
    }

    cout << "Enter the new name of the dish: ";
    cin.ignore(); // To clear the input buffer
    getline(cin, menu[day - 1][column - 1].name);

    cout << "Enter the new price of the dish: ";
    cin >> menu[day - 1][column - 1].price;

    cout << "Menu item changed successfully." << endl;
}

void applyDiscount(Bill &bill) {
    double discount = 0.0;
    if (bill.total > 50) {
        discount = 0.1 * bill.total;
    } else if (bill.total > 30) {
        discount = 0.05 * bill.total;
    }
    cout << "Applying discount: $" << fixed << setprecision(2) << discount << endl; // Debug output
    bill.total -= discount;
}

void showOrderConfirmation(const Bill &bill) {
    cout << "+==============================+" << endl;
    cout << "|      Order Confirmation      |" << endl;
    cout << "+==============================+" << endl;
    for (const auto &item : bill.items) {
        cout << "| " << item.name << " x" << item.quantity << ": $" << fixed << setprecision(2) << item.price * item.quantity << endl;
    }
    cout << "+------------------------------+" << endl;
    cout << "| Total: $" << fixed << setprecision(2) << bill.total << endl;
    cout << "+==============================+" << endl;
}

void paymentOrder(const Bill &bill) {
    pendingpaymentOrders.push_back(bill);
}
void orders(const Bill &bill){
    savedOrders.push_back(bill);
}

void paymentOption(Bill &bill) {
    int paymentChoice;
    cout << "Select Payment Option:" << endl;
    cout << "1. Pay Now\n2. Save for Later\n";
    cin >> paymentChoice;

    if (paymentChoice == 1) {
        applyDiscount(bill);
        showOrderConfirmation(bill);
        orders(bill);
    } else if (paymentChoice == 2) {
        paymentOrder(bill);
        orders(bill);
        cout << "Order saved for later." << endl;
    } else {
        cout << "Invalid option. Please try again." << endl;
        paymentOption(bill);
    }
}

void orderScreen() {
    int choice, quantity;
    Bill bill;
    bill.total = 0.0;
    bill.date= __DATE__;

    cout << "**Welcome to Order Screen**" << endl;
    cout << "Today's Menu:" << endl;
    displayMenu();

    do {
        cout << "Select Item you want to Order (1-8 for food, 9-12 for drinks, 0 to finish):" << endl;
        cout << "1. Burger\n2. Pizza\n3. Sandwich\n4. Fries\n5. Eggs\n6. Noodles\n7. Wrap\n8. Soup\n";
        cout << "9. Fruit Juice\n10. Energy Drink\n11. Soft Drink\n12. Hydration Drink\n";
        cin >> choice;

        if (choice == 0) break;

        if (choice < 1 || choice > 12) {
            cout << "Invalid choice. Please try again." << endl;
            continue;
        }

        cout << "Enter Quantity:" << endl;
        cin >> quantity;

        if (quantity <= 0) {
            cout << "Invalid quantity. Please enter a positive number." << endl;
            continue;
        }

        int currentDay = getCurrentDayOfWeek();
        if (currentDay < 1 || currentDay > 5) {
            cout << "Today is not a weekday. Cannot place an order." << endl;
            return;
        }

        if (choice >= 1 && choice <= 8) {
            MenuItem orderedItem = menu[currentDay - 1][choice - 1];
            bill.items.push_back({orderedItem.name, orderedItem.price, quantity});
            bill.total += orderedItem.price * quantity;
        } else if (choice >= 9 && choice <= 12) {
            int drinkIndex = choice - 9;
            bill.items.push_back({drinks[drinkIndex], drinkPrices[drinkIndex], quantity});
            bill.total += drinkPrices[drinkIndex] * quantity;
        }

    } while (choice != 0);

    if (bill.items.empty()) {
        cout << "No items ordered. Exiting order screen." << endl;
        return;
    }

    paymentOption(bill);
}

int main(){
    
}
