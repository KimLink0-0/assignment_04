#include "Library.h"
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std; // namespace std ���

class Book {
public:
    string title;
    string author;

    Book(const string& title, const string& author)
        : title(title), author(author) {}
};

class BookManager {
private:
    vector<Book> books; // å ��� ����

public:
    // å �߰� �޼���
    void addBook(const string& title, const string& author) {
        books.push_back(Book(title, author)); // push_back ���
        cout << "å�� �߰��Ǿ����ϴ�: " << title << " by " << author << endl;
    }

    // ��� å ��� �޼���
    void displayAllBooks() const {
        if (books.empty()) {
            cout << "���� ��ϵ� å�� �����ϴ�." << endl;
            return;
        }

        cout << "���� ���� ���:" << endl;
        for (size_t i = 0; i < books.size(); i++) { // �Ϲ����� for�� ���
            cout << "- " << books[i].title << " by " << books[i].author << endl;
        }
    }

    //å ã�� �޼���
    void searchByTitle(const string& title) {

        if (books.empty()) {

            cout << "���� ��ϵ� å�� �����ϴ�." << endl;
            return;
        }


        int exist = 0;

        for (size_t i = 0; i < books.size(); i++) {
            if (books[i].title == title) {

                cout << title << "�� " << i + 1 << "��° �׸� �ֽ��ϴ�." << endl;
                exist = 1;

            }
        }

        if (exist == 0) {
            cout << title << "�� ���� �����ϴ�." << endl;
        }

    }

    void searchByAuthor(const string& author) {

        if (books.empty()) {

            cout << "���� ��ϵ� å�� �����ϴ�." << endl;
            return;
        }


        int exist = 0;

        for (size_t i = 0; i < books.size(); i++) {
            if (books[i].author == author) {

                cout << author << "�� å�� " << i + 1 << "��° �׸� �ֽ��ϴ�." << endl;
                exist = 1;

            }
        }

        if (exist == 0) {
            cout << author << "������ å ���� �����ϴ�." << endl;
        }

    }
};

class BorrowManager
{
private:

    unordered_map<string, int> stock;

public:

    // �԰� �޼ҵ�
    void initializeStock(Book& book, int quantity = 3) {
        stock.insert({ book.title, quantity });
    }

    // �뿩 �޼ҵ�
    void borrowBook(string& title) {
        if (stock[title] == 0) {
            cout << title << "�� ��� �����ϴ�." << endl;
            return;
        }

        stock[title] --;
    }

    // ȸ�� �޼ҵ�
    void returnBook(string title) {
        if (stock[title] == 3) {
            cout << title << "�� ��� Ȯ�����ּ���. ���� ����: " << stock[title] << endl;
            return;
        }

        stock[title] ++;
    }

    // ��� Ȯ�� �޼ҵ�
    void displayStock() {
        if (stock.empty()) {
            cout << "���� ��� å�� ��� �����ϴ�." << endl;
            return;
        }

        cout << "���� ���� ���:" << endl;
        for (unordered_map<string, int>::iterator it = stock.begin(); it != stock.end(); ++it) {
            cout << "- " << it->first << " �� ��� : " << it->second << endl;
        }
    }

    

};


int main() {
    BookManager bookmanager;
    BorrowManager borrowmanager;


    // ������ ���� ���α׷��� �⺻ �޴��� �ݺ������� ����Ͽ� ����� �Է��� ó���մϴ�.
    // ���α׷� ���Ḧ �����ϱ� ������ ��� �����մϴ�.
    while (true) {
        cout << "\n������ ���� ���α׷�" << endl;
        cout << "1. ���� ���� ���α׷� ����" << endl;
        cout << "2. �뿩 ���� ���α׷� ����" << endl;
        cout << "3. ����" << endl;
        cout << "����: ";

        int managerChoice;
        cin >> managerChoice;

        if (managerChoice == 1) {
            while (true) {
                cout << "\n���� ���� ���α׷�" << endl;
                cout << "1. å �߰�" << endl; // å ������ �Է¹޾� å ��Ͽ� �߰�
                cout << "2. ��� å ���" << endl; // ���� å ��Ͽ� �ִ� ��� å ���
                cout << "3. �������� å �˻�" << endl; // �������� å �˻�
                cout << "4. ���ڸ����� å �˻�" << endl; // ���ڸ����� å �˻�
                cout << "5. ��������" << endl; // ���α׷� ����
                cout << "����: ";

                int choice; // ������� �޴� ������ ����
                cin >> choice;

                if (choice == 1) {
                    // 1�� ����: å �߰�
                    // ����ڷκ��� å ����� ���ڸ��� �Է¹޾� BookManager�� �߰��մϴ�.
                    string title, author;
                    cout << "å ����: ";
                    cin.ignore(); // ���� �Է��� �ܿ� ���۸� ����
                    getline(cin, title); // ���� �Է� (���� ����)
                    cout << "å ����: ";
                    getline(cin, author); // ���ڸ� �Է� (���� ����)
                    bookmanager.addBook(title, author); // �Է¹��� å ������ �߰�
                }
                else if (choice == 2) {
                    // 2�� ����: ��� å ���
                    // ���� BookManager�� ����� å ����� ����մϴ�.
                    bookmanager.displayAllBooks();
                }
                else if (choice == 3) {
                    // 3�� ����: å �������� �˻�
                    // ���� BookManager�� ����� å�� ã���ϴ�.
                    string title;
                    cout << "å ����:";
                    cin >> title;
                    bookmanager.searchByTitle(title);
                }
                else if (choice == 4) {
                    // 4�� ����: å ���ڷ� �˻�
                    // ���� BookManager�� ����� å�� ã���ϴ�.
                    string author;
                    cout << "å ���ڸ�:";
                    cin >> author;
                    bookmanager.searchByAuthor(author);

                }
                else if (choice == 5) {
                    // 5�� ����: ����
                    // ���α׷��� �����ϰ� ����ڿ��� �޽����� ����մϴ�.
                    cout << "�������� ���ư��ϴ�." << endl;
                    break; // while ���� ����
                }
                else {
                    // �߸��� �Է� ó��
                    // �޴��� ���� ��ȣ�� �Է����� ��� ��� �޽����� ����մϴ�.
                    cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
                }
            }
        }
        if (managerChoice == 2) {
            while (true) {
                cout << "\n�뿩 ���� ���α׷�" << endl;
                cout << "1. å �뿩�ϱ� " << endl; // å ������ �Է¹޾� å ��Ͽ� �߰�
                cout << "2. å �ݳ��ϱ� " << endl; // ���� å ��Ͽ� �ִ� ��� å ���
                cout << "3. ��� Ȯ���ϱ� " << endl; // �������� å �˻�
                cout << "4. ��������" << endl; // ���α׷� ����
                cout << "����: ";

                int choice; // ������� �޴� ������ ����
                cin >> choice;

                if (choice == 1) {
                    string title;
                    cout << "�뿩�� å ����:";
                    cin >> title;
                    borrowmanager.borrowBook(title);
                }
                else if (choice == 2) {
                    string title;
                    cout << "�ݳ��� å ����:";
                    cin >> title;
                    borrowmanager.returnBook(title);

                }
                else if (choice == 3) {
                    borrowmanager.displayStock();

                }
                else if (choice == 4) {
                    // 5�� ����: ����
                    // ���α׷��� �����ϰ� ����ڿ��� �޽����� ����մϴ�.
                    cout << "�������� ���ư��ϴ�." << endl;
                    break; // while ���� ����
                }
                else {
                    // �߸��� �Է� ó��
                    // �޴��� ���� ��ȣ�� �Է����� ��� ��� �޽����� ����մϴ�.
                    cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
                }
            }
        }
        if (managerChoice == 3) {
            // 5�� ����: ����
            // ���α׷��� �����ϰ� ����ڿ��� �޽����� ����մϴ�.
            cout << "���α׷��� �����մϴ�." << endl;
            break; // while ���� ����

        }
        else {
            // �߸��� �Է� ó��
            // �޴��� ���� ��ȣ�� �Է����� ��� ��� �޽����� ����մϴ�.
            cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
        }


        
   
    }
    // ���α׷� ���� ����
    return 0; 
}
