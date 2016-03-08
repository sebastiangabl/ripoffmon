# Level structure

The level binaries are arranged like that (The filename is the level ID):

WIDTH             2 bytes (unsigned short)
HEIGHT            2 bytes (unsigned short)

NEIGHBOURS        16 bytes
------------------------------------------
  ID_RIGHT        2 bytes (unsigned short)
  OFF_RIGHT       2 bytes (short)
  ID_UP           2 bytes (unsigned short)
  OFF_UP          2 bytes (short)
  ID_LEFT         2 bytes (unsigned short)
  OFF_LEFT        2 bytes (short)
  ID_DOWN         2 bytes (unsigned short)
  OFF_DOWN        2 bytes (short)

FLAGS             1 byte
MUSIC             1 byte
  
LEVEL DATA        6 * WIDTH * HEIGHT bytes
------------------------------------------
  MOVEMENT        1 byte
  FLOOR           1 byte
  BACK TILE       2 bytes (unsigned short)
  FRONT TILE      2 bytes (unsigned short)
  
OUTSIDE TILES     2 * 8 bytes
------------------------------------------
  T-R BACK        2 bytes (unsigned short)
  T-R FRONT       2 bytes (unsigned short)
  T-L BACK        2 bytes (unsigned short)
  T-L FRONT       2 bytes (unsigned short)
  B-R BACK        2 bytes (unsigned short)
  B-R FRONT       2 bytes (unsigned short)
  B-L BACK        2 bytes (unsigned short)
  B-L FRONT       2 bytes (unsigned short)
  
ENTITIES          varies
------------------------------------------
  TYPE            1 byte