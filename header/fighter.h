/*
Pointer Casting
(c) 2016
Author: David Erbelding
Written under the supervision of David I. Schwartz, Ph.D., and
supported by a professional development seed grant from the B. Thomas
Golisano College of Computing & Information Sciences
(https://www.rit.edu/gccis) at the Rochester Institute of Technology.
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.
This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#pragma once
#include "../header/character.h"

// Fighter inherits from Character using the public keyword.
// This means that any class can treat the fighter as if it's a character.
class Fighter : private Character
{
public:
    Fighter(int level);
    virtual void PrintClass() override; // The override keyword is not required.
                                        // It does however, help the compiler know that we intend this function to override something.
                                        // This can be helpful, for example in the situation where the names don't match.
                                        // The compiler would complain that there's no function to override.
                                        // Without the override keyword, the compiler will just assume that it's a different function.
};