#include<stdio.h>
#include<conio.h>
#include<windows.h>

int getkey();
void display(int,int,int,int[]);
void calendar(int,int);


//-------------- GOTO function definition ----------------------
void gotoxy(int x,int y) {
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

//------------ Change color -------------------
void SetColor(int ForgC)
{
     WORD wColor;
    //We will need this handle to get the current background attribute
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;

                           //We use csbi for the wAttributes word.
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
                     //Mask out all but the background attribute, and add in the forgournd color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}

char *month[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
char *week[]={"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};

int main()
{


    // ... Rest of the calendar project code ...

    // Add the feedback section
   

	//============================================================= Login Page =========================================================================//
	 int a=0,i=0;
    char uname[10],c=' '; 
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
	int b;
	
	printf("\033[1;33m");
	printf("\n                                      Enter the time you are logging in :  ");
	scanf("%d",&b);

	if(b<0)
	{
		printf("Nothing User.");
	}
	else if(b<12)
	{
		printf("\n\n\n                                           Good morning User.");
	}
	else if(b<=15)
	{
		printf("\n\n\n\n                                         Good afternoon User.");
	}
	else if(b<=18)
	{
		printf("\n\n\n\n                                          Good evening User.");
	}
	else if(b<=24)
	{
		printf("\n\n\n\n                                           Good night User!");
	}
	else{
		printf("Nothing User.");
	};
	
	printf("\n\n\n\n\n\t\t\t\t=> Press any key to continue towards login page...");
	getch();
	printf("\031[0m");
    do
   {
	system("cls");
	
    printf("\n\n                            =========================  LOGIN FORM  =========================  ");
    printf(" \n\n\n                                                  ENTER USERNAME:-");
	scanf("%s", &uname); 
	printf(" \n\n                                                    ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	//char code=pword;
	i=0;
		if(strcmp(uname,"Vanshika")==0 && strcmp(pword,"pass")==0)
	{

	printf("  \n\n                                                  WELCOME TO OUR SYSTEM !!!! ");
	printf("\n\n                                                        Login successful...");
	printf("\n\n\n\t\t\t\t                                    Press any key to continue...");
	getch();//holds the screen
	printf("\034[0m");
	break;
	}
	else
	{
		printf("\n                               SORRY !!!!  LOGIN UNSUCESSFUL");
		a++;
		
		getch();
		
	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\n                 Sorry you have entered the wrong username and password for four times!!!");
		
		getch();
		
		}
		system("cls");	
		
		
		
                             //================//Calender Page//=======
                             
    int nmonth,nyr,ch,year;
       printf("\033[1;33m");
       printf(" -----------------------------------------------------------------------------------------------------------------------");
       printf("\033[1;31m");
printf("\n\n                <===================================: CALENDER :===================================>                     \n\n");
    printf("\033[1;33m");
       printf(" -----------------------------------------------------------------------------------------------------------------------");
       printf("\033[0m");


        printf("\033[5;32m");
        printf("\n\n                                                  This is Calender!      ");
        printf("\033[0m");
        
        printf("\033[1;33m");
        printf("\n\n\n                Basic virtual calendar of months, with the correct alignment of the days based on the weekday.    ");
        printf("\n                 This is a basic calendar program created using simple c program, using this program");
		printf("                                   you can navigate year or month using the arrow key of your keyboard.");
		printf("\033[0m");
		
		printf("\033[2;35m");
        printf("\n\n                                         You have to fill the details here :");
        printf("\033[0m");
    enteryear:
    while(1)
    {
    	
    	printf("\033[1;31m");
        printf("\n\n\n                                   Enter year :  " );
        scanf("%d",&nyr);
         printf("\n                                   Enter month(number) :  " );
        scanf("%d",&nmonth);
        printf("\033[0m");
        
        if(nyr<1945)
        {
            printf("\n\t Please enter year above 1945!\n");
            continue;
        }
        else
        {
            calendar(nyr,nmonth);    }
        

      
       while(1)
        {
        gotoxy(20,20);printf("(*) Use LEFT, RIGHT, UP and DOWN arrow.");
        gotoxy(20,22);printf("(*) Press P to go to particular year and month.");
        gotoxy(20,24);printf("(*) Press ESC to Exit.");
        ch=getkey();
        switch(ch)
        {
        case 80: //-------- DOWN ARROW -----------
               //Increasing month
                if(nmonth==12)
                {
                    //Jump to next year if month is december
                     nmonth=1;
                     nyr++;
                }
                else
                {
                    nmonth++;
                }
                calendar(nyr,nmonth);
                break;
        case 77: //-------- RIGHT ARROW ----------
            //Increasing Year
                nyr++;
                calendar(nyr,nmonth);
                break;
        case 72: //------- UP ARROW -------------
            // Decreasing Month
                if(nmonth==1)
                {
                    // Jump to previous year if month is january
                    nyr--;
                    nmonth=12;
                }
                else
                    nmonth--;
                calendar(nyr,nmonth);
                break;
        case 75: //-------- LEFT ARROW ----------
            //Decreasing year
                if(nyr==1945)
                {
                    //If year is 1945 and we click left arrow than
                  gotoxy(15,2);printf("Year below 1945 not available");
                }
                else
                {
                    nyr--;
                    calendar(nyr,nmonth);
                }

                break;
        case 27: //--------- ESC KEY ------------
            //Exit program
                system("cls");
                gotoxy(50,14);printf("Exiting program.\n\n\n\n\n");
                exit(0);
        case 112://---------- p KEY ------------
            //Go to particular year and month
                system("cls");
                goto enteryear;
        }
        }
        break;
          printf("\n\nLeap year:- %c%d",year);
		{
		if(year% 4 == FALSE && year%100 != FALSE || year%400 == FALSE)
        {
	     // It is a leap year and February has 29 days.
	     printf("\n\nIt's a leap year.");
        }
       else
       {
	// It is not a leap year, so February has 28 days.
	printf("\n\nNot a leap year.");
       }
		}
}
}
 //--------------------------------------------------------------// Feedback //--------------------------------------------------------------------------------//

                  //============== DISPLAYING THE  CALENDAR ===================
                                      //Font//
                        
void display(int nyr,int nmonth,int tdays,int days[])
{
    int i,j,pos;
    SetColor(12); //Color red
    gotoxy(56,6);printf("%s %d",month[nmonth-1],nyr); //Heading year and month dispalying
    for(i=0,pos=30;i<7;i++,pos+=10)
    {
         if(i==6)
            SetColor(9); //Sunday color blue
         else
            SetColor(10);  //Others day color green
        gotoxy(pos,8);printf("%s",week[i]);
    }

    SetColor(15); //setting the color white

   tdays++; //incrementing the tdays by 1
    if(tdays==0 || tdays==7)
        pos=91; //if tdays is 0 or 7, position is sunday
    if(tdays==1)
        pos=31; //if tdays is 1, position is monday
    if(tdays==2)
        pos=41;  //if tdays is 2, position is tuesday
    if(tdays==3)
        pos=51;  //if tdays is 3, position is wednesday
    if(tdays==4)
        pos=61;  //if tdays is 4, position is thursday
    if(tdays==5)
        pos=71;  //if tdays is 5, position is friday
    if(tdays==6)
        pos=81;  //if tdays is 6, position is saturday

    for(i=0,j=10,pos;i<days[nmonth-1];i++,pos+=10)
    {
        if(pos==91)
            SetColor(8); //Changing color to dark grey for sunday
        else
            SetColor(7); //Changing color to white for all days

        gotoxy(pos,j);printf("%d",i+1);
        if(pos==91)
        {
            pos=21; //Moving position to monday
            j++;  //Increasing j by 10 if position is sunday
        }
    }

    SetColor(5); //Changing color to purple

    //Drawing horizontal line
    for(i=22;i<102;i++)
    {
        gotoxy(i,4);printf("%c",196);
        gotoxy(i,17);printf("%c",196);
    }

    //Drawing all the corner of the rectangle
    gotoxy(21,4);printf("%c",218);
    gotoxy(102,4);printf("%c",191);
    gotoxy(21,17);printf("%c",192);
    gotoxy(102,17);printf("%c",217);

    //Drawing vertical line
    for(i=5;i<17;i++)
    {
        gotoxy(21,i);printf("%c",179);
        gotoxy(102,i);printf("%c",179);
    }

    SetColor(11); //Changing color to aqua

    //left and the right navigation symbol
    gotoxy(24,11);printf("%c",174);
    gotoxy(98,11);printf("%c",175);

}

//Arrow Key
int getkey()
{
    int ch;
    ch=getch();
     if(ch==0)
    {
        printf("zero");
        ch=getch();

        return ch;
    }
    return ch;
}


//============================================================== Calculating ==================================================================================//
void calendar(int nyr,int nmonth)
{

    int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int tdays=0,k,myear;
    system("cls");
    myear=nyr-1; //Decreasing year by 1
            if(myear>=1945)
            {
                for(k=1945;k<=myear;k++)
                {
                    if(k%4==0) //If the year is a leap year than total no of days is 366
                        tdays=tdays+366;  //counting all the days till nyr - 1
                    else //If the year is a leap year than total no of days is 365
                        tdays=tdays+365;  //counting all the days till nyr - 1
                }
            }

            if(nyr%4==0)
                days[1]=29; //changing value in days array from 28 to 29 since leap year
            else
                days[1]=28; //changing value in days array from 29 to 28 since not a leap year

            for(k=0;k<(nmonth-1);k++)
            {

                tdays=tdays+days[k]; //Adding nmonth-1 days to tdays
            }

            tdays=tdays%7; //Finding the remainder of tdays so it can calculate the position to display
            display(nyr,nmonth,tdays,days); //Passing the value to display
              
}
  
