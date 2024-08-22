#include <caml/alloc.h>
#include <caml/fail.h>
#include <caml/memory.h>
#include <caml/mlvalues.h>

#if defined(_WIN32) || defined(_WIN64)
#define SYSTEM_NAME "Windows"
#elif defined(__linux__)
#define SYSTEM_NAME "Linux"
#elif defined(__APPLE__) && defined(__MACH__)
#define SYSTEM_NAME "macOS"
#else
#define SYSTEM_NAME "Unknown System"
#endif

CAMLprim value c_string_alloc(value unit) {
  CAMLparam1(unit);
  CAMLlocal1(ocaml_string);

  const char *c_str = "Hello from " SYSTEM_NAME "!";
  ocaml_string = caml_copy_string(c_str);

  CAMLreturn(ocaml_string);
}
