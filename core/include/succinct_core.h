#ifndef SUCCINCT_CORE_H
#define SUCCINCT_CORE_H

#include <vector>
#include <fstream>

#include "npa/elias_delta_encoded_npa.h"
#include "npa/elias_gamma_encoded_npa.h"
#include "npa/npa.h"
#include "npa/wavelet_tree_encoded_npa.h"
#include "sampledarray/flat_sampled_array.h"
#include "sampledarray/layered_sampled_array.h"
#include "sampledarray/layered_sampled_isa.h"
#include "sampledarray/layered_sampled_sa.h"
#include "sampledarray/opportunistic_layered_sampled_array.h"
#include "sampledarray/opportunistic_layered_sampled_isa.h"
#include "sampledarray/opportunistic_layered_sampled_sa.h"
#include "sampledarray/sampled_by_index_isa.h"
#include "sampledarray/sampled_by_index_sa.h"
#include "sampledarray/sampled_by_value_isa.h"
#include "sampledarray/sampled_by_value_sa.h"
#include "succinct_base.h"
#include "utils/divsufsortxx.h"
#include "utils/divsufsortxx_utility.h"

typedef enum {
  CONSTRUCT_IN_MEMORY = 0,
  CONSTRUCT_MEMORY_MAPPED = 1,
  LOAD_IN_MEMORY = 2,
  LOAD_MEMORY_MAPPED = 3
} SuccinctMode;

class SuccinctCore : public SuccinctBase {
 public:
  typedef std::map<char, std::pair<uint64_t, uint32_t>> AlphabetMap;
  typedef std::pair<int64_t, int64_t> Range;

  /* Constructors */
  SuccinctCore(const char *filename, SuccinctMode s_mode =
                   SuccinctMode::CONSTRUCT_IN_MEMORY,
               uint32_t sa_sampling_rate = 32, uint32_t isa_sampling_rate = 32,
               uint32_t npa_sampling_rate = 128, uint32_t context_len = 3,
               SamplingScheme sa_sampling_scheme =
                   SamplingScheme::FLAT_SAMPLE_BY_INDEX,
               SamplingScheme isa_sampling_scheme =
                   SamplingScheme::FLAT_SAMPLE_BY_INDEX,
               NPA::NPAEncodingScheme npa_encoding_scheme =
                   NPA::NPAEncodingScheme::ELIAS_GAMMA_ENCODED,
               uint32_t sampling_range = 1024);

  virtual ~SuccinctCore() {
  }

  /* Lookup functions for each of the core data structures */
  // Lookup NPA at index i
  uint64_t LookupNPA(uint64_t i);

  // Lookup SA at index i
  uint64_t LookupSA(uint64_t i);

  // Lookup ISA at index i
  uint64_t LookupISA(uint64_t i);

  // Get index of value v in C
  uint64_t LookupC(uint64_t val);

  char CharAt(uint64_t i);

  // Serialize succinct data structures
  virtual size_t Serialize();

  // Deserialize succinct data structures
  virtual size_t Deserialize();

  // Memory map succinct data structures
  virtual size_t MemoryMap();

  // Get size of original input
  uint64_t GetOriginalSize();

  // Get succinct core size
  virtual size_t StorageSize();

  virtual void PrintStorageBreakdown();

  // Get SA
  SampledArray *GetSA();

  // Get ISA
  SampledArray *GetISA();

  // Get NPA
  NPA *GetNPA();

  // Get alphabet
  char *GetAlphabet();

  inline int Compare(std::string mgram, int64_t pos);
  inline int Compare(std::string mgram, int64_t pos, size_t offset);

  Range BwdSearch(std::string mgram);
  Range ContinueBwdSearch(std::string mgram, Range range);

  Range FwdSearch(std::string mgram);
  Range ContinueFwdSearch(std::string mgram, Range range, size_t len);

 protected:

  /* Metadata */
  std::string filename_;               // Name of input file
  std::string succinct_path_;          // Name of succinct path
  uint64_t input_size_;                // Size of input

  /* Primary data structures */
  SampledArray *sa_;                   // Suffix Array
  SampledArray *isa_;                  // Inverse Suffix Array
  NPA *npa_;                           // Next Pointer Array
  std::vector<uint64_t> Cinv_idx_;     // Indexes into Cinv;

  /* Auxiliary data structures */
  char *alphabet_;
  AlphabetMap alphabet_map_;
  uint32_t alphabet_size_;             // Size of the input alphabet_

 private:
  /* Construct functions */
  // Create all auxiliary data structures
  void ConstructAuxiliary(BitMap *compactSA, const char *data);

  // Parent Construct function
  void Construct(const char* filename, uint32_t sa_sampling_rate,
                 uint32_t isa_sampling_rate, uint32_t npa_sampling_rate,
                 uint32_t context_len, SamplingScheme sa_sampling_scheme,
                 SamplingScheme isa_sampling_scheme,
                 NPA::NPAEncodingScheme npa_encoding_scheme,
                 uint32_t sampling_range);

  // Helper functions
  bool CompareDataBitmap(BitMap *T, uint64_t i, uint64_t j, uint64_t k);
  uint64_t GetContextValue(BitMap *T, uint32_t i);

  bool IsSampled(uint64_t i);
};
#endif