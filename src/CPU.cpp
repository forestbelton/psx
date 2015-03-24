#include <cstdint>

#include "CPU.h"
#include "Instruction.h"

static inline bool TEST(uint32_t x, uint8_t bit) {
    return x & (1 << bit);
}

uint32_t CPU::read(uint32_t addr) {
    return 0;
}

void CPU::step() {
    Instruction insn;
    insn.raw = this->read(this->pc);
    this->pc += 4;
    this->exec(insn);
}

void CPU::exec(const Instruction &insn) {
    switch(insn.op) {
        /* SPECIAL */
    case 0b000000:
        break;

    case 0b000001:
        switch(insn.imm.rt) {
            /* BLTZ */
        case 0b00000:
            if(TEST(this->reg[insn.imm.rs], 31)) {
                int32_t target = 4 * (int16_t)insn.imm.imm;
                this->pc += target;
            }
            break;

            /* BGEZ */
        case 0b00001:
            if(!TEST(this->reg[insn.imm.rs], 31)) {
                int32_t target = 4 * (int16_t)insn.imm.imm;
                this->pc += target;
            }
            break;

            /* BLTZAL */
        case 0b10000:
            break;

            /* BGEZAL */
        case 0b10001:
            break;
        }

        /* J */
    case 0b000010:
        break;

        /* JAL */
    case 0b000011:
        break;

        /* BEQ */
    case 0b000100:
        break;

        /* BNE */
    case 0b000101:
        break;
    }
}
