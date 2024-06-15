
#ifndef LUNCHSPOT_H
#define LUNCHSPOT_H

#include <iostream>
#include <string>
#include <ctime>
#include <vector>

using namespace std;

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

const string ADMIN_USERNAME = "admin@thelunchspot";
const string ADMIN_PASSWORD = "admin123";

extern vector<Details> parentinfo; // Vector to store Details of multiple parents
extern vector<Details> staffinfo;

void printHeading();
void list_options();
void contact_details();
int get_option();
int getCurrentDayOfWeek();
void weekly_menu();
void parent_registration();
void password_check(Details& temp);
void staff_registration();
void login_registerparent();
void login_registerstaff();
void parentlogin_here();
void stafflogin_here();
void admin_login();
void display_discounts();

#endif // LUNCHSPOT_H

