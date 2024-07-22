#pragma once

#include <iostream>

class Leaf {
    private:
        std::string value;
    public:
        std::vector<Leaf *> after;

        Leaf() {};
        Leaf(std::string v) {
            this->value = v;
        };

        void link_after(Leaf * a) {
            after.push_back(a);
        };

        std::string getValue() {
            return value;
        };

};