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
void displayStatistics(){


    
}
int main() {

    int bookCount = 0;
    int id[50];
    string title[50];
    string author[50];
    int totCopies[50];
    int copiesAva[50];


    registerBooks(id, title, author, totCopies, copiesAva, bookCount);









}