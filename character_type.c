#include <stdio.h>
#include<conio.h>
#include <stdlib.h>


int main() 

{
  //asking user for name & greeting.
printf("Hello! What is your name ? ");

char name[50];
scanf("%s",name);
printf("Hello,%s.Enter a character..\n",name);

getchar();

//figuring the type 
char ch;
scanf("%c",&ch);

if (ch >='a' && ch <= 'z')
 {printf("You entered lower case %c",ch);}

else if (ch>='A' && ch<= 'Z' )
 {printf("You entered Upper case %c",ch);}

else if (ch>='0' && ch<='9')
{printf("You entered number %c",ch);}

else
{printf("You entered special character %c",ch);}


 system("pause");


return 0;


}