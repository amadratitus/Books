#include <iostream>
#include <string>
#include<cstdio>
using namespace std;

class Book {
private:
    string* author;
    string* title;
    float* price;
    string* publisher;
    int* stock;
    static int successfulTransactions;
    static int unsuccessfulTransactions;

    // Private member function to update book price
    void updatePrice(float newPrice) {
        *price = newPrice;
    }

public:
    // Constructor
    Book(string author, string title, float price, string publisher, int stock) {
        this->author = new string(author);
        this->title = new string(title);
        this->price = new float(price);
        this->publisher = new string(publisher);
        this->stock = new int(stock);
    }

    // Check if book is available and process the transaction
    void transaction(int requestedCopies) {
        if (*stock >= requestedCopies) {
            cout <<endl<< "Book details:" << endl;
            cout << "Title: " << *title << endl;
            cout << "Author: " << *author << endl;
            cout << "Price: $" << *price << endl;
            cout << "Publisher: " << *publisher << endl;
            cout << "Stock position: " << *stock << endl;

            float totalCost = requestedCopies * (*price);
            cout << "Total cost for " << requestedCopies << " copies: $" << totalCost << endl;

            *stock -= requestedCopies;
            successfulTransactions++;
        } else {
            cout << "Required number not in stock." << endl;
            unsuccessfulTransactions++;
        }
    }

    static int getSuccessfulTransactions() {
        return successfulTransactions;//return the number of successful transactions
    }

    static int getUnsuccessfulTransactions() {
        return unsuccessfulTransactions; // return the number of unsuccessful transactions
    }

    // Function to search for a book by title and author which is in boolean form.
    bool searchBook(const string& searchTitle, const string& searchAuthor) {
    return ((*title) == searchTitle && (*author) == searchAuthor);
}

};

// Initializing static member variables
int Book::successfulTransactions = 0;
int Book::unsuccessfulTransactions = 0;

int main() {
    // Creating book objects
    Book* books[3];
    books[0] = new Book("Nanyonga Swabrah", "Database Management System",15.69, "System Inc Publishers", 20);
    books[1] = new Book("Christopher Titus", "Object Oriented Programming", 49.99, "iChris Publishers", 15);
    books[2] = new Book("Richard Ssenoga", "Software Engineering Fundamentals", 25.99, "Kyambogo Publishers", 10);

    // User input
    string searchTitle, searchAuthor;
    cout<<"================= Welcome to iChris Book Stores ================="<<endl<<endl;
    cout<<"Enter the book "<<endl;
    cout << "Title: ";
    getline(cin, searchTitle);
    cout << "Author: ";
    getline(cin, searchAuthor);

    // Search for the book in the system
    bool bookFound = false;
    for (int i = 0; i < 3; i++) {
        if (books[i]->searchBook(searchTitle, searchAuthor)) {
            bookFound = true;
            int requestedCopies;
            cout << "Enter the number of copies required: ";
            cin >> requestedCopies;
            cin.ignore();  // Ignore the newline character in the input buffer

            books[i]->transaction(requestedCopies);
            break;
        }
    }
    //Prints error message if the book doesn't exist in the system.
    if (!bookFound) {
        cout << "The book is not available in the system." << endl;
    }

    // Clean up memory previously allocated
    for (int i = 0; i < 3; i++) {
        delete books[i];
    }

    // Accessing and display of transaction counts
    cout << "Successful transactions: " << Book::getSuccessfulTransactions() << endl;
    cout << "Unsuccessful transactions: " << Book::getUnsuccessfulTransactions() << endl;

    return 0;
}
