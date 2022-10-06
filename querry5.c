#include <stdio.h>
#include <stdlib.h>
# define SIZE 100
void enqueue();
void dequeue();
void show();
void search();
void sort();
void reverse();
void priority();
void enqueue_P();
void dequeue_P();
void display();
void circular();
void enQueue_C();
void display_C();
void deQueue_C();
int inp_arr[SIZE];
int prior_arr[SIZE];
int Rear = - 1;
int Front = - 1;
int prior = 0;
int main()
{
    int ch;
    while (1)
    {
        printf("1.Enqueue Operation\n");
        printf("2.Dequeue Operation\n");
        printf("3.Display the Queue\n");
        printf("4.Search for a value in the Queue\n");
        printf("5.Sort the Queue\n");
        printf("6.Reverse the Queue\n");
        printf("7.priority Queue\n");
	printf("8.Circular Queue\n");
        printf("9.Exit\n");
        printf("Enter your choice of operations : ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
            enqueue();
            break;
            case 2:
            dequeue();
            break;
            case 3:
            show();
            break;
            case 4:
            search();
            break;
            case 5:
            sort();
            printf("The Queue is sorted");
            break;
            case 6:
            reverse();
            break;
            case 7:
            priority();
            break;
            case 8:
            circular();
	    break;
            case 9:
            exit(0);
            default:
            printf("Incorrect choice \n");
        }
    }
    return 0;
}

void enqueue()
{
    int insert_item;
    int insert_prior;
    if (Rear == SIZE - 1)
       printf("Overflow \n");

    else
    {
        if (Front == - 1)

        Front = 0;
        printf("Element to be inserted in the Queue\n : ");
        scanf("%d", &insert_item);
        Rear = Rear + 1;
        inp_arr[Rear] = insert_item;
    }
}

void dequeue()
{
    if (Front == - 1 || Front > Rear)
    {
        printf("Underflow \n");
        return ;
    }
    else
    {
        printf("Element deleted from the Queue: %d\n", inp_arr[Front]);
        Front = Front + 1;
    }
}

void show()
{

    if (Front == - 1)
        printf("Empty Queue \n");
    else
    {
        printf("Queue: \n");
        for (int i = Front; i <= Rear; i++)
            printf("%d ", inp_arr[i]);
        printf("\n");
    }
}

void search(){
    int num;
    printf("Write the value you searching for: ");
    scanf("%d",&num);
    for(int x = Front;x<=Rear;x++){
        if(num == inp_arr[x]){
            printf("Value found, It's in the position number: %d\n",x);
            break;
        }
        else if(x == Rear)
        {
            printf("your number couldn't be found");
        }
    }
    }

void sort(){
    int temp;
    for(int i = Front;i<=Rear;i++){
        for(int x = i+1;x<=Rear;x++){
            if(inp_arr[i]< inp_arr[x]){
                temp = inp_arr[i];
                inp_arr[i] = inp_arr[x];
                inp_arr[x] = temp;
            }
        }
    }
}

void reverse(){
    int temp;
    for(int x = 0;x<Rear/2;x++){
        temp = inp_arr[x];
        inp_arr[x] = inp_arr[Rear-x];
        inp_arr[Rear-x] = temp;
    }
    printf("The Queue has been reversed");

}

void priority(){
        while(Rear != -1){
            dequeue();
        }
        int ch;
        while(1){
        printf("1.Enqueue elememt\n");
        printf("2.dequeue element\n");
        printf("3.dequeue element with highest priority\n");
        printf("4.display Queue\n");
        printf("5.Exit\n");
        printf("Enter your choice of operations : ");
        scanf("%d", &ch);
        switch(ch){
        case 1:
        enqueue_P();
        break;
        case 2:
        dequeue();
        break;
        case 3:
        dequeue_P();
        break;
        case 4:
        display();
        break;
        case 5:
        exit(0);
        default:
        printf("Incorrect choice \n");
        }
        }

}


int peek()
{
    int maxPriority = 0;
    int indexPos = -1;

    for (int i = 0; i <= Rear; i++) {

        if (maxPriority == prior_arr[i] && indexPos > -1 && inp_arr[indexPos] < inp_arr[i])
        {
            maxPriority = prior_arr[i];
            indexPos = i;
        }

        else if (maxPriority < prior_arr[i]) {
            maxPriority = prior_arr[i];
            indexPos = i;
        }
    }

    return indexPos;
}

void enqueue_P(){
    int insert_item;
    int insert_prior;
    printf("Element to be inserted in the Queue\n : ");
    scanf("%d", &insert_item);
    Rear += 1;
    inp_arr[Rear] = insert_item;
    printf("Priority of the element\n:");
    scanf("%d", &insert_prior);
    prior_arr[Rear] = insert_prior;
}

void dequeue_P()
{
    if(Rear != -1)
    {

        int indexPos = peek();

        for (int i = indexPos; i < Rear; i++) {
            inp_arr[i] = inp_arr[i + 1];
            prior_arr[i] = prior_arr[i + 1];
        }

        Rear--;
    }
}

void display(){
    for (int i = 0; i <= Rear; i++) {
        printf("(%d, %d)\n",inp_arr[i], prior_arr[i]);
    }
}

void circular(){
    int ch;
    while(1){
        printf("1.enqueue an element\n");
        printf("2.dequeue\n");
        printf("3.display queue\n");
        printf("4.exit\n");
        printf("Enter your choice of operations : ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
            enQueue_C();
            break;
            case 2:
            deQueue_C();
            break;
            case 3:
            display_C();
            break;
            case 4:
            exit(0);
            default:
            printf("Incorrect choice \n");
        }
    }
}

void enQueue_C() {
    int element;
  if (isFull())
    printf("\n Queue is full!! \n");
  else {
    printf("Element to be inserted in the Queue\n : ");
    scanf("%d", &element);
    if (Front == -1) Front = 0;
    Rear = (Rear + 1) % SIZE;
    inp_arr[Rear] = element;
    printf("\n Inserted -> %d\n", element);
  }
}

void deQueue_C() {
  int element;
  if (isEmpty()) {
    printf("\n Queue is empty !! \n");
  } else {
    element = inp_arr[Front];
    if (Front == Rear) {
      Front = -1;
      Rear = -1;
    }

    else {
      Front = (Front + 1) % SIZE;
    }
    printf("\n Deleted element -> %d \n", element);
  }
}

void display_C() {
  int i;
  if (isEmpty())
    printf(" \n Empty Queue\n");
  else {
    printf("\n Front -> %d ", Front);
    printf("\n Items -> ");
    for (i = Front; i != Rear; i = (i + 1) % SIZE) {
      printf("%d ", inp_arr[i]);
    }
    printf("%d ", inp_arr[i]);
    printf("\n Rear -> %d \n", Rear);
  }
}
int isFull() {
  if ((Front == Rear + 1) || (Front == 0 && Rear == SIZE - 1)) return 1;
  return 0;
}

int isEmpty() {
  if (Front == -1) return 1;
  return 0;
}
