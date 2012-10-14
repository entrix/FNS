#include "lattice.h"

namespace twoDimensional {

    Lattice::Lattice(int sx, int sy)
    {
        this->sx = sx;
        this->sy = sy;
        init(sx, sy, false);
    }

    Lattice::Lattice(int sx, int sy, bool rnd)
    {
        this->sx = sx;
        this->sy = sy;
        init(sx, sy, rnd);
    }

    Lattice::~Lattice()
    {
        delete [] nodes;
    }

    void Lattice::init(int sx, int sy, bool rnd)
    {
        if (sx <= 0 || sy <= 0 || sx >=100000 || sy >= 10000) {
            throw new SchemeException(new string("index range is invalid"));
        }

        nodes = new double[sx*sy];

        for (int i = 0; i < sx; ++i)
            for (int j = 0; j < sy; ++j)
                if (rnd)
                    nodes[i*sy + j] = (rand() % 10) / 10.0;
                else
                    nodes[i*sy + j] = 0.0;
    }

    double Lattice::get(int i, int j)
    {
        return nodes[i*sy + j];
    }

    void Lattice::set(int i, int j, double val)
    {
        nodes[i*sy + j] = val;
    }


    void Lattice::printConsole()
    {
        for (int i = 0; i < sx; ++i) {
            for (int j = 0; j < sy; ++j)
                cout << " " << nodes[i*sy + j];
            cout << endl;
        }
    }
}
