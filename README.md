# The GAP package ncgb

TODO: add a description of your package; perhaps also instructions how how to
install and use it, resp. where to find out more


## Contact

TODO: add info on how to contact you and/or how to report issues with your
package

## License

TODO: Provide information on the license of your package. A license is
important as it determines who has a right to distribute your package. The
"default" license to consider is GNU General Public License v2 or later, as
that is the license of GAP itself.


# Quilombo de compiladores: Recompilar ncgb con libstdc++ correctamente

Si ncgb.so fue compilado sin vincularse a libstdc++, es necesario recompilarlo correctamente. Si tienes acceso al código fuente, prueba:

```shell
g++ -shared -o bin/x86_64-pc-linux-gnu-default64-kv9/ncgb.so gen/src/ncgb.o -L/usr/lib/x86_64-linux-gnu -lstdc++
```

Si ncgb.so fue compilado con gcc, pero usa C++, intenta recompilarlo con g++ en lugar de gcc para asegurar que libstdc++ se enlace correctamente

g++ -shared -Wall -Wextra -o bin/x86_64-pc-linux-gnu-default64-kv9/ncgb.so gen/src/ncgb.o -L/usr/lib/x86_64-linux-gnu -lstdc++


Obj FuncInIdeal_BuchbergerCofactor(Obj self, Obj n, Obj f, Obj listGenG, Obj steps)
{

    // Verificar que listGenG es una lista válida
    if (!IS_PLIST(listGenG)) {
        ErrorMayQuit("FuncInIdeal_BuchbergerCofactor: Se esperaba una lista de polinomios.", 0, 0);
        return Fail;
    }

    // Obtener el número de generadores
    Int numGen = LEN_LIST(listGenG);
    Obj nG = INTOBJ_INT(numGen);
    if (numGen == 0) {
        ErrorMayQuit("FuncInIdeal_BuchbergerCofactor: La lista de generadores está vacía.", 0, 0);
        return Fail;
    }

    // crear una const en C llamada cstr
    const char* cstr = "InIdeal";
    // Obtener la longitud de la cadena
    Int len = strlen(cstr);
    // Crear un nuevo objeto GAP para la cadena
    Obj inIdeal = NEW_STRING(len);
    // Copiar el contenido de cstr al objeto GAP
    memcpy(CSTR_STRING(inIdeal), cstr, len);

    // Crear la nueva cadena modificada
    std::string newGapStr = "Not" + std::string(cstr);
    // Longitud de la nueva cadena
    Int newLen = newGapStr.length();
    // Crear un nuevo objeto GAP con la longitud adecuada
    Obj notInIdeal = NEW_STRING(newLen);
    // Copiar la nuevaCadena al objeto GAP
    memcpy(CSTR_STRING(notInIdeal), newGapStr.c_str(), newLen);

    // crear una const en C llamada cstr
    const char* cstr2 = "Unknown";
    // Obtener la longitud de la cadena
    Int len2 = strlen(cstr2);
    // Crear un nuevo objeto GAP para la cadena
    Obj unk = NEW_STRING(len2);
    // Copiar el contenido de cstr al objeto GAP
    memcpy(CSTR_STRING(unk), cstr2, len2);

    // Crear objeto GAP para la respuesta
    const char* response;
    // Convertir n de Obj a un entero C
    Int nn = INT_INTOBJ(n);
    if (nn == 1) {
        response = "InIdeal";
    } else if (nn == 2) {
        response = "NotInIdeal";
    } else {
        response = "Unknown";
    }
    
    Int len3 = strlen(response);
    Obj result = NEW_STRING(len3);
    memcpy(CSTR_STRING(result), response, len3);
    
    return result;
}