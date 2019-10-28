# The default keymap for the Das Keyboard Ultimate

This is the default keymap for the Das Keyboard Ultimate.

The row/column ordering is somewhat arbitrary based on the order of the
pinout of the PCB where the switches are mounted. The ribbon cable soldered
onto the PCB has a female end that is 2 rows, and 13 columns.  I index as
below, with the ribbon extending downwards:

```----------------------------------------
|00|01|02|03|04|05|06|07|08|09|0A|0B|0C|
|10|11|12|13|14|15|16|17|18|19|1A|1B|1C|
----------------------------------------
 || || || || || || || || || || || || ||```

I spent way too much happy beeping time with a multimeter discovering the
following matrix of 18 columns by 8 (diode-gated) rows:

|          | `05`    | `08`     | `09`    | `0A`     | `15`    | `17`     | `18`     | `1A`    |
| -------- | ----    | ----     | ----    | ----     | ----    | ----     | ----     | ----    |
| **`00`** | `F6`    |    `K`   |    `I`  |    `<`   |    `8`  |   `=`    |   `[`    |  ``     |
| **`01`** | ``      |    `L`   |    `O`  |    `>`   |    `9`  |  `F8`    |  `F7`    |  `MENU` |
| **`02`** | `G`     |    `F`   |    `R`  |    `V`   |    `4`  |   `5`    |   `T`    |  `B`    |
| **`03`** | ``      |    `S`   |    `W`  |    `X`   |    `2`  |  `F1`    | `CPSLK`  |  ``     |
| **`04`** | ``      |     ``   | `PAUSE` | `R CTRL` | `F5`    | `L CTRL` |    ``    |  ``     |
| **`06`** | `NUM 0` | `NUM 2`  | `NUM 8` | `NUM /`  |    `0`  | `INSERT` | `NUM 5`  | `RIGHT` |
| **`07`** | `SPACE` | `NUM 1`  | `NUM 7` | `NUM LK` | ``      | `DELETE` | `NUM 4`  | `DOWN`  |
| **`0B`** | ``      | `R WIN`  |    ``   |    ``    |    ``   | ``       |   ``     |  ``     |
| **`0C`** | ``      | `R SHFT` | ``      |  ``      |    ``   |   ``     | `L SHFT` |  ``     |
| **`10`** | `L ALT` |    ``    | `SCRLK` |    ``    | `PRSCR` |   ``     |   ``     | `R ALT` |
| **`11`** | `H`     |    `J`   |    `U`  |    `M`   |    `7`  |   `6`    |   `Y`    |  `N`    |
| **`12`** | `F4`    |    `D`   |    `E`  |    `C`   |    `3`  |  `F2`    |   `F3`   |  ``     |
| **`13`** | `ESC`   |    `A`   |    `Q`  |    `Z`   |    `1`  |   `\``   | `TAB`    |  ``     |
| **`14`** | `F11`   |    `\\`  |    ``   | `ENTER`  |  `F10`  |  `F9`    | `BKSPC`  | `F12`   |
| **`16`** | `'`     |    `;`   |    `P`  |    ``    |    ``   |   `-`    |   `[`    |  `/`    |
| **`19`** | `NUM .` |  `NUM 3` | `NUM 9` | `NUM *`  | `PG DN` | `PG UP`  | `NUM 6`  | `NUM -` |
| **`1B`** | ``      |  ``      |    ``   |    ``    |    ``   |   ``     | `L WIN`  |  ``     |
| **`1C`** | `UP`    | `NUM ENT`| `NUM +` | ``       | `END`   |   `HOME` |   ``     | `LEFT`  |

