#include <exception>
#include "test.h"

#include <R.h>
#include <Rinternals.h>

extern "C" SEXP do_catch(SEXP x) {

  int status = 0;
  try {
    do_throw();
    return R_NilValue;
  } catch(std::exception& e) {
    Rprintf("Caught exception: '%s'\n", e.what());
    status = 1;
  }

  if (status)
    Rf_error("ouch");

  return R_NilValue;
}
