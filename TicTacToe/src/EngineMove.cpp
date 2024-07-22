#pragma once

#include <iostream>

class EngineMove {
    private:
        int x;
        int y;
    public:
        EngineMove() {
            x=0;
            y=0;
        };
        EngineMove(int a,int b) {
            set_x(a);
            set_y(b);
        };

        EngineMove(std::string pre,std::string post) {

            if (pre.size()==post.size()) {

                unsigned int counter = 0;
                int position = -1;

                for (int i=0;i<pre.size();i++) {
                    // Check if only 1 character is different
                    counter = counter + (pre[i]!=post[i]);
                    // Get the different character:
                    if(pre[i]!=post[i]) {
                            position = i;
                        }
                };

                if (counter==1) {
                    if (post[position]=='2') {
                        // Build the engine move:
                        set_x(position / 3 + 1);
                        set_y(position % 3 + 1);
                    } 
                    else {
                        // Not the correct number!
                        std::cerr << "Not an Engine Move!" << std::endl;
                    };

                } else if (counter==0) { 
                    // Strings are the same!
                    std::cerr << "Strings are the same!" << std::endl;
                } else {
                    // Strings differ more than 1 character!
                    std::cerr << "Strings not one next to the other!" << std::endl;
                };
            } else {
                // Strings have different length!
                    std::cerr << "Strings have different length!" << std::endl;
            };

        };

        int get_x() {
            return x;
        };

        int get_y() {
            return y;
        };

        void set_x(int a) {
            if (a>0 & a<4) {
                this->x=a;
            } else {
                std::cerr << "Error: engine move out of bound!" << std::endl;
            };
        };

        void set_y(int b) {
            if (b>0 & b<4) {
                this->y=b;
            } else {
                std::cerr << "Error: engine move out of bound!" << std::endl;
            };
        };
};
