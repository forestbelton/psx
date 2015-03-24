#ifndef PSX_CPU_H_
#define PSX_CPU_H_

#include "Instruction.h"
#include <cstdint>

class CPU {
 private:
  uint32_t reg[32];
  uint32_t pc, hi, lo;

  uint32_t read(uint32_t addr);
  void exec(const Instruction& insn);

 public:
  void step(void);
};

#endif
