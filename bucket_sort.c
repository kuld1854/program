#include <stdio.h>
#include <stdlib.h>
struct node{
   float data;
   struct node* next;
   struct node* prev; 
};
struct node* new_node(float key){
           struct node* temp = malloc(sizeof(struct node));
             temp->data = key;
             temp->next =  temp->prev = NULL;
             return temp;
}
void insert_sort(struct node* temp,struct node * p[]){
               
     if(temp->next == NULL)
         return;
     
        struct node * q = temp;
      temp = temp->next;
      while(temp!=NULL){
                       float key = temp->data;
                       q = temp->prev;
              while( q != NULL && key < q->data){
                    q->next->data = q->data;
                      q = q->prev;
                          }
           if(q!=NULL)
              q->next->data = key;
              else
                 p[(int)(key*10)]->data = key;
              temp =  temp->next;
             
      }

}
void sort_bucket(struct node* p[]){
    
   for(int i=0; i<10; i++){
       if(p[i]!= NULL)
            insert_sort(p[i],p);
   }

}
void make_bucket(float arr[],struct node* p[],int len){
    struct node* t;
   for(int i=0; i<len ; i++){
          struct node *temp  = new_node(arr[i]);
               int index = (int)(arr[i]*10);
               t = p[index];
               if(p[index] == NULL){
                    p[index] = temp;
                     continue;
               }
              while(t->next != NULL){
                   t = t->next;
              }
              temp->prev = t;
              t->next = temp;
 }
}
void print_sort(struct node *p[]){
  struct node * temp ;
  for(int i=0; i<10; i++){
        temp = p[i];
    while(temp!=NULL){
         printf("%f ",temp->data);
         temp = temp->next;
    }
  }
}
int main(){
  // int n;
  // scanf("%d ",&n);
   float arr[] = { 0.00,0.99,0.5,0.12,0.17,0.11,0.15,0.956,0.293};
 //  for(int i=0; i<n; i++)
   //   scanf("%d ",&arr[i]);
   struct node* p[10];
     for(int i=0; i<10; i++)
         p[i] = NULL;
    int len = sizeof(arr)/sizeof(arr[0]);
    
    make_bucket(arr,p,len);
   
    sort_bucket(p);
    print_sort(p);
}
