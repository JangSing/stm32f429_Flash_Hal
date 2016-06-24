Example of Building DLL and Building An Application That Relies on It
====================================================================

Commands
--------
All available commands can be listed by typing:
```
rake -T
```
Commands for this demonstration are:
```
rake build:dll
rake build:main
```

Building DLL
------------
To build DLL file, type:
```
rake build:dll
```
which compiles `TestDll.c` into DLL library. All output files are stored in `build/realease/dll/` folder, including the DLL.

Building Application
--------------------
To build the application that relies on the DLL, type:
```
rake build:main
```
which compiles `src/main/main.c` to `build/realease/dll/main.exe`. Invoking this command automatically invokes the building of the DLL if necessary.

To execute `main.exe`, type:
```
./build/realease/dll/main.exe
```

Note
----
To run `main.exe` successfully, the `TestDll.dll` should be visible to the program. The simplest way is to place it in the same folder as `main.exe` or do any of the following:
- Move/copy `TestDll.dll` into `Windows/System32` folder
- Include the path to `TestDll.dll` in the system PATH

Limitation
==========
If the script is used together with `Unity Ceedling`, it is best to not use namespaces and task names that have been predefined by the framework. It may conflict with its proper operations, eg. `release`.
