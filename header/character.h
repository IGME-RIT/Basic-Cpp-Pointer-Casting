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


class Character
{

public:
    Character(int level);
    virtual void PrintClass() = 0;  // The virtual keyword makes it so that this function can be overriden.
    void PrintStats();              // Normally, a subclass could define the same function, and the one that is called will depend
                                    // On what variable it's being used as at the time. With virtual functions, the derived
                                    // classes function will always be used instead. This is helpful when we want to use a generic
                                    // variable to contain a less generic one.

                                    // = 0; defines this function to be pure virtual.
                                    // This means that the character class will not give any definition for the function.
                                    // Because of this, every derived class will be required to override this function.
                                    // It also makes it impossible to have an object of type Character,
                                    // because then calling the function would be impossible. 


protected:
    int m_level;
    int m_strength;
    int m_dexterity;
    int m_intelligence;
};