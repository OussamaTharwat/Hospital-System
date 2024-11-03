#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


string arr[20][5];
bool status[20][5];
int idx[20];

void sort() {
    for (int i = 0; i < 20; i++) {
        for (int j = idx[i]-1; j >= 0; j--) {
            for (int k = j; k >= 0; k--) {
                if (status[i][j] == 1 && status[i][k] == 0) {
                    swap(status[i][j], status[i][k]);
                    swap(arr[i][j], arr[i][k]);
                }
            }
        }
    }
}
void reset() {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 5; j++) {
            arr[i][j] = arr[i][j+1];
            status[i][j] = status[i][j+1];
        }
    }
}
void get_next_patient() {
    cout << "Enter the number of the specialization: ";
    int spec;
    cin >> spec;
    if (idx[spec]) {
        cout << arr[spec][0] <<", Please go with the Doctor " <<  endl;
        reset();
        idx[spec]--;
    }
    else {
        cout << "No Patients" << endl;
    }
}

void print_all() {
    for (int i = 0; i < 20; i++) {
        if (idx[i] == 0) {
            continue;
        }
        cout << "Specialization: " << i << " Has: " << idx[i] << " Patients" << endl;
        for (int j = 0; j < idx[i]; j++) cout << arr[i][j] << status[i][j] << endl;
    }
}
void add_patient() {
    cout << "Enter Specialization, Name, Status: ";
    int specialization;
    string name;
    bool st;
    cin >> specialization >> name >> st;
    if (idx[specialization] < 5) {
        arr[specialization][idx[specialization]] = name;
        status[specialization][idx[specialization]] = st;
        idx[specialization]++;
        sort();

    }
    else {
        cout << "Sorry we can't add more patients";
    }

}
void menu() {
    while (true){
        cout << "Enter Your Choice: " << endl;
        cout << "1. Add New Patient" << endl;
        cout << "2. Print All Patients" << endl;
        cout << "3. Get Next Patient" << endl;
        cout << "4. Exit" << endl;
        int choice; cin >> choice;
        if (choice == 1) add_patient();
        else if (choice == 2) print_all();
        else if (choice == 3) get_next_patient();
        else if (choice == 4) break;
        else cout << "Invalid Choice" << endl;
    }
}
int main() {
    menu();
}
