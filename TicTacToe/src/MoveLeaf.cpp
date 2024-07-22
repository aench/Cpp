#pragma once

#include "Leaf.cpp"
#include <iostream>

class MoveLeaf : public Leaf {
    private:
        std::vector<std::string> aft;
        std::string cur;
    public:
        MoveLeaf() : Leaf() {
        };
        MoveLeaf(std::string c,std::vector<std::string> a,std::string v) : Leaf(v) {
            setAft(a);
            setCur(c);
        };

        void setAft(std::vector<std::string> a) {this->aft=a;};
        void addAft(std::string a) {aft.push_back(a);};
        void setCur(std::string c) {this->cur=c;};
        std::vector<std::string> getAft() {return aft;};
        std::string getCur() {return cur;};

};