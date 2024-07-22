#include <iostream>
#include "A.cpp"


class singleton 
{
public:

    static const int a = 0; // This must be constant, else it will be modified,
    // but static attributes must be initialized only the first time!!! This is not
    // guaranteed when we work with primitive types??
    static A b;
    // Here b is initialized?? No! should be const? But only because it is static!!

    // Static method (proper of the class). Returns the memory index of an object of class singleton:
	static singleton& get_instance() 
    {   
        std::cout << "A call to get_instance() has been made!" << std::endl;
		// Not explicitly declared, so the default constructor is called!
        // A reference to a "singleton" object is created, if not instanciated,
        // A call to the default constructor is made.
        // Else a reference to a "singleton" object is created and returned!
        static singleton instance; // Here I call the constructor and instantiate with value false??
        // Being static it is a variable associated with the class.
        // So it is not destroyed at the end of this method, althought only here
        // it can be referenced!
        // Only initialized the first time??
        // But only if it is here inside a static method??
        // It is initialized only once, before the program starts??
        // It is initialized only once, but not before the program starts? Only when the
        // actual static function is called! Because it is inside a function!

        // If I already called this function, why it does not call the constructor? Yet instantiated??
        // Same memory address??
        // Why I don't get a redefinition of instance error?
        // Because we are inside a function??
        // When I exit the function I don't have the reference instance anymore, but I
        // return the memory address, so I can keep it and use it!
        // But every time I call this function, should I call the Constructor?
        // Why not?? It is a static variable, so it is proper of the class!
        // Is reference instance variable destroyed here after returning the address?
        // Is not it dangerous??
		return instance;
	}
	
	bool method() 
	{ 
	    return m_something; 
	}
	
protected:
    //contesto del singoletto 
    bool m_something;
    // Il costruttore dichiarato come privato
	singleton() : m_something(false) { // Sto chiamando il costruttore del tipo primitivo bool con argomento valore false.
    // Usando : ... come se stessi facendo discendere il costruttore da un'altro?
    // Ovverride del metodo? No, esegue prima il metodo padre e poi il figlio!
    // Lo si può quindi fare anche per costruttori di classi definite dall'utente!
        std::cout << "Chiamata al costruttore!" << std::endl;
    }
	// stessa cosa per il costruttore di copia, basta dichiararlo privato, 
	// in quanto viene automaticamente generato dal compilatore 
	// (N.B. eccezion fatta per dllexport, usando MSVC)
    // This constructor is called when "=" operator si used!
    // It is also used in the initializatin list!
    // Used also when I give to a function a reference to a class type and return values!
	singleton(const singleton&);
	// stessa cosa per l'operatore di assegnamento: basta dichiararlo privato.
    void operator=(const singleton&);
};