#include <cstdint>

#include "CPU.h"
#include "Instruction.h"

uint32_t CPU::read(uint32_t addr) {
    return 0;
}

void CPU::step() {
    Instruction op;
    op.raw = this->read(this->pc);
    this->exec(op);
}

void CPU::exec(const Instruction &op) {

}
