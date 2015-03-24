#ifndef PSX_INSTRUCTION_H_
#define PSX_INSTRUCTION_H_

union Instruction {
    uint32_t raw;

    struct {
        union {
            unsigned funct : 6;
            unsigned shamt : 5;
            unsigned rd : 5;
            unsigned rt : 5;
            unsigned rs : 5;
        } reg;

        union {
            unsigned imm : 16;
            unsigned rt : 5;
            unsigned rs : 5;
        } imm;

        union {
            unsigned addr : 26;
        } jump;

        unsigned op : 6;
    };
};

#endif
