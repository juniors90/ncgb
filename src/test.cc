extern "C" {
#include <gap_all.h>    // GAP headers
}

#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>    // Para memcpy
#include <gmpxx.h>
#include <sstream>    // Agrega esta línea al inicio del archivo
#include <string>     // Para memcpy

#include "ncgb/Buchberger.hpp"

using namespace std;
using namespace ncgb;
#include "ncgb/F4.hpp"
#include <flint/fmpq.h>
#include <flint/fmpq_mat.h>


typedef Poly<mpq_class> P;


typedef mpq_class R;
typedef Poly<R> PM;


P ObjToPoly(Obj p) {


    if (LEN_LIST(p) != 2) {
        // Dar error
    }

    Obj monomios = ELM_LIST(p, 1);
    Obj coes = ELM_LIST(p, 2);

    Int N = LEN_LIST(monomios);

    vector<pair<Monomial, mpq_class> q(N);

    for (Int i = 1; i <= N; i++) {
        Obj monomio = ELM_LIST(monomios, i);
        Int M = LEN_LIST(monomio);
        vector<__uint8_t> vals(M);
        for (Int j = 1; j <= M; j++) {
            vals[j] = INT_INTOBJ(ELM_LIST(monomio, j));
        }
        q[i].first = Monomial(vals);
        q[i].second = INT_INTOBJ(ELM_LIST(coes), i);
    }

    return P(q);
}


void FuncTestFalopa(Obj self, Obj p) {
    P p2 = ObjToPoly(p);
    p2.nice_print();
}


