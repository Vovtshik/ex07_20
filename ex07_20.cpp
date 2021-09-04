/*ex07_20.cpp*/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int bookingTicket(bool[], int);
void printTicket(int);

int main()
{
   const int numberOfSeats  = 10;
   bool conditionOfSeats[numberOfSeats] = {0};
   int workProgr;
   while(true)
   {
      int numPlace;
      cout << "\n\nTo service the next passenger, enter 1 (to exit the program, press 0):";
      cin >> workProgr;
      if( workProgr)
      {
          numPlace = bookingTicket(conditionOfSeats, numberOfSeats);
	  if(numPlace)
	     printTicket(numPlace);
      }
      else
	  return 0;
   }
}

int bookingTicket(bool ticketArr[], int num)
{
   bool flagSmoker;
   cout << "\nOrdering tickets for the company \"Netishinskie airlines\" flight 001\n";
   cout << "Please enter 1 for \"smokers\"\n"
	<< "Please enter 0 for \"non-smokers\"\n";
   cin >> flagSmoker;
   if(flagSmoker)
   {
      for(int i = 0; i < 5; i++)
      {
         if(!ticketArr[i])
	 {
	    ticketArr[i] = true;
	    return i + 1;
	 }
      }
      cout << "\nThere are no places for \"smokers\"; would you like to buy a non-smoking seat?\n";
      cout << "If yes, please enter 0 to order a place for \"non-smokers\":\n";
      cin >> flagSmoker;
      if(!flagSmoker)
      {
         for(int n = 5; n < num; n++ )
	 {
	    if(!ticketArr[n])
	    {
	       ticketArr[n] = true;
	       return n + 1;
	    }
	 }

	 cout << "\nThere are no vacant seats for the current flight.\n"
	      << "Next flight in 3 hours!\n";
	 return 0;
      }
      else
      {
         cout << "\nThere are no vacant seats for the current flight.\n"
              << "Next flight in 3 hours!\n";
	 return 0;
      }
   }
   else
   {
      for(int n = 5; n < num; n++ )
      {
         if(!ticketArr[n])
	 {
	    ticketArr[n] = true;
	    return n + 1;
	 }
      }
      cout << "\nThere are no places for \"non-smokers\"; would you like to buy a smoking seat?\n";
      cout << "If yes, please enter 1 to order a place for \"smokers\":\n";
      cin >> flagSmoker;
      if(flagSmoker)
      {
         for(int i = 0; i < 5; i++)
	 {
	    if(!ticketArr[i])
	    {
	       ticketArr[i] = true;
	       return i + 1;
	    }
	 }
	 cout << "\nThere are no vacant seats for the current flight.\n"
	      << "Next flight in 3 hours!\n";
         return 0;	 
      }
      else
      {
         cout << "\nThere are no vacant seats for the current flight.\n"
	      << "Next flight in 3 hours!\n";
	 return 0;
      }
      
   }
}

void printTicket(int numTicket)
{
   cout << "\n\ncompany \"Netishinskie airlines\" flight 001\n";
   cout << "Boarding pass.\n";
   cout << "place number: " << numTicket << endl;
   if(numTicket > 0 && numTicket < 6)
      cout << "Lounge for \"smokers\"\n";
   else
      cout << "Lounge for \"nonsmokers\"\n";
}
