#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
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
    int money_current = 100;
    int money_afterbet;
    int bet;
    Card c1;
    string card_rank_span = c1.get_spanish_rank();
    string card_rank_eng = c1.get_english_rank();
    string card_suit_span = c1.get_spanish_suit();
    string card_suit_eng = c1.get_english_suit();
    
    cout<<"You have $100. Enter bet: ";
    cin>>bet;
    while(bet>money_current){
        cout<<"You don't have so many money! Please enter a smaller amount:";
        cin>>bet;
    }
    
    
    
    
    
    
    
    
    
    return 0;


}
