#ifndef LATTICE_H
#define LATTICE_H

#include <iostream>
#include <exception>
#include <string>
#include <cstdlib>
#include "schemeexception.h"

namespace twoDimensional {

    class Lattice
    {
        int sx, sy;
        double *nodes;
    public:
        Lattice(int sx, int sy);
        Lattice(int sx, int sy, bool rnd);
        ~Lattice();
        void init(int sx, int sy, bool rnd);
        double get(int ix, int iy);
        void set(int ix, int iy, double val);
        void printConsole();
    };

}

#endif // LATTICE_H
