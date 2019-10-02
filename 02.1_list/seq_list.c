#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 10

typedef struct seq_list* Seq_List;
struct seq_list{   
    int data[MAXSIZE];
    int last;
};

Seq_List MakeEmpty(Seq_List sl){

    if(!sl){
        sl = (Seq_List)malloc(sizeof(Seq_List));
        sl->last = -1;
        memset(sl->data, 0, sizeof(sl->data));
        return sl;
    }
    else{
        memset(sl->data, 0, sizeof(sl->data));
        sl->last = -1;
        return sl;
    }

}

//postion [1 , (MAXSIXE-1)]
void Insert(Seq_List sl, int data, int postion){
printf("last = %d", sl->last);
    if(!sl || postion <= 0 || postion > MAXSIZE){
        return;
    }

    for(int i = MAXSIZE; i > postion; --i){

        sl->data[i] = sl->data[i-1];

    }

    sl->data[postion - 1] =  data;
    sl->last++;
    

}

int Find(Seq_List sl, int data){

    if(!sl){
        return -1;
    }

    for(int i = 0; i <= sl->last; ++i){
        if(sl->data[i] == data){
            return i;
        }
    }

    return -1;

}

int Delete(Seq_List sl, int postion){

    if(!sl || postion <= 0 || postion > sl->last){
        return -1;
    }

    for(int i = postion-1; i <= sl->last; ++i){
        sl->data[i] = sl->data[i+1];
    }

    --(sl->last);
    return 0;

}

int main(){
    Seq_List sl = MakeEmpty(sl);

    Insert(sl, 17, 1);
    Insert(sl, 19, 2);
    Insert(sl, 21, 3);
    for(int i = 0; i < MAXSIZE; ++i){
        printf("%d\t", sl->data[i]);
    }
    printf("last = %d", sl->last);
    int pos = Find(sl, 21);
    printf("\npostion: %d\n", pos);

    Delete(sl, 1);
     for(int i = 0; i < MAXSIZE; ++i){
        printf("%d\t", sl->data[i]);
    }

    return 0;
}