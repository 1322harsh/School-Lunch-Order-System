
#include "introduction.h"

int main() {
    while (true) {
        printHeading();
        list_options();

        int selected_option = get_option(); // Get the user's task choice
        switch (selected_option) {
            case 1:
                printHeading();
                weekly_menu();
                break;
            case 2:
                printHeading();
                display_discounts();
                break;
            case 3:
                printHeading();
                login_registerparent();
                break;
            case 4:
                printHeading();
                login_registerstaff();
                break;
            case 5:
                printHeading();
                admin_login();
                break;
            default:
                cout << "Invalid option!" << endl;
                break;
        }

        cout << "Press Enter to return to the main menu...";
        cin.ignore();
        cin.get();
    }

    return 0;
}
