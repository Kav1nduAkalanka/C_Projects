#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>

void isFileNull(FILE *fp);
int *readLine(FILE *fp);
int countEle(FILE *fp);
int bufferSize(FILE *fp);

int main()
{
  //open the input file  
  printf("\n test\n");
  FILE *fp = fopen("test.txt","r");
  isFileNull(fp);
 
  int d=bufferSize(fp);
  int c =countEle(fp);

  return 0;  
}


//file pointer null check
void isFileNull(FILE *fp)
{
  if(fp==NULL)
  {
    perror("Error opening file");
    fclose(fp);
    exit (1);
  }
}



//read a line
int *readLine(FILE *fp)
{
  bufferSize(fp);
  countEle(fp);
}

//count the elements
int countEle(FILE *fp)
{
  char ch;
  int count=0;
    while ((ch=fgetc(fp))!='\n' && (ch=fgetc(fp))!=EOF)
    {

    }
    printf("\nelement count= %d",count);
  return count+1;
}

//buffer size for each line
int bufferSize(FILE *fp)
{
  char ch;
  int count =0;
  while ((ch=fgetc(fp))!='\n'&&(ch=fgetc(fp))!=EOF)
  {
    count++;
  }
  printf("\nbuffer size= %d",count+1);
  return count;
}
