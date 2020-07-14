/* Program for taking question from the user with specified keywords and display the answer to that question.
    Made by- Hitesh Kishore Das
                Class-XII A
                Dt-4-4-2015
*/



#include<iostream>
// #include<conio.h>
#include"stdio.h"
#include<fstream>
#include<stdlib.h>
#include<ios>
#include<string.h>

using namespace std;

class keyword
{
public:
    char name[50];
    char what[50];
    char why[50];
    char how[50];
    char where[50];
    char when[50];
    char which[50];
    char whom[50];
    char who[50];
    char whose[50];

    void scribe(void)
    {
        std::ofstream marin;
        marin.open("Keywords.txt",ios::app);
        marin.seekp(0);
        marin<<"\n:"<<name<<'\n'<<what<<'\n'<<why;
        marin<<'\n'<<how<<'\n'<<where;
        marin<<'\n'<<when<<'\n'<<which;
        marin<<'\n'<<whom<<'\n'<<who;
        marin<<'\n'<<whose<<'\n';

        marin.close();
    }

} word;

void shift(char a[], int b)
{
    int l=strlen(a);

    for(int i=b; i<l-1; i++)
    {
        a[i]=a[i+1];

    }

    a[l-1]='\0';
}

void seek(char ser[])
{
    char store[50];
    int flag=0;
    std::ifstream marout;
    marout.open("Keywords.txt",ios::in);
    while(!marout.eof())
    {
        marout.getline(store,50);

        if(store[0]==':')
        {
            shift(store,0);

            if (!strcmp(store,ser))
            {
                marout.getline(store,50);
                strcpy(word.what,store);


                marout.getline(store,50);
                strcpy(word.why,store);

                marout.getline(store,50);
                strcpy(word.how,store);

                marout.getline(store,50);
                strcpy(word.where,store);

                marout.getline(store,50);
                strcpy(word.when,store);

                marout.getline(store,50);
                strcpy(word.which,store);

                marout.getline(store,50);
                strcpy(word.whom,store);

                marout.getline(store,50);
                strcpy(word.who,store);

                marout.getline(store,50);
                strcpy(word.whose,store);

                flag=1;
            }
            if (flag)break;
        }
    }


}


void answer(char a[])
{
    cout<<"Answer from MARTIN--"<<word.what;

    if (!strcmp(a, "what"))
        cout<<word.what;

    if (!strcmp(a, "why"))
        cout<<word.why;

    if (!strcmp(a, "how"))
        cout<<word.how;

    if (!strcmp(a, "where"))
        cout<<word.where;

    if (!strcmp(a, "when"))
        cout<<word.when;

    if (!strcmp(a, "which"))
        cout<<word.which;

    if (!strcmp(a, "whom"))
        cout<<word.whom;

    if (!strcmp(a, "who"))
        cout<<word.who;

    if (!strcmp(a,"whose"))
        cout<<word.whose;


}


void show(void)
{
    int n=0;
    char store[50];
    int flag=0;
    std::ifstream marout;
    marout.open("Keywords.txt",ios::in);
    while(!marout.eof())
    {
        marout.getline(store,50);

        if(store[0]==':')
        {
            n++;
            shift(store,0);
            cout<<n<<".  "<<store<<"\n\n";
        }
    }

    cout<<"The total number of keywords(including the 9 interrogative words) is-  "<<n+9<<"\n\n";
}



int main()

{
MAIN_MENU:

    system("clear");
    cout<<"**Created by-- HITESH KISHORE DAS**\n\n\n\n";
    cout<<"                  ---MARTIN--- \n\n                  -Main Menu-\n\n";
    cout<<"What function do you want to do?\n\n";
    cout<<"1. Interact with MARTIN.\n2. Enter the data for keywords.\n3. See all the keywords.\n4. Exit.";
    cout<<"\n\nEnter the number of the choice (1-4)--";
    int dec;
    cin>>dec;
    if (dec==1)
        goto MARTIN;
    else
    {
        if (dec==2)
            goto INPUT;
        else  if (dec==3)
            goto DISPLAYER;
        else  if (dec==4)
            goto EXIT;
        else
        {
            cout<<"Invalid choice!!  Enter any key to return to main menu-";
            getchar();// getch();
            goto MAIN_MENU;
        }
    }



EXIT:

    system("clear");
    cout<<"\n\n\n\n\n\n\n\n                     Do you really want to exit????? (y/n)--";
    char exd;
    cin>>exd;

    if (exd=='Y'|| exd=='y')
        exit(0);
    else
        goto MAIN_MENU;





DISPLAYER:

    system("cls");
    cout<<"Welcome! The following displayed keyword are available as objects-\n\n";
    cout<<"(Keywords \"what\" \"why\" \"how\" \"where\" \"when\" \"which\" \"whom\" \"who\" \"whose\" \nare available but are not included in this list)\n\n";

    show();
    char decision;
    cout<<"Do you want to go back to the main menu? (y/n)-";
    cin>>decision;

    if (decision=='Y'|| decision=='y')
        goto MAIN_MENU;
    else
        goto EXIT;




INPUT:

    system("cls");
    cout<<"Welcome to the terminal for input of data for keywords!!!\n\n\n\n";

    char test[2];
    //cout<<"Press any character-\n";
    //ch=getch();
    cout<<"Just enter the answers as it asks for them.\n";
    fgets(test,sizeof(test),stdin); // gets(test);

    cout<<"Enter the keyword-";
    fgets(word.name,sizeof(word.name),stdin);// gets(word.name);

    cout<<"Enter the answer to \" what \"-";
    fgets(word.what,sizeof(word.what),stdin);// gets(word.what);

    cout<<"Enter the answer to \"why \"-";
    fgets(word.why,sizeof(word.why),stdin);// gets(word.why);

    cout<<"Enter the answer to \" how \"-";
    fgets(word.how,sizeof(word.how),stdin);// gets(word.how);

    cout<<"Enter the answer to \" where \"-";
    fgets(word.where,sizeof(word.where),stdin);// gets(word.where);

    cout<<"Enter the answer to \" when \"-";
    fgets(word.when,sizeof(word.when),stdin);// gets(word.when);

    cout<<"Enter the answer to \" which \"-";
    fgets(word.which,sizeof(word.which),stdin);// gets(word.which);

    cout<<"Enter the answer to \" whom \"-";
    fgets(word.whom,sizeof(word.whom),stdin);// gets(word.whom);

    cout<<"Enter the answer to \" who \"-";
    fgets(word.who,sizeof(word.who),stdin);// gets(word.who);

    cout<<"Enter the answer to \" whose \"-";
    fgets(word.whose,sizeof(word.whose),stdin);// gets(word.whose);

    word.scribe();

    char d;
    cout<<"Do you want to enter another keyword-(y/n) ";
    d=getchar();// getch();

    if (d=='Y'|| d=='y')
        goto INPUT;
    else
    {
        cout<<" Do you want to go to main menu? (y/n) ";
        d=getchar();//getch();
        if (d=='Y'|| d=='y')
            goto MAIN_MENU;
        else
            goto EXIT;
    }







MARTIN:

    system("cls");
    cout<<"Welcome to the terminal for interacting with Martin!!!\n\n\n";
    cout<<"INSTRUCTIONS-\n\nIn the question the interrogating word such as \" what\" must come first.\n\n";
    cout<<"Then the subject for the question must come after that.\n\n";
    cout<<"Both of these interrogating word and subject will be \nregarded as keywords.\n\n";
    cout<<"The keywords must be within \"\" and number of keywords must be 2.\n\n";
    cout<<"All characters must be in lower case.\n\n";
    cout<<"For example-\"what\" is your \"name\"\?\n\n\n";

    char test0[2];
    cout<<"Press any key if your question is not first in the current session.\n\n";
    fgets(test0,sizeof(test0),stdin);// gets(test0);

    char a[50];
    char get[50];
    cout<<"Now,\n Enter the question-";
    fgets(get,sizeof(get),stdin);// gets(get);

    int len=strlen(get);
    const int l=2;
    int flag=0;
    for(int i=0,j=0; i<len,j<len; j++)
    {

        if (flag)
        {
            if (get[j]=='"')
            {
                get[j]=';';
                flag=!flag;
            }
        }
        else
        {
            if (get[j]=='"')
            {
                get [j]=':';
                flag=!flag;
            }
        }


    }



    int nkey=2;

    len=strlen(get);

    int num[5]= {-1,-1,-1,-1,-1};
    flag=0;

    for (int i=-1, j=0; j<len,i<nkey; j++)
    {
        if (get[j]==':')
        {
            i++;
            flag=1;
        }

        if (get[j]==';')
            flag=0;

        if (flag)
        {
            num[i]+=1;
        }

    }


    /* (for checking)   for (int i=0; i<nkey; i++)
                             cout<<num[i]<<endl;*/

    static int nkey2=nkey;

    char fin[nkey2][10];
    len=strlen(get);
    flag=0;

    for(int i=0,j=0,k=0; i<len , j<nkey2 , k<num[j]+2; i++)
    {
        if (get[i]==':')
        {
            flag=1;
            continue;
        }

        if (get[i]==';')
        {
            flag=0;
            j++;
            k=0;
        }

        if (flag)
        {
            fin[j][k]=get[i];
            k++;
        }
    }

    /* (for checking)   for (int i=0; i<nkey; i++)
                          {   cout<<endl;
                              for (int j=0; j<num[i]; j++)
                                  cout<<fin[i][j];
                                  cout<<endl;
                          }
                          cout<<fin[0]<<":";
                          cout<<"size-"<<strlen(fin[0]);
                                                              */


    const int  nm0= num[0];
    const int  nm1= num[1];
    char object[nm1];


    fin[0][nm0]='\0';
    fin[1][nm1]='\0';
    seek(fin[1]);



    answer(fin[0]);
    cout<<endl;
    getchar();// getch();
    cout<<"Do you want to ask another question?";
    char deci;
    deci=getchar();//getch();
    if (deci=='Y'|| deci=='y')
        goto MARTIN;
    else
    {
        cout<<" Do you want to go to main menu? (y/n) ";
        deci=getchar();//getch();
        if (deci=='Y'|| deci=='y')
            goto MAIN_MENU;
        else
            goto EXIT;
    }

    return 0;
}
