#
# ncgb2: This was my degree thesis project. It consist of a library for computing Gröbner basis in the free algebra.
#
# This file is a script which compiles the package manual.
#
if fail = LoadPackage("AutoDoc", "2018.02.14") then
    Error("AutoDoc version 2018.02.14 or newer is required.");
fi;

AutoDoc( rec( scaffold := true, autodoc := true ) );
