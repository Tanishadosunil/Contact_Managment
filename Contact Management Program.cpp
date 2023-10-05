#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Contact{
public:
    string name, phoneNumber, email;
    Contact(string n, string p, string e) : name(n), phoneNumber(p), email(e) {}
};

class ContactManager{
    vector<Contact> contacts;

public:
    void addContact(string name, string phoneNumber, string email) {
        Contact New(name,phoneNumber,email);
        contacts.push_back(New);
        cout<<"Conatact added successfully."<<endl<<endl;
    }

    void editContact(int index, string name, string phoneNumber, string email) {
        if((index-1)>=0 && (index-1)<contacts.size()) {
            contacts[index-1].name=name;
            contacts[index-1].phoneNumber=phoneNumber;
            contacts[index-1].email=email;
            cout<<"Conatct edited successfully."<<endl;
        }
        else
            cout<<"Invalid Contact."<<endl;
    }

    void deleteContact(int index) {
        if((index-1)>=0 && (index-1)<contacts.size()) {
            contacts.erase(contacts.begin()+(index-1));
            cout<<"Contact deleted successfully"<<endl;
        }
        else
            cout<<"Invalid Contact"<<endl;
        cout<<endl<<endl;
    }

    void searchByIndex() {
        if(contacts.empty()) {
            cout<<"Contact list is empty."<<endl;
        }
        else {
            int index;
            cout<<"Enter Index: "<<endl;
            cin>>index;
            if((index-1)>=0 && (index-1)<contacts.size()) {
                cout<<"Index: "<<index<<endl;
                cout<<"Name: "<<contacts[index-1].name<<endl;
                cout<<"Phone Number: "<<contacts[index-1].phoneNumber<<endl;
                cout<<"Email: "<<contacts[index-1].email<<endl;
            }
            else
                cout<<"Invalid Contact"<<endl;
        }
        cout<<endl<<endl;
    }

    void searchByName() {
        if(contacts.empty())
            cout<<"Contact list is empty."<<endl;
        else {
            string name;
            cout<<"Enter Name: "<<endl;
            cin>>name;
            int index;
            for(index=0; index<contacts.size(); index++) {
                if(contacts[index].name==name) {
                    cout<<"Index: "<<index+1<<endl;
                    cout<<"Name: "<<contacts[index+1].name<<endl;
                    cout<<"Phone Number: "<<contacts[index+1].phoneNumber<<endl;
                    cout<<"Email: "<<contacts[index+1].email<<endl;
                    break;
                }
            }
            if(index==contacts.size())
                cout<<"No such contact is found.";
        }
        cout<<endl<<endl;
    }

    void displayContact() {
        if(contacts.empty())
            cout<<"Contacts not found"<<endl;
        else {
            int count=1;
            for(auto it=contacts.begin(); it!=contacts.end(); it++) {
                cout<<"Index : "<<count<<endl;
                cout<<"Name : "<<it->name<<endl;
                cout<<"phoneNumber : "<<it->phoneNumber<<endl;
                cout<<"email : "<<it->email<<endl;
                cout<<"------------------------------------------"<<endl;
                count++;
            }
        }
        cout<<endl<<endl;
    }
};

int main() {
    while(1) {
        ContactManager contactManager;
        cout<<"Contact Management System"<<endl<<endl;
        cout<<"1. Add Contact"<<endl;
        cout<<"2. Edit Contact"<<endl;
        cout<<"3. Delete Conatct"<<endl;
        cout<<"4. Search Conatct By Index"<<endl;
        cout<<"5. Search Conatct By Name"<<endl;
        cout<<"6. Display Conatct"<<endl;
        cout<<"7. Quit"<<endl<<endl;

        int choice;
        cout<<"Enter your choice: ";
        cin>>choice;
        cout<<endl<<endl;

        switch(choice) {
            case 1:{
                string name, phoneNumber, email;
                cout<<"Enter Name: "<<endl;
                cin>>name;
                cout<<"Enter Phone Number: "<<endl;
                cin>>phoneNumber;
                cout<<"Enter Email: "<<endl;
                cin>>email;
                contactManager.addContact(name,phoneNumber,email);
                cout<<endl<<endl;
                break;
            }
            case 2:{
                int index;
                string name, phoneNumber, email;
                cout<<"Enter Index: "<<endl;
                cin>>index;
                cout<<"Enter Name: "<<endl;
                cin>>name;
                cout<<"Enter Phone Number: "<<endl;
                cin>>phoneNumber;
                cout<<"Enter Email: "<<endl;
                cin>>email;
                contactManager.editContact(index,name,phoneNumber,email);
                cout<<endl<<endl;
                break;
            }
            case 3:{
                int index;
                cout<<"Enter Index: "<<endl;
                cin>>index;
                contactManager.deleteContact(index);
                cout<<endl<<endl;
                break;
            }
            case 4:{
                contactManager.searchByIndex();
                break;
            }
            case 5:{
                contactManager.searchByName();
                break;
            }
            case 6:{
                contactManager.displayContact();
                cout<<endl<<endl;
                break;
            }
            case 7:{
                cout<<"You have successfully executed..."<<endl;
                return 0;
            }
            default:
                cout<<"Invalid Choice..."<<endl;
        }
    }

    return 0;
}
