#include <iostream>

#include <string>
    
using namespace std;

void registerBooks(int id[], string title[], string author[], int totCopies[], int copiesAva[], int &bookCount) {
    
   

    while (bookCount < 50){
    cout << "Enter the books ID, title, author, total number of copies[-1 to exit]: ";
    cin >> id[bookCount];
    if (id[bookCount] == -1) {
        return;
    }
    cin.ignore();
    getline(cin, title[bookCount]);
    getline(cin, author[bookCount]);
    cin >> totCopies[bookCount];
    totCopies[bookCount] = copiesAva[bookCount];

    bookCount++;
    }
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