#ifndef OCULOS_H
#define OCULOS_H

#include <objeto.h>

class Oculos : public Objeto
{
public:
    Oculos();
    Model3DS* model;

    void desenhar();
};

#endif // OCULOS_H
