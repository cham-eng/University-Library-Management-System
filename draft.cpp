#include <iostream>
#include <array>
using namespace std;

void registerBooks(int id[], string title[], string author[], int totCopies[], int availCopies[], int bookCount)
{
    while (bookCount < 50)
    {
        cout << "Enter the book ID (enter -1 to exit): ";
        cin >> id[bookCount];

        if (id[bookCount] == -1)
        break;

        for (int i{0}; i < bookCount; i++)
        {
            bool isUnique = true;
            if (id[bookCount] == id[i])
            {
                isUnique = false;
                cout << "This ID has already been entered, please enter another ID";
                break;
            }
        }

    cout << "Enter the book title and the author's name: ";
    cin >> title[bookCount] >> author[bookCount];
    
    while (totCopies[bookCount] <= 0)
    {
        cout << "Enter the total number of copies: ";
        cin >> totCopies[bookCount];
        if (totCopies[bookCount] <= 0)
        cout << "Invalid Entry";
    }

    availCopies[bookCount] = totCopies[bookCount];

    ++bookCount;

    }

}

int main ()
{
    int id[50];
    string title[50];
    string author[50];
    int totCopies[50];
    int availCopies[50];
    int bookCount = 0;

    registerBooks(id, title, author, totCopies, availCopies, 3);
}