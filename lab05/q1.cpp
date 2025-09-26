#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int guessGame(int num,int player) {
    cout << " ENTER YOUR GUESS (player#"<<player<<"):";
    int num2;
    cin >> num2;

    if(num2 == num) {
        cout <<"it was found";
        return player;
    }
    else if(num2 > num) {
        cout <<"your guess was higher";
    }
    else {
        cout <<"your guess was lower";
    }

    if(player ==1) player =2;
    else player =1;

    return guessGame(num,player);
}

int main() {
    srand(time(nullptr));

    int randNum = rand() %100 + 1;
    int player =1;

    int won = guessGame(randNum,player);
    cout<<"\nthe player who won was: "<<won<<endl;
}