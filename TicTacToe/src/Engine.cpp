#pragma once

#include <iostream>
#include <vector>

#include "EngineMove.cpp"
#include "FieldTable.cpp"
#include "MovesTree.cpp"

class Engine {
    private:
        unsigned int level;
        MovesTree tree_of_moves;
    public:
        Engine() {
            this->level=0;
        };

        Engine(int i) {
            this->level=i;
        };
    
    
        EngineMove findNextMove(std::string current_position) {
            if (level==0) { // Pure random moves
                std::vector<int> position_vector;
                for (int i=0;i<current_position.size();i++) {
                    if (current_position[i]=='0') {
                        position_vector.insert(position_vector.begin(),i);
                    }
                };
                srand(time(0));
                int r_number = rand() % position_vector.size();
                return EngineMove(position_vector[r_number] / 3 + 1,position_vector[r_number] % 3 + 1);
            } else {
                srand(time(0));
                return EngineMove(rand() / 3 + 1,rand() % 3 + 1);
            }
        };

        void memorize(std::string file_name,FieldTable * field){
            std::ofstream memory_write(file_name);
            std::string line;
            if (memory_write.is_open()) {
                for (int i=0;i<9;i++) {
                    memory_write << field->getMatrixElement(i) << ";";
                }
                memory_write << std::endl;    
            memory_write.close();
            } else std::cout << "Unable to open file"; 
        };

        void recall(std::string file_name) {
            std::ifstream memory_read(file_name);
            std::string line1;
            std::string line2;

            if (memory_read.is_open()) {
                while (line2!="end") {
                getline(memory_read,line1);
                if (line1=="begin") {
                    std::cout << line1 << std::endl;
                } else {
                    getline(memory_read,line2);
                    std::cout << "line1: " << line1 << std::endl;
                    std::cout << "line2: " << line2 << std::endl;
                };
            };
            memory_read.close();
            } else std::cout << "Unable to open memory file"; 
            };

};