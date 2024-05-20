#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

class Doctor {
public:
    string name;
    int age;
    string phoneNumber;
    bool hasAppointment;
    bool hasWorkedBefore;

    Doctor(string n, int a, string p, bool ha, bool hw)
        : name(n), age(a), phoneNumber(p), hasAppointment(ha), hasWorkedBefore(hw) {}

    void displayInfo() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Has Appointment: " << (hasAppointment ? "Yes" : "No") << endl;
        cout << "Has Worked Before: " << (hasWorkedBefore ? "Yes" : "No") << endl;
    }
};

class HospitalManagementSystem {
private:
    vector<Doctor> doctors;

public:
    void addDoctor() {
        string name;
        int age;
        string phoneNumber;
        bool hasAppointment;
        bool hasWorkedBefore;

        cout << "Enter doctor's name: ";
        cin.ignore(); 
        getline(cin, name);
        cout << "Enter doctor's age: ";
        cin >> age;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "Enter doctor's phone number: ";
        getline(cin, phoneNumber);
        cout << "Has the doctor an appointment? (1 for Yes, 0 for No): ";
        cin >> hasAppointment;
        cout << "Has the doctor worked here before? (1 for Yes, 0 for No): ";
        cin >> hasWorkedBefore;

        Doctor newDoctor(name, age, phoneNumber, hasAppointment, hasWorkedBefore);
        doctors.push_back(newDoctor);

        cout << "Doctor added successfully!" << endl;
    }

    void removeDoctor() {
        string name;
        cout << "Enter the name of the doctor to remove: ";
        cin.ignore(); // Ensure previous input is cleared
        getline(cin, name);

        for (auto it = doctors.begin(); it != doctors.end(); ++it) {
            if (it->name == name) {
                doctors.erase(it);
                cout << "Doctor removed successfully!" << endl;
                return;
            }
        }

        cout << "Doctor not found!" << endl;
    }

    void displayAllDoctors() const {
        if (doctors.empty()) {
            cout << "No doctors in the system." << endl;
            return;
        }

        for (const auto& doctor : doctors) {
            doctor.displayInfo();
            cout << "-------------------------" << endl;
        }
    }

    void checkAppointment() const {
        string name;
        cout << "Enter the doctor's name to check for an appointment: ";
        cin.ignore(); // Ensure previous input is cleared
        getline(cin, name);

        for (const auto& doctor : doctors) {
            if (doctor.name == name) {
                cout << "Doctor " << name << " has an appointment: " << (doctor.hasAppointment ? "Yes" : "No") << endl;
                return;
            }
        }

        cout << "Doctor not found!" << endl;
    }

    void checkWorkedBefore() const {
        string name;
        cout << "Enter the doctor's name to check if they have worked here before: ";
        cin.ignore(); // Ensure previous input is cleared
        getline(cin, name);

        for (const auto& doctor : doctors) {
            if (doctor.name == name) {
                cout << "Doctor " << name << " has worked here before: " << (doctor.hasWorkedBefore ? "Yes" : "No") << endl;
                return;
            }
        }

        cout << "Doctor not found!" << endl;
    }
};

int main() {
    HospitalManagementSystem hms;
    int choice;

    while (true) {
        cout << "1. Add Doctor" << endl;
        cout << "2. Remove Doctor" << endl;
        cout << "3. Display All Doctors" << endl;
        cout << "4. Check Appointment" << endl;
        cout << "5. Check Worked Before" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                hms.addDoctor();
                break;
            case 2:
                hms.removeDoctor();
                break;
            case 3:
                hms.displayAllDoctors();
                break;
            case 4:
                hms.checkAppointment();
                break;
            case 5:
                hms.checkWorkedBefore();
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
