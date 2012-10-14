#include "simpleiterationscheme.h"

namespace twoDimensional {

    using namespace std;

    SimpleIterationScheme::SimpleIterationScheme(int nx, int ny)
        : IterationScheme(nx, ny)
    {
    }


    SimpleIterationScheme::SimpleIterationScheme(int nx, int ny, double x0, double xl, double y0, double yl)
        : IterationScheme(nx, ny, x0, xl, y0, yl)
    {
        cout << "--> nx = " << this->nx << " ny = " << this->ny << " hx = " << this->hx << " hy " << this->hy << endl;
    }

    double SimpleIterationScheme::LiebmannSolution(int i, int j)
    {
        double a1, a2, b1, b2, c;

        a1 = 1.0;
        a2 = 1.0;
        b1 = 0.0;
        b2 = 0.0;
        c = 4.0;

        return (a1 * (prevLattice->get(i + 1, j) + prevLattice->get(i - 1, j)) * (hy * hy)    +
                        a2 * (prevLattice->get(i, j + 1) + prevLattice->get(i, j - 1)) * (hx * hx) -
                        b1 *  prevLattice->get(i + 1, j) * hx * (hy * hy)                          -
                        b2 *  prevLattice->get(i, j + 1) * hy * (hx * hx))                         /
                        (c * (hx * hx) * (hy * hy) + 2 * a1 * (hy * hy) + 2 * a2 * (hx * hx) - b1 * hx * (hy * hy) - b2 * hy * (hx * hx));
    }

    double SimpleIterationScheme::euclidNorm()
    {
        double max = 0.0;
        double res;

        for (int i = 1; i < nx - 1; ++i)
            for (int j = 1; j < ny - 1; ++j) {
                res = fabs(nextLattice->get(i, j) - prevLattice->get(i, j));
                if (max < res) {
                //System.out.printf("max = [%3d, %3d] = %f\n", i, j, res);
                max = res;
                }
            }

        return max;
    }

    void SimpleIterationScheme::swap()
    {
        Lattice *swapLattice;

        //swap lattice
        swapLattice = prevLattice;
        prevLattice = nextLattice;
        nextLattice = swapLattice;
    }

    void SimpleIterationScheme::execute(double eps)
    {
        double norm;
        int numIter = 0;

//        this.epsilon = epsilon;

        //System.out.println("hx = " + hx + " hy = " + hy + " x0 = " + x0 + " lx = " + lx + " nx = " + nx);
        //analyticalSolution();

//        for (int i = 0; i < nx; ++i) {
//                yNext.get(0).set(i, phi21(i*hx));
//                yPrev.get(0).set(i, phi21(i*hx));
//        }

//        for (int i = 0; i < nx; ++i) {
//                yNext.get(ny - 1).set(i, phi22(i*hx));
//                yPrev.get(ny - 1).set(i, phi22(i*hx));
//        }

//        for (int j = 1; j < ny - 1; ++j) {
//                //linear interpolation
//                double x0 = phi11(j*hy);
//                double xl = phi12(j*hy);
//                double _hx = (xl - x0) / nx;
//                double x  = x0 + _hx;

//                yPrev.get(j).set(0, x0);
//                yNext.get(j).set(0, x0);

//                for (int i = 1; i < nx - 1; ++i, x += _hx) {
//                        yPrev.get(j).set(i, x);

////				if (j > 0 && j < ny - 1) {
//                                yNext.get(j).set(i, 0.0);
////					yPrev.get(j).set(i, 0.0);
////				}
////				else {
////					yNext.get(j).set(i, x);
////					yPrev.get(j).set(i, x);
////				}
//                }

//                yPrev.get(j).set(nx - 1, xl);
//                yNext.get(j).set(nx - 1, xl);
//        }

//        switch(EM) {
//        case Liebmann:
        //cycle iterations
        while (numIter < 10000) {
            for (int i = 1; i < nx - 1; ++i)
                for (int j = 1; j < ny - 1; ++j)
                    nextLattice->set(i, j, LiebmannSolution(i, j));

            norm = euclidNorm();

//            System.out.println("k = " + k + " norm = " + norm + "  " + epsilon);
            if (norm < eps)
                break;

            numIter++;
            swap();
            //printConsole();
            cout << "------------------" << endl;
            cout << "norm = " << norm << endl;
            cout << "------------------" << endl;
        }
//                break;
//        case Seidel:
//                while (true) {
//                        for (int i = 1; i < nx - 1; ++i)
//                                for (int j = 1; j < ny - 1; ++j)
//                                        yNext.get(j).set(i, SeidelSolution(i, j));

//                        if (norm() < epsilon)
//                                break;

//                        swap();
//                }
//                break;

//        case OverRelaxation:
//                double omega = getIterationParameter();

//                System.out.println("omega = " + omega);
//                while (true) {
//                        for (int i = 1; i < nx - 1; ++i)
//                                for (int j = 1; j < ny - 1; ++j)
//                                        yNext.get(j).set(i, OverRelaxationSolution(i, j, omega));

//                        norm = norm();
//                        System.out.println("k = " + k + " norm = " + norm + "  " + epsilon);
//                        if (norm < epsilon)
//                                break;

//                        k++;
//                        swap();
//                }
//                break;
//        }

        //testSolution();

        cout << "Number Iterations: " << numIter << endl;
    }
}
