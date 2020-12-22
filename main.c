#include <stdio.h>
#include <stdlib.h>

#include <stdint.h>
#include "tradingQ.h"
#include <assert.h>
#include <stdlib.h>

void test_list(){
    Slist s1= Slist_new();
    Slist *s = &s1;
    assert(s->count==0);
}

void test_customer(){
    Customer c1 = queue_new();
    Customer *c = &c1;
    assert(c->countc==0);
}

void test_enqueue(){
    Slist s1= Slist_new();
    Slist *s = &s1;
    assert(s->count==0);
    Customer c1 = queue_new();
    Customer *c = &c1;
    assert(c->countc==0);
    QueueResult res;
    Transaction t;
    c = enqueue(s,c,'priyanshu','22-10-12',1000,100,'TATA',&res,&t);
    assert(res.status==QUEUE_OK);
    c = enqueue(s,c,'priyanshu','22-10-12',4000,200,'INFO',&res,&t);
    assert(res.status==QUEUE_OK);
    c = enqueue(s,c,'priyanshu','22-10-12',3000,300,'ISRO',&res,&t);
    assert(res.status==QUEUE_OK);
    c = enqueue(s,c,'priyanshu','22-10-12',2000,400,'TATA',&res,&t);
    assert(res.status==QUEUE_OK);
    c = enqueue(s,c,'priyanshu','22-10-12',5000,500,'TATA',&res,&t);
    assert(res.status==QUEUE_OK);
    c = enqueue(s,c,'priyanshu','23-10-12',7000,700,'BHEL',&res,&t);
    assert(res.status==QUEUE_OK);
    assert(t.t_status=BUY);
}

void test_dequeue(){
    Slist s1= Slist_new();
    Slist *s = &s1;
    assert(s->count==0);
    Customer c1 = queue_new();
    Customer *c = &c1;
    assert(c->countc==0);
    QueueResult res;
    Transaction t;
    c = enqueue(s,c,'priyanshu','22-10-12',1000,100,'TATA',&res,&t);
    assert(res.status==QUEUE_OK);
    c=dequeue(s,c,&res,&t,'priyanshu',50);
    assert(res.status==QUEUE_OK);
    assert(res.quantity==50);
    assert(t.t_status=SELL);
    assert(t.quantity==50);
}

void test_lookup(){
    Slist s1= Slist_new();
    Slist *s = &s1;
    assert(s->count==0);
    Customer c1 = queue_new();
    Customer *c = &c1;
    assert(c->countc==0);
    QueueResult res;
    Transaction t;
    c = enqueue(s,c,'priyanshu','22-10-12',1000,100,'TATA',&res,&t);
    assert(res.status==QUEUE_OK);
    assert(lookup(s,c,'priyanshu')==1);


}
void test_topup(){
    Slist s1= Slist_new();
    Slist *s = &s1;
    assert(s->count==0);
    Customer c1 = queue_new();
    Customer *c = &c1;
    assert(c->countc==0);
    QueueResult res;
    Transaction t;
    c = enqueue(s,c,'priyanshu','22-10-12',1000,100,'TATA',&res,&t);
    assert(res.status==QUEUE_OK);
    c=topup(s,c,'priyanshu',20,'TATA',&res,&t);
    assert(res.status==QUEUE_OK);
    assert(res.quantity==120);
    assert(t.t_status==BUY);

}

int main()
{
    //test_list();
    //test_customer();
    //test_enqueue();
    //test_dequeue();
    //test_lookup();
    //test_topup();
    return 0;
}
