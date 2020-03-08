//=============== Project on Bank Management by Gaurav and Nishtha======================
#include<fstream.h>
#include<process.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<conio.h>
#include<dos.h>
//========== THIS CLASS CONTAINS FUNCTIONS RELATED TO DRAW BOX =====================
class shape
{ public :
void line_hor(int, int, int, char);
void line_ver(int, int, int, char);
void box(int,int,int,int,char);
};
//================= THIS CLASS CONTROL ALL THE FUNCTIONS IN THE MENU=================
class control
{ public :
void main_menu(void);
void help(void);
private:
void edit_menu(void);
};
//=======THIS CLASS CONTAINS FUNCTIONS RELATED TO INITIAL DEPOSIT=====================
class initial
{ public :
void add_to_file(int,char t_name[30],char t_address[60],float);
void display_list(void);
void delete_account(int);
void update_balance(int,float);
void modify(void);
int last_accno(void);
int found_account(int);
char *return_name(int);
char *return_address(int);
float give_balance(int);
int recordno(int);
void display(int);
private:
void modify_account(int,char t_name[30],char t_address[60]);
void box_for_list(void);
int accno;
char name[30],address[60];
float balance;
};
//=============THIS CLASS CONTAINS FUNCTIONS RELATED TO TRANSACTIONS================
class account
{ public :
void new_account(void);
void close_account(void);
void display_account(void);
void transaction(void);
void clear(int,int);
private :
void add_to_file(int,int,int,int,char,char t_type[10],float,float,float);
void delete_account(int);
int no_of_days(int,int,int,int,int,int);
float calculate_interest(int,float);
void display(int);
void box_for_display(int);
int accno;
char type[10]; //Cheque or Cash
int dd,mm,yy; //Date
char tran ; // Deposit or withdrawl
float interest,amount,balance;
};
//=================FUNCTION TO DRAW HORIZONTAL LINE===============================
void shape::line_hor(int column1,int column2,int row,char c)
{ for(column1; column1<=column2;column1++)
{ gotoxy(column1,row);
cout<<c;
}
}
//===================FUNCTION TO DRAW VERTICAL LINE================================
void shape::line_ver(int row1,int row2,int column,char c)
{ for(row1;row1<=row2;row1++)
{ gotoxy(column,row1);
cout<<c;
}
}
//============================FUNCTION TO DRAW BOX LINE===========================
void shape::box(int column1,int row1,int column2,int row2,char c)
{ char ch=218;
textcolor(WHITE);
textbackground(BLACK);
char c1,c2,c3,c4;
char l1=196,l2=179;
if(c==ch)
{ c1=218;
c2=191;
c3=192;
c4=217;
l1=196;
l2=179;
}
else
{ c1=c;
c2=c;
c3=c;
c3=c;
c4=c;
l1=c;
l2=c;
}
gotoxy(column1,row1);
cout<<c1;
gotoxy(column2,row1);
cout<<c2;
gotoxy(column1,row2);
cout<<c3;
gotoxy(column2,row2);
cout<<c4;
column1++;
column2--;
line_hor(column1,column2,row1,l1);
line_hor(column1,column2,row2,l1);
column1--;
column2++;
row1++;
row2--;
line_ver(row1,row2,column1,l2);
line_ver(row1,row2,column2,l2);
}
//============================FUNCTION FOR BY LINE===========================
void by_line()
{ gotoxy(61,25);
textcolor(GREEN);
cprintf("By:Gaurav & Nishtha");
}
//===============FUNCTION TO DISPLAY MAIN MENU AND CALL OTHER FUNCTIONS===================
void control::main_menu()
{ char ch;
while (1)
{ clrscr();
shape s;
textcolor(WHITE);
textbackground(BLACK);
s.box(10,5,71,21,219);
s.box(9,4,72,22,218);
textcolor(RED);
textbackground(BLACK);
gotoxy(35,7);
cprintf(" ABCD BANK ");
gotoxy(35,8);
cprintf("*---------*");
gotoxy(35,9);
textcolor(GREEN+BLINK);
cprintf(" MAIN MENU ");
textbackground(BLACK);
textcolor(LIGHTBLUE);
gotoxy(30,11);
cprintf("1: SEE ACCOUNT ");
gotoxy(30,12);
cprintf("2: LIST OF ACCOUNTS ");
gotoxy(30,13);
cprintf("3: TRANSACTIONS ");
gotoxy(30,14);
cprintf("4: OPEN NEW ACCOUNT ");
gotoxy(30,15);
cprintf("5: EDIT ACCOUNTS ");
gotoxy(30,16);
cprintf("6: HELP ");
gotoxy(30,17);
cprintf("0: QUIT ");
by_line();
gotoxy(30,19);
cout<<"|| ENTER YOUR CHOICE:";
ch=getche();
textcolor(WHITE);
if(ch==27)
break;
else if(ch=='1')
{ account a;
a.display_account();
}
else if(ch=='2')
{ initial ini;
ini.display_list();
}
else if(ch=='3')
{ account a ;
a.transaction();
}
else if(ch=='4')
{ account a;
a.new_account();
}
else if(ch=='5')
edit_menu();
else if(ch=='6')
help();
else if(ch=='0')
break;
}
for(int i=25;i>=1;i--)
{ delay(20);
gotoxy(1,i); clreol();
}
textcolor(WHITE);
}
//=======FUNCTION TO DISPLAY EDIT MENU AND CALL OTHER FUNCTION=====================
void control::edit_menu(void)
{ char ch;
while (1)
{ clrscr();
shape s;
s.box(10,5,71,21,219);
s.box(9,4,72,22,218);
textbackground(BLACK);
textcolor(BLUE);
gotoxy(34,10);
cprintf(" EDIT MENU ");
gotoxy(34,11);
cprintf("^^^^^^^^^^^");
by_line();
textcolor(LIGHTBLUE);
textbackground(BLACK);
gotoxy(31,12);
cprintf("1: MODIFY ACCOUNT");
gotoxy(31,13);
cprintf("2: CLOSE ACCOUNT ");
gotoxy(31,14);
cprintf("0: QUIT ");
gotoxy(31,16);
cout<<"|| ENTER YOUR CHOICE: ";
ch=getche();
if(ch==27)
break;
else if(ch=='1')
{ initial ini;
ini.modify();
break;
}
else if(ch=='2')
{ account a;
a.close_account();
break;
}
else if(ch=='0')
break;
}
textcolor(WHITE);
textbackground(BLACK);
}
//==================== FUNCTION TO DISPLAY HELP ABOUT PROJECT======================
void control::help()
{ clrscr();
shape s;
s.box(2,1,79,25,218);
textcolor(RED); textbackground(BLACK);
gotoxy(30,3);
cprintf(" WELCOME TO THE BANK ");
gotoxy(30,4);
cprintf("^^^^^^^^^^^^^^^^^^^^^");
textcolor(LIGHTBLUE); textbackground(BLACK);
gotoxy(10,6);
cprintf("IN THIS PROGRAM YOU CAN KEEP RECORD OF DAILY BANKING TRANSACTIONS");
delay(10);
gotoxy(10,8);
cprintf(" THIS PROGRAM IS CAPABLE OF HOLDING ANY NO. OF ACCOUNTS ");
delay(10);
gotoxy(10,10);
cprintf("=> IN FIRST OPTION YOU CAN SEE ACCOUNT OF A PARTICULAR ");
delay(10);
gotoxy(10,11);
cprintf(" PERSON BY GIVING SIMPLY ACCOUNT NO. OF THAT PERSON");
delay(10);
gotoxy(10,13);
cprintf("=> IN SECOND OPTION YOUN CAN SEE THE LIST OF ALL ACCOUNTS. ");
delay(10);
gotoxy(10,15);
cprintf("=> THROUGH THIRD OPTION YOU CAN DO BANKING TRANSACTIONS");
delay(10);
gotoxy(10,17);
cprintf("=> IN FOURTH OPTION YOU CAN OPEN NEW ACCOUNT. ");
delay(10);
gotoxy(10,18);
cprintf(" NOTE: OPENING AMOUNT SHOULD BE GREATER THAN Rs.500/-. ");
delay(10);
gotoxy(10,20);
cprintf("=> IN THE FIFTH OPTION YOU CAN MODIFY OR DELETE ANY ACCOUNT. ");
delay(10);
gotoxy(10,22);
cprintf("=> AND LAST OPTION IS QUIT(EXIT).");
delay(10);
textcolor(GREEN+BLINK); textbackground(BLACK);
gotoxy(26,24);
cprintf("|| PRESS ANY KEY TO CONTINUE ");
by_line();
getch();
for(int i=26;i>=1;i--)
{ delay(20);
gotoxy(1,i);
clreol();
}
textcolor(WHITE);
}
//==========THIS FUNCTION RETURN LAST ACCOUNT NO. IN THE FILE INITIAL.DAT=============
int initial::last_accno()
{ fstream file;
file.open("INITIAL.DAT",ios::in|ios::binary);
file.seekg(0,ios::beg);
int count=0;
while(file.read((char*)this,sizeof(initial)))
count=accno;
file.close();
return count;
}
//======THIS FUNCTION RETURN RECORD NO. OF THE A/C NO.FROM INITIAL.DAT===============
int initial::recordno(int t_accno)
{ fstream file;
file.open("INITIAL.DAT",ios::in|ios::binary);
file.seekg(0,ios::beg);
int count=0;
while (file.read((char*)this, sizeof(initial)))
{ count++;
if(t_accno==accno)
break;
}
file.close();
return count;
}
//===========THIS FUNTION DISPLAY THE DETAILS FOR GIVEN A/C NO.FROM THE FILE==========
void initial::display(int t_accno)
{ shape s;
textcolor(BLUE);
s.box(8,7,73,11,219);
fstream file;
file.open("INITIAL.DAT",ios::in|ios::binary);
file.seekg(0,ios::beg);
while(file.read((char*)this,sizeof(initial)))
{ if(t_accno==accno)
{by_line();
gotoxy(6,6);
textcolor(LIGHTBLUE);
cprintf("ACCOUNT NO.:");
cout<<accno;
gotoxy(10,8);
cprintf("NAME :");
cout<<name;
gotoxy(10,9);
cprintf("ADDRERSS :");
cout<<address;
gotoxy(10,10);
cprintf("BALANCE :");
cout<<balance;
break;}
}
file.close();
}
//====THIS FUNCTION RETURNS NAME FOR THE GIVEN ACC NO. IN THE FILE INITIAL.DAT==========
char* initial::return_name(int t_accno)
{ fstream file;
file.open("INITIAL.DAT",ios::in|ios::binary);
file.seekg(0,ios::beg);
char t_name[30];
while(file.read((char*) this,sizeof(initial)))
{ if(accno==t_accno)
{ strcpy(t_name,name);
break;}
}
file.close();
return t_name;
}
//===THIS FUNCTION RETURNS ADDRESS FOR THE GIVEN ACC NO. IN THE FILE INITIAL.DAT=====
char* initial::return_address(int t_accno)
{ fstream file;
file.open("INITIAL.DAT",ios::in|ios::binary);
file.seekg(0,ios::beg);
char t_address[60];
while(file.read((char*)this,sizeof(initial)))
{ if(accno==t_accno)
  { strcpy(t_address,address);
    break;
  }
}
file.close();
return t_address;
}
//===THIS FUNCTION RETURN BALANCE FOR THE GIVEN ACC NO. IN THE FILE INITIAL.DAT======
float initial::give_balance(int t_accno)
{ fstream file;
file.open("INITIAL.DAT",ios::in|ios::binary);
file.seekg(0,ios::beg);
float t_balance;
while(file.read((char *)this, sizeof(initial)))
{ if(accno==t_accno)
{ t_balance=balance;
break;
}
}
file.close();
return t_balance;
}
//====THIS FUNCTION RETURN 1 IF THE GIVEN ACCOUNT NO. FOUND IN THE FILE INITIAL.DAT=====
int initial::found_account(int t_accno)
{ fstream file;
file.open("INITIAL.DAT",ios::in | ios::binary);
file.seekg(0,ios::beg);
int found=0;
while(file.read((char*)this,sizeof(initial)))
{ if (accno==t_accno)
{ found=1;
break;
}
}
file.close();
return found;
}
//=========== THIS FUNCTION DRAWS THE BOX FOR THE LIST OF ACCOUNTS ==================
void initial::box_for_list()
{ shape s;
s.box(2,1,79,25,218);
s.line_hor(3,78,3,196);
s.line_hor(3,78,5,196);
s.line_hor(3,78,23,196);
textbackground(BLACK);
gotoxy(3,4);
for(int i=1;i<=76;i++)
cprintf(" ");
by_line();
textcolor(LIGHTBLUE);
textbackground(BLACK);
gotoxy(4,4);
cprintf(" ACCOUNT NO. NAME OF PERSON BALANCE");
textcolor(LIGHTBLUE);
textbackground(BLACK);
int d1,m1,y1;
struct date d;
getdate(&d);
d1=d.da_day;
m1=d.da_mon;
y1=d.da_year;
gotoxy(4,2);
cout<<" DATE: "<<d1<<"/"<<m1<<"/"<<y1;
textcolor(WHITE);
}
//========THIS FUNCTION DISPLAYS THE LIST OF ACCOUNTS IN FILE INITIAL.DAT ===============
void initial::display_list(void)
{
clrscr();
box_for_list();
int row=6,flag=0;
fstream file;
file.open("INITIAL.DAT",ios::in|ios::binary);
while (file.read((char*)this,sizeof(initial)))
{ delay(10);
gotoxy(7,row);
cout<<accno;
gotoxy(25,row);
cout<<name;
gotoxy(57,row);
cout<<balance;
row++;
if(row==23)
{ flag=1;
row=6;
gotoxy(4,24);
textcolor(GREEN+BLINK);
cprintf("|| PRESS ANY KEY TO CONTINUE...");
getch();
clrscr();
box_for_list();
}
}
file.close();
if(!flag);
{ gotoxy(4,24);
textcolor(GREEN+BLINK);
cprintf("|| PRESS ANY KEY TO CONTINUE...");
getch();
}
textcolor(WHITE);
}
//========THIS FUNCTION ADDS THE GIVEN DATA INTO THE FILE INITIAL.DAT==================
void initial::add_to_file(int t_accno,char t_name[30],char t_address[60], float t_balance)
{ accno=t_accno;
strcpy(name,t_name);
strcpy(address,t_address);
balance=t_balance;
fstream file;
file.open("INITIAL.DAT",ios::out|ios::app|ios::binary);
file.write((char *) this, sizeof(initial));
file.close();
}
//==THIS FUNCTION DELETES RECORD FOR THE GIVEN ACC NO. FROM THE FILE INITIAL.DAT=======
void initial::delete_account(int t_accno)
{ fstream file;
file.open("INITIAL.DAT",ios::in|ios::binary);
fstream temp;
temp.open("temp.dat",ios::out|ios::binary);
file.seekg(0,ios::beg);
while(!file.eof())
{ file.read((char*)this,sizeof(initial));
if(file.eof())
break;
if(accno!=t_accno)
temp.write((char*)this,sizeof(initial));
}
file.close();
temp.close();
file.open("INITIAL.DAT",ios::out|ios::binary);
temp.open("temp.dat", ios::in|ios::binary);
temp.seekg(0,ios::beg);
while(!temp.eof() )
{ temp.read((char*)this,sizeof(initial));
file.write((char*)this,sizeof(initial));
}
file.close();
temp.close();
}
//====THIS FUNCTION UPDATE BALANCE FOR THE GIVEN ACCOUNT NO. IN THE FILE INITIAL.DAT===
void initial :: update_balance(int t_accno, float t_balance)
{ int recno;
recno=recordno(t_accno);
fstream file;
file.open("INITIAL.DAT",ios::out | ios::ate | ios::binary);
balance=t_balance;
int location;
location=(recno-1) * sizeof(initial);
file.seekp(location);
file.write((char *)this, sizeof(initial));
file.close();
}
//=====THIS MODIFYS THE RECORD FOR THE GIVEN DATA IN THE FILE INITIAL.DAT===============
void initial::modify_account(int t_accno,char t_name[30],char t_address[60])
{ int recno;
recno=recordno(t_accno);
fstream file;
file.open("INITIAL.DAT", ios::out | ios::ate |ios::binary);
strcpy(name, t_name);
strcpy(address,t_address);
int location;
location=((recno-1) * sizeof(initial));
file.seekp(location,ios::beg);
file.write((char *) this, sizeof(initial));
file.close();
}
//======THIS FUNCTION GIVE THE DATA TO MODIFY THE RECORD IN THE FILE INITIAL.DAT========
void initial::modify(void)
{ clrscr();
char t_acc[10];
int t, t_accno;
by_line();
textcolor(WHITE);
gotoxy(71,1);
cout<<"<0>=EXIT";
gotoxy(5,5);cout<<"||";
gotoxy(5,6);
cout<<"|| ENTER THE ACCOUNT NO."<<endl;
gotoxy(5,7);
cout<<"||";
gotoxy(30,6);
cin>>t;
t_accno=t;
if(t_accno==0)
return;
clrscr();
if(!found_account(t_accno))
{ gotoxy(5,5);
textcolor(RED);
cprintf("\7|| ACCOUNT NOT FOUND");
getch();
return;
}
shape s;
s.box(2,2,79,24,218);
s.line_hor(3,78,5,196);
s.line_hor(3,78,22,196);
gotoxy(71,1);
cout<<"<0>=EXIT";
textbackground(BLACK);
gotoxy(3,3);
for(int i=1;i<=76;i++) cprintf(" ");
textcolor(RED+BLINK); textbackground(BLACK);
gotoxy(30,3);
cprintf(" MODIFY ACCOUNT SCREEN ");
gotoxy(30,4);
cprintf("~~~~~~~~~~~~~~~~~~~~~~~");
by_line();
textcolor(LIGHTBLUE); textbackground(BLACK);
int d1,m1,y1;
struct date d;
getdate(&d);
d1=d.da_day;
m1=d.da_mon;
y1=d.da_year;
gotoxy(62,6);
cout<<" DATE:"<<d1<<"/"<<m1<<"/"<<y1;
char ch;
display(t_accno);
account a;
do
{a.clear(5,13);
gotoxy(5,13);
textcolor(YELLOW);
cprintf("|| MODIFY THIS ACCOUNT(Y/N):");
ch=getche();
if(ch=='0')
return;
ch=toupper(ch);
}while(ch!='N' && ch!='Y');
if(ch=='N')
return;
int modified=0,valid;
char t_name[30], t_address[60];
gotoxy(5,15);
cprintf("|| NAME:");
gotoxy(5,16);
cprintf("|| ADDRESS:");
by_line();
do
{a.clear(15,15);
a.clear(5,23);
gotoxy(5,23);
cprintf("|| ENTER NAME OR PRESS <ENTER> FOR NO CHANGE");
valid=1;
gotoxy(15,15);
gets(t_name);
strupr(t_name);
if(t_name[0]=='0')
return;
if(strlen(t_name)>25)
{ valid=0;
gotoxy(5,23);
clreol();
gotoxy(5,23);
cprintf("\7|| NAME SHOULD NOT GREATER THAN 25");
getch();
textcolor(WHITE);
}
}while(!valid);
if(strlen(t_name)>0)
modified=1;
do
{ a.clear(15,16);
a.clear(5,23);
gotoxy(5,23);
cprintf("|| ENTER ADDRESS OR PRESS <ENTER> FOR NO CHANGE");
valid=1;
gotoxy(15,16);
gets(t_address);
strupr(t_address);
if(t_address[0]=='0')
return;
if(strlen(t_address)>55)
{ valid=0;
gotoxy(5,23);
cprintf("\7|| SHOULD NOT BLANK OR GREATER THAN 55");
getch();
}
}while(!valid);
if(strlen(t_address)>0)
modified=1;
if(!modified)
return;
a.clear(5,23);
do
{ a.clear(5,18);
gotoxy(5,18);
textcolor(RED);
cprintf("|| DO YOU WANT TO SAVE CHANGES (Y/N):");
ch=getche();
if(ch=='0')
return;
ch=toupper(ch);
}while(ch!='N' && ch!='Y');
if(ch=='N')
return;
modify_account(t_accno,t_name,t_address);
gotoxy(5,21);
textcolor(GREEN+BLINK);
cprintf("\7|| RECORD MODIFIED");
gotoxy(5,23);
cprintf("|| PRESS ANY KEY TO CONTINUE...");
getch();
textcolor(WHITE);
}
//============== THIS FUNCTION CLEAR THE GIVEN ROW AND COLUMNS====================
void account::clear(int col, int row)
{ for(int i=col;i<=78;i++)
{ gotoxy(i,row);
cout<<" ";
}
}
//==========THIS FUNCTION ADDS THE GIVEN DATA INTO THE FILE BANKING.DAT=============
void account::add_to_file(int t_accno,int d1,int m1, int y1,
char t_tran,char t_type[10],float t_interest,
float t_amount, float t_balance)
{ fstream file;
file.open("BANKING.DAT",ios::app |ios::binary);
accno=t_accno;
dd=d1;
mm=m1;
yy=y1;
tran=t_tran;
strcpy(type,t_type);
interest=t_interest;
amount=t_amount;
balance=t_balance;
file.write((char*)this,sizeof(account));
file.close();
}
//====THIS FUNCTION DELETES THE RECORD FOR GIVEN ACC NO. FROM FILE BANKING.DAT=======
void account::delete_account(int t_accno)
{ fstream file;
file.open("BANKING.DAT", ios::in |ios::binary);
fstream temp;
temp.open("temp.dat",ios::out | ios::binary);
file.seekg(0,ios::beg);
while(!file.eof() )
{ file.read((char *) this,sizeof(account));
if(file.eof())
break;
if(accno!= t_accno)
temp.write((char *) this,sizeof(account));
}
file.close();
temp.close();
file.open("BANKING.DAT",ios::out | ios::binary);
temp.open("temp.dat",ios::in | ios::binary);
temp.seekg(0,ios::beg);
while(!temp.eof())
{ temp.read((char *)this,sizeof(account));
if(temp.eof())
break;
file.write((char *) this, sizeof(account));
}
file.close();
temp.close();
}
//================THIS FUNCTION OPENS NEW ACCOUNT================================
void account::new_account()
{ char ch;
int i,valid;
clrscr();
initial ini;
shape s;
s.box(2,2,79,24,218);
s.line_hor(3,78,4,196);
s.line_hor(3,78,22,196);
gotoxy(71,1);
cout<<"<0>=EXIT";
textbackground(BLACK);
gotoxy(3,3);
for(i=1;i<=76;i++)
cprintf(" ");
textcolor(RED+BLINK); textbackground(BLACK);
gotoxy(31,3);
cprintf(" OPEN NEW ACCOUNT ");
gotoxy(31,4);
cprintf("~~~~~~~~~~~~~~~~~~");
by_line();
textcolor(LIGHTBLUE);
textbackground(BLACK);
int d1,m1,y1;
struct date d;
getdate(&d);
d1=d.da_day;
m1=d.da_mon;
y1=d.da_year;
int t_accno;
t_accno=ini.last_accno();
t_accno++;
char t_name[30],t[10],t_address[60];
float t_bal=0.0, t_balance=0.0;
gotoxy(5,6);
cout<<" DATE:"<<d1<<"/"<<m1<<"/"<<y1;
gotoxy(5,8);
cprintf(" ACCOUNT NO. # :");
cout<<t_accno;
gotoxy(5,10);
cprintf(" NAME :");
gotoxy(8,11);
cprintf("ADDRESS:");
gotoxy(8,12);
cprintf("NAME OF VERIFYING PERSON:");
gotoxy(5,14);
cprintf("INITIAL DEPOSIT:");
do
{ clear(15,10);
clear(5,23);
gotoxy(5,23);
cprintf(" ENTER NAME OF THE PERSON");
valid=1;
gotoxy(15,10);
gets(t_name);
strupr(t_name);
if(t_name[0]=='0')
return;
if(strlen(t_name)==0||strlen(t_name)>25)
{ valid=0;
gotoxy(5,23);
cprintf("\7|| NAME SHOULD NOT BLANK OR GREATER THAN 25");
getch();
}
}while(!valid);
do
{clear(15,11);
clear(5,23);
gotoxy(5,23);
cprintf("|| ENTER ADDRESS OF THE PERSON");
valid=1;
gotoxy(23,11);
gets(t_address);
strupr(t_address);
if(t_address[0]=='0')
return;
if(strlen(t_address)==0 || strlen(t_address)>55)
{ valid =0;
gotoxy(5,23);
cprintf("\7|| SHOULD NOT BLANK OR GREATER THAN 55");
getch();
}
}while(!valid);
do
{char vari[30];
clear(5,23);
gotoxy(5,23);
cprintf("|| ENTER NAME OF THE VERIFYING PERSON");
valid=1;
gotoxy(35,12);
gets(vari);
strupr(vari);
if(vari[0]=='0')
return;
if(strlen(vari)==0 || strlen(vari)>25)
{ valid=0;
gotoxy(5,23);
cprintf("\7|| SHOULD NOT BLANK OR GREATER THAN 25");
getch();
}
}while(!valid);
do
{clear(5,23);
clear(5,23);
gotoxy(5,23);
cout<<"|| ENTER INITIAL AMOUNT TO BE DEPOSIT";
valid=1;
gotoxy(23,14);
gets(t);
t_bal=atof(t);
t_balance=t_bal;
if(t[0]=='0')
return;
if(t_balance<500)
{ valid=0;
gotoxy(5,23);
textcolor(RED);
cprintf("\7|| SHOULD NOT LESS THAN 500 ");
getch();}
}while(!valid);
clear(5,23);
do
{ clear(5,17);
valid=1;
gotoxy(7,21);
cout<<"|| DO YOU WANT TO SAVE THE RECORD (Y/N)";
ch=getche();
if(ch=='0')
return;
ch=toupper(ch);
}while(ch!='N' && ch!='Y');
if(ch=='N')
return;
float t_amount,t_interest;
t_amount=t_balance;
t_interest=0.0;
char t_tran,t_type[10];
t_tran='D';
strcpy(t_type,"INITIAL");
ini.add_to_file(t_accno,t_name,t_address,t_balance);
add_to_file(t_accno,d1,m1,y1,t_tran,t_type,t_interest,t_amount,t_balance);
}
//===THIS FUNCTION DRAWS THE BOX FOR DISPLAYING RECORD FROM FILE BANKING.DAT========
void account::box_for_display(int t_accno)
{textcolor(WHITE);
shape s;
s.box(2,1,79,25,218);
s.line_hor(3,78,4,196);
s.line_hor(3,78,6,196);
s.line_hor(3,78,23,196);
by_line();
gotoxy(3,5);
for(int i=1;i<=76;i++) cprintf(" ");
textcolor(WHITE); textbackground(BLACK);
gotoxy(4,5);
cprintf("DATE PARTICULAR DEPOSIT WITHDRAW INTEREST BALANCE");
int d1,m1,y1;
struct date d;
getdate(&d);
d1=d.da_day;
m1=d.da_mon;
y1=d.da_year;
gotoxy(63,2);
cout<<"DATE: "<<d1 <<"/"<<m1<<"/"<<y1;
gotoxy(4,2);
cout<<"ACCOUNT NO."<<t_accno;
initial ini;
char t_name[30];
strcpy(t_name,ini.return_name(t_accno));
char t_address[60];
strcpy(t_address,ini.return_address(t_accno));
gotoxy(25,2);
cout<<t_name;
gotoxy(25,3);
cout<<t_address;
}
//============THIS FUNCTION DISPLAY RECORD FROM THE FILE BANKING.DAT================
void account::display_account()
{clrscr();
char t_acc[10];
int t,t_accno;
by_line();
textcolor(YELLOW);
gotoxy(71,1);
cprintf("<0>=EXIT");
gotoxy(5,5);
cprintf("||");
gotoxy(5,6);
cprintf("|| ENTER THE ACCOUNT NO.");
gotoxy(5,7);
cprintf("||");
gotoxy(30,6);
cin>>t;
t_accno=t;
if(t_accno==0)
return;
clrscr();
initial ini;
if(!ini.found_account(t_accno))
{ gotoxy(5,5);
textcolor(RED);
cprintf("\7|| ACCOUNT NOT FOUND");
getch();
textcolor(WHITE);
return;
}
box_for_display(t_accno);
textcolor(WHITE);textbackground(BLACK);
int row=7,flag;
fstream file;
file.open("BANKING.DAT",ios::in | ios::binary);
while(file.read((char*)this,sizeof(account)))
{ if(accno==t_accno)
{ flag=0;
delay(10);
gotoxy(4,row);
cout<<dd <<"/"<<mm <<"/" <<yy;
gotoxy(16,row);
cout<<type;
if(tran=='D')
gotoxy(30,row);
else
gotoxy(42,row);
cout<<amount;
gotoxy(56,row);
cout<<interest;
gotoxy(66,row);
cout<<balance;
row++;
if(row==23)
{flag=1;
row=7;
gotoxy(4,24);
textcolor(GREEN);
cprintf("||PRESS ANY KEY TO CONTINUE.... ");
getch();
clrscr();
box_for_display(t_accno);}
}
}
file.close();
if(!flag)
{gotoxy(4,24);
textcolor(GREEN);
cprintf("||PRESS ANY KEY TO CONTINUE.....");
getch();
}
textcolor(WHITE);
}
//================THIS FUNCTION RETURNS THE DIFFERENCE BETWEEN 2 DATES==============
int account::no_of_days(int d1,int m1,int y1,int d2,int m2,int y2)
{static int month[]={31,28,31,30,31,30,31,31,30,31,30,31};
int days=0;
while(d1!=d2 || m1!=m2 || y1!=y2)
{days++;
d1++;
if(d1>month[m1-1])
{d1=1;
m1++;
}
if(m1>12)
{m1=1;
y1++;}
}
return days;
}
//========================== THIS FUNCTION CALCULATES INTEREST========================
float account::calculate_interest(int t_accno,float t_balance)
{fstream file;
file.open("BANKING.DAT",ios::in | ios::binary);
file.seekg(0,ios::beg);
int d1,m1,y1,days;
while(file.read((char *)this, sizeof(account)))
{if(accno==t_accno)
{d1=dd;
m1=mm;
y1=yy;
break;
}
}
int d2,m2,y2;
struct date d;
getdate(&d);
d2=d.da_day;
m2=d.da_mon;
y2=d.da_year;
float t_interest=0.0;
days=no_of_days(d1,m1,y1,d2,m2,y2);
int months=0;
if(days>=30)
{months=days/30;
t_interest=((t_balance*months*(0.02)));
}
file.close();
return t_interest;
}
//========= THIS FUNCTION MAKES TRANSACTIONS (DEPOSIT/WITHDRAW)=======================
void account::transaction(void)
{clrscr();
char t_acc[10];
int t,t_accno,valid;
gotoxy(71,1);
cout<<"<0>=EXIT";
by_line();
gotoxy(5,5);
textcolor(BLUE);
cprintf("|| ENTER THE ACCOUNT NO.");
cin>>t;
t_accno=t;
if(t_accno==0)
return;
clrscr();
initial ini;
if(!ini.found_account(t_accno))
{gotoxy(5,5);
by_line();
textcolor(RED);
cprintf("\7|| ACCOUNT NOT FOUND");
getch();
textcolor(WHITE);
return;}
shape s;
s.box(2,2,79,24,218);
s.line_hor(3,78,4,196);
s.line_hor(3,78,22,196);
gotoxy(71,1);
cout<<"<0>=EXIT";
textbackground(BLACK);
gotoxy(3,3);
for(int i=1;i<=76;i++) cprintf(" ");
gotoxy(29,3);
textcolor(RED+BLINK);textbackground(BLACK);
cprintf(" TRANSACTION IN ACCOUNT ");
gotoxy(29,4);
cprintf("~~~~~~~~~~~~~~~~~~~~~~~~");
by_line();
textcolor(WHITE); textbackground(BLACK);
int d1,m1,y1;
struct date d;
getdate(&d);
d1=d.da_day;
m1=d.da_mon;
y1=d.da_year;
gotoxy(5,6);
cout<<"DATE: "<<d1<<"/"<<m1<<"/"<<y1;
gotoxy(5,8);
cprintf("ACCOUNT NO. #");
cout<<t_accno;
char t_name[30];
char t_address[60];
float t_balance;
strcpy(t_name,ini.return_name(t_accno));
strcpy(t_address,ini.return_address(t_accno));
t_balance=ini.give_balance(t_accno);
s.box(25,10,75,13,218);
gotoxy(27,11);
cprintf("NAME: ");
cprintf(t_name);
gotoxy(27,12);
cprintf("ADDRESS: ");
cprintf(t_address);
gotoxy(5,15);
cprintf("LAST BALANCE : Rs.");
cout<<t_balance;
char t_tran,t_type[10],tm[10];
float t_amount,t_amt;
do
{clear(5,18);
valid=1;
gotoxy(5,18);
textcolor(YELLOW);
cprintf("|| DEPOSIT OR WITHDRAW (D/W) :");
t_tran=getche();
if(t_tran=='0')
return;
t_tran=toupper(t_tran);
}while(t_tran!='D' && t_tran!='W');
do
{clear(5,19);
clear(5,23);
gotoxy(5,23);
cout<<"|| ENTER TRANSACTIONS TYPE (BY CASH OR CHEQUE)";
valid=1;
gotoxy(5,19);
cout<<"(CASH/CHEQUE):";
gets(t_type);
strupr(t_type);
if(t_type[0]=='0')
return;
if(strcmp(t_type,"CASH") && strcmp(t_type,"CHEQUE"))
{valid=0;
gotoxy(5,23);
textcolor(RED);
cprintf("\7|| ENTER CORRECTLY!! ");
getch();
}
}while(!valid);
do
{clear(5,21);
clear(5,23);
gotoxy(5,23);
cout<<"|| ENTER AMOUNT FOR TRANSACTION";
valid=1;
gotoxy(5,21);
cout<<"|| AMOUNT :Rs.";
gets(tm);
t_amt=atof(tm);
t_amount=t_amt;
if(tm[0]=='0')
return;
if((t_tran=='W' && t_amount>t_balance)||(t_amount<1))
{valid=0;
gotoxy(5,23);
textcolor(RED);
cprintf("\7|| INVALID DATA ENTERED !");
getch();
}
}while(!valid);
char ch;
clear(5,23);
do
{clear(40,20);
valid=1;
gotoxy(40,20);
cout<<"|| SAVE TRANSACTION (Y/N): ";
ch=getche();
if(ch=='0')
return;
ch=toupper(ch);
}while(ch!='N' && ch!='Y');
if(ch=='N')
return;
float t_interest;
t_interest=calculate_interest(t_accno,t_balance);
if(t_tran=='D')
t_balance=t_balance+t_amount+t_interest;
else
t_balance=(t_balance-t_amount+t_interest);
ini.update_balance(t_accno,t_balance);
add_to_file(t_accno,d1,m1,y1,t_tran,t_type,t_interest,t_amount,t_balance);
textcolor(WHITE);
}
//======================THIS FUNCTION CLOSE THE ACCOUNT (DELETE ACCOUNT)===============
void account::close_account(void)
{clrscr();
char t_acc[10];
int t,t_accno;
gotoxy(71,1);
cout<<"<0>=EXIT";
by_line();
textcolor(BLUE);
gotoxy(5,5);
cout<<"|| ENTER THE ACCOUNT NO.";
cin>>t;
t_accno=t;
if(t_accno==0)
return;
clrscr();
initial ini;
if(!ini.found_account(t_accno))
{gotoxy(5,5);
textcolor(RED);
cprintf("\7|| ACCOUNT NOT FOUND !!");
getch();
textcolor(WHITE);
return;
}
shape s;
s.box(2,2,79,24,218);
s.line_hor(3,78,4,196);
s.line_hor(3,78,22,196);
gotoxy(71,1);
cout<<"<0>=EXIT";
textbackground(BLACK);
gotoxy(3,3);
for(int i=1;i<=76;i++) cprintf(" ");
textbackground(BLACK);
textcolor(RED+BLINK);
gotoxy(30,3);
cprintf(" CLOSE ACCOUNT SCREEN ");
gotoxy(30,4);
cprintf("~~~~~~~~~~~~~~~~~~~~~~");
textcolor(WHITE); textbackground(BLACK);
int d1,m1,y1;
struct date d;
getdate(&d);
d1=d.da_day;
m1=d.da_mon;
y1=d.da_year;
gotoxy(62,5);
cout<<"DATE: "<<d1<<"/"<<m1<<"/"<<y1;
char ch;
ini.display(t_accno);
do
{clear(5,15);
gotoxy(5,15);
cprintf("|| CLOSE THIS ACCOUNT(Y/N):");
ch=getche();
if(ch=='0')
return;
ch=toupper(ch);
}while(ch!='N' && ch!='Y');
if(ch=='N')
return;
ini.delete_account(t_accno);
delete_account(t_accno);
gotoxy(5,20);
textcolor(GREEN);
cprintf("\7|| RECORD DELETED");
gotoxy(5,23);
cprintf("|| PRESS ANY KEY TO CONTINUE...");
getch();
textcolor(WHITE);
}
//=============THIS IS MAIN FUNCTION CALLING HELP AND MAIN MENU FUNCTIONS=============
void main()
{control c;
 c.help();
 c.main_menu();
}
