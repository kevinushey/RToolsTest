#include <R.h>
#include <Rinternals.h>

#include <string>

#define PRINT_REGISTER(NAME)                                   \
{                                                              \
  register int reg asm(NAME);                                  \
  Rprintf("Register '%s': '%p'\n", NAME, reg);                 \
}                                                              \

#define PRINT_EXPR(EXPR)                                       \
  Rprintf(#EXPR ": '%p'\n", EXPR)

extern "C" void* mingw_getsp(void);

extern "C" SEXP ouch() {
	std::string str;
	Rf_error("ouch");
	return R_NilValue;
}

extern "C" SEXP frame_pointer() {
  PRINT_EXPR(mingw_getsp());
  PRINT_REGISTER("esp");
  PRINT_EXPR(__builtin_frame_address(0));
  PRINT_REGISTER("ebp");
  return R_NilValue;
}
