//firstWeekProject

#include<iostream>
using namespace std ;

//-----------game class-------------------

class Gameboard{

    char firstPlayerMove ;
    char secondPlayerMove ;
    char board[3][3];
    int firstCtr ;
    int secondCtr ;
    int fposition ;
    int sposition ;

public:

    void gameCompleteChecker(){
        int blankctr = 0;
        for(int i = 0 ;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]=='-'){
                    blankctr += 1;
                }
            }
        }
        if(blankctr == 0){
            winner = 'e';
        }
    }

    char winner = 'n';

    void setfCoordinates(int position){
        if(position==11){
            board[0][0] = firstPlayerMove;
        }
        else if(position == 12){
            board[0][1] = firstPlayerMove;
        }
        else if(position == 13){
            board[0][2] = firstPlayerMove;
        }
        else if(position == 21){
            board[1][0] = firstPlayerMove;
        }
        else if(position == 22){
            board[1][1] = firstPlayerMove;
        }
        else if(position == 23){
            board[1][2] = firstPlayerMove;
        }
        else if(position == 31){
            board[2][0] = firstPlayerMove;
        }
        else if(position == 32){
            board[2][1] = firstPlayerMove;
        }
        else {
            board[2][2] = firstPlayerMove;
        }
    }

    void setsCoordinates(int position){
        if(position==11){
            board[0][0] = secondPlayerMove;
        }
        else if(position == 12){
            board[0][1] = secondPlayerMove;
        }
        else if(position == 13){
            board[0][2] = secondPlayerMove;
        }
        else if(position == 21){
            board[1][0] = secondPlayerMove;
        }
        else if(position == 22){
            board[1][1] = secondPlayerMove;
        }
        else if(position == 23){
            board[1][2] = secondPlayerMove;
        }
        else if(position == 31){
            board[2][0] = secondPlayerMove;
        }
        else if(position == 32){
            board[2][1] = secondPlayerMove;
        }
        else {
            board[2][2] = secondPlayerMove;
        }
    }

    void getFirstMoves(){

        cout<<"enter the place where the first player wants :"<<endl;
        cin>>fposition;
        setfCoordinates(fposition);
    }
    void getSecondMoves(){
        cout<<"enter the place where second player wants : "<<endl;
        cin>>sposition;
        setsCoordinates(sposition);
    }

    //----------------MODIFYING BLANKS SPACES--------------------------

    void modifyBlanks(){
        for(int i = 0 ;i<3;i++){
            for(int j = 0;j<3;j++){
                if(board[i][j] != firstPlayerMove && board[i][j] != secondPlayerMove){
                    board[i][j] = '-' ;
                }
            }
        }
    }

    //-----------------------------------------------------------------

    //----------------SHOW BOARD GAME --------------------------------

    void showBoard(){
        for(int i =0;i<3;i++){
            for(int j =0;j<3;j++){
                cout<<board[i][j]<<"   ";
            }
            cout<<endl;
        }
    }

    //----------------------------------------------------------------

    //----------------PRIMARY DIAGONAL--------------------------------
    void primaryDiagonal(){
        for(int i = 0;i<3;i++){
            for(int j =0;j<3;j++){
                if(i ==j){
                    if(board[i][j]==firstPlayerMove){
                        firstCtr += 1 ;
                    }
                    else if(board[i][j]== secondPlayerMove){
                        secondCtr += 1 ;
                    }
                }
            }
        }
        if(firstCtr == 3){
            winner = 'f';
        }
        else if(secondCtr == 3){
            winner = 's';
        }
        else{
            firstCtr = 0;
            secondCtr = 0 ;
        }
    }

    //-----------------------------------------------------------------

    //----------------SECONDARY DIAGONAL--------------------------------
    void secondaryDiagonal(){
        for(int i =0 ; i<3 ; i++){
            for(int j = 2;j>=0;j--){
                if(i+j==2) {
                    if (board[i][j] == firstPlayerMove) {
                        firstCtr += 1;
                    } else if (board[i][j] == secondPlayerMove) {
                        secondCtr += 1;
                    }
                }
            }
        }
        if(firstCtr == 3){
            winner = 'f';
        }
        else if(secondCtr == 3){
            winner = 's';
        }
        else{
            firstCtr = 0;
            secondCtr = 0;
        }
    }

    //-------------------------------------------------------------------

    //----------------------ROWS-----------------------------------------
    void rows(){

        for(int i = 0;i<3;i++){
            if(winner == 'n') {
                int k = 0;
                while (k == 0) {
                    for (int j = 0; j < 3; j++) {
                        if (board[i][j] == firstPlayerMove) {
                            firstCtr += 1;
                        } else if (board[i][j] == secondPlayerMove) {
                            secondCtr += 1;
                        }
                    }
                    if (firstCtr == 3) {
                        winner = 'f';
                        k = 1;
                    } else if (secondCtr == 3) {
                        winner = 's';
                        k = 1;
                    } else {
                        firstCtr = 0;
                        secondCtr = 0;
                        k = 1;
                    }

                }
            }
        }

    }

    //-------------------------------------------------------------------


    //---------------------COLUMNS---------------------------------------
    void columns(){
        for(int i = 0;i<3;i++){
            if(winner == 'n') {
                int k = 0;
                while (k == 0) {
                    for (int j = 0; j < 3; j++) {
                        if (board[j][i] == firstPlayerMove) {
                            firstCtr += 1;
                        } else if (board[j][i] == secondPlayerMove) {
                            secondCtr += 1;
                        }
                    }
                    if (firstCtr == 3) {
                        winner = 'f';
                        k = 1;
                    } else if (secondCtr == 3) {
                        winner = 's';
                        k = 1;
                    } else {
                        firstCtr = 0;
                        secondCtr = 0;
                        k = 1;
                    }

                }
            }
        }


    }

    //-------------------------------------------------------------------
    void getMoves(){
        cout<<"enter the move for the first Player : "<<endl;
        cin>>firstPlayerMove ;

        if(firstPlayerMove == 'X'){
            secondPlayerMove = 'O' ;
        }
        else {
            secondPlayerMove = 'X';
        }

    }

} gameboard;

int main(){

    cout<<"welcome to the tic tac toe game"<<endl<<endl<<endl;
    gameboard.getMoves();

    while(gameboard.winner == 'n'){
        gameboard.getFirstMoves();
        gameboard.modifyBlanks();
        gameboard.primaryDiagonal();
        gameboard.secondaryDiagonal();
        gameboard.rows();
        gameboard.columns();
        gameboard.gameCompleteChecker();
        gameboard.showBoard();
        gameboard.getSecondMoves();
        gameboard.modifyBlanks();
        gameboard.showBoard();
        gameboard.primaryDiagonal();
        gameboard.secondaryDiagonal();
        gameboard.rows();
        gameboard.columns();
        gameboard.gameCompleteChecker();
    }
    if(gameboard.winner == 'f'){
        cout<<"first player wins!!"<<endl;
    }
    else if(gameboard.winner == 's') {
        cout<<"second player wins!!"<<endl;
    }
    else {
        cout<<"no one wins"<<endl;
    }

    return 0 ;
}
