#include<iostream>
#include<cstring>
#include<conio.h> //To use the getch keyword we have used conio.h header file
using namespace std;

class atm{
 private:
 long int acc_no;
 string name;
 int pin;
 double balance;
 string mobile_no;

 public:
 void setData(long int acc_No, string n, int PIN, double bal, string phone_No){
    acc_no=acc_No;
    name=n;
    pin=PIN;
    balance=bal;
    mobile_no=phone_No;
}
long int get_accountNo(){
    return acc_no;
}
string get_name(){
    return name;
}
int get_pin(){
    return pin;
}
double get_bal(){
    return balance;
}
string get_phNO(){
    return mobile_no;
}
void setMobile(string mob_prev, string mob_new){
    if(mob_prev==mobile_no)
    {
        mobile_no==mob_new;
        cout<<endl<<"Successfully Updated Mobile Number.\n";
        _getch(); //getch is used to hold screen untill user press any key
    }
    else
    {
        cout<<"\nIncorrect!!! Old Mobile Number.";
        _getch();
    }
}
void cashwithDraw(int amount){
    if(amount > 0 && amount < balance){
        balance-=amount;
        cout<<endl<<"Please Collect Your Cash";
        cout<<endl<<"Available Balance :"<<balance;
        _getch();
    }
    else
    {
        cout<<"\nInvalid Input or Insufficient Balance";
        _getch();
    }
}
};
int main(){
    int choice = 0, enterPIN;
    long int enteraccNo;

    system("cls");
    atm user1;
    user1.setData(1234567, "Tim", 1111, 45000.90, "9087654321");
    do{
        system("cls");
        
        cout<<"\n*****Welcome To ATM*****\n";
        cout<<"\nEnter Your Account No\n";
        cin>>enteraccNo;

        cout<<"\nEnter PIN\n";
        cin>>enterPIN;

        if((enteraccNo==user1.get_accountNo()) && (enterPIN==user1.get_pin())){
            do{
                int amountt=0;
                string old_mob, new_mob;
                system("cls");

                cout<<"\n***** Welcome to ATM *****\n";
                cout<<"\nSelect Option\n";
                cout<<"\n1.Check Balance\n";
                cout<<"\n2.Cash Withdraw\n";
                cout<<"\n3.Show User Details\n";
                cout<<"\n4.Update Mobile Number\n";
                cout<<"\n5.Exit\n";
                cin>>choice;

                switch(choice){
                    case 1: 
                    cout<<"\nYour Bank balance is:"<<user1.get_bal();
                    _getch();
                    break;

                    case 2: cout<<"\nEnter the amount:";
                    cin>>amountt;
                    user1.cashwithDraw(amountt);
                    break;

                    case 3: 
                    cout<<"\nUser Details are:\n";
                    cout<<"\nAccount Number - "<<user1.get_accountNo();
                    cout<<"\nName - "<<user1.get_name();
                    cout<<"\nBalance - "<<user1.get_bal();
                    cout<<"\nMobile Number - "<<user1.get_phNO();
                    _getch();
                    break;

                    case 4:
                    cout<<"\nEnter Old Mobile Number. ";
                    cin>>old_mob;

                    cout<<"\nEnter New Mobile Number. ";
                    cin>>new_mob;
                    user1.setMobile(old_mob, new_mob);
                    break;

                    case 5: exit(0);

                    default:
                     cout<<"\nEnter Valid Data!!!";
                }
            }while(1);
        }
        else
        {
           cout<<"\nUser Details are Invalid!!! ";
           _getch();
        }
    }while(1);
}
