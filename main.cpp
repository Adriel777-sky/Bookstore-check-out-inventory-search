/*Adriel A. Okolo
HW5 4/25/2021
C++ program that */


#include <iostream>
using namespace std;


class Book{
private:
int ID;
string title;
float price;
string author;

public:
Book(){}
Book(int id,string t, float p,string a){
  ID=id;
  title=t;
  price=p;
  author=a;
}
void setOD(int id){
  ID=id;
}
void setTitle(string t){
  title=t;
}
void setPrice(float p){
  price=p;
}
void setAuthor(string a){
  author=a;
}
int getID(){
  return ID;
}
string GetTitle(){
  return title;
}
float getPrice(){
  return price;
}
 string getAuthor(){
   return author;
 }
void displayBookInfo(){
cout<<"ID: "<<ID<<endl;
cout<<"Title: "<<title<<endl;
cout<<"Price: "<< price<<endl;
cout<<"Author: "<< author<<endl;
}
};
struct bookNode{
  Book book;
  struct bookNode*next;
};
class BookLinkedList{
  private:
  struct bookNode*head;

  public:
BookLinkedList(){
head = NULL;
}
void addBook(Book book){
struct bookNode * newNode = new struct bookNode;
newNode->book = book;
newNode->next = NULL;
  
struct bookNode* current = head;
  
if(head == NULL){
head = newNode;
return;
}
while(current->next!=NULL)current = current -> next;
current->next = newNode;
}
  
void displayBook(int id){
struct bookNode* current = head;
if(head == NULL){
cout<<"No Book purchased\n";
return;
}
while(current!=NULL){
if(current->book.getID() == id){
current->book.displayBookInfo();
return;
}
current = current->next;
}
  
cout<<"Book not purchased\n";
}
void displayAllBooks(){
struct bookNode* current = head;
if(head == NULL){
cout<<"No Book purchased\n";
return;
}
while(current!=NULL){
current->book.displayBookInfo();
current = current->next;
}
}
};

void menu(){
cout<<"1.Purchase a Book\n2.Display a Book\n3.Display All Book\n4.Quit\n";
}

int main(){
int choice;
int ID;
string title;
float price;
string author;
BookLinkedList list;
  
do{
menu();
cout<<"Enter choice : ";
cin>>choice;
  
switch(choice){
case 1:{
cout<<"Enter ID : ";
cin>>ID;
cin.ignore();
cout<<"Enter Title : ";
getline(cin,title);
cout<<"Enter price : ";
cin>>price;
cin.ignore();
  
cout<<"Enter author name : ";
getline(cin,author);
  
Book book(ID , title , price , author);
list.addBook(book);
break;
}
case 2:{
cout<<"Enter ID : ";
cin>>ID;
list.displayBook(ID);
break;
}
case 3:{
list.displayAllBooks();
break;
break;
}
case 4:{
cout<<"Good bye!\n";
break;
}
default:{
cout<<"Invalid choice\n";
break;
}
}
  
}while(choice!=4);
}
