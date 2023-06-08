#include<iostream>
#include<string>
#include<queue>
#include<stack>
using namespace std;
struct node
{
    string name;
    struct node *link;
};
class Dept
{
    node *head[10];
    int visited[10];
    int n;
    public:
    Dept()
    {
        cout<<"\nEnter how many departments in college: ";
        cin>>n;
        for(int i=0;i<n;i++)
        {
            head[i] = new node();
            head[i]->name="novalue";
            head[i]->link = NULL;
        }
        
        for(int i=0;i<n;i++)
        {
            visited[i] = 0;
        }
    }
    void create()
    {
        int adj;
        node *temp;
        
        for(int i=0;i<n;i++)
        {
            cout<<"\nEnter name of "<<i+1<<"th dept: ";
            cin>>head[i]->name;
            cout<<"\nEnter how many departments adjecent to "<<head[i]->name<<" :";
            cin>>adj;
            temp = head[i];
            for(int j=0;j<adj;j++)
            {
                node *nnode=new node();
                nnode->link=NULL;
                cout<<"\nEnter connected department of "<<head[i]->name<<": ";
                cin>>nnode->name;
                temp->link = nnode;
                temp=temp->link;
            }
        }
    }
    void display()
    {
        node *temp;
        for(int i=0;i<n;i++)
        {
            cout<<"\n"<<head[i]->name<<" --->";
            temp=head[i]->link;
            while(temp!=NULL)
            {
                cout<<"\t"<<temp->name;
                temp = temp->link;
            }
        }
    }
    int getAddress(string nm)
    {
        int i;
        for(i=0;i<n;i++)
        {
            if(head[i]->name == nm)
            {
                break;
            }
        }
        return i;
    }
    int allvisited()
    {
        int i;
        for(i=0;i<n;i++)
        {
            if(visited[i]==0)
            {
                break;
            }
        }
        if(i==n)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void BFS()
    {
        for(int i=0;i<n;i++)
        {
            visited[i] = 0;
        }
        string tempname;
        queue<string> q;
        node *temp;
        int i;
        q.push(head[0]->name);
        cout<<endl<<endl;
        while(!q.empty())
        {
            tempname = q.front();
            q.pop();
            cout<<tempname<<"\t";
            i = getAddress(tempname);
            visited[i] = 1;
            temp = head[i];
            while(temp->link!=NULL)
            {
                tempname = temp->link->name;
                i = getAddress(tempname);
                if(visited[i]==0)
                {
                    q.push(tempname);
                }
                temp = temp->link;
            }
            if(allvisited())
            {
                break;
            }
        }
    }
    void DFS()
    {
        for(int i=0;i<n;i++)
        {
            visited[i] = 0;
        }
        int i;
        node *temp;
        stack<string> s;
        string tempstring;
        tempstring = head[0]->name;
        temp = head[0];
        cout<<"\n";
        while(temp!=NULL)
        {
            tempstring = temp->name;
            i = getAddress(tempstring);
            if(visited[i]==0)
            {
                s.push(temp->name);
                cout<<temp->name<<"\t";
                visited[i] = 1;
            }
            temp=temp->link;
        }
        while(!s.empty())
        {
            tempstring = s.top();
            s.pop();
            i = getAddress(tempstring);
            temp = head[i];
            while(temp!=NULL)
            {
                tempstring = temp->name;
                i = getAddress(tempstring);
                if(visited[i]==0)
                {
                    s.push(temp->name);
                    cout<<temp->name<<"\t";
                    visited[i] = 1;
                }
                temp=temp->link;
            }
        }
    }
};
int main()
{
    Dept d;
    d.create();
    d.display();
    d.DFS();
    d.BFS();
    return 0;
}