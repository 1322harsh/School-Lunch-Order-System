#include "introduction.h"

vector<Details> parentinfo;
vector<Details> staffinfo;

void printHeading() {
    cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "| _________   _      _   _____    _      _     _   __       _   _____   _      _    ________   __________   __________   _________  |" << endl;
    cout << "||___   ___| | |    | | | ____|  | |    | |   | | |   `    | | |  ___| | |    | |  |  ______| |  ______  | |  ______  | |___   ___| |" << endl;
    cout << "|    | |     | |____| | | |___   | |    | |   | | | |` `   | | | |     | |____| |  |  |       | |______| | | |      | |     | |     |" << endl;
    cout << "|    | |     | |____| | |  ___|  | |    | |   | | | | ` `  | | | |     | |____| |  |  |_____  | _________| | |      | |     | |     |" << endl;
    cout << "|    | |     | |    | | | |      | |    | |   | | | |  ` ` | | | |     | |    | |  |______  | | |          | |      | |     | |     |" << endl;
    cout << "|    | |     | |    | | | |___   | |___ | |___| | | |   ` `| | | |___  | |    | |   ______| | | |          | |______| |     | |     |" << endl;
    cout << "|    |_|     |_|    |_| |_____|  |_____||_______| |_|    `___| |_____| |_|    |_|  |________| |_|          |__________|     |_|     |" << endl;
    cout << "|                                                                                                                                   |" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

void list_options() {
    cout << "1. Weekly Menu" << endl
         << "2. Discounts" << endl
         << "3. Login and Registration for Parents" << endl
         << "4. Login and Registration for Staff" << endl
         << "5. Admin Login" << endl;
}

void contact_details() {
    cout << "_____________________________________________________________________________________________________________________________________" << endl;
    cout << "\t\t\t\t\t The Lunch Spot\t **All Rights Reserved**" << endl;
    cout << "_____________________________________________________________________________________________________________________________________" << endl;
    cout << "Welcome to our School Lunch Service!\nWe believe in Quality and Customer Satisfaction.\n";
    cout << "\n\nContact Details- 0234123443 , 0787890907\n";
    cout << "223 VDR ROAD , AUXXL\n";
    cout << "_____________________________________________________________________________________________________________________________________" << endl;
}

int get_option() {
    int option;
    bool valid = false;

    while (!valid) {
        cout << "Enter the task number you want to do: ";
        cin >> option;

        if (option >= 1 && option <= 5) {
            valid = true;
        } else {
            cout << "Please enter a valid task number!!" << endl;
        }
    }
    return option;
}

int getCurrentDayOfWeek() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    return ltm->tm_wday;  // tm_wday is 0 for Sunday, 1 for Monday, ..., 6 for Saturday
}

void weekly_menu() {
    int currentDay = getCurrentDayOfWeek();

      const int NUM_DAYS = 5;
      const int NUM_CATEGORIES = 8;
      const int NUM_DRINKS = 4;

      const string categories[NUM_CATEGORIES] = { "Burger", "Pizza", "Sandwich", "Fries", "Eggs", "Noodles", "Wraps", "Soup" };
      const string drinks[NUM_DRINKS] = { "Fruit Juice", "Energy Drink", "Soft Drink", "Hydration Drink" };
      const double drinkPrices[NUM_DRINKS] = { 2.50, 3.00, 2.00, 3.50 };
      const string weekdays[NUM_DAYS] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };

      MenuItem menu[NUM_DAYS][NUM_CATEGORIES] = {
          {{"Classic Cheeseburger", 8.00}, {"Margherita Pizza", 10.00}, {"Grilled Chicken Sandwich", 9.00}, {"Sweet Potato Fries", 4.00}, {"Scrambled Eggs with smoked salmon", 7.00}, {"Pad Thai with shrimp", 12.00}, {"Greek Wrap", 8.00}, {"Tomato Basil Soup", 5.00}},
          {{"BBQ Bacon Burger", 9.50}, {"Pepperoni Pizza", 11.00}, {"Turkey Club Sandwich", 8.50}, {"Curly Fries", 4.00}, {"Eggs Benedict", 9.00}, {"Spaghetti Carbonara", 11.00}, {"Buffalo Chicken Wrap", 8.50}, {"Chicken Noodle Soup", 6.00}},
          {{"Mushroom Swiss Burger", 9.00}, {"Veggie Pizza", 10.00}, {"BLT Sandwich", 7.50}, {"Parmesan Truffle Fries", 5.00}, {"Omelette with spinach, mushrooms, and goat cheese", 7.00}, {"Ramen with pork", 12.00}, {"Falafel Wrap", 7.50}, {"Butternut Squash Soup", 6.00}},
          {{"Spicy Black Bean Burger", 8.50}, {"Hawaiian Pizza", 11.00}, {"Roast Beef Sandwich", 9.00}, {"Waffle Fries", 4.50}, {"Shakshuka", 8.00}, {"Lo Mein with chicken", 11.00}, {"BBQ Pulled Pork Wrap", 8.50}, {"French Onion Soup", 6.50}},
          {{"Blue Cheese Burger", 9.50}, {"Meat Lovers Pizza", 12.00}, {"Caprese Sandwich", 8.00}, {"Chili Cheese Fries", 5.00}, {"Frittata", 7.50}, {"Pesto Pasta", 10.00}, {"Grilled Veggie Wrap", 7.50}, {"Minestrone Soup", 6.00}}
      };

      cout << "+==============================+" << endl;
      cout << "|          Weekly Menu         |" << endl;
      cout << "+==============================+" << endl;

      if (currentDay >= 1 && currentDay <= 5) { // Monday to Friday
          string currentWeekday = weekdays[currentDay - 1];
          cout << currentWeekday << ":" << endl;
          cout << "+------------------------------+" << endl;
          for (int category = 0; category < NUM_CATEGORIES; category++) {
              cout << "| " << categories[category] << ": " << menu[currentDay - 1][category].name << " ($" << menu[currentDay - 1][category].price << ")" << endl;
          }
      } else {
          cout << "Today is not a weekday. Please check the menu on a weekday." << endl;
      }

      cout << "+------------------------------+" << endl;
      cout << "| Drinks:                      |" << endl;
      cout << "+------------------------------+" << endl;
      for (int drink = 0; drink < NUM_DRINKS; drink++) {
          cout << "| " << drinks[drink] << ": $" << drinkPrices[drink] << endl;
      }
      cout << "+------------------------------+" << endl;
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
        }}

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

void staff_registration() {
    Details temp1;

        cout << "Enter full name: ";
        getline(cin, temp1.name);

        cout << "Enter gender (M for male / F for female): ";
        cin >> temp1.gender;
        cin.ignore(); // Clear the newline character from the input buffer

        cout << "Enter date of birth (DOB): ";
        getline(cin, temp1.DOB);

        cout << "Enter contact number: ";
        getline(cin, temp1.contact);

        cout << "Enter Visa card number: ";
        getline(cin, temp1.visacardnumber);

        cout << "Enter Visa card expiry date: ";
        getline(cin, temp1.visacardexpiry);

        cout << "Enter your username: ";
        getline(cin, temp1.username);

        password_check(temp1);

        staffinfo.push_back(temp1);

        for (int i = 0; i < staffinfo.size(); i++) {
            if (temp1.username == staffinfo[i].username) {
                cout << "Full name: " << staffinfo[i].name << endl;
                cout << "Gender: " << staffinfo[i].gender << endl;
                cout << "Date of Birth: " << staffinfo[i].DOB << endl;
                cout << "Contact number: " << staffinfo[i].contact << endl;
                cout << "Visa card number: " << staffinfo[i].visacardnumber << endl;
                cout << "Visa card expiry date: " << staffinfo[i].visacardexpiry << endl;
                cout << "Username: " << staffinfo[i].username << endl;
                cout << "--------------------------------------" << endl;
            }
        }}

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

void login_registerstaff() {
    int option1;
        cout << "1. Login" << endl << "2. Registration" << endl;
        cout << "Enter 1 for Login and 2 for Registration: ";
        cin >> option1;
        cin.ignore(); // Clear the newline character from the input buffer
        if (option1 == 1) {
            stafflogin_here();
        } else if (option1 == 2) {
            staff_registration();
        } else {
            cout << "Please enter a valid option!" << endl;
            login_registerstaff();
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
                    cout << "Hello! " << parent.name << ", you logged in successfully!" << endl;
                } else {
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

void stafflogin_here() {
    string username, password;
        cout << "Enter your username: ";
        cin >> username;
        cin.ignore(); // Clear the newline character from the input buffer

        bool user_found = false;
        for (auto& staff : staffinfo) {
            if (username == staff.username) {
                user_found = true;
                cout << "Enter your password: ";
                getline(cin, password);

                if (password == staff.password) {
                    cout << "Hello! " << staff.name << ", you logged in successfully!" << endl;
                } else {
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

void admin_login() {
    string username, password;
        cout << "Enter admin username: ";
        cin >> username;
        cin.ignore(); // Clear the newline character from the input buffer
        cout << "Enter admin password: ";
        getline(cin, password);

        if (username == ADMIN_USERNAME && password == ADMIN_PASSWORD) {
            cout << "Admin login successful!" << endl;
            // Placeholder for admin functionalities
            cout << "Welcome, Admin! [Admin functionalities will be implemented here]" << endl;
        } else {
            cout << "Invalid admin credentials. Please try again." << endl;
        }

}

void display_discounts() {
    cout << "+==============================+" << endl;
    cout << "|        Discounts             |" << endl;
    cout << "+==============================+" << endl;
    cout << "10% off for 5 or more orders!" << endl;
    cout << "Contact us for more bulk order discounts." << endl;
    cout << "+==============================+" << endl;
}

