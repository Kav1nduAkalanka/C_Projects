#include <stdio.h>
#include <stdlib.h>

void nullCheck(FILE*fp);
void ptrNullCheck(int *ptr);
void lowToHigh(int *arr,int count);
void writeToFile(FILE *fp,int *arr,int count);

int main(){

    FILE *fp = fopen("data.txt","r");
    nullCheck(fp);

    int l,r,count=0; 
 
 //count how many pairs are there
 while(fscanf(fp,"%d %d",&l,&r)==2){
        count++;
 }
 rewind(fp);

 //DMA
 int *left  = (int *)malloc(sizeof(int)*(count));
 int *right = (int *)malloc(sizeof(int)*(count));

 ptrNullCheck(left);
 ptrNullCheck(right);

 

 //load data into arrays
 while(fscanf(fp,"%d %d",&l,&r)==2){
      for(int i=0;i<count;i++){
            left[i]=l;
            right[i]=r;
        }
    }


    fclose(fp);

    lowToHigh(left,count);
    lowTohigh(right,count);

    FILE *lw = fopen("left.txt","w");
    FILE *rw = fopen("right.txt","w");

    writeToFile(lw,left,count);
    writeToFile(rw,right,count);
    
  
 return 0;   
}


//Check file pointer for null
void nullCheck(FILE *fp){    
if (fp==NULL){
    printf("cant access the file");
    exit (1);
}
}


//sort from lowest to highest
void lowToHigh(int *arr,int count){

    for(int i=0;i<count;i++){
        int min = arr[i];
         
        for(int j=i+1;j<count;j++){
            if (min>arr[j])
            {
                int temp= arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                

            }
            min=arr[i];
        }  
    }          
}

//write to the file and fclose and free memory
void writeToFile(FILE *fp,int *arr,int count){
    null_check(fp);
    for ( int i = 0; i <count ; i++){
        fprintf(fp,"%d\n",arr[i]);
    }

    fclose(fp);
    free(arr);
}


//pointer null check
void ptrNullCheck(int*ptr){    
    if (ptr==NULL){
        printf("Memory Assing failed");
        exit (1);
    }
}
    