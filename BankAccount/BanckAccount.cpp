#include<bits/stdc++.h>
using namespace std;
// base class
// abstract
class BankAccout{
protected:
    //accnum
    int accnum;
    // balance
    double balance;
public:
    BankAccout() {}

    BankAccout(int accnum):accnum(accnum),balance(0) {}

    int getAccnum() const {
        return accnum;
    }

    double getBalance() const {
        return balance;
    }
    /*
     * this method check if amount>0
     */
    virtual void deposit(double amount);
    /*
     * 1- if balance >0 && amount >0 && amount<=balance
     */
    virtual void withdraw (double amount);
};


class CheckAccout : public BankAccout{
public:
    double fee=2.5;
    // override defualt
    CheckAccout():BankAccout() {}

    CheckAccout(int accnum,  double fee) : BankAccout(accnum), fee(fee) {}
/*
     * this method check if amount>0
     */
    void deposit(double amount) override {
        //check if(amount>0)
        if(amount>0){
            balance+=amount;
            cout << "amount added by : " << amount << endl;
            // apply transaction fee
            balance-=fee;
            cout << "fee applied by : " << fee << endl;
        }else cout << "amount must be greater than zero" << endl;
    }
    /*
    * 1- if balance >0 && amount >0 && amount<=balance
    */
    void withdraw(double amount) override {
        if(amount>0){
            // check balance
            if((fee+amount)<=balance){
                balance-=(fee+balance);
                cout << "you width : " << amount << " and  " << fee <<  " fom balance " << endl;
                cout << "your balance become  : " << balance << endl;
            }
        }else cout << "amount must be greater than zero" << endl;
    }
};
// child from banckaccont
// has an interest rate
// has a interest method
class savingaccount : public BankAccout{
private:
    // variable
    double interestrate;
    // override defualt
public:
    savingaccount():BankAccout() {}

    savingaccount(int accnum,  double interestrate) : BankAccout(accnum), interestrate(interestrate) {}
/*
     * this method check if amount>0
     */
    void deposit(double amount) override {
        //check if(amount>0)
        if(amount>0){
            balance+=amount;
            cout << "amount added by : " << amount << endl;
        }else cout << "amount must be greater than zero" << endl;
    }
    /*
    * 1- if balance >0 && amount >0 && amount<=balance
    */
    void withdraw(double amount) override {
        if(amount>0){
            // check balance
            if((amount)<=balance){
                cout << "your balance become  : " << balance << endl;
            }
        }else cout << "amount must be greater than zero" << endl;
    }

    void setInterestrate(double interestrate) {
        savingaccount::interestrate = interestrate;
    }

    double getInterestrate() const {
        return interestrate;
    }
    // calc interest
    double calcinterest(){
        return balance*interestrate;
    }
    // apply clac
    void applyclac(){
        balance+=calcinterest();
        cout << "interset added to balnace int = "<<interestrate << endl;
        deposit(interestrate);
    }
};
int main() {
    // create vec of accounts
    vector<BankAccout>accounts;

    return 0;
}
/*
 * this method to display options
 */
int menu (){
    cout << "Bank account menu" << endl;
    cout << "1- create new account " << endl;
    cout << "2- deposit funds " << endl;
    cout << "3- withdrqw funds" << endl;
    cout << "4- quit " << endl;
    int choice;
    do{
        cout << "Enter your choice : ";
        cin>> choice;
    }while(choice<1 || choice>4);
    return choice;
}
// account type
int accountmenu (){
    cout << "selection account type  : " << endl;
    cout <<"1- checking account " << endl;
    cout << "2- saving account " << endl;
    int key;
    do{
        cin>>key;
    }while (key<1||key>2);
    return key;
}
// create account
BankAccout createaccount (){
    BankAccout account = NULL;
    int key = accountmenu();
    int accnum ;
    cout << "enter account number : ";
    cin>>accnum;
    if(key==1){
        // this is CHECK account
        cout << "Enter fee : " << endl;
        double fee;cin>>fee;
        account = *new CheckAccout(accnum,fee);
    }else {
        //  its Saving account
         cout << "Enter interset rate : ";
          int ir;cin>>ir;
          account = *new savingaccount(accnum,ir);
    }
    return account;
}