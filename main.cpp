#include <iostream>

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

int searchBook(int id[], int bookFound, int bookCount){

    cout << "Search for a book by its ID: ";
    cin >> bookFound;
    for (int i = 0; i < bookCount; i++) {
        if (id[i] == bookFound)
        return i;
    }
}

int main() {

    int bookCount = 0;
    int id[50];
    string title[50];
    string author[50];
    int totCopies[50];
    int copiesAva[50];

    int bookFound = 0;

    registerBooks(id, title, author, totCopies, copiesAva, bookCount);









}