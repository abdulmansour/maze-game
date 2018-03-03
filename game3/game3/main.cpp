#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main () {
  //write a program which generates a maze (entry point along a path to exit point)
    
    int height = 20;
    int width = 20;
    char maze[height][width];
    
    srand(unsigned(time(NULL)));
    
    int entry_point = rand()%(height-5) + 2;
    int break_path = rand()%(width-2) + 1;
    int exit_point = rand()%(height-5) + 2;
    int upper_wall_entry = entry_point - 1;
    int lower_wall_entry = entry_point + 1;
    int upper_wall_exit = exit_point - 1;
    int lower_wall_exit = exit_point + 1;
    int right_wall = break_path + 1;
    int left_wall = break_path - 1;
    
    for (int i = 0; i < height; i++) { //maze creation
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height-1 || j == 0 || j == width-1) {
                maze[i][j] = '*';
            }
            else {
                maze[i][j] = ' ';
            }
            if ((i == entry_point && j==0) || (i == exit_point && j==width-1)) {
                maze[i][j] = ' ';
            }
            if(entry_point <= exit_point) {
                if(i == upper_wall_entry && j <= right_wall) {
                    maze[i][j] = '*';
                }
                else if(i == lower_wall_entry && j <= left_wall) {
                    maze[i][j] = '*';
                }
                else if(j == left_wall && i <= lower_wall_exit && i >= lower_wall_entry) {
                    maze[i][j] = '*';
                }
                else if(j == right_wall && i <= upper_wall_exit && i >= upper_wall_entry) {
                    maze[i][j] = '*';
                }
                else if(i == upper_wall_exit && j >= right_wall) {
                    maze[i][j] = '*';
                }
                else if(i == lower_wall_exit && j >= left_wall) {
                    maze[i][j] = '*';
                }
            }
            else if(entry_point > exit_point) {
                if(i == upper_wall_entry && j <= left_wall) {
                    maze[i][j] = '*';
                }
                else if(i == lower_wall_entry && j <= right_wall) {
                    maze[i][j] = '*';
                }
                else if(j == left_wall && i <= upper_wall_entry && i >= upper_wall_exit) {
                    maze[i][j] = '*';
                }
                else if(j == right_wall && i <= lower_wall_entry && i >= lower_wall_exit) {
                    maze[i][j] = '*';
                }
                else if(i == upper_wall_exit && j >= left_wall) {
                    maze[i][j] = '*';
                }
                else if(i == lower_wall_exit && j >= right_wall) {
                    maze[i][j] = '*';
                }
                
            }
        }
    }
    int x = entry_point;
    int y = 0;
    char move;
    
    char * movement = &maze[x][y];
    *movement = 'x';
    
    while(true) { // user controls runner around maze
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                cout << maze[i][j];
            }
            cout << endl;
        }
        if (movement == &maze[exit_point][width-1]) { //game ends once exit_point reached
            cout << endl << "Maze Completed!!" << endl;
            break;
        }
        cout << endl << "Move w(up) a(left) s(down) d(left): " << flush;
        cin >> move;
        cout << "---------------------" << endl << endl;
        
        if (move == 'w'){
            if (maze[x-1][y] != '*') {
                x--;
            }
        }
        else if (move == 's') {
            if (maze[x+1][y] != '*') {
                x++;
            }
        }
        else if (move == 'a') {
            if(y != 0) {
                if(maze[x][y-1] != '*') {
                    y--;
                }
            }
        }
        else if (move == 'd') {
            if(maze[x][y+1] != '*') {
                y++;
            }
        }
        *movement = ' ';
        movement = &maze[x][y];
        *movement = 'x';
    }
}