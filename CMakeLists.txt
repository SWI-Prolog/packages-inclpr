cmake_minimum_required(VERSION 3.5)
project(swipl-inclpr)

include("../cmake/PrologPackage.cmake")

set(INCLPR_PRV inclpr_core.pl inclpr_consistency.pl inclpr_inversion.pl
    inclpr_interval_arithmetic.pl inclpr_symbolic_processing.pl
    inclpr_natural_interval_extension.pl inclpr_newton.pl inclpr_ordering.pl)

swipl_plugin(inclpr_priv
	     NOINDEX
	     PL_LIB_SUBDIR clp/inclpr
	     PL_LIBS ${INCLPR_PRV})

swipl_plugin(inclpr
	     C_SOURCES inclpr.c
	     PL_LIB_SUBDIR clp
	     PL_LIBS inclpr.pl)

swipl_examples(benchmarks.pl)

# Doesn't work as this is not enough to make chr run from the
# build directory
if(0)
test_libs(
    inclpr
    PACKAGES chr
    PARENT_LIB)
endif()
