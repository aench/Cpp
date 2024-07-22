#include "Engine.cpp"
#include "FieldTable.cpp"

class Game {
    private:
        // Attibutes:
        Engine engine;
        FieldTable field;

        // Singleton DP.
        Game();
        Game(const Game&);
        void operator=(const Game&);
    public:
        // Singleton DP.
        static Game& get_instance() {
            static Game game;
            return game;
        }

        Engine * get_engine(){
            return &engine;
        }

        FieldTable * get_field(){
            return &field;
        }

};

Game::Game() {
    engine = Engine();
    field = FieldTable();
};