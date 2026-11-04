#include <iostream>
#include <iomanip>
#include <string>
    
using namespace std;

void displayBooks (int id[],string title[],string author[],int totCopies[],int copiesAva[],int bookCount)
    {
        cout << "Book ID" << setw(10) << "Title" << setw(10)
        << "Author" << setw(10) << "Total" << setw(10) << "Available" << endl;

        for (int i=0; i < bookCount; i++)
        {
            cout << id[i] << setw(10) << title[i] << setw(10) << author[i] << setw(10)
            << totCopies[i] << setw(10) << copiesAva[i] << setw(10) << endl;
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

    displayBooks(id, title, author, totCopies, copiesAva, bookCount);
    displayStatistics(bookCount, totCopies, copiesAva);

}