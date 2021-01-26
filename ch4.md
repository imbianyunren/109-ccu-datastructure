# ch4 
1. inverts a single link list
```c
typedef struct listNode *listPointer;
typedef struct listNode{
    char data;
    listPointer link;
}

listPointer invert (listPointer lead){
    listPointer middle,trail;
    middle=NULL;
    while(lead){
        trail=middle;
        middle=lead;
        lead=lead->link;
        middle->link=trail;
    }
    return middle;
}
```
2. Write a function that concatenate two circular link list A and B to one circular link list C
```c
listPointer concatenate(listPointer A,listPointer B){
  listPointer temp,C;
  /* check for empty lists */
  if (! A) return B;
  if (! B) return A;
  /* neither list is empty, find end of first list */
  C=A;
  for (temp=A;temp->link;temp=temp->link);
  /* link end of first to start of second */
  temp->link = B;
  for (temp=B;temp->link;temp=temp->link);
  temp->link = A;
  return C;
}
```
3. Rewrite delete so that it uses only two pointers, first and trail.
```c 
void delete(listPointer *first, listPointer trail)
{/* delete x from the list, trail is the preceding node and *first is 
    the front of the list */
    if (trail)
        trail->link = trail->link->link;
    else
        *first = (*first)->link;
    free(x);
}
```
4. Create a function that searches for an integer, num.
```c
listPointer find(listPointer *first, int num)
{
    listPointer temp=first;
    while(temp){
        if(temp->data == num) return temp;
        temp=temp->link;
    }
    return NULL;
}
```
5. Write a function, length, that returns the number of nodes in a list
```c
int length(listPointer list)
{
    int cnt=0;
    listPointer temp=list;
    while(temp){
        cnt++;
        temp=temp->link;
    }
    return cnt;
}
```
6. Write a function, pread, that reads in n pairs of coefficients and exponents
```c
PolyPointer pread()
{/*read the polynomial into a chain */
  PolyPointer front, rear,temp;
  float coefficient;
  int exponent;
  front=rear=NULL;
  scanf("%f,%d",&coefficient,&exponent);
  while (exponent >= 0) {
     temp = (PolyPointer)malloc(sizeof(struct PolyNode));
     temp->coef =  coefficient;
     temp->expon = exponent;
     temp->link = NULL;
     if (!front) front = temp;
     else rear->link = temp;
     rear = temp;
     scanf("%f,%d",&coefficient,&exponent);
     }
     return front;
}
```
7. Write a function, peval, to evaluate the polynomial a at point x, where x is some floating point number.
```c
float peval(float x, PolyPointer a)
{/*evaluate the polynomial at point x */
  PolyPointer temp;
  float result = 0;
  for (temp = a; temp; temp= temp->link) 
    result = result + temp->coef * pow(x,temp->expon);
  return result;
}
```
8. Rewrite Exercise 6 using a circular representation for the polynomial
```c
PolyPointer ReadPoly()
{/*read in the polynomial */
  PolyPointer node,c;
  float coefficient;
  int exponent;
  node = GetNode();
  node->coef = -1.0;
  node->expon = -1;
  node->link = node;
  scanf("%f,%d",&coefficient,&exponent);
  while (exponent >= 0) {
     c = GetNode();
     c->coef =  coefficient; 
     c->expon = exponent;
     c->link = node->link;
     node->link = c;
     scanf("%f,%d",&coefficient,&exponent);
	}
  return node;
}
```
9. Write a function that deletes a node containing a number, num, from a circularly linked list. 
```c
void delete(listPointer first, int num)
{
    listPointer temp;
    if(first!=NULL) {
        temp=first;
        do{
            if(temp->data == num) {
                temp->link=temp->link->link;
            }
            temp=temp->link;
        }while(temp!=first)
    }
}
```