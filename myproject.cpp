//***LIBRARY MANAGEMENT SYSTEM PROJECT***/

#include <iostream>
#include <vector> //Create collections of my 3 objects.
#include <string>
#include <ctime>   //For working with dates. 
using namespace std;


//Book Details.
class Book {
public:
    int bookID;
    string title, author, genre;
    bool isAvailable;  

    Book(int id, string t, string a, string g) : bookID(id), title(t), author(a), genre(g), isAvailable(true) {}  //Creates the book object.
};

//Member Details.
class Member {
public:
    int memberID;
    string name, address, phoneNumber;

    Member(int id, string n, string a, string p) : memberID(id), name(n), address(a), phoneNumber(p) {} //Creates the member object.
};

//Transaction Details.
class Transaction {
public:
    int transactionID, memberID, bookID;
    time_t borrowDate, returnDate; //From ctime library

    Transaction(int tid, int mid, int bid, time_t bDate) : transactionID(tid), memberID(mid), bookID(bid), borrowDate(bDate), returnDate(0) {}  //Creates transaction object.
};

//Creates collections of our objects..
vector<Book> books;
vector<Member> members;
vector<Transaction> transactions;
int nextBookID = 1, nextMemberID = 1, nextTransactionID = 1;

//Add a new book to the library.
void addBook() {
    string title, author, genre;
    cout << "Enter title: "; cin.ignore(); getline(cin, title);
    cout << "Enter author: "; getline(cin, author);
    cout << "Enter genre: "; getline(cin, genre);
    books.push_back(Book(nextBookID++, title, author, genre));
    cout << "Book added successfully.\n";
}

//Add a new member to the library
void addMember() {
    string name, address, phone;
    cout << "Enter name: "; cin.ignore(); getline(cin, name);
    cout << "Enter address: "; getline(cin, address);
    cout << "Enter phone number: "; getline(cin, phone);
    members.push_back(Member(nextMemberID++, name, address, phone));
    cout << "Member added successfully.\n";
}

//Function to borrow book.
void borrowBook() {
    int mid, bid;//The id of member and book
    cout << "Enter member ID: "; cin >> mid;
    cout << "Enter book ID: "; cin >> bid;
    time_t now = time(0);
    for (auto &b : books) {
        if (b.bookID == bid && b.isAvailable) {
            b.isAvailable = false;
            transactions.push_back(Transaction(nextTransactionID++, mid, bid, now));
            cout << "Book borrowed successfully.\n";
            return;
        }
    }
    cout << "Book not available.\n";
}

//Function to return the book
void returnBook() {
    int tid;//we only need the transaction id.
    cout << "Enter transaction ID: "; cin >> tid;
    time_t now = time(0);
    for (auto &t : transactions) {
        if (t.transactionID == tid && t.returnDate == 0) {
            t.returnDate = now;
            for (auto &b : books) {
                if (b.bookID == t.bookID) {
                    b.isAvailable = true;
                    cout << "Book returned successfully. Overdue fee: $" << difftime(now, t.borrowDate) / (60 * 60 * 24) << "\n";
                    return;
                }
            }
        }
    }
    cout << "Transaction not found.\n";
}

//Function to view available books
void viewBooks() {
    for (const auto &b : books) {
        cout << b.bookID << ": " << b.title << " by " << b.author << " (" << b.genre << ") - " << (b.isAvailable ? "Available" : "Borrowed") << endl;
    }
}
//Function to view all members
void viewMembers() {
    for (const auto &m : members) {
        cout << m.memberID << ": " << m.name << ", " << m.address << ", " << m.phoneNumber << endl;
    }
}

//Function to view all transactions
void viewTransactions() {
    for (const auto &t : transactions) {
        cout << t.transactionID << ": Member " << t.memberID << " borrowed book " << t.bookID 
             << " on " << ctime(&t.borrowDate) << " and returned on " << (t.returnDate ? ctime(&t.returnDate) : "Not returned yet") << endl;
    }
}

int main() {

    int choice;

    while (true) {

        cout <<"------------------------------\n";
        cout << "Library Management System\n";
        cout <<"------------------------------\n";
        cout << "1. Add Book\n2. Add Member\n3. Borrow Book\n4. Return Book\n5. View Books\n6. View Members\n7. View Transactions\n8. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: addBook(); break;
            case 2: addMember(); break;
            case 3: borrowBook(); break;
            case 4: returnBook(); break;
            case 5: viewBooks(); break;
            case 6: viewMembers(); break;
            case 7: viewTransactions(); break;
            case 8:
                cout<<"Thank you and you welcome back! Kwaheri..";
                return 0;
            default: cout << "Invalid choice.\n";
        }
    }
    return 0;
}
