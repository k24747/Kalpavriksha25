/*
Problem Statement: Railway Ticket Counter Simulation
A railway station has a ticket counter that serves passengers based on the following priority levels:
VIP – People with special privileges (served first).
SENIOR_CITIZEN – Elderly passengers (served after VIPs).
GENERAL – Regular passengers (served last, FIFO order).
Each passenger has:
 
A passenger ID (integer).
A passenger type (enum: VIP, SENIOR_CITIZEN, GENERAL).
A name (string, max 50 characters).

Requirements:
1. Implement a ticket counter queue system that processes passengers based on the priority:
VIP passengers should be served first.
Then senior citizens.
Finally, general passengers (FIFO order).
2. Implement a menu Driven program : 
       1- enqueue -> Add a passenger to the queue
       2- dequeue -> Serve the next passenger
       3- displayQueue -> Display all waiting passenger
 
3. Use enum to define passenger categories.
4. Implement a queue (use an array to implement your sorted structures).
5. The first line of input has the number of operations to be performed (N).
 
Sample Input:
9
1,101, GENERAL, "Alice";
1,102, VIP, "Bob";
1,103, SENIOR_CITIZEN, "Charlie";
1,104, GENERAL, "David";
2
3
2
2
3
 
Sample Output:
Serving Passenger: ID 102, Name: Bob, Type: VIP

Waiting Passengers:
ID 103, Name: Charlie, Type: SENIOR_CITIZEN
ID 101, Name: Alice, Type: GENERAL
ID 104, Name: David, Type: GENERAL
 
Serving Passenger: ID 103, Name: Charlie, Type: SENIOR_CITIZEN
Serving Passenger: ID 101, Name: Alice, Type: GENERAL
 
Waiting Passengers:
ID 104, Name: David, Type: GENERAL
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum priority{ VIP, SENIOR_CITIZEN, GENERAL };

typedef struct Passeneger{
    int id;
    char name[50];
    enum priority prio;
}Passeneger;

typedef struct PriorityQueue{
    Passeneger *queue;
    int capacity;
    int size;
    int rear;
    int front;
}PriorityQueue;

const char* getStringFromEnum(enum priority pri){
    if(pri == VIP){
        return "VIP";
    }else if(pri == SENIOR_CITIZEN){
        return "SENIOR_CITIZEN";
    }else if(pri == GENERAL){
        return "GENERAL";
    }
}

enum priority getEnumFromString(char *pri){
    if(strcmp(pri, "VIP") == 0){
        return VIP;
    }else if(strcmp(pri, "SENIOR_CITIZEN") == 0){
        return SENIOR_CITIZEN;
    }else{
        return GENERAL;
    }
}

void init(PriorityQueue *pq){
    pq->capacity = 1;
    pq->size = 0;
    pq->queue = (Passeneger *)malloc(pq->capacity * sizeof(Passeneger));
}

void resize(PriorityQueue *pq){
    pq->capacity *= 2;
    pq->queue = (Passeneger *)realloc(pq->queue, pq->capacity * sizeof(Passeneger));
}

void enqueue(PriorityQueue *pq, int id, char *pri, char *name){
    if(pq->size == pq->capacity){
        resize(pq);
    }
    Passeneger newPassenger;
    newPassenger.id = id;
    newPassenger.prio = getEnumFromString(pri);
    strcpy(newPassenger.name, name);
    int i = pq->size-1;
    while(i >= 0 && pq->queue[i].prio > newPassenger.prio){
        pq->queue[i+1] = pq->queue[i];
        i--;
    }
    pq->queue[i+1] = newPassenger;
    pq->size++;
}

void dequeue(PriorityQueue *pq){
    printf("Serving Passenger: ID %d, Name: %s, Type: %s\n", pq->queue[0].id, pq->queue[0].name, 
    getStringFromEnum(pq->queue[0].prio));
    for(int i = 1; i < pq->size; i++){
        pq->queue[i-1] = pq->queue[i];
    }
    pq->size--;
}

void display(PriorityQueue *pq){
    printf("Waiting Passengers:\n");
    for(int i = 0; i < pq->size; i++){
        printf("ID %d, Name: %s, Type: %s\n", pq->queue[i].id, pq->queue[i].name, 
        getStringFromEnum(pq->queue[i].prio));
    }
}

int main(){
    PriorityQueue pq;
    init(&pq);
    int operations, choice;
    scanf("%d", &operations);

    for(int i = 0; i < operations; i++){
        scanf("%d", &choice);
        if(choice == 1){
            int pId;
            char name[51]; 
            char passengerType[15];
            scanf(",%d, %[^,], \"%[^\"]\";", &pId, passengerType, name);     
            enqueue(&pq, pId, passengerType, name);
        }else if(choice == 2){
            dequeue(&pq);
        }else if(choice == 3){
            display(&pq);
        }
    }

    free(pq.queue);
    return 0;
}