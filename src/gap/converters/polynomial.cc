#include "gap/converters/polynomial.hpp"

namespace ncgb_gap {

P ObjToPoly(Obj p) {

    if (LEN_LIST(p) != 2) {
        // Dar error
    }

    Obj monomios = ELM_LIST(p, 1);
    Obj coes = ELM_LIST(p, 2);

    Int N = LEN_LIST(monomios);

    std::vector<std::pair<ncgb::Monomial<>, mpq_class>> q(N);

    for (Int i = 1; i <= N; i++) {
        Obj monomio = ELM_LIST(monomios, i);
        Int M = LEN_LIST(monomio);
        std::vector<__uint8_t> vals(M);
        for (Int j = 1; j <= M; j++) {
            vals[j - 1] = INT_INTOBJ(ELM_LIST(monomio, j)) - 1;
        }

        q[i - 1].first = ncgb::Monomial(vals);
        q[i - 1].second = INT_INTOBJ(ELM_LIST(coes, i));
    }
    return P(q);
}

Obj PolyToObj(const P& p) {

    const auto& terms = p.terms;
    Int N = static_cast<Int>(terms.size());
    Obj monomios = NEW_PLIST(T_PLIST, N);
    Obj coes = NEW_PLIST(T_PLIST, N);

    SET_LEN_PLIST(monomios, N);
    SET_LEN_PLIST(coes, N);

    Int i = 1;

    for (const auto& term : terms) {

        const ncgb::Monomial<>& monomio = term.first;
        const mpq_class& coef = term.second;

        Int M = static_cast<Int>(monomio.vals.size());

        Obj monomioObj = NEW_PLIST(T_PLIST, M);
        SET_LEN_PLIST(monomioObj, M);

        for (Int j = 1; j <= M; ++j) {
            SET_ELM_PLIST(
                monomioObj,
                j,
                INTOBJ_INT(static_cast<Int>(monomio.vals[j - 1]) + 1)
            );
        }

        Obj coefObj = INTOBJ_INT(static_cast<Int>(coef.get_num().get_si()));

        SET_ELM_PLIST(monomios, i, monomioObj);
        SET_ELM_PLIST(coes, i, coefObj);

        ++i;
    }

    Obj result = NEW_PLIST(T_PLIST, 2);
    SET_LEN_PLIST(result, 2);

    SET_ELM_PLIST(result, 1, monomios);
    SET_ELM_PLIST(result, 2, coes);

    CHANGED_BAG(result);

    return result;
}

} // namespace ncgb_gap