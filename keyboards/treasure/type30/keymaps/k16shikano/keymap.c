#include QMK_KEYBOARD_H

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_A):
            return 175;
        case LCTL_T(KC_Z):
            return 225;
        case LCTL_T(KC_S):
            return 225;
        case LSFT_T(KC_X):
            return 150;
        case LSFT_T(KC_G):
            return 225;
        case LT(4,KC_F):
            return 225;
        case LALT_T(KC_C):
            return 225;
        case LT(4,KC_V):
            return 225;
        case LT(3,KC_ENT):
            return 130;
        case LT(2,KC_B):
            return 90;
        case LT(1,KC_N):
            return 200;
        default:
            return TAPPING_TERM;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_A):
            return false;
        case LCTL_T(KC_Z):
            return false;
        case LCTL_T(KC_S):
            return false;
        case LSFT_T(KC_X):
            return true;
        case LSFT_T(KC_G):
            return false;
        case LALT_T(KC_C):
            return false;
        case LT(4,KC_V):
            return false;
        case LT(2,KC_B):
            return true;
        case LT(1,KC_N):
            return false;
        default:
            return false;
    }
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_A):
            return 25;
        case LT(3,KC_ENT):
            return 75;
        case LT(2,KC_B):
            return 75;
        case LSFT_T(KC_X):
            return QUICK_TAP_TERM;
        case LT(1,KC_N):
            return 5;
        case LCTL_T(KC_S):
            return 75;
        default:
            return QUICK_TAP_TERM;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_A):
            return false;
        case LCTL_T(KC_Z):
            return false;
        case LCTL_T(KC_S):
            return false;
        case LSFT_T(KC_X):
            return true;
        case LSFT_T(KC_G):
            return false;
        case LALT_T(KC_C):
            return false;
        case LT(4,KC_V):
            return false;
        case LT(2,KC_B):
            return true;
        case LT(1,KC_N):
            return false;
        default:
            return false;
    }
}

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_S):
            return true;
        default:
            return false;
    }
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
    KC_Q, KC_W,         KC_E,         KC_R,         KC_T,       KC_ESC, KC_TRNS,  KC_Y,        KC_U,    KC_I,     KC_O,          KC_BACKSPACE,
    LCTL_T(KC_A), LCTL_T(KC_S), KC_D,         LT(4,KC_F),   LT(5,KC_G), KC_TRNS, KC_TRNS,  KC_H,        KC_J,    KC_K,     KC_L,          LT(5,KC_P),
    LCTL_T(KC_Z), LSFT_T(KC_X), LALT_T(KC_C), LT(4,KC_V),   LT(2,KC_B), KC_TRNS, KC_TRNS,  LT(1,KC_N),  KC_M,    KC_COMMA,LSFT_T(KC_DOT),LT(3,KC_ENT)
    ),

    [1] = LAYOUT(
    KC_1,         KC_2,         KC_3,         KC_4,         KC_5,       KC_ESC, KC_TRNS,  KC_6,        KC_7,    KC_8,    KC_9,           KC_0,
    KC_TAB,       KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_SPC,     KC_TRNS, KC_TRNS,  KC_1,        KC_2,    KC_3,    KC_4,           KC_5,
    KC_LCTL,      KC_LSFT,      KC_LALT,      KC_SPC,       KC_SPC,     KC_TRNS, KC_TRNS,  KC_SPC,      KC_SPC,  KC_TAB,  KC_TAB,         LALT(KC_GRV)
    ),

  [2] = LAYOUT(
    KC_EXLM,      KC_AT,        KC_HASH,      KC_DLR,       KC_PERC,      KC_ESC, KC_TRNS, KC_CIRC,     KC_AMPR, KC_ASTR, KC_MINS,        KC_EQL,
    KC_LCTL,      KC_GRV,       KC_TILD,      LALT(KC_GRV), LALT(KC_GRV), KC_TRNS, KC_TRNS, KC_LPRN,     KC_RPRN, KC_SCLN, KC_COLN, KC_BSLS,
    KC_LCTL,      KC_LSFT,      KC_LALT,      LALT(KC_GRV), LT(2,KC_NO),  KC_TRNS, KC_TRNS, KC_LBRC,     KC_RBRC, KC_LT,   KC_GT,          LT(3,KC_SLSH)),

  [3] = LAYOUT(
    KC_ESC,       KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,  KC_ESC, KC_TRNS,    KC_LEFT,     KC_UP,   KC_UP,   KC_UP,          KC_DEL,
    KC_LCTL,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,  KC_TRNS, KC_TRNS,    KC_LEFT,     KC_LEFT, KC_UP,   KC_RGHT,        KC_TRNS,
    KC_LCTL,      KC_LSFT,      KC_LALT,      KC_TRNS,      KC_LSFT,  KC_TRNS, KC_TRNS,    KC_LEFT,     KC_LEFT, KC_DOWN, KC_RGHT,        LT(3,KC_NO)),

  [4] = LAYOUT(
    KC_EXLM,      KC_AT,        KC_HASH,      KC_DLR,       KC_PERC,  KC_ESC, KC_TRNS,    KC_CIRC,     KC_AMPR, KC_ASTR, KC_MINS,        KC_EQL,
    KC_TAB,       KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,  KC_TRNS, KC_TRNS,    KC_LPRN,     KC_RPRN, KC_LCBR, KC_RCBR,        KC_BSLS,
    KC_LCTL,      KC_LSFT,      KC_LALT,      LT(4,KC_NO),  KC_SPACE, KC_TRNS, KC_TRNS,    KC_LBRC,     KC_RBRC, KC_QUOT, KC_DQUO,          KC_GRV),

  [5] = LAYOUT(
    KC_F1,        KC_F2,        KC_F3,        KC_F4,       KC_F5,       KC_ESC, KC_TRNS,  KC_F6,       KC_F7,   KC_F8,   KC_F9,          KC_F10,
    KC_F11,       KC_F12,       KC_TRNS,      QK_BOOT,     LT(5,KC_NO), KC_TRNS, KC_TRNS,  KC_TRNS,     KC_TRNS, KC_TRNS, QK_BOOT,        LT(5,KC_NO),
    RM_TOGG,      RM_HUEU,      RM_NEXT,      RM_VALU,     RM_VALD,     KC_TRNS, KC_TRNS,  QK_BOOT,     KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS)
};
