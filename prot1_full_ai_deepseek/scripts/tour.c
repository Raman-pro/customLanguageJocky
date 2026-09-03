// JOCKY build A903AF514AC976BA seed=7 date=2026-09-03 04:44:56
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0600
#endif
#if defined(_WIN32)
#define WIN32_LEAN_AND_MEAN
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <tlhelp32.h>
#include <direct.h>
#elif defined(__APPLE__)
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <libproc.h>
#else
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#endif

static const volatile uint8_t j_enc_0[] = {0xC5, 0xC4, 0xC7, 0xC6, 0xC1, 0xC0, 0xC3, 0xC2, 0xCD, 0xCC, 0x94, 0x97, 0x96, 0x91, 0x90, 0x93};
static const char* j_dc_0(void) {
    static char j_rb[17];
    for (int j_i = 0; j_i < 16; j_i++) j_rb[j_i] = j_enc_0[j_i] ^ 245;
    j_rb[16] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_1[] = {0x1A, 0x1B, 0x18, 0x19, 0x1E, 0x1F, 0x1C, 0x1D, 0x12, 0x13, 0x4B, 0x48, 0x49, 0x4E, 0x4F, 0x4C};
static const char* j_dc_1(void) {
    static char j_rb[17];
    for (int j_i = 0; j_i < 16; j_i++) j_rb[j_i] = j_enc_1[j_i] ^ 42;
    j_rb[16] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_2[] = {0xB1, 0xA1};
static const char* j_dc_2(void) {
    static char j_rb[3];
    for (int j_i = 0; j_i < 2; j_i++) j_rb[j_i] = j_enc_2[j_i] ^ 195;
    j_rb[2] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_3[] = {0xC8, 0xDD};
static const char* j_dc_3(void) {
    static char j_rb[3];
    for (int j_i = 0; j_i < 2; j_i++) j_rb[j_i] = j_enc_3[j_i] ^ 191;
    j_rb[2] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_4[] = {0x8E, 0xD1, 0xD3, 0xCE, 0xC2};
static const char* j_dc_4(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_4[j_i] ^ 161;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_5[] = {0x0D};
static const char* j_dc_5(void) {
    static char j_rb[2];
    for (int j_i = 0; j_i < 1; j_i++) j_rb[j_i] = j_enc_5[j_i] ^ 127;
    j_rb[1] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_6[] = {0x03};
static const char* j_dc_6(void) {
    static char j_rb[2];
    for (int j_i = 0; j_i < 1; j_i++) j_rb[j_i] = j_enc_6[j_i] ^ 9;
    j_rb[1] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_7[] = {0x27};
static const char* j_dc_7(void) {
    static char j_rb[2];
    for (int j_i = 0; j_i < 1; j_i++) j_rb[j_i] = j_enc_7[j_i] ^ 85;
    j_rb[1] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_8[] = {0xB6};
static const char* j_dc_8(void) {
    static char j_rb[2];
    for (int j_i = 0; j_i < 1; j_i++) j_rb[j_i] = j_enc_8[j_i] ^ 137;
    j_rb[1] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_9[] = {0x22, 0x27, 0x3D, 0x3A, 0x2B, 0x20};
static const char* j_dc_9(void) {
    static char j_rb[7];
    for (int j_i = 0; j_i < 6; j_i++) j_rb[j_i] = j_enc_9[j_i] ^ 110;
    j_rb[6] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_10[] = {0x67, 0x71, 0x76, 0x63, 0x60, 0x6E, 0x6B, 0x71, 0x6A, 0x67, 0x66};
static const char* j_dc_10(void) {
    static char j_rb[12];
    for (int j_i = 0; j_i < 11; j_i++) j_rb[j_i] = j_enc_10[j_i] ^ 34;
    j_rb[11] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_11[] = {0xD5, 0xDA, 0xD9, 0xC5, 0xD3, 0xC9, 0xC1, 0xD7, 0xDF, 0xC2};
static const char* j_dc_11(void) {
    static char j_rb[11];
    for (int j_i = 0; j_i < 10; j_i++) j_rb[j_i] = j_enc_11[j_i] ^ 150;
    j_rb[10] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_12[] = {0xEB, 0xF6, 0xF2, 0xFA, 0xE0, 0xE8, 0xFE, 0xF6, 0xEB};
static const char* j_dc_12(void) {
    static char j_rb[10];
    for (int j_i = 0; j_i < 9; j_i++) j_rb[j_i] = j_enc_12[j_i] ^ 191;
    j_rb[9] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_13[] = {0x48, 0x53, 0x4F, 0x42, 0x55};
static const char* j_dc_13(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_13[j_i] ^ 7;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_14[] = {0x69, 0x62, 0x73, 0x74, 0x73, 0x66, 0x73, 0x27, 0x2A, 0x66, 0x69, 0x27, 0x2A, 0x77, 0x27, 0x73, 0x64, 0x77, 0x27, 0x35, 0x39, 0x28, 0x63, 0x62, 0x71, 0x28, 0x69, 0x72, 0x6B, 0x6B};
static const char* j_dc_14(void) {
    static char j_rb[31];
    for (int j_i = 0; j_i < 30; j_i++) j_rb[j_i] = j_enc_14[j_i] ^ 7;
    j_rb[30] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_15[] = {0xA2};
static const char* j_dc_15(void) {
    static char j_rb[2];
    for (int j_i = 0; j_i < 1; j_i++) j_rb[j_i] = j_enc_15[j_i] ^ 208;
    j_rb[1] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_16[] = {0x9D, 0x8A, 0x99};
static const char* j_dc_16(void) {
    static char j_rb[4];
    for (int j_i = 0; j_i < 3; j_i++) j_rb[j_i] = j_enc_16[j_i] ^ 233;
    j_rb[3] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_17[] = {0x2D, 0x72, 0x70, 0x6D, 0x61, 0x2D, 0x6C, 0x67, 0x76, 0x2D, 0x76, 0x61, 0x72};
static const char* j_dc_17(void) {
    static char j_rb[14];
    for (int j_i = 0; j_i < 13; j_i++) j_rb[j_i] = j_enc_17[j_i] ^ 2;
    j_rb[13] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_18[] = {0xE5, 0xBA, 0xB8, 0xA5, 0xA9, 0xE5, 0xA4, 0xAF, 0xBE, 0xE5, 0xBE, 0xA9, 0xBA, 0xFC};
static const char* j_dc_18(void) {
    static char j_rb[15];
    for (int j_i = 0; j_i < 14; j_i++) j_rb[j_i] = j_enc_18[j_i] ^ 202;
    j_rb[14] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_19[] = {0x39, 0x3A, 0x3D, 0x3C, 0x2D};
static const char* j_dc_19(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_19[j_i] ^ 113;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_20[] = {0xB8, 0xBB, 0xB3, 0xA5, 0xAC};
static const char* j_dc_20(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_20[j_i] ^ 240;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_21[] = {0xAA, 0xA9, 0xA1, 0xB0, 0xBE};
static const char* j_dc_21(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_21[j_i] ^ 226;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_22[] = {0xF3, 0xF0, 0xEE, 0xE7};
static const char* j_dc_22(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_22[j_i] ^ 187;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_23[] = {0xE5, 0xF0};
static const char* j_dc_23(void) {
    static char j_rb[3];
    for (int j_i = 0; j_i < 2; j_i++) j_rb[j_i] = j_enc_23[j_i] ^ 146;
    j_rb[2] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_24[] = {0xF9, 0xFF, 0xF8, 0xE8};
static const char* j_dc_24(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_24[j_i] ^ 141;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_25[] = {0x41, 0x46, 0x4B, 0x54, 0x42};
static const char* j_dc_25(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_25[j_i] ^ 39;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_26[] = {0x9F, 0x99, 0x9E, 0x8E};
static const char* j_dc_26(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_26[j_i] ^ 235;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_27[] = {0x1B, 0x1C, 0x11, 0x0E, 0x18};
static const char* j_dc_27(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_27[j_i] ^ 125;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_28[] = {0x20, 0x26, 0x21, 0x31};
static const char* j_dc_28(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_28[j_i] ^ 84;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_29[] = {0xB1, 0xB6, 0xBB, 0xA4, 0xB2};
static const char* j_dc_29(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_29[j_i] ^ 215;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_30[] = {0xF7, 0xF1, 0xF6, 0xE6};
static const char* j_dc_30(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_30[j_i] ^ 131;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_31[] = {0xD3, 0xD4, 0xD9, 0xC6, 0xD0};
static const char* j_dc_31(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_31[j_i] ^ 181;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_32[] = {0x7C, 0x7A, 0x7D, 0x6D};
static const char* j_dc_32(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_32[j_i] ^ 8;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_33[] = {0x59, 0x5E, 0x53, 0x4C, 0x5A};
static const char* j_dc_33(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_33[j_i] ^ 63;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_34[] = {0x8C, 0x8A, 0x8D, 0x9D};
static const char* j_dc_34(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_34[j_i] ^ 248;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_35[] = {0x2E, 0x29, 0x24, 0x3B, 0x2D};
static const char* j_dc_35(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_35[j_i] ^ 72;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_36[] = {0xE3, 0xE5, 0xE2, 0xF2};
static const char* j_dc_36(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_36[j_i] ^ 151;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_37[] = {0x5E, 0x59, 0x54, 0x4B, 0x5D};
static const char* j_dc_37(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_37[j_i] ^ 56;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_38[] = {0x72, 0x74, 0x73, 0x63};
static const char* j_dc_38(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_38[j_i] ^ 6;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_39[] = {0x4F, 0x48, 0x45, 0x5A, 0x4C};
static const char* j_dc_39(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_39[j_i] ^ 41;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_40[] = {0x9E, 0x98, 0x9F, 0x8F};
static const char* j_dc_40(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_40[j_i] ^ 234;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_41[] = {0x96, 0x91, 0x9C, 0x83, 0x95};
static const char* j_dc_41(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_41[j_i] ^ 240;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_42[] = {0x08, 0x0E, 0x09, 0x19};
static const char* j_dc_42(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_42[j_i] ^ 124;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_43[] = {0x5F, 0x58, 0x55, 0x4A, 0x5C};
static const char* j_dc_43(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_43[j_i] ^ 57;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_44[] = {0x85, 0x83, 0x84, 0x94};
static const char* j_dc_44(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_44[j_i] ^ 241;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_45[] = {0x0A, 0x0D, 0x00, 0x1F, 0x09};
static const char* j_dc_45(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_45[j_i] ^ 108;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_46[] = {0x4E, 0x48, 0x4F, 0x5F};
static const char* j_dc_46(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_46[j_i] ^ 58;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_47[] = {0x4B, 0x4C, 0x41, 0x5E, 0x48};
static const char* j_dc_47(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_47[j_i] ^ 45;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_48[] = {0x27, 0x21, 0x26, 0x36};
static const char* j_dc_48(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_48[j_i] ^ 83;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_49[] = {0xC8, 0xCF, 0xC2, 0xDD, 0xCB};
static const char* j_dc_49(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_49[j_i] ^ 174;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_50[] = {0x52, 0x54, 0x53, 0x43};
static const char* j_dc_50(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_50[j_i] ^ 38;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_51[] = {0x9C, 0x9B, 0x96, 0x89, 0x9F};
static const char* j_dc_51(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_51[j_i] ^ 250;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_52[] = {0x3B, 0x3D, 0x3A, 0x2A};
static const char* j_dc_52(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_52[j_i] ^ 79;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_53[] = {0x38, 0x3F, 0x32, 0x2D, 0x3B};
static const char* j_dc_53(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_53[j_i] ^ 94;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_54[] = {0xE6, 0xE0, 0xE7, 0xF7};
static const char* j_dc_54(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_54[j_i] ^ 146;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_55[] = {0x74, 0x73, 0x7E, 0x61, 0x77};
static const char* j_dc_55(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_55[j_i] ^ 18;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_56[] = {0x87, 0x81, 0x86, 0x96};
static const char* j_dc_56(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_56[j_i] ^ 243;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_57[] = {0x05, 0x02, 0x0F, 0x10, 0x06};
static const char* j_dc_57(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_57[j_i] ^ 99;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_58[] = {0xB5, 0xB3, 0xB4, 0xA4};
static const char* j_dc_58(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_58[j_i] ^ 193;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_59[] = {0x4D, 0x4A, 0x47, 0x58, 0x4E};
static const char* j_dc_59(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_59[j_i] ^ 43;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_60[] = {0x8E, 0x88, 0x8F, 0x9F};
static const char* j_dc_60(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_60[j_i] ^ 250;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_61[] = {0xE6, 0xE1, 0xEC, 0xF3, 0xE5};
static const char* j_dc_61(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_61[j_i] ^ 128;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_62[] = {0x35, 0x33, 0x34, 0x24};
static const char* j_dc_62(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_62[j_i] ^ 65;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_63[] = {0x45, 0x42, 0x4F, 0x50, 0x46};
static const char* j_dc_63(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_63[j_i] ^ 35;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_64[] = {0xD7, 0xD1, 0xD6, 0xC6};
static const char* j_dc_64(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_64[j_i] ^ 163;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_65[] = {0xFB, 0xFC, 0xF1, 0xEE, 0xF8};
static const char* j_dc_65(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_65[j_i] ^ 157;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_66[] = {0x39, 0x3F, 0x38, 0x28};
static const char* j_dc_66(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_66[j_i] ^ 77;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_67[] = {0x5B, 0x5C, 0x51, 0x4E, 0x58};
static const char* j_dc_67(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_67[j_i] ^ 61;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_68[] = {0xE6, 0xE0, 0xE7, 0xF7};
static const char* j_dc_68(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_68[j_i] ^ 146;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_69[] = {0x5D, 0x5A, 0x57, 0x48, 0x5E};
static const char* j_dc_69(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_69[j_i] ^ 59;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_70[] = {0x00, 0x06, 0x01, 0x11};
static const char* j_dc_70(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_70[j_i] ^ 116;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_71[] = {0xC6, 0xC1, 0xCC, 0xD3, 0xC5};
static const char* j_dc_71(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_71[j_i] ^ 160;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_72[] = {0xDD, 0xDB, 0xDC, 0xCC};
static const char* j_dc_72(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_72[j_i] ^ 169;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_73[] = {0x83, 0x84, 0x89, 0x96, 0x80};
static const char* j_dc_73(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_73[j_i] ^ 229;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_74[] = {0x0A, 0x0C, 0x0B, 0x1B};
static const char* j_dc_74(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_74[j_i] ^ 126;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_75[] = {0xE9, 0xEE, 0xE3, 0xFC, 0xEA};
static const char* j_dc_75(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_75[j_i] ^ 143;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_76[] = {0x7C, 0x7A, 0x7D, 0x6D};
static const char* j_dc_76(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_76[j_i] ^ 8;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_77[] = {0x83, 0x84, 0x89, 0x96, 0x80};
static const char* j_dc_77(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_77[j_i] ^ 229;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_78[] = {0xA6, 0xA0, 0xA7, 0xB7};
static const char* j_dc_78(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_78[j_i] ^ 210;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_79[] = {0x8A, 0x8D, 0x80, 0x9F, 0x89};
static const char* j_dc_79(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_79[j_i] ^ 236;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_80[] = {0xFE, 0xF8, 0xFF, 0xEF};
static const char* j_dc_80(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_80[j_i] ^ 138;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_81[] = {0x76, 0x71, 0x7C, 0x63, 0x75};
static const char* j_dc_81(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_81[j_i] ^ 16;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_82[] = {0xEF, 0xE9, 0xEE, 0xFE};
static const char* j_dc_82(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_82[j_i] ^ 155;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_83[] = {0x30, 0x37, 0x3A, 0x25, 0x33};
static const char* j_dc_83(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_83[j_i] ^ 86;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_84[] = {0x1A, 0x1C, 0x1B, 0x0B};
static const char* j_dc_84(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_84[j_i] ^ 110;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_85[] = {0x7F, 0x78, 0x75, 0x6A, 0x7C};
static const char* j_dc_85(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_85[j_i] ^ 25;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_86[] = {0x6E, 0x6B, 0x7A, 0x63, 0x7B};
static const char* j_dc_86(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_86[j_i] ^ 15;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_87[] = {0x0A, 0x0C, 0x0B, 0x1B};
static const char* j_dc_87(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_87[j_i] ^ 126;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_88[] = {0xC5, 0xC2, 0xCF, 0xD0, 0xC6};
static const char* j_dc_88(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_88[j_i] ^ 163;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_89[] = {0x5A, 0x5C, 0x5B, 0x4B};
static const char* j_dc_89(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_89[j_i] ^ 46;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_90[] = {0xE7, 0xE0, 0xED, 0xF2, 0xE4};
static const char* j_dc_90(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_90[j_i] ^ 129;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_91[] = {0xFC, 0xFA, 0xFD, 0xED};
static const char* j_dc_91(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_91[j_i] ^ 136;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_92[] = {0x9B, 0x9C, 0x91, 0x8E, 0x98};
static const char* j_dc_92(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_92[j_i] ^ 253;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_93[] = {0xC8, 0xCE, 0xC9, 0xD9};
static const char* j_dc_93(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_93[j_i] ^ 188;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_94[] = {0xF3, 0xF4, 0xF9, 0xE6, 0xF0};
static const char* j_dc_94(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_94[j_i] ^ 149;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_95[] = {0xC5, 0xC1, 0xC6, 0xC7, 0xDA};
static const char* j_dc_95(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_95[j_i] ^ 168;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_96[] = {0x05, 0x03, 0x04, 0x14};
static const char* j_dc_96(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_96[j_i] ^ 113;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_97[] = {0xD3, 0xD4, 0xD9, 0xC6, 0xD0};
static const char* j_dc_97(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_97[j_i] ^ 181;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_98[] = {0x0E, 0x08, 0x0F, 0x1F};
static const char* j_dc_98(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_98[j_i] ^ 122;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_99[] = {0x56, 0x51, 0x5C, 0x43, 0x55};
static const char* j_dc_99(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_99[j_i] ^ 48;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_100[] = {0xC8, 0xCE, 0xC9, 0xD9};
static const char* j_dc_100(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_100[j_i] ^ 188;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_101[] = {0xED, 0xEA, 0xE7, 0xF8, 0xEE};
static const char* j_dc_101(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_101[j_i] ^ 139;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_102[] = {0x10, 0x10, 0x0D, 0x44, 0x43, 0x59, 0x48, 0x4A, 0x48, 0x5F, 0x5E, 0x0D, 0x10, 0x10};
static const char* j_dc_102(void) {
    static char j_rb[15];
    for (int j_i = 0; j_i < 14; j_i++) j_rb[j_i] = j_enc_102[j_i] ^ 45;
    j_rb[14] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_103[] = {0x5E, 0x5E, 0x43, 0x01, 0x0C, 0x0C, 0x0F, 0x06, 0x02, 0x0D, 0x10, 0x43, 0x5E, 0x5E};
static const char* j_dc_103(void) {
    static char j_rb[15];
    for (int j_i = 0; j_i < 14; j_i++) j_rb[j_i] = j_enc_103[j_i] ^ 99;
    j_rb[14] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_104[] = {0x8D, 0x8B, 0x8C, 0x9C};
static const char* j_dc_104(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_104[j_i] ^ 249;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_105[] = {0x51, 0x56, 0x5B, 0x44, 0x52};
static const char* j_dc_105(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_105[j_i] ^ 55;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_106[] = {0x8C, 0x8A, 0x8D, 0x9D};
static const char* j_dc_106(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_106[j_i] ^ 248;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_107[] = {0x02, 0x05, 0x08, 0x17, 0x01};
static const char* j_dc_107(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_107[j_i] ^ 100;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_108[] = {0x70, 0x70, 0x6D, 0x3E, 0x39, 0x3F, 0x24, 0x23, 0x2A, 0x3E, 0x6D, 0x70, 0x70};
static const char* j_dc_108(void) {
    static char j_rb[14];
    for (int j_i = 0; j_i < 13; j_i++) j_rb[j_i] = j_enc_108[j_i] ^ 77;
    j_rb[13] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_109[] = {0x43, 0x4E, 0x47, 0x47, 0x44, 0x07, 0x0B, 0x5C, 0x44, 0x59, 0x47, 0x4F};
static const char* j_dc_109(void) {
    static char j_rb[13];
    for (int j_i = 0; j_i < 12; j_i++) j_rb[j_i] = j_enc_109[j_i] ^ 43;
    j_rb[12] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_110[] = {0x38, 0x2E, 0x3E, 0x3C, 0x2D, 0x38, 0x39, 0x67, 0x7D, 0x01, 0x7D, 0x3F, 0x3C, 0x3E, 0x36, 0x2E, 0x31, 0x3C, 0x2E, 0x35, 0x71, 0x7D, 0x7F, 0x7D, 0x2C, 0x28, 0x32, 0x29, 0x38};
static const char* j_dc_110(void) {
    static char j_rb[30];
    for (int j_i = 0; j_i < 29; j_i++) j_rb[j_i] = j_enc_110[j_i] ^ 93;
    j_rb[29] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_111[] = {0x21, 0x24, 0x23, 0x28, 0x7C, 0x47, 0x21, 0x24, 0x23, 0x28, 0x7F};
static const char* j_dc_111(void) {
    static char j_rb[12];
    for (int j_i = 0; j_i < 11; j_i++) j_rb[j_i] = j_enc_111[j_i] ^ 77;
    j_rb[11] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_112[] = {0xEA, 0xEA, 0xF7, 0xA1, 0xB6, 0xA5, 0xBE, 0xB6, 0xB5, 0xBB, 0xB2, 0xA4, 0xF7, 0xEA, 0xEA};
static const char* j_dc_112(void) {
    static char j_rb[16];
    for (int j_i = 0; j_i < 15; j_i++) j_rb[j_i] = j_enc_112[j_i] ^ 215;
    j_rb[15] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_113[] = {0x86, 0x83, 0x8F, 0x87, 0x95};
static const char* j_dc_113(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_113[j_i] ^ 236;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_114[] = {0x04, 0x02, 0x05, 0x15};
static const char* j_dc_114(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_114[j_i] ^ 112;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_115[] = {0x7D, 0x7A, 0x77, 0x68, 0x7E};
static const char* j_dc_115(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_115[j_i] ^ 27;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_116[] = {0xDD, 0xDB, 0xDC, 0xCC};
static const char* j_dc_116(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_116[j_i] ^ 169;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_117[] = {0x9D, 0x9A, 0x97, 0x88, 0x9E};
static const char* j_dc_117(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_117[j_i] ^ 251;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_118[] = {0xB4, 0xB4, 0xA9, 0xE8, 0xFB, 0xE0, 0xFD, 0xE1, 0xE4, 0xEC, 0xFD, 0xE0, 0xEA, 0xA9, 0xB4, 0xB4};
static const char* j_dc_118(void) {
    static char j_rb[17];
    for (int j_i = 0; j_i < 16; j_i++) j_rb[j_i] = j_enc_118[j_i] ^ 137;
    j_rb[16] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_119[] = {0x31, 0x37, 0x30, 0x20};
static const char* j_dc_119(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_119[j_i] ^ 69;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_120[] = {0xB0, 0xB7, 0xBA, 0xA5, 0xB3};
static const char* j_dc_120(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_120[j_i] ^ 214;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_121[] = {0x86, 0x80, 0x87, 0x97};
static const char* j_dc_121(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_121[j_i] ^ 242;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_122[] = {0x94, 0x93, 0x9E, 0x81, 0x97};
static const char* j_dc_122(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_122[j_i] ^ 242;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_123[] = {0xB1, 0xB7, 0xB0, 0xA0};
static const char* j_dc_123(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_123[j_i] ^ 197;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_124[] = {0x46, 0x41, 0x4C, 0x53, 0x45};
static const char* j_dc_124(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_124[j_i] ^ 32;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_125[] = {0xCE, 0xCE, 0xD3, 0x90, 0x9C, 0x9E, 0x83, 0x92, 0x81, 0x9A, 0x80, 0x9C, 0x9D, 0x80, 0xD3, 0xCE, 0xCE};
static const char* j_dc_125(void) {
    static char j_rb[18];
    for (int j_i = 0; j_i < 17; j_i++) j_rb[j_i] = j_enc_125[j_i] ^ 243;
    j_rb[17] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_126[] = {0x9D, 0x9B, 0x9C, 0x8C};
static const char* j_dc_126(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_126[j_i] ^ 233;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_127[] = {0x7A, 0x7D, 0x70, 0x6F, 0x79};
static const char* j_dc_127(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_127[j_i] ^ 28;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_128[] = {0x01, 0x07, 0x00, 0x10};
static const char* j_dc_128(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_128[j_i] ^ 117;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_129[] = {0x91, 0x96, 0x9B, 0x84, 0x92};
static const char* j_dc_129(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_129[j_i] ^ 247;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_130[] = {0x24, 0x22, 0x25, 0x35};
static const char* j_dc_130(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_130[j_i] ^ 80;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_131[] = {0x99, 0x9E, 0x93, 0x8C, 0x9A};
static const char* j_dc_131(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_131[j_i] ^ 255;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_132[] = {0xED, 0xEB, 0xEC, 0xFC};
static const char* j_dc_132(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_132[j_i] ^ 153;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_133[] = {0x60, 0x67, 0x6A, 0x75, 0x63};
static const char* j_dc_133(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_133[j_i] ^ 6;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_134[] = {0xB1, 0xB7, 0xB0, 0xA0};
static const char* j_dc_134(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_134[j_i] ^ 197;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_135[] = {0x2B, 0x2C, 0x21, 0x3E, 0x28};
static const char* j_dc_135(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_135[j_i] ^ 77;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_136[] = {0xE3, 0xE5, 0xE2, 0xF2};
static const char* j_dc_136(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_136[j_i] ^ 151;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_137[] = {0xD8, 0xDF, 0xD2, 0xCD, 0xDB};
static const char* j_dc_137(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_137[j_i] ^ 190;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_138[] = {0x7C, 0x7C, 0x61, 0x2D, 0x2E, 0x26, 0x28, 0x22, 0x61, 0x7C, 0x7C};
static const char* j_dc_138(void) {
    static char j_rb[12];
    for (int j_i = 0; j_i < 11; j_i++) j_rb[j_i] = j_enc_138[j_i] ^ 65;
    j_rb[11] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_139[] = {0xA8, 0xAE, 0xA9, 0xB9};
static const char* j_dc_139(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_139[j_i] ^ 220;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_140[] = {0x86, 0x81, 0x8C, 0x93, 0x85};
static const char* j_dc_140(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_140[j_i] ^ 224;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_141[] = {0x48, 0x4E, 0x49, 0x59};
static const char* j_dc_141(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_141[j_i] ^ 60;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_142[] = {0x51, 0x56, 0x5B, 0x44, 0x52};
static const char* j_dc_142(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_142[j_i] ^ 55;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_143[] = {0x90, 0x96, 0x91, 0x81};
static const char* j_dc_143(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_143[j_i] ^ 228;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_144[] = {0x6E, 0x69, 0x64, 0x7B, 0x6D};
static const char* j_dc_144(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_144[j_i] ^ 8;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_145[] = {0xD3, 0xD5, 0xD2, 0xC2};
static const char* j_dc_145(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_145[j_i] ^ 167;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_146[] = {0x86, 0x81, 0x8C, 0x93, 0x85};
static const char* j_dc_146(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_146[j_i] ^ 224;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_147[] = {0x1E, 0x18, 0x1F, 0x0F};
static const char* j_dc_147(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_147[j_i] ^ 106;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_148[] = {0x38, 0x3F, 0x32, 0x2D, 0x3B};
static const char* j_dc_148(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_148[j_i] ^ 94;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_149[] = {0x23, 0x23, 0x3E, 0x6D, 0x6A, 0x6C, 0x77, 0x70, 0x79, 0x3E, 0x71, 0x6E, 0x7B, 0x6C, 0x7F, 0x6A, 0x77, 0x71, 0x70, 0x6D, 0x3E, 0x23, 0x23};
static const char* j_dc_149(void) {
    static char j_rb[24];
    for (int j_i = 0; j_i < 23; j_i++) j_rb[j_i] = j_enc_149[j_i] ^ 30;
    j_rb[23] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_150[] = {0xE8, 0xED, 0xE1, 0xE9, 0xFB};
static const char* j_dc_150(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_150[j_i] ^ 162;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_151[] = {0x69, 0x6C, 0x60, 0x68, 0x7A};
static const char* j_dc_151(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_151[j_i] ^ 35;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_152[] = {0x2F, 0x29, 0x2E, 0x3E};
static const char* j_dc_152(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_152[j_i] ^ 91;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_153[] = {0x43, 0x44, 0x49, 0x56, 0x40};
static const char* j_dc_153(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_153[j_i] ^ 37;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_154[] = {0x94, 0x91, 0x9D, 0x95, 0x87};
static const char* j_dc_154(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_154[j_i] ^ 254;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_155[] = {0xEE, 0xE8, 0xEF, 0xFF};
static const char* j_dc_155(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_155[j_i] ^ 154;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_156[] = {0xAB, 0xAC, 0xA1, 0xBE, 0xA8};
static const char* j_dc_156(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_156[j_i] ^ 205;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_157[] = {0x73, 0x76, 0x7A, 0x72, 0x60};
static const char* j_dc_157(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_157[j_i] ^ 57;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_158[] = {0xFD, 0xFB, 0xFC, 0xEC};
static const char* j_dc_158(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_158[j_i] ^ 137;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_159[] = {0xFA, 0xFD, 0xF0, 0xEF, 0xF9};
static const char* j_dc_159(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_159[j_i] ^ 156;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_160[] = {0xAC, 0xAC, 0xB1, 0xF8, 0xF7, 0xB1, 0xBE, 0xB1, 0xF4, 0xFD, 0xE2, 0xF4, 0xB1, 0xAC, 0xAC};
static const char* j_dc_160(void) {
    static char j_rb[16];
    for (int j_i = 0; j_i < 15; j_i++) j_rb[j_i] = j_enc_160[j_i] ^ 145;
    j_rb[15] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_161[] = {0xB8, 0xAB, 0xB8, 0xB3};
static const char* j_dc_161(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_161[j_i] ^ 221;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_162[] = {0x93, 0x98, 0x98};
static const char* j_dc_162(void) {
    static char j_rb[4];
    for (int j_i = 0; j_i < 3; j_i++) j_rb[j_i] = j_enc_162[j_i] ^ 252;
    j_rb[3] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_163[] = {0x8F, 0x84, 0x8A};
static const char* j_dc_163(void) {
    static char j_rb[4];
    for (int j_i = 0; j_i < 3; j_i++) j_rb[j_i] = j_enc_163[j_i] ^ 237;
    j_rb[3] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_164[] = {0x8E, 0x89, 0x9B, 0x8A, 0x9D, 0xCF, 0x86, 0x89};
static const char* j_dc_164(void) {
    static char j_rb[9];
    for (int j_i = 0; j_i < 8; j_i++) j_rb[j_i] = j_enc_164[j_i] ^ 239;
    j_rb[8] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_165[] = {0xB8, 0xB8, 0xA5, 0xF2, 0xED, 0xEC, 0xE9, 0xE0, 0xA5, 0xB8, 0xB8};
static const char* j_dc_165(void) {
    static char j_rb[12];
    for (int j_i = 0; j_i < 11; j_i++) j_rb[j_i] = j_enc_165[j_i] ^ 133;
    j_rb[11] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_166[] = {0xC1, 0xC1, 0xDC, 0x9A, 0x93, 0x8E, 0xDC, 0xC1, 0xC1};
static const char* j_dc_166(void) {
    static char j_rb[10];
    for (int j_i = 0; j_i < 9; j_i++) j_rb[j_i] = j_enc_166[j_i] ^ 252;
    j_rb[9] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_167[] = {0x7C, 0x7C, 0x61, 0x20, 0x32, 0x32, 0x28, 0x26, 0x2F, 0x2C, 0x24, 0x2F, 0x35, 0x61, 0x7C, 0x7C};
static const char* j_dc_167(void) {
    static char j_rb[17];
    for (int j_i = 0; j_i < 16; j_i++) j_rb[j_i] = j_enc_167[j_i] ^ 65;
    j_rb[16] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_168[] = {0x94, 0x94, 0x89, 0xDA, 0xC1, 0xC8, 0xCD, 0xC6, 0xDE, 0xC0, 0xC7, 0xCE, 0x89, 0x94, 0x94};
static const char* j_dc_168(void) {
    static char j_rb[16];
    for (int j_i = 0; j_i < 15; j_i++) j_rb[j_i] = j_enc_168[j_i] ^ 169;
    j_rb[15] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_169[] = {0xD2, 0xD2, 0xCF, 0x89, 0x9A, 0x81, 0x8C, 0x9B, 0x86, 0x80, 0x81, 0x9C, 0xCF, 0xD2, 0xD2};
static const char* j_dc_169(void) {
    static char j_rb[16];
    for (int j_i = 0; j_i < 15; j_i++) j_rb[j_i] = j_enc_169[j_i] ^ 239;
    j_rb[15] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_170[] = {0x71, 0x7C, 0x75, 0x75, 0x76, 0x39, 0x7F, 0x6B, 0x76, 0x74, 0x39, 0x78, 0x39, 0x6F, 0x76, 0x70, 0x7D, 0x39, 0x7F, 0x6C, 0x77, 0x7A, 0x6D, 0x70, 0x76, 0x77};
static const char* j_dc_170(void) {
    static char j_rb[27];
    for (int j_i = 0; j_i < 26; j_i++) j_rb[j_i] = j_enc_170[j_i] ^ 25;
    j_rb[26] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_171[] = {0x82, 0xA7, 0xA2};
static const char* j_dc_171(void) {
    static char j_rb[4];
    for (int j_i = 0; j_i < 3; j_i++) j_rb[j_i] = j_enc_171[j_i] ^ 195;
    j_rb[3] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_172[] = {0x70, 0x70, 0x6D, 0x20, 0x38, 0x39, 0x38, 0x2C, 0x21, 0x6D, 0x3F, 0x28, 0x2E, 0x38, 0x3F, 0x3E, 0x24, 0x22, 0x23, 0x6D, 0x70, 0x70};
static const char* j_dc_172(void) {
    static char j_rb[23];
    for (int j_i = 0; j_i < 22; j_i++) j_rb[j_i] = j_enc_172[j_i] ^ 77;
    j_rb[22] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_173[] = {0x36, 0x30, 0x37, 0x27};
static const char* j_dc_173(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_173[j_i] ^ 66;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_174[] = {0xE0, 0xE7, 0xEA, 0xF5, 0xE3};
static const char* j_dc_174(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_174[j_i] ^ 134;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_175[] = {0x35, 0x33, 0x34, 0x24};
static const char* j_dc_175(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_175[j_i] ^ 65;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_176[] = {0x13, 0x14, 0x19, 0x06, 0x10};
static const char* j_dc_176(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_176[j_i] ^ 117;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_177[] = {0x6C, 0x6A, 0x6D, 0x7D};
static const char* j_dc_177(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_177[j_i] ^ 24;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_178[] = {0x26, 0x21, 0x2C, 0x33, 0x25};
static const char* j_dc_178(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_178[j_i] ^ 64;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_179[] = {0xB8, 0xB8, 0xA5, 0xE6, 0xEA, 0xE8, 0xF5, 0xEA, 0xF6, 0xEC, 0xF1, 0xEC, 0xEA, 0xEB, 0xA5, 0xB8, 0xB8};
static const char* j_dc_179(void) {
    static char j_rb[18];
    for (int j_i = 0; j_i < 17; j_i++) j_rb[j_i] = j_enc_179[j_i] ^ 133;
    j_rb[17] = 0;
    return j_rb;
}

static int32_t j_str_len(const char* s) { return (int32_t)strlen(s); }
static bool j_str_eq(const char* a, const char* b) { return strcmp(a, b) == 0; }

static char j_buf[65536];
#define J_BUF_CAP (sizeof j_buf)

static void j_json_escape(char* out, size_t cap, const char* s) {
    size_t o = 0;
    for (const char* p = s; *p && o + 8 < cap; ++p) {
        unsigned char c = (unsigned char)*p;
        switch (c) {
            case '"': out[o++] = '\\'; out[o++] = '"'; break;
            case '\\': out[o++] = '\\'; out[o++] = '\\'; break;
            case '\n': out[o++] = '\\'; out[o++] = 'n'; break;
            case '\r': out[o++] = '\\'; out[o++] = 'r'; break;
            case '\t': out[o++] = '\\'; out[o++] = 't'; break;
            default:
                if (c < 0x20) {
                    out[o++] = '\\'; out[o++] = 'u'; out[o++] = '0'; out[o++] = '0';
                    out[o++] = j_dc_0()[c >> 4];
                    out[o++] = j_dc_1()[c & 15];
                } else out[o++] = (char)c;
        }
    }
    out[o] = '\0';
}

static const char* j_sys_now(void) {
    time_t t = time(NULL);
#if defined(_WIN32)
    struct tm* tmv = localtime(&t);
    strftime(j_buf, J_BUF_CAP, "%Y-%m-%dT%H:%M:%S", tmv);
#else
    struct tm tmv;
    localtime_r(&t, &tmv);
    strftime(j_buf, J_BUF_CAP, "%Y-%m-%dT%H:%M:%S", &tmv);
#endif
    return j_buf;
}

static void j_sys_sleep(int32_t ms) {
#if defined(_WIN32)
    Sleep((DWORD)ms);
#else
    struct timespec ts;
    ts.tv_sec = ms / 1000;
    ts.tv_nsec = (long)(ms % 1000) * 1000000L;
    nanosleep(&ts, NULL);
#endif
}

static const char* j_sys_cwd(void) {
#if defined(_WIN32)
    _getcwd(j_buf, (int)J_BUF_CAP);
#else
    getcwd(j_buf, J_BUF_CAP);
#endif
    return j_buf;
}

static const char* j_env_get(const char* name) {
    const char* v = getenv(name);
    return v ? v : "";
}

static bool j_fs_exists(const char* path) {
#if defined(_WIN32)
    return GetFileAttributesA(path) != INVALID_FILE_ATTRIBUTES;
#else
    return access(path, F_OK) == 0;
#endif
}

static const char* j_fs_read(const char* path) {
    FILE* f = fopen(path, j_dc_2());
    if (!f) return "";
    size_t n = fread(j_buf, 1, J_BUF_CAP - 1, f);
    fclose(f);
    j_buf[n] = '\0';
    return j_buf;
}

static void j_fs_write(const char* path, const char* data) {
    FILE* f = fopen(path, j_dc_3());
    if (f) { fputs(data, f); fclose(f); }
}

static const char* j_fs_list(const char* dir) {
    size_t off = 0;
    j_buf[off++] = '[';
    int first = 1;
#if defined(_WIN32)
    char pattern[1024];
    snprintf(pattern, sizeof pattern, "%s\\*", dir);
    WIN32_FIND_DATAA fd;
    HANDLE h = FindFirstFileA(pattern, &fd);
    if (h != INVALID_HANDLE_VALUE) {
        do {
            if (fd.cFileName[0] == '.') continue;
            if (off > J_BUF_CAP - 200) break;
            if (!first) j_buf[off++] = ',';
            first = 0;
            char esc[1024];
            j_json_escape(esc, sizeof esc, fd.cFileName);
            int n = snprintf(j_buf + off, J_BUF_CAP - off, "\"%s\"", esc);
            off += (size_t)(n > 0 ? n : 0);
        } while (FindNextFileA(h, &fd));
        FindClose(h);
    }
#else
    DIR* d = opendir(dir);
    if (d) {
        struct dirent* de;
        while ((de = readdir(d)) != NULL) {
            if (de->d_name[0] == '.') continue;
            if (off > J_BUF_CAP - 200) break;
            if (!first) j_buf[off++] = ',';
            first = 0;
            char esc[1024];
            j_json_escape(esc, sizeof esc, de->d_name);
            int n = snprintf(j_buf + off, J_BUF_CAP - off, "\"%s\"", esc);
            off += (size_t)(n > 0 ? n : 0);
        }
        closedir(d);
    }
#endif
    j_buf[off++] = ']';
    j_buf[off] = '\0';
    return j_buf;
}

static const char* j_sys_process_list(void) {
    size_t off = 0;
    j_buf[off++] = '[';
    int first = 1;
#if defined(_WIN32)
    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snap != INVALID_HANDLE_VALUE) {
        PROCESSENTRY32W pe;
        pe.dwSize = sizeof pe;
        if (Process32FirstW(snap, &pe)) {
            do {
                if (off > J_BUF_CAP - 400) break;
                char name[1024];
                size_t k = 0;
                for (size_t i = 0; pe.szExeFile[i] && k + 1 < sizeof name; ++i)
                    name[k++] = (char)(pe.szExeFile[i] & 0xFF);
                name[k] = '\0';
                if (!first) j_buf[off++] = ',';
                first = 0;
                char esc[2048];
                j_json_escape(esc, sizeof esc, name);
                int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"pid\":%lu,\"name\":\"%s\"}", (unsigned long)pe.th32ProcessID, esc);
                off += (size_t)(n > 0 ? n : 0);
            } while (Process32NextW(snap, &pe));
        }
        CloseHandle(snap);
    }
#elif defined(__APPLE__)
    int all_pids[8192];
    int np = proc_listallpids(all_pids, sizeof all_pids);
    for (int i = 0; i < np; ++i) {
        int pid = all_pids[i];
        if (off > J_BUF_CAP - 400) break;
        char name[256];
        int len = proc_name(pid, name, sizeof name);
        if (len <= 0) snprintf(name, sizeof name, "pid_%d", pid);
        if (!first) j_buf[off++] = ',';
        first = 0;
        char esc[512];
        j_json_escape(esc, sizeof esc, name);
        int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"pid\":%d,\"name\":\"%s\"}", pid, esc);
        off += (size_t)(n > 0 ? n : 0);
    }
#else
    DIR* d = opendir(j_dc_4());
    if (d) {
        struct dirent* de;
        while ((de = readdir(d)) != NULL) {
            if (de->d_name[0] < '0' || de->d_name[0] > '9') continue;
            int pid = atoi(de->d_name);
            char p[64], name[256];
            snprintf(p, sizeof p, "/proc/%d/comm", pid);
            FILE* f = fopen(p, j_dc_5());
            if (f) {
                if (fgets(name, sizeof name, f)) name[strcspn(name, j_dc_6())] = '\0';
                fclose(f);
                if (off > J_BUF_CAP - 400) break;
                if (!first) j_buf[off++] = ',';
                first = 0;
                char esc[512];
                j_json_escape(esc, sizeof esc, name);
                int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"pid\":%d,\"name\":\"%s\"}", pid, esc);
                off += (size_t)(n > 0 ? n : 0);
            }
        }
        closedir(d);
    }
#endif
    j_buf[off++] = ']';
    j_buf[off] = '\0';
    return j_buf;
}

static void j_net_proc_parse(const char* path, size_t* off, int* first) {
    FILE* f = fopen(path, j_dc_7());
    if (!f) return;
    char line[512];
    int skip = 1;
    while (fgets(line, sizeof line, f)) {
        if (skip) { skip = 0; continue; }
        char laddr[64], raddr[64], st[16];
        if (sscanf(line, "%*s %63s %63s %15s", laddr, raddr, st) != 3) continue;
        if (*off > J_BUF_CAP - 300) break;
        if (!*first) j_buf[(*off)++] = ',';
        *first = 0;
        int n = snprintf(j_buf + *off, J_BUF_CAP - *off, "{\"local\":\"%s\",\"remote\":\"%s\",\"state\":\"%s\"}", laddr, raddr, st);
        *off += (size_t)(n > 0 ? n : 0);
    }
    fclose(f);
}

static const char* j_net_sockets(void) {
    size_t off = 0;
    j_buf[off++] = '[';
    int first = 1;
#if defined(_WIN32)
    ULONG sz = 0;
    GetExtendedTcpTable(NULL, &sz, FALSE, AF_INET, TCP_TABLE_OWNER_PID_ALL, 0);
    char* t = (char*)malloc(sz ? sz : 1);
    if (t) {
        MIB_TCPTABLE_OWNER_PID* tab = (MIB_TCPTABLE_OWNER_PID*)t;
        if (GetExtendedTcpTable(tab, &sz, FALSE, AF_INET, TCP_TABLE_OWNER_PID_ALL, 0) == NO_ERROR) {
            for (DWORD i = 0; i < tab->dwNumEntries; ++i) {
                MIB_TCPROW_OWNER_PID* r = &tab->table[i];
                char li[64], ri[64];
                snprintf(li, sizeof li, "%s:%u", inet_ntoa(*(struct in_addr*)&r->dwLocalAddr), (unsigned)ntohs((u_short)r->dwLocalPort));
                snprintf(ri, sizeof ri, "%s:%u", inet_ntoa(*(struct in_addr*)&r->dwRemoteAddr), (unsigned)ntohs((u_short)r->dwRemotePort));
                const char* state = j_dc_8();
                switch (r->dwState) {
                    case 2:  state = j_dc_9(); break;
                    case 5:  state = j_dc_10(); break;
                    case 8:  state = j_dc_11(); break;
                    case 11: state = j_dc_12(); break;
                    default: state = j_dc_13(); break;
                }
                if (off > J_BUF_CAP - 300) break;
                if (!first) j_buf[off++] = ',';
                first = 0;
                int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"local\":\"%s\",\"remote\":\"%s\",\"state\":\"%s\"}", li, ri, state);
                off += (size_t)(n > 0 ? n : 0);
            }
        }
        free(t);
    }
#elif defined(__APPLE__)
    FILE* ns = popen(j_dc_14(), j_dc_15());
    if (ns) {
        char line[512];
        while (fgets(line, sizeof line, ns)) {
            char proto[8], laddr[64], raddr[64], st[32];
            if (sscanf(line, "%7s %*s %*s %63s %63s %31s", proto, laddr, raddr, st) == 4) {
                if (strncmp(proto, j_dc_16(), 3) != 0) continue;
                if (off > J_BUF_CAP - 300) break;
                if (!first) j_buf[off++] = ',';
                first = 0;
                int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"local\":\"%s\",\"remote\":\"%s\",\"state\":\"%s\"}", laddr, raddr, st);
                off += (size_t)(n > 0 ? n : 0);
            }
        }
        pclose(ns);
    }
#else
    j_net_proc_parse(j_dc_17(), &off, &first);
    j_net_proc_parse(j_dc_18(), &off, &first);
#endif
    j_buf[off++] = ']';
    j_buf[off] = '\0';
    return j_buf;
}

static const char* j_reg_list(const char* key) {
    size_t off = 0;
    j_buf[off++] = '[';
    int first = 1;
#if defined(_WIN32)
    HKEY root = HKEY_LOCAL_MACHINE;
    const char* sub = key;
    if (strncmp(key, j_dc_19(), 5) == 0) { root = HKEY_LOCAL_MACHINE; sub = key + 5; }
    else if (strncmp(key, j_dc_20(), 5) == 0) { root = HKEY_CURRENT_USER; sub = key + 5; }
    else if (strncmp(key, j_dc_21(), 5) == 0) { root = HKEY_CLASSES_ROOT; sub = key + 5; }
    else if (strncmp(key, j_dc_22(), 4) == 0) { root = HKEY_USERS; sub = key + 4; }
    HKEY hk = NULL;
    if (RegOpenKeyExA(root, sub, 0, KEY_READ, &hk) == ERROR_SUCCESS) {
        for (DWORD i = 0; ; ++i) {
            char s[256];
            DWORD n = sizeof s;
            if (RegEnumKeyExA(hk, i, s, &n, NULL, NULL, NULL, NULL) != ERROR_SUCCESS) break;
            if (off > J_BUF_CAP - 400) break;
            if (!first) j_buf[off++] = ',';
            first = 0;
            char esc[512];
            j_json_escape(esc, sizeof esc, s);
            int n2 = snprintf(j_buf + off, J_BUF_CAP - off, "\"%s\"", esc);
            off += (size_t)(n2 > 0 ? n2 : 0);
        }
        RegCloseKey(hk);
    }
#else
    (void)key;
#endif
    j_buf[off++] = ']';
    j_buf[off] = '\0';
    return j_buf;
}

static void j_mem_dump(int32_t pid, const char* path) {
#if defined(_WIN32)
    HANDLE h = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, (DWORD)pid);
    if (!h) return;
    FILE* out = fopen(path, j_dc_23());
    if (!out) { CloseHandle(h); return; }
    unsigned char* base = NULL;
    MEMORY_BASIC_INFORMATION mbi;
    unsigned long regions = 0;
    while (VirtualQueryEx(h, base, &mbi, sizeof mbi) == sizeof mbi && regions++ < 100000) {
        if (mbi.State == MEM_COMMIT && !(mbi.Protect & (PAGE_GUARD | PAGE_NOACCESS)) &&
            (mbi.Protect == PAGE_READWRITE || mbi.Protect == PAGE_READONLY ||
             mbi.Protect == PAGE_EXECUTE_READWRITE || mbi.Protect == PAGE_EXECUTE_READ)) {
            unsigned char* chunk = (unsigned char*)malloc(mbi.RegionSize ? mbi.RegionSize : 1);
            SIZE_T read = 0;
            if (chunk && ReadProcessMemory(h, mbi.BaseAddress, chunk, mbi.RegionSize, &read) && read) {
                fwrite(chunk, 1, read, out);
            }
            free(chunk);
        }
        base = (unsigned char*)mbi.BaseAddress + mbi.RegionSize;
    }
    fclose(out);
    CloseHandle(h);
#else
    (void)pid; (void)path;
#endif
}

static volatile int32_t j_h652w1jw = 59026;
static volatile int32_t j_rhq5zfgl = 64358;

static int32_t j_1gg4zy7k(int32_t j_vuw7p4af);
static int32_t j_r7dcnie5(int32_t j_v61ud416, int32_t j_braojhvw);
static void j_9cxtij2d(const char* j_03irshy4);
static int32_t j_0yag5obe(int32_t j_q906qbti);
static int32_t j_3fkui2i8(int32_t j_q906qbti);
static bool j_487n9rjp(int32_t j_q906qbti);
static bool j_rzt0awj4(int32_t j_q906qbti);
static const char* j_zmezz654(const char* j_elg32nx1, int32_t j_0y6g1n65);

static int32_t j_1gg4zy7k(int32_t j_vuw7p4af)
{
    int32_t j_azbz09tc = 0;
    while ((j_azbz09tc != -1))
    {
        switch (j_azbz09tc)
        {
            case 0:
                static volatile int64_t j_sj29oxhz = 1675;
                if ((((j_sj29oxhz * j_sj29oxhz) + j_sj29oxhz) >= 0))
                {
                }
                else
                {
                    (void)printf("%s\n", 0 ? j_dc_24() : j_dc_25());
                }
                j_azbz09tc = 1;
                break;
            case 1:
                static volatile int64_t j_5ug1d6wt = 91605;
                if ((((j_5ug1d6wt * j_5ug1d6wt) + j_5ug1d6wt) < 0))
                {
                    volatile int64_t j_armn7lt1 = ((j_5ug1d6wt * 26) + 605);
                    (void)printf("%s\n", 0 ? j_dc_26() : j_dc_27());
                }
                j_azbz09tc = 2;
                break;
            case 2:
                static volatile int64_t j_s290tspo = 95564;
                static volatile int64_t j_q3v0kszc = 26785;
                if ((((j_q3v0kszc * j_q3v0kszc) + j_q3v0kszc) < 0))
                {
                    volatile int64_t j_52itf1cb = ((j_q3v0kszc * 62) + 785);
                    (void)printf("%s\n", 0 ? j_dc_28() : j_dc_29());
                }
                j_azbz09tc = 3;
                break;
            case 3:
                if ((((j_s290tspo * j_s290tspo) + j_s290tspo) < 0))
                {
                    (void)printf("%s\n", 0 ? j_dc_30() : j_dc_31());
                }
                j_azbz09tc = 4;
                break;
            case 4:
                return (j_vuw7p4af * 2);
                break;
            case 5:
                static volatile int64_t j_5pveza24 = 33917;
                if ((((j_5pveza24 * j_5pveza24) + j_5pveza24) < 0))
                {
                    volatile int64_t j_c0s7icbl = ((j_5pveza24 * 58) + 917);
                    (void)printf("%s\n", 0 ? j_dc_32() : j_dc_33());
                }
                j_azbz09tc = 6;
                break;
            case 6:
                static volatile int64_t j_mb4hg3n0 = 87685;
                if ((((j_mb4hg3n0 * j_mb4hg3n0) + j_mb4hg3n0) < 0))
                {
                    volatile int64_t j_bcdpe9pk = ((j_mb4hg3n0 * 73) + 685);
                    (void)printf("%s\n", 0 ? j_dc_34() : j_dc_35());
                }
                j_azbz09tc = -1;
                break;
            default:
                break;
        }
    }
    return 0;
}

static int32_t j_r7dcnie5(int32_t j_v61ud416, int32_t j_braojhvw)
{
    int32_t j_myk70g1l = 0;
    while ((j_myk70g1l != -1))
    {
        switch (j_myk70g1l)
        {
            case 0:
                static volatile int64_t j_izx0t6up = 29751;
                if ((((j_izx0t6up * j_izx0t6up) + j_izx0t6up) < 0))
                {
                    (void)printf("%s\n", 0 ? j_dc_36() : j_dc_37());
                }
                j_myk70g1l = 1;
                break;
            case 1:
                return (j_v61ud416 + j_braojhvw);
                break;
            case 2:
                static volatile int64_t j_xe5mwy7c = 92333;
                static volatile int64_t j_wzoz3acc = 11413;
                static volatile int64_t j_xvhe3dow = 12039;
                if ((((j_xvhe3dow * j_xvhe3dow) + j_xvhe3dow) < 0))
                {
                    volatile int64_t j_bc7j5prq = ((j_xvhe3dow * 54) + 39);
                    (void)printf("%s\n", 0 ? j_dc_38() : j_dc_39());
                }
                j_myk70g1l = 3;
                break;
            case 3:
                if ((((j_wzoz3acc * j_wzoz3acc) + j_wzoz3acc) >= 0))
                {
                }
                else
                {
                    (void)printf("%s\n", 0 ? j_dc_40() : j_dc_41());
                }
                j_myk70g1l = 4;
                break;
            case 4:
                if ((((j_xe5mwy7c * j_xe5mwy7c) + j_xe5mwy7c) >= 0))
                {
                }
                else
                {
                    (void)printf("%s\n", 0 ? j_dc_42() : j_dc_43());
                }
                j_myk70g1l = -1;
                break;
            default:
                break;
        }
    }
    return 0;
}

static void j_9cxtij2d(const char* j_03irshy4)
{
    int32_t j_xw6laelx = 0;
    while ((j_xw6laelx != -1))
    {
        switch (j_xw6laelx)
        {
            case 0:
                static volatile int64_t j_q3wjo41b = 85795;
                if ((((j_q3wjo41b * j_q3wjo41b) + j_q3wjo41b) >= 0))
                {
                }
                else
                {
                    (void)printf("%s\n", 0 ? j_dc_44() : j_dc_45());
                }
                j_xw6laelx = 1;
                break;
            case 1:
                static volatile int64_t j_ue63jahe = 71285;
                if ((((j_ue63jahe * j_ue63jahe) + j_ue63jahe) < 0))
                {
                    volatile int64_t j_adjm9rcj = ((j_ue63jahe * 37) + 285);
                    (void)printf("%s\n", 0 ? j_dc_46() : j_dc_47());
                }
                j_xw6laelx = 2;
                break;
            case 2:
                (void)printf("%s\n", j_03irshy4);
                j_xw6laelx = -1;
                break;
            default:
                break;
        }
    }
}

static int32_t j_0yag5obe(int32_t j_q906qbti)
{
    int32_t j_5ecj60ym = 0;
    while ((j_5ecj60ym != -1))
    {
        switch (j_5ecj60ym)
        {
            case 0:
                if ((j_q906qbti <= 1))
                {
                    return 1;
                }
                j_5ecj60ym = 1;
                break;
            case 1:
                static volatile int64_t j_2zrufqur = 88980;
                static volatile int64_t j_3jug6i77 = 74417;
                static volatile int64_t j_a9uzoy92 = 66786;
                if ((((j_a9uzoy92 * j_a9uzoy92) + j_a9uzoy92) < 0))
                {
                    volatile int64_t j_ut19no8y = ((j_a9uzoy92 * 99) + 786);
                    (void)printf("%s\n", 0 ? j_dc_48() : j_dc_49());
                }
                j_5ecj60ym = 2;
                break;
            case 2:
                if ((((j_3jug6i77 * j_3jug6i77) + j_3jug6i77) < 0))
                {
                    volatile int64_t j_jnmr5ieb = ((j_3jug6i77 * 55) + 417);
                    (void)printf("%s\n", 0 ? j_dc_50() : j_dc_51());
                }
                j_5ecj60ym = 3;
                break;
            case 3:
                if ((((j_2zrufqur * j_2zrufqur) + j_2zrufqur) < 0))
                {
                    (void)printf("%s\n", 0 ? j_dc_52() : j_dc_53());
                }
                j_5ecj60ym = 4;
                break;
            case 4:
                return (j_q906qbti * j_0yag5obe((j_q906qbti - 1)));
                break;
            case 5:
                static volatile int64_t j_crqdq2hd = 51029;
                if ((((j_crqdq2hd * j_crqdq2hd) + j_crqdq2hd) < 0))
                {
                    (void)printf("%s\n", 0 ? j_dc_54() : j_dc_55());
                }
                j_5ecj60ym = -1;
                break;
            default:
                break;
        }
    }
    return 0;
}

static int32_t j_3fkui2i8(int32_t j_q906qbti)
{
    int32_t j_fyaf86gp = 0;
    while ((j_fyaf86gp != -1))
    {
        switch (j_fyaf86gp)
        {
            case 0:
                if ((j_q906qbti < 2))
                {
                    return j_q906qbti;
                }
                j_fyaf86gp = 1;
                break;
            case 1:
                static volatile int64_t j_dcg0dy56 = 61651;
                if ((((j_dcg0dy56 * (j_dcg0dy56 + 1)) % 2) == 1))
                {
                    (void)printf("%s\n", 0 ? j_dc_56() : j_dc_57());
                }
                j_fyaf86gp = 2;
                break;
            case 2:
                static volatile int64_t j_1r505rue = 7417;
                if ((((j_1r505rue * j_1r505rue) + j_1r505rue) < 0))
                {
                    (void)printf("%s\n", 0 ? j_dc_58() : j_dc_59());
                }
                j_fyaf86gp = 3;
                break;
            case 3:
                static volatile int64_t j_lyfub232 = 3851;
                if ((((j_lyfub232 * j_lyfub232) + j_lyfub232) < 0))
                {
                    volatile int64_t j_pptheq8s = ((j_lyfub232 * 98) + 851);
                    (void)printf("%s\n", 0 ? j_dc_60() : j_dc_61());
                }
                j_fyaf86gp = 4;
                break;
            case 4:
                return (j_3fkui2i8((j_q906qbti - 1)) + j_3fkui2i8((j_q906qbti - 2)));
                break;
            default:
                break;
        }
    }
    return 0;
}

static bool j_487n9rjp(int32_t j_q906qbti)
{
    int32_t j_dstq2aem = 0;
    while ((j_dstq2aem != -1))
    {
        switch (j_dstq2aem)
        {
            case 0:
                static volatile int64_t j_rsl1yluz = 64504;
                if ((((j_rsl1yluz * j_rsl1yluz) + j_rsl1yluz) < 0))
                {
                    volatile int64_t j_b9asq5kx = ((j_rsl1yluz * 52) + 504);
                    (void)printf("%s\n", 0 ? j_dc_62() : j_dc_63());
                }
                j_dstq2aem = 1;
                break;
            case 1:
                if ((j_q906qbti == 0))
                {
                    return true;
                }
                j_dstq2aem = 2;
                break;
            case 2:
                static volatile int64_t j_kv7lqn3m = 17762;
                static volatile int64_t j_acn9es3c = 34358;
                if ((((j_acn9es3c * j_acn9es3c) + j_acn9es3c) < 0))
                {
                    volatile int64_t j_wilzcbf2 = ((j_acn9es3c * 87) + 358);
                    (void)printf("%s\n", 0 ? j_dc_64() : j_dc_65());
                }
                j_dstq2aem = 3;
                break;
            case 3:
                if ((((j_kv7lqn3m * j_kv7lqn3m) + j_kv7lqn3m) < 0))
                {
                    (void)printf("%s\n", 0 ? j_dc_66() : j_dc_67());
                }
                j_dstq2aem = 4;
                break;
            case 4:
                static volatile int64_t j_45a0mvub = 25029;
                if ((((j_45a0mvub * j_45a0mvub) + j_45a0mvub) < 0))
                {
                    volatile int64_t j_ql6kfjr5 = ((j_45a0mvub * 35) + 29);
                    (void)printf("%s\n", 0 ? j_dc_68() : j_dc_69());
                }
                j_dstq2aem = 5;
                break;
            case 5:
                static volatile int64_t j_dj2cpbs8 = 26514;
                if ((((j_dj2cpbs8 * j_dj2cpbs8) + j_dj2cpbs8) >= 0))
                {
                }
                else
                {
                    (void)printf("%s\n", 0 ? j_dc_70() : j_dc_71());
                }
                j_dstq2aem = 6;
                break;
            case 6:
                return j_rzt0awj4((j_q906qbti - 1));
                break;
            default:
                break;
        }
    }
    return 0;
}

static bool j_rzt0awj4(int32_t j_q906qbti)
{
    int32_t j_7fgjr93h = 0;
    while ((j_7fgjr93h != -1))
    {
        switch (j_7fgjr93h)
        {
            case 0:
                static volatile int64_t j_ycp0bqwk = 48552;
                static volatile int64_t j_cc9231iz = 88627;
                static volatile int64_t j_xxjxtk3x = 65830;
                static volatile int64_t j_hdm4nmw9 = 87447;
                if ((((j_hdm4nmw9 * j_hdm4nmw9) + j_hdm4nmw9) < 0))
                {
                    volatile int64_t j_eqkvgs16 = ((j_hdm4nmw9 * 80) + 447);
                    (void)printf("%s\n", 0 ? j_dc_72() : j_dc_73());
                }
                j_7fgjr93h = 1;
                break;
            case 1:
                if ((((j_xxjxtk3x * j_xxjxtk3x) + j_xxjxtk3x) < 0))
                {
                    volatile int64_t j_a60zat2h = ((j_xxjxtk3x * 25) + 830);
                    (void)printf("%s\n", 0 ? j_dc_74() : j_dc_75());
                }
                j_7fgjr93h = 2;
                break;
            case 2:
                static volatile int64_t j_x7enfq45 = 54965;
                if ((((j_x7enfq45 * j_x7enfq45) + j_x7enfq45) < 0))
                {
                    volatile int64_t j_nzmf4tnm = ((j_x7enfq45 * 44) + 965);
                    (void)printf("%s\n", 0 ? j_dc_76() : j_dc_77());
                }
                j_7fgjr93h = 3;
                break;
            case 3:
                if ((((j_cc9231iz * j_cc9231iz) + j_cc9231iz) < 0))
                {
                    (void)printf("%s\n", 0 ? j_dc_78() : j_dc_79());
                }
                j_7fgjr93h = 4;
                break;
            case 4:
                if ((((j_ycp0bqwk * j_ycp0bqwk) % 4) == 3))
                {
                    (void)printf("%s\n", 0 ? j_dc_80() : j_dc_81());
                }
                j_7fgjr93h = 5;
                break;
            case 5:
                if ((j_q906qbti == 0))
                {
                    return false;
                }
                j_7fgjr93h = 6;
                break;
            case 6:
                return j_487n9rjp((j_q906qbti - 1));
                break;
            case 7:
                static volatile int64_t j_gb90dsa1 = 62431;
                if ((((j_gb90dsa1 * j_gb90dsa1) + j_gb90dsa1) < 0))
                {
                    volatile int64_t j_7wqluzjg = ((j_gb90dsa1 * 70) + 431);
                    (void)printf("%s\n", 0 ? j_dc_82() : j_dc_83());
                }
                j_7fgjr93h = 8;
                break;
            case 8:
                static volatile int64_t j_s764yx2c = 26297;
                if ((((j_s764yx2c * j_s764yx2c) % 4) < 2))
                {
                }
                else
                {
                    (void)printf("%s\n", 0 ? j_dc_84() : j_dc_85());
                }
                j_7fgjr93h = -1;
                break;
            default:
                break;
        }
    }
    return 0;
}

static const char* j_zmezz654(const char* j_elg32nx1, int32_t j_0y6g1n65)
{
    int32_t j_448a8ko8 = 0;
    while ((j_448a8ko8 != -1))
    {
        switch (j_448a8ko8)
        {
            case 0:
                if ((j_0y6g1n65 >= 18))
                {
                    return j_dc_86();
                }
                j_448a8ko8 = 1;
                break;
            case 1:
                static volatile int64_t j_q8btyjso = 76429;
                if ((((j_q8btyjso * j_q8btyjso) + j_q8btyjso) < 0))
                {
                    volatile int64_t j_qezw3k2l = ((j_q8btyjso * 47) + 429);
                    (void)printf("%s\n", 0 ? j_dc_87() : j_dc_88());
                }
                j_448a8ko8 = 2;
                break;
            case 2:
                static volatile int64_t j_6rhfc336 = 60558;
                if ((((j_6rhfc336 * j_6rhfc336) + j_6rhfc336) < 0))
                {
                    volatile int64_t j_xzepwns9 = ((j_6rhfc336 * 14) + 558);
                    (void)printf("%s\n", 0 ? j_dc_89() : j_dc_90());
                }
                j_448a8ko8 = 3;
                break;
            case 3:
                static volatile int64_t j_krkebsji = 25747;
                if ((((j_krkebsji * j_krkebsji) + j_krkebsji) >= 0))
                {
                }
                else
                {
                    (void)printf("%s\n", 0 ? j_dc_91() : j_dc_92());
                }
                j_448a8ko8 = 4;
                break;
            case 4:
                static volatile int64_t j_20vqo097 = 70347;
                if ((((j_20vqo097 * j_20vqo097) + j_20vqo097) < 0))
                {
                    volatile int64_t j_zd1n47us = ((j_20vqo097 * 81) + 347);
                    (void)printf("%s\n", 0 ? j_dc_93() : j_dc_94());
                }
                j_448a8ko8 = 5;
                break;
            case 5:
                return j_dc_95();
                break;
            case 6:
                static volatile int64_t j_pj4w74s4 = 6381;
                static volatile int64_t j_30qvhth5 = 71685;
                static volatile int64_t j_xmp45ldy = 39721;
                if ((((j_xmp45ldy * j_xmp45ldy) + j_xmp45ldy) < 0))
                {
                    volatile int64_t j_agw3fqh5 = ((j_xmp45ldy * 52) + 721);
                    (void)printf("%s\n", 0 ? j_dc_96() : j_dc_97());
                }
                j_448a8ko8 = 7;
                break;
            case 7:
                if ((((j_30qvhth5 * j_30qvhth5) % 4) < 2))
                {
                }
                else
                {
                    (void)printf("%s\n", 0 ? j_dc_98() : j_dc_99());
                }
                j_448a8ko8 = 8;
                break;
            case 8:
                if ((((j_pj4w74s4 * j_pj4w74s4) + j_pj4w74s4) >= 0))
                {
                }
                else
                {
                    (void)printf("%s\n", 0 ? j_dc_100() : j_dc_101());
                }
                j_448a8ko8 = -1;
                break;
            default:
                break;
        }
    }
    return 0;
}

int32_t main(void)
{
    int32_t j_zuosqjyf = 0;
    while ((j_zuosqjyf != -1))
    {
        switch (j_zuosqjyf)
        {
            case 0:
                (void)printf("%s\n", j_dc_102());
                (void)printf("%d\n", 0);
                (void)printf("%d\n", 42);
                (void)printf("%d\n", -(17));
                static volatile int64_t j_lziyzu56 = 30479;
                if ((((j_lziyzu56 * j_lziyzu56) + j_lziyzu56) >= 0))
                {
                    (void)printf("%d\n", 1000000);
                }
                else
                {
                    volatile int64_t j_89l82esg = ((j_lziyzu56 * 2) + 1);
                }
                j_zuosqjyf = 1;
                break;
            case 1:
                (void)printf("%s\n", j_dc_103());
                (void)printf("%s\n", true ? j_dc_104() : j_dc_105());
                (void)printf("%s\n", false ? j_dc_106() : j_dc_107());
                (void)printf("%s\n", j_dc_108());
                (void)printf("%s\n", j_dc_109());
                (void)printf("%s\n", "");
                static volatile int64_t j_h5dziqo1 = 69373;
                if ((((j_h5dziqo1 * j_h5dziqo1) + j_h5dziqo1) >= 0))
                {
                    (void)printf("%s\n", j_dc_110());
                }
                else
                {
                    volatile int64_t j_kalk7t2b = ((j_h5dziqo1 * 2) + 1);
                }
                j_zuosqjyf = 2;
                break;
            case 2:
                (void)printf("%s\n", j_dc_111());
                static volatile int64_t j_tzbkwacx = 22245;
                if ((((j_tzbkwacx * j_tzbkwacx) + j_tzbkwacx) >= 0))
                {
                    (void)printf("%s\n", j_dc_112());
                }
                else
                {
                    volatile int64_t j_rryrpo72 = ((j_tzbkwacx * 2) + 1);
                }
                j_zuosqjyf = 3;
                break;
            case 3:
                int32_t j_60c6t7vv = 10;
                int32_t j_8ubbcwox = 20;
                (void)printf("%d\n", j_60c6t7vv);
                (void)printf("%d\n", j_8ubbcwox);
                const char* j_03irshy4 = j_dc_113();
                bool j_mhxmer1e = true;
                (void)printf("%s\n", j_03irshy4);
                static volatile int64_t j_kmhci3w3 = 71591;
                if ((((j_kmhci3w3 * j_kmhci3w3) + j_kmhci3w3) >= 0))
                {
                    (void)printf("%s\n", j_mhxmer1e ? j_dc_114() : j_dc_115());
                }
                else
                {
                    volatile int64_t j_wud4h6wb = ((j_kmhci3w3 * 2) + 1);
                }
                j_zuosqjyf = 4;
                break;
            case 4:
                static volatile int64_t j_8frmjcm4 = 98119;
                if ((((j_8frmjcm4 * j_8frmjcm4) + j_8frmjcm4) >= 0))
                {
                    j_mhxmer1e = false;
                }
                else
                {
                    volatile int64_t j_8u98zlyn = ((j_8frmjcm4 * 2) + 1);
                }
                j_zuosqjyf = 5;
                break;
            case 5:
                static volatile int64_t j_9xp1uu9s = 37781;
                if ((((j_9xp1uu9s * j_9xp1uu9s) + j_9xp1uu9s) >= 0))
                {
                    (void)printf("%s\n", j_mhxmer1e ? j_dc_116() : j_dc_117());
                }
                else
                {
                    volatile int64_t j_scjqppva = ((j_9xp1uu9s * 2) + 1);
                }
                j_zuosqjyf = 6;
                break;
            case 6:
                (void)printf("%s\n", j_dc_118());
                static volatile int64_t j_lv6vgy6j = 54881;
                static volatile int64_t j_0hyrbpis = 72747;
                if ((((j_0hyrbpis * j_0hyrbpis) + j_0hyrbpis) < 0))
                {
                    volatile int64_t j_45aprccr = ((j_0hyrbpis * 55) + 747);
                    (void)printf("%s\n", 0 ? j_dc_119() : j_dc_120());
                }
                j_zuosqjyf = 7;
                break;
            case 7:
                if ((((j_lv6vgy6j * (j_lv6vgy6j + 1)) % 2) == 0))
                {
                }
                else
                {
                    (void)printf("%s\n", 0 ? j_dc_121() : j_dc_122());
                }
                j_zuosqjyf = 8;
                break;
            case 8:
                static volatile int64_t j_een4ydf9 = 19557;
                if ((((j_een4ydf9 * j_een4ydf9) + j_een4ydf9) < 0))
                {
                    volatile int64_t j_n723uwi9 = ((j_een4ydf9 * 61) + 557);
                    (void)printf("%s\n", 0 ? j_dc_123() : j_dc_124());
                }
                j_zuosqjyf = 9;
                break;
            case 9:
                (void)printf("%d\n", (2 + (3 * 4)));
                static volatile int64_t j_5g5tfbwq = 67452;
                if ((((j_5g5tfbwq * j_5g5tfbwq) + j_5g5tfbwq) >= 0))
                {
                    (void)printf("%d\n", ((2 + 3) * 4));
                }
                else
                {
                    volatile int64_t j_eeaoqv88 = ((j_5g5tfbwq * 2) + 1);
                }
                j_zuosqjyf = 10;
                break;
            case 10:
                static volatile int64_t j_bc2xfye4 = 47448;
                if ((((j_bc2xfye4 * j_bc2xfye4) + j_bc2xfye4) >= 0))
                {
                    (void)printf("%d\n", ((10 - 3) - 2));
                }
                else
                {
                    volatile int64_t j_yhs5wtil = ((j_bc2xfye4 * 2) + 1);
                }
                j_zuosqjyf = 11;
                break;
            case 11:
                (void)printf("%d\n", (100 / 7));
                (void)printf("%d\n", (100 % 7));
                (void)printf("%d\n", -((3 + 4)));
                (void)printf("%d\n", ((7 / 2) * 2));
                static volatile int64_t j_yaib4te9 = 33437;
                if ((((j_yaib4te9 * j_yaib4te9) + j_yaib4te9) >= 0))
                {
                    (void)printf("%d\n", (1 + ((2 * 3) % 4)));
                }
                else
                {
                    volatile int64_t j_qrp75fq0 = ((j_yaib4te9 * 2) + 1);
                }
                j_zuosqjyf = 12;
                break;
            case 12:
                (void)printf("%s\n", j_dc_125());
                static volatile int64_t j_dk8omte1 = 74791;
                if ((((j_dk8omte1 * j_dk8omte1) + j_dk8omte1) >= 0))
                {
                    (void)printf("%s\n", (1 == 1) ? j_dc_126() : j_dc_127());
                }
                else
                {
                    volatile int64_t j_idjpr52v = ((j_dk8omte1 * 2) + 1);
                }
                j_zuosqjyf = 13;
                break;
            case 13:
                (void)printf("%s\n", (1 != 2) ? j_dc_128() : j_dc_129());
                static volatile int64_t j_3jc0f1gf = 35484;
                if ((((j_3jc0f1gf * j_3jc0f1gf) + j_3jc0f1gf) >= 0))
                {
                    (void)printf("%s\n", (3 < 5) ? j_dc_130() : j_dc_131());
                }
                else
                {
                    volatile int64_t j_13o7v2rx = ((j_3jc0f1gf * 2) + 1);
                }
                j_zuosqjyf = 14;
                break;
            case 14:
                (void)printf("%s\n", (5 <= 5) ? j_dc_132() : j_dc_133());
                (void)printf("%s\n", (4 > 9) ? j_dc_134() : j_dc_135());
                (void)printf("%s\n", (9 >= 10) ? j_dc_136() : j_dc_137());
                (void)printf("%s\n", j_dc_138());
                (void)printf("%s\n", (true && true) ? j_dc_139() : j_dc_140());
                (void)printf("%s\n", (true && false) ? j_dc_141() : j_dc_142());
                static volatile int64_t j_phctvr82 = 33434;
                if ((((j_phctvr82 * j_phctvr82) + j_phctvr82) >= 0))
                {
                    (void)printf("%s\n", (false || true) ? j_dc_143() : j_dc_144());
                }
                else
                {
                    volatile int64_t j_aidfd00s = ((j_phctvr82 * 2) + 1);
                }
                j_zuosqjyf = 15;
                break;
            case 15:
                static volatile int64_t j_v6n879ql = 69575;
                if ((((j_v6n879ql * j_v6n879ql) + j_v6n879ql) >= 0))
                {
                    (void)printf("%s\n", !(true) ? j_dc_145() : j_dc_146());
                }
                else
                {
                    volatile int64_t j_gt2q4905 = ((j_v6n879ql * 2) + 1);
                }
                j_zuosqjyf = 16;
                break;
            case 16:
                (void)printf("%s\n", !(!(true)) ? j_dc_147() : j_dc_148());
                (void)printf("%s\n", j_dc_149());
                const char* j_ehkpx8ro = j_dc_150();
                (void)printf("%d\n", j_str_len(j_ehkpx8ro));
                (void)printf("%d\n", j_str_len(""));
                (void)printf("%s\n", j_str_eq(j_ehkpx8ro, j_dc_151()) ? j_dc_152() : j_dc_153());
                (void)printf("%s\n", j_str_eq(j_ehkpx8ro, j_dc_154()) ? j_dc_155() : j_dc_156());
                (void)printf("%s\n", !j_str_eq(j_ehkpx8ro, j_dc_157()) ? j_dc_158() : j_dc_159());
                static volatile int64_t j_hm2pswux = 83430;
                if ((((j_hm2pswux * j_hm2pswux) + j_hm2pswux) >= 0))
                {
                    (void)printf("%s\n", j_dc_160());
                }
                else
                {
                    volatile int64_t j_lqkh4c8h = ((j_hm2pswux * 2) + 1);
                }
                j_zuosqjyf = 17;
                break;
            case 17:
                int32_t j_q906qbti = 7;
                if (((j_q906qbti % 2) == 0))
                {
                    (void)printf("%s\n", j_dc_161());
                }
                else
                {
                    (void)printf("%s\n", j_dc_162());
                }
                j_zuosqjyf = 18;
                break;
            case 18:
                if ((j_q906qbti > 10))
                {
                    (void)printf("%s\n", j_dc_163());
                }
                j_zuosqjyf = 19;
                break;
            case 19:
                static volatile int64_t j_mwk6rj7l = 13004;
                if ((((j_mwk6rj7l * j_mwk6rj7l) + j_mwk6rj7l) >= 0))
                {
                    (void)printf("%s\n", j_dc_164());
                }
                else
                {
                    volatile int64_t j_dq4pnd44 = ((j_mwk6rj7l * 2) + 1);
                }
                j_zuosqjyf = 20;
                break;
            case 20:
                static volatile int64_t j_0o55tqdl = 64069;
                if ((((j_0o55tqdl * j_0o55tqdl) + j_0o55tqdl) >= 0))
                {
                    (void)printf("%s\n", j_dc_165());
                }
                else
                {
                    volatile int64_t j_1din73mx = ((j_0o55tqdl * 2) + 1);
                }
                j_zuosqjyf = 21;
                break;
            case 21:
                int32_t j_49eo3tu3 = 0;
                while ((j_49eo3tu3 < 3))
                {
                    (void)printf("%d\n", j_49eo3tu3);
                    j_49eo3tu3 = (j_49eo3tu3 + 1);
                }
                j_zuosqjyf = 22;
                break;
            case 22:
                (void)printf("%s\n", j_dc_166());
                for (int32_t j_nawvynuv = 0; (j_nawvynuv < 4); j_nawvynuv = (j_nawvynuv + 1))
                {
                    (void)printf("%d\n", j_nawvynuv);
                }
                j_zuosqjyf = 23;
                break;
            case 23:
                static volatile int64_t j_hk02vts0 = 32786;
                if ((((j_hk02vts0 * j_hk02vts0) + j_hk02vts0) >= 0))
                {
                    (void)printf("%s\n", j_dc_167());
                }
                else
                {
                    volatile int64_t j_dyg4ysgd = ((j_hk02vts0 * 2) + 1);
                }
                j_zuosqjyf = 24;
                break;
            case 24:
                int32_t j_vuw7p4af = 0;
                int32_t j_t88h552s = j_vuw7p4af = 5;
                static volatile int64_t j_dbvts15r = 41285;
                if ((((j_dbvts15r * j_dbvts15r) + j_dbvts15r) >= 0))
                {
                    (void)printf("%d\n", j_vuw7p4af);
                }
                else
                {
                    volatile int64_t j_gv1m22n1 = ((j_dbvts15r * 2) + 1);
                }
                j_zuosqjyf = 25;
                break;
            case 25:
                (void)printf("%d\n", j_t88h552s);
                static volatile int64_t j_xher4o8t = 71860;
                if ((((j_xher4o8t * j_xher4o8t) + j_xher4o8t) >= 0))
                {
                    (void)printf("%s\n", j_dc_168());
                }
                else
                {
                    volatile int64_t j_ejusn88r = ((j_xher4o8t * 2) + 1);
                }
                j_zuosqjyf = 26;
                break;
            case 26:
                int32_t j_tmzqj8p3 = 1;
                if (true)
                {
                    int32_t j_tmzqj8p3 = 2;
                    (void)printf("%d\n", j_tmzqj8p3);
                }
                j_zuosqjyf = 27;
                break;
            case 27:
                (void)printf("%d\n", j_tmzqj8p3);
                (void)printf("%s\n", j_dc_169());
                (void)printf("%d\n", j_1gg4zy7k(21));
                (void)printf("%d\n", j_r7dcnie5(2, 3));
                (void)j_9cxtij2d(j_dc_170());
                (void)printf("%d\n", j_0yag5obe(5));
                static volatile int64_t j_sfok4bjs = 80079;
                if ((((j_sfok4bjs * j_sfok4bjs) + j_sfok4bjs) >= 0))
                {
                    (void)printf("%d\n", j_3fkui2i8(10));
                }
                else
                {
                    volatile int64_t j_4syq8c2d = ((j_sfok4bjs * 2) + 1);
                }
                j_zuosqjyf = 28;
                break;
            case 28:
                (void)printf("%s\n", j_zmezz654(j_dc_171(), 21));
                (void)printf("%s\n", j_dc_172());
                (void)printf("%s\n", j_487n9rjp(10) ? j_dc_173() : j_dc_174());
                (void)printf("%s\n", j_rzt0awj4(10) ? j_dc_175() : j_dc_176());
                static volatile int64_t j_62bbodto = 54376;
                if ((((j_62bbodto * j_62bbodto) + j_62bbodto) >= 0))
                {
                    (void)printf("%s\n", j_487n9rjp(7) ? j_dc_177() : j_dc_178());
                }
                else
                {
                    volatile int64_t j_43v0jyt8 = ((j_62bbodto * 2) + 1);
                }
                j_zuosqjyf = 29;
                break;
            case 29:
                static volatile int64_t j_2vxbybkw = 41964;
                if ((((j_2vxbybkw * j_2vxbybkw) + j_2vxbybkw) >= 0))
                {
                    (void)printf("%s\n", j_dc_179());
                }
                else
                {
                    volatile int64_t j_1saze6rj = ((j_2vxbybkw * 2) + 1);
                }
                j_zuosqjyf = 30;
                break;
            case 30:
                (void)printf("%d\n", j_1gg4zy7k(j_1gg4zy7k(2)));
                (void)printf("%d\n", j_0yag5obe(j_3fkui2i8(5)));
                j_zuosqjyf = -1;
                break;
            default:
                break;
        }
    }
    return 0;
}
