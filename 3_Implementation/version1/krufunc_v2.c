/**
 * @file krufunc_v2.c
 * @author Aditi S
 * @brief Finds minimum cost of spanning tree using Krushal's Algorithm - It has all the code in functions and are called from the automated test file
 * @version 1.0
 * @date 2022-04-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
 
int i, j, a, b, u, v, n, ne = 1;
int min, mincost,par[9];
int flag[9]; 

int findParent(int);
int uni(int, int);

/**
 * @brief This is the  function that finds a subset of the edges that forms a tree that includes every vertex, where the total weight of all the edges in the tree is minimized.
 * 
 * @param in_n n The no.of vertices in the graph
 * @param in_ecost ecost The cost adjacency matrix
 * @return int  Returns the minimum cost of the spanning tree
 */
int krucal(int n,int ecost[][n])
{
  mincost = 0 ;
   
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      printf("%d ", ecost[i][j] );
       if (ecost[i][j] == 0)
        ecost[i][j] = 999;
    }
    printf("\n ");
  }
 
  while (ne < n)
  {
    for (i = 0, min = 999; i < n; i++)
    {
      for (j = 0; j < n; j++)
      {
        if (ecost[i][j] < min)
        {
          min = ecost[i][j];
          a = u = i;
          b = v = j;
        }
      }
    }
    u = findParent(u);
    v = findParent(v);
   
    if (uni(u, v))
    {
     printf("%d edge (%d,%d) =%d\n", ne++, a, b, min);
      mincost += min;
    }
    ecost[a][b] = ecost[b][a] = 999; // the edge i.e added,its cost set to max
  }
  printf("\nMinimum cost = %d\n", mincost);
  return mincost ; 
}



/**
 * @brief This function returns parent of vertex i
 * 
 * @param in_i i The vertex no
 * @return int  Returns the parent vertex of vertex i
 */
int findParent(int i)
{
  while (par[i])
     i = par[i];
  return i;
}
 
 /**
 * @brief This function makes i as the parent of j
 * 
 * @param in_i i The parent vertex no
 * @param in_j j The vertex who parent is i
 * @return int  Returns 1 if there is an edge from vertex i to j
 */
int uni(int i, int j)
{
  // Check if the selected edge is creating a cycle or not
  if (i != j /* && flag[j] ==0 */ )   //Consider only that vertex whose parent not set yet
  {
    par[j] = i ;  
    // flag[j] = 1 ;
    return 1;
  }
   return 0;
}

void manual_test_krucal()
{
     // test1 - for Graph with 5 vertices and 6 edges ,mincost should be 11
    int n=5;
    int cost[5][5] = {{0,0,2,1,0}, {0,0,5,0,0}, {2,5,0,0,3}, {1,0,0,0,0}, {0,0,3,0,0}};

    if(11 == krucal(n,cost))
        printf("Krucal function is working for another graph with 5 vertices and 6 edges \n");
    else 
        printf("Krucal function is not working \n");
  
    // test2 - for Graph with 4 vertices and 5 edges ,mincost should be 3
    int n1=4;
    int cost1[4][4] = {{0,1,4,3}, {1,0,0,2}, {4,0,0,5},{3,2,5,0}};

    // for second test it should take flag array as commented in code 
    if(7 == krucal(n1,cost1))
        printf("Krucal function is working for another graph with 4 vertices and 5 edges \n");
    else 
        printf("Krucal function is not working for 4 vertices \n");
  
        
}