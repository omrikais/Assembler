#include <stdio.h>
#include "List.h"
/*Created by Omri Kaisari on 05/08/2020.*/
 int main()
 {
     struct Node *start = NULL;
     unsigned floatSize = sizeof(float);
     /* Create and print an int linked list*/
     unsigned intSize = sizeof(int);
     int arr[] = {10, 20, 30, 40, 50}, i;
     float arr2[] = {10.1, 20.2, 30.3, 40.4, 50.5};
     for (i=4; i>=0; i--)
         push(&start, &arr[i], intSize);
     printf("Created integer linked list is \n");
     printList(start, printInt);
     /* Create and print a float linked list*/
     start = NULL;
     for (i=4; i>=0; i--)
         push(&start, &arr2[i], floatSize);
     printf("\n\nCreated float linked list is \n");
     printList(start, printFloat);
    
     return 0;
 }
