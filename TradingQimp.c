/*NAME: PRIYANSHU DUGAYA
  REG NO: 201046023


  "IMPLEMENTATION OF ALL THE NECESSARY FUNCTIONS"

*/

#include <stdint.h>
#include "tradingQ.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//CREATING A LIST OF ALL CUSTOMERS//
Slist Slist_new(){
    Slist s1= {NULL,0,NULL};
    return s1;
}

//CREATING QUEUE FOR EACH CUSTOMER//
Customer queue_new(){
    Customer c1 = {0,NULL,NULL,NULL};
    return c1;
}

//CREATING A NODE//
static Node* _get_new_node_(char* name,char* date,int32_t price,int32_t quantity,char* company_name){
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->name = name;
    newnode->company_name = company_name;
    newnode->date = date;
    newnode->price = price;
    newnode->quantity=quantity;
    newnode->next=NULL;
    return newnode;
}

//ENQUEUE NEW SHARE FOR A PERTICULAR CUSTOMER//
Customer* enqueue(Slist* s,Customer *c,char* name,char* date,int32_t price,int32_t quantity,char* company_name,QueueResult *res, Transaction *t){
    assert(s!=NULL && c!= NULL);
    //GOING THROUGH LIST OF CUSTOMERS AND ADDING AT HEAD//
    c->next = s->head;
    if(s->head==NULL){
        s->head = s->tail = c;
    }else{
        s->head = c;
    }


    //ENQUEUE THE NEW SHARES//
    Node *newnode = _get_new_node_(name,date,price,quantity,company_name);
    if(c->countc<MAX_SIZE){
        if(c->rear!=NULL){
        c->rear->next = newnode;
        c->rear = newnode;
        }else{
        c->rear = c->front = newnode;
    }

    }else if(c->countc == MAX_SIZE){         //IF QUEUE IS FULL DEQUEUE THE NODE AND ADD A NEWNODE//
        Node* temp;
        if(c->front!=NULL){
            temp=c->front;
            c->front = c->front->next;
            if(c->front==NULL){
                c->rear =NULL;
            }
            --c->countc;
            res->status = QUEUE_OK;
            free(temp);
        }else{
            res->status = QUEUE_FULL;
        }
        if(c->rear!=NULL){
        c->rear->next = newnode;
        c->rear = newnode;
        }else{
        c->rear = c->front = newnode;

    }

    }

    ++c->countc;
    ++s->count;
    res->status = QUEUE_OK;
    //STORING IN TRANSACTION STRUCTURE//
    t->company_name=company_name;
    t->date=date;
    t->price=price;
    t->quantity=quantity;
    t->t_status=BUY;
    return c;

}

//DEQUEUE THE SHARES FOR GIBEN NAME AND QUANTITY(Only last node)//
Customer* dequeue(Slist* s,Customer *c,QueueResult *res,Transaction *t,char* name,int32_t quantity){
    assert(s!=NULL && c!= NULL);
    Node *temp;
    Node *ctemp;
    temp=s->head;
    while(strcmp(temp->name,name)!=0){
        temp=temp->next;
    }
    if(c->front!=NULL){
        if(c->front->quantity==quantity){
                ctemp = c->front;
                c->front = c->front->next;
                if(c->front == NULL){
                    c->rear = NULL;
                }
        --c->countc;
        res->status = QUEUE_OK;
        free(ctemp);

        }else{
            c->front->quantity=(c->front->quantity) - quantity;
            res->status = QUEUE_OK;
            res->quantity = c->front->quantity;
        }
    }else{
        res->status = QUEUE_EMPTY;
    }
    t->company_name=c->front->company_name;
    t->date=c->front->date;
    t->price=c->front->price;
    t->quantity=c->front->quantity;
    t->t_status=SELL;


    return c;
}

//Looking for a customer having any shares in the list//
int32_t lookup(const Slist *s,const Customer* c,char *name){
    assert(c!=NULL && s!=NULL);
    Node *temp;
    Node *ctemp;
    temp=s->head;
    while(strcmp(temp->name,name)!=0){
        temp=temp->next;
    }
    return(temp!=NULL);
}

//adding new quantity for a particular customer given company name//
Customer* topup(Slist* s,Customer *c,char* name,int32_t quantity,char* company_name,QueueResult *res,Transaction *t){
    assert(s!=NULL && c!= NULL);
    Node *temp;
    Node *ctemp;
    temp=s->head;
    while(strcmp(temp->name,name)!=0){
        temp=temp->next;
    }
    ctemp = temp;
    while(strcmp(ctemp->company_name,company_name)!=0){
        ctemp = ctemp->next;
    }
    ctemp->quantity = (ctemp->quantity) + quantity;
    res->status =QUEUE_OK;
    //storing information in the transaction structure//
    res->quantity = ctemp->quantity;
    t->company_name=ctemp->company_name;
    t->date=ctemp->date;
    t->price=ctemp->price;
    t->quantity=ctemp->quantity;
    t->t_status=BUY;

    return c;
}




