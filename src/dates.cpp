#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
SEXP ctor_mdy() {
  Date dt = Date(12,31,2005);
  return wrap(dt);
}

// [[Rcpp::export]]
SEXP ctor_ymd() {
  Date dt = Date(2005,12,31);
  return wrap(dt);
}

// [[Rcpp::export]]
SEXP ctor_int(int d) {
  Date dt = Date(d);
  return wrap(dt);
}
