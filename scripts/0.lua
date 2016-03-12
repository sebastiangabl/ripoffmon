#test(version)
io.write("Test LUA script calling a c++ function (",_VERSION,")\n")
externCall("test", 2, os.date("%H"), os.date("%M"))
externCall("test", 2, arg[1], arg[2])