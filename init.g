#
# ncgb: This was my degree thesis project. It consist of a library for computing Gröbner basis in the free algebra.
#
# Reading the declaration part of the package.
#
_PATH_SO:=Filename(DirectoriesPackagePrograms("ncgb"), "ncgb.so");
if _PATH_SO <> fail then
    LoadDynamicModule(_PATH_SO);
fi;
Unbind(_PATH_SO);

ReadPackage( "ncgb", "gap/ncgb.gd");
