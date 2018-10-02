//Course: CSc 220-Algorithms
//Project1: hw3.cpp 
//Name: Hasibul Islam
//Date: 11/20/2017

#include <iostream>
#include <queue>
#include<stdlib.h>
#include <stdio.h>
using namespace std;
      
bool bfs(int *capacity, int s, int t, int n, int path[]){
	
  bool *v_visited = new bool[n];
  
  int i; int j;
  int num_vertex;

        //un(v_visted) all vertices 
    for(i = 0; i < n; i++)  
              v_visited[i] = 0;
        
        //bfs going to find if the path exist
                queue <int> v_queue;
                v_queue.push(s);
                v_visited[s] = true;
                path[s] = -1;

	  while(!v_queue.empty()){
		
            num_vertex = v_queue.front();
            v_queue.pop();

    for(j = 0; j < n; j++){
          
    if( v_visited[j] == false && *(capacity + num_vertex *n + j) > 0){
                
                v_queue.push(j);
                path[j] = num_vertex;
                v_visited[j] = true;
              }
            }
          }
      return (v_visited[t] == true);    
    }


static int res_capacity[1000][1000];

//Ford-Fulkerson algorithm 
void maximum_flow(int n, int s, int t, int *capacity, int *flow){

        int i; int j;
        int m_flow = INT_MAX;
        int *path_flow = new int[n]; 
        
        for (i = 0; i < n; i++)
        for (j = 0; j < n; j++){ 
        
          res_capacity[i][j] = *(capacity + i * n + j);
    }  
		
  while (bfs(&(res_capacity[0][0]), s, t, n, path_flow) == true){	

          for (j = t; j != s; j = path_flow[j]) {
                i = path_flow[j];

            m_flow = min(m_flow, res_capacity[i][j]);
      }
            
        for (j = t; j != s; j = path_flow[j]){
                  i = path_flow[j];
              
              *(flow + path_flow[j] * n + j) += m_flow;
              res_capacity[path_flow[j]][j] -= m_flow;
              res_capacity[j][path_flow[j]] += m_flow;
                }
            }

        }
