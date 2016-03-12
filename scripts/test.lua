io.write("Running ",_VERSION,"\n")

function test(arg1, arg2, arg3)
  io.write("Test LUA function calling a c++ function\n")
  externCall("test", 1, arg1)
  externCall("test", 1, arg2)
  externCall("test", 1, arg3)
end