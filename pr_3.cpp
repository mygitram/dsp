#include<iostream>
#include<string.h>
using namespace std;
struct node
{
    string name;
    int count;
    struct node *child[5];
};
class Book
{
    node *root;
    string nm;
    public:
    Book()
    {
        root = NULL;
    }
    void create()
    {
        node *nnode;
        node *nde = new node();
        cout<<"\nEnter name of Book: ";
        cin>>nde->name;
        root = nde;
        cout<<"\nHow many chapter in this Book: ";
        cin>>root->count;
        for(int i=0;i<root->count;i++)
        {
            root->child[i] = new node();
            cout<<"\nEnter name of chapter: ";
            cin>>root->child[i]->name;
            cout<<"\nHow many sections in this chapter: ";
            cin>>root->child[i]->count;

            for(int j=0;j<root->child[i]->count;j++)
            {
                root->child[i]->child[j] = new node();
                cout<<"\nEnter name of section: ";
                cin>>root->child[i]->child[j]->name;
                cout<<"\nHow many sub-sections in this chapter: ";
                cin>>root->child[i]->child[j]->count;
                for(int k=0;k<root->child[i]->child[j]->count;k++)
                {
                    root->child[i]->child[j]->child[k] = new node();
                    cout<<"\nEnter name of sub-section: ";
                    cin>>root->child[i]->child[j]->child[k]->name;
                }   
            }    
        }

    }
    void display()
    {
        cout<<"\n\n"<<root->name;
        for(int i=0;i<root->count;i++)
        {
            cout<<"\n--"<<root->child[i]->name;
            for(int j=0;j<root->child[i]->count;j++)
            {
                cout<<"\n------"<<root->child[i]->child[j]->name;
                for(int k=0;k<root->child[i]->child[j]->count;k++)
                {
                    cout<<"\n-------------"<<root->child[i]->child[j]->child[k]->name;
                }    
            }
           
        }
    }

};
int main()
{
    Book b;
    int n;
    char c;
    do
    {
        cout<<"\n 1.Create \t 2.Display:";
        cin>>n;
        switch(n)
        {
            case 1:
            b.create();
            break;
            case 2:
            b.display();
            break;
        }
        cout<<"\n Do you wanna continue Y/N:";
        cin>>c;
    } while (c=='Y'||c=='y');
    
}