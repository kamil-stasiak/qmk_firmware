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
                    "matrix": [
                        0,
                        0
                    ],
                    // układ X Y gdzie początek układu to lewy górny róg
                    // dlatego X to kolumny, Y to wiersze 
                    // kolumny X rosną w prawo, wiersze Y rosną w dół
                    "x": 0,
                    "y": 0.25
                },
                {
                    "matrix": [
                        1,
                        0
                    ],
                    "x": 0,
                    "y": 1.25
                }
            ]
        }
    }
}
```

Keybaord matrix: https://pcbheaven.com/wikipages/How_Key_Matrices_Works/
Początek kolumny połączony jest z pinem kolumny, początek wiersza połączony jest z pinem wiersza

# Split

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

Patrząc na klawiaturę możnaby założyć, że jej prawa cześć to dodatkowe kolumny, a jest zupełnie odwrotnie.
Split klawiatura działa tak, że, że drugi mikrokontroler jest jakby dodatkowymi wierszami pierwszego.

https://docs.qmk.fm/#/feature_split_keyboard?id=layout-macro

> Configuring your layout in a split keyboard works slightly differently to a non-split keyboard. Take for example the
> following layout. The top left numbers refer to the matrix row and column, and the bottom right are the order of the
> keys in the layout:
> Since the matrix scanning procedure operates on entire rows, it first populates the left half’s rows, then the right
> half’s. Thus, the matrix as QMK views it has double the rows instead of double the columns:

Co z tego wynika

- nie trzeba deklaorwać dodatkowych pinów mikrokontrolera na dodatkowe kolumny czy wiersze
- na drugim kontrolerze użyte zostaną te same Piny
- W `info.json -> layout` trzeba zadeklrować `matrix` tak, żeby nie używać większej liczy kolumn,
  tylko większą liczbę wierszy: `matrix: [ROW, COL]`, dlatego ja mam niby 10 wierszy


Jeżeli zapiszę `layout` w następujący sposób, to znaczy prawa ręka ma podane COL od 6 do 0, 
to pirwsza kolumna jest kolumną najbardziej z prawej strony
[//]: # (// @formatter:off)
```json5
{
    "layout": [
        // {"matrix": [ROW, COL] },
        // LEFT hand 1st ROW
        {"matrix": [0, 0], "x": 0, "y": 0.25},
        {"matrix": [0, 1], "x": 1, "y": 0.25},
        {"matrix": [0, 2], "x": 2, "y": 0.125},
        {"matrix": [0, 3], "x": 3, "y": 0},
        {"matrix": [0, 4], "x": 4, "y": 0.125},
        {"matrix": [0, 5], "x": 5, "y": 0.25},
        {"matrix": [0, 6], "x": 8, "y": 0.25},

        // RIGHT hand 1st row
        {"matrix": [5, 6], "x": 8, "y": 0.25},
        {"matrix": [5, 5], "x": 8, "y": 0.25},
        {"matrix": [5, 4], "x": 9, "y": 0.125},
        {"matrix": [5, 3], "x": 10, "y": 0},
        {"matrix": [5, 2], "x": 11, "y": 0.125},
        {"matrix": [5, 1], "x": 12, "y": 0.25},
        {"matrix": [5, 0], "x": 13, "y": 0.25},
        }
}
```

[//]: # (// @formatter:on )


Gdy to odwróciłem czyli kolumny prawej strony są zadeklarowane rosnąco 0, 1, 2... 
to pierwszą kolumną staje się ta najbardziej po lewj stronie prawej części 

[//]: # (// @formatter:off)
```json5
    "layouts": {
        "LAYOUT_split_3x6_3": {
            "layout": [
//                LEFT hand 1st ROW
                {"matrix": [0, 0], "x": 0, "y": 0.25},
                {"matrix": [0, 1], "x": 1, "y": 0.25},
                {"matrix": [0, 2], "x": 2, "y": 0.125},
                {"matrix": [0, 3], "x": 3, "y": 0},
                {"matrix": [0, 4], "x": 4, "y": 0.125},
                {"matrix": [0, 5], "x": 5, "y": 0.25},
                {"matrix": [0, 6], "x": 8, "y": 0.25},

//                RIGHT hand 1st row
                {"matrix": [5, 0], "x": 8, "y": 0.25},
                {"matrix": [5, 1], "x": 8, "y": 0.25},
                {"matrix": [5, 2], "x": 9, "y": 0.125},
                {"matrix": [5, 3], "x": 10, "y": 0},
                {"matrix": [5, 4], "x": 11, "y": 0.125},
                {"matrix": [5, 5], "x": 12, "y": 0.25},
                {"matrix": [5, 6], "x": 13, "y": 0.25},

```
[//]: # (// @formatter:on )

Czyli po prostu te wpisy `matrix` mówią jakiego przycisku w macro `LAYOUT_split_3x6_3` należy szukać i go odpalają.

Usawienie reverse order (opcji 1) powinno ułatwić lutowanie 

## Która część jest prawa, a która lewa

By default ta podłączona kablem to lewa

> If neither options are defined, the handedness defaults to MASTER_LEFT.
Tutaj opcje zmiany: https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness

# Błędy

```shell
duplicate macro parameter "k5A"
```

Istnieją dwa takie same wpisy `matrix` w `info.json -> layout`. Para kolumna-wiersz nie może się powtarzać

```shell
 macro "LAYOUT_split_3x6_3" passed 70 arguments, but takes just 69
```

W `info.json -> layout` zadeklarownych jest mniej przycisków niż w pliku `keymap.c` w macro `LAYOUT_split_3x6_3`

```shell
Matrix column for key 6 (k0H) is 7 but must be less than 7
```

W pliku `info.json` w sekcji `matrix_pins` zadeklarownych jest 7 kolumn czyli można używać wartości od 0 do 6,
a w `layout` użyte zostało 7. 
Pamiętaj, że ilość wierszy może być 2 razy większa w przypadku split, 
bo split używa kolumn z drugiej części jako wiersze
