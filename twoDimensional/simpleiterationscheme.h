#ifndef SIMPLEITERATIONSCHEME_H
#define SIMPLEITERATIONSCHEME_H

#include <iostream>
#include <exception>
#include <string>
#include "iterationscheme.h"
#include "schemeexception.h"
#include "lattice.h"
#include "cmath"

namespace twoDimensional {

    class SimpleIterationScheme : public IterationScheme
    {
        double LiebmannSolution(int i, int j);
        double euclidNorm();
        void swap();
    public:
        SimpleIterationScheme(int nx, int ny);
        SimpleIterationScheme(int nx, int ny, double x0, double xl, double y0, double yl);
        virtual void execute(double eps);
    };

}

#endif // SIMPLEITERATIONSCHEME_H
