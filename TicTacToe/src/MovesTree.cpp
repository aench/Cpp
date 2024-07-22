#pragma once

#include "Tree.cpp"
#include "Leaf.cpp"
#include "MoveLeaf.cpp"
#include "EngineMove.cpp"

class MovesTree : public Tree {
    private:
        std::vector<MoveLeaf> crown;
    public:
    MovesTree() : Tree() {};
    MovesTree(std::vector<Leaf> c) : Tree(c){};
    MovesTree(std::vector<MoveLeaf> c) {
        crown=c;
    };

    EngineMove findNext(std::string str) {
        MoveLeaf leaf;
        bool found = false;
        for (MoveLeaf l : crown) {
            if(l.getValue()==str) {
                leaf=l;
                found=true;
            };
        };
        EngineMove move;
        if (found) {
            srand(time(0));
            int ext = rand() % leaf.after.size();
            std::cout << leaf.getValue() << ";" << leaf.after[ext]->getValue() << std::endl;;
            move = EngineMove(leaf.getValue(),leaf.after[ext]->getValue());
            return move;
        } else {
            std::cerr << "Move not found!" << std::endl;
            return move;
        };
    };

    int dim() {
        return crown.size();
    };
};