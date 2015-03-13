#include <R.h>
#include <Rinternals.h>

#include <string>

extern "C" SEXP ouch() {
	std::string str;
	Rf_error("ouch");
	return R_NilValue;
}
