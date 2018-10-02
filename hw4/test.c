int main(void)
{  int i;
   hashtable_t *table1, *table2, *table3;
   table1 = create_hash(1000);
   table2 = create_hash(10000);
   table3 = create_hash(100000);
   for( i=0; i< 2000; i++)
     insert_hash( table1, 2*i, 3*i+1);
   for( i=0; i< 4000; i++)
   { int f;
     f = find_hash(table1, i);
     if( i%2== 0)
     {  if( f != 3*(i/2)+1 )
	 {  printf("Test1 Error: key %d, value found %d, should be %d.\n",
		   i,f, 3*(i/2)+1 );
         }
     }
     else
     {  if( f!= 0 )  
	 {  printf("Test1 Error: key %d, value found %d, should be 0 (not found)\n",
		   i,f);
         }
     }
   }      
   printf("End Test1\n");
   for( i=0; i< 20000; i++)
   {  insert_hash( table2, 3*i, 2*i+1);
      insert_hash( table3, 5*i, 2*i+1);
   }
   for( i=1000; i< 20000; i++)
      delete_hash( table2, 3*i);
   for( i=0; i< 3000; i++)
   { int f;
     f = find_hash(table2, i);
     if( (i%3== 0) && ( f != 2*(i/3)+1 ) )
	printf("Test2 Error: key %d, value found %d, should be %d.\n",
		   i,f, 2*(i/3)+1 );
     if( (i%3!=0) && ( f!= 0 ) )  
        printf("Test2 Error: key %d, value found %d, should be 0 (not found)\n",
		   i,f);
   }
   for( i=3000; i< 60000; i++)
   {  if( find_hash(table2, i) != 0 )
         printf("Test2 Error: key %d found, should be not found\n",i);
   }
   printf("End Test2\n");
   for( i=0; i< 100000; i++)
   { int f;
     f = find_hash(table3, i);
     if( (i%5== 0) && ( f != 2*(i/5)+1 ) )
	printf("Test3 Error: key %d, value found %d, should be %d.\n",
		   i,f, 2*(i/5)+1 );
     if( (i%5!=0) && ( f!= 0 ) )  
        printf("Test3 Error: key %d, value found %d, should be 0 (not found)\n",
		   i,f);
   }
   printf("End Test3\n");



}
