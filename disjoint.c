#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int parent[MAX];

void makeSet(int n){
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    printf("Sets are created \n");
}

int find(int x){
    if(parent[x]!=x){
        parent[x]=find(parent[x]);
    }
    return parent[x];
}

void unionSet(int x,int y){
    int rootX=find(x),rootY=find(y);
    if(rootX!=rootY){
        parent[rootX]=rootY;
        printf("Union done\n");
    }else{
        printf("They are already in the same set\n");
    }
}

void display(int n){
    for(int i=0;i<n;i++){
        printf("%d : %d\n",find(i),i);
    }
}

void main(){
    int ch, i, n, a, x, b;
    printf("Enter the number of disjoint sets you want :");
    scanf("%d",&n);
    makeSet(n);
    while(1){
        printf("\n*****Disjoint Set Operations*****\n");
        printf("1)Display Sets\n2)Find Set\n3)Union Sets\n4)Exit\n");
        printf("Enter your choice :");
        scanf("%d",&ch);
        switch(ch){
            case  1:
                display(n);
                break;
            case 2:
                printf("Enter the set you want to find: ");
                scanf("%d",&x);
                printf("%d's root is %d",x,find(x));

                break;
            case 3:
                printf("Enter the sets you want to union: ");
                scanf("%d %d",&a,&b);
                unionSet(a,b);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!!");
        }
    }

}