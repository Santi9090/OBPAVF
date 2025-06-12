#ifndef SESION_H
#define SESION_H

class Sesion {
    private:
        static Sesion* instancia;
        Usuario *usuario;
        Sesion();
    public:
        static Sesion* getInstancia();
        void setUsuario(Usuario *usuario);
        Usuario* getUsuario();
        ~Sesion();
};

#endif