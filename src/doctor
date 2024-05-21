#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Doctor {
private:
    string name;
    int age;
    string phoneNumber;
    bool hasAppointment;
    bool hasWorked;

public:
    Doctor(string name, int age, string phoneNumber)
        : name(name), age(age), phoneNumber(phoneNumber), hasAppointment(false), hasWorked(false) {}

    string getName() const {
        return name;
    }

    void AddAppointment() {
        hasAppointment = true;
        cout << "Added appointment schedule for doctor " << name << endl;
    }

    void RemoveAppointment() {
        hasAppointment = false;
        cout << "Deleted doctor's appointment " << name << endl;
    }

    void SetWorkedStatus(bool status) {
        hasWorked = status;
        cout << "Updated the doctor's working status " << name << endl;
    }

    void DisplayInfo() {
        cout << "Doctor's information:" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "The phone number: " << phoneNumber << endl;
        cout << "Appointment schedule: " << (hasAppointment ? "Yes" : "No") << endl;
        cout << "Used to work at a hospital: " << (hasWorked ? "Yes" : "No") << endl;
    }
};

int main() {
    string name, phoneNumber;
    int age;
    vector<Doctor> doctors;

    while (true) {
        cout << "===== Hospital Management System =====" << endl;
        cout << "1. Add doctor" << endl;
        cout << "2. Delete doctor" << endl;
        cout << "3. Display doctor information" << endl;
        cout << "4. Add an appointment to your doctor" << endl;
        cout << "5. Delete doctor's appointment" << endl;
        cout << "6. Update the doctor's working status" << endl;
        cout << "0. Exit the program" << endl;
        cout << "Please select an option: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 0:
                cout << "Program exited." << endl;
                return 0;

            case 1:
                cout << "Enter the doctor's name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter age: ";
                cin >> age;
                cout << "Enter the phone number: ";
                cin.ignore();
                getline(cin, phoneNumber);

                doctors.push_back(Doctor(name, age, phoneNumber));
                cout << "Doctor added successfully!" << endl;
                break;

            case 2:
                if (doctors.empty()) {
                    cout << "There is no doctor to remove." << endl;
                } else {
                    cout << "List of doctors:" << endl;
                    for (int i = 0; i < doctors.size(); ++i) {
                        cout << i + 1 << ". " << doctors[i].getName() << endl;
                    }
                    cout << "Please select the doctor's order number to delete: ";
                    int index;
                    cin >> index;

                    if (index >= 1 && index <= doctors.size()) {
                        doctors.erase(doctors.begin() + index - 1);
                        cout << "Doctor successfully deleted!" << endl;
                    } else {
                        cout << "Invalid order number." << endl;
                    }
                }
                break;

            case 3:
                if (doctors.empty()) {
                    cout << "There are no doctors to show." << endl;
                } else {
                    cout << "List of doctors" << endl;
                    for (int i = 0; i < doctors.size(); ++i) {
                        cout << i + 1 << ". " << doctors[i].getName() << endl;
                    }
                    cout << "Please select a doctor's order number to display information: ";
                    int index;
                    cin >> index;

                    if (index >= 1 && index <= doctors.size()) {
                        doctors[index - 1].DisplayInfo();
                    } else {
                        cout << "Invalid order number." << endl;
                    }
                }
                break;

            case 4:
                if (doctors.empty()) {
                    cout << "There is no doctor to add an appointment." << endl;
                } else {
                    cout << "List of doctor:" << endl;
                    for (int i = 0; i < doctors.size(); ++i) {
                        cout << i + 1 << ". " << doctors[i].getName() << endl;
                    }
                    cout << "Please select your doctor's order number to add an appointment: ";
                    int index;
                    cin >> index;

                    if (index >= 1 && index <= doctors.size()) {
                        doctors[index - 1].AddAppointment();
                    } else {
                        cout << "Invalid order number." << endl;
                    }
                }
                break;

            case 5:
                if (doctors.empty()) {
                    cout << "There is no doctor to clear appointments." << endl;
                } else {
                    cout << "List of doctor:" << endl;
                    for (int i = 0; i < doctors.size(); ++i) {
                        cout << i + 1 << ". " << doctors[i].getName() << endl;
                    }
                    cout << "Please select the doctor's order number to delete the appointment: ";
                    int index;
                    cin >> index;

                    if (index >= 1 && index <= doctors.size()) {
                        doctors[index - 1].RemoveAppointment();
                    } else {
                        cout << "Invalid order number." << endl;
                    }
                }
                break;

            case 6:
                if (doctors.empty()) {
                    cout << "There is no doctor to update work status." << endl;
                } else {
                    cout << "List of doctor:" << endl;
                    for (int i = 0; i < doctors.size(); ++i) {
                        cout << i + 1 << ". " << doctors[i].getName() << endl;
                    }
                    cout << "Please select your doctor's order number to update your working status: ";
                    int index;
                    cin >> index;

                    if (index >= 1 && index <= doctors.size()) {
                        cout << "Enter working status (1: Yes, 0: No): ";
                        int status;
                        cin >> status;
                        doctors[index - 1].SetWorkedStatus(status == 1);
                    } else {
                        cout << "Invalid order number." << endl;
                    }
                }
                break;

            default:
                cout << "Invalid selection. Please select again." << endl;
                break;
        }
    }

    return 0;
}
