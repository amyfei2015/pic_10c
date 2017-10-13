#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "cards.h"
using namespace std;

// Global constants (if any)


// Non member functions declarations (if any)


// Non member functions implementations (if any)


// Stub for main
int main(){
    srand((int)time(0)); //to make the rank and suite numbers random.
   //variable declaration
    Player player;
    int money_current = player.get_money();
    int bet;
    char yesno;
    
    
    //each while loop indicates one turn of game
    while (money_current<1000 && money_current >0)
    {
    
    
        cout<<"You have $"<< money_current <<". Enter bet: ";
        cin>>bet;
        
        //make sure that the bet does not exceeds the amount of money that the player has
        while(bet>money_current){
            cout<<"You don't have so many money! Please enter a smaller amount:";
            cin>>bet;
        }
        
        //set hands and cards
        Hand plyr_hand,dlr_hand;
        plyr_hand.add_card(Card());
        int index_card = 0;
        double dlr_total = 0;
        Card c1 = plyr_hand.get_card(index_card);
        double card_value;
        double plyr_total = c1.get_value();
        
        //start
        cout<<"Your cards:"<<endl;
        c1.print();
        cout<< "Your total is "<<plyr_total<<". Do you want another card (y/n)?";
        cin>>yesno;
       
        //if the bet exceeds the money the player has
        while (yesno == 'y' || yesno =='Y'){
            plyr_hand.add_card(Card());
            ++index_card;
            c1 =plyr_hand.get_card(index_card);
            card_value = c1.get_value();
            plyr_total += card_value;
            cout<<"New card:"<<endl;
            c1.print();
            cout<<endl<<"Your cards:"<<endl;
            plyr_hand.print();
            cout<< "Your total is "<<plyr_total<<". Do you want another card (y/n)?";
            cin>>yesno;
        }
        
        //dealer's turn
        dlr_hand =  dlrs_turn();
        dlr_total = dlr_hand.get_value();
        
        
        cout<<"Dealer's cards:"<<endl;
        dlr_hand.print();
        cout<<"Dealer's total is "<<dlr_total<<"."<<endl;
       
        
        
        if (plyr_total < 7.6)//same as <=7.5
        {
           if (dlr_total < 7.6 && plyr_total <= dlr_total)
           {
               player.add_bet(-bet);
               money_current =player.get_money();
               cout<<"Too bad. You lose "<<bet<<".\n";
           }
           else
           {
               player.add_bet(bet);
               money_current = player.get_money();
               cout<<"You win "<<bet<<".\n";
           }
        }
        else
        {
            player.add_bet(-bet);
            money_current =player.get_money();
            cout<<"Too bad. You lose "<<bet<<".\n";
        }
    }
    
    //output the final results
    if (money_current <100) //same as <1
    {
        cout<<"You have $0. GAME OVER!\nCome back when you have more money.\n\nBye!\n";
    }
    else
    {
           cout<<"Congratulations. You beat the casino!\n\nBye!\n";
    }
        
    return 0;


}
