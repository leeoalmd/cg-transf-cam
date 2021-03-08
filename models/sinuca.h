#ifndef SINUCA_H
#define SINUCA_H

#include <objeto.h>

class Sinuca : public Objeto
{
public:
    Sinuca();
    Model3DS* model;

    void desenhar();
};

#endif // SINUCA_H
