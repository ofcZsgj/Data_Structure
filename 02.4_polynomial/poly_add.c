#include <stdio.h>
#include <stdlib.h>

struct PolyNode{
    int coef;
    int expon;
    struct PolyNode* link;
};
typedef struct PolyNode* Polynomial;

//be careful: Segmentation fault: 11
void test(Polynomial* p){

    Polynomial temp = (Polynomial)malloc(sizeof(Polynomial));
    temp->coef = 9;
    temp->expon = 9;
    temp->link = NULL;

    //temp->link = NULL, (print NULL is error)
    Polynomial temp2 = (Polynomial)malloc(sizeof(Polynomial));
    temp->coef = 13;
    temp->expon = 13;
    temp->link = NULL;

    temp->link = temp2;

    (*p)->link = temp;  
    (*p) = temp;
    
}

int CompareExpon(int expon1, int expon2){

    if(expon1 > expon2){
        return 1;
    }
    else if(expon1 < expon2){
        return -1;
    }
    else{
        return 0;
    }

}

//Polynomial* is to modify rear
void Attach(int coef, int expon, Polynomial* rear){

    Polynomial p;
    p = (Polynomial)malloc(sizeof(Polynomial));
    if(!p){
        printf("Out Of Space\n");
        return;
    }

    p->coef = coef;
    p->expon = expon;

    (*rear)->link = p;
    (*rear) = p;

}

Polynomial PolyAdd(Polynomial p1, Polynomial p2){

    Polynomial temp, front, rear;
    rear = (Polynomial)malloc(sizeof(Polynomial));

    if(!rear){
        printf("Out Of Space\n");
        return NULL;
    }

    front = rear;

    while(p1 && p2){

        switch(CompareExpon(p1->expon, p2->expon)){

            case 1:{
                Attach(p1->coef, p1->expon, &rear);
                p1 = p1->link;
                break;
            }

            case -1:{
                Attach(p2->coef, p2->expon, &rear);
                p2 = p2->link;
                break;
            }

            case 0:{
                int sum = p1->coef + p2->coef;
                if(sum){
                    Attach(sum, p1->expon, &rear);
                }
                p1 = p1->link;
                p2 = p2->link;
                break;
            }

        }

    }

    for(; p1; p1 = p1->link){
        Attach(p1->coef, p1->expon, &rear);    
    }
    for(; p2; p2 = p2->link){
        Attach(p2->coef, p2->expon, &rear);
    }

    rear->link = NULL;
    temp = front;
    front = front->link;
    free(temp);

    return front;

}

int main(){

    Polynomial p, q;
    p = (Polynomial)malloc(sizeof(Polynomial));
    q = (Polynomial)malloc(sizeof(Polynomial));
    p->coef = 7;
    p->expon = 7;
    p->link = q;

    q->coef = 11;
    q->expon = 11;
    q->link = NULL;

    test(&p);

    printf("p->coef: %d, p->expon: %d\n", p->coef, p->expon);
    printf("p->link->coef: %d, p->link->expon: %d\n", p->link->coef, p->link->expon);

    return 0;
}