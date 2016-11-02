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

// Include iostream for output during the program.
#include <iostream>
using namespace std;

// These classes all inherit from the character class.
#include "../header/fighter.h"
#include "../header/ranger.h"
#include "../header/wizard.h"
#include "../header/necromancer.h"

int main() 
{
    cout << "Press enter to continue" << endl;
    cin.get();

    // Not only can you cast data in C++, you can also cast objects to other types of objects.
    {
        // The first kind of casting was used in the virtual functions example.
        // This line creates an necromancer objects, and then upcasts and copies it to a base type.
        // This kind of casting causes object slicing, and any data that would have previously existed is now gone.
        Necromancer necromancer = Necromancer(10);
        cout << "Calling PrintClass on necromancer type object:" << endl;
        necromancer.PrintClass();

        Wizard upCasted = necromancer;  // Implicit upcasting. (Remember this slices the object, so it can't be reversed)
        cout << "Calling PrintClass on wizard type object copied from necromancer:" << endl;
        upCasted.PrintClass();

        // Downcasting is casting a base class to a derived class, and it's not allowed like this:
        // Necromancer downCasted = upcasted;
    }
    cin.get();


    // To harness the full power of casting in C++, we'll have to use pointers.

    {
        cout << "C style casting:" << endl;


        // With C style casting, you can convert any pointer to a pointer of another type.
        Necromancer* necromancerptr = new Necromancer(10);
        cout << "Calling PrintClass on necromancer pointer:" << endl;
        necromancerptr->PrintClass();


        // Here we can upcast a pointer like before.
        Wizard* wizardptr = necromancerptr;
        cout << "Calling PrintClass on wizard pointer upcasted from necromancer:" << endl;
        wizardptr->PrintClass();


        // More importantly, because our object wasn't sliced, we can downcast back to the original type:
        // Note that we need parens for any casting operation where the object being casted doesn't inherit from the target type.
        Necromancer* necromancerptr2 = (Necromancer*)wizardptr;
        cout << "Calling PrintClass on downcasted necromancer pointer:" << endl;
        necromancerptr2->PrintClass();


        // Even more crazy, you can cast a type to a completely different type:
        Fighter* fighterptr = (Fighter*)necromancerptr;
        cout << "Calling PrintClass on sidecasted fighter pointer:" << endl;
        // This is extremely dangerous, and only works here because the types both inherit from character which has this function.
        fighterptr->PrintClass();





        cout << "Weirder stuff incoming" << endl;
        cin.get();




        // You can also cast it to something that makes no sense at all:
        int* intptr = (int*)necromancerptr;
        cout << "Value at address when converted to int*: " << *intptr << endl; // This will most likely output what seems like junk (depends on compiler)

        // You can actually add to the memory address to read from different parts of memory too:
        int* first = intptr + 1;
        cout << "Value at address + 1: " << *first << endl;             // This trick is called pointer arithmetic.
        cout << "Value at address + 2: " << *(intptr + 2) << endl;      // It's a useful feature of the language, but usually used differently.
        cout << "Value at address + 3: " << *(intptr + 3) << endl;
        cout << "Value at address + 4: " << *(intptr + 4) << endl;      // Most compilers will be fine with this line, but it might not work.

        // Now if we compare that to our object:
        cout << "Compared to character stats: " << endl;
        necromancerptr->PrintStats();

        // The memory is the same!



        // We only need to delete one object we allocated when we are done.
        delete necromancerptr;
    }
    cin.get();



    // Now that you know that you can do that kind of casting, don't.
    // It is widely regarded as a bad move.

    // Why? C++ has added special functions to make casting more predictable/safer than it was in C.



    {
        // Dynamic casting is the safest type of casting.
        cout << "Dynamic Casting:" << endl;

        // Create a necromancer pointer again.
        Necromancer* necromancerptr = new Necromancer(10);
        cout << "Calling PrintClass on necromancer pointer:" << endl;
        necromancerptr->PrintClass();

        // Here we use dynamic cast. The syntax can be a little weird at first:
        //                        Pointer type being casted to
        //          The cast function        |          pointer to cast
        //                         v         v          v
        Wizard* wizardptr2 = dynamic_cast<Wizard*>(necromancerptr);
        // Angle brackets are used in C++ to do type related things.
        // Casting is one of those things
        cout << "Calling PrintClass on wizard pointer upcasted from necromancer:" << endl;
        wizardptr2->PrintClass();


        // We can also downcast:
        Necromancer* necromancerptr2 = dynamic_cast<Necromancer*>(wizardptr2);
        cout << "Calling PrintClass on necromancer downcasted from wizard:" << endl;
        necromancerptr2->PrintClass();

        // and side cast:
        cout << "Attempting to dynamic_cast necromancer to ranger:" << endl;
        Ranger* rangerptr = dynamic_cast<Ranger*>(necromancerptr);

        // There's a problem with this, Necromancerptr isn't a ranger.
        // Unlinke C casting, dynamic_cast will return nullptr if it can't cast correctly.
        if (rangerptr == nullptr)
        {
            cout << "rangerptr == nullptr" << endl;
        }
        // This can be helpful because it makes casting mistakes extremely obvious.

        delete necromancerptr;  // Let's get rid of this thing and look at a different kind of casting.
    }
    cin.get();




    {
        // Static casting is the next level.
        cout << "Static Casting:" << endl;

        // Create a necromancer pointer again.
        Necromancer* necromancerptr = new Necromancer(10);
        cout << "Calling PrintClass on necromancer pointer:" << endl;
        necromancerptr->PrintClass();

        // The syntax for every other type of casting is exactly the same:

        Wizard* wizardptr2 = static_cast<Wizard*>(necromancerptr);
        cout << "Calling PrintClass on wizard pointer upcasted from necromancer:" << endl;
        wizardptr2->PrintClass();


        // We can also downcast:
        Necromancer* necromancerptr2 = static_cast<Necromancer*>(wizardptr2);
        cout << "Calling PrintClass on necromancer downcasted from wizard:" << endl;
        necromancerptr2->PrintClass();

        // So far, dynamic casting and static casting seem to work the same way...


        // but what about side casting?:
        cout << "Attempting to static_cast necromancer to ranger:" << endl;
        Ranger* rangerptr = dynamic_cast<Ranger*>(necromancerptr);

        // This is where the only real difference between static casting and dynamic casting appears
        if (rangerptr != nullptr)
        {
            cout << "rangerptr != nullptr" << endl;
        }

        // static_cast never checks to make sure that the type conversion is correct.
        // This can help make your code faster if you can guarentee that it will work correctly.


        delete necromancerptr;  // delete this thing.
    }
    cin.get();



    {
        // Finally, reinterpret casting.
        cout << "Reinterpret Casting:" << endl;

        // Reinterpret casting does the exact same thing as static casting 99% of the time.
        // However, there is one situation where it works differently:

        int* x = new int(5);                            // Here we create an int pointer.
        cout << "value at x: " << *x << endl;

        // static_cast cant convert between pointers to primitive types.
        // float* xSCast = static_cast<float*>(x);      // Static cast x to float*

        // reinterpret_cast can!
        float* xRCast = reinterpret_cast<float*>(x);    // Reinterpret x as a float pointer.
        cout << "value at float pointer to x: " << *xRCast << endl;

        // These numbers are different, because int and float are layed out differently in memory.
        // reinterpret_cast literally takes the binary and treats it as something else.

        delete x;
    }
    cin.get();



    // Review on when to use each type of casting:

    // Dynamic Cast:
    // You want avoid casting between types that aren't related.

    // Static Cast:
    // You want to convert one object to another, but the objects aren't directly related by inheritance.
    
    // Reinterpret Cast:
    // You want to take some binary data and completely change what it means. (wtf level stuff)

    // C casting:
    // It is generally considered ok to use C casting when converting between primitive types.
    // This is only because it's assumed that most people know what the default casting behavior will be for this.
    // Avoid at all costs when casting pointers.

    // Other benefits of using explicit C++ casting in favor of C casting:
    // They make it obvious what casting is even happening.
    // They make it clear what you intend for the casting to do.
    // They also make it easier to find with ctrl-f.

    cout << "End of program." << endl;
    cin.get();  // wait for user to press enter.
    return 0;   // End Program.
}