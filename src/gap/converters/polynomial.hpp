#pragma once

extern "C" {
#include <gap_all.h>    // GAP headers
}

#include <gmpxx.h>
#include "ncgb/Buchberger.hpp"

namespace ncgb_gap {

using P = ncgb::Poly<mpq_class>;

// Convierte un objeto GAP (lista [monomios, coeficientes]) a un Poly<mpq_class>
P ObjToPoly(Obj p);

// Convierte un Poly<mpq_class> a un objeto GAP (lista [monomios, coeficientes])
Obj PolyToObj(const P& p);

} // namespace ncgb_gap