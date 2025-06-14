# DLL Injection Template


This template adds CMake support and executable hash verification to
[Beginners Guide to Codecaves](https://web.archive.org/web/20240910225721/codeproject.com/Articles/20240/The-Beginners-Guide-to-Codecaves) sample project.
At the moment, only 32-bit executable injection targets are supported.

For convenience, it comes in two flavours:
- Combined (single CMakeLists.txt for both Loader and Patch targets)
- Separate (separate CMakeLists.txt for all targets)

A patch example utilising this template can be found [here](https://github.com/Casqade/FA-18E_SH_patch).


## CMake options

- `INJECTION_TARGET_FILENAME`: Target executable filename for DLL injection
- `INJECTION_TARGET_MD5`: Target executable MD5 hashsum
- `INJECTED_PATCH_FILENAME`: DLL patch filename for injection
- `ENABLE_CONSOLE`: Automatically create terminal window for the patch DLL


## References:
- [The Beginners Guide to Codecaves](https://www.codeproject.com/Articles/20240/The-Beginners-Guide-to-Codecaves)
- [A More Complete DLL Injection Solution Using CreateRemoteThread](https://www.codeproject.com/Articles/20084/A-More-Complete-DLL-Injection-Solution-Using-Creat)

