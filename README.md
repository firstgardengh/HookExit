# HookExit
This project hooks the exit function with a simple inline hook, replaces it with the destination function and uses an alternative method to exit.

# Usage
Usage for this would be to debug applications before they exit.

# Functions
You can add your own functions to hook, simply specify `detour(&source, &destination)`.

# Compatibility
This project is only compatible with x64 programs.
