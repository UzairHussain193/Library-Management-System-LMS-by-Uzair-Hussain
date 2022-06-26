/* 
	//////===================     LIBRARY MANAGEMENT SYSTEM ( L.M.S ).  ======================//////
	//////=======================     Programming Fundamentals.    ===========================////// 
	//////=====================     First Semester Project 2k22.     =======================////// 
		
	**************************    Name : Uzair Hussain Shaikh.  **************************    
	**************************    Roll no : 21 SW 085.          **************************    
	**************************    Teacher : Sir Sajjad.         **************************    
	**************************    Year : 1st Sem, 1st year.     **************************    
*/
////  HEADER Files /////
#include<iostream>							// for cout and cin
#include<fstream>							// for filing
#include<string.h>							// for string
#include<conio.h>							//for getch()
#include <windows.h>						// FOR CHANGING COLOUR

using namespace std;

//////   CLASS LIBRARY /////    OOPS  CONCEPTS ///// 
class library {
	
	private:
		
		
	public:
		string bookname,bookauthor,bookpublisher,booksubj;
		int bookyear;
		static string bookid;
		library() {
			intro();
		}
		void starline();
		void intro();
		void menu();
		void student();
		void pass();
		void search();
		void librarian();
		void add();
};
string library::bookid;

void library::starline(){
	int i=1;
	cout<<"\t\t";
	while(i<=60) {
		cout<<"-";
		i++;
	}
	cout<<endl;
}
void library::intro(){
	system("cls");
	starline();
	cout<<"\n\t\t\t====== LIBRARY MANAGEMENT SYSTEM ( L.M.S ). ======\n"<<endl;
	starline();
	cout<<"\n\t\t\t======  Programming Fundamentals.  ======\n"<<endl;
	cout<<"\n\t\t\t======  First Semester Project 2k22.  ======\n"<<endl;
	starline();
	cout<<"\n\t\t\t++++++  Name : Uzair Hussain Shaikh.  \n"<<endl;
	cout<<"\n\t\t\t++++++  Roll no : 21 SW 085.  \n"<<endl;
	cout<<"\n\t\t\t++++++  Teacher : Sir Sajjad.  \n"<<endl;
	cout<<"\n\t\t\t++++++  Year : 1st Sem, 1st year.  \n"<<endl;
	starline();
	getch();
	system("cls");
	menu();
}
void library::menu() {
	int i;
	cout<<"\n\t\t\t====== LIBRARY MANAGEMENT SYSTEM ( L.M.S ). ======\n"<<endl;
	starline();
	cout<<"\n\t\t-->Please Choose Any Option To login \n";
	cout<<"\n\t\t1.Student\n\n"
		<<"\t\t2.Librarian\n\n"
		<<"\t\t3.Close Application\n";
	starline();
	cout<<"\n\t\tEnter your choice : ";
	cin>>i;
	if(i==1 ) {
		system("cls");
		student();
	} 
	else if(i==2){
		pass();
	}
	else if(i==3){
		system("cls");
		cout<<"\n\n\t\t\t\t\tTHANK YOU...\n"<<endl;
		starline();
		starline();
		starline();
		exit(0);
	}
	else {
		cout<<"\n\t\tPlease enter correct option :(";
		getch();
		system("cls");
		menu();
	}
}
void library::pass() {
	int i=0;
	char pass;
	string completepass,ch1="admin123";
	cout<<"\n\t\tEnter Password : ";
	for(int i=1;i<=8;i++){	
		pass=getch();
		completepass+=pass;
		cout<<"*";	
	}
	ifstream inf("password.txt");
	inf>>ch1;
	inf.close();
	for(int i=0;i<=3;i++);
	if(completepass=="admin123") {
		system("cls");
		librarian();
	} 
	else {
		cout<<"\n\n\t\tWrong Password.\n\n\t\ttry again.....\n";
		getch();
		system("cls");
		menu();
	}
}
void library::student() {
	int i;
	cout<<"\n\t\t\t====== LIBRARY MANAGEMENT SYSTEM ( L.M.S ). ======\n"<<endl;
	cout<<"\n\t\t\t====== WELCOME STUDENT ======\n\n";
	cout<<"\n\t\t-->Please Choose One Option:\n";
	starline();
	cout<<"\n\t\t1.View BookList\n\n"
		<<"\t\t2.Book Details\n\n"
		<<"\t\t3.Go to main menu\n\n"
		<<"\t\t4.Close Application\n";
		
	cout<<"\n\t\tEnter your choice : ";
	cin>>i;
	starline();
	string str;
	if(i==1){
		ifstream book("Booklist.txt",ios::app);
		if(book.is_open()){
		system("cls");
		cout<<"\n\n\t\tBook List Found\n\n"<<endl;
		while(getline(book,str)){
			cout<<endl<<str<<endl;
		}
		cout<<"\n\n\t\t->Press any key to continue.....";
		getch();
		system("cls");
		student();
		}
		else{
			cout<<"\n\n\t\tNo such file found";
			cout<<"\n\n\t\t->Press any key to continue.....";
			getch();
			system("cls");
			student();
		}
	}
	else if(i==2){
		ifstream book2("Bookdetails.txt",ios::app);
		if(book2.is_open()){
		system("cls");
		cout<<"\n\n\t\tBook Details Found\n\n"<<endl;
		while(getline(book2,str)){
			cout<<endl<<str<<endl;
		}
		book2.close();
		cout<<"\n\n\t\t->Press any key to continue.....";
		getch();
		system("cls");
		student();
		}
		else{
			cout<<"\n\n\t\tNo such file found";
			cout<<"\n\n\t\t->Press any key to continue.....";
			getch();
			system("cls");
			student();
		}
	}
	else if(i==3) {
		system("cls");
		menu();
	} 
	else if(i==4){
		system("cls");
		cout<<"\n\n\t\t\t\t\tTHANK YOU !...\n"<<endl;
		starline();
		starline();
		starline();
		exit(0);
	}
	else {
		cout<<"\n\t\tPlease enter correct option :(";
		getch();
		system("cls");
		student();
	}
}
void library::librarian() {
	int i;
	cout<<"\n\t\t====== LIBRARY MANAGEMENT SYSTEM ( L.M.S ). ======\n"<<endl;
	cout<<"\n\t\t\t====== WELCOME LIBRARIAN ======\n";
	starline();
	cout<<"\n\t\t\t-->Please Choose One Option:\n";
	
	cout<<"\n\t\t1.View BookList\n\n"
		<<"\t\t2.Book Details\n\n"
		<<"\t\t3.Add Book\n\n"
		<<"\t\t4.Search Book\n\n"
		<<"\t\t5.Go to main menu\n\n"
		<<"\t\t6.Close Application\n";
		
	starline();
	cout<<"\n\t\tEnter your choice : ";
	cin>>i;
	string str;
		if(i==1){
			ifstream book("Booklist.txt",ios::app);
			if(!book){
			cout<<"\n\n\t\tNo such file found";
				cout<<"\n\n\t\t->Press any key to continue.....";
				getch();
				system("cls");
				librarian();
			}
			else{
				system("cls");
			while(getline(book,str)){
				cout<<endl<<str<<endl;
			}
			cout<<"\n\n\t\t->Press any key to continue.....";
			getch();
			system("cls");
			librarian();
				
			}
		}
		else if(i==2){
			system("cls");
			ifstream bookdet("Bookdetails.txt",ios::app);
			if(bookdet.is_open()){
				while(getline(bookdet,str)){
				cout<<endl<<str<<endl;
				}
				cout<<"\n\t\t->Press any key to continue.....  ";
				getch();
				system("cls");
				librarian();
			}
			else{
				cout<<"\n\n\t\tNo such file found";
				cout<<"\n\n\t\t->Press any key to continue.....";
				getch();
				system("cls");
				librarian();
			}
		}
		else if(i==3){
			system("cls");
			add();
		}
		else if(i==4){
			system("cls");
			search();
		}
		else if(i==5){
			system("cls");
			menu();
		}
		else if(i==6){
			system("cls");
			cout<<"\n\n\t\t\t\t\tTHANK YOU !...\n"<<endl;
			starline();
			starline();
			starline();
			exit(0);
		}
		else{
			cout<<"\n\t\tPlease enter correct option :(";
			getch();
			system("cls");
			librarian();
		}
}
void library::add(){
	char ch;
	system("cls");	
	cout<<"\n\t\t\t====== LIBRARY MANAGEMENT SYSTEM ( L.M.S ). ======\n"<<endl;
	starline();
	do{
		cout<<"\n\t\tEnter I.D of book : ";
		cin>>bookid;
		cout<<"\n\t\tEnter name of book : ";
		cin>>bookname;
		cout<<"\n\t\tEnter name of author of book : ";
		cin>>bookauthor;
		cout<<"\n\t\tEnter name of subject of book : ";
		cin>>booksubj;
		cout<<"\n\t\tEnter name of publisher of book : ";
		cin>>bookpublisher;
		cout<<"\n\t\tEnter year of publish of book : ";
		cin>>bookyear;
	
		string P;
		string pa=".txt";
		P=library::bookid+pa;
				
		ofstream outf(P.c_str());
		{
			outf<<"\t\t____________________LIBRARY________________________"<<endl;
			outf<<"\t\t__________________BOOK DETAILS_____________________"<<endl;
			outf<<"\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
			outf<<"\t\t\tBook I.D : "<<bookid<<endl;
			outf<<"\t\t\tBook Name : "<<bookname<<endl;
			outf<<"\t\t\tBook Author : "<<bookauthor<<endl;
			outf<<"\t\t\tBook Subject : "<<booksubj<<endl;
			outf<<"\t\t\tBook Publisher : "<<bookpublisher<<endl;
			outf<<"\t\t\tBook Year : "<<bookyear<<endl;
			outf<<"\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;		
	}
		outf.close();
		
		fstream bookadd;
		bookadd.open("Bookdetails.txt",ios::app | ios::out);
		bookadd<<"\n\n\t\t******* BOOK DETAILS ********"<<endl<<endl;	
		bookadd<<"\t\tBook I.D : "<<bookid<<endl;
		bookadd<<"\t\tBook Name : "<<bookname<<endl;
		bookadd<<"\t\tBook Author : "<<bookauthor<<endl;
		bookadd<<"\t\tBook Subject : "<<booksubj<<endl;
		bookadd<<"\t\tBook Publisher : "<<bookpublisher<<endl;
		bookadd<<"\t\tBook Year : "<<bookyear<<endl;
		bookadd.close();
		fstream bookad;
		bookad.open("Booklist.txt",ios::app | ios::out);
		outf<<"\t\t__________________BOOK LIST_____________________"<<endl;
		outf<<"\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		bookad<<bookid<<". "<<bookname<<endl;
		bookad.close();
		cout<<"\n\n\t\tYour book has been added....\n";
		cout<<"\n\n\t\t->Do you want to add more books ( y/n ).....";
		ch=getch();	
	}while(ch=='Y' || ch=='y');
	system("cls");
	librarian();
}
void library::search(){
	int i;
	int id;
	int found;
	char arr[100];
	string PATH;
	string PA=".txt";
	
	string str;
	system("cls");
	cout<<"\n\t\t\t====== LIBRARY MANAGEMENT SYSTEM ( L.M.S ). ======\n"<<endl;
	starline();
	cout<<"\n\n\n\t\t->Please Choose one option :-\n";
	starline();
	cout<<"\t\t  1.Search By Book's ID\n"
		<<"\t\t  2.Go To Main Menu \n"
		<<"\t\t  3.Exit. \n";
	cout<<"\n\t\t  Enter Your Choice : ";
	cin>>i;
	
	if(i==1){
		cout<<"\n\n\t\tEnter Book Id : ";
		cin>>str;
		PATH=str+PA;
		ifstream inf(PATH.c_str());
	   	        {
	   	        	if(!inf){
	   	        		system("cls");
	   	        		cout<<"\n\n\t\tfile error !"<<endl;
	   	        		}
	   	        	else{
	   	        		system("cls");
					   while(!inf.eof()){
	   	        		inf.getline(arr,100);
	   	        		cout<<arr<<endl;
	   	        		
					   }
	   	        	
	   	        }
	   	        inf.close();
	   	        }
	   	cout<<"\n\n\n\t\tPlease enter any key to continue :(";
		getch();
		system("cls");
		librarian();
	}
	else if(i==2) {
		system("cls");
		menu();
	} 
	else if(i==3){
		system("cls");
		cout<<"\n\n\t\t\t\t\tTHANK YOU !...\n"<<endl;
		starline();
		starline();
		starline();
		exit(0);
	}
	else {
		cout<<"\n\t\tPlease enter correct option :(";
		getch();
		system("cls");
		librarian();
	}
}
int main() {
	system("color 2b");				/// used for color changes 
									//// 4 for background and e for text color
	library obj;
	return 0;
}
