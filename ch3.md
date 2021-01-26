# CH3

##### 1.queueFull && queueEmpty noncircular:

queue_head 為 queue 存放起始位置
queue_tail 為 queue 存放尾端

Queue full:

```c
Boolean isfull(int * queue_tail){
  if (*queue_tail > MAX_QUEUE_SIZE)
 	return True;
	else return False;
}
```

Queue empty:

```c
Boolean isempty(int *queue_head){
     if (*queue_head == NULL)
	return True;
	else return False;
}
```

##### 2.queueFull && queueEmpty circular:
```c
Boolean isfull(int * queue_tail, const int queue_head){
  if ((*queue_tail + 1) % MAX_SIZE == queue_head)
 	return True;
	else return False;
}
```
```c
Boolean isempty(int *queue_head,int queue_tail){
     if (*queue_head == NULL || *queue_head==queue_tail)
	return True;
	else return False;
}
```
##### 3.enqueue(add) and Dequeue(delete) functions in noncircular:

```c	
void push_queue(int * queue, int * queue_tail, const int data)
{
  if(isfull(*queue_tail)) {
    queue[*queue_tail] = data
    (*queue_tail) += 1;
  }
	else return;
}

int pop_queue(int * queue, int * queue_head, const int queue_tail)
{
    if(isempty(queue_head)) return -1; //return error num
 
    int data;
    data = queue[(*queue_head)];
    (*queue_head) += 1;
 
    return data;
}
```

##### 4. Write the postfix from of the following expressions : 
(a) a * b * c  >>  a b * c *
(b) *a + b * c + d  >>  -a b + c - d + 
(c) a * -b + c  >> a -b * c + 
(d) (a + b) * d + e/(f + a * d) + c  >> a b + d * e f a d * + / + c +

##### 5. a stack and a queue in an array
```c
top=-1
front=-1
push(element item) {
  memory[++top] = item;
}
pop(element item){
  return memory[top--];
}
delete(element item){
  return memory[++front];
}
```

##### 6. two stacks in an array
```c
#include <stdio.h>
#define SIZE 10
 
 
int ar[SIZE];
int top1 = -1;
int top2 = SIZE;
 
//Functions to push data
void push_stack1 (int data)
{
  if (top1 < top2 - 1)
  {
    ar[++top1] = data;
  }
  else
  {
    printf ("Stack Full! Cannot Push\n");
  }
}
void push_stack2 (int data)
{
  if (top1 < top2 - 1)
  {
    ar[--top2] = data; 
  }
  else
  {
    printf ("Stack Full! Cannot Push\n");
  }
}
 
//Functions to pop data
void pop_stack1 ()
{
  if (top1 >= 0)
  {
    int popped_value = ar[top1--];
    printf ("%d is being popped from Stack 1\n", popped_value);
  }
  else
  {
    printf ("Stack Empty! Cannot Pop\n");
  }
}
void pop_stack2 ()
{
  if (top2 < SIZE)
  {
    int popped_value = ar[top2++];
    printf ("%d is being popped from Stack 2\n", popped_value);
  }
  else
  {
    printf ("Stack Empty! Cannot Pop\n");
  }
}
```

##### 7. 


##### 8. transforms a infix expression into a postfix one.

(1) abc - d + /ea - *c*(Set a = 2, b = 3, c = 4, d = 5, e = 6)
=> a/(b-c+d) * (e-a) * c = -8

(2) +*+ABC*+*D*E + DE* ABC(Set A = 1, B = 2, C = 3, D = 4, E = 5)
=> A*(B+C)+[(D+E)*D*E+(A*B)]*C = 5+(9*4*5+(1*2))*5=5+(180+2)*5=915