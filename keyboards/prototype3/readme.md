# prototype3

Funkcja użyta w pliku `keymaps/default/keymap.c -> LAYOUT_split_3x6_3` musi nazywać się tak,
jak pole w pliku `info.json->layouts.LAYOUT_split_3x6_3`
Zawartość tej funkcji musi być skojarzona z wpisem w `info.json` w 2 miejscach `matrix_pins` i `layouts`.

Matrix pins musi deklarować tyle pinów wejściowych na kolumny i wiersze,
żeby możliwe było przypisanie wszystkich zadeklarowanych przycisków w `keymaps/default/keymap.c` i `info.json->layouts`.
Jak rozumiem liczba zadeklarowanych przycisków w tych dwóch miejscach musi być równa

Nazwy pinów jakie należy wpisać do matrix_pins są tutaj: https://deskthority.net/wiki/Arduino_Pro_Micro#Pinout.
Chodzi o nazwy w kolumnie `AVR` bez literki P na początku.

Połóżmy płytkę tak, że wejście usb jest od lewej strony a mikrokontroler od góry. Wtedy piny układają się tak


    * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
    * │   │RAW│GND│RST│VCC│ F4│ F5│ F6│ F7│ B1│ B3│ B2│ B6│
    * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───├───┼───┼───┤
    * │USB│   │   │   │   │   │   │   │   │   │   │   │   │     
    * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
    * │   │ D3│ D2│GND│GND│ D1│ D0│ D4│ C6│ D7│ E6│ B4│ B5│
    * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘

```json5
{
    "layouts": {
        "LAYOUT_split_3x6_3": {

            // 
            "layout": [
                {
                    // matrix: [ROW, COLUMN]
                    "matrix": [0, 0],
                    // układ X Y gdzie początek układu to lewy górny róg
                    // dlatego X to kolumny, Y to wiersze 
                    // kolumny X rosną w prawo, wiersze Y rosną w dół
                    "x": 0, "y": 0.25
                },
                {"matrix": [1, 0], "x": 0, "y": 1.25}
            ]
        }
    }
}
```

Keybaord matrix: https://pcbheaven.com/wikipages/How_Key_Matrices_Works/
Początek kolumny połączony jest z pinem kolumny, początek wiersza połączony jest z pinem wiersza

SU120 wyprowadzając kabel TRRS połączył GND, VCC i pin D2 (PD2). To znaczy, że w `rules.mk` trzeba zadeklarować:
```mk
SPLIT_KEYBOARD = yes
```
a potem `info.json`

```json5
{
  "split": {
    "soft_serial_pin": "D2"
  },
}
```
