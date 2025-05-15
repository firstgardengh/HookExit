# HookExit
This project hooks the exit function with a simple inline hook, replaces it with the destination function and uses an alternative method to exit.

# Functions
You can add your own functions to hook, simply call `detour(&source, &destination)` where `source` is your specified function.

# Compatibility
This project is only compatible with x64 programs.
