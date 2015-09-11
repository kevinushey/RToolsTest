#include <exception>
#include <stdexcept>

void do_throw() {
  throw std::range_error("ouch");
}
