/*
Nicholas Morgan 
Cs135
04/24/23


*/
#include <iostream>
using namespace std;

class Money {
public: 
    int dollars;
    int cents;
};

//Money withdraw_money(Money balance, Money withdrawal);
Money withdraw_money(Money balance, Money withdrawal) {
    Money ending;
    ending.dollars = balance.dollars - withdrawal.dollars;
    ending.cents = balance.cents - withdrawal.cents;
    if (ending.cents < 0) {
        ending.dollars = ending.dollars - 1;
        ending.cents = ending.cents + 100;
    }
    if (ending.dollars < 0){
        ending.dollars = 0;
        ending.cents = 0;
    }
    return ending;

}

int main () {
    Money starting = {100, 00};
    Money withdrawal = {2,75};
    Money ending = withdraw_money(starting, withdrawal);
    cout << "$" << ending.dollars << "." << ending.cents << endl;
}

