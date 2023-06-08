#include<iostream>
#include<queue>
using namespace std;
class Obst
{
    public:
        int w[10][10];
        int c[10][10];
        int r[10][10];
        int q[10],p[10],n;
        string s[10];
        Obst()
        {
                for(int i=0;i<10;i++)
                {
                        for(int j=0;j<10;j++)
                        {
                                w[i][j] = 0;
                                c[i][j] = 0;
                                r[i][j] = 0;
                        }
                }
        }
        void create();
        void displayTree();
};

void Obst::create()
{
    cout<<"\nenter value of n : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"enter keys : ";
        cin>>s[i];
    }
    cout<<"enter succ. prob. : ";
    for(int i=1; i<n+1; i++)
    {
        cin>>p[i];
    }
    cout<<"\nenter unsucc. prob . : ";
    for(int i=0; i<n+1; i++)
    {
        cin>>q[i];
    }

    //for 0 difference
    for(int i=0; i<n+1; i++)
    {
        w[i][i] = q[i];
        c[i][i] = r[i][i] = 0;
    }


    // for 1 diffrence

    for(int i=0,j; i<n; i++)
    {
        j=i+1;
        w[i][j] = p[j] + q[j] +w[i][i];
        c[i][j] = w[i][j];
        r[i][j] = j;
    }

    // for difference 2 to n

    for(int d = 2; d <= n; d++)
    {
        for(int i=0; (i+d) <= n; i++)
        {
            int j=i+d;
            w[i][j] = p[j] + q[j] + w[i][j-1];
            int minc = 2000;
            int root=0;
            int cost = 0;
            for(int k=i+1;k<=j;k++)
            {
                cost = c[i][k-1] + c[k][j];
                if(cost < minc)
                {
                    minc = cost;
                    root = k;
                }
            }
            c[i][j] = w[i][j] + minc;
            r[i][j] = root;
        }
    }

}

void Obst::displayTree()
{
    queue <int> q;
    q.push(0);
    q.push(n);
    int i=0,j=0;
    cout<<"root\tleft\tright"<<endl;
    while(!q.empty())
    {
        i = q.front();
        q.pop();
        j = q.front();
        q.pop();
        int k = r[i][j];
        cout<<s[k-1]<<"\t"; 
        if(r[i][k-1] != 0)
        {
            q.push(i);
            q.push(k-1);
            int p = r[i][k-1];
            cout<<s[p-1]<<"\t";
        }
        else
        {
            cout<<"NULL"<<"\t";
        }
        if(r[k][j] != 0)
        {
            q.push(k);
            q.push(j);
            int p = r[k][j];
            cout<<s[p-1];
        }
        else
        {
            cout<<"NULL"<<"\t";
        }
        cout<<endl;
    }
}

int main()
{
    Obst o1;
    o1.create();
    o1.displayTree();
}
