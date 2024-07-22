#pragma once

#include <iostream>
#include <fstream>

class FieldTable {
    private:
        unsigned int matrix[9];
    public:
        FieldTable() {
            for (int i=0;i<9;i++) {
                matrix[i] = 0;
            };
        };

        unsigned int check_win() {
            if (matrix[0]==matrix[1]==matrix[2]==1 | 
                matrix[3]==matrix[4]==matrix[5]==1 |
                matrix[6]==matrix[7]==matrix[8]==1 |
                matrix[0]==matrix[3]==matrix[6]==1 | 
                matrix[1]==matrix[4]==matrix[7]==1 |
                matrix[2]==matrix[5]==matrix[8]==1 |
                matrix[0]==matrix[4]==matrix[8]==1 | 
                matrix[2]==matrix[4]==matrix[6]==1) {
                    return 1;
            } else if (matrix[0]==matrix[1]==matrix[2]==2 | 
                       matrix[3]==matrix[4]==matrix[5]==2 |
                       matrix[6]==matrix[7]==matrix[8]==2 |
                       matrix[0]==matrix[3]==matrix[6]==2 | 
                       matrix[1]==matrix[4]==matrix[7]==2 |
                       matrix[2]==matrix[5]==matrix[8]==2 |
                       matrix[0]==matrix[4]==matrix[8]==2 | 
                       matrix[2]==matrix[4]==matrix[6]==2) {
                    return 2;
            } else {return 0;};
        };

        void movePlayer(int x,int y) {
            if (matrix[3*(x-1)+y-1]==0) {
                matrix[3*(x-1)+y-1] = 1;
            } else if (x>3 | x<0 | y>3 | y<0) {
                std::cout << "Move out of bounds!" << std::endl;
            } else {
                std::cout << "Posto già occupato!" << std::endl;
            };
        };

        void moveEngine(int x,int y) {
            if (matrix[3*(x-1)+y-1]==0) {
                matrix[3*(x-1)+y-1] = 2;
            } else if (x>3 | x<0 | y>3 | y<0) {
                std::cout << "Move out of bounds!" << std::endl;
            } else {
                std::cout << "Someone already played there!" << std::endl;
            };
        };

        unsigned int getMatrixElement(int i) {
            return matrix[i];
        };

        void print(){
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << "+-+-+-+" << std::endl;
            
            for (int i=0;i<9;i++) {
                if (i!=0 & i % 3 == 0) {
                    std::cout << "|" << std::endl;
                    std::cout << "+-+-+-+" << std::endl;
                }
                std::cout << "|";
                if (matrix[i]==0) {
                    std::cout << " ";
                } else {
                    std::cout << matrix[i];
                }
            }
            std::cout << "|" << std::endl;
            std::cout << "+-+-+-+" << std::endl;
            std::cout << std::endl;
            std::cout << std::endl;
        };
        
};