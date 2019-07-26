Documentation Author: Niko Procopi 2019

This tutorial was designed for Visual Studio 2017 / 2019
If the solution does not compile, retarget the solution
to a different version of the Windows SDK. If you do not
have any version of the Windows SDK, it can be installed
from the Visual Studio Installer Tool

Welcome to the Pointer Casting Tutorial!
Prerequesites: Inheritence

Casting pointers allow you to take a pointer to an object 
of a child class, and cast the pointer, to treat the object
like its parent class. For example, if "fighter" is a child of
"character", you can cast a fighter pointer to be a character pointer,
and then that fighter will be treated like a character, not a fighter.