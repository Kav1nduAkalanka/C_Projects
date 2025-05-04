#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct student{

char name[30];
int roll_no;
float marks;    
}std;

int std_count();
void check_null(FILE*fp);

int  main(){

    printf("What you want to do?\n");
    printf("1.Make a new list\n");
    printf("2.Add a new Student\n");
    printf("3.View all student records\n");
    printf("4.Student with the highest marks\n");
    printf("press the corresponding number: ");

   int input=1;
   std stds[MAX];
   
   do
   {
    if (input<1|| input >4)
    {
       printf("please enter a valid input: ");
    }
    
    scanf("%d",&input);
    
   } while (input<1 || input>4);
   
  //make a new list
  if(input==1)
  {

    int n=1;
    printf("Number of Students(MAX=100): ");

    do
    {
      if (n<=0 || n>100)
      {
        printf("please enter a valid input");
      }
      scanf("%d",&n);
      getchar();
      
    }while (n<=0 || n>100);



    for (int i = 0; i < n; i++)
    {
      printf("\n%d)Student's Name: ",i+1);
      fgets(stds[i].name,30,stdin);
      stds[i].name[strcspn(stds[i].name,"\n")] = '\0';
    
      printf("\nRoll number: ");
      scanf("%d",&stds[i].roll_no);

      printf("\nMarks: ");
      scanf("%f",&stds[i].marks);
      getchar();
    }
    
    
        //open file//
        FILE *fp = fopen("data.dat","wb");
        check_null(fp);

        for(int i=0;i<n;i++)
        {
         fwrite(&stds[i],sizeof(std),1,fp);
        }
       


        fclose(fp);
  }

  //new student

  if(input==2){
     int d=std_count();
      int left = 100-d;
      if(left==0){
        printf("you can't add more students.");
        exit(1);
      }
      printf("\nHow many new students to add to the list(%d left): ",left);
      int n=0;

    do
    {
      if(n>left){
          printf("\ninvalid input.please enter again: ");
         }
      scanf("%d",&n);
    } while (n>left);

    FILE *fp=fopen("data.dat","ab");
    check_null(fp);

    for(int i=0;i<n;i++)
    {   getchar();
        printf("\n%d)Student's Name: ",i+1+d);
        fgets(stds[d+i].name,30,stdin);
        stds[d+i].name[strcspn(stds[d+i].name,"\n")] = '\0';
      
        printf("\nRoll number: ");
        scanf("%d",&stds[d+i].roll_no);
  
        printf("\nMarks: ");
        scanf("%f",&stds[d+i].marks);
        getchar();

        fwrite(&stds[d+i],sizeof(std),1,fp);
    }
    fclose(fp);
  }

  //view all
  if(input==3){
  
    FILE *fp=fopen("data.dat","rb");
    check_null(fp);
    int str_count= std_count();
   
    stds[str_count];
    for (int i = 0; i <str_count; i++)
    {
      fread(&stds[i],sizeof(std),1,fp);
    }

    printf("Name\t Roll-NO.\t Marks\n");

    for (int i = 0; i <str_count; i++)
    {
     printf("%s\t %d\t \t%.2f\n",stds[i].name,stds[i].roll_no,stds[i].marks);
    }

    fclose(fp);
  }

  //student with the highest marks
  if(input==4){
  

    FILE *fp=fopen("data.dat","rb");
    check_null(fp);
    int str_count= std_count();
    int std_no=0;
    printf("%d",str_count);
   
    stds[MAX];
    for (int i = 0; i <str_count; i++)
    {
      fread(&stds[i],sizeof(std),1,fp);
    }
    float highest=-1.00;

    for (int i = 0; i <str_count; i++){
       float n=stds[i].marks;
      if (n>=highest)
      {
        highest=n;
        std_no=i;
      }
      
    }

    printf("\n-student with the highest marks-\n");
    printf("Name: %s\n",stds[std_no].name);
    printf("Roll Number: %d\n",stds[std_no].roll_no);
    printf("Marks: %.2f\n",stds[std_no].marks);

    fclose(fp);
  }

return 0;
}


//struct count
int std_count(){
FILE *file=fopen("data.dat","rb");
check_null(file);
std temp;

int count =0;
while(fread(&temp,sizeof(std),1,file)==1)
{
count++;
}

fclose(file);
return count;
}

//nullCheck
void check_null(FILE*fp){
  if(fp==NULL)
  {
    printf("can't access the file");
    exit(1);
  }
}

