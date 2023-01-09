#pragma once

class Book {
  private:
	string author;
	string category;
	int pages;

  public:
    string status;
    Book() = default;
	Book(string author, string category, int pages, string status)
	{
		this->author = author;
		this->category = category;
		this->pages = pages;
		this->status = status;
	}
    friend ostream& operator <<(ostream& out, const Book& b) {
        out << b.author;
        out << " ";
        out << b.category;
        out << " ";
        out << b.pages;
        out << " ";
        out << b.status;
        out << endl;
        return out;
        }
};
