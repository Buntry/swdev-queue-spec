//lang::CwC
#import "object.h"
#import "string.h"
#import "queue.h"
#include <stdio.h>


void FAIL() { exit(1); }

void OK(const char *m) { printf("OK: %s\n", m); }

void t_true(bool p) { if (!p) FAIL(); }

void t_false(bool p) { if (p) FAIL(); }

void test_empty_queue() {
    Queue* q = new Queue();
    t_true(q->len() == 0);

    delete q;
    OK("test_empty_queue")
}

void test_basic_push_len() {
    String *s = new String("Hello");
    String *t = new String("World");

    Queue* q = new Queue();
    t_true(q->len() == 0);

    q->push(s);
    t_true(q->len() == 1);

    q->push(t);
    t_true(q->len() == 2);


    delete s;
    delete t;
    delete q;

    OK("test_basic_push_len");
}

void test_push_pop() {
    String *s = new String("Hello");
    String *t = new String("World");

    Queue* q = new Queue();
    t_true(q->len() == 0);

    q->push(s);
    t_true(q->len() == 1);

    t_true(q->peek()->equals(s));

    t_true(q->pop()->equals(s));

    q->push(t);
    t_true(q->len() == 1);
    t_true(q->peek()->equals(t));


    delete s;
    delete t;
    delete q;

    OK("test_push_pop");
}

void test_multi_push_pop() {
    String *s = new String("Hello");
    String *t = new String("World");
    String *u = new String("!");

    Queue* q = new Queue();
    t_true(q->len() == 0);

    q->push(s);
    t_true(q->len() == 1);
    t_true(q->peek()->equals(s));

    q->push(t);
    t_true(q->len() == 2);
    t_true(q->peek()->equals(s));
    t_true(q->pop()->equals(s));
    t_true(q->peek()->equals(t));

    t_true(q->pop()->equals(t));
    t_true(q->len() == 0);

    q->push(s);
    t_true(q->pop()->equals(s));
    t_true(q->len() == 0);
    q->push(s);
    t_true(q->pop()->equals(s));
    q->push(s);
    t_true(q->len() == 1);
    t_true(q->pop()->equals(s));
    q->push(s);
    t_true(q->pop()->equals(s));
    t_true(q->len() == 0);

    q->push(s);
    q->push(t);
    q->push(u);
    t_true(q->len() == 3);
    t_true(q->peek()->equals(s));
    t_true(q->pop()->equals(s));
    q->push(s);
    t_true(q->len() == 3);
    t_true(q->peek()->equals(t));
    t_true(q->pop()->equals(t));
    q->push(t);
    t_true(q->len() == 3);
    t_true(q->peek()->equals(u));

    delete s;
    delete t;
    delete u;
    delete q;

    OK("test_multi_push_pop");
}

void test_very_complex_queue_of_queues() {
    String *s = new String("Hello");
    String *t = new String("World");

    Queue* q = new Queue();
    t_true(q->len() == 0);

    q->push(s);
    t_true(q->len() == 1);

    t_true(q->pop()->equals(s));
    t_true(q->len() == 0);

    q->push(t);
    t_true(q->len() == 1);

    Queue* p = new Queue();
    t_true(p->len() == 0);

    p->push(s);
    t_true(p->len() == 1);

    t_true(p->pop()->equals(s));

    p->push(t);
    t_true(p->len() == 1);

    t_true(q->equals(p));
    t_true(q->hash() == p->hash());

    q->push(p);

    t_true(q->len() == 2);
    t_true(q->peek()->equals(t));
    t_true(q->len() == 2);
    t_true(q->pop()->equals(t));
    t_true(q->len() == 1);
    t_true(q->pop()->equals(p));
    t_true(q->len() == 0);

    delete s;
    delete t;
    delete q;
    delete p;

    OK("test_push_pop");
}




int main() {
    test_empty_queue();
    test_basic_push_len();
    test_push_pop();
    test_multi_push_pop();
    test_very_complex_queue_of_queues();
    OK("SUCESS!");
    return 0;
}
