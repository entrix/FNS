#include "iterationscheme.h"


namespace twoDimensional {

    using namespace std;

    IterationScheme::IterationScheme(int nx, int ny)
    {
        this->nx = nx;
        this->ny = ny;
        init(nx, ny);
    }

    IterationScheme::IterationScheme(int nx, int ny, double x0, double xl, double y0, double yl)
    {
        this->nx = nx;
        this->ny = ny;
        init(nx, ny, x0, xl, y0, yl);
    }

    IterationScheme::~IterationScheme() {
        delete prevLattice;
        delete nextLattice;
    }

    void  IterationScheme::init(int nx, int ny)
    {
        prevLattice = new Lattice(nx, ny, true);
        nextLattice = new Lattice(nx, ny, false);
    }

    void  IterationScheme::init(int nx, int ny, double x0, double xl, double y0, double yl)
    {
        init(nx, ny);
        this->x0 = x0;
        this->xl = xl;
        this->y0 = y0;
        this->yl = yl;
        this->hx = fabs(x0 - xl) / nx;
        this->hy = fabs(y0 - yl) / ny;
    }

    void IterationScheme::printConsole()
    {
        nextLattice->printConsole();
    }
}
