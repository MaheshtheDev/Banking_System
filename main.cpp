#include<iostream>
#include<cstdlib>
#include<string.h>
#include<fstream>
#include<conio.h>
#include<string>
#include<iomanip>
using namespace std;
void cl();
void admin();
void customer();
class bacc
{
public:
    int accno,amt;
    char nm[20],an[11],tp,occ[10],passw[5];
    void get()
    {
        cout<<"\n\t**********FILL THE FOLLOWING FORM TO CREATE ACCOUNT**********";
        cout<<"\n\t      1.Name Of the Account Holder:";
        cin>>nm;
          cout<<"\t      2.Contact Number            :";
          cin>>an;
          cout<<"\t      3.Account Type "
              <<"\n\t(\"SAVING'S(s)\",\"CURRENT(c)\"):";
          cin>>tp;
          cout<<"\t      4.Occupation                :";
          cin>>occ;
    }
    void balup()
    {
        cout<<"\n\t      5.Initial Deposit Amount     "                      <<"\n\t Min=500(FOR Saving's=500,FOR Current=1000):";
          cin>>amt;
    }
    void pwd()
    {
         cout<<"\n\n\tCreate Our Password with 5 Character:";
          cin>>passw;
    }
    void show()
    {
        cout<<"\n\t**********Details Of Required  Account**********";
        cout<<"\n\t      1.Name Of the Account Holder:"<<nm;
          cout<<"\n\t      2.Contact Number            :"<<an;
          cout<<"\n\t      3.Account Type              :"<<tp;
          cout<<"\n\t      4.Occupation                :"<<occ;
          cout<<"\n\t      5.Amount Balance            :"<<amt;
        cout<<"\n\t************************************************";
    }
    void diskIn(int);
    void diskOut();
    static int diskCount();
    void cdiskIn(int);
    void cdiskOut();
    static int cdiskCount();
};
void bacc::diskIn(int pn)
{
   ifstream infile;
   infile.open("ACC.DAT", ios::binary);
   infile.seekg( pn*sizeof(bacc) );
   infile.read( (char*)this, sizeof(*this) );
}
void bacc::cdiskIn(int cpn)
{
    ifstream infile;
    infile.open("CACC.DAT", ios::binary);
    infile.seekg( cpn*sizeof(bacc) );
    infile.read( (char*)this, sizeof(*this) );
}
void bacc::cdiskOut()
{
    ofstream outfile;
    outfile.open("CACC.DAT", ios::app | ios::binary);
    outfile.write( (char*)this, sizeof(*this) );
}
void bacc::diskOut()
{
    ofstream outfile;
    outfile.open("ACC.DAT", ios::app | ios::binary);
    outfile.write( (char*)this, sizeof(*this) );
}
int bacc::diskCount()
{
    ifstream infile;
    infile.open("ACC.DAT", ios::binary);
    infile.seekg(0, ios::end);
    return (int)infile.tellg() / sizeof(bacc);
}
int bacc::cdiskCount()
{
    ifstream infile;
    infile.open("CACC.DAT", ios::binary);
    infile.seekg(0, ios::end);
    return (int)infile.tellg() / sizeof(bacc);
}
int main()
{
    bacc a;
    system("CLS");
    system("COLOR 74");
    int op,opt,b,an,n=0,ran;
    char ch,li[13]={'S','B','I','1','1','7','0','6','7','7','7'},pass[5]={'1','2','3','4'},ali[13],pali[5];
    cout<<"\n\n\n\t\t\t\t~~~~~~~~~WELCOME TO SBI ONLINE~~~~~~~~~~~";
    cout<<"\n\n\n\t\t\t\t\t*****************";
    cout<<"\n\t\t\t\t\t1.ADMIN    LOGIN";
    cout<<"\n\t\t\t\t\t2.CUSTOMER LOGIN";
    cout<<"\n\t\t\t\t\t3.EXIT          ";
    cout<<"\n\t\t\t\t\t*****************";    cout<<"\n\t\t\t\t***********Developed by \"Mahesh\"************";
    cout<<"\n\t\t\tEnter Your Option:";
    cin>>op;
    switch(op)
    {
    case 1:
        system("CLS");
        system("COLOR 1F");
        admin();
        main();
    case 2:
        system("CLS");
        system("COLOR 1F");
        customer();
        main();
    case 3:
        system("CLS");
        system("COLOR 0F");
        cout<<"\n\n\n\t\t Hope U Enjoy The Service...[Keep Smiling]";
        cout<<"\n\t\t ~~~~~~Developed By \"MAHESH\"~~~~~~~";
        getch();
        exit(0);
    default:
        main();
    }
}
void admin()
{
    int opt,n,i=0,ran,l,ac,des=0;
    bacc a;
    char ch,ps[6],li[13]={'S','B','I','1','1','7','0','6','7','7','7'},pass[5]={'1','2','3','4'},ali[13],pali[5];
    system("CLS");
       cout<<"\n\n\t\t\t*******ADMIN LOGIN*******";
        cout<<"\n\t\t\tEnter LOGIN ID:";
        cin>>ali;
        cout<<"\t\t\tEnter Password:";
        ch = getch();
        while(ch != '\r'){
          pali[i]=ch;
          cout << '*';
          i++;
         ch =getch();}
        if((strcmp(li,ali)==0)&&(strcmp(pass,pali)==0))
            {
                ad:
            system("CLS");
            cout<<"\n\n\t\t\t**********Account's Manager***********";
            cout<<"\n\t\t\t  1.Add   Account";
            cout<<"\n\t\t\t  2.View  Account's List";
            cout<<"\n\t\t\t  3.Deposit Amount";
            cout<<"\n\t\t\t  4.Withdraw Amount";
            cout<<"\n\t\t\t  5.Balance Enquiry";
            cout<<"\n\t\t\t  6.Delete Account";
            cout<<"\n\t\t\t  7.Exit          ";
            cout<<"\n\n\t\t\t**************************************";
            cout<<"\n\tEnter Your Choice:";
            cin>>opt;
            int flag=0;
            switch(opt)
            {
            case 1:
                system("CLS");
                a.get();
                am:
                a.balup();
                if((a.tp=='s'&&a.amt>=500)||(a.tp=='c'&&a.amt>=1000))
                {
                xy:
                a.pwd();
                cout<<"\n\tConfirm Password:";
                cin>>ps;
                if(strcmp(ps,a.passw)==0)
                {
                n=bacc::diskCount();
                cout<<"\n\t"<<n;
                if(n>0)
                a.accno=100+n;
                else
                    a.accno=100;
                cout<<"\n\t Your Account Number is:"<<a.accno;
                getch();
                a.diskOut();
                }
                else
                {
                    cout<<"\n\tInvalid Password";
                    goto xy;
                }
                }
                else
                {
                    cout<<"\n\tDeposit Required Amount...!";
                   goto am;
                }
                goto ad;
            case 2:
                system("CLS");
                n=bacc::diskCount();
                cout<<"\n\t********************************************************************";
                cout<<"\n\t  Account Holder Name  | Account Number | Account Type | Occupation|";
                cout<<"\n\t********************************************************************";
                for(i=0;i<n;i++)
                {
                a.diskIn(i);
                l=strlen(a.nm);
                l=22-l;
                   cout<<"\n\t   "<<a.nm<<setw(l)<<"| "<<a.accno<<setw(14)<<"| "<<a.tp<<setw(14)<<"| "<<a.occ;
                }
                cout<<"\n\t********************************************************************";
                cout<<"\n\t \"s\" Indicating SAVING's Account";
                cout<<"\n\t \"c\" Indicating CURRENT's Account";
                getch();
                goto ad;
            case 3:
                system("CLS");
                cout<<"\n\t\tEnter the Account Number:";
                cin>>ac;
                n=bacc::diskCount();
                for(i=0;i<n;i++)
                {
                    a.diskIn(i);
                    if(a.accno==ac)
                    {
                        a.show();
                        cout<<"\n\tEnter the Amount Deposited:";
                        cin>>des;
                        a.amt=a.amt+des;
                        a.diskOut();
                        n=bacc::diskCount();
                    for(int j=0;j<n;j++)
                    {
                       if(j!=i)
                       {
                       a.diskIn(j);
                       a.cdiskOut();
                       }
                     }
                      remove("ACC.DAT");
                      n=bacc::cdiskCount();
                      for(int j=0;j<n;j++)
                        {
                         a.cdiskIn(j);
                         a.diskOut();
                        }
                        remove("CACC.DAT");
                    cout<<"\n\tRecord Saved";
                        getch();
                    }

                    }
                goto ad;
            case 4:
                system("CLS");
                cout<<"\n\t\tEnter the Account Number:";
                cin>>ac;
                n=bacc::diskCount();
                for(i=0;i<n;i++)
                {
                    a.diskIn(i);
                    if(a.accno==ac)
                    {
                        a.show();
                        cout<<"\n\tEnter the Amount Withdraw:";
                        cin>>des;
                        a.amt=a.amt-des;
                        a.diskOut();
                        n=bacc::diskCount();
                    for(int j=0;j<n;j++)
                    {
                       if(j!=i)
                       {
                       a.diskIn(j);
                       a.cdiskOut();
                       }
                     }
                      remove("ACC.DAT");
                      n=bacc::cdiskCount();
                      for(int j=0;j<n;j++)
                        {
                         a.cdiskIn(j);
                         a.diskOut();
                        }
                        remove("CACC.DAT");
                    cout<<"\n\tDetail's UPDATED";
                        getch();
                    }

                    }
                goto ad;
            case 5:
                system("CLS");
                cout<<"\n\tEnter the Account Number:";
                cin>>ran;
                flag=0;
                n=bacc::diskCount();
                for(i=0;i<n;i++)
                {
                 a.diskIn(i);
                 if(a.accno==ran){
                        a.show();
                        flag=1;
                        getch();
                        }
                }
                if(flag==0){system("CLS");
                    cout<<"\n\tSorry...!There No Account on this Number";
                   getch();
                }
                goto ad;
            case 6:
                system("CLS");
                char o;
                cout<<"\n\tEnter Account Number:";
                cin>>ac;
                n=bacc::diskCount();
                for(i=0;i<n;i++)
                {
                    a.diskIn(i);
                    if(a.accno==ac)
                    {
                        a.show();
                        cout<<"\n\tDo u want to Delete Account(y/n)";
                        cin>>o;
                        if(o=='y')
                      for(int j=0;j<n;j++)
                      {
                       if(j!=i)
                       {
                       a.diskIn(j);
                       a.cdiskOut();
                       }
                      else
                      {
                       a.diskIn(i);
                      cout<<a.nm<<endl;
                      _sleep(2000);
                      cout<<"\t\tDeleting File......";
                      }
                     }
                      remove("ACC.DAT");
                      n=bacc::cdiskCount();
                  for(int j=0;j<n;j++)
                 {
                 a.cdiskIn(j);
                 a.diskOut();
                 }
                   remove("CACC.DAT");
                    }
                }
                goto ad;
            case 7:
                main();
            default:
                 goto ad;
            }
        }
        else
        {
            cout<<"Invalid Input";
            admin();
        }
}
void customer()
{
    bacc a;
    a1:
    int lacno,flag=0,n,op,des;
    char lpass[5],ch;
    cout<<"\n\t******CUSTOMER LOGIN******";
    cout<<"\n\t Login ID:";
    cin>>lacno;
    cout<<"\n\t Password:";
    ch=getch();
     int i=0;
     n=bacc::diskCount();
        while(ch != '\r'){
          lpass[i]=ch;
          cout << '*';
          i++;
         ch =getch();}
         for(i=0;i<n;i++)
         {
             a.diskIn(i);
         if((lacno==a.accno)&&(strcmp(lpass,a.passw)==0))
         {
             x1:
             system("CLS");
             flag=1;
             cout<<"\n\t******WELCOME "<<a.nm<<" TO SBI ONLINE******";
             cout<<"\n\t 1.Balance Enquiry";
             cout<<"\n\t 2.Withdraw Amount";
             cout<<"\n\t 3.Exit           ";
             cout<<"\n\t****************************";
             cout<<"\n\t Enter Your Option:";
             cin>>op;
             switch(op)
             {
             case 1:
                 system("CLS");
                a.show();
                getch();
                goto x1;
             case 2:
                 system("CLS");
                a.show();
                        cout<<"\n\tEnter the Amount Withdraw:";
                        cin>>des;
                        a.amt=a.amt-des;
                        a.diskOut();
                        n=bacc::diskCount();
                    for(int j=0;j<n;j++)
                    {
                       if(j!=i)
                       {
                       a.diskIn(j);
                       a.cdiskOut();
                       }
                     }
                      remove("ACC.DAT");
                      n=bacc::cdiskCount();
                      for(int j=0;j<n;j++)
                        {
                         a.cdiskIn(j);
                         a.diskOut();
                        }
                        remove("CACC.DAT");
                    cout<<"\n\tDetail's UPDATED";
             getch();
             goto x1;
             case 3:
                main();
         }
         }
         }
         if(flag==0)
         {
            system("CLS");
            cout<<"\n\tINVALID LOGIN ID or PASSWORD";
            goto a1;
         }
}
