#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

// Constants
const int SIZE = 10;

// Parallel Arrays: Store names, powers, weaknesses
string names[SIZE] = {
    "Squirrel Girl", "Arm-Fall-Off-Boy", "The Tick", "Matter-Eater Lad", "Bouncing Boy",
    "Color Kid", "Doorman", "Zeitgeist", "Gin Genie", "Dogwelder"
};

string powers[SIZE] = {
    "Control Squirrels", "Detachable Limbs", "Super Strength", "Eat Anything",
    "Bounce Power", "Color Manipulation", "Teleportation", "Acid Vomit",
    "Seismic Alcohol Bursts", "Welding Dogs to Enemies"
};

string weaknesses[SIZE] = {
    "Time Limits", "Heavy Objects", "Poor Judgment", "Digestive Problems",
    "Puncture Vulnerability", "Bright Light", "Needs Doors", "Self Doubt",
    "Sobriety", "Ethical Concerns"
};

// Multidimensional Array: year introduced and comic universe
string info[SIZE][2] = {
    {"1992", "Marvel"}, {"1989", "DC"}, {"1986", "Other"}, {"1962", "DC"},
    {"1961", "DC"}, {"1966", "DC"}, {"1989", "Marvel"}, {"2001", "Marvel"},
    {"2001", "Marvel"}, {"1997", "DC"}
};
// Function Prototypes
void displayAll(bool toUpper = false);
void searchByName();
void searchByPower();
void sortAlphabetically();
void displayMenu();
string toLowerCase(string str);
string toUpperCase(string str);
int main() {
    int choice;
    do {
        displayMenu();
        cin >> choice;
        cin.ignore(); // Clean newline from buffer

        switch (choice) {
            case 1: searchByName(); break;
            case 2: searchByPower(); break;
            case 3: sortAlphabetically(); break;
            case 4: displayAll(true); break;
            case 5: displayAll(false); break;
            case 6: cout << "Exiting program. Goodbye!" << endl; break;
            default: cout << "Invalid choice. Try again.\n"; break;
        }
        cout << "\n";
    } while (choice != 6);
    return 0;
}
void displayMenu() {
    cout << "====== Superhero Database ======\n";
    cout << "1. Search by Name\n";
    cout << "2. Search by Superpower\n";
    cout << "3. Sort Alphabetically\n";
    cout << "4. Display All (UPPERCASE)\n";
    cout << "5. Display All (lowercase)\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

void displayAll(bool toUpper) {
    for (int i = 0; i < SIZE; i++) {
        string name = toUpper ? toUpperCase(names[i]) : toLowerCase(names[i]);
        string power = toUpper ? toUpperCase(powers[i]) : toLowerCase(powers[i]);
        string weak = toUpper ? toUpperCase(weaknesses[i]) : toLowerCase(weaknesses[i]);
        string year = info[i][0];
        string universe = toUpper ? toUpperCase(info[i][1]) : toLowerCase(info[i][1]);

        cout << name << " | " << power << " | " << weak << " | " << year << " | " << universe << endl;
    }
}

void searchByName() {
    string input;
    cout << "Enter superhero name to search: ";
    getline(cin, input);
    input = toLowerCase(input);

    bool found = false;
    for (int i = 0; i < SIZE; i++) {
        if (toLowerCase(names[i]).find(input) != string::npos) {
            cout << "\nFound: " << names[i] << " | " << powers[i] << " | " << weaknesses[i]
                 << " | " << info[i][0] << " | " << info[i][1] << endl;
            found = true;
        }
    }
    if (!found) cout << "No superhero found with that name.\n";
}

void searchByPower() {
    string input;
    cout << "Enter superpower keyword: ";
    getline(cin, input);
    input = toLowerCase(input);

    bool found = false;
    for (int i = 0; i < SIZE; i++) {
        if (toLowerCase(powers[i]).find(input) != string::npos) {
            cout << names[i] << " | " << powers[i] << " | " << weaknesses[i]
                 << " | " << info[i][0] << " | " << info[i][1] << endl;
            found = true;
        }
    }
    if (!found) cout << "No superhero found with that power.\n";
}

void sortAlphabetically() {
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            if (toLowerCase(names[i]) > toLowerCase(names[j])) {
                swap(names[i], names[j]);
                swap(powers[i], powers[j]);
                swap(weaknesses[i], weaknesses[j]);
                swap(info[i][0], info[j][0]);
                swap(info[i][1], info[j][1]);
            }
        }
    }
    cout << "Superheroes sorted alphabetically by name.\n";
}
string toLowerCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

string toUpperCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}