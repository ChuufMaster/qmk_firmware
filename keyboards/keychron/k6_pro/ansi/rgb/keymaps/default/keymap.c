/* Copyright 2021 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

#define CTL_ESC    LCTL_T(KC_ESC)
#define GUI_A      LGUI_T(KC_A)
#define ALT_S      LALT_T(KC_S)
#define CTL_D      LCTL_T(KC_D)
#define SFT_F      LSFT_T(KC_F)
#define SFT_J      RSFT_T(KC_J)
#define CTL_K      RCTL_T(KC_K)
#define ALT_L      RALT_T(KC_L)
#define GUI_SCN    RGUI_T(KC_SCLN)
#define SFT_TAB    LSFT_T(KC_TAB)
#define NUM_M      LT(NUM,KC_M)
#define NUM_C      LT(NUM,KC_C)
#define LALT_CAP   LALT_T(CW_TOGG)
#define RALT_CAP   RALT_T(CW_TOGG)
#define MO_WIN_FN1 MO(WIN_FN1)
#define MO_FN2     MO(FN2)
#define SPC_NAV    LT(_NAV, KC_SPC)
#define QUOT_NUM   LT(NUM_2, KC_QUOT)

// clang-format off
enum layers{
  MAC_BASE,
  WIN_BASE,
  MAC_FN1,
  _NAV,
  WIN_FN1,
  FN2,
  NUM,
  NUM_2
};

enum custom_keycodes {
    KC_PRVWD,
    KC_NXTWD,
};

enum combos {
    CMB_LBRC,
    CMB_RBRC,
    CMB_LPRN,
    CMB_RPRN,
    CMB_CW,
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM left_bracket_combo[] = {CTL_D, SFT_F, COMBO_END};
const uint16_t PROGMEM right_bracket_combo[] = {SFT_J, CTL_K, COMBO_END};
const uint16_t PROGMEM l_prn_combo[] = {GUI_A, ALT_S, COMBO_END};
const uint16_t PROGMEM r_prn_combo[] = {ALT_L, GUI_SCN, COMBO_END};
const uint16_t PROGMEM c_word_combo[] = {SFT_F, SFT_J, COMBO_END};

combo_t key_combos[] = {
    [CMB_LBRC] = COMBO(left_bracket_combo, KC_LBRC),
    [CMB_RBRC] = COMBO(right_bracket_combo, KC_RBRC),
    [CMB_LPRN] = COMBO(l_prn_combo, KC_LPRN),
    [CMB_RPRN] = COMBO(r_prn_combo, KC_RPRN),
    [CMB_CW] = COMBO(c_word_combo, CW_TOGG),
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌─────────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬──────────┬──────┬──────┬───────┐
//    │ QK_GESC │   1   │   2   │   3   │   4   │   5   │   6   │   7   │   8   │   9   │   0   │    -     │  =   │ bspc │  RGB  │
//    ├─────────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼──────────┼──────┼──────┼───────┤
//    │   tab   │   q   │   w   │   e   │   r   │   t   │   y   │   u   │   i   │   o   │   p   │    [     │  ]   │  \   │ home  │
//    ├─────────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼──────────┼──────┴──────┼───────┤
//    │   esc   │   a   │   s   │   d   │   f   │   g   │   h   │   j   │   k   │   l   │   ;   │ QUOT_NUM │     ent     │ pgup  │
//    ├─────────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼──────────┴──────┬──────┼───────┤
//    │  lsft   │   z   │   x   │   c   │   v   │   b   │   n   │   m   │   ,   │   .   │   /   │      rsft       │  up  │ pgdn  │
//    ├─────────┼───────┼───────┼───────┴───────┴───────┴───────┴───────┴───────┼───────┼───────┼──────────┬──────┼──────┼───────┤
//    │  lctl   │ lgui  │ lalt  │                      spc                      │ ralt  │  FN1  │   FN2    │ left │ down │ rght  │
//    └─────────┴───────┴───────┴───────────────────────────────────────────────┴───────┴───────┴──────────┴──────┴──────┴───────┘
[MAC_BASE] = LAYOUT_ansi_68(
  QK_GESC , KC_1    , KC_2     , KC_3  , KC_4  , KC_5 , KC_6 , KC_7  , KC_8    , KC_9     , KC_0       , KC_MINS  , KC_EQL  , KC_BSPC , RGB_MOD,
  KC_TAB  , KC_Q    , KC_W     , KC_E  , KC_R  , KC_T , KC_Y , KC_U  , KC_I    , KC_O     , KC_P       , KC_LBRC  , KC_RBRC , KC_BSLS , KC_HOME,
  CTL_ESC , GUI_A   , ALT_S    , CTL_D , SFT_F , KC_G , KC_H , SFT_J , CTL_K   , ALT_L    , GUI_SCN    , QUOT_NUM ,      KC_ENT       , KC_PGUP,
  KC_LSFT , KC_Z    , KC_X     , NUM_C , KC_V  , KC_B , KC_N , NUM_M , KC_COMM , KC_DOT   , KC_SLSH    ,      KC_RSFT       , KC_UP   , KC_PGDN,
  KC_LCTL , KC_LGUI , LALT_CAP ,                    SPC_NAV                    , RALT_CAP , MO_WIN_FN1 , MO_FN2   , KC_LEFT , KC_DOWN , KC_RGHT
),

//    ┌─────────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬──────┬──────┬───────┐
//    │ QK_GESC │   1   │   2   │   3   │   4   │   5   │   6   │   7   │   8   │   9   │   0   │   -   │  =   │ bspc │  RGB  │
//    ├─────────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼──────┼──────┼───────┤
//    │   tab   │   q   │   w   │   e   │   r   │   t   │   y   │   u   │   i   │   o   │   p   │   [   │  ]   │  \   │ home  │
//    ├─────────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼──────┴──────┼───────┤
//    │   esc   │   a   │   s   │   d   │   f   │   g   │   h   │   j   │   k   │   l   │   ;   │   '   │     ent     │ pgup  │
//    ├─────────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┴──────┬──────┼───────┤
//    │  lsft   │   z   │   x   │   c   │   v   │   b   │   n   │   m   │   ,   │   .   │   /   │     rsft     │  up  │ pgdn  │
//    ├─────────┼───────┼───────┼───────┴───────┴───────┴───────┴───────┴───────┼───────┼───────┼───────┬──────┼──────┼───────┤
//    │  lctl   │ lgui  │ lalt  │                      spc                      │ ralt  │  FN1  │  FN2  │ left │ down │ rght  │
//    └─────────┴───────┴───────┴───────────────────────────────────────────────┴───────┴───────┴───────┴──────┴──────┴───────┘
[WIN_BASE] = LAYOUT_ansi_68(
  QK_GESC , KC_1    , KC_2    , KC_3 , KC_4 , KC_5 , KC_6 , KC_7 , KC_8    , KC_9    , KC_0       , KC_MINS , KC_EQL  , KC_BSPC , RGB_MOD,
  KC_TAB  , KC_Q    , KC_W    , KC_E , KC_R , KC_T , KC_Y , KC_U , KC_I    , KC_O    , KC_P       , KC_LBRC , KC_RBRC , KC_BSLS , KC_HOME,
  CTL_ESC , KC_A    , KC_S    , KC_D , KC_F , KC_G , KC_H , KC_J , KC_K    , KC_L    , KC_SCLN    , KC_QUOT ,      KC_ENT       , KC_PGUP,
  KC_LSFT , KC_Z    , KC_X    , KC_C , KC_V , KC_B , KC_N , KC_M , KC_COMM , KC_DOT  , KC_SLSH    ,      KC_RSFT      , KC_UP   , KC_PGDN,
  KC_LCTL , KC_LGUI , KC_LALT ,                   KC_SPC                   , KC_RALT , MO_WIN_FN1 , MO_FN2  , KC_LEFT , KC_DOWN , KC_RGHT
),

//    ┌─────────┬──────────┬─────────┬─────────┬──────────┬─────────┬─────────┬──────┬──────┬──────┬──────┬──────┬──────┬─────┬─────────┐
//    │    `    │   bRID   │  bRIU   │  mCTL   │   l  PAD │ RGB_VAD │ RGB_VAI │ mprv │ mply │ mnxt │ mute │ vold │ volu │     │ RGB_TOG │
//    ├─────────┼──────────┼─────────┼─────────┼──────────┼─────────┼─────────┼──────┼──────┼──────┼──────┼──────┼──────┼─────┼─────────┤
//    │         │ BT_HST1  │ BT_HST2 │   end   │          │         │         │ pgup │      │      │      │      │      │     │         │
//    ├─────────┼──────────┼─────────┼─────────┼──────────┼─────────┼─────────┼──────┼──────┼──────┼──────┼──────┼──────┴─────┼─────────┤
//    │ RGB_TOG │   RGB    │ RGB_VAI │  pgdn   │ RGB_SAI  │ RGB_SPI │  left   │ down │  up  │ rght │      │      │            │         │
//    ├─────────┼──────────┼─────────┼─────────┼──────────┼─────────┼─────────┼──────┼──────┼──────┼──────┼──────┴──────┬─────┼─────────┤
//    │         │ RGB_RMOD │ RGB_VAD │ RGB_HUD │ RGB_SAD  │  home   │ NK_TOGG │      │      │      │      │             │     │         │
//    ├─────────┼──────────┼─────────┼─────────┴──────────┴─────────┴─────────┴──────┴──────┼──────┼──────┼──────┬──────┼─────┼─────────┤
//    │         │          │         │                                                      │      │      │      │      │     │         │
//    └─────────┴──────────┴─────────┴──────────────────────────────────────────────────────┴──────┴──────┴──────┴──────┴─────┴─────────┘
[MAC_FN1] = LAYOUT_ansi_68(
  KC_GRV  , KC_BRID  , KC_BRIU , KC_MCTL , KC_LPAD , RGB_VAD , RGB_VAI , KC_MPRV , KC_MPLY , KC_MNXT , KC_MUTE , KC_VOLD , KC_VOLU , KC_TRNS , RGB_TOG,
  KC_TRNS , BT_HST1  , BT_HST2 , KC_END  , KC_TRNS , KC_TRNS , KC_TRNS , KC_PGUP , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
  RGB_TOG , RGB_MOD  , RGB_VAI , KC_PGDN , RGB_SAI , RGB_SPI , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , KC_TRNS , KC_TRNS ,      KC_TRNS      , KC_TRNS,
  KC_TRNS , RGB_RMOD , RGB_VAD , RGB_HUD , RGB_SAD , KC_HOME , NK_TOGG , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,      KC_TRNS      , KC_TRNS , KC_TRNS,
  KC_TRNS , KC_TRNS  , KC_TRNS ,                          KC_TRNS                          , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS
),

//    ┌─────────┬──────────┬─────────┬─────────┬─────────┬─────────┬─────────┬──────┬──────┬──────┬──────┬──────┬──────┬─────┬─────────┐
//    │    `    │   bRID   │  bRIU   │         │         │ RGB_VAD │ RGB_VAI │ mprv │ mply │ mnxt │ mute │ vold │ volu │     │ RGB_TOG │
//    ├─────────┼──────────┼─────────┼─────────┼─────────┼─────────┼─────────┼──────┼──────┼──────┼──────┼──────┼──────┼─────┼─────────┤
//    │         │          │ C(rght) │   end   │         │         │  C(c)   │ pgup │ home │ ent  │ C(v) │      │      │     │         │
//    ├─────────┼──────────┼─────────┼─────────┼─────────┼─────────┼─────────┼──────┼──────┼──────┼──────┼──────┼──────┴─────┼─────────┤
//    │ RGB_TOG │   end    │ RGB_VAI │  pgdn   │ RGB_SAI │ RGB_SPI │  left   │ down │  up  │ rght │      │      │            │         │
//    ├─────────┼──────────┼─────────┼─────────┼─────────┼─────────┼─────────┼──────┼──────┼──────┼──────┼──────┴──────┬─────┼─────────┤
//    │         │ RGB_RMOD │   del   │ RGB_HUD │ RGB_SAD │  pRVWD  │ NK_TOGG │      │      │      │      │             │     │         │
//    ├─────────┼──────────┼─────────┼─────────┴─────────┴─────────┴─────────┴──────┴──────┼──────┼──────┼──────┬──────┼─────┼─────────┤
//    │         │          │         │                                                     │      │      │      │      │     │         │
//    └─────────┴──────────┴─────────┴─────────────────────────────────────────────────────┴──────┴──────┴──────┴──────┴─────┴─────────┘
[_NAV] = LAYOUT_ansi_68(
  KC_GRV  , KC_BRID  , KC_BRIU     , _______ , _______ , RGB_VAD  , RGB_VAI , KC_MPRV , KC_MPLY , KC_MNXT , KC_MUTE , KC_VOLD , KC_VOLU , _______ , RGB_TOG,
  _______ , _______  , C(KC_RIGHT) , KC_END  , _______ , _______  , C(KC_C) , KC_PGUP , KC_HOME , KC_ENT  , C(KC_V) , _______ , _______ , _______ , _______,
  RGB_TOG , KC_END   , RGB_VAI     , KC_PGDN , RGB_SAI , RGB_SPI  , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , _______ , _______ ,      _______      , _______,
  _______ , RGB_RMOD , KC_DEL      , RGB_HUD , RGB_SAD , KC_PRVWD , NK_TOGG , _______ , _______ , _______ , _______ ,      _______      , _______ , _______,
  _______ , _______  , _______     ,                          _______                           , _______ , _______ , _______ , _______ , _______ , _______
),

//    ┌─────────┬──────────┬─────────┬─────────┬──────────┬─────────┬─────────┬──────┬──────┬──────┬──────┬──────┬──────┬─────┬─────────┐
//    │    `    │   bRID   │  bRIU   │  tASK   │   f  ILE │ RGB_VAD │ RGB_VAI │ mprv │ mply │ mnxt │ mute │ vold │ volu │     │ RGB_TOG │
//    ├─────────┼──────────┼─────────┼─────────┼──────────┼─────────┼─────────┼──────┼──────┼──────┼──────┼──────┼──────┼─────┼─────────┤
//    │         │ BT_HST1  │ BT_HST2 │ BT_HST3 │          │         │         │      │      │      │      │      │      │     │         │
//    ├─────────┼──────────┼─────────┼─────────┼──────────┼─────────┼─────────┼──────┼──────┼──────┼──────┼──────┼──────┴─────┼─────────┤
//    │ RGB_TOG │   RGB    │ RGB_VAI │ RGB_HUI │ RGB_SAI  │ RGB_SPI │         │      │      │      │      │      │            │         │
//    ├─────────┼──────────┼─────────┼─────────┼──────────┼─────────┼─────────┼──────┼──────┼──────┼──────┼──────┴──────┬─────┼─────────┤
//    │         │ RGB_RMOD │ RGB_VAD │ RGB_HUD │ RGB_SAD  │ RGB_SPD │ NK_TOGG │      │      │      │      │             │     │         │
//    ├─────────┼──────────┼─────────┼─────────┴──────────┴─────────┴─────────┴──────┴──────┼──────┼──────┼──────┬──────┼─────┼─────────┤
//    │         │          │         │                                                      │      │      │      │      │     │         │
//    └─────────┴──────────┴─────────┴──────────────────────────────────────────────────────┴──────┴──────┴──────┴──────┴─────┴─────────┘
[WIN_FN1] = LAYOUT_ansi_68(
  KC_GRV  , KC_BRID  , KC_BRIU , KC_TASK , KC_FILE , RGB_VAD , RGB_VAI , KC_MPRV , KC_MPLY , KC_MNXT , KC_MUTE , KC_VOLD , KC_VOLU , KC_TRNS , RGB_TOG,
  KC_TRNS , BT_HST1  , BT_HST2 , BT_HST3 , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
  RGB_TOG , RGB_MOD  , RGB_VAI , RGB_HUI , RGB_SAI , RGB_SPI , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,      KC_TRNS      , KC_TRNS,
  KC_TRNS , RGB_RMOD , RGB_VAD , RGB_HUD , RGB_SAD , RGB_SPD , NK_TOGG , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,      KC_TRNS      , KC_TRNS , KC_TRNS,
  KC_TRNS , KC_TRNS  , KC_TRNS ,                          KC_TRNS                          , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS
),

//    ┌─────┬─────┬─────┬─────┬─────┬─────────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
//    │  ~  │ f1  │ f2  │ f3  │ f4  │   f5    │ f6  │ f7  │ f8  │ f9  │ f10 │ f11 │ f12 │     │     │
//    ├─────┼─────┼─────┼─────┼─────┼─────────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
//    │     │     │     │     │     │         │     │     │     │     │     │     │     │     │     │
//    ├─────┼─────┼─────┼─────┼─────┼─────────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┤
//    │     │     │     │     │     │         │     │     │     │     │     │     │           │     │
//    ├─────┼─────┼─────┼─────┼─────┼─────────┼─────┼─────┼─────┼─────┼─────┼─────┴─────┬─────┼─────┤
//    │     │     │     │     │     │ BAT_LVL │     │     │     │     │     │           │     │     │
//    ├─────┼─────┼─────┼─────┴─────┴─────────┴─────┴─────┴─────┼─────┼─────┼─────┬─────┼─────┼─────┤
//    │     │     │     │                                       │     │     │     │     │     │     │
//    └─────┴─────┴─────┴───────────────────────────────────────┴─────┴─────┴─────┴─────┴─────┴─────┘
[FN2] = LAYOUT_ansi_68(
  KC_TILD , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  , KC_TRNS , KC_TRNS,
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,      KC_TRNS      , KC_TRNS,
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , BAT_LVL , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,      KC_TRNS      , KC_TRNS , KC_TRNS,
  KC_TRNS , KC_TRNS , KC_TRNS ,                          KC_TRNS                          , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS
),

//    ┌─────┬─────┬─────┬─────┬─────┬─────────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
//    │  ~  │ f1  │ f2  │ f3  │ f4  │   f5    │ f6  │ f7  │ f8  │ f9  │ f10 │ f11 │ f12 │     │     │
//    ├─────┼─────┼─────┼─────┼─────┼─────────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
//    │     │  1  │  2  │  3  │  4  │    5    │  6  │  7  │  8  │  9  │  0  │  -  │     │     │     │
//    ├─────┼─────┼─────┼─────┼─────┼─────────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┤
//    │     │  !  │  @  │  #  │  $  │    %    │  ^  │  &  │  *  │  (  │  )  │  |  │           │     │
//    ├─────┼─────┼─────┼─────┼─────┼─────────┼─────┼─────┼─────┼─────┼─────┼─────┴─────┬─────┼─────┤
//    │     │     │     │     │     │ BAT_LVL │     │     │     │     │     │           │     │     │
//    ├─────┼─────┼─────┼─────┴─────┴─────────┴─────┴─────┴─────┼─────┼─────┼─────┬─────┼─────┼─────┤
//    │     │     │     │                                       │     │     │     │     │     │     │
//    └─────┴─────┴─────┴───────────────────────────────────────┴─────┴─────┴─────┴─────┴─────┴─────┘
[NUM] = LAYOUT_ansi_68(
  KC_TILD , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  , KC_TRNS , KC_TRNS,
  KC_TRNS , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_MINS , KC_TRNS , KC_TRNS , KC_TRNS,
  KC_TRNS , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC , KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , KC_PIPE ,      KC_TRNS      , KC_TRNS,
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , BAT_LVL , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,      KC_TRNS      , KC_TRNS , KC_TRNS,
  KC_TRNS , KC_TRNS , KC_TRNS ,                          KC_TRNS                          , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS
),

//    ┌─────┬─────┬─────┬────┬────┬────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
//    │  ~  │ f1  │ f2  │ f3 │ f4 │ f5 │ f6  │ f7  │ f8  │ f9  │ f10 │ f11 │ f12 │     │     │
//    ├─────┼─────┼─────┼────┼────┼────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
//    │     │  `  │  7  │ 8  │ 9  │ \  │  6  │  7  │  8  │  9  │  0  │  -  │     │     │     │
//    ├─────┼─────┼─────┼────┼────┼────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┤
//    │     │  0  │  1  │ 2  │ 3  │ -  │  ^  │  &  │  *  │  (  │  )  │  |  │           │     │
//    ├─────┼─────┼─────┼────┼────┼────┼─────┼─────┼─────┼─────┼─────┼─────┴─────┬─────┼─────┤
//    │     │  ~  │  4  │ 5  │ 6  │ =  │     │     │     │     │     │           │     │     │
//    ├─────┼─────┼─────┼────┴────┴────┴─────┴─────┴─────┼─────┼─────┼─────┬─────┼─────┼─────┤
//    │     │     │     │              lgui              │     │     │     │     │     │     │
//    └─────┴─────┴─────┴────────────────────────────────┴─────┴─────┴─────┴─────┴─────┴─────┘
[NUM_2] = LAYOUT_ansi_68(
  KC_TILD , KC_F1   , KC_F2   , KC_F3 , KC_F4 , KC_F5   , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  , KC_TRNS , KC_TRNS,
  KC_TRNS , KC_GRV  , KC_7    , KC_8  , KC_9  , KC_BSLS , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_MINS , KC_TRNS , KC_TRNS , KC_TRNS,
  KC_TRNS , KC_0    , KC_1    , KC_2  , KC_3  , KC_MINS , KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , KC_PIPE ,      KC_TRNS      , KC_TRNS,
  KC_TRNS , KC_TILD , KC_4    , KC_5  , KC_6  , KC_EQL  , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,      KC_TRNS      , KC_TRNS , KC_TRNS,
  KC_TRNS , KC_TRNS , KC_TRNS ,                        KC_LGUI                        , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS
)
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CTL_ESC:
            return TAPPING_TERM - 50;
        default:
            return TAPPING_TERM;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LALT_CAP:
            if (record->tap.count && record->event.pressed) {
                tap_code16(CW_TOGG); // Send CW_TOGG on tap
                return false;        // Return false to ignore further processing of key
            }
            break;

        case RALT_T(CW_TOGG):
            if (record->tap.count && record->event.pressed) {
                tap_code16(CW_TOGG); // Send CW_TOGG on tap
                return false;        // Return false to ignore further processing of key
            }
            break;
        case KC_PRVWD:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_LEFT);
            }
            break;
        case KC_NXTWD:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_RIGHT);
            }
            break;
    }
    return true;
}
