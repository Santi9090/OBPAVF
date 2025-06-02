#ifndef FABRICA
#define FABRICA
#include <iostream>
class Fabrica{
    private:
        static Fabrica* instancia;
        Fabrica();
    public:
        static Fabrica* getInstancia();
};
#endif