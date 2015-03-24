#ifndef PSX_CPU_H_
#define PSX_CPU_H_

#include <cstdint>

class CPU {
 private:
  uint32_t reg[32];
  uint32_t pc, hi, lo;

 public:
  void exec(uint32_t insn);
};

#endif
