#include "instruction.h"
#include  <stdio.h>

void executeInstruction(const instruction *inst, vm *machine) {
    switch (inst->op) {
        case NOP:
            machine->programCounter++;
            break;
        case ADD: {
            int a = machine->registers[inst->operand1];
            int b = machine->registers[inst->operand2]; 
            machine->registers[registerA] = a + b; 
            machine->programCounter++;
            break;
        }
        case SUB: {
            int a = machine->registers[inst->operand1];
            int b = machine->registers[inst->operand2];
            machine->registers[registerA] = a - b;
            machine->programCounter++;
            break;
        }
        case MULT: {
            int a = machine->registers[inst->operand1];
            int b = machine->registers[inst->operand2];
            machine->registers[registerA] = a * b;
            machine->programCounter++;
            break;
        }
        case JUMPI: {
            if (machine->registers[registerA] != 0) {
                machine->programCounter = inst->operand1; 
            }
            break;
        }
        case CMP: {
            int a = machine->registers[inst->operand1];
            int b = machine->registers[inst->operand2];
            if (a == b){
                machine->registers[registerA] = 0;
            }
            if (a > b){
                machine->registers[registerA] = 1;
            }
            if (a < b){
                machine->registers[registerA] = 2;
            }
            machine->programCounter++;
            break;
        }
        case MOVER: {
            machine->memory[inst->operand2] = machine->registers[inst->operand1]; 
            machine->programCounter++;
            break;
        }
        case MOVEM: {
            machine->registers[inst->operand1] = machine->memory[inst->operand2]; 
            machine->programCounter++;
            break;
        }
        case LOAD: {
            machine->memory[inst->operand1] = inst->operand2; 
            machine->programCounter++;
            break;
        }
        case HALT:
            machine->running = 0;
            machine->programCounter = 0;
            break;
    }
}
void printInstruction(const instruction *inst) {
    if (inst->op == NOP) {
        return;
    } 
    switch (inst->op) {
        case NOP:
            break;
        case ADD:
            printf("adition (%d, %d)",
                inst->operand1, inst->operand2);
            break;    
        case SUB:
            printf("subtraction (%d, %d)",
                inst->operand1, inst->operand2);
            break;    
        case MULT:
            printf("multiply (%d, %d)",
                inst->operand1, inst->operand2);
            break;   
        case JUMPI:
            printf("jump if (%d)",inst->operand1);
            break;
        case CMP:
            printf("compare (%d, %d)",
                inst->operand1, inst->operand2);
            break;
        case MOVER:
            printf("move into register (%d, %d)",
                inst->operand1, inst->operand2);
            break; 
        case MOVEM:
            printf("move into memory (%d, %d)",
                inst->operand1, inst->operand2);
            break; 
        case LOAD:
            printf("load into memory (%d,%d)", inst->operand1, inst->operand2);
            break; 
        case HALT:
            printf("exit program");
            break; 
    }
}