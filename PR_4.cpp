#include<iostream>
#include<string>
#include<queue>
using namespace std;
struct node
{
    int data;
    node *left,*right;
};
class BTree
{
    public:
    node *root;
    int n=0,longpn=0;
    
    public:
    int count=1,t=0;
    BTree()
    {
        root = NULL;
    }
    void create()
    {
        int d;
        cout<<"\nEnter data you want to insert: ";
        cin>>d;
        insert(d);
    }
    void insert(int d)
    {
        node *nnode = new node();n++;
        nnode->left=nnode->right=NULL;
        nnode->data = d;
        if(root==NULL)
        {
            root = nnode;
        }
        else
        {
            node *temp,*nod;
            temp = root;

            while(temp != NULL)
            {
                nod = temp;
                if(temp->data>d )
                {
                    t++;
                    temp=temp->left;
                }
                else
                {
                    t++;
                    temp=temp->right;
                }
            }

            if(nod->data>d)
            {
                nod->left = nnode;
            }
            if(nod->data<d)
            {
                nod->right = nnode;
            }
            
            if(t>count)
            {
                count = t;
            }
            t=0;
        }
    }

    void display()
    {
        preorder(root);
    }
    void preorder(node *t)
    {
        if(t!=NULL)
        {
            cout<<t->data<<" ";
            preorder(t->left);
            preorder(t->right);
        }
    }

    void findMin()
    {
        node *temp = root;
        while(temp->left!=NULL)
        {
            temp = temp->left;
        }
        cout<<"\nMin value = "<<temp->data;
    }

    void search(int d)
    {
        node *nod,*temp = root;
        
        while(temp!=NULL)
        {
            nod = temp;
            if(temp->data>d)
            {
                temp=temp->left;
            }
            else
            {
                temp= temp->right;
            }
        }
        if(nod->data == d)
        {
            cout<<"\nData found";
        }
        else
        {
            cout<<"\nData not found";
        }
    }
    void mirror()
    {
        mr(root);
    }
    void mr(node *t)
    {
        if(t->left!=NULL)
        {
            mr(t->left);
        }
        if(t->right!=NULL)
        {
            mr(t->right);
        }
        node *ttt=t->left;
        t->left=t->right;
        t->right=ttt;
    }
    // void mirror()
    // {
    //     queue<node*> q1,q2;
    //     node *temp,*temp1,*temp2;
    //     temp = root;
    //     q1.push(temp);
    //     while(!q1.empty())
    //     {
    //         temp = q1.front();
    //         q1.pop();
    //         if(temp->left!=NULL)
    //         {
    //             q1.push(temp->left);
    //         }
    //         if(temp->right!=NULL)
    //         {
    //             q1.push(temp->right);
    //         }
    //         temp1 = temp->left;
    //         temp->left = temp->right;
    //         temp->right = temp1;
    //     }
    // }
    void height()
    {
        count=0;
        if(root==NULL)
        {
            cout<<"\n Tree doesn't exist";
        }
        else
        {
            he(root,0);
            cout<<"\n Height of tree is:"<<count;
        }
    }
    
    int he(node *temp,int c)
    {
        c++;
        if(temp->left!=NULL)
        {
            he(temp->left,c);
        }
        if(temp->right!=NULL)
        {
            he(temp->right,c);
        }
        if(count<c)
        {
            count=c;
        }
        return 0;
    }
    
    

};
int main()
{
    BTree t;
    t.insert(35);
    t.insert(24);
    t.insert(22);
    t.insert(40);
    t.insert(30);
    t.insert(32);
    t.insert(47);
    t.display();
    cout<<endl;
    t.mirror();
    t.display();

    // t.findMin();
    // t.search(12);
    
    t.height();
    return 0;
}