#include <iostream>
#include <stdlib.h>
#include <time.h>
#include  <set>
#include <bits/stdc++.h>
#include <iterator>

void init_random_numbers()
{
    srand(time(NULL));
}
bool toss_coin()
{   
    if(rand()%2==0)
    {
        //Head
        return true;
    }
    else
    {
        return false;
    }

}
class node
{
    public:
    int node_id;
    bool susceptible;
    bool infected;
    bool recovered;
    int infected_time;
    int recovered_time;


};

//suseptible set
static std::set<node*> S;
//Infected set
static std::set<node*> I;
//Recovered set
static std::set<node*> R;


//defines edges;
static int adjacency_matrix[100][100];

void generate_nodes(int no_of_nodes)
{
    for(int i=0;i<no_of_nodes;i++)
    {
        node* nd = new node;
        nd->node_id=i+1;
        S.insert(nd);
    }

}

void construct_graph()
{
    //generates new 100 nodes
    generate_nodes(100);
    //initially no nodes are connected
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            adjacency_matrix[i][j]=0;
        }
    }

    //tossing coin and coonecting nodes
    init_random_numbers();
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            if(j==i)
            {
                adjacency_matrix[i][j]=0;
            }
            if(j>i)
            {
                if(toss_coin())
                {
                    adjacency_matrix[i][j]=1;
                }

            }
            else if(i>j)
            {
                adjacency_matrix[i][j]=adjacency_matrix[j][i];
            }
        }
    }
}

int main()
{
    construct_graph();
    
    return 0;
}