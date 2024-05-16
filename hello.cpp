#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


struct Doctor {
    string name;
    int age;
    string hometown;
    string phoneNumber;
    string specialty;
};

/
void printDoctor(const Doctor& doctor) {
    cout << "Name: " << doctor.name << endl;
    cout << "Age: " << doctor.age << " years old" << endl;
    cout << "Hometown: " << doctor.hometown << endl;
    cout << "Phone Number: " << doctor.phoneNumber << endl;
    cout << "Specialty: " << doctor.specialty << endl;
    cout << "----------------------------" << endl;
}


void addDoctor(vector<Doctor>& doctors) {
    string name, hometown, phoneNumber, specialty;
    int age;

    cout << "\nEnter Doctor Information:\n";
    cout << "Name: ";
    getline(cin, name);
    cout << "Age: ";
    cin >> age;
    cin.ignore(); /
    cout << "Hometown: ";
    getline(cin, hometown);
    cout << "Phone Number: ";
    getline(cin, phoneNumber);
    cout << "Specialty: ";
    getline(cin, specialty);

    doctors.push_back({name, age, hometown, phoneNumber, specialty});
    cout << "Doctor added successfully!" << endl;
}


void deleteDoctorByName(vector<Doctor>& doctors) {
    string nameQuery;
    cout << "Enter doctor's name to delete: ";
    getline(cin, nameQuery);



    if (it != doctors.end()) {
        doctors.erase(it);
        cout << "Doctor " << nameQuery << " deleted successfully!" << endl;
    } else {
        cout << "Doctor not found with the name: " << nameQuery << endl;
    }
}


void modifyDoctorInfo(vector<Doctor>& doctors) {
    string nameQuery;
    cout << "Enter doctor's name to modify: ";
    getline(cin, nameQuery);

    auto it = find_if(doctors.begin(), doctors.end(), 
                      [](const Doctor& doctor) { return doctor.name == nameQuery; });

    if (it != doctors.end()) {
        int choice;
        cout << "\nChoose field to modify:\n";
        cout << "1. Age\n";
        cout << "2. Hometown\n";
        cout << "3. Phone Number\n";
        cout << "4. Specialty\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: { 
                int newAge;
                cout << "Enter new age: ";
                cin >> newAge;
                it->age = newAge;
                break;
            }
            case 2: { 
                string newHometown;
                cout << "Enter new hometown: ";
                cin.ignore(); 
                getline(cin, newHometown);
                it->hometown = newHometown;
                break;
            }
            case 3: { 
                string newPhoneNumber;
                cout << "Enter new phone number: ";
                getline(cin, newPhoneNumber);
                it->phoneNumber = newPhoneNumber;
                break;
            }
            case 4: { 
                string newSpecialty;
                cout << "Enter new specialty: ";
                getline(cin, newSpecialty);
                it->specialty = newSpecialty;
                break;
            }
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
        }

        cout << "Doctor's information updated successfully!" << endl;
    } else {
        cout << "Doctor not found with the name: " << nameQuery << endl;
    }
}


void displayAllDoctors(const vector<Doctor>& doctors) {
    if (doctors.empty()) {
cout << "No doctors found in the system." << endl;
    } else {
        cout << "\nList of Doctors:" << endl;
        for (const Doctor& doctor : doctors) {
            printDoctor(doctor);
        }
    }
}

int main() {
    
    vector<Doctor> doctors;

    
    int choice;
    do {
        cout << "\nDoctor Management System" << endl;
        cout << "1. Add Doctor" << endl;
        cout << "2. Delete Doctor" << endl;
        cout << "3. Modify Doctor Information" << endl;
        cout << "4. Display All Doctors" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addDoctor(doctors);
                break;
            case 2:
                deleteDoctorByName(doctors);
                break;
            case 3:
                modifyDoctorInfo(doctors);
                break;
            case 4:
                displayAllDoctors(doctors);
                break;
            case 5:
                cout << "Exiting the system..." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
        }
    } while (choice != 5);

    return 0;
}
