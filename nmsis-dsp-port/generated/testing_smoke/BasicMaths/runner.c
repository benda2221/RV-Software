#include <stdint.h>
#include <stdio.h>
#include "dsp/basic_math_functions.h"

#define ARRAY_SIZE(a) ((uint32_t)(sizeof(a) / sizeof((a)[0])))

static volatile q63_t smoke_sink;

static const q7_t q7_input1[] = {
    (q7_t)0x52u,    (q7_t)0x01u,    (q7_t)0x47u,    (q7_t)0x20u,
    (q7_t)0xA5u,    (q7_t)0xFDu,    (q7_t)0xFCu,    (q7_t)0x44u,
    (q7_t)0xF5u,    (q7_t)0xCBu,    (q7_t)0x2Au,    (q7_t)0xE7u,
    (q7_t)0x1Eu,    (q7_t)0x28u,    (q7_t)0xFFu,    (q7_t)0xEFu,
    (q7_t)0x3Eu,    (q7_t)0x2Cu,    (q7_t)0x05u,    (q7_t)0x32u,
    (q7_t)0xAEu,    (q7_t)0x09u,    (q7_t)0xBEu,    (q7_t)0xF5u,
    (q7_t)0x24u,    (q7_t)0xFAu,    (q7_t)0xDEu,    (q7_t)0xD6u,
    (q7_t)0xF4u,    (q7_t)0xE7u,    (q7_t)0x0Du,    (q7_t)0xD7u,
    (q7_t)0x10u,    (q7_t)0x19u,    (q7_t)0x0Cu,    (q7_t)0xC8u,
    (q7_t)0xBBu,    (q7_t)0x1Eu,    (q7_t)0x05u,    (q7_t)0xAAu,
    (q7_t)0x44u,    (q7_t)0x60u,    (q7_t)0x2Du,    (q7_t)0x21u,
    (q7_t)0x1Cu,    (q7_t)0xF0u,    (q7_t)0x2Eu,    (q7_t)0x25u,
    (q7_t)0xF4u,    (q7_t)0xF1u,    (q7_t)0xC7u,    (q7_t)0x19u,
    (q7_t)0x26u,    (q7_t)0xBBu,    (q7_t)0xD0u,    (q7_t)0x08u,
    (q7_t)0x46u,    (q7_t)0xF9u,    (q7_t)0xEFu,    (q7_t)0x7Eu,
    (q7_t)0x19u,    (q7_t)0x1Eu,    (q7_t)0x1Bu,    (q7_t)0x0Au,
    (q7_t)0x1Fu,    (q7_t)0x22u,    (q7_t)0x12u,    (q7_t)0x10u,
    (q7_t)0x13u,    (q7_t)0x05u,    (q7_t)0x41u,    (q7_t)0x0Fu,
    (q7_t)0x3Bu,    (q7_t)0xF6u,    (q7_t)0xF9u,    (q7_t)0x45u,
    (q7_t)0xE5u,    (q7_t)0xE4u,    (q7_t)0x14u,    (q7_t)0xCDu,
    (q7_t)0xE5u,    (q7_t)0xEDu,    (q7_t)0xF3u,    (q7_t)0x14u,
    (q7_t)0x00u,    (q7_t)0xEFu,    (q7_t)0xEEu,    (q7_t)0xDAu,
    (q7_t)0x19u,    (q7_t)0x12u,    (q7_t)0xB4u,    (q7_t)0x0Bu,
    (q7_t)0xABu,    (q7_t)0x14u,    (q7_t)0x0Au,    (q7_t)0xF7u,
    (q7_t)0x15u,    (q7_t)0x35u,    (q7_t)0x38u,    (q7_t)0x0Cu,
    (q7_t)0xCAu,    (q7_t)0x32u,    (q7_t)0x02u,    (q7_t)0xD9u,
    (q7_t)0x1Fu,    (q7_t)0x00u,    (q7_t)0xB9u,    (q7_t)0x5Cu,
    (q7_t)0xE4u,    (q7_t)0x39u,    (q7_t)0xE0u,    (q7_t)0xE6u,
    (q7_t)0x09u,    (q7_t)0xADu,    (q7_t)0x0Eu,    (q7_t)0x30u,
    (q7_t)0x24u,    (q7_t)0xAEu,    (q7_t)0xF5u,    (q7_t)0x02u,
    (q7_t)0x1Eu,    (q7_t)0xE5u,    (q7_t)0x1Du,    (q7_t)0xE0u,
    (q7_t)0xC0u,    (q7_t)0x16u,    (q7_t)0xEBu,    (q7_t)0x35u,
    (q7_t)0xAAu,    (q7_t)0x30u,    (q7_t)0xF4u,    (q7_t)0x95u,
    (q7_t)0xFBu,    (q7_t)0xFBu,    (q7_t)0xD4u,    (q7_t)0x17u,
    (q7_t)0x36u,    (q7_t)0xF5u,    (q7_t)0x26u,    (q7_t)0x00u,
    (q7_t)0x59u,    (q7_t)0xDDu,    (q7_t)0x47u,    (q7_t)0xC5u,
    (q7_t)0xE0u,    (q7_t)0x86u,    (q7_t)0xCAu,    (q7_t)0x26u,
    (q7_t)0x3Bu,    (q7_t)0xC8u,    (q7_t)0x36u,    (q7_t)0x31u,
    (q7_t)0xD0u,    (q7_t)0xADu,    (q7_t)0x05u,    (q7_t)0x19u,
    (q7_t)0x07u,    (q7_t)0xF4u,    (q7_t)0xBEu,    (q7_t)0xEDu,
    (q7_t)0xC9u,    (q7_t)0xD3u,    (q7_t)0x17u,    (q7_t)0xC0u,
    (q7_t)0x0Du,    (q7_t)0xDEu,    (q7_t)0xCFu,    (q7_t)0xDAu,
    (q7_t)0x66u,    (q7_t)0x95u,    (q7_t)0xE2u,    (q7_t)0xE4u,
    (q7_t)0x00u,    (q7_t)0x10u,    (q7_t)0xECu,    (q7_t)0xB8u,
    (q7_t)0xD5u,    (q7_t)0x27u,    (q7_t)0x0Bu,    (q7_t)0xDDu,
    (q7_t)0x13u,    (q7_t)0x85u,    (q7_t)0xD3u,    (q7_t)0xDFu,
    (q7_t)0xCDu,    (q7_t)0xD0u,    (q7_t)0x36u,    (q7_t)0x3Au,
    (q7_t)0xFCu,    (q7_t)0xDBu,    (q7_t)0x2Bu,    (q7_t)0xE0u,
    (q7_t)0x21u,    (q7_t)0xDBu,    (q7_t)0xE0u,    (q7_t)0x1Fu,
    (q7_t)0x64u,    (q7_t)0xF0u,    (q7_t)0x8Fu,    (q7_t)0x0Eu,
    (q7_t)0x45u,    (q7_t)0xE1u,    (q7_t)0x39u,    (q7_t)0x80u,
    (q7_t)0xBBu,    (q7_t)0xF6u,    (q7_t)0xC8u,    (q7_t)0x42u,
    (q7_t)0x02u,    (q7_t)0x38u,    (q7_t)0x16u,    (q7_t)0x62u,
    (q7_t)0xE2u,    (q7_t)0x3Bu,    (q7_t)0xFDu,    (q7_t)0xE4u,
    (q7_t)0xF6u,    (q7_t)0x91u,    (q7_t)0x15u,    (q7_t)0xF0u,
    (q7_t)0xABu,    (q7_t)0x6Au,    (q7_t)0x16u,    (q7_t)0x0Eu,
    (q7_t)0xF3u,    (q7_t)0xC4u,    (q7_t)0xE7u,    (q7_t)0x0Eu,
    (q7_t)0xAAu,    (q7_t)0x34u,    (q7_t)0x1Du,    (q7_t)0x13u,
    (q7_t)0x44u,    (q7_t)0xE8u,    (q7_t)0xF2u,    (q7_t)0xEFu,
    (q7_t)0x2Eu,    (q7_t)0x22u,    (q7_t)0x44u,    (q7_t)0x41u,
    (q7_t)0x2Cu,    (q7_t)0x2Eu,    (q7_t)0x74u,    (q7_t)0x02u,
    (q7_t)0x16u,    (q7_t)0x06u,    (q7_t)0xEAu,    (q7_t)0x45u,
    (q7_t)0xCBu,    (q7_t)0xDEu,    (q7_t)0xE5u,    (q7_t)0xF3u,
    (q7_t)0x0Fu,    (q7_t)0xDEu,    (q7_t)0x35u,    (q7_t)0x09u,
};

static const q7_t q7_input2[] = {
    (q7_t)0x1Eu,    (q7_t)0xDEu,    (q7_t)0x10u,    (q7_t)0xF2u,
    (q7_t)0x91u,    (q7_t)0xDCu,    (q7_t)0x37u,    (q7_t)0x02u,
    (q7_t)0xDEu,    (q7_t)0x08u,    (q7_t)0x28u,    (q7_t)0xC3u,
    (q7_t)0x00u,    (q7_t)0xFDu,    (q7_t)0x14u,    (q7_t)0x14u,
    (q7_t)0xFCu,    (q7_t)0x1Eu,    (q7_t)0x25u,    (q7_t)0xF2u,
    (q7_t)0xECu,    (q7_t)0xD7u,    (q7_t)0x5Bu,    (q7_t)0x66u,
    (q7_t)0xF2u,    (q7_t)0x93u,    (q7_t)0xF2u,    (q7_t)0x11u,
    (q7_t)0x35u,    (q7_t)0x2Au,    (q7_t)0xEEu,    (q7_t)0xFEu,
    (q7_t)0xE7u,    (q7_t)0xE2u,    (q7_t)0x27u,    (q7_t)0xEDu,
    (q7_t)0xDFu,    (q7_t)0x02u,    (q7_t)0x41u,    (q7_t)0xC1u,
    (q7_t)0xEDu,    (q7_t)0x1Cu,    (q7_t)0xD8u,    (q7_t)0x0Du,
    (q7_t)0x2Du,    (q7_t)0xE7u,    (q7_t)0xEAu,    (q7_t)0xD6u,
    (q7_t)0xD3u,    (q7_t)0x44u,    (q7_t)0xB5u,    (q7_t)0x63u,
    (q7_t)0x12u,    (q7_t)0x2Du,    (q7_t)0xF1u,    (q7_t)0x1Cu,
    (q7_t)0xDCu,    (q7_t)0xD8u,    (q7_t)0xD8u,    (q7_t)0xD4u,
    (q7_t)0x05u,    (q7_t)0xEBu,    (q7_t)0x04u,    (q7_t)0x48u,
    (q7_t)0xC6u,    (q7_t)0xE1u,    (q7_t)0x01u,    (q7_t)0x30u,
    (q7_t)0x1Du,    (q7_t)0x01u,    (q7_t)0xEAu,    (q7_t)0x17u,
    (q7_t)0xE0u,    (q7_t)0xB4u,    (q7_t)0x1Du,    (q7_t)0xFDu,
    (q7_t)0xBBu,    (q7_t)0xF3u,    (q7_t)0xC1u,    (q7_t)0x2Cu,
    (q7_t)0x2Bu,    (q7_t)0xE0u,    (q7_t)0x95u,    (q7_t)0xD4u,
    (q7_t)0x0Au,    (q7_t)0xEAu,    (q7_t)0x07u,    (q7_t)0xFFu,
    (q7_t)0x2Fu,    (q7_t)0x04u,    (q7_t)0x17u,    (q7_t)0xF7u,
    (q7_t)0x02u,    (q7_t)0x09u,    (q7_t)0x22u,    (q7_t)0xE6u,
    (q7_t)0x0Au,    (q7_t)0xCEu,    (q7_t)0x36u,    (q7_t)0x35u,
    (q7_t)0xF1u,    (q7_t)0x33u,    (q7_t)0x01u,    (q7_t)0x27u,
    (q7_t)0x96u,    (q7_t)0xCCu,    (q7_t)0xEBu,    (q7_t)0xBCu,
    (q7_t)0x1Cu,    (q7_t)0x30u,    (q7_t)0x9Bu,    (q7_t)0xC8u,
    (q7_t)0x09u,    (q7_t)0xD4u,    (q7_t)0x07u,    (q7_t)0x25u,
    (q7_t)0x00u,    (q7_t)0x2Fu,    (q7_t)0x3Au,    (q7_t)0xF3u,
    (q7_t)0x0Fu,    (q7_t)0x2Au,    (q7_t)0xF6u,    (q7_t)0x2Bu,
    (q7_t)0xEEu,    (q7_t)0xE9u,    (q7_t)0xE1u,    (q7_t)0xE3u,
    (q7_t)0x01u,    (q7_t)0x0Du,    (q7_t)0x1Du,    (q7_t)0x0Fu,
    (q7_t)0x40u,    (q7_t)0x0Au,    (q7_t)0x01u,    (q7_t)0x12u,
    (q7_t)0x39u,    (q7_t)0x2Fu,    (q7_t)0x2Fu,    (q7_t)0x0Cu,
    (q7_t)0xE7u,    (q7_t)0x08u,    (q7_t)0x09u,    (q7_t)0xE9u,
    (q7_t)0xB8u,    (q7_t)0xEDu,    (q7_t)0x93u,    (q7_t)0xFDu,
    (q7_t)0x21u,    (q7_t)0xEDu,    (q7_t)0xE5u,    (q7_t)0xCFu,
    (q7_t)0x65u,    (q7_t)0xE3u,    (q7_t)0x16u,    (q7_t)0xECu,
    (q7_t)0xB9u,    (q7_t)0x02u,    (q7_t)0xFAu,    (q7_t)0x3Au,
    (q7_t)0x13u,    (q7_t)0x14u,    (q7_t)0x27u,    (q7_t)0x2Au,
    (q7_t)0xE4u,    (q7_t)0x32u,    (q7_t)0xE1u,    (q7_t)0xF0u,
    (q7_t)0xEFu,    (q7_t)0x51u,    (q7_t)0x0Eu,    (q7_t)0x4Bu,
    (q7_t)0x18u,    (q7_t)0xF2u,    (q7_t)0xB6u,    (q7_t)0x18u,
    (q7_t)0x16u,    (q7_t)0xF2u,    (q7_t)0xFAu,    (q7_t)0x0Au,
    (q7_t)0xFEu,    (q7_t)0x14u,    (q7_t)0x84u,    (q7_t)0x1Bu,
    (q7_t)0x03u,    (q7_t)0x05u,    (q7_t)0xDCu,    (q7_t)0xD9u,
    (q7_t)0x50u,    (q7_t)0xF2u,    (q7_t)0x1Fu,    (q7_t)0xF1u,
    (q7_t)0x34u,    (q7_t)0x7Bu,    (q7_t)0x0Cu,    (q7_t)0x02u,
    (q7_t)0xCCu,    (q7_t)0x2Du,    (q7_t)0xFCu,    (q7_t)0xBEu,
    (q7_t)0x27u,    (q7_t)0x0Eu,    (q7_t)0x1Au,    (q7_t)0xFAu,
    (q7_t)0xD8u,    (q7_t)0xFAu,    (q7_t)0x14u,    (q7_t)0x49u,
    (q7_t)0xC0u,    (q7_t)0x24u,    (q7_t)0x05u,    (q7_t)0x18u,
    (q7_t)0xE6u,    (q7_t)0xBCu,    (q7_t)0x7Fu,    (q7_t)0xE0u,
    (q7_t)0x24u,    (q7_t)0xEEu,    (q7_t)0x3Bu,    (q7_t)0xA6u,
    (q7_t)0xC2u,    (q7_t)0xF9u,    (q7_t)0x00u,    (q7_t)0xCBu,
    (q7_t)0xE0u,    (q7_t)0xF0u,    (q7_t)0xF7u,    (q7_t)0xD3u,
    (q7_t)0x09u,    (q7_t)0xE4u,    (q7_t)0x0Fu,    (q7_t)0xF3u,
    (q7_t)0xA8u,    (q7_t)0xD8u,    (q7_t)0xD0u,    (q7_t)0x22u,
    (q7_t)0x96u,    (q7_t)0x1Bu,    (q7_t)0x0Fu,    (q7_t)0x44u,
    (q7_t)0xA0u,    (q7_t)0x45u,    (q7_t)0x0Cu,    (q7_t)0xF4u,
    (q7_t)0x00u,    (q7_t)0xC2u,    (q7_t)0xEAu,    (q7_t)0xE3u,
    (q7_t)0x2Au,    (q7_t)0x0Eu,    (q7_t)0xD5u,    (q7_t)0xE2u,
    (q7_t)0x0Eu,    (q7_t)0xDCu,    (q7_t)0x09u,    (q7_t)0xC1u,
};

static const q7_t q7_inputrand[] = {
    (q7_t)0xF6u,    (q7_t)0xFEu,    (q7_t)0xF5u,    (q7_t)0x1Bu,
    (q7_t)0x0Du,    (q7_t)0x13u,    (q7_t)0xF9u,    (q7_t)0x10u,
    (q7_t)0xF6u,    (q7_t)0x02u,    (q7_t)0xE4u,    (q7_t)0xD5u,
    (q7_t)0xF5u,    (q7_t)0xF7u,    (q7_t)0x14u,    (q7_t)0xDFu,
    (q7_t)0xFBu,    (q7_t)0xE6u,    (q7_t)0xF0u,    (q7_t)0xEEu,
    (q7_t)0x02u,    (q7_t)0x18u,    (q7_t)0x0Eu,    (q7_t)0x0Eu,
    (q7_t)0x16u,    (q7_t)0xF8u,    (q7_t)0xF3u,    (q7_t)0xF2u,
    (q7_t)0xFFu,    (q7_t)0x0Fu,    (q7_t)0xF6u,    (q7_t)0x0Du,
    (q7_t)0x1Cu,
};

static const q7_t q7_inputclip[] = {
    (q7_t)0x8Du,    (q7_t)0x8Eu,    (q7_t)0x8Eu,    (q7_t)0x8Fu,
    (q7_t)0x90u,    (q7_t)0x91u,    (q7_t)0x91u,    (q7_t)0x92u,
    (q7_t)0x93u,    (q7_t)0x94u,    (q7_t)0x94u,    (q7_t)0x95u,
    (q7_t)0x96u,    (q7_t)0x97u,    (q7_t)0x97u,    (q7_t)0x98u,
    (q7_t)0x99u,    (q7_t)0x9Au,    (q7_t)0x9Bu,    (q7_t)0x9Bu,
    (q7_t)0x9Cu,    (q7_t)0x9Du,    (q7_t)0x9Eu,    (q7_t)0x9Eu,
    (q7_t)0x9Fu,    (q7_t)0xA0u,    (q7_t)0xA1u,    (q7_t)0xA1u,
    (q7_t)0xA2u,    (q7_t)0xA3u,    (q7_t)0xA4u,    (q7_t)0xA4u,
    (q7_t)0xA5u,    (q7_t)0xA6u,    (q7_t)0xA7u,    (q7_t)0xA8u,
    (q7_t)0xA8u,    (q7_t)0xA9u,    (q7_t)0xAAu,    (q7_t)0xABu,
    (q7_t)0xABu,    (q7_t)0xACu,    (q7_t)0xADu,    (q7_t)0xAEu,
    (q7_t)0xAEu,    (q7_t)0xAFu,    (q7_t)0xB0u,    (q7_t)0xB1u,
    (q7_t)0xB1u,    (q7_t)0xB2u,    (q7_t)0xB3u,    (q7_t)0xB4u,
    (q7_t)0xB4u,    (q7_t)0xB5u,    (q7_t)0xB6u,    (q7_t)0xB7u,
    (q7_t)0xB8u,    (q7_t)0xB8u,    (q7_t)0xB9u,    (q7_t)0xBAu,
    (q7_t)0xBBu,    (q7_t)0xBBu,    (q7_t)0xBCu,    (q7_t)0xBDu,
    (q7_t)0xBEu,    (q7_t)0xBEu,    (q7_t)0xBFu,    (q7_t)0xC0u,
    (q7_t)0xC1u,    (q7_t)0xC1u,    (q7_t)0xC2u,    (q7_t)0xC3u,
    (q7_t)0xC4u,    (q7_t)0xC4u,    (q7_t)0xC5u,    (q7_t)0xC6u,
    (q7_t)0xC7u,    (q7_t)0xC8u,    (q7_t)0xC8u,    (q7_t)0xC9u,
    (q7_t)0xCAu,    (q7_t)0xCBu,    (q7_t)0xCBu,    (q7_t)0xCCu,
    (q7_t)0xCDu,    (q7_t)0xCEu,    (q7_t)0xCEu,    (q7_t)0xCFu,
    (q7_t)0xD0u,    (q7_t)0xD1u,    (q7_t)0xD1u,    (q7_t)0xD2u,
    (q7_t)0xD3u,    (q7_t)0xD4u,    (q7_t)0xD5u,    (q7_t)0xD5u,
    (q7_t)0xD6u,    (q7_t)0xD7u,    (q7_t)0xD8u,    (q7_t)0xD8u,
    (q7_t)0xD9u,    (q7_t)0xDAu,    (q7_t)0xDBu,    (q7_t)0xDBu,
    (q7_t)0xDCu,    (q7_t)0xDDu,    (q7_t)0xDEu,    (q7_t)0xDEu,
    (q7_t)0xDFu,    (q7_t)0xE0u,    (q7_t)0xE1u,    (q7_t)0xE1u,
    (q7_t)0xE2u,    (q7_t)0xE3u,    (q7_t)0xE4u,    (q7_t)0xE5u,
    (q7_t)0xE5u,    (q7_t)0xE6u,    (q7_t)0xE7u,    (q7_t)0xE8u,
    (q7_t)0xE8u,    (q7_t)0xE9u,    (q7_t)0xEAu,    (q7_t)0xEBu,
    (q7_t)0xEBu,    (q7_t)0xECu,    (q7_t)0xEDu,    (q7_t)0xEEu,
    (q7_t)0xEEu,    (q7_t)0xEFu,    (q7_t)0xF0u,    (q7_t)0xF1u,
    (q7_t)0xF2u,    (q7_t)0xF2u,    (q7_t)0xF3u,    (q7_t)0xF4u,
    (q7_t)0xF5u,    (q7_t)0xF5u,    (q7_t)0xF6u,    (q7_t)0xF7u,
    (q7_t)0xF8u,    (q7_t)0xF8u,    (q7_t)0xF9u,    (q7_t)0xFAu,
    (q7_t)0xFBu,    (q7_t)0xFBu,    (q7_t)0xFCu,    (q7_t)0xFDu,
    (q7_t)0xFEu,    (q7_t)0xFEu,    (q7_t)0xFFu,    (q7_t)0x00u,
    (q7_t)0x01u,    (q7_t)0x02u,    (q7_t)0x02u,    (q7_t)0x03u,
    (q7_t)0x04u,    (q7_t)0x05u,    (q7_t)0x05u,    (q7_t)0x06u,
    (q7_t)0x07u,    (q7_t)0x08u,    (q7_t)0x08u,    (q7_t)0x09u,
    (q7_t)0x0Au,    (q7_t)0x0Bu,    (q7_t)0x0Bu,    (q7_t)0x0Cu,
    (q7_t)0x0Du,    (q7_t)0x0Eu,    (q7_t)0x0Eu,    (q7_t)0x0Fu,
    (q7_t)0x10u,    (q7_t)0x11u,    (q7_t)0x12u,    (q7_t)0x12u,
    (q7_t)0x13u,    (q7_t)0x14u,    (q7_t)0x15u,    (q7_t)0x15u,
    (q7_t)0x16u,    (q7_t)0x17u,    (q7_t)0x18u,    (q7_t)0x18u,
    (q7_t)0x19u,    (q7_t)0x1Au,    (q7_t)0x1Bu,    (q7_t)0x1Bu,
    (q7_t)0x1Cu,    (q7_t)0x1Du,    (q7_t)0x1Eu,    (q7_t)0x1Fu,
    (q7_t)0x1Fu,    (q7_t)0x20u,    (q7_t)0x21u,    (q7_t)0x22u,
    (q7_t)0x22u,    (q7_t)0x23u,    (q7_t)0x24u,    (q7_t)0x25u,
    (q7_t)0x25u,    (q7_t)0x26u,    (q7_t)0x27u,    (q7_t)0x28u,
    (q7_t)0x28u,    (q7_t)0x29u,    (q7_t)0x2Au,    (q7_t)0x2Bu,
    (q7_t)0x2Bu,    (q7_t)0x2Cu,    (q7_t)0x2Du,    (q7_t)0x2Eu,
    (q7_t)0x2Fu,    (q7_t)0x2Fu,    (q7_t)0x30u,    (q7_t)0x31u,
    (q7_t)0x32u,    (q7_t)0x32u,    (q7_t)0x33u,    (q7_t)0x34u,
    (q7_t)0x35u,    (q7_t)0x35u,    (q7_t)0x36u,    (q7_t)0x37u,
    (q7_t)0x38u,    (q7_t)0x38u,    (q7_t)0x39u,    (q7_t)0x3Au,
    (q7_t)0x3Bu,    (q7_t)0x3Cu,    (q7_t)0x3Cu,    (q7_t)0x3Du,
    (q7_t)0x3Eu,    (q7_t)0x3Fu,    (q7_t)0x3Fu,    (q7_t)0x40u,
    (q7_t)0x41u,    (q7_t)0x42u,    (q7_t)0x42u,    (q7_t)0x43u,
    (q7_t)0x44u,    (q7_t)0x45u,    (q7_t)0x45u,    (q7_t)0x46u,
    (q7_t)0x47u,    (q7_t)0x48u,    (q7_t)0x48u,    (q7_t)0x49u,
    (q7_t)0x4Au,    (q7_t)0x4Bu,    (q7_t)0x4Cu,    (q7_t)0x4Cu,
    (q7_t)0x4Du,    (q7_t)0x4Eu,    (q7_t)0x4Fu,    (q7_t)0x4Fu,
    (q7_t)0x50u,    (q7_t)0x51u,    (q7_t)0x52u,    (q7_t)0x52u,
    (q7_t)0x53u,    (q7_t)0x54u,    (q7_t)0x55u,    (q7_t)0x55u,
    (q7_t)0x56u,    (q7_t)0x57u,    (q7_t)0x58u,    (q7_t)0x58u,
    (q7_t)0x59u,    (q7_t)0x5Au,    (q7_t)0x5Bu,    (q7_t)0x5Cu,
    (q7_t)0x5Cu,    (q7_t)0x5Du,    (q7_t)0x5Eu,    (q7_t)0x5Fu,
    (q7_t)0x5Fu,    (q7_t)0x60u,    (q7_t)0x61u,    (q7_t)0x62u,
    (q7_t)0x62u,    (q7_t)0x63u,    (q7_t)0x64u,    (q7_t)0x65u,
    (q7_t)0x65u,    (q7_t)0x66u,    (q7_t)0x67u,    (q7_t)0x68u,
    (q7_t)0x69u,    (q7_t)0x69u,    (q7_t)0x6Au,    (q7_t)0x6Bu,
    (q7_t)0x6Cu,    (q7_t)0x6Cu,    (q7_t)0x6Du,    (q7_t)0x6Eu,
    (q7_t)0x6Fu,    (q7_t)0x6Fu,    (q7_t)0x70u,    (q7_t)0x71u,
    (q7_t)0x72u,    (q7_t)0x72u,    (q7_t)0x73u,
};

static const q7_t q7_maxpos[] = {
    (q7_t)0x7Eu,    (q7_t)0x01u,    (q7_t)0x7Eu,    (q7_t)0x01u,
    (q7_t)0x7Eu,    (q7_t)0x01u,    (q7_t)0x7Eu,    (q7_t)0x01u,
    (q7_t)0x7Eu,    (q7_t)0x01u,    (q7_t)0x7Eu,    (q7_t)0x01u,
    (q7_t)0x7Eu,    (q7_t)0x01u,    (q7_t)0x7Eu,    (q7_t)0x01u,
    (q7_t)0x7Eu,    (q7_t)0x01u,    (q7_t)0x7Eu,    (q7_t)0x01u,
    (q7_t)0x7Eu,    (q7_t)0x01u,    (q7_t)0x7Eu,    (q7_t)0x01u,
    (q7_t)0x7Eu,    (q7_t)0x01u,    (q7_t)0x7Eu,    (q7_t)0x01u,
    (q7_t)0x7Eu,    (q7_t)0x01u,    (q7_t)0x7Eu,    (q7_t)0x01u,
    (q7_t)0x7Eu,
};

static const q7_t q7_maxneg[] = {
    (q7_t)0x81u,    (q7_t)0xFFu,    (q7_t)0x81u,    (q7_t)0xFFu,
    (q7_t)0x81u,    (q7_t)0xFFu,    (q7_t)0x81u,    (q7_t)0xFFu,
    (q7_t)0x81u,    (q7_t)0xFFu,    (q7_t)0x81u,    (q7_t)0xFFu,
    (q7_t)0x81u,    (q7_t)0xFFu,    (q7_t)0x81u,    (q7_t)0xFFu,
    (q7_t)0x81u,    (q7_t)0xFFu,    (q7_t)0x81u,    (q7_t)0xFFu,
    (q7_t)0x81u,    (q7_t)0xFFu,    (q7_t)0x81u,    (q7_t)0xFFu,
    (q7_t)0x81u,    (q7_t)0xFFu,    (q7_t)0x81u,    (q7_t)0xFFu,
    (q7_t)0x81u,    (q7_t)0xFFu,    (q7_t)0x81u,    (q7_t)0xFFu,
    (q7_t)0x81u,
};

static const q7_t q7_maxneg2[] = {
    (q7_t)0x80u,    (q7_t)0xFEu,    (q7_t)0x80u,    (q7_t)0xFEu,
    (q7_t)0x80u,    (q7_t)0xFEu,    (q7_t)0x80u,    (q7_t)0xFEu,
    (q7_t)0x80u,    (q7_t)0xFEu,    (q7_t)0x80u,    (q7_t)0xFEu,
    (q7_t)0x80u,    (q7_t)0xFEu,    (q7_t)0x80u,    (q7_t)0xFEu,
    (q7_t)0x80u,    (q7_t)0xFEu,    (q7_t)0x80u,    (q7_t)0xFEu,
    (q7_t)0x80u,    (q7_t)0xFEu,    (q7_t)0x80u,    (q7_t)0xFEu,
    (q7_t)0x80u,    (q7_t)0xFEu,    (q7_t)0x80u,    (q7_t)0xFEu,
    (q7_t)0x80u,    (q7_t)0xFEu,    (q7_t)0x80u,    (q7_t)0xFEu,
    (q7_t)0x80u,
};

static const uint8_t q7_bit1[] = {
    (uint8_t)0xFBu,    (uint8_t)0xD4u,    (uint8_t)0xF1u,    (uint8_t)0xD8u,
    (uint8_t)0x8Au,    (uint8_t)0x8Fu,    (uint8_t)0x00u,    (uint8_t)0xF8u,
    (uint8_t)0xD2u,    (uint8_t)0xD0u,    (uint8_t)0xE3u,    (uint8_t)0x46u,
    (uint8_t)0xC4u,    (uint8_t)0x64u,    (uint8_t)0x5Eu,    (uint8_t)0xB8u,
    (uint8_t)0x45u,    (uint8_t)0x14u,    (uint8_t)0x1Cu,    (uint8_t)0x71u,
    (uint8_t)0x9Du,    (uint8_t)0x9Au,    (uint8_t)0x5Fu,    (uint8_t)0x42u,
    (uint8_t)0xFEu,    (uint8_t)0x7Cu,    (uint8_t)0xCAu,    (uint8_t)0x2Cu,
    (uint8_t)0x3Fu,    (uint8_t)0x1Bu,    (uint8_t)0xFAu,    (uint8_t)0xC7u,
    (uint8_t)0xB5u,    (uint8_t)0x33u,    (uint8_t)0x72u,    (uint8_t)0x46u,
    (uint8_t)0xF0u,    (uint8_t)0x8Au,    (uint8_t)0x39u,    (uint8_t)0xCCu,
    (uint8_t)0xA2u,    (uint8_t)0x05u,    (uint8_t)0xA4u,    (uint8_t)0x41u,
    (uint8_t)0x87u,    (uint8_t)0xE0u,    (uint8_t)0x79u,
};

static const uint8_t q7_bit2[] = {
    (uint8_t)0xA7u,    (uint8_t)0xE3u,    (uint8_t)0x1Bu,    (uint8_t)0xCAu,
    (uint8_t)0x5Du,    (uint8_t)0x6Au,    (uint8_t)0x31u,    (uint8_t)0x4Cu,
    (uint8_t)0xB2u,    (uint8_t)0x00u,    (uint8_t)0xB9u,    (uint8_t)0xA2u,
    (uint8_t)0x09u,    (uint8_t)0xEEu,    (uint8_t)0xA0u,    (uint8_t)0x4Eu,
    (uint8_t)0xC2u,    (uint8_t)0x21u,    (uint8_t)0x65u,    (uint8_t)0x98u,
    (uint8_t)0xD6u,    (uint8_t)0xCCu,    (uint8_t)0x50u,    (uint8_t)0xD6u,
    (uint8_t)0x27u,    (uint8_t)0x04u,    (uint8_t)0x0Du,    (uint8_t)0x18u,
    (uint8_t)0x3Eu,    (uint8_t)0xE5u,    (uint8_t)0x44u,    (uint8_t)0x3Cu,
    (uint8_t)0x44u,    (uint8_t)0x5Fu,    (uint8_t)0xC8u,    (uint8_t)0xBCu,
    (uint8_t)0x2Cu,    (uint8_t)0x67u,    (uint8_t)0x7Au,    (uint8_t)0x36u,
    (uint8_t)0x88u,    (uint8_t)0x8Au,    (uint8_t)0xC7u,    (uint8_t)0xBAu,
    (uint8_t)0x91u,    (uint8_t)0x45u,    (uint8_t)0xB9u,
};

static const q7_t q7_ref[] = {
    (q7_t)0x70u,    (q7_t)0xDFu,    (q7_t)0x57u,    (q7_t)0x12u,
    (q7_t)0x80u,    (q7_t)0xDAu,    (q7_t)0x33u,    (q7_t)0x47u,
    (q7_t)0xD3u,    (q7_t)0xD3u,    (q7_t)0x52u,    (q7_t)0xAAu,
    (q7_t)0x1Eu,    (q7_t)0x24u,    (q7_t)0x13u,    (q7_t)0x03u,
    (q7_t)0x3Au,    (q7_t)0x4Au,    (q7_t)0x2Au,    (q7_t)0x25u,
    (q7_t)0x9Au,    (q7_t)0xE0u,    (q7_t)0x19u,    (q7_t)0x5Bu,
    (q7_t)0x16u,    (q7_t)0x8Eu,    (q7_t)0xD0u,    (q7_t)0xE7u,
    (q7_t)0x29u,    (q7_t)0x11u,    (q7_t)0xFCu,    (q7_t)0xD5u,
    (q7_t)0xF8u,    (q7_t)0xFBu,    (q7_t)0x33u,    (q7_t)0xB6u,
    (q7_t)0x9Au,    (q7_t)0x20u,    (q7_t)0x46u,    (q7_t)0x80u,
    (q7_t)0x31u,    (q7_t)0x7Bu,    (q7_t)0x05u,    (q7_t)0x2Eu,
    (q7_t)0x49u,    (q7_t)0xD7u,    (q7_t)0x17u,    (q7_t)0xFBu,
    (q7_t)0xC8u,    (q7_t)0x36u,    (q7_t)0x80u,    (q7_t)0x7Du,
    (q7_t)0x38u,    (q7_t)0xE8u,    (q7_t)0xC1u,    (q7_t)0x24u,
    (q7_t)0x22u,    (q7_t)0xD1u,    (q7_t)0xC7u,    (q7_t)0x51u,
    (q7_t)0x1Eu,    (q7_t)0x09u,    (q7_t)0x20u,    (q7_t)0x52u,
    (q7_t)0xE5u,    (q7_t)0x03u,    (q7_t)0x13u,    (q7_t)0x41u,
    (q7_t)0x30u,    (q7_t)0x06u,    (q7_t)0x2Cu,    (q7_t)0x26u,
    (q7_t)0x1Bu,    (q7_t)0xABu,    (q7_t)0x16u,    (q7_t)0x42u,
    (q7_t)0xA0u,    (q7_t)0xD6u,    (q7_t)0xD5u,    (q7_t)0xFAu,
    (q7_t)0x10u,    (q7_t)0xCDu,    (q7_t)0x88u,    (q7_t)0xE8u,
    (q7_t)0x0Au,    (q7_t)0xD9u,    (q7_t)0xF5u,    (q7_t)0xD8u,
    (q7_t)0x48u,    (q7_t)0x16u,    (q7_t)0xCBu,    (q7_t)0x01u,
    (q7_t)0xADu,    (q7_t)0x1Du,    (q7_t)0x2Bu,    (q7_t)0xDEu,
    (q7_t)0x20u,    (q7_t)0x03u,    (q7_t)0x6Eu,    (q7_t)0x41u,
    (q7_t)0xBBu,    (q7_t)0x65u,    (q7_t)0x03u,    (q7_t)0x00u,
    (q7_t)0xB5u,    (q7_t)0xCCu,    (q7_t)0xA4u,    (q7_t)0x18u,
    (q7_t)0x00u,    (q7_t)0x69u,    (q7_t)0x80u,    (q7_t)0xAEu,
    (q7_t)0x13u,    (q7_t)0x81u,    (q7_t)0x14u,    (q7_t)0x55u,
    (q7_t)0x23u,    (q7_t)0xDDu,    (q7_t)0x2Fu,    (q7_t)0xF5u,
    (q7_t)0x2Du,    (q7_t)0x0Fu,    (q7_t)0x13u,    (q7_t)0x0Cu,
    (q7_t)0xAEu,    (q7_t)0xFFu,    (q7_t)0xCCu,    (q7_t)0x18u,
    (q7_t)0xAAu,    (q7_t)0x3Du,    (q7_t)0x11u,    (q7_t)0xA3u,
    (q7_t)0x3Bu,    (q7_t)0x04u,    (q7_t)0xD5u,    (q7_t)0x29u,
    (q7_t)0x6Fu,    (q7_t)0x24u,    (q7_t)0x56u,    (q7_t)0x0Cu,
    (q7_t)0x41u,    (q7_t)0xE5u,    (q7_t)0x51u,    (q7_t)0xAEu,
    (q7_t)0x98u,    (q7_t)0x80u,    (q7_t)0x80u,    (q7_t)0x23u,
    (q7_t)0x5Du,    (q7_t)0xB5u,    (q7_t)0x1Bu,    (q7_t)0x00u,
    (q7_t)0x35u,    (q7_t)0x90u,    (q7_t)0x1Au,    (q7_t)0x05u,
    (q7_t)0xC0u,    (q7_t)0xF6u,    (q7_t)0xB8u,    (q7_t)0x27u,
    (q7_t)0xDCu,    (q7_t)0xE7u,    (q7_t)0x3Eu,    (q7_t)0xEAu,
    (q7_t)0xF1u,    (q7_t)0x11u,    (q7_t)0xB0u,    (q7_t)0xCAu,
    (q7_t)0x55u,    (q7_t)0xE6u,    (q7_t)0xF0u,    (q7_t)0x2Eu,
    (q7_t)0x18u,    (q7_t)0x02u,    (q7_t)0xA2u,    (q7_t)0xD1u,
    (q7_t)0xEBu,    (q7_t)0x19u,    (q7_t)0x06u,    (q7_t)0xE7u,
    (q7_t)0x11u,    (q7_t)0x99u,    (q7_t)0x80u,    (q7_t)0xFAu,
    (q7_t)0xD0u,    (q7_t)0xD5u,    (q7_t)0x12u,    (q7_t)0x13u,
    (q7_t)0x4Cu,    (q7_t)0xCDu,    (q7_t)0x4Au,    (q7_t)0xD1u,
    (q7_t)0x55u,    (q7_t)0x56u,    (q7_t)0xECu,    (q7_t)0x21u,
    (q7_t)0x30u,    (q7_t)0x1Du,    (q7_t)0x8Bu,    (q7_t)0xCBu,
    (q7_t)0x6Bu,    (q7_t)0xEFu,    (q7_t)0x53u,    (q7_t)0x80u,
    (q7_t)0x93u,    (q7_t)0xF0u,    (q7_t)0xDCu,    (q7_t)0x7Fu,
    (q7_t)0xC2u,    (q7_t)0x5Cu,    (q7_t)0x1Bu,    (q7_t)0x7Au,
    (q7_t)0xC8u,    (q7_t)0xF7u,    (q7_t)0x7Du,    (q7_t)0xC4u,
    (q7_t)0x1Au,    (q7_t)0x80u,    (q7_t)0x50u,    (q7_t)0x95u,
    (q7_t)0x80u,    (q7_t)0x63u,    (q7_t)0x16u,    (q7_t)0xD9u,
    (q7_t)0xD2u,    (q7_t)0xB4u,    (q7_t)0xDEu,    (q7_t)0xE0u,
    (q7_t)0xB3u,    (q7_t)0x18u,    (q7_t)0x2Bu,    (q7_t)0x06u,
    (q7_t)0xEDu,    (q7_t)0xC0u,    (q7_t)0xC2u,    (q7_t)0x11u,
    (q7_t)0xC3u,    (q7_t)0x3Du,    (q7_t)0x52u,    (q7_t)0x7Fu,
    (q7_t)0xCCu,    (q7_t)0x73u,    (q7_t)0x7Fu,    (q7_t)0xF5u,
    (q7_t)0x16u,    (q7_t)0xC8u,    (q7_t)0xD5u,    (q7_t)0x27u,
    (q7_t)0xF5u,    (q7_t)0xECu,    (q7_t)0xBAu,    (q7_t)0xD4u,
    (q7_t)0x1Eu,    (q7_t)0xBAu,    (q7_t)0x3Eu,    (q7_t)0xCBu,
};

static const q31_t q7_refdot[] = {
    (q31_t)0x00000CE0u,
};

static const uint8_t q7_refand[] = {
    (uint8_t)0xA3u,    (uint8_t)0xC0u,    (uint8_t)0x11u,    (uint8_t)0xC8u,
    (uint8_t)0x08u,    (uint8_t)0x0Au,    (uint8_t)0x00u,    (uint8_t)0x48u,
    (uint8_t)0x92u,    (uint8_t)0x00u,    (uint8_t)0xA1u,    (uint8_t)0x02u,
    (uint8_t)0x00u,    (uint8_t)0x64u,    (uint8_t)0x00u,    (uint8_t)0x08u,
    (uint8_t)0x40u,    (uint8_t)0x00u,    (uint8_t)0x04u,    (uint8_t)0x10u,
    (uint8_t)0x94u,    (uint8_t)0x88u,    (uint8_t)0x50u,    (uint8_t)0x42u,
    (uint8_t)0x26u,    (uint8_t)0x04u,    (uint8_t)0x08u,    (uint8_t)0x08u,
    (uint8_t)0x3Eu,    (uint8_t)0x01u,    (uint8_t)0x40u,    (uint8_t)0x04u,
    (uint8_t)0x04u,    (uint8_t)0x13u,    (uint8_t)0x40u,    (uint8_t)0x04u,
    (uint8_t)0x20u,    (uint8_t)0x02u,    (uint8_t)0x38u,    (uint8_t)0x04u,
    (uint8_t)0x80u,    (uint8_t)0x00u,    (uint8_t)0x84u,    (uint8_t)0x00u,
    (uint8_t)0x81u,    (uint8_t)0x40u,    (uint8_t)0x39u,
};

static const q15_t q15_input1[] = {
    (q15_t)0x0EB1u,    (q15_t)0xD7DAu,    (q15_t)0xDFC2u,    (q15_t)0x2DDAu,
    (q15_t)0xAEB8u,    (q15_t)0x1A8Cu,    (q15_t)0x34D0u,    (q15_t)0xC949u,
    (q15_t)0x19FFu,    (q15_t)0x1AFCu,    (q15_t)0xD67Eu,    (q15_t)0x2639u,
    (q15_t)0x1546u,    (q15_t)0xF32Du,    (q15_t)0x2A82u,    (q15_t)0xB79Eu,
    (q15_t)0x1317u,    (q15_t)0xEAF2u,    (q15_t)0xCBD9u,    (q15_t)0xC454u,
    (q15_t)0x42FDu,    (q15_t)0xBB89u,    (q15_t)0x9B4Fu,    (q15_t)0xCE5Cu,
    (q15_t)0x09A1u,    (q15_t)0xDFC2u,    (q15_t)0xD780u,    (q15_t)0x2B2Cu,
    (q15_t)0x0FDBu,    (q15_t)0xC69Cu,    (q15_t)0x5D9Bu,    (q15_t)0xBC82u,
    (q15_t)0x2794u,    (q15_t)0xC287u,    (q15_t)0x152Bu,    (q15_t)0xDA69u,
    (q15_t)0x2BE1u,    (q15_t)0xE9BBu,    (q15_t)0xD5EEu,    (q15_t)0xC7C4u,
    (q15_t)0xBCDAu,    (q15_t)0xC828u,    (q15_t)0x19B1u,    (q15_t)0x5F41u,
    (q15_t)0x5146u,    (q15_t)0x00F0u,    (q15_t)0xDEF6u,    (q15_t)0x2A44u,
    (q15_t)0xCD0Au,    (q15_t)0xE918u,    (q15_t)0xF4D0u,    (q15_t)0xD863u,
    (q15_t)0x241Fu,    (q15_t)0xE030u,    (q15_t)0x26F3u,    (q15_t)0x1ACBu,
    (q15_t)0x245Cu,    (q15_t)0x047Cu,    (q15_t)0x9433u,    (q15_t)0x2BF5u,
    (q15_t)0x2F0Fu,    (q15_t)0x40E5u,    (q15_t)0xC00Du,    (q15_t)0x849Cu,
    (q15_t)0x215Du,    (q15_t)0xDE1Bu,    (q15_t)0x264Au,    (q15_t)0x311Du,
    (q15_t)0x0C88u,    (q15_t)0x1028u,    (q15_t)0x2D8Fu,    (q15_t)0xCE0Eu,
    (q15_t)0x1B43u,    (q15_t)0x5529u,    (q15_t)0x2914u,    (q15_t)0xE215u,
    (q15_t)0x0C95u,    (q15_t)0xF727u,    (q15_t)0xDF21u,    (q15_t)0xD12Eu,
    (q15_t)0xBF74u,    (q15_t)0xBFB5u,    (q15_t)0xC4B0u,    (q15_t)0xCDBBu,
    (q15_t)0xE3D0u,    (q15_t)0xFAF9u,    (q15_t)0x2579u,    (q15_t)0xE9F5u,
    (q15_t)0xE00Du,    (q15_t)0xE3B7u,    (q15_t)0x2FE5u,    (q15_t)0xE7A2u,
    (q15_t)0xE72Cu,    (q15_t)0x4C12u,    (q15_t)0x156Eu,    (q15_t)0x03A9u,
    (q15_t)0xE767u,    (q15_t)0x14B9u,    (q15_t)0x8F36u,    (q15_t)0x54D3u,
    (q15_t)0xF8CFu,    (q15_t)0xC5F2u,    (q15_t)0xE3E2u,    (q15_t)0x3EEBu,
    (q15_t)0x054Au,    (q15_t)0x6482u,    (q15_t)0x013Cu,    (q15_t)0xFF6Du,
    (q15_t)0x078Fu,    (q15_t)0xA20Au,    (q15_t)0xEF63u,    (q15_t)0xCBABu,
    (q15_t)0xC222u,    (q15_t)0xA967u,    (q15_t)0x3F6Bu,    (q15_t)0xFAFEu,
    (q15_t)0x1498u,    (q15_t)0xF9D3u,    (q15_t)0xC2C3u,    (q15_t)0xCD2Cu,
    (q15_t)0x1B37u,    (q15_t)0xA9E8u,    (q15_t)0xF8A4u,    (q15_t)0xD3A6u,
    (q15_t)0xD238u,    (q15_t)0x55ECu,    (q15_t)0xF7FAu,    (q15_t)0x007Cu,
    (q15_t)0xC1BFu,    (q15_t)0x161Fu,    (q15_t)0x8000u,    (q15_t)0x273Du,
    (q15_t)0xEEC7u,    (q15_t)0xFDDAu,    (q15_t)0xD41Cu,    (q15_t)0x51C4u,
    (q15_t)0x1697u,    (q15_t)0x3C98u,    (q15_t)0x2E62u,    (q15_t)0xC85Du,
    (q15_t)0x01FFu,    (q15_t)0xC356u,    (q15_t)0xBCC5u,    (q15_t)0xF6C0u,
    (q15_t)0xC2FBu,    (q15_t)0x1CC0u,    (q15_t)0xC736u,    (q15_t)0xED5Cu,
    (q15_t)0x1B3Cu,    (q15_t)0xCEDCu,    (q15_t)0xDC71u,    (q15_t)0xD699u,
    (q15_t)0x895Au,    (q15_t)0xF44Eu,    (q15_t)0xFEABu,    (q15_t)0xB470u,
    (q15_t)0xE176u,    (q15_t)0xC915u,    (q15_t)0x23ADu,    (q15_t)0xDBDEu,
    (q15_t)0x2579u,    (q15_t)0xB028u,    (q15_t)0xF293u,    (q15_t)0xF1D3u,
    (q15_t)0x2BE9u,    (q15_t)0x3FE0u,    (q15_t)0x5143u,    (q15_t)0x8BB5u,
    (q15_t)0xD9A9u,    (q15_t)0xC304u,    (q15_t)0x5BE4u,    (q15_t)0xBD39u,
    (q15_t)0xF24Au,    (q15_t)0xC721u,    (q15_t)0xE044u,    (q15_t)0xE5EBu,
    (q15_t)0x3015u,    (q15_t)0x22EBu,    (q15_t)0x0FC5u,    (q15_t)0xF766u,
    (q15_t)0xCAECu,    (q15_t)0x356Eu,    (q15_t)0xF105u,    (q15_t)0xE3F6u,
    (q15_t)0xC69Bu,    (q15_t)0xC858u,    (q15_t)0x1EF3u,    (q15_t)0xD29Au,
    (q15_t)0xF220u,    (q15_t)0x156Bu,    (q15_t)0x0625u,    (q15_t)0xD1BAu,
    (q15_t)0x0DF9u,    (q15_t)0x6A80u,    (q15_t)0xECF5u,    (q15_t)0xBBC4u,
    (q15_t)0xE8B3u,    (q15_t)0x1DBDu,    (q15_t)0x27EDu,    (q15_t)0x43D5u,
    (q15_t)0x38E0u,    (q15_t)0x0942u,    (q15_t)0x0DB3u,    (q15_t)0x93F4u,
    (q15_t)0xF640u,    (q15_t)0xBC17u,    (q15_t)0xFB75u,    (q15_t)0xB565u,
    (q15_t)0x39FDu,    (q15_t)0x037Eu,    (q15_t)0x533Fu,    (q15_t)0x3981u,
    (q15_t)0x2FC2u,    (q15_t)0xA54Du,    (q15_t)0x2DACu,    (q15_t)0x403Bu,
    (q15_t)0xD1ACu,    (q15_t)0x2397u,    (q15_t)0x06C3u,    (q15_t)0xDD46u,
    (q15_t)0x9F4Cu,    (q15_t)0xF716u,    (q15_t)0xD4F2u,    (q15_t)0xFEEAu,
    (q15_t)0xCE26u,    (q15_t)0xF1C9u,    (q15_t)0x376Eu,    (q15_t)0x2D6Cu,
    (q15_t)0x1DA1u,    (q15_t)0x1ADFu,    (q15_t)0x2DB9u,    (q15_t)0x1E02u,
    (q15_t)0xFA30u,    (q15_t)0x0633u,    (q15_t)0x4356u,    (q15_t)0x06F1u,
    (q15_t)0x0751u,    (q15_t)0x2881u,    (q15_t)0x1D47u,    (q15_t)0x2D8Cu,
    (q15_t)0xA430u,    (q15_t)0xB60Eu,    (q15_t)0x9CBDu,    (q15_t)0xF925u,
    (q15_t)0xF90Cu,    (q15_t)0x235Au,    (q15_t)0xDAACu,    (q15_t)0x3B2Bu,
    (q15_t)0x112Au,    (q15_t)0x8F09u,    (q15_t)0x00B9u,    (q15_t)0xB234u,
    (q15_t)0xA386u,    (q15_t)0xD619u,    (q15_t)0x20AAu,    (q15_t)0x5063u,
};

static const q15_t q15_input2[] = {
    (q15_t)0xF977u,    (q15_t)0xF484u,    (q15_t)0xB38Du,    (q15_t)0xC049u,
    (q15_t)0x127Fu,    (q15_t)0xEE0Du,    (q15_t)0x5183u,    (q15_t)0x1CFFu,
    (q15_t)0x2EC8u,    (q15_t)0x7FFFu,    (q15_t)0x44B4u,    (q15_t)0xD9ADu,
    (q15_t)0x4410u,    (q15_t)0x27AAu,    (q15_t)0x0313u,    (q15_t)0xC597u,
    (q15_t)0xA23Cu,    (q15_t)0xFCF7u,    (q15_t)0xF6CAu,    (q15_t)0x0540u,
    (q15_t)0x3DD7u,    (q15_t)0x4BA0u,    (q15_t)0xCB04u,    (q15_t)0x4650u,
    (q15_t)0x5117u,    (q15_t)0x0F7Au,    (q15_t)0x16B7u,    (q15_t)0x0052u,
    (q15_t)0x04F6u,    (q15_t)0xCBB2u,    (q15_t)0xD270u,    (q15_t)0xFCD5u,
    (q15_t)0xDFF0u,    (q15_t)0x389Eu,    (q15_t)0x2413u,    (q15_t)0xD405u,
    (q15_t)0x08F1u,    (q15_t)0xF872u,    (q15_t)0xABD2u,    (q15_t)0x13D4u,
    (q15_t)0x86ABu,    (q15_t)0xDECAu,    (q15_t)0xEFE1u,    (q15_t)0x04D6u,
    (q15_t)0x2F20u,    (q15_t)0xE4F2u,    (q15_t)0x74C9u,    (q15_t)0xFAFFu,
    (q15_t)0x1E5Bu,    (q15_t)0x4BBCu,    (q15_t)0xE50Fu,    (q15_t)0x26A3u,
    (q15_t)0xF12Fu,    (q15_t)0x9774u,    (q15_t)0x0465u,    (q15_t)0x0FE1u,
    (q15_t)0xB3DDu,    (q15_t)0xFF6Au,    (q15_t)0x2B48u,    (q15_t)0xD882u,
    (q15_t)0xD6B7u,    (q15_t)0x077Au,    (q15_t)0xE7ACu,    (q15_t)0x94B7u,
    (q15_t)0x03BBu,    (q15_t)0x2E0Bu,    (q15_t)0xEE40u,    (q15_t)0xED35u,
    (q15_t)0xEC88u,    (q15_t)0x3365u,    (q15_t)0x60B5u,    (q15_t)0x249Eu,
    (q15_t)0x03B7u,    (q15_t)0xCCB7u,    (q15_t)0xB6E0u,    (q15_t)0xB83Bu,
    (q15_t)0xEB34u,    (q15_t)0xEC7Fu,    (q15_t)0xEC20u,    (q15_t)0x037Fu,
    (q15_t)0x29F7u,    (q15_t)0x9EE0u,    (q15_t)0x0079u,    (q15_t)0xF08Cu,
    (q15_t)0xE025u,    (q15_t)0xE064u,    (q15_t)0xF44Au,    (q15_t)0x28BFu,
    (q15_t)0xDB1Au,    (q15_t)0x11F0u,    (q15_t)0xFF16u,    (q15_t)0x5896u,
    (q15_t)0x01D3u,    (q15_t)0x2546u,    (q15_t)0x0D96u,    (q15_t)0xE7A4u,
    (q15_t)0xFBAFu,    (q15_t)0xC158u,    (q15_t)0x1BD0u,    (q15_t)0x1349u,
    (q15_t)0x0F56u,    (q15_t)0x3C3Au,    (q15_t)0x0971u,    (q15_t)0x0144u,
    (q15_t)0x0103u,    (q15_t)0xD605u,    (q15_t)0x5F13u,    (q15_t)0xD660u,
    (q15_t)0x56D8u,    (q15_t)0x281Au,    (q15_t)0xCB9Cu,    (q15_t)0xF087u,
    (q15_t)0x0DF1u,    (q15_t)0xE910u,    (q15_t)0x00A3u,    (q15_t)0xDB1Fu,
    (q15_t)0xEF24u,    (q15_t)0xCB3Cu,    (q15_t)0xFDC3u,    (q15_t)0x33BFu,
    (q15_t)0xC071u,    (q15_t)0x2387u,    (q15_t)0x1D00u,    (q15_t)0xFCABu,
    (q15_t)0xDEAFu,    (q15_t)0xD8BEu,    (q15_t)0x50D2u,    (q15_t)0xA530u,
    (q15_t)0x3BEDu,    (q15_t)0x33D0u,    (q15_t)0xC7B0u,    (q15_t)0x8906u,
    (q15_t)0x1389u,    (q15_t)0x5832u,    (q15_t)0x12A8u,    (q15_t)0xCD6Bu,
    (q15_t)0x3FB1u,    (q15_t)0x2AF3u,    (q15_t)0x1438u,    (q15_t)0x230Au,
    (q15_t)0x1D37u,    (q15_t)0xDBE5u,    (q15_t)0xC794u,    (q15_t)0xCF49u,
    (q15_t)0xBD1Fu,    (q15_t)0x0352u,    (q15_t)0xDDEFu,    (q15_t)0xF71Bu,
    (q15_t)0xF034u,    (q15_t)0x69E3u,    (q15_t)0xE115u,    (q15_t)0xD0FBu,
    (q15_t)0x14C9u,    (q15_t)0xF522u,    (q15_t)0xDF36u,    (q15_t)0xE814u,
    (q15_t)0xE306u,    (q15_t)0x2CE3u,    (q15_t)0xDB81u,    (q15_t)0x6658u,
    (q15_t)0x02D7u,    (q15_t)0x1E97u,    (q15_t)0xBA82u,    (q15_t)0xEE1Au,
    (q15_t)0x5C73u,    (q15_t)0x2956u,    (q15_t)0xBC37u,    (q15_t)0xF3FAu,
    (q15_t)0xD52Du,    (q15_t)0xFE74u,    (q15_t)0xA370u,    (q15_t)0xE439u,
    (q15_t)0x007Au,    (q15_t)0x0138u,    (q15_t)0xF675u,    (q15_t)0xDAB6u,
    (q15_t)0xFB95u,    (q15_t)0xE5D5u,    (q15_t)0xF490u,    (q15_t)0xF4FDu,
    (q15_t)0x0BD8u,    (q15_t)0x58FFu,    (q15_t)0xE5FAu,    (q15_t)0x1DC2u,
    (q15_t)0x0DB3u,    (q15_t)0xD10Fu,    (q15_t)0x006Fu,    (q15_t)0xC3FAu,
    (q15_t)0xE69Eu,    (q15_t)0xFF03u,    (q15_t)0x01C4u,    (q15_t)0x2F8Au,
    (q15_t)0xE336u,    (q15_t)0x05F5u,    (q15_t)0xD870u,    (q15_t)0xDF1Eu,
    (q15_t)0x532Bu,    (q15_t)0x2F9Bu,    (q15_t)0xED67u,    (q15_t)0xB192u,
    (q15_t)0xF663u,    (q15_t)0xC955u,    (q15_t)0xD832u,    (q15_t)0xCB4Fu,
    (q15_t)0x060Bu,    (q15_t)0x136Au,    (q15_t)0x3EC8u,    (q15_t)0xCBF4u,
    (q15_t)0xF509u,    (q15_t)0x480Fu,    (q15_t)0x22B4u,    (q15_t)0xE9D0u,
    (q15_t)0x3610u,    (q15_t)0x35F0u,    (q15_t)0xD66Au,    (q15_t)0xC10Au,
    (q15_t)0x3476u,    (q15_t)0x0C80u,    (q15_t)0x002Bu,    (q15_t)0xEF29u,
    (q15_t)0x02A2u,    (q15_t)0x8E39u,    (q15_t)0xED70u,    (q15_t)0x0D5Du,
    (q15_t)0x8AF0u,    (q15_t)0x1793u,    (q15_t)0x1CD9u,    (q15_t)0xE7A7u,
    (q15_t)0x45C4u,    (q15_t)0x422Du,    (q15_t)0xCF10u,    (q15_t)0x3A84u,
    (q15_t)0xF767u,    (q15_t)0xC650u,    (q15_t)0xF766u,    (q15_t)0xCAA0u,
    (q15_t)0x2688u,    (q15_t)0x1341u,    (q15_t)0x3C45u,    (q15_t)0x492Bu,
    (q15_t)0x01EEu,    (q15_t)0x156Fu,    (q15_t)0x0862u,    (q15_t)0x28AFu,
    (q15_t)0x42C1u,    (q15_t)0xE27Eu,    (q15_t)0x0164u,    (q15_t)0x8BC3u,
    (q15_t)0x678Du,    (q15_t)0xEECAu,    (q15_t)0xCAF7u,    (q15_t)0xE0ADu,
    (q15_t)0x15EBu,    (q15_t)0x9059u,    (q15_t)0xCAB6u,    (q15_t)0xFE6Eu,
};

static const q15_t q15_inputrand[] = {
    (q15_t)0x271Bu,    (q15_t)0xDA32u,    (q15_t)0x1348u,    (q15_t)0xF2FBu,
    (q15_t)0x2AABu,    (q15_t)0x011Bu,    (q15_t)0x04BEu,    (q15_t)0xEDA1u,
    (q15_t)0xF82Bu,    (q15_t)0xF5ECu,    (q15_t)0x201Au,    (q15_t)0xE56Eu,
    (q15_t)0xE8B7u,    (q15_t)0x09B3u,    (q15_t)0x1889u,    (q15_t)0x15E1u,
    (q15_t)0x00F3u,
};

static const q15_t q15_inputclip[] = {
    (q15_t)0x8CCDu,    (q15_t)0x8DA1u,    (q15_t)0x8E75u,    (q15_t)0x8F49u,
    (q15_t)0x901Du,    (q15_t)0x90F2u,    (q15_t)0x91C6u,    (q15_t)0x929Au,
    (q15_t)0x936Eu,    (q15_t)0x9442u,    (q15_t)0x9516u,    (q15_t)0x95EBu,
    (q15_t)0x96BFu,    (q15_t)0x9793u,    (q15_t)0x9867u,    (q15_t)0x993Bu,
    (q15_t)0x9A0Fu,    (q15_t)0x9AE4u,    (q15_t)0x9BB8u,    (q15_t)0x9C8Cu,
    (q15_t)0x9D60u,    (q15_t)0x9E34u,    (q15_t)0x9F08u,    (q15_t)0x9FDDu,
    (q15_t)0xA0B1u,    (q15_t)0xA185u,    (q15_t)0xA259u,    (q15_t)0xA32Du,
    (q15_t)0xA401u,    (q15_t)0xA4D6u,    (q15_t)0xA5AAu,    (q15_t)0xA67Eu,
    (q15_t)0xA752u,    (q15_t)0xA826u,    (q15_t)0xA8FAu,    (q15_t)0xA9CFu,
    (q15_t)0xAAA3u,    (q15_t)0xAB77u,    (q15_t)0xAC4Bu,    (q15_t)0xAD1Fu,
    (q15_t)0xADF3u,    (q15_t)0xAEC8u,    (q15_t)0xAF9Cu,    (q15_t)0xB070u,
    (q15_t)0xB144u,    (q15_t)0xB218u,    (q15_t)0xB2ECu,    (q15_t)0xB3C1u,
    (q15_t)0xB495u,    (q15_t)0xB569u,    (q15_t)0xB63Du,    (q15_t)0xB711u,
    (q15_t)0xB7E5u,    (q15_t)0xB8BAu,    (q15_t)0xB98Eu,    (q15_t)0xBA62u,
    (q15_t)0xBB36u,    (q15_t)0xBC0Au,    (q15_t)0xBCDEu,    (q15_t)0xBDB3u,
    (q15_t)0xBE87u,    (q15_t)0xBF5Bu,    (q15_t)0xC02Fu,    (q15_t)0xC103u,
    (q15_t)0xC1D7u,    (q15_t)0xC2ACu,    (q15_t)0xC380u,    (q15_t)0xC454u,
    (q15_t)0xC528u,    (q15_t)0xC5FCu,    (q15_t)0xC6D0u,    (q15_t)0xC7A5u,
    (q15_t)0xC879u,    (q15_t)0xC94Du,    (q15_t)0xCA21u,    (q15_t)0xCAF5u,
    (q15_t)0xCBC9u,    (q15_t)0xCC9Eu,    (q15_t)0xCD72u,    (q15_t)0xCE46u,
    (q15_t)0xCF1Au,    (q15_t)0xCFEEu,    (q15_t)0xD0C2u,    (q15_t)0xD197u,
    (q15_t)0xD26Bu,    (q15_t)0xD33Fu,    (q15_t)0xD413u,    (q15_t)0xD4E7u,
    (q15_t)0xD5BBu,    (q15_t)0xD690u,    (q15_t)0xD764u,    (q15_t)0xD838u,
    (q15_t)0xD90Cu,    (q15_t)0xD9E0u,    (q15_t)0xDAB4u,    (q15_t)0xDB89u,
    (q15_t)0xDC5Du,    (q15_t)0xDD31u,    (q15_t)0xDE05u,    (q15_t)0xDED9u,
    (q15_t)0xDFADu,    (q15_t)0xE082u,    (q15_t)0xE156u,    (q15_t)0xE22Au,
    (q15_t)0xE2FEu,    (q15_t)0xE3D2u,    (q15_t)0xE4A6u,    (q15_t)0xE57Bu,
    (q15_t)0xE64Fu,    (q15_t)0xE723u,    (q15_t)0xE7F7u,    (q15_t)0xE8CBu,
    (q15_t)0xE99Fu,    (q15_t)0xEA74u,    (q15_t)0xEB48u,    (q15_t)0xEC1Cu,
    (q15_t)0xECF0u,    (q15_t)0xEDC4u,    (q15_t)0xEE98u,    (q15_t)0xEF6Du,
    (q15_t)0xF041u,    (q15_t)0xF115u,    (q15_t)0xF1E9u,    (q15_t)0xF2BDu,
    (q15_t)0xF391u,    (q15_t)0xF466u,    (q15_t)0xF53Au,    (q15_t)0xF60Eu,
    (q15_t)0xF6E2u,    (q15_t)0xF7B6u,    (q15_t)0xF88Au,    (q15_t)0xF95Fu,
    (q15_t)0xFA33u,    (q15_t)0xFB07u,    (q15_t)0xFBDBu,    (q15_t)0xFCAFu,
    (q15_t)0xFD83u,    (q15_t)0xFE58u,    (q15_t)0xFF2Cu,    (q15_t)0x0000u,
    (q15_t)0x00D4u,    (q15_t)0x01A8u,    (q15_t)0x027Du,    (q15_t)0x0351u,
    (q15_t)0x0425u,    (q15_t)0x04F9u,    (q15_t)0x05CDu,    (q15_t)0x06A1u,
    (q15_t)0x0776u,    (q15_t)0x084Au,    (q15_t)0x091Eu,    (q15_t)0x09F2u,
    (q15_t)0x0AC6u,    (q15_t)0x0B9Au,    (q15_t)0x0C6Fu,    (q15_t)0x0D43u,
    (q15_t)0x0E17u,    (q15_t)0x0EEBu,    (q15_t)0x0FBFu,    (q15_t)0x1093u,
    (q15_t)0x1168u,    (q15_t)0x123Cu,    (q15_t)0x1310u,    (q15_t)0x13E4u,
    (q15_t)0x14B8u,    (q15_t)0x158Cu,    (q15_t)0x1661u,    (q15_t)0x1735u,
    (q15_t)0x1809u,    (q15_t)0x18DDu,    (q15_t)0x19B1u,    (q15_t)0x1A85u,
    (q15_t)0x1B5Au,    (q15_t)0x1C2Eu,    (q15_t)0x1D02u,    (q15_t)0x1DD6u,
    (q15_t)0x1EAAu,    (q15_t)0x1F7Eu,    (q15_t)0x2053u,    (q15_t)0x2127u,
    (q15_t)0x21FBu,    (q15_t)0x22CFu,    (q15_t)0x23A3u,    (q15_t)0x2477u,
    (q15_t)0x254Cu,    (q15_t)0x2620u,    (q15_t)0x26F4u,    (q15_t)0x27C8u,
    (q15_t)0x289Cu,    (q15_t)0x2970u,    (q15_t)0x2A45u,    (q15_t)0x2B19u,
    (q15_t)0x2BEDu,    (q15_t)0x2CC1u,    (q15_t)0x2D95u,    (q15_t)0x2E69u,
    (q15_t)0x2F3Eu,    (q15_t)0x3012u,    (q15_t)0x30E6u,    (q15_t)0x31BAu,
    (q15_t)0x328Eu,    (q15_t)0x3362u,    (q15_t)0x3437u,    (q15_t)0x350Bu,
    (q15_t)0x35DFu,    (q15_t)0x36B3u,    (q15_t)0x3787u,    (q15_t)0x385Bu,
    (q15_t)0x3930u,    (q15_t)0x3A04u,    (q15_t)0x3AD8u,    (q15_t)0x3BACu,
    (q15_t)0x3C80u,    (q15_t)0x3D54u,    (q15_t)0x3E29u,    (q15_t)0x3EFDu,
    (q15_t)0x3FD1u,    (q15_t)0x40A5u,    (q15_t)0x4179u,    (q15_t)0x424Du,
    (q15_t)0x4322u,    (q15_t)0x43F6u,    (q15_t)0x44CAu,    (q15_t)0x459Eu,
    (q15_t)0x4672u,    (q15_t)0x4746u,    (q15_t)0x481Bu,    (q15_t)0x48EFu,
    (q15_t)0x49C3u,    (q15_t)0x4A97u,    (q15_t)0x4B6Bu,    (q15_t)0x4C3Fu,
    (q15_t)0x4D14u,    (q15_t)0x4DE8u,    (q15_t)0x4EBCu,    (q15_t)0x4F90u,
    (q15_t)0x5064u,    (q15_t)0x5138u,    (q15_t)0x520Du,    (q15_t)0x52E1u,
    (q15_t)0x53B5u,    (q15_t)0x5489u,    (q15_t)0x555Du,    (q15_t)0x5631u,
    (q15_t)0x5706u,    (q15_t)0x57DAu,    (q15_t)0x58AEu,    (q15_t)0x5982u,
    (q15_t)0x5A56u,    (q15_t)0x5B2Au,    (q15_t)0x5BFFu,    (q15_t)0x5CD3u,
    (q15_t)0x5DA7u,    (q15_t)0x5E7Bu,    (q15_t)0x5F4Fu,    (q15_t)0x6023u,
    (q15_t)0x60F8u,    (q15_t)0x61CCu,    (q15_t)0x62A0u,    (q15_t)0x6374u,
    (q15_t)0x6448u,    (q15_t)0x651Cu,    (q15_t)0x65F1u,    (q15_t)0x66C5u,
    (q15_t)0x6799u,    (q15_t)0x686Du,    (q15_t)0x6941u,    (q15_t)0x6A15u,
    (q15_t)0x6AEAu,    (q15_t)0x6BBEu,    (q15_t)0x6C92u,    (q15_t)0x6D66u,
    (q15_t)0x6E3Au,    (q15_t)0x6F0Eu,    (q15_t)0x6FE3u,    (q15_t)0x70B7u,
    (q15_t)0x718Bu,    (q15_t)0x725Fu,    (q15_t)0x7333u,
};

static const q15_t q15_maxpos[] = {
    (q15_t)0x7FFEu,    (q15_t)0x0001u,    (q15_t)0x7FFEu,    (q15_t)0x0001u,
    (q15_t)0x7FFEu,    (q15_t)0x0001u,    (q15_t)0x7FFEu,    (q15_t)0x0001u,
    (q15_t)0x7FFEu,    (q15_t)0x0001u,    (q15_t)0x7FFEu,    (q15_t)0x0001u,
    (q15_t)0x7FFEu,    (q15_t)0x0001u,    (q15_t)0x7FFEu,    (q15_t)0x0001u,
    (q15_t)0x7FFEu,
};

static const q15_t q15_maxneg[] = {
    (q15_t)0x8001u,    (q15_t)0xFFFFu,    (q15_t)0x8001u,    (q15_t)0xFFFFu,
    (q15_t)0x8001u,    (q15_t)0xFFFFu,    (q15_t)0x8001u,    (q15_t)0xFFFFu,
    (q15_t)0x8001u,    (q15_t)0xFFFFu,    (q15_t)0x8001u,    (q15_t)0xFFFFu,
    (q15_t)0x8001u,    (q15_t)0xFFFFu,    (q15_t)0x8001u,    (q15_t)0xFFFFu,
    (q15_t)0x8001u,
};

static const q15_t q15_maxneg2[] = {
    (q15_t)0x8000u,    (q15_t)0xFFFEu,    (q15_t)0x8000u,    (q15_t)0xFFFEu,
    (q15_t)0x8000u,    (q15_t)0xFFFEu,    (q15_t)0x8000u,    (q15_t)0xFFFEu,
    (q15_t)0x8000u,    (q15_t)0xFFFEu,    (q15_t)0x8000u,    (q15_t)0xFFFEu,
    (q15_t)0x8000u,    (q15_t)0xFFFEu,    (q15_t)0x8000u,    (q15_t)0xFFFEu,
    (q15_t)0x8000u,
};

static const uint16_t q15_bit1[] = {
    (uint16_t)0xF97Du,    (uint16_t)0x7E98u,    (uint16_t)0xE83Eu,    (uint16_t)0x9006u,
    (uint16_t)0x8ECFu,    (uint16_t)0x82B2u,    (uint16_t)0x873Cu,    (uint16_t)0xE6D0u,
    (uint16_t)0x42C6u,    (uint16_t)0xA110u,    (uint16_t)0x7D1Eu,    (uint16_t)0x0CDCu,
    (uint16_t)0xB6CCu,    (uint16_t)0xB5A5u,    (uint16_t)0xB245u,    (uint16_t)0xC19Au,
    (uint16_t)0x7B95u,    (uint16_t)0xB857u,    (uint16_t)0x3E23u,    (uint16_t)0xECC1u,
    (uint16_t)0x8AC4u,    (uint16_t)0xA9A0u,    (uint16_t)0x7CFFu,
};

static const uint16_t q15_bit2[] = {
    (uint16_t)0xABDBu,    (uint16_t)0x927Fu,    (uint16_t)0x5D5Du,    (uint16_t)0xF0CCu,
    (uint16_t)0x90C8u,    (uint16_t)0xE1A9u,    (uint16_t)0xCACFu,    (uint16_t)0x2B30u,
    (uint16_t)0xEDC4u,    (uint16_t)0x5AB6u,    (uint16_t)0x7E72u,    (uint16_t)0x7867u,
    (uint16_t)0x0B8Au,    (uint16_t)0x0E28u,    (uint16_t)0x6421u,    (uint16_t)0x5673u,
    (uint16_t)0x8AE7u,    (uint16_t)0xF8DCu,    (uint16_t)0x45A3u,    (uint16_t)0xF95Du,
    (uint16_t)0x4B42u,    (uint16_t)0xB9A3u,    (uint16_t)0x7FE6u,
};

static const q15_t q15_ref[] = {
    (q15_t)0x0827u,    (q15_t)0xCC5Eu,    (q15_t)0x934Fu,    (q15_t)0xEE23u,
    (q15_t)0xC137u,    (q15_t)0x0899u,    (q15_t)0x7FFFu,    (q15_t)0xE647u,
    (q15_t)0x48C7u,    (q15_t)0x7FFFu,    (q15_t)0x1B32u,    (q15_t)0xFFE7u,
    (q15_t)0x5956u,    (q15_t)0x1AD7u,    (q15_t)0x2D96u,    (q15_t)0x8000u,
    (q15_t)0xB553u,    (q15_t)0xE7E9u,    (q15_t)0xC2A3u,    (q15_t)0xC994u,
    (q15_t)0x7FFFu,    (q15_t)0x072Au,    (q15_t)0x8000u,    (q15_t)0x14ACu,
    (q15_t)0x5AB8u,    (q15_t)0xEF3Bu,    (q15_t)0xEE37u,    (q15_t)0x2B7Eu,
    (q15_t)0x14D1u,    (q15_t)0x924Eu,    (q15_t)0x300Bu,    (q15_t)0xB957u,
    (q15_t)0x0784u,    (q15_t)0xFB26u,    (q15_t)0x393Eu,    (q15_t)0xAE6Eu,
    (q15_t)0x34D3u,    (q15_t)0xE22Du,    (q15_t)0x81C0u,    (q15_t)0xDB98u,
    (q15_t)0x8000u,    (q15_t)0xA6F2u,    (q15_t)0x0992u,    (q15_t)0x6417u,
    (q15_t)0x7FFFu,    (q15_t)0xE5E2u,    (q15_t)0x53BFu,    (q15_t)0x2543u,
    (q15_t)0xEB65u,    (q15_t)0x34D3u,    (q15_t)0xD9DFu,    (q15_t)0xFF06u,
    (q15_t)0x154Eu,    (q15_t)0x8000u,    (q15_t)0x2B58u,    (q15_t)0x2AACu,
    (q15_t)0xD839u,    (q15_t)0x03E6u,    (q15_t)0xBF7Bu,    (q15_t)0x0477u,
    (q15_t)0x05C7u,    (q15_t)0x485Fu,    (q15_t)0xA7B9u,    (q15_t)0x8000u,
    (q15_t)0x2518u,    (q15_t)0x0C26u,    (q15_t)0x148Au,    (q15_t)0x1E53u,
    (q15_t)0xF910u,    (q15_t)0x438Du,    (q15_t)0x7FFFu,    (q15_t)0xF2ADu,
    (q15_t)0x1EFAu,    (q15_t)0x21E0u,    (q15_t)0xDFF5u,    (q15_t)0x9A50u,
    (q15_t)0xF7C9u,    (q15_t)0xE3A5u,    (q15_t)0xCB41u,    (q15_t)0xD4ADu,
    (q15_t)0xE96Cu,    (q15_t)0x8000u,    (q15_t)0xC529u,    (q15_t)0xBE46u,
    (q15_t)0xC3F5u,    (q15_t)0xDB5Du,    (q15_t)0x19C2u,    (q15_t)0x12B5u,
    (q15_t)0xBB27u,    (q15_t)0xF5A7u,    (q15_t)0x2EFAu,    (q15_t)0x4038u,
    (q15_t)0xE8FFu,    (q15_t)0x7159u,    (q15_t)0x2304u,    (q15_t)0xEB4Du,
    (q15_t)0xE317u,    (q15_t)0xD611u,    (q15_t)0xAB06u,    (q15_t)0x681Cu,
    (q15_t)0x0825u,    (q15_t)0x022Bu,    (q15_t)0xED53u,    (q15_t)0x402Fu,
    (q15_t)0x064Du,    (q15_t)0x3A86u,    (q15_t)0x6050u,    (q15_t)0xD5CDu,
    (q15_t)0x5E68u,    (q15_t)0xCA23u,    (q15_t)0xBAFFu,    (q15_t)0xBC32u,
    (q15_t)0xD013u,    (q15_t)0x9277u,    (q15_t)0x400Eu,    (q15_t)0xD61Du,
    (q15_t)0x03BCu,    (q15_t)0xC50Fu,    (q15_t)0xC086u,    (q15_t)0x00EBu,
    (q15_t)0xDBA8u,    (q15_t)0xCD6Fu,    (q15_t)0x15A4u,    (q15_t)0xD051u,
    (q15_t)0xB0E7u,    (q15_t)0x2EAAu,    (q15_t)0x48CCu,    (q15_t)0xA5ACu,
    (q15_t)0xFDACu,    (q15_t)0x49EFu,    (q15_t)0x8000u,    (q15_t)0xB044u,
    (q15_t)0x0250u,    (q15_t)0x560Cu,    (q15_t)0xE6C4u,    (q15_t)0x1F2Fu,
    (q15_t)0x5648u,    (q15_t)0x678Bu,    (q15_t)0x429Au,    (q15_t)0xEB67u,
    (q15_t)0x1F37u,    (q15_t)0x9F3Bu,    (q15_t)0x8458u,    (q15_t)0xC609u,
    (q15_t)0x801Au,    (q15_t)0x2012u,    (q15_t)0xA525u,    (q15_t)0xE477u,
    (q15_t)0x0B71u,    (q15_t)0x38BFu,    (q15_t)0xBD86u,    (q15_t)0xA794u,
    (q15_t)0x9E23u,    (q15_t)0xE970u,    (q15_t)0xDDE1u,    (q15_t)0x9C84u,
    (q15_t)0xC47Bu,    (q15_t)0xF5F8u,    (q15_t)0xFF2Eu,    (q15_t)0x4237u,
    (q15_t)0x2851u,    (q15_t)0xCEBFu,    (q15_t)0xAD15u,    (q15_t)0xDFEDu,
    (q15_t)0x7FFFu,    (q15_t)0x6936u,    (q15_t)0x0D7Au,    (q15_t)0x8000u,
    (q15_t)0xAED7u,    (q15_t)0xC178u,    (q15_t)0xFF54u,    (q15_t)0xA172u,
    (q15_t)0xF2C4u,    (q15_t)0xC859u,    (q15_t)0xD6B9u,    (q15_t)0xC0A1u,
    (q15_t)0x2BAAu,    (q15_t)0x08C0u,    (q15_t)0x0455u,    (q15_t)0xEC63u,
    (q15_t)0xD6C4u,    (q15_t)0x7FFFu,    (q15_t)0xD6FFu,    (q15_t)0x01B8u,
    (q15_t)0xD44Eu,    (q15_t)0x9968u,    (q15_t)0x1F62u,    (q15_t)0x9693u,
    (q15_t)0xD8BEu,    (q15_t)0x146Eu,    (q15_t)0x07E9u,    (q15_t)0x0143u,
    (q15_t)0xF12Fu,    (q15_t)0x7075u,    (q15_t)0xC565u,    (q15_t)0x9AE2u,
    (q15_t)0x3BDEu,    (q15_t)0x4D58u,    (q15_t)0x1554u,    (q15_t)0xF567u,
    (q15_t)0x2F43u,    (q15_t)0xD297u,    (q15_t)0xE5E5u,    (q15_t)0x8000u,
    (q15_t)0xFC4Bu,    (q15_t)0xCF81u,    (q15_t)0x3A3Cu,    (q15_t)0x8158u,
    (q15_t)0x2F06u,    (q15_t)0x4B8Eu,    (q15_t)0x75F2u,    (q15_t)0x2351u,
    (q15_t)0x65D3u,    (q15_t)0xDB3Eu,    (q15_t)0x0417u,    (q15_t)0x0145u,
    (q15_t)0x0623u,    (q15_t)0x3017u,    (q15_t)0x06EEu,    (q15_t)0xCC6Fu,
    (q15_t)0xA1EDu,    (q15_t)0x854Fu,    (q15_t)0xC262u,    (q15_t)0x0C47u,
    (q15_t)0x8000u,    (q15_t)0x095Cu,    (q15_t)0x5447u,    (q15_t)0x1513u,
    (q15_t)0x6365u,    (q15_t)0x5D0Cu,    (q15_t)0xFCC9u,    (q15_t)0x5886u,
    (q15_t)0xF197u,    (q15_t)0xCC83u,    (q15_t)0x3ABCu,    (q15_t)0xD191u,
    (q15_t)0x2DD9u,    (q15_t)0x3BC2u,    (q15_t)0x598Cu,    (q15_t)0x76B7u,
    (q15_t)0xA61Eu,    (q15_t)0xCB7Eu,    (q15_t)0xA51Fu,    (q15_t)0x21D4u,
    (q15_t)0x3BCDu,    (q15_t)0x05D8u,    (q15_t)0xDC10u,    (q15_t)0xC6EEu,
    (q15_t)0x78B7u,    (q15_t)0x8000u,    (q15_t)0xCBB0u,    (q15_t)0x92E1u,
    (q15_t)0xB971u,    (q15_t)0x8000u,    (q15_t)0xEB5Fu,    (q15_t)0x4ED1u,
};

static const q63_t q15_refdot[] = {
    (q63_t)0x000000001C245239ULL,
};

static const uint16_t q15_refand[] = {
    (uint16_t)0xA959u,    (uint16_t)0x1218u,    (uint16_t)0x481Cu,    (uint16_t)0x9004u,
    (uint16_t)0x80C8u,    (uint16_t)0x80A0u,    (uint16_t)0x820Cu,    (uint16_t)0x2210u,
    (uint16_t)0x40C4u,    (uint16_t)0x0010u,    (uint16_t)0x7C12u,    (uint16_t)0x0844u,
    (uint16_t)0x0288u,    (uint16_t)0x0420u,    (uint16_t)0x2001u,    (uint16_t)0x4012u,
    (uint16_t)0x0A85u,    (uint16_t)0xB854u,    (uint16_t)0x0423u,    (uint16_t)0xE841u,
    (uint16_t)0x0A40u,    (uint16_t)0xA9A0u,    (uint16_t)0x7CE6u,
};

static const q31_t q31_input1[] = {
    (q31_t)0xFAB7BE89u,    (q31_t)0xD0A53F53u,    (q31_t)0x1A111E21u,    (q31_t)0x49953816u,
    (q31_t)0x039D1FD3u,    (q31_t)0xD15A0327u,    (q31_t)0x1A0C9993u,    (q31_t)0xC11799B2u,
    (q31_t)0x5FF34F43u,    (q31_t)0x2F1AAAD3u,    (q31_t)0xC253CA7Bu,    (q31_t)0xE07AE872u,
    (q31_t)0x2BA6A1A5u,    (q31_t)0xE72C367Eu,    (q31_t)0x095EB61Cu,    (q31_t)0x11B2C034u,
    (q31_t)0xC348EFDBu,    (q31_t)0xF61D0686u,    (q31_t)0x3D8F8865u,    (q31_t)0x02583C63u,
    (q31_t)0x421A42F1u,    (q31_t)0x47700CDBu,    (q31_t)0xF9C76EADu,    (q31_t)0x41934B18u,
    (q31_t)0xD8541E1Fu,    (q31_t)0xBF0E6064u,    (q31_t)0xF0CD84F3u,    (q31_t)0xE32E481Eu,
    (q31_t)0xEDCD8FAAu,    (q31_t)0x16CBA5C6u,    (q31_t)0xCC5D5A03u,    (q31_t)0x4A705300u,
    (q31_t)0xE029F9BEu,    (q31_t)0xD35E7614u,    (q31_t)0x1C73D288u,    (q31_t)0xF8F29B53u,
    (q31_t)0x02A059E3u,    (q31_t)0x9A7BBCC9u,    (q31_t)0x39C39102u,    (q31_t)0xE3BF944Au,
    (q31_t)0xF0A526E3u,    (q31_t)0xB08F1663u,    (q31_t)0x4FAD19C2u,    (q31_t)0xE4CEF118u,
    (q31_t)0xE7350F23u,    (q31_t)0xC64F1B53u,    (q31_t)0xEA13DD5Du,    (q31_t)0x0D202897u,
    (q31_t)0xF26A7EACu,    (q31_t)0x1F390903u,    (q31_t)0x04742117u,    (q31_t)0xDBF0142Bu,
    (q31_t)0x21C69D2Cu,    (q31_t)0xED29C807u,    (q31_t)0x1CA2D79Eu,    (q31_t)0xCB7324B6u,
    (q31_t)0x2D3AC862u,    (q31_t)0x47A212F5u,    (q31_t)0x05922A20u,    (q31_t)0x9FD4BDC5u,
    (q31_t)0x05BBA2EFu,    (q31_t)0x31929A7Fu,    (q31_t)0xED64FC90u,    (q31_t)0x0187E40Bu,
    (q31_t)0x3E79D6D5u,    (q31_t)0x35174F2Au,    (q31_t)0x0AB7A1FAu,    (q31_t)0xC730FEF6u,
    (q31_t)0xD205B519u,    (q31_t)0x2ACED497u,    (q31_t)0x149629BCu,    (q31_t)0x496AF8C9u,
    (q31_t)0x072A0A97u,    (q31_t)0xE3584B0Du,    (q31_t)0x60B6CCACu,    (q31_t)0xC8282020u,
    (q31_t)0xF3E040D4u,    (q31_t)0x74151274u,    (q31_t)0x3B33B20Au,    (q31_t)0x295461DEu,
    (q31_t)0x9580056Eu,    (q31_t)0x5ED8128Au,    (q31_t)0xB3BA36FCu,    (q31_t)0xE782E074u,
    (q31_t)0xD201785Du,    (q31_t)0x56075012u,    (q31_t)0x02F41C39u,    (q31_t)0x280A17B1u,
    (q31_t)0x5BA1EC9Bu,    (q31_t)0x3DD79454u,    (q31_t)0x26F5E393u,    (q31_t)0xB99DE788u,
    (q31_t)0x184041E6u,    (q31_t)0x1843AB84u,    (q31_t)0x20739447u,    (q31_t)0xF6C45E87u,
    (q31_t)0xB414F760u,    (q31_t)0x42D4F39Au,    (q31_t)0x0246E933u,    (q31_t)0x1474FF77u,
    (q31_t)0xEA54E9E5u,    (q31_t)0xE089C52Du,    (q31_t)0x1ED61839u,    (q31_t)0x02B4ABE6u,
    (q31_t)0x1D6A7895u,    (q31_t)0xF8DC8A57u,    (q31_t)0x174AB327u,    (q31_t)0xD1B60E6Du,
    (q31_t)0xF06DAD72u,    (q31_t)0xDC4DF87Au,    (q31_t)0xFCC33845u,    (q31_t)0xDF56EAA7u,
    (q31_t)0x2AF56086u,    (q31_t)0xF4BA1686u,    (q31_t)0x31DBFBB8u,    (q31_t)0xEC519D45u,
    (q31_t)0xC869501Du,    (q31_t)0x32ACDDF0u,    (q31_t)0xCEE42B32u,    (q31_t)0x5F1CA782u,
    (q31_t)0xE9C295D2u,    (q31_t)0xFB159839u,    (q31_t)0x0BF034FBu,    (q31_t)0xC602333Au,
    (q31_t)0x2B7C9F68u,    (q31_t)0x3F2915ADu,    (q31_t)0x0723B081u,    (q31_t)0x3DA20555u,
    (q31_t)0xE9063F46u,    (q31_t)0xCF83C9F3u,    (q31_t)0x2087CB56u,    (q31_t)0x1434EFE2u,
    (q31_t)0xFD5001B9u,    (q31_t)0x53D3B0B7u,    (q31_t)0x044D3F8Fu,    (q31_t)0x09F2CFD5u,
    (q31_t)0xED9C70B2u,    (q31_t)0x3A6A2875u,    (q31_t)0x64150B08u,    (q31_t)0x0DC63106u,
    (q31_t)0xD7CDB3CAu,    (q31_t)0x0109E1A7u,    (q31_t)0xE728DD93u,    (q31_t)0xEAAEF9D0u,
    (q31_t)0xF37E2FEEu,    (q31_t)0x3944E08Du,    (q31_t)0x12D442B3u,    (q31_t)0x27451C2Cu,
    (q31_t)0x1E952599u,    (q31_t)0x087125C1u,    (q31_t)0x0EE3B9E6u,    (q31_t)0xDBA281ACu,
    (q31_t)0xD91FF3D4u,    (q31_t)0xD7827B49u,    (q31_t)0x0156172Au,    (q31_t)0x1497EC12u,
    (q31_t)0x2EC0F116u,    (q31_t)0x0732C6B0u,    (q31_t)0x21FA3074u,    (q31_t)0x29E8EEE4u,
    (q31_t)0xF438F972u,    (q31_t)0x2B6083E6u,    (q31_t)0xD3183ACFu,    (q31_t)0x1139B2A3u,
    (q31_t)0x994730B6u,    (q31_t)0x04686EB7u,    (q31_t)0xFB2A8BE6u,    (q31_t)0xE4001E4Fu,
    (q31_t)0x326D1A8Du,    (q31_t)0x12444A2Eu,    (q31_t)0xC2D02A01u,    (q31_t)0x5ABAF2CFu,
    (q31_t)0xF9B0578Au,    (q31_t)0x38BBF29Au,    (q31_t)0xFFD6E55Au,    (q31_t)0xF93208A8u,
    (q31_t)0xE1793803u,    (q31_t)0x4DF77468u,    (q31_t)0x080DF39Bu,    (q31_t)0xCDBF0532u,
    (q31_t)0x0D097F49u,    (q31_t)0x09F21DE6u,    (q31_t)0xFECC9CD0u,    (q31_t)0xD3B19A9Au,
    (q31_t)0xDFCB383Fu,    (q31_t)0x9E2027FFu,    (q31_t)0x3949D876u,    (q31_t)0xC4501FA5u,
    (q31_t)0x263A70BFu,    (q31_t)0x30BF0DD2u,    (q31_t)0x202E838Bu,    (q31_t)0xF224F6BDu,
    (q31_t)0x38304013u,    (q31_t)0x48EE54B1u,    (q31_t)0x1A65946Au,    (q31_t)0xBAFA30A1u,
    (q31_t)0xAB283604u,    (q31_t)0xCFAFC5C6u,    (q31_t)0xB9FA6AD7u,    (q31_t)0x4D0A2DCBu,
    (q31_t)0xFD4680E8u,    (q31_t)0x7FFFFFFFu,    (q31_t)0x2D84CF3Fu,    (q31_t)0x265DA6E3u,
    (q31_t)0xF3561B3Du,    (q31_t)0xEF08A690u,    (q31_t)0xE2B7F2F0u,    (q31_t)0xDD4C2DF4u,
    (q31_t)0x166BD24Eu,    (q31_t)0x3478C4A7u,    (q31_t)0x21D0339Cu,    (q31_t)0x35AB59A8u,
    (q31_t)0xD4C328B6u,    (q31_t)0xF04166CFu,    (q31_t)0x3BB12F73u,    (q31_t)0x53FA8D72u,
    (q31_t)0x64EC1557u,    (q31_t)0x35CA36AEu,    (q31_t)0x1C4CC90Cu,    (q31_t)0x1BBEC121u,
    (q31_t)0xDDE3F0EAu,    (q31_t)0x35EFC713u,    (q31_t)0x39535A61u,    (q31_t)0x2CC5C0B9u,
    (q31_t)0x40D6DE42u,    (q31_t)0x07D6ED0Bu,    (q31_t)0x04F369EFu,    (q31_t)0xD1B33498u,
    (q31_t)0xB8F88BDCu,    (q31_t)0xEBB4F9B9u,    (q31_t)0x07A293FBu,    (q31_t)0x294230FEu,
    (q31_t)0xE9FF43EBu,    (q31_t)0x390EC222u,    (q31_t)0xC826C79Au,    (q31_t)0x154547EEu,
    (q31_t)0xEA6E8928u,    (q31_t)0xD3B57D9Cu,    (q31_t)0x08273AC4u,    (q31_t)0xED765FE0u,
    (q31_t)0xFB5BE6B2u,    (q31_t)0x3CB7DE50u,    (q31_t)0xF051FADEu,    (q31_t)0x036682C5u,
    (q31_t)0xD5EB8DE1u,    (q31_t)0x1B04132Au,    (q31_t)0x2FA26906u,    (q31_t)0x9DD3D8EFu,
    (q31_t)0x5ED1D048u,    (q31_t)0x007E6EA0u,    (q31_t)0xFF277C82u,    (q31_t)0xC7EB9D50u,
    (q31_t)0xE4F9F063u,    (q31_t)0xE5FCB076u,    (q31_t)0xD10265D4u,    (q31_t)0xFAB3D758u,
};

static const q31_t q31_input2[] = {
    (q31_t)0x3228AB4Au,    (q31_t)0x08D12D9Bu,    (q31_t)0x036CDE01u,    (q31_t)0xFBD88CAEu,
    (q31_t)0xD5CA97A9u,    (q31_t)0x8FAB3853u,    (q31_t)0x26C60070u,    (q31_t)0x101D4A07u,
    (q31_t)0xF224215Eu,    (q31_t)0xFAE412ECu,    (q31_t)0xD011C445u,    (q31_t)0xE50A01DBu,
    (q31_t)0x074B8D35u,    (q31_t)0x234664FAu,    (q31_t)0x0B54B238u,    (q31_t)0xED3365F8u,
    (q31_t)0xF7D23A24u,    (q31_t)0x1A971A67u,    (q31_t)0xF625D925u,    (q31_t)0x1A6EE013u,
    (q31_t)0x0BB5C931u,    (q31_t)0xF457A99Bu,    (q31_t)0x289031CEu,    (q31_t)0x0125556Au,
    (q31_t)0xD62E058Eu,    (q31_t)0xF95334F7u,    (q31_t)0xEA654168u,    (q31_t)0x0F4EE37Du,
    (q31_t)0x7FFFFFFFu,    (q31_t)0x1F81629Du,    (q31_t)0x17756F82u,    (q31_t)0x531972D5u,
    (q31_t)0xC1B57480u,    (q31_t)0xFED22EC5u,    (q31_t)0x0B569DACu,    (q31_t)0x061F53F4u,
    (q31_t)0x1ECF86DDu,    (q31_t)0x01286810u,    (q31_t)0x4F9A2B5Fu,    (q31_t)0xB8F8F02Du,
    (q31_t)0x3CC35D18u,    (q31_t)0xF0D15D66u,    (q31_t)0x39317AFBu,    (q31_t)0x0AABBD1Eu,
    (q31_t)0x19EAF304u,    (q31_t)0x3AFB4766u,    (q31_t)0x0282AEA1u,    (q31_t)0xF725E52Au,
    (q31_t)0xF9218486u,    (q31_t)0x1A9F5F6Bu,    (q31_t)0xF897252Du,    (q31_t)0x12BAA22Fu,
    (q31_t)0x2333307Eu,    (q31_t)0xD1792A50u,    (q31_t)0x24F1473Fu,    (q31_t)0x2397CDABu,
    (q31_t)0x2EAEA857u,    (q31_t)0xEC61C2D3u,    (q31_t)0x0672436Cu,    (q31_t)0x3C17F8B6u,
    (q31_t)0xEC5B68A0u,    (q31_t)0x0E75A335u,    (q31_t)0x129800D3u,    (q31_t)0xFFF531D2u,
    (q31_t)0xD8F8B7FCu,    (q31_t)0x05A3407Du,    (q31_t)0x10B662D9u,    (q31_t)0x320D47AFu,
    (q31_t)0xD493A97Du,    (q31_t)0x0F31CD6Au,    (q31_t)0x0BA9E8DDu,    (q31_t)0x6135AA7Cu,
    (q31_t)0xC71AFBCDu,    (q31_t)0x234AF3BFu,    (q31_t)0x34186CFBu,    (q31_t)0x25B17489u,
    (q31_t)0x1FF20A13u,    (q31_t)0x3CA8ADBBu,    (q31_t)0xDB5014E1u,    (q31_t)0x1A0C1554u,
    (q31_t)0xD55638BBu,    (q31_t)0x02E9574Au,    (q31_t)0x168DEDFBu,    (q31_t)0x1F1D8B55u,
    (q31_t)0x24462792u,    (q31_t)0xF5AED760u,    (q31_t)0xE7C8A6BCu,    (q31_t)0x35FEB0D2u,
    (q31_t)0xC695C7B5u,    (q31_t)0xF314A324u,    (q31_t)0x1BFBCBC2u,    (q31_t)0xF9B794B7u,
    (q31_t)0x21C702B8u,    (q31_t)0x0D964141u,    (q31_t)0x60E12518u,    (q31_t)0x1F9CA0C3u,
    (q31_t)0x09CF72C6u,    (q31_t)0x05D069F2u,    (q31_t)0xC0576536u,    (q31_t)0xE2D1E286u,
    (q31_t)0xF38C584Eu,    (q31_t)0xF0EEAD2Fu,    (q31_t)0xFC3BDDD3u,    (q31_t)0x9C35F346u,
    (q31_t)0xE256D4CCu,    (q31_t)0xD04131BEu,    (q31_t)0xD1D7DE9Du,    (q31_t)0x107664B7u,
    (q31_t)0x0BA840AFu,    (q31_t)0x0EE7344Au,    (q31_t)0xF090687Fu,    (q31_t)0x11D7B6C5u,
    (q31_t)0x2D24C9AFu,    (q31_t)0x27A825AFu,    (q31_t)0xA73ED225u,    (q31_t)0x094B917Bu,
    (q31_t)0x1EEF7BF2u,    (q31_t)0x0440583Du,    (q31_t)0x0B8A0664u,    (q31_t)0xD992DCD6u,
    (q31_t)0x0745A19Du,    (q31_t)0x4A7A1615u,    (q31_t)0xDB2275D5u,    (q31_t)0x359DF826u,
    (q31_t)0xC5DA5B5Au,    (q31_t)0xD0B36FBBu,    (q31_t)0x0117A598u,    (q31_t)0x190B580Au,
    (q31_t)0x1941A7A3u,    (q31_t)0x1839AC8Au,    (q31_t)0xDC2F19F9u,    (q31_t)0x9ECAD0B5u,
    (q31_t)0xA5DC11E7u,    (q31_t)0x12FC2DA3u,    (q31_t)0x2C528695u,    (q31_t)0xFB08B205u,
    (q31_t)0xD02A1E82u,    (q31_t)0xE902806Cu,    (q31_t)0xC7936B43u,    (q31_t)0xF3B13B31u,
    (q31_t)0x183E6EA5u,    (q31_t)0xEE80B869u,    (q31_t)0xF190A8AEu,    (q31_t)0xFD8D7122u,
    (q31_t)0x321EC3A2u,    (q31_t)0x056ECA59u,    (q31_t)0xD40497F0u,    (q31_t)0xD94844E1u,
    (q31_t)0xC72FB3F9u,    (q31_t)0x0E35E2D6u,    (q31_t)0x0CB81CF2u,    (q31_t)0x297F90A0u,
    (q31_t)0x12D659D5u,    (q31_t)0x40090C19u,    (q31_t)0x340A218Au,    (q31_t)0xBF144EB9u,
    (q31_t)0x098ADEEDu,    (q31_t)0xFEC2EE21u,    (q31_t)0x0133901Cu,    (q31_t)0x2D2EBD9Fu,
    (q31_t)0xE1F92964u,    (q31_t)0xFA040017u,    (q31_t)0xD9621437u,    (q31_t)0x061CE050u,
    (q31_t)0x40FE21B8u,    (q31_t)0xF52D6EA6u,    (q31_t)0xDE440512u,    (q31_t)0x3D130A92u,
    (q31_t)0xFF8F0CF8u,    (q31_t)0xC9ED070Bu,    (q31_t)0xC5C386A7u,    (q31_t)0x01F5CFA7u,
    (q31_t)0xD2FD8196u,    (q31_t)0xE5FA641Fu,    (q31_t)0x24242CA2u,    (q31_t)0xE551E61Au,
    (q31_t)0x0E80778Cu,    (q31_t)0xB7E53D79u,    (q31_t)0x0E650887u,    (q31_t)0xF0494969u,
    (q31_t)0x49A105A7u,    (q31_t)0x0B0A1A5Eu,    (q31_t)0xCBC066ADu,    (q31_t)0x1C7AD83Eu,
    (q31_t)0x48159C1Bu,    (q31_t)0xEDB9D6B1u,    (q31_t)0xF19E1F72u,    (q31_t)0xF8ED7CE2u,
    (q31_t)0x287DFCF8u,    (q31_t)0x1A6045D7u,    (q31_t)0xE406EC66u,    (q31_t)0x377E7BB0u,
    (q31_t)0x26F9A438u,    (q31_t)0x01DC6D86u,    (q31_t)0x0BEBE596u,    (q31_t)0xE9365226u,
    (q31_t)0xD74C6CC8u,    (q31_t)0xF7D13297u,    (q31_t)0x35495CCDu,    (q31_t)0xD78ECBB2u,
    (q31_t)0x41C2F13Cu,    (q31_t)0x1A975ED5u,    (q31_t)0x24441E66u,    (q31_t)0xF8863F46u,
    (q31_t)0xA7D0B566u,    (q31_t)0x00368BA6u,    (q31_t)0xDDD23D9Au,    (q31_t)0xE1D3AC7Du,
    (q31_t)0x1394A08Bu,    (q31_t)0x04AD895Fu,    (q31_t)0xDE6CBDB5u,    (q31_t)0x3051D96Au,
    (q31_t)0x160E70A7u,    (q31_t)0xDA15485Du,    (q31_t)0x48481702u,    (q31_t)0x1CD76AF9u,
    (q31_t)0x02AB26C7u,    (q31_t)0xF00BA0CDu,    (q31_t)0xE3957590u,    (q31_t)0xEC8BBD0Du,
    (q31_t)0x2936C1B2u,    (q31_t)0xFCD9A94Bu,    (q31_t)0xFC9E4ACCu,    (q31_t)0xE1D46FE7u,
    (q31_t)0x02F16893u,    (q31_t)0x2760228Bu,    (q31_t)0x0D181A3Du,    (q31_t)0x1A4800F9u,
    (q31_t)0xF6812E26u,    (q31_t)0x126E6871u,    (q31_t)0xF9B78C6Fu,    (q31_t)0x14C6AD15u,
    (q31_t)0x28C36383u,    (q31_t)0x8D830F97u,    (q31_t)0xFA9FB38Fu,    (q31_t)0x4185E31Cu,
    (q31_t)0xF1B109BFu,    (q31_t)0x8D61957Fu,    (q31_t)0x0FD0152Au,    (q31_t)0x0223ECF6u,
    (q31_t)0x29D5287Fu,    (q31_t)0xF251E518u,    (q31_t)0xDA439FFAu,    (q31_t)0xD349568Au,
    (q31_t)0x06F6A33Du,    (q31_t)0x195EE1B6u,    (q31_t)0x11B79672u,    (q31_t)0xCA24A284u,
    (q31_t)0x0C96014Bu,    (q31_t)0x0F3964EDu,    (q31_t)0x101D4139u,    (q31_t)0xD3D5AA7Eu,
    (q31_t)0x26915EECu,    (q31_t)0x01A04B4Fu,    (q31_t)0x32F6444Fu,    (q31_t)0xFEADB99Au,
};

static const q31_t q31_inputrand[] = {
    (q31_t)0x229D1A17u,    (q31_t)0x1B4B61EAu,    (q31_t)0x07281F85u,    (q31_t)0x2AAAAAABu,
    (q31_t)0x08255585u,    (q31_t)0xEE55B1DDu,    (q31_t)0xECDA8C68u,    (q31_t)0x16EC051Du,
    (q31_t)0x050B7554u,
};

static const q31_t q31_inputclip[] = {
    (q31_t)0x8CCCCCCDu,    (q31_t)0x8DAA89D1u,    (q31_t)0x8E8846D5u,    (q31_t)0x8F6603DAu,
    (q31_t)0x9043C0DEu,    (q31_t)0x91217DE2u,    (q31_t)0x91FF3AE6u,    (q31_t)0x92DCF7EAu,
    (q31_t)0x93BAB4EFu,    (q31_t)0x949871F3u,    (q31_t)0x95762EF7u,    (q31_t)0x9653EBFBu,
    (q31_t)0x9731A900u,    (q31_t)0x980F6604u,    (q31_t)0x98ED2308u,    (q31_t)0x99CAE00Cu,
    (q31_t)0x9AA89D11u,    (q31_t)0x9B865A15u,    (q31_t)0x9C641719u,    (q31_t)0x9D41D41Du,
    (q31_t)0x9E1F9121u,    (q31_t)0x9EFD4E26u,    (q31_t)0x9FDB0B2Au,    (q31_t)0xA0B8C82Eu,
    (q31_t)0xA1968532u,    (q31_t)0xA2744237u,    (q31_t)0xA351FF3Bu,    (q31_t)0xA42FBC3Fu,
    (q31_t)0xA50D7943u,    (q31_t)0xA5EB3648u,    (q31_t)0xA6C8F34Cu,    (q31_t)0xA7A6B050u,
    (q31_t)0xA8846D54u,    (q31_t)0xA9622A59u,    (q31_t)0xAA3FE75Du,    (q31_t)0xAB1DA461u,
    (q31_t)0xABFB6165u,    (q31_t)0xACD91E69u,    (q31_t)0xADB6DB6Eu,    (q31_t)0xAE949872u,
    (q31_t)0xAF725576u,    (q31_t)0xB050127Au,    (q31_t)0xB12DCF7Fu,    (q31_t)0xB20B8C83u,
    (q31_t)0xB2E94987u,    (q31_t)0xB3C7068Bu,    (q31_t)0xB4A4C390u,    (q31_t)0xB5828094u,
    (q31_t)0xB6603D98u,    (q31_t)0xB73DFA9Cu,    (q31_t)0xB81BB7A1u,    (q31_t)0xB8F974A5u,
    (q31_t)0xB9D731A9u,    (q31_t)0xBAB4EEADu,    (q31_t)0xBB92ABB1u,    (q31_t)0xBC7068B6u,
    (q31_t)0xBD4E25BAu,    (q31_t)0xBE2BE2BEu,    (q31_t)0xBF099FC2u,    (q31_t)0xBFE75CC7u,
    (q31_t)0xC0C519CBu,    (q31_t)0xC1A2D6CFu,    (q31_t)0xC28093D3u,    (q31_t)0xC35E50D8u,
    (q31_t)0xC43C0DDCu,    (q31_t)0xC519CAE0u,    (q31_t)0xC5F787E4u,    (q31_t)0xC6D544E9u,
    (q31_t)0xC7B301EDu,    (q31_t)0xC890BEF1u,    (q31_t)0xC96E7BF5u,    (q31_t)0xCA4C38F9u,
    (q31_t)0xCB29F5FEu,    (q31_t)0xCC07B302u,    (q31_t)0xCCE57006u,    (q31_t)0xCDC32D0Au,
    (q31_t)0xCEA0EA0Fu,    (q31_t)0xCF7EA713u,    (q31_t)0xD05C6417u,    (q31_t)0xD13A211Bu,
    (q31_t)0xD217DE20u,    (q31_t)0xD2F59B24u,    (q31_t)0xD3D35828u,    (q31_t)0xD4B1152Cu,
    (q31_t)0xD58ED231u,    (q31_t)0xD66C8F35u,    (q31_t)0xD74A4C39u,    (q31_t)0xD828093Du,
    (q31_t)0xD905C641u,    (q31_t)0xD9E38346u,    (q31_t)0xDAC1404Au,    (q31_t)0xDB9EFD4Eu,
    (q31_t)0xDC7CBA52u,    (q31_t)0xDD5A7757u,    (q31_t)0xDE38345Bu,    (q31_t)0xDF15F15Fu,
    (q31_t)0xDFF3AE63u,    (q31_t)0xE0D16B68u,    (q31_t)0xE1AF286Cu,    (q31_t)0xE28CE570u,
    (q31_t)0xE36AA274u,    (q31_t)0xE4485F78u,    (q31_t)0xE5261C7Du,    (q31_t)0xE603D981u,
    (q31_t)0xE6E19685u,    (q31_t)0xE7BF5389u,    (q31_t)0xE89D108Eu,    (q31_t)0xE97ACD92u,
    (q31_t)0xEA588A96u,    (q31_t)0xEB36479Au,    (q31_t)0xEC14049Fu,    (q31_t)0xECF1C1A3u,
    (q31_t)0xEDCF7EA7u,    (q31_t)0xEEAD3BABu,    (q31_t)0xEF8AF8B0u,    (q31_t)0xF068B5B4u,
    (q31_t)0xF14672B8u,    (q31_t)0xF2242FBCu,    (q31_t)0xF301ECC0u,    (q31_t)0xF3DFA9C5u,
    (q31_t)0xF4BD66C9u,    (q31_t)0xF59B23CDu,    (q31_t)0xF678E0D1u,    (q31_t)0xF7569DD6u,
    (q31_t)0xF8345ADAu,    (q31_t)0xF91217DEu,    (q31_t)0xF9EFD4E2u,    (q31_t)0xFACD91E7u,
    (q31_t)0xFBAB4EEBu,    (q31_t)0xFC890BEFu,    (q31_t)0xFD66C8F3u,    (q31_t)0xFE4485F8u,
    (q31_t)0xFF2242FCu,    (q31_t)0x00000000u,    (q31_t)0x00DDBD04u,    (q31_t)0x01BB7A08u,
    (q31_t)0x0299370Du,    (q31_t)0x0376F411u,    (q31_t)0x0454B115u,    (q31_t)0x05326E19u,
    (q31_t)0x06102B1Eu,    (q31_t)0x06EDE822u,    (q31_t)0x07CBA526u,    (q31_t)0x08A9622Au,
    (q31_t)0x09871F2Fu,    (q31_t)0x0A64DC33u,    (q31_t)0x0B429937u,    (q31_t)0x0C20563Bu,
    (q31_t)0x0CFE1340u,    (q31_t)0x0DDBD044u,    (q31_t)0x0EB98D48u,    (q31_t)0x0F974A4Cu,
    (q31_t)0x10750750u,    (q31_t)0x1152C455u,    (q31_t)0x12308159u,    (q31_t)0x130E3E5Du,
    (q31_t)0x13EBFB61u,    (q31_t)0x14C9B866u,    (q31_t)0x15A7756Au,    (q31_t)0x1685326Eu,
    (q31_t)0x1762EF72u,    (q31_t)0x1840AC77u,    (q31_t)0x191E697Bu,    (q31_t)0x19FC267Fu,
    (q31_t)0x1AD9E383u,    (q31_t)0x1BB7A088u,    (q31_t)0x1C955D8Cu,    (q31_t)0x1D731A90u,
    (q31_t)0x1E50D794u,    (q31_t)0x1F2E9498u,    (q31_t)0x200C519Du,    (q31_t)0x20EA0EA1u,
    (q31_t)0x21C7CBA5u,    (q31_t)0x22A588A9u,    (q31_t)0x238345AEu,    (q31_t)0x246102B2u,
    (q31_t)0x253EBFB6u,    (q31_t)0x261C7CBAu,    (q31_t)0x26FA39BFu,    (q31_t)0x27D7F6C3u,
    (q31_t)0x28B5B3C7u,    (q31_t)0x299370CBu,    (q31_t)0x2A712DCFu,    (q31_t)0x2B4EEAD4u,
    (q31_t)0x2C2CA7D8u,    (q31_t)0x2D0A64DCu,    (q31_t)0x2DE821E0u,    (q31_t)0x2EC5DEE5u,
    (q31_t)0x2FA39BE9u,    (q31_t)0x308158EDu,    (q31_t)0x315F15F1u,    (q31_t)0x323CD2F6u,
    (q31_t)0x331A8FFAu,    (q31_t)0x33F84CFEu,    (q31_t)0x34D60A02u,    (q31_t)0x35B3C707u,
    (q31_t)0x3691840Bu,    (q31_t)0x376F410Fu,    (q31_t)0x384CFE13u,    (q31_t)0x392ABB17u,
    (q31_t)0x3A08781Cu,    (q31_t)0x3AE63520u,    (q31_t)0x3BC3F224u,    (q31_t)0x3CA1AF28u,
    (q31_t)0x3D7F6C2Du,    (q31_t)0x3E5D2931u,    (q31_t)0x3F3AE635u,    (q31_t)0x4018A339u,
    (q31_t)0x40F6603Eu,    (q31_t)0x41D41D42u,    (q31_t)0x42B1DA46u,    (q31_t)0x438F974Au,
    (q31_t)0x446D544Fu,    (q31_t)0x454B1153u,    (q31_t)0x4628CE57u,    (q31_t)0x47068B5Bu,
    (q31_t)0x47E4485Fu,    (q31_t)0x48C20564u,    (q31_t)0x499FC268u,    (q31_t)0x4A7D7F6Cu,
    (q31_t)0x4B5B3C70u,    (q31_t)0x4C38F975u,    (q31_t)0x4D16B679u,    (q31_t)0x4DF4737Du,
    (q31_t)0x4ED23081u,    (q31_t)0x4FAFED86u,    (q31_t)0x508DAA8Au,    (q31_t)0x516B678Eu,
    (q31_t)0x52492492u,    (q31_t)0x5326E197u,    (q31_t)0x54049E9Bu,    (q31_t)0x54E25B9Fu,
    (q31_t)0x55C018A3u,    (q31_t)0x569DD5A7u,    (q31_t)0x577B92ACu,    (q31_t)0x58594FB0u,
    (q31_t)0x59370CB4u,    (q31_t)0x5A14C9B8u,    (q31_t)0x5AF286BDu,    (q31_t)0x5BD043C1u,
    (q31_t)0x5CAE00C5u,    (q31_t)0x5D8BBDC9u,    (q31_t)0x5E697ACEu,    (q31_t)0x5F4737D2u,
    (q31_t)0x6024F4D6u,    (q31_t)0x6102B1DAu,    (q31_t)0x61E06EDFu,    (q31_t)0x62BE2BE3u,
    (q31_t)0x639BE8E7u,    (q31_t)0x6479A5EBu,    (q31_t)0x655762EFu,    (q31_t)0x66351FF4u,
    (q31_t)0x6712DCF8u,    (q31_t)0x67F099FCu,    (q31_t)0x68CE5700u,    (q31_t)0x69AC1405u,
    (q31_t)0x6A89D109u,    (q31_t)0x6B678E0Du,    (q31_t)0x6C454B11u,    (q31_t)0x6D230816u,
    (q31_t)0x6E00C51Au,    (q31_t)0x6EDE821Eu,    (q31_t)0x6FBC3F22u,    (q31_t)0x7099FC26u,
    (q31_t)0x7177B92Bu,    (q31_t)0x7255762Fu,    (q31_t)0x73333333u,
};

static const q31_t q31_maxpos[] = {
    (q31_t)0x7FFFFFFEu,    (q31_t)0x00000001u,    (q31_t)0x7FFFFFFEu,    (q31_t)0x00000001u,
    (q31_t)0x7FFFFFFEu,    (q31_t)0x00000001u,    (q31_t)0x7FFFFFFEu,    (q31_t)0x00000001u,
    (q31_t)0x7FFFFFFEu,
};

static const q31_t q31_maxneg[] = {
    (q31_t)0x80000001u,    (q31_t)0xFFFFFFFFu,    (q31_t)0x80000001u,    (q31_t)0xFFFFFFFFu,
    (q31_t)0x80000001u,    (q31_t)0xFFFFFFFFu,    (q31_t)0x80000001u,    (q31_t)0xFFFFFFFFu,
    (q31_t)0x80000001u,
};

static const q31_t q31_maxneg2[] = {
    (q31_t)0x80000000u,    (q31_t)0xFFFFFFFEu,    (q31_t)0x80000000u,    (q31_t)0xFFFFFFFEu,
    (q31_t)0x80000000u,    (q31_t)0xFFFFFFFEu,    (q31_t)0x80000000u,    (q31_t)0xFFFFFFFEu,
    (q31_t)0x80000000u,
};

static const uint32_t q31_bit1[] = {
    (uint32_t)0x4BCE8F92u,    (uint32_t)0xFF14D182u,    (uint32_t)0x434E2DD4u,    (uint32_t)0xB7FC2F59u,
    (uint32_t)0x048FA4A9u,    (uint32_t)0x038DCC83u,    (uint32_t)0x4ABEA434u,    (uint32_t)0xCF338938u,
    (uint32_t)0x0DC0A132u,    (uint32_t)0x12A999EFu,    (uint32_t)0x9E357213u,
};

static const uint32_t q31_bit2[] = {
    (uint32_t)0xA8B8FCB8u,    (uint32_t)0xEDCB517Du,    (uint32_t)0x434011BDu,    (uint32_t)0x40705DDAu,
    (uint32_t)0xF95571D7u,    (uint32_t)0xD4678EDBu,    (uint32_t)0x234AE04Fu,    (uint32_t)0x0939EF27u,
    (uint32_t)0xBDF4A6FEu,    (uint32_t)0xEC99DE65u,    (uint32_t)0x8735465Du,
};

static const q31_t q31_ref[] = {
    (q31_t)0x2CE069D3u,    (q31_t)0xD9766CEEu,    (q31_t)0x1D7DFC22u,    (q31_t)0x456DC4C5u,
    (q31_t)0xD967B77Cu,    (q31_t)0x80000000u,    (q31_t)0x40D29A03u,    (q31_t)0xD134E3B8u,
    (q31_t)0x521770A1u,    (q31_t)0x29FEBDBFu,    (q31_t)0x92658EC0u,    (q31_t)0xC584EA4Cu,
    (q31_t)0x32F22EDAu,    (q31_t)0x0A729B78u,    (q31_t)0x14B36855u,    (q31_t)0xFEE6262Cu,
    (q31_t)0xBB1B29FFu,    (q31_t)0x10B420EDu,    (q31_t)0x33B5618Au,    (q31_t)0x1CC71C75u,
    (q31_t)0x4DD00C22u,    (q31_t)0x3BC7B676u,    (q31_t)0x2257A07Bu,    (q31_t)0x42B8A082u,
    (q31_t)0xAE8223ADu,    (q31_t)0xB861955Bu,    (q31_t)0xDB32C65Bu,    (q31_t)0xF27D2B9Bu,
    (q31_t)0x6DCD8FAAu,    (q31_t)0x364D0863u,    (q31_t)0xE3D2C986u,    (q31_t)0x7FFFFFFFu,
    (q31_t)0xA1DF6E3Eu,    (q31_t)0xD230A4D9u,    (q31_t)0x27CA7034u,    (q31_t)0xFF11EF48u,
    (q31_t)0x216FE0C1u,    (q31_t)0x9BA424D9u,    (q31_t)0x7FFFFFFFu,    (q31_t)0x9CB88477u,
    (q31_t)0x2D6883FAu,    (q31_t)0xA16073CAu,    (q31_t)0x7FFFFFFFu,    (q31_t)0xEF7AAE36u,
    (q31_t)0x01200227u,    (q31_t)0x014A62B9u,    (q31_t)0xEC968BFEu,    (q31_t)0x04460DC1u,
    (q31_t)0xEB8C0333u,    (q31_t)0x39D8686Eu,    (q31_t)0xFD0B4644u,    (q31_t)0xEEAAB65Bu,
    (q31_t)0x44F9CDA9u,    (q31_t)0xBEA2F257u,    (q31_t)0x41941EDDu,    (q31_t)0xEF0AF262u,
    (q31_t)0x5BE970B9u,    (q31_t)0x3403D5C8u,    (q31_t)0x0C046D8Cu,    (q31_t)0xDBECB67Bu,
    (q31_t)0xF2170B8Fu,    (q31_t)0x40083DB4u,    (q31_t)0xFFFCFD63u,    (q31_t)0x017D15DDu,
    (q31_t)0x17728ED1u,    (q31_t)0x3ABA8FA7u,    (q31_t)0x1B6E04D3u,    (q31_t)0xF93E46A4u,
    (q31_t)0xA6995E96u,    (q31_t)0x3A00A202u,    (q31_t)0x20401299u,    (q31_t)0x7FFFFFFFu,
    (q31_t)0xCE450664u,    (q31_t)0x06A33ECCu,    (q31_t)0x7FFFFFFFu,    (q31_t)0xEDD994A9u,
    (q31_t)0x13D24AE7u,    (q31_t)0x7FFFFFFFu,    (q31_t)0x1683C6EBu,    (q31_t)0x43607732u,
    (q31_t)0x80000000u,    (q31_t)0x61C169D4u,    (q31_t)0xCA4824F6u,    (q31_t)0x06A06BC9u,
    (q31_t)0xF6479FEFu,    (q31_t)0x4BB62772u,    (q31_t)0xEABCC2F5u,    (q31_t)0x5E08C883u,
    (q31_t)0x2237B44Fu,    (q31_t)0x30EC3778u,    (q31_t)0x42F1AF55u,    (q31_t)0xB3557C3Fu,
    (q31_t)0x3A07449Fu,    (q31_t)0x25D9ECC5u,    (q31_t)0x7FFFFFFFu,    (q31_t)0x1660FF4Au,
    (q31_t)0xBDE46A26u,    (q31_t)0x48A55D8Cu,    (q31_t)0xC29E4E69u,    (q31_t)0xF746E1FCu,
    (q31_t)0xDDE14233u,    (q31_t)0xD178725Cu,    (q31_t)0x1B11F60Du,    (q31_t)0x9EEA9F2Du,
    (q31_t)0xFFC14D61u,    (q31_t)0xC91DBC16u,    (q31_t)0xE92291C4u,    (q31_t)0xE22C7324u,
    (q31_t)0xFC15EE22u,    (q31_t)0xEB352CC5u,    (q31_t)0xED53A0C4u,    (q31_t)0xF12EA16Cu,
    (q31_t)0x581A2A34u,    (q31_t)0x1C623C35u,    (q31_t)0xD91ACDDCu,    (q31_t)0xF59D2EC0u,
    (q31_t)0xE758CC10u,    (q31_t)0x36ED362Du,    (q31_t)0xDA6E3196u,    (q31_t)0x38AF8458u,
    (q31_t)0xF108376Fu,    (q31_t)0x458FAE4Eu,    (q31_t)0xE712AACFu,    (q31_t)0xFBA02B60u,
    (q31_t)0xF156FAC3u,    (q31_t)0x0FDC8568u,    (q31_t)0x083B5619u,    (q31_t)0x56AD5D5Eu,
    (q31_t)0x0247E6E9u,    (q31_t)0xE7BD767Du,    (q31_t)0xFCB6E54Fu,    (q31_t)0xB2FFC097u,
    (q31_t)0xA32C139Fu,    (q31_t)0x66CFDE5Au,    (q31_t)0x309FC624u,    (q31_t)0x04FB81DAu,
    (q31_t)0xBDC68F34u,    (q31_t)0x236CA8E1u,    (q31_t)0x2BA8764Bu,    (q31_t)0x01776C37u,
    (q31_t)0xF00C226Eu,    (q31_t)0xEF8A9A10u,    (q31_t)0xD8B98641u,    (q31_t)0xE83C6AF3u,
    (q31_t)0x259CF390u,    (q31_t)0x3EB3AAE6u,    (q31_t)0xE6D8DAA2u,    (q31_t)0x008D610Du,
    (q31_t)0xE5C4D992u,    (q31_t)0x16A70898u,    (q31_t)0x1B9BD6D8u,    (q31_t)0x0522124Cu,
    (q31_t)0xEBF64DAAu,    (q31_t)0x178B8763u,    (q31_t)0x356038B4u,    (q31_t)0xD3AC3ACBu,
    (q31_t)0x384BD003u,    (q31_t)0x05F5B4D1u,    (q31_t)0x232DC08Fu,    (q31_t)0x5717AC84u,
    (q31_t)0xD63222D7u,    (q31_t)0x256483FDu,    (q31_t)0xAC7A4F06u,    (q31_t)0x175692F3u,
    (q31_t)0xDA45526Eu,    (q31_t)0xF995DD5Du,    (q31_t)0xD96E90F9u,    (q31_t)0x211328E0u,
    (q31_t)0x31FC2785u,    (q31_t)0xDC315139u,    (q31_t)0x8893B0A7u,    (q31_t)0x5CB0C275u,
    (q31_t)0xCCADD920u,    (q31_t)0x1EB656B9u,    (q31_t)0x23FB11FCu,    (q31_t)0xDE83EEC2u,
    (q31_t)0xEFF9AF8Fu,    (q31_t)0x05DCB1E1u,    (q31_t)0x1672FC22u,    (q31_t)0xBE084E9Bu,
    (q31_t)0x56AA84F0u,    (q31_t)0x14FC3844u,    (q31_t)0xCA8D037Du,    (q31_t)0xF02C72D9u,
    (q31_t)0x27E0D45Au,    (q31_t)0x8BD9FEAFu,    (q31_t)0x2AE7F7E7u,    (q31_t)0xBD3D9C87u,
    (q31_t)0x4EB86DB7u,    (q31_t)0x4B1F53A8u,    (q31_t)0x04356FF1u,    (q31_t)0x29A3726Du,
    (q31_t)0x5F29E44Bu,    (q31_t)0x4ACAC236u,    (q31_t)0x26517A00u,    (q31_t)0xA43082C8u,
    (q31_t)0x8274A2CCu,    (q31_t)0xC780F85Eu,    (q31_t)0xEF43C7A4u,    (q31_t)0x2498F97Du,
    (q31_t)0x3F097224u,    (q31_t)0x7FFFFFFFu,    (q31_t)0x51C8EDA5u,    (q31_t)0x1EE3E629u,
    (q31_t)0x9B26D0A3u,    (q31_t)0xEF3F3236u,    (q31_t)0xC08A308Bu,    (q31_t)0xBF1FDA70u,
    (q31_t)0x2A0072D9u,    (q31_t)0x39264E06u,    (q31_t)0x003CF151u,    (q31_t)0x65FD3311u,
    (q31_t)0xEAD1995Du,    (q31_t)0xCA56AF2Cu,    (q31_t)0x7FFFFFFFu,    (q31_t)0x70D1F86Bu,
    (q31_t)0x67973C1Eu,    (q31_t)0x25D5D77Bu,    (q31_t)0xFFE23E9Cu,    (q31_t)0x084A7E2Du,
    (q31_t)0x071AB29Cu,    (q31_t)0x32C9705Fu,    (q31_t)0x35F1A52Du,    (q31_t)0x0E9A30A0u,
    (q31_t)0x43C846D5u,    (q31_t)0x2F370F96u,    (q31_t)0x120B842Bu,    (q31_t)0xEBFB3591u,
    (q31_t)0xAF79BA01u,    (q31_t)0xFE23622Au,    (q31_t)0x015A206Au,    (q31_t)0x3E08DE13u,
    (q31_t)0x12C2A76Fu,    (q31_t)0xC691D1B9u,    (q31_t)0xC2C67B29u,    (q31_t)0x56CB2B0Au,
    (q31_t)0xDC1F92E7u,    (q31_t)0x80000000u,    (q31_t)0x17F74FEEu,    (q31_t)0xEF9A4CD6u,
    (q31_t)0x25310F31u,    (q31_t)0x2F09C368u,    (q31_t)0xCA959AD8u,    (q31_t)0xD6AFD94Fu,
    (q31_t)0xDCE2311Eu,    (q31_t)0x3462F4E0u,    (q31_t)0x4159FF78u,    (q31_t)0x80000000u,
    (q31_t)0x6B67D193u,    (q31_t)0x0FB7D38Cu,    (q31_t)0x0F44BDBBu,    (q31_t)0x9BC147CEu,
    (q31_t)0x0B8B4F4Fu,    (q31_t)0xE79CFBC5u,    (q31_t)0x03F8AA24u,    (q31_t)0xF96190F2u,
};

static const q63_t q31_refdot[] = {
    (q63_t)0x0000035C709433ECULL,
};

static const uint32_t q31_refand[] = {
    (uint32_t)0x08888C90u,    (uint32_t)0xED005100u,    (uint32_t)0x43400194u,    (uint32_t)0x00700D58u,
    (uint32_t)0x00052081u,    (uint32_t)0x00058C83u,    (uint32_t)0x020AA004u,    (uint32_t)0x09318920u,
    (uint32_t)0x0DC0A032u,    (uint32_t)0x00899865u,    (uint32_t)0x86354211u,
};

static uint32_t min_u32(uint32_t a, uint32_t b) { return a < b ? a : b; }

static void touch_q63(q63_t value) { smoke_sink += value; }

static unsigned run_q7(void)
{
    q7_t out[256];
    uint8_t out_logical[256];
    q31_t dot = 0;
    unsigned count = 0;
    const uint32_t full = min_u32(ARRAY_SIZE(q7_input1), ARRAY_SIZE(q7_ref));
    const uint32_t logical_full = min_u32(ARRAY_SIZE(q7_bit1), ARRAY_SIZE(q7_refand));
    touch_q63((q63_t)q7_ref[0]);
    touch_q63((q63_t)q7_refdot[0]);
    touch_q63((q63_t)q7_refand[0]);
    riscv_add_q7(q7_input1, q7_input2, out, 15); count++;
    riscv_sub_q7(q7_input1, q7_input2, out, 15); count++;
    riscv_mult_q7(q7_input1, q7_input2, out, 15); count++;
    riscv_negate_q7(q7_input1, out, 15); count++;
    riscv_offset_q7(q7_input1, (q7_t)0x40u, out, 15); count++;
    riscv_scale_q7(q7_input1, (q7_t)0x40u, 0, out, 15); count++;
    riscv_dot_prod_q7(q7_input1, q7_input2, 15, &dot); touch_q63((q63_t)dot); count++;
    riscv_abs_q7(q7_input1, out, 15); count++;
    riscv_and_u8(q7_bit1, q7_bit2, out_logical, 15); count++;
    riscv_or_u8(q7_bit1, q7_bit2, out_logical, 15); count++;
    riscv_not_u8(q7_bit1, out_logical, 15); count++;
    riscv_xor_u8(q7_bit1, q7_bit2, out_logical, 15); count++;
    riscv_add_q7(q7_input1, q7_input2, out, 32); count++;
    riscv_sub_q7(q7_input1, q7_input2, out, 32); count++;
    riscv_mult_q7(q7_input1, q7_input2, out, 32); count++;
    riscv_negate_q7(q7_input1, out, 32); count++;
    riscv_offset_q7(q7_input1, (q7_t)0x40u, out, 32); count++;
    riscv_scale_q7(q7_input1, (q7_t)0x40u, 0, out, 32); count++;
    riscv_dot_prod_q7(q7_input1, q7_input2, 32, &dot); touch_q63((q63_t)dot); count++;
    riscv_abs_q7(q7_input1, out, 32); count++;
    riscv_and_u8(q7_bit1, q7_bit2, out_logical, 32); count++;
    riscv_or_u8(q7_bit1, q7_bit2, out_logical, 32); count++;
    riscv_not_u8(q7_bit1, out_logical, 32); count++;
    riscv_xor_u8(q7_bit1, q7_bit2, out_logical, 32); count++;
    riscv_add_q7(q7_input1, q7_input2, out, 47); count++;
    riscv_sub_q7(q7_input1, q7_input2, out, 47); count++;
    riscv_mult_q7(q7_input1, q7_input2, out, 47); count++;
    riscv_negate_q7(q7_input1, out, 47); count++;
    riscv_offset_q7(q7_input1, (q7_t)0x40u, out, 47); count++;
    riscv_scale_q7(q7_input1, (q7_t)0x40u, 0, out, 47); count++;
    riscv_dot_prod_q7(q7_input1, q7_input2, 47, &dot); touch_q63((q63_t)dot); count++;
    riscv_abs_q7(q7_input1, out, 47); count++;
    riscv_and_u8(q7_bit1, q7_bit2, out_logical, 47); count++;
    riscv_or_u8(q7_bit1, q7_bit2, out_logical, 47); count++;
    riscv_not_u8(q7_bit1, out_logical, 47); count++;
    riscv_xor_u8(q7_bit1, q7_bit2, out_logical, 47); count++;
    riscv_add_q7(q7_input1, q7_input2, out, full); count++;
    riscv_sub_q7(q7_input1, q7_input2, out, full); count++;
    riscv_mult_q7(q7_input1, q7_input2, out, full); count++;
    riscv_negate_q7(q7_input1, out, full); count++;
    riscv_offset_q7(q7_input1, (q7_t)0x40u, out, full); count++;
    riscv_scale_q7(q7_input1, (q7_t)0x40u, 0, out, full); count++;
    riscv_dot_prod_q7(q7_input1, q7_input2, full, &dot); touch_q63((q63_t)dot); count++;
    riscv_abs_q7(q7_input1, out, full); count++;
    riscv_shift_q7(q7_inputrand, 1, out, ARRAY_SIZE(q7_inputrand)); count++;
    riscv_clip_q7(q7_inputclip, out, (q7_t)0xC0u, (q7_t)0xF3u, ARRAY_SIZE(q7_inputclip)); count++;
    riscv_clip_q7(q7_inputclip, out, (q7_t)0xC0u, (q7_t)0x40u, ARRAY_SIZE(q7_inputclip)); count++;
    riscv_clip_q7(q7_inputclip, out, (q7_t)0x0Du, (q7_t)0x40u, ARRAY_SIZE(q7_inputclip)); count++;
    riscv_and_u8(q7_bit1, q7_bit2, out_logical, logical_full); count++;
    riscv_or_u8(q7_bit1, q7_bit2, out_logical, logical_full); count++;
    riscv_not_u8(q7_bit1, out_logical, logical_full); count++;
    riscv_xor_u8(q7_bit1, q7_bit2, out_logical, logical_full); count++;
    printf("RUN testing-smoke/BasicMaths/q7 calls=%u\n", count);
    return count;
}

static unsigned run_q15(void)
{
    q15_t out[256];
    uint16_t out_logical[256];
    q63_t dot = 0;
    unsigned count = 0;
    const uint32_t full = min_u32(ARRAY_SIZE(q15_input1), ARRAY_SIZE(q15_ref));
    const uint32_t logical_full = min_u32(ARRAY_SIZE(q15_bit1), ARRAY_SIZE(q15_refand));
    touch_q63((q63_t)q15_ref[0]);
    touch_q63((q63_t)q15_refdot[0]);
    touch_q63((q63_t)q15_refand[0]);
    riscv_add_q15(q15_input1, q15_input2, out, 7); count++;
    riscv_sub_q15(q15_input1, q15_input2, out, 7); count++;
    riscv_mult_q15(q15_input1, q15_input2, out, 7); count++;
    riscv_negate_q15(q15_input1, out, 7); count++;
    riscv_offset_q15(q15_input1, (q15_t)0x4000u, out, 7); count++;
    riscv_scale_q15(q15_input1, (q15_t)0x4000u, 0, out, 7); count++;
    riscv_dot_prod_q15(q15_input1, q15_input2, 7, &dot); touch_q63((q63_t)dot); count++;
    riscv_abs_q15(q15_input1, out, 7); count++;
    riscv_and_u16(q15_bit1, q15_bit2, out_logical, 7); count++;
    riscv_or_u16(q15_bit1, q15_bit2, out_logical, 7); count++;
    riscv_not_u16(q15_bit1, out_logical, 7); count++;
    riscv_xor_u16(q15_bit1, q15_bit2, out_logical, 7); count++;
    riscv_add_q15(q15_input1, q15_input2, out, 16); count++;
    riscv_sub_q15(q15_input1, q15_input2, out, 16); count++;
    riscv_mult_q15(q15_input1, q15_input2, out, 16); count++;
    riscv_negate_q15(q15_input1, out, 16); count++;
    riscv_offset_q15(q15_input1, (q15_t)0x4000u, out, 16); count++;
    riscv_scale_q15(q15_input1, (q15_t)0x4000u, 0, out, 16); count++;
    riscv_dot_prod_q15(q15_input1, q15_input2, 16, &dot); touch_q63((q63_t)dot); count++;
    riscv_abs_q15(q15_input1, out, 16); count++;
    riscv_and_u16(q15_bit1, q15_bit2, out_logical, 16); count++;
    riscv_or_u16(q15_bit1, q15_bit2, out_logical, 16); count++;
    riscv_not_u16(q15_bit1, out_logical, 16); count++;
    riscv_xor_u16(q15_bit1, q15_bit2, out_logical, 16); count++;
    riscv_add_q15(q15_input1, q15_input2, out, 23); count++;
    riscv_sub_q15(q15_input1, q15_input2, out, 23); count++;
    riscv_mult_q15(q15_input1, q15_input2, out, 23); count++;
    riscv_negate_q15(q15_input1, out, 23); count++;
    riscv_offset_q15(q15_input1, (q15_t)0x4000u, out, 23); count++;
    riscv_scale_q15(q15_input1, (q15_t)0x4000u, 0, out, 23); count++;
    riscv_dot_prod_q15(q15_input1, q15_input2, 23, &dot); touch_q63((q63_t)dot); count++;
    riscv_abs_q15(q15_input1, out, 23); count++;
    riscv_and_u16(q15_bit1, q15_bit2, out_logical, 23); count++;
    riscv_or_u16(q15_bit1, q15_bit2, out_logical, 23); count++;
    riscv_not_u16(q15_bit1, out_logical, 23); count++;
    riscv_xor_u16(q15_bit1, q15_bit2, out_logical, 23); count++;
    riscv_add_q15(q15_input1, q15_input2, out, full); count++;
    riscv_sub_q15(q15_input1, q15_input2, out, full); count++;
    riscv_mult_q15(q15_input1, q15_input2, out, full); count++;
    riscv_negate_q15(q15_input1, out, full); count++;
    riscv_offset_q15(q15_input1, (q15_t)0x4000u, out, full); count++;
    riscv_scale_q15(q15_input1, (q15_t)0x4000u, 0, out, full); count++;
    riscv_dot_prod_q15(q15_input1, q15_input2, full, &dot); touch_q63((q63_t)dot); count++;
    riscv_abs_q15(q15_input1, out, full); count++;
    riscv_shift_q15(q15_inputrand, 1, out, ARRAY_SIZE(q15_inputrand)); count++;
    riscv_clip_q15(q15_inputclip, out, (q15_t)0xC000u, (q15_t)0xF333u, ARRAY_SIZE(q15_inputclip)); count++;
    riscv_clip_q15(q15_inputclip, out, (q15_t)0xC000u, (q15_t)0x4000u, ARRAY_SIZE(q15_inputclip)); count++;
    riscv_clip_q15(q15_inputclip, out, (q15_t)0x0CCDu, (q15_t)0x4000u, ARRAY_SIZE(q15_inputclip)); count++;
    riscv_and_u16(q15_bit1, q15_bit2, out_logical, logical_full); count++;
    riscv_or_u16(q15_bit1, q15_bit2, out_logical, logical_full); count++;
    riscv_not_u16(q15_bit1, out_logical, logical_full); count++;
    riscv_xor_u16(q15_bit1, q15_bit2, out_logical, logical_full); count++;
    printf("RUN testing-smoke/BasicMaths/q15 calls=%u\n", count);
    return count;
}

static unsigned run_q31(void)
{
    q31_t out[256];
    uint32_t out_logical[256];
    q63_t dot = 0;
    unsigned count = 0;
    const uint32_t full = min_u32(ARRAY_SIZE(q31_input1), ARRAY_SIZE(q31_ref));
    const uint32_t logical_full = min_u32(ARRAY_SIZE(q31_bit1), ARRAY_SIZE(q31_refand));
    touch_q63((q63_t)q31_ref[0]);
    touch_q63((q63_t)q31_refdot[0]);
    touch_q63((q63_t)q31_refand[0]);
    riscv_add_q31(q31_input1, q31_input2, out, 3); count++;
    riscv_sub_q31(q31_input1, q31_input2, out, 3); count++;
    riscv_mult_q31(q31_input1, q31_input2, out, 3); count++;
    riscv_negate_q31(q31_input1, out, 3); count++;
    riscv_offset_q31(q31_input1, (q31_t)0x40000000u, out, 3); count++;
    riscv_scale_q31(q31_input1, (q31_t)0x40000000u, 0, out, 3); count++;
    riscv_dot_prod_q31(q31_input1, q31_input2, 3, &dot); touch_q63((q63_t)dot); count++;
    riscv_abs_q31(q31_input1, out, 3); count++;
    riscv_and_u32(q31_bit1, q31_bit2, out_logical, 3); count++;
    riscv_or_u32(q31_bit1, q31_bit2, out_logical, 3); count++;
    riscv_not_u32(q31_bit1, out_logical, 3); count++;
    riscv_xor_u32(q31_bit1, q31_bit2, out_logical, 3); count++;
    riscv_add_q31(q31_input1, q31_input2, out, 8); count++;
    riscv_sub_q31(q31_input1, q31_input2, out, 8); count++;
    riscv_mult_q31(q31_input1, q31_input2, out, 8); count++;
    riscv_negate_q31(q31_input1, out, 8); count++;
    riscv_offset_q31(q31_input1, (q31_t)0x40000000u, out, 8); count++;
    riscv_scale_q31(q31_input1, (q31_t)0x40000000u, 0, out, 8); count++;
    riscv_dot_prod_q31(q31_input1, q31_input2, 8, &dot); touch_q63((q63_t)dot); count++;
    riscv_abs_q31(q31_input1, out, 8); count++;
    riscv_and_u32(q31_bit1, q31_bit2, out_logical, 8); count++;
    riscv_or_u32(q31_bit1, q31_bit2, out_logical, 8); count++;
    riscv_not_u32(q31_bit1, out_logical, 8); count++;
    riscv_xor_u32(q31_bit1, q31_bit2, out_logical, 8); count++;
    riscv_add_q31(q31_input1, q31_input2, out, 11); count++;
    riscv_sub_q31(q31_input1, q31_input2, out, 11); count++;
    riscv_mult_q31(q31_input1, q31_input2, out, 11); count++;
    riscv_negate_q31(q31_input1, out, 11); count++;
    riscv_offset_q31(q31_input1, (q31_t)0x40000000u, out, 11); count++;
    riscv_scale_q31(q31_input1, (q31_t)0x40000000u, 0, out, 11); count++;
    riscv_dot_prod_q31(q31_input1, q31_input2, 11, &dot); touch_q63((q63_t)dot); count++;
    riscv_abs_q31(q31_input1, out, 11); count++;
    riscv_and_u32(q31_bit1, q31_bit2, out_logical, 11); count++;
    riscv_or_u32(q31_bit1, q31_bit2, out_logical, 11); count++;
    riscv_not_u32(q31_bit1, out_logical, 11); count++;
    riscv_xor_u32(q31_bit1, q31_bit2, out_logical, 11); count++;
    riscv_add_q31(q31_input1, q31_input2, out, full); count++;
    riscv_sub_q31(q31_input1, q31_input2, out, full); count++;
    riscv_mult_q31(q31_input1, q31_input2, out, full); count++;
    riscv_negate_q31(q31_input1, out, full); count++;
    riscv_offset_q31(q31_input1, (q31_t)0x40000000u, out, full); count++;
    riscv_scale_q31(q31_input1, (q31_t)0x40000000u, 0, out, full); count++;
    riscv_dot_prod_q31(q31_input1, q31_input2, full, &dot); touch_q63((q63_t)dot); count++;
    riscv_abs_q31(q31_input1, out, full); count++;
    riscv_shift_q31(q31_inputrand, 1, out, ARRAY_SIZE(q31_inputrand)); count++;
    riscv_clip_q31(q31_inputclip, out, (q31_t)0xC0000000u, (q31_t)0xF3333333u, ARRAY_SIZE(q31_inputclip)); count++;
    riscv_clip_q31(q31_inputclip, out, (q31_t)0xC0000000u, (q31_t)0x40000000u, ARRAY_SIZE(q31_inputclip)); count++;
    riscv_clip_q31(q31_inputclip, out, (q31_t)0x0CCCCCCDu, (q31_t)0x40000000u, ARRAY_SIZE(q31_inputclip)); count++;
    riscv_and_u32(q31_bit1, q31_bit2, out_logical, logical_full); count++;
    riscv_or_u32(q31_bit1, q31_bit2, out_logical, logical_full); count++;
    riscv_not_u32(q31_bit1, out_logical, logical_full); count++;
    riscv_xor_u32(q31_bit1, q31_bit2, out_logical, logical_full); count++;
    printf("RUN testing-smoke/BasicMaths/q31 calls=%u\n", count);
    return count;
}

int main(void)
{
    printf("Start testing-smoke/BasicMaths pattern run\n");
    unsigned calls = run_q7() + run_q15() + run_q31();
    printf("PASS testing-smoke/BasicMaths calls=%u\n", calls);
    return 0;
}
