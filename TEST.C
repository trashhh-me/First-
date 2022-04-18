//*************************************************

//application: Covid-19 record

//*************************************************

#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<string.h>
#include<dos.h>

void getdata1( );
void getdata2( );
void getdata3( );
void getdata4( );
void getdata5( );
void getdata6( );
void getdata7( );


struct patient{
char COUNTRY[20];
long int ACTIVE;
long int CRITICAL;
long int DEATH;
long int RECOVERED;
};


void main()
{
int a;
clrscr();
gotoxy(30,11);
textcolor(YELLOW);
cprintf("COVID-19 RECORD APP");
gotoxy(1,13);
textcolor(BLUE);
cprintf("Let's all look out for each other by knowing our status, trying not to infect others, and reserving care for those in need.");
gotoxy(24,24);
textcolor(WHITE+BLINK);
cprintf("press any key to continue");
getch();

clrscr();
gotoxy(30,3);
textcolor(GREEN);
cprintf("INFORMATION");
gotoxy(26,6);
textcolor(WHITE);
cprintf("Add Cases         [press 1]");
gotoxy(26,8);
textcolor(WHITE);
cprintf("Delete Cases      [press 2]");
gotoxy(26,10);
textcolor(WHITE);
cprintf("Active Cases      [press 3]");
gotoxy(26,12);
textcolor(WHITE);
cprintf("Critical Cases    [press 4]");
gotoxy(26,14);
textcolor(WHITE);
cprintf("Death Cases       [press 5]");
gotoxy(26,16);
textcolor(WHITE);
cprintf("Recovered Cases   [press 6]");
gotoxy(26,18);
textcolor(WHITE);
cprintf("List Cases        [press 7]");
gotoxy(26,20);
textcolor(WHITE);
cprintf("Close             [press 8]");
gotoxy(26,22);
textcolor(WHITE);
cprintf("Please enter your choice: ");
scanf("%d",&a);
if(a==8){
clrscr();
gotoxy(22,10);
textcolor(RED);
cprintf("The application will close now");
gotoxy(25,12);
textcolor(RED);
cprintf("STAY SAFE, STAY AT HOME");
gotoxy(15,14);
textcolor(RED);
cprintf("Also don't forget to wash your hands frequently");
delay(5000);
exit(1);
}
else if(a==1)
{
clrscr();
getdata1();
}
else if(a==2)
{
clrscr();
getdata2();
}
else if(a==3)
{
clrscr();
getdata3();
}
else if(a==4)
{
clrscr();
getdata4(  );
}
else if(a==5)
{
clrscr();
getdata5();
}
else if(a==6)
{
clrscr();
getdata6( );
}
else if(a==7)
{
clrscr();
getdata7( );
}
}



void getdata1( ){
char CH;
struct patient C;
 FILE *fp;
gotoxy(25,2);
printf("ADD CASES  ");
   fp=fopen("C:\\doneeee.txt","a");
    if(fp==NULL){
      clrscr();
      printf("FILE OPENING ERROR ");
      delay(1000);
      exit(1);
    }
 //SEEK_END .goes to the end of the file
    fseek(fp,0,SEEK_END);
    fflush(stdin);
    CH='Y';
while(CH == 'Y'){
clrscr( );
gotoxy(10,8);
printf("Enter the country(all in block letters) :");
scanf("%s",C.COUNTRY);

fflush(stdin);
gotoxy(10,9);
printf("ACTIVE CASES : ");
scanf("%d",&C.ACTIVE);

fflush(stdin);
gotoxy(10,10);
printf("CRITICAL CASES : ");
scanf("%d",&C.CRITICAL);

fflush(stdin);
gotoxy(10,11);
printf("RECOVERED : ");
scanf("%d",&C.RECOVERED);

fflush(stdin);
gotoxy(10,12);
printf("DEATH : ");
scanf("%d",&C.DEATH);

fwrite(&C,sizeof(C),1,fp);
  Message:
printf("Do you want to continue [Y/N]");
	  CH = getche();
	  //checking Y and N condition
	  //restart the loop if yes
      if(CH == 'y' || CH == 'Y'){
		CH='Y';
	  }
	//exit if N or any other button
	  else if(CH == 'n' || CH == 'N'){
		main();
	  }
	  else{
		goto Message;
	  }
}
}



void getdata2( ){
char name[20], CH;
struct patient C;
    FILE *fp,*fp1;
int f=0,C1, C2, C3, C4;
char CW[20];
rewind(fp);
clrscr();

gotoxy(25,2);
printf("DELETE CASES  ");
gotoxy(10,8);
printf("Enter the country(all in block): ");
scanf("%s",name);
 fp=fopen("C:\\doneeee.txt","rb");
fp1=fopen("C:\\doneeee2.txt","ab");
   
    while(fread(&C,sizeof(C),1,fp)==1)
    {
	if(strcmp(C.COUNTRY,name)==0)
{
f=1;
clrscr();
gotoxy(20,10);
printf("DATA FOUND");
clrscr();
gotoxy(15,10);
printf("YOUR DELETE IS SUCCESSFUL");
getch( );
}
else
fwrite(&C,sizeof(C),1,fp1);
if(f==0){
clrscr();
gotoxy(15,10);
printf("DATA NOT FOUND");
}
}
fclose(fp);
    fclose(fp1);
remove("C:\\doneeee.txt");
rename("C:\\doneeee2.txt","C:\\doneeee.txt");
main();
}






void getdata3( ){
char cou[20];
struct patient C;
FILE *fp;
rewind(fp);
gotoxy(25,2);
printf("ACTIVE CASES  ");
gotoxy(10,10);
  printf(" ENTER THE COUNTRY(all in block letters) :");
    scanf("%s",cou);
fp = fopen("C:\\doneeee.txt","rb+");
	if(fp == NULL){
clrscr();

      printf("FILE OPENING ERROR ");
      delay(1000);
      exit(1);
    }
while(fread(&C,sizeof(C),1,fp)==1){
		if(strcmp(C.COUNTRY,cou)==0){
clrscr( );
gotoxy(10,10);
textcolor(RED);
cprintf("Total active cases in %s is %d ",C.COUNTRY,C.ACTIVE);
gotoxy(8,19);
textcolor(YELLOW);
cprintf("STAY SAFE..YOUR HEALTH IS IMPORTANT FOR US");
getch( );
fclose(fp);
main();
}
}
}



void getdata4( ){
struct patient C;
char cou[20];
FILE *fp;
rewind(fp);
gotoxy(25,2);
printf("CRITICAL CASES  ");
gotoxy(10,10);
  printf(" ENTER THE COUNTRY(all in block):");
   scanf("%s",cou);

fp = fopen("C:\\doneeee.txt","rb+");
	if(fp == NULL){
clrscr();
      printf("FILE OPENING ERROR ");
      delay(1000);
      exit(1);
    }
while(fread(&C,sizeof(C),1,fp)==1){
		if(strcmp(C.COUNTRY,cou)==0){
clrscr();
gotoxy(10,10);
textcolor(RED);
cprintf("Total critical cases in %s is %d ",C.COUNTRY,C.CRITICAL);
gotoxy(8,19);
textcolor(YELLOW);
cprintf("STAY SAFE..YOUR HEALTH IS IMPORTANT FOR US");
getch();
fclose(fp);
main();
}
}

}


void getdata5( ){
char cou[20];
struct patient C;
FILE *fp;
rewind(fp);
gotoxy(25,2);
printf("DEATH CASES  ");
gotoxy(10,10);
  printf(" ENTER THE COUNTRY(all in block letters):");
    scanf("%s",cou);

fp = fopen("C:\\doneeee.txt","rb+");
	if(fp == NULL){
clrscr();
      printf("FILE OPENING ERROR ");
      delay(1000);
      exit(1);
    }
while(fread(&C,sizeof(C),1,fp)==1){
		if(strcmp(C.COUNTRY,cou)==0){
clrscr();
gotoxy(10,10);
textcolor(RED);
cprintf("Total death cases in %s is %d ",C.COUNTRY,C.DEATH);
gotoxy(8,19);
textcolor(YELLOW);
cprintf("STAY SAFE..YOUR HEALTH IS IMPORTANT FOR US");
getch();
fclose(fp);
main();
}
}

}



void getdata6( ){
struct patient C;
char cou[20];
FILE *fp;
rewind(fp);
gotoxy(25,2);
printf("RECOVERED CASES  ");
  printf(" ENTER THE COUNTRY(all in block letters):");
gotoxy(10,10);
  scanf("%s",cou);

fp = fopen("C:\\doneeee.txt","rb+");
	if(fp == NULL){
clrscr();
      printf("FILE OPENING ERROR ");
      delay(1000);
      exit(1);
    }
while(fread(&C,sizeof(C),1,fp)==1){
		if(strcmp(C.COUNTRY,cou)==0){
clrscr( );
gotoxy(10,10);
textcolor(RED);
printf("Total recovered cases in %s is %d ",C.COUNTRY,C.RECOVERED);
gotoxy(8,19);
textcolor(YELLOW);
cprintf("STAY SAFE..YOUR HEALTH IS IMPORTANT FOR US");
getch();
main();
}
}

}


void getdata7( ){
	struct patient C;
	char CH;
long unsigned int ac=0,c=0,r=0,d=0;
    FILE *fp;

  /* Y=6 for records to be printed along y-axis and goes increasing order 1by1 */
int a=1;
    int Y=6;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\turboc3\\bgi");

 /* line to draw a horizontal above square. */

    line(20,65,610,65);
    line(21,66,611,66);

    line(50,40,50,449);
    gotoxy(4,4);
    printf("NO.");

  /* country */

    gotoxy(19,4);
    printf("COUNTRY");
    line(292,40,292,449);


    gotoxy(38,4);
    printf("ACT. CASES");
    line(385,40,385,449);

  /* critical cases */

    gotoxy(50,4);
    printf("CRI.CASES");
    line(470,40,470,449);

  /* recovered cases  */

    gotoxy(61,4);
    printf("REC.CASES");
    line(556,40,556,449);

  /* THE REMAINING COLUMN IS FOR death cases*/

    gotoxy(71,4);
    printf("DEATH");
line(613,40,613,449);
    fp=fopen("C:\\doneeee.txt","rb+");
    rewind(fp);
 while(fread(&C,sizeof(C),1,fp)==1){
    gotoxy(5,Y);
 printf("%d.",a);
 gotoxy(19,Y);
    printf("%s",C.COUNTRY);
    gotoxy(40,Y);
    printf("%d",C.ACTIVE);
    gotoxy(50,Y);
    printf("%d",C.CRITICAL);
    gotoxy(61,Y);
    printf("%d", C.RECOVERED);
    gotoxy(72,Y);
    printf("%d",C.DEATH);
 
    ++Y;
a++;
ac=ac + C.ACTIVE;
c=c + C.CRITICAL;
r=r + C.RECOVERED;
d=d + C.DEATH;
}
gotoxy(19,Y+3);
    printf("TOTAL");
    gotoxy(40,Y+3);
    printf("%d",ac);
    gotoxy(50,Y+3);
    printf("%d",c);
    gotoxy(61,Y+3);
    printf("%d", r);
    gotoxy(72,Y+3);
    printf("%d",d);
getch();
fclose(fp);
   }

























