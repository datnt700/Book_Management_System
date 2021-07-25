#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

class Book
{
public:
	//setters - assigning user value to private variables
	void setId(string id)
	{
		this->id = id;
	}
	void setTitle(string title)
	{
		this->title = title;
	}
	void setAuthor(string author)
	{
		this->author = author;
	}
	void setEdition(string edition)
	{
		this->edition = edition;
	}
	void setPublication(string publication)
	{
		this->publication = publication;
	}
	//getters - getting the values from private variables
	string getId()
	{
		return id;
	}
	string getTitle()
	{
		return title;
	}
	string getEdition()
	{
		return edition;
	}
	string getPublication()
	{
		return publication;
	}
	string getAuhor()
	{
		return author;
	}

private:
	string id,title, edition, publication, author;
};

//Initilizing functions
void addBook(int counter);
void deleteBook(int counter);
void editBook(int counter);
void searchBook(int counter);
void viewAllBook(int counter);
void quit();

//counter for Book array
int counter = 0;

//function for incrementing counter
void increment(int a) {
	a++;
	counter = a;
}

//function for decrementing counter
void decrement(int a) {
	a--;
	counter = a;
}

//Book class array initialization
Book books[10];


int main()
{
	system("color f4");
	int choice;
	//Main Menu
	system("cls");
	cout << "LIBRARY MANAGEMENT SYSTEM\n\n";
	cout << "1.ADD BOOK\n";
	cout << "2.DELETE BOOK\n";
	cout << "3.EDIT BOOK\n";
	cout << "4.SEARCH BOOK\n";
	cout << "5.VIEW ALL BOOKS\n";
	cout << "6.QUIT\n\n";

	cout << "ENTER CHOICE: ";
	cin >> choice;
	system("cls");

	switch (choice)
	{
	case 1:
		addBook(counter);
		break;
	case 2:
		deleteBook(counter);
		break;
	case 3:
		editBook(counter);
		break;
	case 4:
		searchBook(counter);
		break;
	case 5:
		viewAllBook(counter);
		break;
	case 6:
		quit();
	default:
		break;
	}

	_getch();
	return 0;
}

void addBook(int counter)
{
	
	string id, title, author, edition, publication;
	cout << "ADD BOOK\n\n";
	if (counter < 10) {
		
		cout << "Enter id: ";
		cin >> id; 
		cout << "Enter Title: ";
		cin.ignore();
		getline(cin, title);
		cout << "Enter Author: ";
		getline(cin, author);
		cout << "Enter Edition: ";
		getline(cin, edition);
		cout << "Enter Publication: ";
		getline(cin, publication);

		books[counter].setId(id); //assigning the values entered to book object
		books[counter].setTitle(title);
		books[counter].setAuthor(author);
		books[counter].setEdition(edition);
		books[counter].setPublication(publication);
		increment(counter);	//calling function to increment counter
		cout << "\nBOOK ADDED SUCCESSFULLY!\n\nPress any key to continue . . .";
		_getch();
		main();
	}
	else {
		cout << "YOU HAVE REACHED THE MAXIMUM NUMBER OF BOOKS TOBE ADDED!\n\nPress any key to continue . . .";
		_getch();
		main();
	}
	
}

void deleteBook(int counter)
{
	string id;
	int choice;
	cout << "DELETE BOOK\n\n";
	if (counter == 0) {
		cout << "THERE IS NO BOOK TO DELETE!\n\nPress any key to continue . . .";
		_getch();
		main();
	}
	cout << "Enter Id: ";
	cin >> id;

	for (int i = 0; i < counter; i++) {
		//finding a match using for loop
		if (books[i].getId() == id) {
			cout << "\nBOOK FOUND\n\n";
			cout << "Do you want to delete?\n[1]Yes\n[2]No\n\nEnter Choice: ";
			cin >> choice;
			if (choice == 1) {
				books[i].setId(""); //setting the value to none
				books[i].setTitle("");
				books[i].setAuthor("");
				books[i].setEdition("");
				books[i].setPublication("");
				for (int a = i; a < counter; a++) {
					//adjusting the values after deletion of data eg. data from book[4] copied to book[3]
					books[a] = books[a + 1];
				}
				decrement(counter); //calling function to decrement counter
				cout << "\nBOOK SUCCESSFULLY DELETED!\n\nPress any key to continue . . .";
				_getch();
				main();
			}
			else {
				main();
			}
		}
	}
	cout << "\nBOOK NOT FOUND!\n\nPress any key to continue . . .";
	_getch();
	main();

}

void editBook(int counter)
{
	system("cls");
	string id, title, edition, publication, author;
	string editId;
	int choice;
	cout << "\n\nEdit Book\n";
	if (counter == 0)
	{
		cout << "THERE IS NO BOOK TO EDIT\n\nPress any key to continue ...";
		_getch();
		main();
	}
	cout << "Enter ID: ";
	cin >> editId;
	for (int i = 0; i < counter; i++)
	{
		if (books[i].getId() == editId)
		{
			cout << "BOOK DETAILS\n\n";
			cout << "ID: " << books[i].getId() << endl;
			cout << "TITLE: " << books[i].getTitle() << endl;
			cout << "Author: " << books[i].getAuhor() << endl;
			cout << "EDITION: " << books[i].getEdition() << endl;
			cout << "PUBLICATION: " << books[i].getPublication() << endl << endl;
			cout << "Do you want edit this book\n\n1.Yes/2.No\n";
			cin >> choice;
			if (choice == 1)
			{
				cout << "Enter ID: ";
				cin >> id;
				cout << "Enter Title: ";
				cin.ignore();
				getline(cin, title);
				cout << "Enter Author: ";
				getline(cin, author);
				cout << "Enter Edition: ";
				getline(cin, edition);
				cout << "Enter Publication: ";
				getline(cin, publication);
				books[i].setId(id);
				books[i].setTitle(title);
				books[i].setAuthor(author);
				books[i].setEdition(edition);
				books[i].setPublication(publication);
				cout << "\n\n---Edit Completed---\n\n\n\nPress any key to continue . . .";
				_getch();
				main();
			}
		}
	}
	cout << "Book Not Found\n\nPress any key to continue ...";
	_getch();
	main();

}

void searchBook(int counter)
{
	string id;
	cout << "Enter ID: ";
	cin >> id;
	for (int i = 0; i < counter; i++)
	{
		if (books[i].getId() == id)
		{
			cout << "\n\nBOOK DETAILS\n\n";
			cout << "ID: " << books[i].getId() << endl;
			cout << "TITLE: " << books[i].getTitle() << endl;
			cout << "Author: " << books[i].getAuhor() << endl;
			cout << "EDITION: " << books[i].getEdition() << endl;
			cout << "PUBLICATION: " << books[i].getPublication() << endl << endl;
		}
	}
	cout << "Press any key to continue . . .";
	_getch();
	main();
}

void viewAllBook(int counter)
{
	//iterating all the values on the library using book array
	cout << "VIEW ALL BOOKS\n\n";
	for (int i = 0; i < counter; i++) {
		cout << "BOOK DETAILS\n\n";
		cout << "ID: " << books[i].getId() << endl;
		cout << "TITLE: " << books[i].getTitle() << endl;	
		cout << "Author: " << books[i].getAuhor() << endl;
		cout << "EDITION: " << books[i].getEdition() << endl;
		cout << "PUBLICATION: " << books[i].getPublication() << endl << endl;
	}
	cout << "Press any key to continue . . .";
	_getch();
	main();
}

void quit()
{
	_exit(1);
}




























//void addBook(int counter) {
//	int isbn;
//	string title, author, edition, publication;
//	cout << "ADD BOOK\n\n";
//	if (counter < 10) {
//		cout << "Enter ISBN: ";
//		cin>> isbn; //getline - just like cin but includes white spaces
//		cout << "Enter Title: ";
//		cin >> title;
//		cout << "Enter Author: ";
//		cin >> author;
//		cout << "Enter Edition: ";
//		cin >> edition;
//		cout << "Enter Publication: ";
//		cin >> publication;
//		books[counter].setIsbn(isbn); //assigning the values entered to book object
//		books[counter].setTitle(title);
//		books[counter].setAuthor(author);
//		books[counter].setEdition(edition);
//		books[counter].setPublication(publication);
//		increment(counter);	//calling function to increment counter
//		cout << "\nBOOK ADDED SUCCESSFULLY!\n\nPress any key to continue . . .";
//		_getch();
//		main();
//	}
//	else {
//		cout << "YOU HAVE REACHED THE MAXIMUM NUMBER OF BOOKS TOBE ADDED!\n\nPress any key to continue . . .";
//		_getch();
//		main();
//	}
//}
//void deleteBook(int counter)
//{
//	int isbn;
//	int choice;
//	cout << "Delete Book" << endl;
//	if (counter == 0) {
//		cout << "There is no book to delete\n\n Press any key to continue....";
//		_getch();
//		main();
//	}
//	cout << "Enter ISBN: ";
//	cin >> isbn;
//	for (int i = 0; i < counter; i++)
//	{
//		if(books[i].getIsbn()==isbn)
//		{
//			cout << "\nBook Found\n\n";
//			cout << "Do you want to delete\n[1]Yes\n[2]No\n\nEnter choice: ";
//			cin >> choice;
//			if (choice == 1)
//			{
//				books[i].setIsbn(isbn);
//				books[i].setTitle("");
//				books[i].setAuthor("");
//				books[i].setEdition("");
//				books[i].setPublication("");
//				for (int a = i; a < counter; a++)
//				{
//					books[a] = books[a + 1];
//				}
//				
//				decrement(counter);
//				cout << "\nBook successfully Deleted\n\nPress any key to continue";
//				_getch();
//				main();
//			}
//			else
//			{
//				main();
//			}
//		}
//	}
//	cout << "\nBook not Found\n\nPress any key to continue...";
//	_getch();
//	main();
//}
//void editBook(int counter)
//{
//	system("cls");
//	int editIsbn, isbn, choice;
//	string title, author, edition, publication;
//	cout << "\nEdit Book\n\n";
//	if (counter == 0) {
//		cout << "There is no book to edit\n\n Press any key to continue...";
//		_getch();
//		main();
//	}
//	cout << "Enter ISBN: ";
//	cin>> editIsbn;
//	for (int i = 0; i < counter; i++)
//	{
//		if (books[i].getIsbn() == editIsbn)
//		{
//			cout << "\nBook Found\n\n";
//			cout << "ISBN: " << books[i].getIsbn() << endl;
//			cout << "TITLE: " << books[i].getTitle() << endl;
//			cout << "Author: " << books[i].getAuthor() << endl;
//			cout << "Publication: " << books[i].getPublication() << endl;
//			cout << "\nDo you want to edit\n[1]Yes\n[2]No\n\nEnter choice: ";
//			cin >> choice;
//			if (choice == 1)
//			{
//				cout << "Enter ISBN: ";
//				cin>> isbn;
//				cout << "Enter Title: ";
//				cin >> title;
//				cout << "Enter Author: ";
//				cin >> author;
//				cout << "Enter Editiion: ";
//				cin >> edition;
//				cout << "Enter Publication: ";
//				cin >> publication;
//				books[i].setIsbn(isbn);
//				books[i].setTitle(title);
//				books[i].setAuthor(author);
//				books[i].setEdition(edition);
//				books[i].setPublication(publication);
//				cout << "\nBook Edited Successfully!\n\nPress any key to continue...";
//				_getch();
//				main();
//			}
//			else
//			{
//				main();
//			}
//		}
//	}
//	cout << "\n Book Not Found!\n\nPress any key continue...";
//	_getch();
//	main();
//}
//void searchBook(int counter)
//{
//	int isbn;
//	
//	bool print = false;
//	cout << "Search Book\n\n";
//	if (counter == 0)
//	{
//		cout << "There is no book to search\n\nPress any key to continue ...";
//		_getch();
//		main();
//	}
//	cout << "Enter ISBN: ";
//	cin>> isbn;
//	for (int i = 0; i < counter; i++)
//	{
//		if (books[i].getIsbn() == isbn)
//		{
//			cout << "\nBook Found\n\n";
//			cout << "Title: " << books[i].getTitle() << endl;
//			cout << "Author: " << books[i].getAuthor() << endl;
//			cout << "Edition: " << books[i].getEdition() << endl;
//			cout << "Publication: " << books[i].getPublication() << endl;
//			print = true;
//		}
//	}
//	if (print)
//	{
//		cout << "\n\nPress any key to continue ...";
//		_getch();
//		main();
//	}
//	else
//	{
//		cout << "\nBook not found\nPress any key to continue ...";
//		_getch();
//		main();
//	}
//}
//void viewAllBook(int counter)
//{
//	cout << "View All Book" << endl;
//	for (int i = 0; i < counter; i++)
//	{
//		cout << "Book Details \n\n";
//		cout << "ISBN: " << books[i].getIsbn() << endl;
//		cout << "Title: " << books[i].getTitle() << endl;
//		cout << "Author: " << books[i].getAuthor() << endl;
//		cout << "Edition: " << books[i].getEdition() << endl;
//		cout << "Publication: " << books[i].getPublication() << endl;
//	}
//	if (counter == 0)
//	{
//		cout << "No Book in library " << endl;
//	}
//	else
//	{
//		cout << "\n\nPress any key to continue...";
//		_getch();
//		main();
//	}
//	
//}
//void Quit()
//{
//	_exit(1);
//}
