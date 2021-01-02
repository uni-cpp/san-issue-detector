Please, set this environment variables (/etc/environment as example on Linux)

# UBSAN_OPTIONS=print_stacktrace=1
MSAN_OPTIONS=poison_in_dtor=1
ASAN_OPTIONS=halt_on_error=0:detect_stack_use_after_return=1:check_initialization_order=true:strict_init_order=true:verbosity=0
