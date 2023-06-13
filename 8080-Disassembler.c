#include <stdio.h>
#include <stdlib.h>

int Disassemble8080Op(unsigned char *codebuffer, int pc){
    unsigned char *codeSeg = &codebuffer[pc];
    int opBytes = 1;
    printf("%04x: %02x:   ",pc,*codeSeg);
    switch (*codeSeg) // ML = Memory location NOT value, VAL = Value at memory location
    {
    case 0x00: printf("NOP"); break; // No operation
    case 0x01: printf("LXI      B,#$%02x%02x",codeSeg[2],codeSeg[1]); opBytes=3; break; // Moves byte 3 to register B (ML), moves byte 2 to register C (ML)
    case 0x02: printf("STAX     B"); break; // The value of register A (ML) is copied to memory at the address of register pair BC (VAL)
    case 0x03: printf("INX      B"); break; // Register pair (BC) is incremented as a 16-bit number (ML) (by 1)
    case 0x04: printf("INR      B"); break; // Register B is incremented by 1 (ML)
    case 0x05: printf("DCR      B"); break; // Register B is decremented (ML)
    case 0x06: printf("MVI      B,#$%02x", codeSeg[1]); opBytes=2; break; // Moves the value of byte 2 to the memory at register B (ML)
    case 0x07: printf("RLC"); break; // Content of register A is shifted left one bit (ML). The lowest order bit of register A's content is set to whatever bit was shifted out and flag CY is set to this bit (ML).
    case 0x08: printf("NOP"); break; // No operation
    case 0x09: printf("DAD      B"); break; // The register pair BC (ML) is added to the HL register pair (ML)
    case 0x0a: printf("LDAX     B"); break; // The content found at register pair BC (VAL) is copied into register A (ML)
    case 0x0b: printf("DCX      B"); break; // Decrements the register pair BC (ML)
    case 0x0c: printf("INR      C"); break; // Register C is incremented by 1 (ML)
    case 0x0d: printf("DCR      C"); break; // Register C is decremented by 1 (ML)
    case 0x0e: printf("MVI      C,#$%02x", codeSeg[1]); opBytes=2; break; // Moves the value of byte 2 to the memory at register C (ML)
    case 0x0f: printf("RRC"); break; // Content of register A is shifted right one bit (ML). The highest order bit of register A is set to whatever bit was shifted out and flag CY is set to this bit (ML).
    case 0x10: printf("NOP"); break; // No operation
    case 0x11: printf("LXI      D,#$%02x%02x",codeSeg[2],codeSeg[1]); opBytes=3; break; // Moves byte 3 to register D (ML), moves byte 2 to register E (ML)
    case 0x12: printf("STAX     D"); break; // The value of register A (ML) is copied to memory at the address of register pair DE (VAL)
    case 0x13: printf("INX      D"); break; // Register pair (DE) is incremented as a 16-bit number (ML) (by 1)
    case 0x14: printf("INR      D"); break; // Register D is incremented by 1 (ML)
    case 0x15: printf("DCR      D"); break; // Register D is decremented (ML)
    case 0x16: printf("MVI      D,#$%02x", codeSeg[1]); opBytes=2; break; // Moves the value of byte 2 to the memory at register D (ML)
    case 0x17: printf("RAL"); break; // Content of register A is shifted left 1 bit (ML). The lowest order bit of register A's content is set to the previous flag CY (ML). The flag CY is set to the bit shifted out (ML).
    case 0x18: printf("NOP"); break; // No operation
    case 0x19: printf("DAD      D"); break; // The register pair DE is added to the HL register pair (ML)
    case 0x1a: printf("LDAX     D"); break; // The content found at register pair DE (VAL) is copied into register A (ML)
    case 0x1b: printf("DCX      D"); break; // Decrements the register pair DE (ML)
    case 0x1c: printf("INR      E"); break; // Register E is incremented by 1 (ML)
    case 0x1d: printf("DCR      E"); break; // Register E is decremented (ML)
    case 0x1e: printf("MVI      E,#$%02x", codeSeg[1]); opBytes=2; break; // Moves the value of byte 2 to the memory at register E (ML)
    case 0x1f: printf("RAR"); break; // Content of register A is shifted right one bit (ML). The highest order bit of register A is set to what it was before being shifted (IE value of bit 6) and flag CY is set to the bit shifted out(ML).
    case 0x20: printf("NOP"); break; // No operation
    case 0x21: printf("LXI      H,#$%02x%02x",codeSeg[2],codeSeg[1]); opBytes=3; break; // Moves byte 3 to register H (ML), moves byte 2 to register L (ML)
    case 0x22: printf("SHLD     $%02x%02x",codeSeg[2],codeSeg[1]); opBytes=3; break; // Content of register L (ML) is copied into the memory pointed to by adr (VAL), content of register H (ML) is copied into the memory pointed to by adr+1 (VAL) 
    case 0x23: printf("INX      H"); break; // Register pair (HL) is incremented as a 16-bit number (ML) (by 1)
    case 0x24: printf("INR      H"); break; // Register H is incremented by 1 (ML)
    case 0x25: printf("DCR      H"); break; // Register H is decremented (ML)
    case 0x26: printf("MVI      H,#$%02x", codeSeg[1]); opBytes=2; break; // Moves the value of byte 2 to the memory at register H (ML)
    case 0x27: printf("DAA"); break; // Special opcode
    case 0x28: printf("NOP"); break; // No operation
    case 0x29: printf("DAD      H"); break; // The register pair HL is added to the HL register pair (ML)
    case 0x2a: printf("LHLD     $%02x%02x",codeSeg[2],codeSeg[1]); opBytes=3; break; // Copies the value found at adr (VAL) into register L (ML), Copies the value found at adr+1 (VAL) into register H (ML)
    case 0x2b: printf("DCX      H"); break; // Decrements the register pair HL (ML)
    case 0x2c: printf("INR      L"); break; // Register L is incremented by 1 (ML)
    case 0x2d: printf("DCR      L"); break; // Register L is decremented (ML)
    case 0x2e: printf("MVI      L,#$%02x", codeSeg[1]); opBytes=2; break; // Moves the value of byte 2 to the memory at register L (ML)
    case 0x2f: printf("CMA"); break; // The register A (ML) is given the value of !A (Not a) (ML)
    case 0x30: printf("NOP"); break; // No operation
    case 0x31: printf("LXI      SP,#$%02x%02x",codeSeg[2],codeSeg[1]); opBytes=3; break; // Moves byte 3 to the high order of register pair SP (Stack pointer) (ML), moves byte 2 to the low order of register pair SP (Stack pointer) (ML)
    case 0x32: printf("STA      $%02x%02x",codeSeg[2],codeSeg[1]); opBytes=3; break; // Copies register A (ML) to the value of the given adress (Byte 2 and 3) (VAL)
    case 0x33: printf("INX      SP"); break; // Register pair (SP - Stack pointer) is incremented as a 16-bit number (ML) (by 1)
    case 0x34: printf("INR      M"); break; // Register pair HL (Val) is incremented by 1
    case 0x35: printf("DCR      M"); break; // Register pair HL (Val) is decremented by 1
    case 0x36: printf("MVI      M,#$%02x", codeSeg[1]); opBytes=2; break; // Moves the value of byte 2 to the value at register HL (VAL)
    case 0x37: printf("STC"); break; // CY flag is set to 1
    case 0x38: printf("NOP"); break; // No operation
    case 0x39: printf("DAD      SP"); break; // The register pair SP is added to the HL register pair (ML)
    case 0x3a: printf("LDA      $%02x%02x",codeSeg[2],codeSeg[1]); opBytes=3; break; // Copies the value found at adr (VAL) into register A (ML)
    case 0x3b: printf("DCX      SP"); break; // Decrements the register pair SP by 1 (ML)
    case 0x3c: printf("INR      A"); break; // Register A (ML) is incremented by 1
    case 0x3d: printf("DCR      A"); break; // Register A (ML) is decremented by 1
    case 0x3e: printf("MVI      A,#$%02x", codeSeg[1]); opBytes=2; break; // Moves the value of byte 2 to the memory at register A (ML)
    case 0x3f: printf("CMC"); break; // The register flag CY (ML) is given the value of !CY (Not CY) (ML)
    case 0x40: printf("MOV      B,B"); break; // Copies register B (ML) into register B (ML) 
    case 0x41: printf("MOV      B,C"); break; // Copies register C (ML) into register B (ML) 
    case 0x42: printf("MOV      B,D"); break; // Copies register D (ML) into register B (ML) 
    case 0x43: printf("MOV      B,E"); break; // Copies register E (ML) into register B (ML) 
    case 0x44: printf("MOV      B,H"); break; // Copies register H (ML) into register B (ML) 
    case 0x45: printf("MOV      B,L"); break; // Copies register L (ML) into register B (ML) 
    case 0x46: printf("MOV      B,M"); break; // Copies register pair HL (VAL) into register B (ML) 
    case 0x47: printf("MOV      B,A"); break; // Copies register A (ML) into register B (ML) 
    case 0x48: printf("MOV      C,B"); break; // Copies register B (ML) into register C (ML) 
    case 0x49: printf("MOV      C,C"); break; // Copies register C (ML) into register C (ML) 
    case 0x4a: printf("MOV      C,D"); break; // Copies register D (ML) into register C (ML) 
    case 0x4b: printf("MOV      C,E"); break; // Copies register E (ML) into register C (ML) 
    case 0x4c: printf("MOV      C,H"); break; // Copies register H (ML) into register C (ML) 
    case 0x4d: printf("MOV      C,L"); break; // Copies register L (ML) into register C (ML) 
    case 0x4e: printf("MOV      C,M"); break; // Copies register pair HL (VAL) into register C (ML) 
    case 0x4f: printf("MOV      C,A"); break; // Copies register A (ML) into register C (ML) 
    case 0x50: printf("MOV      D,B"); break; // Copies register B (ML) into register D (ML) 
    case 0x51: printf("MOV      D,C"); break; // Copies register C (ML) into register D (ML) 
    case 0x52: printf("MOV      D,D"); break; // Copies register D (ML) into register D (ML) 
    case 0x53: printf("MOV      D,E"); break; // Copies register E (ML) into register D (ML) 
    case 0x54: printf("MOV      D,H"); break; // Copies register H (ML) into register D (ML) 
    case 0x55: printf("MOV      D,L"); break; // Copies register L (ML) into register D (ML) 
    case 0x56: printf("MOV      D,M"); break; // Copies register pair HL (VAL) into register D (ML) 
    case 0x57: printf("MOV      D,A"); break; // Copies register A (ML) into register D (ML)
    case 0x58: printf("MOV      E,B"); break; // Copies register B (ML) into register E (ML) 
    case 0x59: printf("MOV      E,C"); break; // Copies register C (ML) into register E (ML) 
    case 0x5a: printf("MOV      E,D"); break; // Copies register D (ML) into register E (ML) 
    case 0x5b: printf("MOV      E,E"); break; // Copies register E (ML) into register E (ML) 
    case 0x5c: printf("MOV      E,H"); break; // Copies register H (ML) into register E (ML) 
    case 0x5d: printf("MOV      E,L"); break; // Copies register L (ML) into register E (ML) 
    case 0x5e: printf("MOV      E,M"); break; // Copies register pair HL (VAL) into register E (ML) 
    case 0x5f: printf("MOV      E,A"); break; // Copies register A (ML) into register E (ML)
    case 0x60: printf("MOV      H,B"); break; // Copies register B (ML) into register H (ML) 
    case 0x61: printf("MOV      H,C"); break; // Copies register C (ML) into register H (ML) 
    case 0x62: printf("MOV      H,D"); break; // Copies register D (ML) into register H (ML) 
    case 0x63: printf("MOV      H,E"); break; // Copies register E (ML) into register H (ML) 
    case 0x64: printf("MOV      H,H"); break; // Copies register H (ML) into register H (ML) 
    case 0x65: printf("MOV      H,L"); break; // Copies register L (ML) into register H (ML) 
    case 0x66: printf("MOV      H,M"); break; // Copies register pair HL (VAL) into register H (ML) 
    case 0x67: printf("MOV      H,A"); break; // Copies register A (ML) into register H (ML)
    case 0x68: printf("MOV      L,B"); break; // Copies register B (ML) into register L (ML) 
    case 0x69: printf("MOV      L,C"); break; // Copies register C (ML) into register L (ML) 
    case 0x6a: printf("MOV      L,D"); break; // Copies register D (ML) into register L (ML) 
    case 0x6b: printf("MOV      L,E"); break; // Copies register E (ML) into register L (ML) 
    case 0x6c: printf("MOV      L,H"); break; // Copies register H (ML) into register L (ML) 
    case 0x6d: printf("MOV      L,L"); break; // Copies register L (ML) into register L (ML) 
    case 0x6e: printf("MOV      L,M"); break; // Copies register pair HL (VAL) into register L (ML) 
    case 0x6f: printf("MOV      L,A"); break; // Copies register A (ML) into register L (ML)
    case 0x70: printf("MOV      M,B"); break; // Copies register B (ML) into register pair HL (VAL) 
    case 0x71: printf("MOV      M,C"); break; // Copies register C (ML) into register pair HL (VAL) 
    case 0x72: printf("MOV      M,D"); break; // Copies register D (ML) into register pair HL (VAL) 
    case 0x73: printf("MOV      M,E"); break; // Copies register E (ML) into register pair HL (VAL) 
    case 0x74: printf("MOV      M,H"); break; // Copies register H (ML) into register pair HL (VAL) 
    case 0x75: printf("MOV      M,L"); break; // Copies register L (ML) into register pair HL (VAL) 
    case 0x76: printf("HLT"); break; // Processor gets halted and won't commence until the next interrupt
    case 0x77: printf("MOV      M,A"); break; // Copies register A (ML) into register pair HL (VAL) 
    case 0x78: printf("MOV      A,B"); break; // Copies register B (ML) into register A (ML) 
    case 0x79: printf("MOV      A,C"); break; // Copies register C (ML) into register A (ML) 
    case 0x7a: printf("MOV      A,D"); break; // Copies register D (ML) into register A (ML) 
    case 0x7b: printf("MOV      A,E"); break; // Copies register E (ML) into register A (ML) 
    case 0x7c: printf("MOV      A,H"); break; // Copies register H (ML) into register A (ML) 
    case 0x7d: printf("MOV      A,L"); break; // Copies register L (ML) into register A (ML) 
    case 0x7e: printf("MOV      A,M"); break; // Copies register pair HL (VAL) into register A (ML) 
    case 0x7f: printf("MOV      A,A"); break; // Copies register A (ML) into register A (ML)

    }
    printf("\n");
    return opBytes;
}
  

int main(int argc, char *argv[])
{
    FILE *fp;
    unsigned char *buffer=0;
    long length;
    int pc=0;
    if(argc==2){
        fp = fopen(argv[1],"r");
        fseek(fp,0,SEEK_END);
        length = ftell(fp);
        fseek(fp,0,SEEK_SET);
        buffer = (unsigned char*)malloc(length*sizeof(unsigned char));
        if(buffer!=0){
            fread(buffer,1,length,fp);
            while(pc<length){
                pc = pc + Disassemble8080Op(buffer,pc);
            }
            free(buffer);
        }
        fclose(fp);
    }
    else{
        printf("Invalid Number of Arguments");
        return 0;
    }
  
    return 0;
}