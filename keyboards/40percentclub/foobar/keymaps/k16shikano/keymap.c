#include QMK_KEYBOARD_H

/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */

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
            return false;
        case LSFT_T(KC_G):
            return false;
        case LALT_T(KC_C):
            return false;
        case LT(4,KC_V):
            return false;
        case LT(2,KC_B):
            return false;
        case LT(1,KC_N):
            return false;
        default:
            return true;
    }
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_A):
            return 0;
        case LT(3,KC_ENT):
            return 0;
        case LT(2,KC_B):
            return 0;
        case LSFT_T(KC_X):
            return 0;
        case LT(1,KC_N):
            return 0;
        case LCTL_T(KC_S):
            return 0;
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
            return false;
        case LSFT_T(KC_G):
            return false;
        case LALT_T(KC_C):
            return false;
        case LT(4,KC_V):
            return false;
        case LT(2,KC_B):
            return false;
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

// Tap Dance declarations
enum {
      TD_Q_ESC,
      TD_CD,
      TD_ST,
      TD_QT_DQ,
      TD_SC_CL,
};

void dance_q_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code16(KC_Q);
    } else {
        register_code(KC_ESCAPE);
    }
}

void dance_q_reset(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code16(KC_Q);
    } else {
        unregister_code(KC_ESCAPE);
    }
}

void dance_cd_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code16(KC_COMMA);
    } else {
      register_code(KC_DOT);
    }
}

void dance_cd_reset(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code16(KC_COMMA);
    } else {
        unregister_code(KC_DOT);
    }
}

void dance_st_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code16(KC_SPACE);
    } else {
      register_code(KC_TAB);
    }
}

void dance_st_reset(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code16(KC_SPACE);
    } else {
        unregister_code(KC_TAB);
    }
}

void dance_qtdq_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_QUOT);
    } else {
      register_code16(KC_DQUO);
    }
}

void dance_qtdq_reset(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code(KC_QUOT);
    } else {
        unregister_code16(KC_DQUO);
    }
}

void dance_sccl_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_SCLN);
    } else {
      register_code16(KC_COLN);
    }
}

void dance_sccl_reset(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code(KC_SCLN);
    } else {
        unregister_code16(KC_COLN);
    }
}

// All tap dance functions would go here. Only showing this one.
tap_dance_action_t tap_dance_actions[] = {
    [TD_Q_ESC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_q_finished, dance_q_reset),
    [TD_CD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cd_finished, dance_cd_reset),
    [TD_ST] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_st_finished, dance_st_reset),
    [TD_QT_DQ] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_qtdq_finished, dance_qtdq_reset),
    [TD_SC_CL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_sccl_finished, dance_sccl_reset),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split(
    TD(TD_Q_ESC), KC_W,         KC_E,         KC_R,         KC_T,        KC_Y,        KC_U,    KC_I,     KC_O,          KC_BSPC,
    LCTL_T(KC_A), LCTL_T(KC_S), KC_D,         LT(4,KC_F),   LSFT_T(KC_G),KC_H,        KC_J,    KC_K,     KC_L,          LT(5,KC_P),
    LCTL_T(KC_Z), LSFT_T(KC_X), LALT_T(KC_C), LT(4,KC_V),   LT(2,KC_B),  LT(1,KC_N),  KC_M,    TD(TD_CD),LSFT_T(KC_DOT),LT(3,KC_ENT)),

  [1] = LAYOUT_split(
    KC_1,         KC_2,         KC_3,         KC_4,         KC_5,        KC_6,        KC_7,    KC_8,    KC_9,           KC_0,
    KC_TAB,       KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_SPC,      KC_1,        KC_2,    KC_3,    KC_4,           KC_5,
    KC_LCTL,      KC_LSFT,      KC_LALT,      KC_SPC,       KC_SPC,      KC_SPC,      KC_SPC,  KC_TAB,  KC_TAB,         LALT(KC_GRV)),

  [2] = LAYOUT_split(
    KC_EXLM,      KC_AT,        KC_HASH,      KC_DLR,       KC_PERC,     KC_CIRC,     KC_AMPR, KC_ASTR, KC_MINS,        KC_EQL,
    KC_LCTL,      KC_GRV,       KC_TILD,      LALT(KC_GRV), LALT(KC_GRV),KC_LPRN,     KC_RPRN, TD(TD_SC_CL), TD(TD_QT_DQ), KC_BSLS,
    KC_LCTL,      KC_LSFT,      KC_LALT,      LALT(KC_GRV), LT(2,KC_NO), KC_LBRC,     KC_RBRC, KC_LT,   KC_GT,          LT(3,KC_SLSH)),

  [3] = LAYOUT_split(
    KC_ESC,       KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,     KC_LEFT,     KC_UP,   KC_UP,   KC_UP,          KC_DEL,
    KC_LCTL,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,     KC_LEFT,     KC_LEFT, KC_UP,   KC_RGHT,        KC_TRNS,
    KC_LCTL,      KC_LSFT,      KC_LALT,      KC_TRNS,      KC_LSFT,     KC_LEFT,     KC_LEFT, KC_DOWN, KC_RGHT,        LT(3,KC_NO)),

  [4] = LAYOUT_split(
    KC_EXLM,      KC_AT,        KC_HASH,      KC_DLR,       KC_PERC,     KC_CIRC,     KC_AMPR, KC_ASTR, KC_MINS,        KC_EQL,
    KC_TAB,       KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,     KC_LPRN,     KC_RPRN, KC_LCBR, KC_RCBR,        KC_BSLS,
    KC_LCTL,      KC_LSFT,      KC_LALT,      LT(4,KC_NO),  KC_SPACE,    KC_LBRC,     KC_RBRC, KC_LT,   KC_GT,          KC_GRV),

  [5] = LAYOUT_split(
    KC_F1,        KC_F2,        KC_F3,        KC_F4,       KC_F5,        KC_F6,       KC_F7,   KC_F8,   KC_F9,          KC_F10,
    KC_F11,       KC_F12,       KC_TRNS,      KC_TRNS,     KC_TRNS,      KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS,        LT(5,KC_NO),
    KC_LCTL,      KC_LSFT,      KC_LALT,      KC_TRNS,     KC_DEL,       QK_BOOT,     KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS)
};
