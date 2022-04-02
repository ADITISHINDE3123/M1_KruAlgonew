/**
 * @file krumain.c
 * @author Aditi S
 * @brief Finds minimum cost of spanning tree using Krushal's Algorithm
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
int min, mincost = 0, ecost[9][9],par[9];
 
int findParent(int);
int uni(int, int);
 

/**
 * This is the  function that finds a subset of the edges that forms a tree that includes every vertex, where the total weight of all the edges in the tree is minimized.
 * Most of the cable network companies use  Kruskal's algorithm to find the shortest path to lay cables across a city or group of cities.
 * 
*/
void simplemain()
{
  printf("Kruskal's algorithm in C \n");
  
  printf("Enter the no. of vertices:\n");
  scanf("%d", &n);
 
  printf("\nEnter the cost adjacency matrix:\n");
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      scanf("%d", &ecost[i][j]);
      if (ecost[i][j] == 0)
        ecost[i][j] = 999;
    }
  }
 
  printf("The edges of Minimum Cost Spanning Tree are\n");
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
 
    ecost[a][b] = ecost[b][a] = 999;
  }
 
  printf("\nMinimum cost = %d\n", mincost);
  getch();
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
  if (i != j)
  {
    par[j] = i;
    return 1;
  }
 
  return 0;
}