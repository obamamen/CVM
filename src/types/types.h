#pragma once

#define registerA 0
#define registerB 1
#define registerC 2

#define registerCount 3
#define ramSize 1024
#define instructionSize 4096

#define emptyInstruction {0,0,0}

typedef unsigned char opcode;

typedef struct instruction{
    opcode op;
    unsigned char operands[2];
}instruction;



typedef unsigned char byte;

typedef struct vm{
    int programCounter;
    int registers[registerCount];
    byte memory[ramSize];
    instruction instructions[instructionSize];
    int running;
}vm;