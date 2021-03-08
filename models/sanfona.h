#ifndef SANFONA_H
#define SANFONA_H

#include <objeto.h>

class Sanfona : public Objeto
{
public:
    Sanfona();
    Model3DS* model;

    void desenhar();
};

#endif // SANFONA_H
