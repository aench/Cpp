#pragma once

#include <vector>
#include "Leaf.cpp"

class Tree {
    private:
        std::vector<Leaf> crown;
    public:
        Tree(){};
        Tree(std::vector<Leaf> c){
            crown=c;
        };

        void add(Leaf leaf) {
            bool found = false;
            for(Leaf l : crown) {
                if (l.getValue()==leaf.getValue()) {
                    found = true;
                };
            };
            if (found==false) {crown.push_back(leaf);};
        };

};