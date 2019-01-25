#include <stdio.h>
#include <stdlib.h>

struct node_t {
    int data;
    struct node_t* next;
};

void
printlist(struct node_t* node)
{
    struct node_t* tmp = node;
    while (tmp) {
        printf("r[%p]->%d\n", tmp, tmp->data);
        tmp = tmp->next;
    }
}

void
pushdata(struct node_t** node, int data)
{
    struct node_t* tmp = *node;
    struct node_t* newnode = \
        (struct node_t*)malloc(sizeof(struct node_t));
    newnode->data = data;
    newnode->next = NULL;
    if (!*node)
        *node = newnode;
    else {
        while (tmp) {
            if (!tmp->next) {
                tmp->next = newnode;
                break;
            }
            tmp = tmp->next;
        }
    }
}

struct node_t* mergelist(struct node_t* p, struct node_t* q)
{
    struct node_t* r = NULL;
    struct node_t* pcur = p, *qcur = q;
    while (pcur && qcur) {
        if (pcur->data < qcur->data) {
            pushdata(&r, pcur->data);
            pcur = pcur->next;
        } else {
            pushdata(&r, qcur->data);
            qcur = qcur->next;
        }
    }
    while (pcur) {
        pushdata(&r, pcur->data);
        pcur=pcur->next;
    }
    while (qcur) {
        pushdata(&r, qcur->data);
        qcur=qcur->next;
    }
    return r;
}

void
main(void)
{
    struct node_t* p = NULL;
    struct node_t* q = NULL;
    struct node_t* r = NULL;
    pushdata(&p, 1);
    pushdata(&p, 2);
    pushdata(&p, 4);
    pushdata(&q, 1);
    pushdata(&q, 3);
    pushdata(&q, 4);
    r = mergelist(p, q);
    printlist(r);
}

