#include<iostream>
#include<stack>
using namespace std;
struct node
{
    char data;
    struct node *left;
    struct node *right;
};
class BT
{
    public:
        node *root;
    public:
        BT()
        {
            root=NULL;
        }
        void ConvertBT(char exp[15])
        {
            int i;
            stack<node*> s1;
            node *temp1,*temp2;
            for(i=0;i<15;i++)
            {
                if(exp[i]=='\0')
                {
                    break;
                }
            }
            i--;
            while(i!=-1)
            {
                node *nnode = new node();
                nnode->left=NULL;
                nnode->right=NULL;
                nnode->data=exp[i];
                // cout<<"\ni="<<i;
                if(exp[i]>='a' && exp[i]<='z')
                {
                    s1.push(nnode);                 
                }
                else
                {
                    temp1 = s1.top();
                    s1.pop();

                    temp2 = s1.top();
                    s1.pop();
                    
                    nnode->left = temp1;
                    nnode->right = temp2;
                    s1.push(nnode);
                    
                }
                
                i--;
            }
            root = s1.top();s1.pop();
        }
};

void Postorder(node *root)
{
    node *temp;
    stack<node*> s1,s2;
    s1.push(root);
    while(!s1.empty())
    {
        temp = s1.top();
        s1.pop();
        s2.push(temp);

        if(temp->left!=NULL)
        {
            s1.push(temp->left);
        }
        if(temp->right!=NULL)
        {
            s1.push(temp->right);
        }
    }
    while(!s2.empty())
    {
        temp = s2.top();s2.pop();
        cout<<temp->data<<" ";
    }
}
void deletee(node *temp)
{
    if(temp!=NULL)
    {
        deletee(temp->left);
        deletee(temp->right);
        delete temp;
    }
}
int main()
{
    BT b;
    char ex[15];
    cout<<"\nEnter an expression: ";
    cin>>ex;
    b.ConvertBT(ex);
    Postorder(b.root);

    deletee(b.root);
    cout<<"\nAfter deletion: ";
    Postorder(b.root);
    return 0;
}











