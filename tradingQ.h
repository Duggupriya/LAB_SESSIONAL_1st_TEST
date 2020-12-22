#ifndef TRADINGQ_H_INCLUDED
#define TRADINGQ_H_INCLUDED
#include <stdint.h>
#include "appconst.h"

typedef struct _slist_ Slist;
struct _slist_{
    int32_t count;
    Slist *head;
    Slist *tail;
    char* name;
};

typedef struct _node_ Node;
struct _node_{
    char* name;
    char* company_name;
    char* date;
    int32_t price;
    int32_t quantity;
    Node *next;
};

typedef struct _customer_ Customer;
struct _customer_{
    int32_t countc;
    Node *rear;
    Node *front;
    Customer* next;
};



typedef struct _queue_result_ QueueResult;
struct _queue_result_{
    int32_t quantity;
    uint8_t status;
};

typedef struct _transaction_ Transaction;
struct _transaction_{
    char* company_name;
    char* date;
    int32_t quantity;
    int32_t price;
    uint32_t t_status;
};

Customer queue_new();
Slist Slist_new();
Customer* enqueue(Slist* s,Customer *c,char* name,char* date,int32_t price,int32_t quantity,char* company_name,QueueResult *res, Transaction *t);
Customer* dequeue(Slist* s,Customer *c,QueueResult *res,Transaction *t,char* name,int32_t quantity);
Customer* topup(Slist* s,Customer *c,char* name,int32_t quantity,char* company_name,QueueResult *res,Transaction *t);
int32_t lookup(const Slist *s,const Customer* c,char *name);









#endif // TRADINGQ_H_INCLUDED
