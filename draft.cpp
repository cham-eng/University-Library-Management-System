#include <iostream>
#include <iomanip>
#include <string>
    
using namespace std;

void registerBooks(int id[], string title[], string author[], int totCopies[], int copiesAva[], int &bookCount) {
    
    while (bookCount < 50){
        bool unique = false;
        while (unique == false) {
            cout << "Enter the books ID [-1 to exit]: ";
            cin >> id[bookCount];
             if (id[bookCount] == -1) 
             {
                return;
            }
            while (id[bookCount] < 0) {
                cout << "The ID can't be negative. Please try again: ";
                cin >> id[bookCount];
            }

            unique = true;
            for (int i = 0; i < bookCount; i++){
        if (id[bookCount] == id[i]){
            cout << "This ID is already present, please try again: ";
            unique = false;
            break;
        }
    }
    
    }
    cout << "Enter title, author, and total number of copies: ";
    cin.ignore();
    getline(cin, title[bookCount]);
    getline(cin, author[bookCount]);
    cin >> totCopies[bookCount];

     while (totCopies[bookCount] < 0) {
        cout << "The total number of copies can't be negative. Please try again: ";
        cin >> totCopies[bookCount];
    }
    copiesAva[bookCount] = totCopies[bookCount];

    bookCount++;
    }
}

void displayBooks(int id[],string title[],string author[],int totCopies[],int copiesAva[],int bookCount)
    {
        cout << setw(15) << "Book ID" << setw(30) << "Title" << setw(20)
        << "Author" << setw(15) << "Total" << setw(15) << "Available" << endl;

        for (int i=0; i < bookCount; i++)
        {
            cout << setw(15) << id[i] << setw(30) << title[i] << setw(20) << author[i] << setw(15)
            << totCopies[i] << setw(15) << copiesAva[i] << endl;
        }
    }


int searchBook(int id[], int bookFound, int bookCount){
    for (int i = 0; i < bookCount; i++) {
        if (id[i] == bookFound)
        return i;
    }
    return -1;
}

void borrowBook(int id[], int bookFound, int bookCount, int copiesAva[], string title[]) {
    cout << "Enter the ID of the book you would like to borrow: ";
    cin >> bookFound;
    int bookChosen = searchBook(id, bookFound, bookCount);

    if (bookChosen == -1) {
        cout << "Error: Book ID not found!\n";
        return;
    }

    if (copiesAva[bookChosen] > 0) {
        copiesAva[bookChosen]--;
        cout << "You have successfully borrowed " << title[bookChosen] <<"." <<endl;
    } else {
        cout << "Sorry, there are no more copies available.";
    }

}

void returnBook(int id[], int bookFound, int bookCount, int copiesAva[], string title[], int totCopies[]) {
    cout << "Enter the ID of the book you would like to return: ";
    cin >> bookFound;
    int bookChosen = searchBook(id, bookFound, bookCount);

    if (bookChosen == -1) {
        cout << "Error: Book ID not found!\n";
        return;
    }
    
    if (totCopies[bookChosen] > copiesAva[bookChosen]) {
        copiesAva[bookChosen]++;
        cout << "You have successfully return " << title[bookChosen] << ". \n";
    } else {
        cout << "You haven\'t borrowed that book yet.";
    }

}
void displayStatistics(int bookCount, int totCopies[], int copiesAva[]) {

    int totalPhysical = 0;
    int totalAvail = 0;
    int totalBorrowed = 0;
    
    for (int i=0; i < bookCount; i++)
    {
        totalPhysical += totCopies[i];
        totalAvail += copiesAva[i];
        totalBorrowed += totCopies[i] - copiesAva[i];
    }

    cout << "\nLibrary statistics\n";
    cout << "Total of registered book titles: " << bookCount << endl;
    cout << "Total of physical copies: " << totalPhysical << endl;
    cout << "Total of available copies: " << totalAvail << endl;
    cout << "Total of borrowed copies: " << totalBorrowed << endl;
    
}

int main() {

    int bookCount = 0;
    int bookFound = 0;
    int id[50];
    string title[50];
    string author[50];
    int totCopies[50];
    int copiesAva[50];
    int bookChosen = 0;

 int selection;

    do {
        cout << "\nLIBRARY MANAGEMENT SYSTEM\n";
        cout << "1. Register Books\n";
        cout << "2. Display All Books\n";
        cout << "3. Search for a Book\n";
        cout << "4. Borrow a Book\n";
        cout << "5. Return a Book\n";
        cout << "6. Display Library Statistics\n";
        cout << "7. Exit\n";
        
        cout << "Enter your menu selection: ";
        cin >> selection;
        
        switch (selection) {
            case 1:
            registerBooks(id, title, author, totCopies, copiesAva, bookCount);
            break;
            case 2:
            displayBooks (id, title, author,  totCopies, copiesAva, bookCount);
            break;
            case 3:
            cout << "Enter the Id of the book you would like to find: ";
            cin >> bookFound;
            searchBook(id, bookFound, bookCount);
            cout << setw(15) << "Book ID" << setw(30) << "Title" << setw(20)
        << "Author" << setw(15) << "Total" << setw(15) << "Available" << endl;

         cout << setw(15) << id[bookChosen] <<  setw(30) << title[bookChosen] << setw(20) << author[bookChosen] 
         << setw(15) << totCopies[bookChosen] << setw(15) << copiesAva[bookChosen] << endl;

            break;
            case 4:
            borrowBook(id, bookFound, bookCount, copiesAva, title);
            break;
            case 5:
            returnBook(id, bookFound, bookCount, copiesAva, title, totCopies);
            break;
            case 6:
            displayStatistics(bookCount, totCopies, copiesAva);
            break;
            default: cout << "Invalid selection.\n";
            case 7:
            break;
        }
    } while (selection != 7);

    return 0;

}