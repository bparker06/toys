#pragma once

#include <cstdint>
#include <cstdlib>

uint32_t avx2_sumwords(uint16_t* array, size_t size);
uint32_t avx2_sumwords_variant2(uint16_t* array, size_t size);
