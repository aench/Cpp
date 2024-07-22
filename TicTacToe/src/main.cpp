#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

#include "Game.cpp"
#include "Engine.cpp"
#include "FieldTable.cpp"
#include "Tree.cpp"
#include "Leaf.cpp"
#include "EngineMove.cpp"
#include "MovesTree.cpp"
#include "MoveLeaf.cpp"


int main() {

    // Qui ho messo a mano le strutture, bisognerebbe metterle in automatico
    // che le salva ad ogni partita.
    // Bisogna salvare un vettore di afters!!
    // I before non servono mi sembra!

    // 1. Rendi il codice tale che mi salva da solo le partite.

    Leaf * leaf1 = new Leaf("100000000");
    Leaf * leaf2 = new Leaf("100020000");
    Leaf * leaf3 = new Leaf("100120000");
    Leaf * leaf4 = new Leaf("100000002");

    leaf3->after.push_back(NULL);
    leaf2->after.push_back(leaf3);
    leaf1->after.push_back(leaf2);
    leaf1->after.push_back(leaf4);
    leaf4->after.push_back(NULL);

    // Qui posso semplicemente salvare la lista, tanto sono linkati di per sé.

    // Quando poi la leggo devo riuscire a costruire un MovesTree!

    std::ofstream memory_write("../memory/tree.csv");
    if (memory_write.is_open()) {
        memory_write << "begin" << std::endl;
        
        memory_write << leaf1 << ";";
        memory_write << leaf1->after[0];
        for (int i =1;i<leaf1->after.size();i++) {
            memory_write << "," << leaf1->after[i];
        }
        memory_write << ";" << leaf1->getValue() << std::endl;

        memory_write << leaf2 << ";";
        memory_write << leaf2->after[0];
        for (int i =1;i<leaf2->after.size();i++) {
            memory_write << "," << leaf2->after[i];
        }
        memory_write << ";" << leaf2->getValue() << std::endl;

        memory_write << leaf3 << ";";
        memory_write << leaf3->after[0];
        for (int i =1;i<leaf3->after.size();i++) {
            memory_write << "," << leaf3->after[i];
        }
        memory_write << ";" << leaf3->getValue() << std::endl;
        
        memory_write << leaf4 << ";";
        memory_write << leaf4->after[0];
        for (int i =1;i<leaf4->after.size();i++) {
            memory_write << "," << leaf1->after[i];
        }
        memory_write << ";" << leaf4->getValue() << std::endl;

        memory_write << "end" << std::endl; 
        memory_write.close();
    } else std::cout << "Unable to open file";

    std::cout << std::endl;
    std::cout << std::endl;


    std::ifstream memory_read("../memory/tree.csv");

    std::vector<MoveLeaf> leaf_list;
    leaf_list.clear();

    std::string line;
    if (memory_read.is_open()) {
        while(getline(memory_read,line)) {
            if (line!="begin" & line!="end") {
            std::vector<std::string> result;
            std::stringstream check1(line);
            std::string intermediate;
            // Tokenizing w.r.t. ';'
            while(getline(check1, intermediate, ';'))
            {result.push_back(intermediate);};

            std::cout << "Result Token 0: " << result[0] <<  std::endl;
            std::cout << "Result Token 1: " << result[1] <<  std::endl;
            std::cout << "Result Token 2: " << result[2] <<  std::endl;

            std::vector<std::string> result_after;
            std::stringstream check2(result[1]);
            // Tokenizing w.r.t. ';'
            while(getline(check2, intermediate, ','))
            {result_after.push_back(intermediate);};

            MoveLeaf * leaf = new MoveLeaf(result[0],result_after,result[2]);
            leaf_list.push_back(*leaf);
            };
        };
        memory_read.close();
    } else std::cout << "Unable to open memory file";


// Voglio assegnare al puntatore after dell'elemento 0 della lista
// L'indirizzo dell'elemento 1 della lista:

for (int i = 0;i<leaf_list.size();i++) {
    for (int k=0;k<leaf_list[i].getAft().size();k++) {
        for (int j=0;j<leaf_list.size();j++) {
            if(leaf_list[i].getAft()[k]==leaf_list[j].getCur()) {
                leaf_list[i].after.push_back(&leaf_list[j]);
            };
        };
    };
};

// leaf_list[0].after=&leaf_list[1];
// Stampo il valore dell'elemento puntato da after dell'elemento 0 della lista
std::cout << "Afters of element: " << leaf_list[0].getValue() << std::endl;
for (int i =0;i<leaf_list[0].after.size();i++) {
    std::cout << leaf_list[0].after[i]->getValue() << std::endl;
}

std::cout << "Afters of element: " << leaf_list[1].getValue() << std::endl;
for (int i =0;i<leaf_list[1].after.size();i++) {
    std::cout << leaf_list[1].after[i]->getValue() << std::endl;
}

MovesTree tree = MovesTree(leaf_list);

std::cout << "Cerco di far trovare la mossa all'engine:" << std::endl;
EngineMove move = tree.findNext("100000000");
std::cout << move.get_x() << ";" << move.get_y() << std::endl;

// Prendo una leaf.
// Prendo i suoi valori di after.
// Cerco tutti quelli che hanno quel valore come current.
// Metto after di quello di partenza i valori trovati.
// Metto before delle leaf trovate quelle trovate.


// Tolgo il before?? ==========
// Prendo una leaf.
// Prendo i suoi valori di after.
// Cerco tutti quelli che hanno quel valore come current.
// Metto after di quello di partenza i valori trovati.
/*
MovesTree tree = MovesTree();
    
    for (MoveLeaf leaf: leaf_list) {
        // Prendo tutto i valori di after:
        int a = leaf.getAft();
        Leaf * leaf1;
        if (tree.find(leaf.getValue()).getValue()=="Null") {
            leaf1 = new Leaf(leaf.getValue());
        } else {
            leaf1 = &tree.find(leaf.getValue());
        };
        for (MoveLeaf leaf_c: leaf_list) {
            int c = leaf_c.getCur();
            if (c==a) {
                Leaf * leaf2;
                if (tree.find(leaf_c.getValue()).getValue()=="Null") {
                    leaf2 = new Leaf(leaf_c.getValue());
                } else {
                    leaf2 = &tree.find(leaf_c.getValue());
                };
            leaf1->after=leaf2;
            tree.add(*leaf1);
            tree.add(*leaf2);
            };
        };
    };


tree.print();
*/




/*
std::string line_before = std::string(line.begin(),std::find(line.begin(),line.end(),";"));
std::string line_after = std::string(line.begin(),std::find(line.begin(),line.end(),";"));
*/

/*
std::cout << "line_before: " << line_before << std::endl;
std::cout << "line_after: " << line_after << std::endl;
*/

/*
    FieldTable field;
    field.print();
    field.movePlayer(1,1);
    field.moveEngine(2,2);
    
    Engine engine;
    engine.memorize("../memory/level_1.csv",&field);

    std::ifstream memory_read("../memory/level_1.csv");

    std::string line;
    if (memory_read.is_open()) {
        while (getline (memory_read,line)) {
            std::cout << line << '\n';
        };
    memory_read.close();
    } else std::cout << "Unable to open file"; 


    Game::get_instance();
    int x = Game::get_instance().get_engine()->findNextMove().get_x();
    int y = Game::get_instance().get_engine()->findNextMove().get_y();
    
    Game::get_instance().get_field()->moveEngine(x,y);
    Game::get_instance().get_field()->print();
*/
    return 0;
};