#pragma once

#define registerA 0


#define registerCount 3
#define ramSize 16
#define instructionSize 256

#define emptyInstruction {0,0,0}

typedef unsigned char opcode;
typedef unsigned char byte;

typedef struct instruction{
    opcode op : 4;
    byte operand1 : 8;
    byte operand2 : 8;
}instruction;


typedef struct vm{
    int programCounter;
    byte registers[registerCount];
    byte memory[ramSize];
    instruction instructions[instructionSize];
    int running;
}vm;