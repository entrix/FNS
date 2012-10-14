#ifndef ITERATIONSCHEME_H
#define ITERATIONSCHEME_H

#include <iostream>
#include <exception>
#include <string>
#include <cmath>
#include "schemeexception.h"
#include "lattice.h"

enum Layer { prev, next };

namespace twoDimensional {

    class IterationScheme
    {
    protected:
        double hx, hy;
        int nx, ny;
        double x0, xl;
        double y0, yl;
        Lattice *prevLattice;
        Lattice *nextLattice;

    public:
        IterationScheme(int nx, int ny);
        IterationScheme(int nx, int ny, double x0, double xl, double y0, double yl);
        ~IterationScheme();
        virtual void init(int nx, int ny);
        virtual void init(int nx, int ny, double x0, double xl, double y0, double yl);
        virtual void execute(double eps) = 0;
        virtual void printConsole();
    };

}

#endif // ITERATIONSCHEME_H
