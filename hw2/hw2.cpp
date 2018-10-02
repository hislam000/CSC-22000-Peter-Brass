
//Course: CSc 220-Algorithms
//Project1: hw2.cpp 
//Name: Hasibul Islam
//Date: 10/25/2017

void depth_distribution(tree_node_t *tree,int depth,int *data){
        if(tree->left== NULL){  printf("Tree empty\n"); }
       else if( tree->right == NULL ) { data[depth]++;  }
        else{
            depth_distribution(tree->left,depth+1,data);
            depth_distribution(tree->right,depth+1,data);
        }
    }  
void depth_distribution(tree_node_t *tree){ 
     //BLOCKSIZE and  depth_distribution [Given in test file]
     //int data[BLOCKSIZE]={0}; 
     int data[(BLOCKSIZE)+1]={0};
     depth_distribution(tree,0,data); 
     int total;  total=0; int j; int i;
    //array
     for(j=0; j<=tree->height; ++j){
         //add no of leaf to total
         total+=data[j]; }
     printf("The tree has %d leaves\n",total);
     printf("  Depth          Leaves\n");
     //array
     for(j=0; j<=tree->height; ++j){
         //print both depth and no of leaf
         printf("    %d              %d\n",i,data[j]); 
         ++i;
        }
    }
 
