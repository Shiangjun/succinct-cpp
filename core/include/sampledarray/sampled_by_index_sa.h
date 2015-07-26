#ifndef SAMPLED_BY_INDEX_SA_H
#define SAMPLED_BY_INDEX_SA_H

#include "flat_sampled_array.h"

class SampledByIndexSA : public FlatSampledArray {
 public:
  // Constructor
  SampledByIndexSA(uint32_t sampling_rate, NPA *npa, bitmap_t *SA,
                   uint64_t sa_n, SuccinctAllocator &s_allocator);

  SampledByIndexSA(uint32_t sampling_rate, NPA *npa,
                   SuccinctAllocator &s_allocator);

  // Access element at index i
  virtual uint64_t operator[](uint64_t i);

 protected:
  // Sample original SA by index
  virtual void sample(bitmap_t *original, uint64_t n);
};

#endif