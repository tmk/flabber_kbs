#include "keymap_common.h"

const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* base layer */
  [0] = KEYMAP(
    ESC, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC, \
    FN12,FN5, S,   D,   F,   G,   H,   J,   K,   L,   FN6,      FN1,  \
    LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT,      FN7, RSFT, \
         LGUI, FN13,    FN0,        FN2,        FN2,  BSLS,GRV        \
  ),
  /* left thumb - numbers */
  [1] = KEYMAP(
    GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL,  \
    TRNS,1,   2,   3,   4,   5,   6,   7,   8,   9,   0,        QUOT, \
    TRNS,NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  INS,      DEL, TRNS, \
         TRNS, TRNS,    TRNS,      FN3,         TRNS, TRNS,TRNS       \
  ),
  /* right thumb - mouse */
  [2] = KEYMAP(
    GRV, NO,  NO,  NO,  NO,  NO,  WH_L,WH_D,MS_U,WH_U,WH_R,BSLS,GRV,  \
    TRNS,VOLD,VOLU,MUTE,NO,  NO,  NO,  MS_L,MS_D,MS_R,BTN1,     QUOT, \
    TRNS,NO,  NO,  NO,  NO,  BTN3,BTN2,BTN1,FN9, FN10,     DEL, TRNS, \
         TRNS, TRNS,    FN4,       TRNS,        TRNS, TRNS,TRNS       \
  ),
  /* both thumb(left->right) - Fkeys */
  [3] = KEYMAP(
    GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12,  \
    TRNS,1,   2,   3,   4,   5,   6,   7,   8,   9,   0,        TRNS, \
    TRNS,NO,  NO,  CAPS,NO,  NO,  NO,  NO,  NO,  NO,       NO,  TRNS, \
         TRNS, TRNS,    TRNS,      FN3,         TRNS, TRNS,BTLD       \
  ),
  /* both thumbs(right->left) - Fkeys */
  [4] = KEYMAP(
    ESC, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12,  \
    TRNS,1,   2,   3,   4,   5,   6,   7,   8,   9,   0,        TRNS, \
    TRNS,NO,  NO,  CAPS,NO,  NO,  PSCR,SLCK,PAUS,INS,      DEL, TRNS, \
         TRNS, TRNS,    FN4,       TRNS,        TRNS, TRNS,BTLD       \
  ),
  /* left pinky - numbers */
  [5] = KEYMAP(
    TAB, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   F11, F12,  \
    TRNS,TRNS,2,   3,   4,   5,   6,   7,   8,   9,   0,        QUOT, \
    TRNS,NO,  NO,  NO,  NO,  NO,  PSCR,SLCK,PAUS,INS,      DEL, TRNS, \
         TRNS, TRNS,    TRNS,      FN4,         TRNS, TRNS,TRNS       \
  ),
  /* right pinky - cursor and numbers */
  [6] = KEYMAP(
    TAB, 1,   2,   3,   4,   5,   HOME,PGDN,PGUP,END, NO,  NO,  NO,   \
    TRNS,1,   2,   3,   4,   5,   LEFT,DOWN,UP,  RGHT,TRNS,     NO,   \
    TRNS,NO,  NO,  NO,  NO,  NO,  HOME,PGDN,PGUP,END,      TRNS,TRNS, \
         TRNS, TRNS,    TRNS,      TRNS,        TRNS, TRNS,TRNS       \
  ),
  /* easy alt+tab and control+tab */
  [7] = KEYMAP(
    TAB, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS, \
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS, \
         TRNS, LALT,    TRNS,       TRNS,       TRNS, TRNS,TRNS       \
  ),
  [8] = KEYMAP(
    TAB, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
    LCTL,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS, \
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS, \
         TRNS, TRNS,    TRNS,       TRNS,       TRNS, TRNS,TRNS       \
  ),
};


/*
 * Macro definition
 */
enum macro_id {
    ALT_TAB,
};
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
        case ALT_TAB:
            return (record->event.pressed ?
                    MACRO( D(LALT), D(TAB), END ) : MACRO( U(TAB), END ));
    }
    return MACRO_NONE;
}


const uint16_t fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),
    [1] = ACTION_LAYER_TAP(1, KC_ENTER),
    [2] = ACTION_LAYER_TAP(2, KC_SPC),
    [3] = ACTION_LAYER_TAP(3, KC_BSPC),
    [4] = ACTION_LAYER_TAP(4, KC_BSPC),
    [5] = ACTION_LAYER_TAP(5, KC_A),
    [6] = ACTION_LAYER_TAP(6, KC_SCOLON),
    [7] = ACTION_LAYER_TAP(6, KC_SLASH),
    [9] = ACTION_MODS_KEY(MOD_LALT, KC_LEFT),
    [10] = ACTION_MODS_KEY(MOD_LALT, KC_RIGHT),
    [11] = ACTION_MACRO(ALT_TAB),
    [12] = ACTION_LAYER_MODS(7, MOD_LCTL),
    [13] = ACTION_LAYER_MODS(8, MOD_LALT),
};

