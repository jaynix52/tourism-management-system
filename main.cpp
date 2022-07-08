#include <iostream>
#include <iomanip>
#include <string.h>
#include <cstdio>

using namespace std;


class Customer {

    private :
    string customPlace;
    string customDays;
    string customNights;
    public :
    string name;
    string phoneNumber;
    string email;

    int SelectedPackage;
    int numberOfguest;
    int totalAmt;

    void Show()
    {
        cout << "Thank you for traveling with Tourism.";
    }

    friend class CustomPackage;
    friend class SpecialCustomer;

};


class CustomPackage{
public :

     void print(Customer obj){
        string p,d,n;
        fflush(stdin);
        cout<<"Which Place : ";
        cin>>p;
        fflush(stdin);
        cout<<"How many Days : ";
        cin>>d;
        fflush(stdin);
        cout<<"How many Nights : ";
        cin>>n;
        obj.customPlace = p;
        obj.customDays = d;
        obj.customNights = n ;
        cout<<""<<endl;
        cout<<""<<endl;
        cout<<"Your Custom package details:"<<endl;
        cout<<"Place :"<<obj.customPlace<<endl;
        cout<<"Days :"<<obj.customDays<<endl;
        cout<<"Nights :"<<obj.customNights<<endl;
        cout<<"Package has been processed! Thank you for choosing Tourism."<<endl;
     }
};

void index(){
    cout<<"    Welcome to Tourism Management Service    " << endl;
    cout<<" Travel Packages" <<endl;
    cout<<""<<endl;
    cout<<"Please choose the options between 0,1,2,3 to continue."<<endl;
    cout<<"0. Customer Service"<<endl;
    cout<<"1. Select a Package"<<endl;
    cout<<"2. create a custom Package"<<endl;
    cout<<"3. Exit"<<endl;
    cout<<""<<endl;
    cout<<"Please enter your option's number :"<<endl;
}

int bookpackage(int a){
    int bookpkOption;
    cout<<""<<endl;
    cout<<"Please enter number of guest :"<<endl;
    cin>>bookpkOption;

    return bookpkOption;

}

int bookpackage(){
    int bookpkOption;
    cout<<""<<endl;
    cout<<"Please enter your package's number :"<<endl;
    cin>>bookpkOption;

    return bookpkOption;

}

class SpecialCustomer : public Customer
{
public:

    void Show()
    {
        cout << "\nTicket received.We will contact you soon.";
    }
};


void packageinfo(){
    cout<<"   Package Plans  " << endl;
    cout<<"" <<endl;
    cout<<"1. Singapore 7 Days Package -> RM 25,000"<<endl;
    cout<<"2. Bangkok, Thailand 4 days 3 nights -> RM 17,500"<<endl;
    cout<<"3. Saudi Arabia 1 week 3 days -> RM 49,999"<<endl;
    cout<<"4. Sweden 1 week Tour -> RM 32,500"<<endl;
    cout<<"5. Hong Kong 2 Nights 3 Days -> RM 29,999"<<endl;
    cout<<"6. Taiwan 5 days 4 nights -> RM 48,500"<<endl;
    cout<<"7. Mexico 3 Days 2 Nights Package -> RM 48,499"<<endl;
    cout<<"" <<endl;
}



void display(Customer c){
    cout<<"Dear "+c.name+","<<endl;
    cout<<"Selected Package Plan "<<c.SelectedPackage<<" for "<<c.numberOfguest<<" guest will cost RM "<<c.totalAmt<<" in total."<<endl;
}


int calculatepackage(int& p , int& n){
    int bar [8] = { 0,25000,17500,49999,32500,29999,48500,48499};
    int total = bar[p] * n;
    return total;

}

int main()
{

    int option;
    Customer user;
    while(option!=3){
    cout<<""<<endl;
    index();
    cin>>option;
    if(option==0){
        SpecialCustomer sc;
        sc.Show();
        option=3;
    }
    else if(option==1){
        char pkOption;
        packageinfo();
        cout<<"book a package?(y/n)"<<endl;
        cin>>pkOption;
        if(pkOption == 'y'){
            int selectedPackage = bookpackage();
            int numberOfguest =  bookpackage(selectedPackage);
            string show;
            cout<<"Please fill up your Personal Informations"<<endl;
            cout<<"Name : ";
            cin>>show;
            user.name=show;
            fflush(stdin);
            cout<<"Phone Number : ";
            cin>>show;
            user.phoneNumber=show;
            cout<<"Email Address : ";
            cin>>show;
            user.email=show;
            user.SelectedPackage=selectedPackage;
            user.numberOfguest=numberOfguest;
            user.totalAmt=calculatepackage(selectedPackage,numberOfguest);
            cout<<""<<endl;
            cout<<""<<endl;
            display(user);
            user.Show();
            option=3;
        }
    }
    else if (option==2){
        cout<<"Make your own package with Tourism69."<<endl;
        string show;
            cout<<"Please fill up the Personal Informations"<<endl;
            cout<<"Name : ";
            cin>>show;
            user.name=show;
            fflush(stdin);
            cout<<"Phone Number : ";
            cin>>show;
            user.phoneNumber=show;
            cout<<"Email Address : ";
            cin>>show;
            user.email=show;
            Customer obj;
            CustomPackage obj2;
            cout<<"Dear "<<user.name<<",\nPlease fill up your custom Package."<<endl;
            obj2.print(obj);
            option=3;

    }
    else {
        cout<<"Option doesn't exists. Please enter your option's number again."<<endl;
    }
    }


    return 0;
}
