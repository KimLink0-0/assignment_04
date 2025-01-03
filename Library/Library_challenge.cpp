#include "Library.h"
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std; // namespace std 사용

class Book {
public:
    string title;
    string author;

    Book(const string& title, const string& author)
        : title(title), author(author) {}
};

class BookManager {
private:
    vector<Book> books; // 책 목록 저장

public:
    // 책 추가 메서드
    void addBook(const string& title, const string& author) {
        books.push_back(Book(title, author)); // push_back 사용
        cout << "책이 추가되었습니다: " << title << " by " << author << endl;
    }

    // 모든 책 출력 메서드
    void displayAllBooks() const {
        if (books.empty()) {
            cout << "현재 등록된 책이 없습니다." << endl;
            return;
        }

        cout << "현재 도서 목록:" << endl;
        for (size_t i = 0; i < books.size(); i++) { // 일반적인 for문 사용
            cout << "- " << books[i].title << " by " << books[i].author << endl;
        }
    }

    //책 찾기 메서드
    void searchByTitle(const string& title) {

        if (books.empty()) {

            cout << "현재 등록된 책이 없습니다." << endl;
            return;
        }


        int exist = 0;

        for (size_t i = 0; i < books.size(); i++) {
            if (books[i].title == title) {

                cout << title << "은 " << i + 1 << "번째 항목에 있습니다." << endl;
                exist = 1;

            }
        }

        if (exist == 0) {
            cout << title << "의 재고는 없습니다." << endl;
        }

    }

    void searchByAuthor(const string& author) {

        if (books.empty()) {

            cout << "현재 등록된 책이 없습니다." << endl;
            return;
        }


        int exist = 0;

        for (size_t i = 0; i < books.size(); i++) {
            if (books[i].author == author) {

                cout << author << "의 책은 " << i + 1 << "번째 항목에 있습니다." << endl;
                exist = 1;

            }
        }

        if (exist == 0) {
            cout << author << "저자의 책 재고는 없습니다." << endl;
        }

    }
};

class BorrowManager
{
private:

    unordered_map<string, int> stock;

public:

    // 입고 메소드
    void initializeStock(Book& book, int quantity = 3) {
        stock.insert({ book.title, quantity });
    }

    // 대여 메소드
    void borrowBook(string& title) {
        if (stock[title] == 0) {
            cout << title << "의 재고가 없습니다." << endl;
            return;
        }

        stock[title] --;
    }

    // 회수 메소드
    void returnBook(string title) {
        if (stock[title] == 3) {
            cout << title << "의 재고를 확인해주세요. 현재 재고는: " << stock[title] << endl;
            return;
        }

        stock[title] ++;
    }

    // 재고 확인 메소드
    void displayStock() {
        if (stock.empty()) {
            cout << "현재 모든 책의 재고가 없습니다." << endl;
            return;
        }

        cout << "현재 도서 재고:" << endl;
        for (unordered_map<string, int>::iterator it = stock.begin(); it != stock.end(); ++it) {
            cout << "- " << it->first << " 의 재고량 : " << it->second << endl;
        }
    }

    

};


int main() {
    BookManager bookmanager;
    BorrowManager borrowmanager;


    // 도서관 관리 프로그램의 기본 메뉴를 반복적으로 출력하여 사용자 입력을 처리합니다.
    // 프로그램 종료를 선택하기 전까지 계속 동작합니다.
    while (true) {
        cout << "\n도서관 관리 프로그램" << endl;
        cout << "1. 도서 관리 프로그램 실행" << endl;
        cout << "2. 대여 관리 프로그램 실행" << endl;
        cout << "3. 종료" << endl;
        cout << "선택: ";

        int managerChoice;
        cin >> managerChoice;

        if (managerChoice == 1) {
            while (true) {
                cout << "\n도서 관리 프로그램" << endl;
                cout << "1. 책 추가" << endl; // 책 정보를 입력받아 책 목록에 추가
                cout << "2. 모든 책 출력" << endl; // 현재 책 목록에 있는 모든 책 출력
                cout << "3. 제목으로 책 검색" << endl; // 제목으로 책 검색
                cout << "4. 저자명으로 책 검색" << endl; // 저자명으로 책 검색
                cout << "5. 이전으로" << endl; // 프로그램 종료
                cout << "선택: ";

                int choice; // 사용자의 메뉴 선택을 저장
                cin >> choice;

                if (choice == 1) {
                    // 1번 선택: 책 추가
                    // 사용자로부터 책 제목과 저자명을 입력받아 BookManager에 추가합니다.
                    string title, author;
                    cout << "책 제목: ";
                    cin.ignore(); // 이전 입력의 잔여 버퍼를 제거
                    getline(cin, title); // 제목 입력 (공백 포함)
                    cout << "책 저자: ";
                    getline(cin, author); // 저자명 입력 (공백 포함)
                    bookmanager.addBook(title, author); // 입력받은 책 정보를 추가
                }
                else if (choice == 2) {
                    // 2번 선택: 모든 책 출력
                    // 현재 BookManager에 저장된 책 목록을 출력합니다.
                    bookmanager.displayAllBooks();
                }
                else if (choice == 3) {
                    // 3번 선택: 책 제목으로 검색
                    // 현재 BookManager에 저장된 책을 찾습니다.
                    string title;
                    cout << "책 제목:";
                    cin >> title;
                    bookmanager.searchByTitle(title);
                }
                else if (choice == 4) {
                    // 4번 선택: 책 저자로 검색
                    // 현재 BookManager에 저장된 책을 찾습니다.
                    string author;
                    cout << "책 저자명:";
                    cin >> author;
                    bookmanager.searchByAuthor(author);

                }
                else if (choice == 5) {
                    // 5번 선택: 종료
                    // 프로그램을 종료하고 사용자에게 메시지를 출력합니다.
                    cout << "이전으로 돌아갑니다." << endl;
                    break; // while 루프 종료
                }
                else {
                    // 잘못된 입력 처리
                    // 메뉴에 없는 번호를 입력했을 경우 경고 메시지를 출력합니다.
                    cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
                }
            }
        }
        if (managerChoice == 2) {
            while (true) {
                cout << "\n대여 관리 프로그램" << endl;
                cout << "1. 책 대여하기 " << endl; // 책 정보를 입력받아 책 목록에 추가
                cout << "2. 책 반납하기 " << endl; // 현재 책 목록에 있는 모든 책 출력
                cout << "3. 재고 확인하기 " << endl; // 제목으로 책 검색
                cout << "4. 이전으로" << endl; // 프로그램 종료
                cout << "선택: ";

                int choice; // 사용자의 메뉴 선택을 저장
                cin >> choice;

                if (choice == 1) {
                    string title;
                    cout << "대여할 책 제목:";
                    cin >> title;
                    borrowmanager.borrowBook(title);
                }
                else if (choice == 2) {
                    string title;
                    cout << "반납할 책 제목:";
                    cin >> title;
                    borrowmanager.returnBook(title);

                }
                else if (choice == 3) {
                    borrowmanager.displayStock();

                }
                else if (choice == 4) {
                    // 5번 선택: 종료
                    // 프로그램을 종료하고 사용자에게 메시지를 출력합니다.
                    cout << "이전으로 돌아갑니다." << endl;
                    break; // while 루프 종료
                }
                else {
                    // 잘못된 입력 처리
                    // 메뉴에 없는 번호를 입력했을 경우 경고 메시지를 출력합니다.
                    cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
                }
            }
        }
        if (managerChoice == 3) {
            // 5번 선택: 종료
            // 프로그램을 종료하고 사용자에게 메시지를 출력합니다.
            cout << "프로그램을 종료합니다." << endl;
            break; // while 루프 종료

        }
        else {
            // 잘못된 입력 처리
            // 메뉴에 없는 번호를 입력했을 경우 경고 메시지를 출력합니다.
            cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
        }


        
   
    }
    // 프로그램 정상 종료
    return 0; 
}
