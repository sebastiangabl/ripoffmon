# Level structure

The level's filename (minus extension) is it's ID in the engine. The level file layout looks like this:

__SIZE__ | __4 bytes__ | __Type__
---- | ---- | ----
WIDTH | 2 bytes | unsigned short
HEIGHT | 2 bytes | unsigned short
|
__NEIGHBOURS__ | __16 bytes__ | __Type__
ID_RIGHT | 2 bytes | unsigned short
OFF_RIGHT | 2 bytes | short
ID_UP | 2 bytes | unsigned short
OFF_UP | 2 bytes | short
ID_LEFT | 2 bytes | unsigned short
OFF_LEFT | 2 bytes | short
ID_DOWN | 2 bytes | unsigned short
OFF_DOWN | 2 bytes | short
|
__SETTINGS__ | __2 bytes__ | __Type__
FLAGS | 1 byte | unsigned char
TILESET | 1 byte | unsigned char
MUSIC | 1 byte | unsigned char
|
__LEVEL DATA__ | __6 * WIDTH * HEIGHT bytes__ | __Type__
MOVEMENT | 1 byte | unsigned char
FLOOR | 1 byte | unsigned char
BACK TILE ID | 2 bytes | unsigned short
FRONT TILE ID | 2 bytes | unsigned short
|
__OUTSIDE TILES__ | __2 * 8 bytes__ | __Type__
TOP-RIGHT BACK | 2 bytes | unsigned short
TOP-RIGHT FRONT | 2 bytes | unsigned short
TOP-LEFT BACK | 2 bytes | unsigned short
TOP-LEFT FRONT | 2 bytes | unsigned short
BOTTOM-RIGHT BACK | 2 bytes | unsigned short
BOTTOM-RIGHT FRONT | 2 bytes | unsigned short
BOTTOM-LEFT BACK | 2 bytes | unsigned short
BOTTOM-LEFT FRONT | 2 bytes | unsigned short
| 
__SCRIPTS__ |
|
__WARPS__ |
|
__ENTITIES__ |
