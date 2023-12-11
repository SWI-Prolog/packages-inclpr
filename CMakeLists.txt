cmake_minimum_required(VERSION 3.5)
project(swipl-inclpr)

include("../cmake/PrologPackage.cmake")

set(INCLPR_PRV inclpr_core.pl inclpr_consistency.pl inclpr_inversion.pl
    inclpr_interval_arithmetic.pl inclpr_symbolic_processing.pl
    inclpr_natural_interval_extension.pl inclpr_newton.pl inclpr_ordering.pl)

swipl_plugin(inclpr_priv
	     NOINDEX
	     PL_LIB_SUBDIR inclpr
	     PL_LIBS ${INCLPR_PRV})

swipl_plugin(inclpr
	     NOINDEX
	     C_SOURCES inclpr.c
	     PL_LIBS inclpr.pl)

swipl_examples(benchmarks.pl)
