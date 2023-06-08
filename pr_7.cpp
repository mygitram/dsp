#include<iostream>
#include<string.h>
using namespace std;
class Graph
{
    int g[10][10],time,city_count;
    string city[10],sc,ds;
    int ch;
    public:
    Graph()
    {
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                g[i][j] = 0;
            }
        }
        city_count =0;
    }
    
    void create()
    {
        int i,j,si=0,di=0;
        do{
            cout<<"\nEnter source: ";
            cin>>sc;
            cout<<"\nEnter destination: ";
            cin>>ds;
            for(i=0;i<10;i++)
            {
                if(city[i]==sc)
                {
                    break;
                }
            }
            if(i==10)
            {
                city[city_count] = sc;
                city_count++;
            }
           
            for(j=0;j<10;j++)
            {
                if(city[j]==ds)
                {
                    break;
                }
            }
            if(j==10)
            {
                city[city_count] = ds;
                city_count++;
            }
            
            
            cout<<"\nEnter time between "<<sc<<" and "<<ds<<" :";
            cin>>time;
            for(j=0;j<10;j++)
		    {
		    		if(city[j]==sc)
		    			si=j;
		    		if(city[j]==ds)
		    			di=j;
		    }
            
            // cout<<"\n\nsc = "<<si<<"\n ds = "<<di;
            g[si][di] = time;
            g[di][si] = time;

            cout<<"\nDo you want to add more cities: ";
            cin>>ch;
        }while(ch!=0);
        
        
    }

    void display()
    {
        int i;
        for(i=0;i<city_count;i++)
        {
            cout<<"\t"<<city[i];
        }
        for(i=0;i<city_count;i++)
        {
            cout<<endl<<city[i];
            for(int j=0;j<city_count;j++)
            {
                cout<<"\t"<<g[i][j];
            }
        }
       
    }
};
int main()
{
    Graph g;
    g.create();
    g.display();
    return 0;
}