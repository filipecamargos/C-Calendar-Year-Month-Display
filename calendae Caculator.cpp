#include <iostream>
#include <iomanip>
using namespace std;

/******************************************************
* Responsable for getting the number of months
******************************************************/
int getMonth()
{
   int month;

   cout << "Enter a month number: ";
   cin  >> month;
   
   while ( month < 1 || month > 12)
   {
      cout << "Month must be between 1 and 12.\n"
           << "Enter a month number: ";
      cin >> month;
   }
   
   
   return month;
}
      
/*************************************************************
* This fuction is responsable for prompting the user the year
**************************************************************/
int getYear()
{
   int year;

   cout << "Enter year: ";
   cin  >> year;

   while ( year < 1753)
   {
      cout << "Year must be 1753 or later.\n"
           << "Enter year: ";
      cin >> year;
   }


   return year;
   
}

/************************************************************
* This fuction will work integreated to our offSet to set
* the number of days and to be displyed
*************************************************************/
bool isLeapYear(int year)
{
   if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
      return true;
   else
      return false;
}

/*************************************************************
* This fuction will work to provide the number of days to be
* displayed according with the month, it also consider if our
* year is a leap year so the right number is display for month 2
*****************************************************************/
int numberDay(int year, int month)
{
   int numberDaysMonth;

   if (month == 1)
      numberDaysMonth = 31;
   else if (month == 2)
   {
      if (isLeapYear(year) == true)
         numberDaysMonth = 29;
      else
         numberDaysMonth = 28;
   }
   else if (month == 3)
      numberDaysMonth = 31;
   else if (month == 4)
      numberDaysMonth = 30;
   else if (month == 5)
      numberDaysMonth = 31;
   else if (month == 6)
      numberDaysMonth = 30;
   else if (month == 7)
      numberDaysMonth = 31;
   else if (month == 8)
      numberDaysMonth = 31;
   else if (month == 9)
      numberDaysMonth = 30;
   else if (month == 10)
      numberDaysMonth = 31;
   else if (month == 11)
      numberDaysMonth = 30;
   else if (month == 12)
      numberDaysMonth = 31;

   return numberDaysMonth;   
}

/***********************************************************************
 * Computes the number of days in the given year.
 **********************************************************************/
int numberDayYear(int year)
{
   int daysYear = 365 + isLeapYear(year);
   return daysYear;
}


/*************************************************************
* The compute Offset will be responsable for caculatin our
* offset and send it to the display fuction so the days can
* be aligned correctly
*************************************************************/
int computerOffset(int  month,int  year)
{
   int offset = 0;

   // Count the number of day from 1753
   for (int yearCounting = 1753; yearCounting < year;
        yearCounting++)
   {
      offset += numberDayYear(yearCounting);
   }
   
   // count the number of days in the given year and month
   for (int monthCounting = 1;monthCounting < month;
        monthCounting++)
   {
      offset += numberDay(year, monthCounting);
   }

   return offset % 7;
}

/******************************************************
* This display will be responsable for printing the
* correspond year and also the month for that year
* according with the user's input
******************************************************/
void displayHead(int month, int year)
{
   cout << endl;
   
   if (month == 1)
      cout << "January, " << year << endl;
   else if (month == 2)
      cout << "February, " << year << endl;
   else if (month == 3)
      cout << "March, " << year << endl;
   else if (month == 4)
      cout << "April, " << year << endl;
   else if (month == 5)
      cout << "May, " << year << endl;
   else if (month == 6)
      cout << "June, " << year << endl;
   else if (month == 7)
      cout << "July, " << year << endl;
   else if (month == 8)
      cout << "August, " << year << endl;
   else if (month == 9)
      cout << "September, " << year << endl;
   else if (month == 10)
      cout << "October, " << year << endl;
   else if (month == 11)
      cout << "November, " << year << endl;
   else if (month == 12)
      cout << "December, " << year << endl;   
}

/*****************************************************
* Our display fuction will recieve the computation
* of the year and all the other information such as,
* the offset with the month and display the exactly table
* for the given month and year
*****************************************************/
void display(int off, int days)
{
  
   // Headers of the Dispay
   cout << "  Su  Mo  Tu  We  Th  Fr  Sa" << endl;
   
   // This part of the code is set to set he numbers of
   //space to jump in case of offset 6 (Sunday)
   if (off >= 0 && off < 6)
      for (int space = 0; space <= off && off != 6 ; space++)
      {
         cout << "    ";
      }
   
   int jump;
   jump = 2;

   if (off == 6)
      jump = 1;
   else
      jump = jump + off;
   
   // This part of the coud set the right space for the
   // the rest of the weeks depending of the offset
   for (int startday = 1; startday <= days; startday++)
   {
      
      if (jump == 8)
      {
         cout << "\n"; 
         jump = 1;
      }
      
      jump++;
      
      cout << "  " << setw(2) << startday  ;
   } 
   cout << endl;
}

/******************************************************
* The main fuction will be responsable for calling
* our other fuction and distributing the variable
* acordingly so the computation can be made
******************************************************/
int main()
{
   int month = getMonth();
   int year = getYear();
   int offSet = computerOffset(month, year);
   int day = numberDay(year, month);
   displayHead(month, year);
   display(offSet, day);

   return 0;
}
