#include "cards.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>

/* 
You might or might not need these two extra libraries 
#include <iomanip>
#include <algorithm>
*/


/* *************************************************
   Card class
   ************************************************* */

/* 
   Default constructor for the Card class.
   It could give repeated cards. This is OK.
   Most variations of Blackjack are played with 
   several decks of cards at the same time.
*/
Card::Card(){
   int r = 1 + rand() % 4;
   switch (r) {
      case 1: suit = OROS; break;
      case 2: suit = COPAS; break; 
      case 3: suit = ESPADAS; break;
      case 4: suit = BASTOS; break; 
      default: break;
   }

   r = 1 + rand() % 10;  
   switch (r) {
      case  1: rank = AS; break; 
      case  2: rank = DOS; break; 
      case  3: rank = TRES; break; 
      case  4: rank = CUATRO; break; 
      case  5: rank = CINCO; break; 
      case  6: rank = SEIS; break; 
      case  7: rank = SIETE; break; 
      case  8: rank = SOTA; break; 
      case  9: rank = CABALLO; break; 
      case 10: rank = REY; break; 
      default: break;
   }
}

// Accessor: returns a string with the suit of the card in Spanish 
string Card::get_spanish_suit() const { 
   string suitName;
   switch (suit) {
      case OROS: 
         suitName = "oros"; 
	 break;
      case COPAS: 
         suitName = "copas"; 
	 break; 
      case ESPADAS: 
         suitName = "espadas"; 
	 break;
      case BASTOS: 
         suitName = "bastos"; 
	 break; 
      default: break;
   }
   return suitName;
}

// Accessor: returns a string with the rank of the card in Spanish 
string Card::get_spanish_rank() const { 
   string rankName;
   switch (rank) {
      case AS:
         rankName = "As"; 
	 break; 
      case DOS: 
         rankName = "Dos"; 
	 break; 
      case TRES: 
         rankName = "Tres"; 
	 break; 
      case CUATRO: 
         rankName = "Cuatro"; 
	 break; 
      case CINCO: 
         rankName = "Cinco"; 
	 break; 
      case SEIS: 
         rankName = "Seis"; 
	 break; 
      case SIETE: 
         rankName = "Siete"; 
	 break; 
      case SOTA: 
         rankName = "Sota"; 
	 break; 
      case CABALLO: 
         rankName = "Caballo"; 
	 break; 
      case REY: 
         rankName = "Rey"; 
	 break; 
      default: break;
   }
   return rankName;
}



// Accessor: returns a string with the suit of the card in English 
// This is just a stub! Modify it to your liking.
string Card::get_english_suit() const { 
    string suitName;
    switch (suit) {
        case OROS:
            suitName = "coins";
            break;
        case COPAS:
            suitName = "cups";
            break;
        case ESPADAS:
            suitName = "spades";
            break;
        case BASTOS:
            suitName = "clubs";
            break;
        default: break;
    }
    return suitName;
}



// Accessor: returns a string with the rank of the card in English 
// This is just a stub! Modify it to your liking.
string Card::get_english_rank() const { 
    string rankName;
    switch (rank) {
        case AS:
            rankName = "Aces";
            break;
        case DOS:
            rankName = "Two";
            break;
        case TRES:
            rankName = "Three";
            break;
        case CUATRO:
            rankName = "Four";
            break;
        case CINCO:
            rankName = "Five";
            break;
        case SEIS:
            rankName = "Six";
            break;
        case SIETE:
            rankName = "Seven";
            break;
        case SOTA:
            rankName = "Jack";
            break;
        case CABALLO:
            rankName = "Knight";
            break;
        case REY:
            rankName = "King";
            break;
        default: break;
    }
    return rankName;
}



// Assigns a numerical value to card based on rank.
// AS=1, DOS=2, ..., SIETE=7, SOTA=10, CABALLO=11, REY=12
int Card::get_rank() const {
   return static_cast<int>(rank) + 1 ;
}

// Comparison operator for cards
// Returns TRUE if card1 < card2
bool Card::operator < (Card card2) const {
   return rank < card2.rank;
}


//print card to console
void Card::print() const{
    string card_rank_span = (*this).get_spanish_rank();
    string card_rank_eng = (*this).get_english_rank();
    string card_suit_span = (*this).get_spanish_suit();
    string card_suit_eng = (*this).get_english_suit();
    
     cout<< setw(14)<<card_rank_span <<" de "<<card_suit_span<<setw(12)<<"("<<card_rank_eng<<" of "<<card_suit_eng<<")."<<endl;
    
}

//get the numeric value of each card
double Card::get_value() const{
    int rank = (*this).get_rank();
    if (rank <9)
        return rank;
    else
        return 0.5;
}

/* *************************************************
   Hand class
   ************************************************* */
// Implemente the member functions of the Hand class here.
Hand::Hand(){
    cards;//don't know how to do with it
}
void Hand::add_card(Card cadd){
    cards.push_back(cadd);
    return;
}

//This return the card at the position index
Card Hand::get_card(int index) const{
    return cards[index];
}

//This returns the number of cards in Hand
size_t Hand:: get_size() const{
    return (cards.size());
}

//print all cards properly in hand
void Hand:: print() const{
    for (size_t i = 0, n = cards.size(); i< n;++i){
        cards[i].print();
    }
}

//This return the total score of all cards in hand
double Hand:: get_value() const{
    double total = cards[0].get_value();
    double current;
    size_t n = cards.size();
    for(size_t i = 1;i<n;++i)
    {
        current = cards[i].get_value();
        total+= current;
    }
    return total;
}


/* *************************************************
   Player class
   ************************************************* */
// Implemente the member functions of the Player class here.


//Default for player class
Player::Player(){
    money = 100;
    }

//This creates a player with initial amount of money m
Player::Player(int m){
    money = m;
}
    
//This add bet to the money that the palyer currently hold
void Player::add_bet(int add){
    money += add;
    return;
}

//This returns the money that the player currently has
int  Player::get_money() const{
    return money;
}
    
/* *************************************************
Other functions
 ************************************************* */

/*
 fuction dealer's turn
 input:nothing
 output: Hand (containing all cards the dealer has for one turn)
 algorithm: dealer continues to add card as long as the total value is less than 5.5
 */
Hand dlrs_turn(){
    Hand h;
    h.add_card(Card());
    int card_index = 0;
    double sum_card = h.get_card(card_index).get_value();
    
    while(sum_card < 5.3){ //less than 5.5
        h.add_card(Card());
        card_index +=1;
        int c_current =h.get_card(card_index).get_value();
        sum_card += c_current;
    }
    return h;
}


    

    

