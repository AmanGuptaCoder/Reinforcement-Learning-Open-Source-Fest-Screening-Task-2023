// include Lua headers
extern "C" {
    #include "lua.h" // Lua header file
    #include "lualib.h" // Lua standard library header file
    #include "lauxlib.h" // Lua auxiliary library header file
}
#include <iostream>

int main() {
	// Creating a new Lua state and loading the standard libraries
	lua_State* L = luaL_newstate(); // Create a new Lua state and get a pointer to it
	luaL_openlibs(L); // Load all standard Lua libraries into the Lua state

	// Pushing the "io" field of the "loaded" table onto the stack
	lua_getglobal(L, "package"); // Push the global variable "package" onto the stack
	lua_getfield(L, -1, "loaded"); // Push the "loaded" field of the "package" table onto the stack
	lua_getfield(L, -1, "io"); // Push the "io" field of the "loaded" table onto the stack

	// Checking if the "io" field is not nil and printing a message if it is not nil
	if (!lua_isnil(L, -1)) { // Check if the value at the top of the stack is not nil
    		lua_pop(L, 3); // Remove the top three elements from the stack
    		lua_pushstring(L, "Aman Gupta says hello"); // Push a string onto the stack
    		lua_getglobal(L, "print"); // Push the global variable "print" onto the stack
    		lua_insert(L, -2); // Move the message string to be just below the "print" function on the stack
    		lua_call(L, 1, 0); // Call the "print" function with the message string as an argument
	}
	// Printing an error message if the "io" field is nil
	else {
    		printf("Lua standard library not loaded correctly\n"); // Print an error message to the console
    		lua_pop(L, 3); // Remove the top three elements from the stack
	}
 
    	// Closing the Lua state and freeing all resources
    	lua_close(L); // Close the Lua state and free all resources associated with it

   	return 0;
}
