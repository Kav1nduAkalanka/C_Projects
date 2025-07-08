#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void isFileNull(FILE *fp);
int safeReports(FILE *fp);

int main(){

    FILE *fp = fopen("input.txt","r");
    isFileNull(fp);
    int safe = safeReports(fp);
    printf("safe reports: %d",safe);

    fclose(fp);



 return 0;   
}

//check filepointer for null
void isFileNull(FILE *fp){
    if(fp==NULL){
        printf("Cannot access the file.");
        exit(1);
    }
}



int safeReports(FILE *fp){
    char *line = NULL;
    size_t length = 0;
    __ssize_t lineRead;
    int reports;

    while ((lineRead = getline(&line,&length,fp))!=-1){
        if (line[length-1]=='\n'){
            line[length-1]=='\0';
            length--;
        }
        
        //token the line
        int *numbers=NULL;
        size_t numberSize=0; //size of the current buffer
        size_t numberCount=0; // number of elements that counted
        char *token=strtok(line," ");
        
        while (token!=NULL){
            //memory allocation
            if(numberSize<=numberCount){
                size_t newSize = numberSize == 0?1:numberSize*2;
                
                int *temp =realloc(numbers,newSize*sizeof(int));
                    if(temp==NULL){
                        printf("error allocating memory for line.temp failed");
                        free(numbers);
                        exit(1);
                    }
                numbers = temp;
            }

            numbers[numberCount++] = atoi(token);
            token =strtok(NULL," ");
        }
        
        int direction =0; //0-->same 1-->increasing -1-->decreasing
        int count=0;
        for (size_t i = 0; i < numberCount; i++){
            int diff = numbers[i]-numbers[i+1];
            if(diff==0){
                continue;
            } 
            
            int absdiff = abs(diff);
            
            if(absdiff>=1 && absdiff<=3){
                count++;
            }
            else{
                continue;
            }     
        }
        if(count ==numberCount){
            reports++;
        }
        free(numbers);
    }
    
    return reports;
}