#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

class Booking {
public:
    string code, name, date;
    int cost;
};

int seat = 60;

void insert_details(); // Insert new movie details
void viewAll();        // View all movies
void find();           // Find a specific movie
void book_ticket();    // Book tickets
void old_record();     // View previous transactions

int main() {
    int ch;
    do {
        cout << "\n====================================================================\n";
        cout << "\t\t\t >>> Movie Ticket Booking <<< \n";
        cout << "====================================================================\n";
        cout << "Press <1> Insert Movie\n";
        cout << "Press <2> View All Movies\n";
        cout << "Press <3> Find Movie\n";
        cout << "Press <4> Book Ticket\n";
        cout << "Press <5> View All Transactions\n";
        cout << "Press <0> Exit\n";
        cout << "Enter your Choice :: ";
        cin >> ch;

        switch (ch) {
            case 1: insert_details(); break;
            case 2: viewAll(); break;
            case 3: find(); break;
            case 4: book_ticket(); break;
            case 5: old_record(); break;
            case 0: exit(0);
            default: cout << "Wrong choice!\n"; break;
        }
    } while (ch != 0);
    return 0;
}

void insert_details() {
    Booking b;
    cout << "\nEnter movie code: ";
    cin >> b.code;
    cout << "Enter movie name: ";
    cin >> b.name;
    cout << "Enter release date: ";
    cin >> b.date;
    cout << "Enter ticket price: ";
    cin >> b.cost;

    ofstream myFile("data.txt");
    if (!myFile) {
        cout << "File not found.\n";
    } else {
        myFile << b.code << " " << b.name << " " << b.date << " " << b.cost << "\n";
        cout << "Record inserted successfully.\n";
    }
}

void viewAll() {
	string line;
    ifstream inFile("data.txt");
    if (!inFile) {
        cout << "File not found!\n";
        return;
    }

    cout << "\n\n>>> Movies Available <<<\n";
   
    while (getline(inFile, line)) {
        cout << line << endl;
    }
}

void find() {
    Booking b;
    string searchCode;
    cout << "Enter movie code: ";
    cin >> searchCode;

    ifstream inFile("data.txt");
    if (!inFile) {
        cout << "File not found!\n";
        return;
    }

    bool found = false;
    while (inFile >> b.code >> b.name >> b.date >> b.cost) {
        if (b.code == searchCode) {
            cout << "\nRecord Found\n";
            cout << "Code: " << b.code << "\nMovie Name: " << b.name
                 << "\nDate: " << b.date << "\nTicket Price: " << b.cost << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "No record found with the given code.\n";
}

void book_ticket() {
    Booking b;
    string movieCode;
    string customerName;
    int mobile, totalSeats, totalAmount;

    // Display all movies
    viewAll();

    cout << "\nFor booking ticket, choose a movie (Enter Movie Code): ";
    cin >> movieCode;

    ifstream inFile("data.txt");
    if (!inFile) {
        cout << "File not found!\n";
        return;
    }

    bool found = false;
    while (inFile >> b.code >> b.name >> b.date >> b.cost) {
        if (b.code == movieCode) {
            cout << "\nRecord Found\n";
            cout << "Movie Name: " << b.name << "\nDate: " << b.date << "\nPrice: " << b.cost << endl;

            cout << "\n>>> Fill Details <<<\n";
            cout << "Your Name: ";
            cin >> customerName;
            cout << "Mobile Number: ";
            cin >> mobile;
            cout << "Total number of tickets: ";
            cin >> totalSeats;

            totalAmount = totalSeats * b.cost;

            cout << "\n***** ENJOY MOVIE *****\n";
            cout << "Name: " << customerName << "\nMobile: " << mobile << "\nMovie: " << b.name
                 << "\nSeats: " << totalSeats << "\nPer Ticket: " << b.cost
                 << "\nTotal Amount: " << totalAmount << endl;

            ofstream outFile("oldTransection.txt");
            if (outFile) {
                outFile << customerName << " " << mobile << " " << totalSeats << " " << totalAmount << "\n";
                cout << "Transaction recorded successfully.\n";
            } else {
                cout << "Unable to open transaction file.\n";
            }
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Movie code not found.\n";
}

void old_record() {
	string line;
    ifstream inFile("oldTransection.txt");
    if (!inFile) {
        cout << "Transaction file not found!\n";
        return;
    }

    cout << "\n>>> Old Transactions <<<\n";
    
    while (getline(inFile, line)) {
        cout << line << endl;
    }
}

