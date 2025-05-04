#include <stdio.h>
#include <stdlib.h>

int elementCount(FILE *);
void fileNull(FILE *);
void writeArr(FILE *,int *,int);
void ptrNull(int *);
int simCount(int *,int *,int);

int main(){

    FILE *left =fopen("a.txt", "r");
    FILE *right = fopen("b.txt","r");
    fileNull(left);fileNull(right);

    int count = elementCount(left);
    int rightCount = elementCount(right);

    if (count!=rightCount){
        printf("Error reading the file");
        exit(1);
    }

    rewind(left); rewind(right);

    int *leftArr=(int *)malloc(sizeof(int)*count);
    int *rightArr=(int *)malloc(sizeof(int)*count);

    ptrNull(leftArr);ptrNull(rightArr);

    writeArr(left,leftArr,count);
    writeArr(right,rightArr,count);

    int results = simCount(leftArr,rightArr,rightCount);

     printf("\n%d",results);
 return 0;    
}

//count the elements in the file
int elementCount(FILE *fp){
 int input,count=0;  
 while (fscanf(fp,"%d",&input)==1)
 {
    count++;
 }
 return count;
}

//file null check
void fileNull(FILE *fp){
    if(fp==NULL){
        printf("Cannot access the file");
        exit (1);
    }
}

//pointer null check
void ptrNull(int *ptr){
    if(ptr==NULL){
        printf("Memort allocation failed.");
        exit (1);
    }
}

//read the files and write in to arrays
void writeArr(FILE *fp,int *arr,int count){

    for (int i = 0; i < count; i++)
    {
        fscanf(fp,"%d",&arr[i]);
    }
    
}

//calculate the similler count
int simCount(int *left,int *right,int count){
    int results=0;
    
    for(int i=0;i<count;i++){
        
        int simCount=0;

        for (int j = 0; j < count; j++){
            if(left[i] < right[j]){
                j++;
            }

            else if(left[i] > right[j]){
                i++;
            }

            else{
                simCount++;
            }
           if(left[i]==right[j]){
            results+=left[i]*simCount;
            }
        }
    }

    return results;
}
