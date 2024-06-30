#include <iostream>
#include <fstream>
#include <string>
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
vector<string> complaintlist;
vector<Details> parentinfo;

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

    cout << "Enter your password: ";
    getline(cin, temp.password);

    parentinfo.push_back(temp);

    cout << "\nPlease check registered details" << endl;
    for (const auto& parent : parentinfo) {
        cout << "Full name: " << parent.name << endl;
        cout << "Gender: " << parent.gender << endl;
        cout << "Date of Birth: " << parent.DOB << endl;
        cout << "Contact number: " << parent.contact << endl;
        cout << "Visa card number: " << parent.visacardnumber << endl;
        cout << "Visa card expiry date: " << parent.visacardexpiry << endl;
        cout << "Username: " << parent.username << endl;
        cout << "--------------------------------------" << endl;
    }
}
void parentcomplaint(){
    int task;
    cout << "**This is complaint screen**" << endl;
    cout << "1.Lodge Complaint \n2.Review Complaint" << endl;
    cout << "Enter your choice for your task:";
    cin >> task;
    switch (task){
        case 1:
        lodgecomplaint();
        break;
        case 2:
    }
}
  void  lodgecomplaint(){if (parentinfo.empty()) {
        cout << "No parent registered. Please register first." << endl;
        return;
    }

    cout << "\t\t\t\t**This is your complaint screen**" << endl;
    string filename = parentinfo[0].name + "_complaint.txt"; // Create a unique file name

    ofstream myfile(filename.c_str(), ios::app); // Open file in append mode
    if (myfile.is_open()) {
        cout << "Enter your complaint: ";
        string complaint;
        getline(cin, complaint);

        myfile << "My complaint:" << endl << complaint << endl; // Append complaint and add a newline
        myfile.close();
        cout << "Complaint saved successfully to " << filename << endl;
        complaintlist.push_back(filename); // Store the filename in the complaint list
    } else {
        cout << "Unable to open file" << endl;
    }
}
void adminview() {
    if (complaintlist.empty()) {
        cout << "No complaints to display." << endl;
        return;
    }

    cout << "List of complaints:" << endl;
    for (size_t i = 0; i < complaintlist.size(); ++i) {
        cout << i + 1 << ". " << complaintlist[i] << endl;
    }

    int option2;
    cout << "Enter the number of the complaint you want to review: ";
    cin >> option2;

    if (option2 < 1 || option2 > complaintlist.size()) {
        cout << "Invalid selection." << endl;
        return;
    }

    string filename_to_open = complaintlist[option2 - 1];
    ifstream myfile_to_open(filename_to_open.c_str());
    if (!myfile_to_open.is_open()) {
        cerr << "The file could not be opened." << endl;
        return;
    }

    string line;
    cout << "Contents of complaint " << option2 << ":" << endl;
    while (getline(myfile_to_open, line)) {
        cout << line << endl;
    }
    myfile_to_open.close();
    
}
int main (){
    parentcomplaint();
}