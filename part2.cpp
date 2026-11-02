#include <iostream>
#include <string>
    
using namespace std;

void displayBooks(int id[],string title[],string author[],int totCopies[],int copiesAva[],int bookCount)
    {
        cout << "Book ID\tTitle\tAuthor\tTotal\tAvailable" << endl;

        for (int i=0; i < bookCount; i++)
        {
            cout << id[i] << "\t.  " << title[i] << "\t" << author[i] << "\t"
            << totCopies[i] << "\t" << copiesAva[i] << "\t" << endl;
        }

    }

int main() {

    int bookCount = 0;
    int id[50];
    string title[50];
    string author[50];
    int totCopies[50];
    int copiesAva[50];

    displayBooks(id, title, author, totCopies, copiesAva, bookCount);
}