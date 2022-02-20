#include <iostream>
#include<cstring>

    using namespace std;

    class Node
    {
        public:
        char number[50];
        char name[30];
        char gmail[55];
        Node *prev,*next;

        //Constructor
        Node(char n[],char num[],char em[])
        {
            strcpy(name,n);    //Copy n in name
            strcpy(number,num);
            strcpy(gmail,em);
            next=NULL;
            prev=NULL;
        }
        friend class list;
    };
    class list
    {
        Node *head;
        Node*temp;
        Node*ptr;
        Node *ptr1;
        Node*ptr2;
        Node*newNode;

        public:
        Node *prev;

        void insert();
        void deletecontact(char n[20]);
        void deletesamenumber();
        void deletesamename();
        void deletesamegmail();
        void searchbyname(char p[20]);
        void searchbynumber(char no[30]);
        void searchbygmail(char g[20]);
        void display();
        void update(char ch[10]);
        void sort();


        list()
        {
            head=NULL;
            temp=NULL;
            ptr=NULL;
            ptr1=NULL;
            ptr2=NULL;
            newNode=NULL;
        }
    };


    void list::display() //Display Function
    {
        ptr=head;
        while(ptr!=NULL)
        {
            cout<<"\n\nNAME  ::\t"<<ptr->name;
            cout<<"\nNUMBER::\t"<<ptr->number;
            cout<<"\nG-MAIL::\t"<<ptr->gmail;
            ptr=ptr->next;
        }
    }
        //Aashir
    void list::insert() //Insert At Tail
    {
        char number[50];
        char gmail[40];
        char name[30];
        char ans;
        do
        {
            cout<<"ENTER NAME      :";
            cin>>name;

            cout<<"ENTER NUMBER    :";
            cin>>number;
            while(strlen(number)!=11) //Count Input of number
            {
                cout<<"ENTER VALID NUMBER  :";
                cin>>number;
            }
            cout<<"ENTER G-MAIL    :";
            cin>>gmail;
            temp=new Node(name,number,gmail);
            if(head==NULL)
            {
                head=temp;
            }
            else
            {
                ptr=head;
                while(ptr->next!=NULL)
                {
                    ptr=ptr->next;
                }
                ptr->next=temp;
                temp->prev=ptr;
            }
            cout<<"DO YOU WANT TO CONTINUE?????????";
            cout<<"ENTER y to Continue else Enter n";
            cin>>ans;
        }while(ans=='y');

    }
    void list::sort()
    {
        Node *i,*j;
        int temp;
        char n[10];
        for(i=head;i->next!=NULL;i=i->next)
        {
            for(j=i->next;j!=NULL;j=j->next)
            {
                temp=strcmp(i->name,j->name);
                if(temp>0)
                {
                    strcpy(n,i->name);
                    strcpy(i->name,j->name);
                    strcpy(j->name,n);
                }
            }
        }

    }
    void list::deletecontact(char s[20])
    {
        int c=0;
        ptr=head;
        while(ptr!=NULL)
        {
            if(strcmp(s,ptr->name)==0) //Comparisson of s and name
            {
                c=1;
                break;
            }
            else
            {
                c=2;
            }
            ptr=ptr->next;
        }
        if(c==1 && ptr!=head && ptr->next!=NULL) // Delete At Index
        {
            ptr->prev->next=ptr->next; //ptr.getprev.setnext( ptr.next)
            ptr->next->prev=ptr->prev;  //ptr.getnext.setprev(ptr.getprev())
            delete(ptr);
            cout<<"YOUR CONTACT IS SUCCESSFULLY DELETED\n\n";
        }
        if(ptr==head) //Delete at head
        {
            head=head->next;
            head->prev=NULL;
            delete(ptr);
            cout<<"YOUR CONTACT IS SUCCESSFULLY DELETED\n\n";
        }
        if(ptr->next==NULL) // delation at end
        {
            ptr->prev->next=NULL;
            ptr->prev=NULL;
            delete(ptr);
            cout<<"YOUR CONTACT IS SUCCESSFULLY DELETED\n\n";
        }
        if(c==2)
        {
            cout<<"YOUR ENTERED NAME IS NOT IN THE LIST...";
        }
    }

    void list::deletesamename()
    {
        ptr1=head;
        while (ptr1 != NULL && ptr1->next != NULL)
        {
            ptr2 = ptr1;
            while (ptr2->next != NULL)
            {
                if (strcmp(ptr1->name,ptr2->next->name)==0)
                {
                    newNode = ptr2->next;
                    ptr2->next = ptr2->next->next;
                    delete(newNode);
                }
                else
                {
                    ptr2 = ptr2->next;
                }
            }
            ptr1 = ptr1->next;
        }
    }
    void list::deletesamegmail()
    {
        ptr1=head;
        while (ptr1 != NULL && ptr1->next != NULL)
        {
            ptr2 = ptr1;
            while (ptr2->next != NULL)
            {
                if (strcmp(ptr1->gmail,ptr2->next->gmail)==0)
                {
                    newNode = ptr2->next;
                    ptr2->next = ptr2->next->next;
                    delete(newNode);
                }
                else
                {
                    ptr2 = ptr2->next;
                }
            }
            ptr1 = ptr1->next;
        }
    }
    void list::deletesamenumber()
    {
        ptr1=head;
        while (ptr1 != NULL && ptr1->next != NULL)
        {
            ptr2 = ptr1;
            while (ptr2->next != NULL)
            {
                if (strcmp(ptr1->number,ptr2->number)==0)
                {
                    newNode = ptr2->next;
                    ptr2->next = ptr2->next->next;
                    delete(newNode);
                }
                else
                {
                    ptr2 = ptr2->next;
                }
            }
            ptr1 = ptr1->next;
        }
    }
    //Moeed
    void list::searchbyname(char na[10])
    {
        ptr=head;
        while(ptr!=NULL)
        {
            if(strcmp(na,ptr->name)==0)
            {
                cout<<"NAME FOUND"<<endl;
                cout<<"CONTACT DETAILS ARE BELOW:\n"<<endl;
                cout<<"\n\nNAME  ::\t"<<ptr->name;
                cout<<"\nNUMBER::\t"<<ptr->number;
                cout<<"\nG-MAIL::\t"<<ptr->gmail;

            }
            ptr=ptr->next;
        }
    }
    void list::searchbynumber(char num[20])
    {
        ptr=head;
        while(ptr!=NULL)
        {
            if(strcmp(num,ptr->number)==0)
            {
                cout<<"NUMBER FOUND\n"<<endl;
                cout<<"CONTACT DETAILS ARE BELOW:\n"<<endl;
                cout<<"\n\nNAME  ::\t"<<ptr->name;
                cout<<"\nNUMBER::\t"<<ptr->number;
                cout<<"\nG-MAIL::\t"<<ptr->gmail;

            }
            ptr=ptr->next;
        }
    }
    void list::searchbygmail(char gm[20])
    {
        ptr=head;
        while(ptr!=NULL)
        {
            if(strcmp(gm,ptr->gmail)==0)
            {
                cout<<"G-MAIL FOUND\n"<<endl;
                cout<<"CONTACT DETAILS ARE BELOW:\n"<<endl;
                cout<<"\n\nNAME  ::\t"<<ptr->name;
                cout<<"\nNUMBER::\t"<<ptr->number;
                cout<<"\nG-MAIL::\t"<<ptr->gmail;

            }
            ptr=ptr->next;
        }
    }
    //Bilal
    void list::update(char n[20])
    {
        char ans;
        int c;
        ptr=head;
        while(ptr!=NULL)
        {
            if(strcmp(n,ptr->name)==0)
            {

                do
                {
                    cout<<"\nWHAT DO YOU WANT TO UPDATE?\n1.NAME\n2.PHONE NUMBER\n3.G-MAIL\n";
                    cin>>c;
                    switch(c)
                    {
                        case 1:
                            cout<<"ENTER NEW-NAME=";
                            cin>>ptr->name;
                            break;
                        case 2:
                            cout<<"ENTER NEW PHONE-NUMBER?";
                            cin>>ptr->number;
                            while(strlen(ptr->number)!=11)
                            {
                                cout<<"ENTER VALID NUMBER  :";
                                cin>>ptr->number;
                            }
                            break;
                        case 3:
                            cout<<"ENTER NEW G-MAIL";
                            cin>>ptr->gmail;
                            break;
                    }
                    cout<<"DO YOU WANT TO CONTINUE UPDATING?";
                    cin>>ans;
                }while(ans=='y');
            }
            ptr=ptr->next;
        }
    }
    int main()
    {
        char n[20];
        char nam[20];
        char name[10];
        char number[10];
        char gmail[20];
        list d1;
        // apply d;
        char ans;
        int ch,a;
        cout<<"**************                                PHONE BOOK                          ********************";
        cout<<"\n\nWHAT IS YOUR NAME?\n";
        cin.getline(name,20);
        cout<<"\n\n!!!!!!!!!!!!!!!!!!!!!!!   WELCOME "<<name<<"   !!!!!!!!!!!!!!!!!!!!!";
        cout<<"\n\n\nLET'S CREATE OUR PHONEBOOK "<<name<<"  \n\n";
        d1.insert();
        d1.sort();
        do
        {
            cout<<"\n\n\n\n1) DISPLAY YOUR PHONE BOOK\n2) INSERT NEW CONTACT\n3) UPDATE DETAILS ON EXISTING CONTACT\n4) DELETE CONTACT\n5) DELETE SAME NAME IN PHONEBOOK\n6) DELETE SAME NUMBERS IN PHONEBOOK\n7) SEARCH\n";
            cin>>ch;
            switch(ch)
            {
                case 2:
                    d1.insert();
                    d1.sort();
                    break;

                case 1:
                     d1.sort();
                    d1.display();
                    break;
                case 3:

                    cout<<"\n\nENTER THE NAME OF PERSON WHOSE DETAILS YOU WANT TO UPDATE...\n";
                    cin>>n;
                    d1.update(n);
                    d1.sort();
                    break;
                case 4:
                    cout<<"\nENTER THE NAME YOU WANT TO DELETE FROM PHONEBOOK\n";
                    cin>>name;
                    d1.deletecontact(name);
                    break;
                case 5:
                    d1.deletesamename();
                    d1.display();
                    break;
                case 6:
                    d1.deletesamenumber();
                    d1.display();
                    break;
                case 7:
                    do
                    {
                        cout<<"1.SEARCH BY NAME\n2.SEARCH BY NUMBER\n3.SEARCH BY GMAIL";
                        cin>>a;
                        switch(a)
                        {
                            case 1:
                                cout<<"ENTER THE NAME TO BE SEARCHED\n";
                                cin>>name;
                                d1.searchbyname(name);
                                break;
                            case 2:
                                cout<<"ENTER THE NUMBER TO BE SEARCHED\n";
                                cin>>number;
                                d1.searchbynumber(number);
                                break;
                            case 3:
                                cout<<"ENTER THE GMAIL TO BE SEARCHED\n";
                                cin>>gmail;
                                d1.searchbygmail(gmail);
                                break;
                            default:cout<<"\nNO PROPER INPUT GIVEN.....\n";
                        }
                        cout<<"DO YOU WANT TO CONTINUE SEARCHING?????????";
                        cin>>ans;
                    }while(ans=='y');

                    break;
                case 8:d1.deletesamegmail();
                    d1.display();
                    break;
                default:cout<<"\nNO PROPER INPUT GIVEN..\n";
            }
            cout<<"\n\nDO YOU WANT TO CONTINUE OPERATIONS?????????";
            cout<<"Enter y to Continue and n To STOP";
            cin>>ans;
        }while(ans=='y');
    }
