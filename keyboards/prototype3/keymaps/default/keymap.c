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
      * │???│???│???│???│???│SPC│               │SPC│???│???│???│???│???│
      * ├───┼───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┼───┤
      * │   │   │   │   │   │ENT│               │???│   │   │   │   │   │
      * └───┴───┴───┴───┴───┴───┘               └───┴───┴───┴───┴───┴───┘
      */

//    [0] = LAYOUT_split_3x6_3(
//          KC_ESC,       KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                KC_6,    KC_7,     KC_8,    KC_9,    KC_0,      KC_MINUS,
//          KC_TAB,       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                KC_Y,    KC_U,     KC_I,    KC_O,    KC_P,      KC_BACKSLASH,
//          KC_BACKSPACE, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                KC_H,    KC_J,     KC_K,    KC_L, KC_SEMICOLON, KC_QUOTE,
//          KC_NO,        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                KC_N,    KC_M,   KC_COMMA,   KC_DOT,  KC_SLASH,  KC_RIGHT_BRACKET,
//          KC_NO,        KC_NO,   KC_NO,   MO(3),   MO(1),   KC_SPACE,          KC_SPACE,  MO(2),    MO(4),   KC_NO,   KC_NO,     KC_NO,
//          KC_NO,        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_ENTER,            KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO
//    ),

    [0] = LAYOUT_split_3x6_3(
        KC_ESC,       KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                KC_6,    KC_7,     KC_8,    KC_9,    KC_0,      KC_MINUS,
        KC_TAB,       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                KC_Y,    KC_U,     KC_I,    KC_O,    KC_P,      KC_BACKSLASH,

        // left home row
        KC_BACKSPACE, RCTL_T(KC_A),    RGUI_T(KC_S),    RALT_T(KC_D),    RSFT_T(KC_F),    KC_G,

        // right home row
        KC_H,    RSFT_T(KC_J),     RALT_T(KC_K),    RGUI_T(KC_L), RCTL_T(KC_SEMICOLON), KC_QUOTE,

        KC_7,        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                KC_N,    KC_M,   KC_COMMA,   KC_DOT,  KC_SLASH,  KC_RIGHT_BRACKET,
        KC_1,        KC_2,   KC_3,   MO(3),   MO(1),   KC_SPACE,          KC_SPACE,  MO(2),    MO(4),   KC_6,   KC_7,     KC_8,
        KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_ENTER,            KC_M,    KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO
    ),

    [1] = LAYOUT_split_3x6_3(
              _______,    _______,    _______,    _______,    _______,    _______,                KC_F6,            KC_F7,         KC_F8,      KC_F9,      KC_F10,     KC_F11,
              _______,    _______,    _______,    _______,    _______,    _______,                _______, LGUI(KC_LEFT_BRACKET),  KC_UP,   LGUI(KC_RIGHT_BRACKET),     KC_ASTERISK,    KC_F12,
              _______, KC_RIGHT_CTRL, KC_RIGHT_GUI, KC_RIGHT_ALT, KC_RIGHT_SHIFT, _______,        _______,          KC_LEFT,       KC_DOWN,    KC_RIGHT,   KC_EQUAL,    KC_GRAVE,
              _______,    _______,    _______,    _______,    _______,    _______,                _______,          _______,       KC_F16,     _______,    KC_BACKSLASH,    _______,
              _______,    _______,    _______,    _______,    _______,    _______,                _______,          _______,       _______,    _______,    KC_PLUS,    _______,
              _______,    _______,    _______,    _______,    _______,    _______,                _______,          _______,       _______,    _______,    _______,    _______
    ),
    [2] = LAYOUT_split_3x6_3(
                  _______,     KC_F1,      KC_F2,      KC_F3,           KC_F4,         KC_F5,            _______,    _______,     _______,    _______,    _______,    _______,
                  _______,    KC_EXCLAIM,    KC_AT, KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE, KC_HASH,           _______,    _______,     _______,    _______,    _______,    _______,
                  KC_DELETE,    KC_PERCENT,    KC_DOLLAR,    KC_LEFT_PAREN,    KC_RIGHT_PAREN,       KC_CIRCUMFLEX	,           _______, KC_RIGHT_SHIFT, KC_RIGHT_ALT, KC_RIGHT_GUI, KC_RIGHT_CTRL, _______,
                  _______,    KC_AMPERSAND,    KC_PIPE,    KC_LEFT_BRACKET,  KC_RIGHT_BRACKET,       KC_TILDE,           _______,    _______,     _______,    _______,    _______,    _______,
                  _______,    _______,    _______,    _______,         _______,       _______,           _______,    _______,     _______,    _______,    _______,    _______,
                  _______,    _______,    _______,    _______,         _______,       _______,           _______,    _______,     _______,    _______,    _______,    _______
    ),
//
    [3] = LAYOUT_split_3x6_3(
                          _______,    _______,    _______,    _______,    _______,    _______,                _______,       _______,      _______,        _______,         _______,    _______,
                          _______,    _______,    _______,    _______,    _______,    _______,                _______,       _______,     KC_PAGE_UP,      _______,         _______,    _______,
                          _______, KC_RIGHT_CTRL, KC_RIGHT_GUI, KC_RIGHT_ALT, KC_RIGHT_SHIFT,  _______,       KC_F13,        KC_HOME,    KC_PAGE_DOWN,      KC_END,         KC_F19,    _______,
                          _______,    _______,    _______,    _______,    _______,    _______,                KC_F14,        KC_F15,      KC_F16,           KC_F17,         KC_F18,    _______,
                          _______,    _______,    _______,    _______,    _______,    _______,                _______,       _______,     _______,         _______,         _______,    _______,
                          _______,    _______,    _______,    _______,    _______,    _______,                _______,       _______,     _______,         _______,         _______,    _______
     ),

    [4] = LAYOUT_split_3x6_3(
                  _______,    _______,    _______,    _______,    _______,    _______,                _______,       _______,     _______,    _______,    _______,    _______,
                  _______,    _______,    KC_1,       KC_2,    KC_3,    _______,                _______,       _______,     _______,    _______,    _______,    _______,
                  _______,    KC_0,       KC_4,       KC_5,    KC_6,    _______,                _______,   KC_RIGHT_SHIFT, KC_RIGHT_ALT, KC_RIGHT_GUI, KC_RIGHT_CTRL, _______,
                  _______,    _______,    KC_7,       KC_8,    KC_9,    _______,                _______,       _______,     _______,    _______,    _______,    _______,
                  _______,    _______,    _______,    KC_0,    _______,    _______,                _______,       _______,     _______,    _______,    _______,    _______,
                  _______,    _______,    _______,    _______,    _______,    _______,                _______,       _______,     _______,    _______,    _______,    _______
    ),

//    [?] = LAYOUT_split_3x6_3(
//                      _______,    _______,    _______,    _______,    _______,    _______,                _______,       _______,     _______,    _______,    _______,    _______,
//                      _______,    _______,    _______,    _______,    _______,    _______,                _______,       _______,     _______,    _______,    _______,    _______,
//                      _______,    _______,    _______,    _______,    _______,    _______,                _______,       _______,     _______,    _______,    _______,    _______,
//                      _______,    _______,    _______,    _______,    _______,    _______,                _______,       _______,     _______,    _______,    _______,    _______,
//                      _______,    _______,    _______,    _______,    _______,    _______,                _______,       _______,     _______,    _______,    _______,    _______,
//                      _______,    _______,    _______,    _______,    _______,    _______,                _______,       _______,     _______,    _______,    _______,    _______
//   ),
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

//
