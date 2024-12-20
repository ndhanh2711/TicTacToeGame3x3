#include <stdio.h>
#include <math.h>
char a[3][3];
void taobang(void){
    //Tạo một bảng trống với các kí tự là dấu cách
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            a[i][j] = ' ';
        }
    }
}
void tiktactoe1(){
    printf("RULES OF TTHE GAME  : \n");
    printf("_______________________________________________________________________________________\n");
    printf("|Fill in 'x'or'o' in the cells of the table using numbers,like in the following table:|\n");
    for(int i = 0; i < 3; i++){
        if(i == 1){
            printf("|  | | | |  --->  |");
        }
        else{
            printf("|  | | | |        |");
        }
    for(int j = 3 * i + 1; j <= 3 * i + 3; j++){
        printf("%d|", j);
        }
        if(i == 1){
            printf("  --->  |o|o|x|                                              |");
        }
        else{
            printf("        |x|o|x|                                              |");
        }
            printf("\n");
    }
    printf("|The game ends when one player has three pieces in a row                              |\n");
    for(int i = 0; i < 3; i++){
        if(i == 0){
            printf("|     |x|x|x|                                                                         |\n");
        }
        else if(i == 1){
            printf("| Ex: | | | | --> 'x' WIN                                                             |\n|     | | | |                                                                         |\n");
        }
    }
    printf("---------------------------------------------------------------------------------------\n");
}

void displayBoard(void){
    //Hiển thị bảng trống
    for(int i = 0; i < 3; i++){
        printf("|");
    for(int j = 0; j < 3; j++){
        printf(" |");
        }
        printf("\n");
    }
}

int checkMove(int row, int col){
    //Kiểm tra nước đi có hợp lệ không
    if (row < 0 || row > 3 || col < 0 || col > 3) {
        return 0; // ko hợp lệ
      }
      if (a[row][col] == 'x' || a[row][col] == 'o'){
        return 0; // Vị trí này đã bị đánh
      }
      return 1; // Hợp lí
}

void makeMove(char a[3][3], int row, int col, char symbol){
    //Hàm lưu kí tự người chơi đánh vào bảng trống
    a[row][col] = symbol;
}

int checkWin(void) {
    // Kiểm tra xem có người chiến thắng hay không
    // Kiểm tra hàng ngang
    
    for (int i = 0; i < 3; i++) {
        if (a[i][0] == a[i][1] && a[i][1] == a[i][2] && a[i][0] != ' ' && a[i][0] == 'x') {
            printf("*****PLAYER 1 WIN*****\n");
            return a[i][0]; // Người chơi sở hữu hàng ngang này chiến thắng
        }
        else if (a[i][0] == a[i][1] && a[i][1] == a[i][2] && a[i][0] != ' ' && a[i][0] == 'o') {
            printf("*****PLAYER 2 WIN*****\n");
            return a[i][0];
        }
    }
    
        // Kiểm tra cột dọc
    for (int i = 0; i < 3; i++) {
        if (a[0][i] == a[1][i] && a[1][i] == a[2][i] && a[0][i] != ' ' && a[0][i] == 'x') {
            printf("*****PLAYER 1 WIN*****\n");
            return a[0][i]; // Người chơi sở hữu cột dọc này chiến thắng
        }
        if (a[0][i] == a[1][i] && a[1][i] == a[2][i] && a[0][i] != ' ' && a[0][i] == 'o') {
            printf("*****PLAYER 2 WIN*****\n");
            return a[0][i];
        }
    }
    
            // Kiểm tra đường chéo chính
        if (a[0][0] == a[1][1] && a[1][1] == a[2][2] && a[0][0] != ' ' && a[0][0] == 'x') {
            printf("*****PLAYER 1 WIN*****\n");
            return a[0][0]; // Người chơi sở hữu đường chéo chính chiến thắng
            }
        if (a[0][0] == a[1][1] && a[1][1] == a[2][2] && a[0][0] != ' ' && a[0][0] == 'o') {
            printf("*****PLAYER 2 WIN*****\n");
            return a[0][0]; // Người chơi sở hữu đường chéo chính chiến thắng
            }
    
            // Kiểm tra đường chéo phụ
        if (a[0][2] == a[1][1] && a[1][1] == a[2][0] && a[0][2] != ' ' && a[1][1] == 'x') {
            printf("*****PLAYER 1 WIN*****\n");
            return a[0][2]; // Người chơi sở hữu đường chéo phụ chiến thắng
            }
        else if (a[0][2] == a[1][1] && a[1][1] == a[2][0] && a[0][2] != ' ' && a[1][1] == 'o') {
            printf("*****PLAYER 2 WIN*****\n");
            return a[0][2]; // Người chơi sở hữu đường chéo phụ chiến thắng
            }
    
            // Kiểm tra xem còn ô trống nào hay không
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (a[i][j] == ' ') {
                        return 0; // Còn ô trống, chưa có người chiến thắng
                    }
                }
            }
    
            // Hòa
                printf("DRAW\n");
                return 3;
        }

void boardfight(char a[3][3]){
    //In ra bảng cập nhật sau khi người chơi đã đánh
    for(int i = 0; i < 3; i++){
        printf("|");
        for(int j = 0; j < 3; j++){
            printf("%c|", a[i][j]);
        }
        printf("\n");
    }
}
void tiktactoe2(){
    taobang();
    displayBoard(); // In ra bảng trống
    int fight; //Là ô số người chơi đánh
    int row = 0; //Hàng
    int col = 0; //Cột
    int i = 9;
    while(i >= 1){
        printf("Turn %d\n", 10 - i);
        if(i % 2){
            printf("Turn Player 1(x):");
        }
        else{
            printf("Turn Player 2(o):");
        }
        scanf("%d", &fight);
        printf("-----------------------\n");

        // Lưu vị trí người chơi đánh
        if(fight == 1){ row = 0; col = 0;}
        else if(fight == 2){ row = 0; col = 1;}
        else if(fight == 3){ row = 0; col = 2;}
        else if(fight == 4){ row = 1; col = 0;}
        else if(fight == 5){ row = 1; col = 1;}
        else if(fight == 6){ row = 1; col = 2;}
        else if(fight == 7){ row = 2; col = 0;}
        else if(fight == 8){ row = 2; col = 1;}
        else if(fight == 9){ row = 2; col = 2;}

        // Check xem đánh hợp lệ hay không thì mới lưu kí tự
        if(i % 2 == 1 && checkMove(row, col) == 1){
            makeMove(a, row, col, 'x');
            boardfight(a);
        }
        else if(i % 2 == 1 && checkMove(row, col) == 0){
            printf("Request to undo a move:\n");
      
            continue;
        }
        if(i % 2 == 0 && checkMove(row, col) == 1){
            makeMove(a, row, col, 'o');
            boardfight(a);
        }
        else if(i % 2 == 0 && checkMove(row, col) == 0){
            printf("Request to undo a move:\n");
            continue;
        }
        i--;
        if(checkWin()){
            printf("END GAMES\n\n");
            break;
        }
    }
    printf("Look back at the results\n");
    boardfight(a); //In ra kết quả cuối cùng
    printf("---------END!---------\n");
    printf("\n");
}


int main(void) {
    int lc;
    while(1){
        printf("~~~~~~~~~~~TICTAKTOE~~~~~~~~~~~\n");
        printf("[1.Learn the rules of the game]\n");
        printf("[2.Start                      ]\n");
        printf("[0.Exit games                 ]\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("CHOOSE: ");
        scanf("%d", &lc);
        if(lc == 1){
            tiktactoe1();
        }
        else if(lc == 2){
            int lc1;
            while(1){
                printf("----------Select game mode----------\n");
                printf("{ 1.Two Player                     }\n");
                printf("{ 2.Play against the computer      }\n");
                printf("{ 0.Return to the initial interface}\n");
                printf("------------------------------------\n");
                printf("CHOOSE: ");
                scanf("%d", &lc1);
                if(lc1 == 1){
                    tiktactoe2();
                }
                else if(lc1 == 2){
                    printf("This mode has not been updated yet\n\n");
                }
                else if(lc1 == 0){
                    break;
                }
            }
        }
        else if(lc == 0){
            printf("You've exited the game. If you want to continue playing, please run the code again\n");
            return 0;
        }
    }
    return 0;
}