#
# ncgb2: This was my degree thesis project. It consist of a library for computing Gröbner basis in the free algebra.
#
# This file runs package tests. It is also referenced in the package
# metadata in PackageInfo.g.
#
LoadPackage( "ncgb2" );

TestDirectory(DirectoriesPackageLibrary( "ncgb2", "tst" ),
  rec(exitGAP := true));

FORCE_QUIT_GAP(1); # if we ever get here, there was an error
