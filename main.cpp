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
    copiesAva[bookCount] = totCopies[bookCount];

    bookCount++;
    }
}

void displayBooks(int id[],string title[],string author[],int totCopies[],int copiesAva[],int bookCount)
    {
        cout << "Book ID" << setw(10) << "Title" << setw(10)
        << "Author" << setw(10) << "Total" << setw(10) << "Available" << endl;

        for (int i=0; i < bookCount; i++)
        {
            cout << id[i] << setw(10) << title[i] << setw(10) << author[i] << setw(10)
            << totCopies[i] << setw(10) << copiesAva[i] << setw(10) << endl;
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

    cout << "Library statistics\n";
    cout << "Total registered book titles: " << bookCount << endl;
    cout << "Total physical copies: " << totalPhysical << endl;
    cout << "Total available copies: " << totalAvail << endl;
    cout << "Total borrowed copies: " << totalBorrowed << endl;
    
}


    
int main() {

    int bookCount = 0;
    int id[50];
    string title[50];
    string author[50];
    int totCopies[50];
    int copiesAva[50];


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
            searchBook(id, bookFound, bookCount);
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
        }
    } while (selection != 7);






    return 0;


}