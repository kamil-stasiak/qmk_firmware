// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐               ┌───┬───┬───┬───┬───┬───┐
      * │ESC│ 1 │ 2 │ 3 │ 4 │ 5 │               │ 6 │ 7 │ 8 │ 9 │ 0 │ Q │
      * ├───┼───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┼───┤
      * │TAB│ Q │ W │ E │ R │ T │               │ Y │ U │ I │ O │ P │ \ │
      * ├───┼───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┼───┤
      * │BCS│ A │ S │ D │ F │ G │               │ H │ J │ K │ L │ ; │ ' │
      * ├───┼───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┼───┤
      * │???│ Z │ X │ C │ V │ B │               │ N │ M │ , │ . │ / │ ] │
      * ├───┼───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┼───┤
      * │???│???│???│UP │SPC│ENT│               │???│SPC│UP │???│???│???│
      * ├───┼───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┼───┤
      * │   │   │   │   │   │ ' │               │???│   │   │   │   │   │
      * └───┴───┴───┴───┴───┴───┘               └───┴───┴───┴───┴───┴───┘
      */
    [0] = LAYOUT_split_3x6_3(
          KC_ESC,       KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                KC_6,    KC_7,     KC_8,    KC_9,    KC_0,      KC_MINUS,
          KC_TAB,       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                KC_Y,    KC_U,     KC_I,    KC_O,    KC_P,      KC_BACKSLASH,
          KC_BACKSPACE, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                KC_H,    KC_J,     KC_K,    KC_L, KC_SEMICOLON, KC_QUOTE,
          KC_NO,        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                KC_N,    KC_M,  KC_COMMA,   KC_DOT,  KC_SLASH,  KC_RIGHT_BRACKET,
          KC_NO,        KC_NO,   KC_NO,   KC_NO,   KC_SPACE,  KC_ENTER,          KC_NO,   KC_SPACE, KC_NO,   KC_NO,   KC_NO,     KC_NO,
          KC_NO,        KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_QUOTE,             KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO
    )
};

// Working left side
//const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//     /*
//      * ┌───┬───┬───┬───┬───┬───┐           ┌───┬───┬───┬───┬───┬───┐
//      * │ P │ 1 │ 2 │ 3 │ 4 │ 5 │ v         │ Y │ U │ I │ O │ P │Bsp│
//      * ├───┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┼───┤
//      * │ O │ Q │ W │ E │ R │ T │ b         │ H │ J │ K │ L │ ; │ ' │
//      * ├───┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┼───┤
//      * │ I │ A │ S │ D │ F │ G │ n         │ H │ J │ K │ L │ ; │ ' │
//      * ├───┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┼───┤
//      * │ U │ Z │ X │ C │ V │ B │ m         │ N │ M │ , │ . │ / │Sft│
//      * ├───┼───┼───┼───┼───┼───┼───┐       ├───┼───┼───┼───┼───┼───┤
//      * │ Y │ H │ J │ K │ L │ ; │ " │       │ H │ J │ K │ L │ ; │ ' │
//      * └───┴───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
//      */
//    [0] = LAYOUT_split_3x6_3(
//          KC_P,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_V,
//          KC_O,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_B,
//          KC_I,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_N,
//          KC_U,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_M,
//          KC_Y,    KC_H,    KC_J,    KC_K,    KC_L,  KC_SEMICOLON, KC_QUOTE
//    )
//};
