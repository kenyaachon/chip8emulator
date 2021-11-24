/* #pragma once
#include "../Source/Chip8.hpp"
#include <cstring>

const unsigned int FONTSET_START_ADDRESS = 0x50;

//clear the display
//00E0: CLS
void Chip8::OP_00E0()
{
    memset(video, 0, sizeof(video));
}

//Return from a subroutine
//OOEE: RET
void Chip8::OP_00EE()
{
    --sp;
    ptcounter = stack[sp];
}

//Jump to location nnn
//The interpreter sets the program counter to nnn
//1nnnn: JP adddr
void Chip8::OP_1nnn()
{
    uint16_t address = optcode & 0x0FFFu;
    ptcounter = address;
}

//Call subroutine at nnn
//2nnn - CALL addr
void Chip8::OP_2nnn()
{
    uint16_t adddress = optcode & 0x0FFFu;

    stack[sp] = ptcounter;
    sp++;
    ptcounter = adddress;
}

//Skipx next instruction if Vx == kk
//3xkk - SE Vx, byte
void Chip8::OP_3xkk()
{
    uint8_t Vx = (optcode & 0x0F00u) >> 8u;
    uint8_t byte = optcode & 0x00FFu;

    if (registers[Vx] == byte)
    {
        ptcounter += 2;
    }
}

//Skipx next instruction if Vx != kk
//4xkk - SNE Vx, byte
void Chip8::OP_4xkk()
{
    uint8_t Vx = (optcode & 0x0F00u) >> 8u;
    uint8_t byte = optcode & 0x00FFu;

    if (registers[Vx] != byte)
    {
        ptcounter += 2;
    }
}

//Skip next instruction if Vx == Vy
//5xy0 - SE Vx, Vy
void Chip8::OP_5xy0()
{
    uint8_t Vx = (optcode & 0x0F00u) >> 8u;
    uint8_t Vy = (optcode & 0x00F0u) >> 4u;

    if (registers[Vx] == registers[Vy])
    {
        ptcounter += 2;
    }
}

//Set Vx == kk
//6xkk - LD Vx, byte
void Chip8::OP_6xkk()
{
    uint8_t Vx = (optcode & 0x0F00u) >> 8u;
    uint8_t byte = (optcode & 0x00FFu);

    registers[Vx] += byte;
}

//Set Vx = Vx + kk
//7xkk - ADD Vx, byte
void Chip8::OP_7xkk()
{
    uint8_t Vx = (optcode & 0x0F00u) >> 8u;
    uint8_t byte = optcode & 0x00FFu;

    registers[Vx] += byte;
}

//Set Vx = Vy
//8xy0 - LD Vx, Vy
void Chip8::OP_8xy0()
{
    uint8_t Vx = (optcode & 0x0F00u) >> 8u;
    uint8_t Vy = (optcode & 0x00F0u) >> 4u;

    registers[Vx] = registers[Vy];
}

//Set Vx = Vx OR Vy
// 8xy1 - OR Vx, Vy
void Chip8::OP_8xy1()
{
    uint8_t Vx = (optcode & 0x0F00u) >> 8u;
    uint8_t Vy = (optcode & 0x00F0u) >> 4u;

    registers[Vx] |= registers[Vy];
}

//Set Vx = Vx AND Vy
//8xy2 - AND Vx, Vy
void Chip8::OP_8xy2()
{
    uint8_t Vx = (optcode & 0x0F00u) >> 8u;
    uint8_t Vy = (optcode & 0x00F0u) >> 4u;

    registers[Vx] &= registers[Vy];
}

//Set Vx = Vx XOR Vy
//8xy3 - XOR Vx, Vy
void Chip8::OP_8xy3()
{
    uint8_t Vx = (optcode & 0x0F00u) >> 8u;
    uint8_t Vy = (optcode & 0x00F0u) >> 4u;

    registers[Vx] ^= registers[Vy];
}

// Set Vx = Vx + Vy, set VF = carry
// 8xy4 - ADD Vx, Vy
void Chip8::OP_8xy4()
{
    uint8_t Vx = (optcode & 0x0F00u) >> 8u;
    uint8_t Vy = (optcode & 0x00F0u) >> 4u;

    uint16_t sum = registers[Vx] + registers[Vy];

    if (sum > 255U)
    {
        registers[0xF] = 1;
    }
    else
    {
        registers[0xF] = 0;
    }

    registers[Vx] = sum & 0xFFu;
}

// Set Vx = Vx - VY, = NOT borrow
//8xy5 - SUB VX, VY
void Chip8::OP_8xy5()
{
    uint8_t Vx = (optcode & 0x0F00u) >> 8u;
    uint8_t Vy = (optcode & 0x00F0u) >> 4u;

    if (registers[Vx] > registers[Vy])
    {
        registers[0xF] = 1;
    }
    else
    {
        registers[0xF] = 0;
    }

    registers[Vx] -= registers[Vy];
}

//Set Vx = Vx SHR 1
//8xy6 - SHR Vx
void Chip8::OP_8xy6()
{
    uint8_t Vx = (optcode & 0x0F00u) >> 8u;

    //Save LSB in VF
    registers[0xF] = (registers[Vx] & 0x1u);

    registers[Vx] >>= 1;
}

//Set Vx = Vy- Vx, set VF = not borrow
//8xy7 - SUBN Vx, Vy
void Chip8::OP_8xy7()
{

    uint8_t Vx = (optcode & 0x0F00u) >> 8u;
    uint8_t Vy = (optcode & 0x00F0u) >> 4u;

    if (registers[Vy] > registers[Vx])
    {
        registers[0xF] = 1;
    }
    else
    {
        registers[0xF] = 0;
    }

    registers[Vx] = registers[Vy] - registers[Vx];
}

//Set Vx = Vx SHL 1
//8xyE - SHL Vx {, Vy}
void Chip8::OP_8xyE()
{
    uint8_t Vx = (optcode & 0x0F00u) >> 8u;

    //Save MSB in VF
    registers[0xF] = (registers[Vx] & 0x80u);

    registers[Vx] <<= 1;
}

// SKip next instruction if Vx != Vy
//9xy0 - SNE Vx, Vy
void Chip8::OP_9xy0()
{
    uint8_t Vx = (optcode & 0x0F00u) >> 8u;
    uint8_t Vy = (optcode & 0x00F0u) >> 4u;

    if (registers[Vx] != registers[Vy])
    {
        //move to the next instruction in the stack
        ptcounter += 2;
    }
}

//Set I = nnn
//Annn - LD I, addr
void Chip8::OP_Annn()
{
    uint16_t address = optcode & 0x0FFFu;

    index = address;
}

//Jump to location nnn + V0
//Bnnn - JP V0, addr
void Chip8::OP_Bnnn()
{
    uint16_t address = optcode & 0x0FFFu;

    ptcounter = registers[0] + address;
}

//Set Vx = random byte AND kk
void Chip8::OP_Cxkk()
{
    uint8_t Vx = (optcode & 0x0F00u) >> 8u;
    uint8_t byte = optcode & 0x00FFu;

    registers[Vx] = randByte(randGen) & byte;
}

//Display n-byte sprite starting at memory location
//I at (Vx, Vy), set VF = collision
void Chip8::OP_Dxyn()
{
    uint8_t Vx = (optcode & 0x0F00u) >> 8u;
    uint8_t Vy = (optcode & 0x00F0u) >> 4u;
    uint8_t height = optcode & 0x000Fu;

    //Wrap if going beyond screen boundaries
    uint8_t xPos = registers[Vx] % VIDEO_WIDTH;
    uint8_t yPos = registers[Vy] % VIDEO_HEIGHT;

    registers[0xF] = 0;

    for (unsigned int row = 0; row < height; row++)
    {
        uint8_t spriteByte = memory[index + row];

        for (unsigned int col = 0; col < 8; col++)
        {
            uint8_t spritePixel = spriteByte & (0x80u >> col);
            uint32_t *screenPixel = &video[(yPos + row) * VIDEO_WIDTH + (xPos + col)];

            //Sprite pixel is on
            if (spritePixel)
            {
                //Screen pixel also on - collision
                if (*screenPixel == 0xFFFFFFFF)
                {
                    registers[0xF] = 1;
                }

                // Effectively XOR with the sprite pixel
                *screenPixel ^= 0xFFFFFFFF;
            }
        }
    }
}

// Ex9E - SKP Vx
//SKip next instruction if key with the value of Vx is pressed
void Chip8::OP_Ex9E()
{
    uint8_t Vx = (optcode & 0x0F00u) >> 8u;
    uint8_t key = registers[Vx];

    if (keypad[key])
    {
        ptcounter += 2;
    }
}

// ExA1 - SKNP Vx
//SKip next instruction if key with the value of Vx is not pressed
void Chip8::OP_ExA1()
{
    uint8_t Vx = (optcode & 0x0F00u) >> 8u;
    uint8_t key = registers[Vx];

    if (!keypad[key])
    {
        ptcounter += 2;
    }
}

//Fx07 - LD Vx, DT
//Set Vx = delay timer value
void Chip8::OP_Fx07()
{
    uint8_t Vx = (optcode & 0x0F00u) >> 8u;

    registers[Vx] = delayTimer;
}

void Chip8::OP_Fx0A()
{
    uint8_t Vx = (optcode & 0x0F00u) >> 8u;

    if (keypad[0])
    {
        registers[Vx] = 0;
    }
    else if (keypad[1])
    {
        registers[Vx] = 1;
    }
    else if (keypad[2])
    {
        registers[Vx] = 2;
    }
    else if (keypad[3])
    {
        registers[Vx] = 3;
    }
    else if (keypad[4])
    {
        registers[Vx] = 4;
    }
    else if (keypad[5])
    {
        registers[Vx] = 5;
    }
    else if (keypad[6])
    {
        registers[Vx] = 6;
    }
    else if (keypad[7])
    {
        registers[Vx] = 7;
    }
    else if (keypad[8])
    {
        registers[Vx] = 8;
    }
    else if (keypad[9])
    {
        registers[Vx] = 9;
    }
    else if (keypad[10])
    {
        registers[Vx] = 10;
    }
    else if (keypad[11])
    {
        registers[Vx] = 11;
    }
    else if (keypad[12])
    {
        registers[Vx] = 12;
    }
    else if (keypad[13])
    {
        registers[Vx] = 13;
    }
    else if (keypad[14])
    {
        registers[Vx] = 14;
    }
    else if (keypad[15])
    {
        registers[Vx] = 15;
    }
    else
    {
        ptcounter -= 2;
    }
}

//Fx15 - LD DT, Vx
//Set delay timer = Vx
void Chip8::OP_Fx15()
{
    uint8_t Vx = (optcode & 0x0F00u) >> 8u;
    delayTimer = registers[Vx];
}

//Set sound timer = Vx
//Fx18 - LD ST, Vx
void Chip8::OP_Fx18()
{
    uint8_t Vx = (optcode & 0x0F00u) >> 8u;

    soundTimer = registers[Vx];
}

//Set I = I + Vx
//Fx1E - ADD I, Vx
void Chip8::OP_Fx1E()
{
    uint8_t Vx = (optcode & 0x0F00u) >> 8u;

    index += registers[Vx];
}

//Fx29 - LD F, Vx
//Set I = loca tion of sprite fro digit Vx
void Chip8::OP_Fx29()
{
    uint8_t Vx = (optcode & 0x0F00u) >> 8u;
    uint8_t digit = registers[Vx];

    index = FONTSET_START_ADDRESS + (5 * digit);
}

//Fx33 - LD B, Vx
//Store BCD representation of Vx in memory locations I, I+1, I+2
//intrepreter takes the decimal value of Vx, and places the hundred digits
// in memory at location in I, the tens digits at location I+1,
//and the ones digit at location I+2
void Chip8::OP_Fx33()
{
    uint8_t Vx = (optcode & 0x0F00u) >> 8u;
    uint8_t value = registers[Vx];

    //ones place
    memory[index + 2] = value % 10;
    value /= 10;

    //Tens place
    memory[index + 1] = value % 10;
    value /= 10;

    // Hundreds place
    memory[index] = value % 10;
}

//Fx55 - LD [I], Vx
//Store registers V0 through Vx in memory starting at
//location I
void Chip8::OP_Fx55()
{
    uint8_t Vx = (optcode & 0x0F00u) >> 8u;

    for (uint8_t i = 0; i <= Vx; i++)
    {
        memory[index + 1] = registers[i];
    }
}

//Fx65 - LD Vx, [I]
//Read registers V0 through Vx from memory starting at
//location I
void Chip8::OP_Fx65()
{
    uint8_t Vx = (optcode & 0x0F00u) >> 8u;

    for (uint8_t i = 0; i <= Vx; i++)
    {
        registers[i] = memory[index + i];
    }
} */

#include "Chip8.hpp"
#include <cstring>

const unsigned int FONTSET_START_ADDRESS = 0x50;

void Chip8::OP_00E0()
{
    memset(video, 0, sizeof(video));
}

void Chip8::OP_00EE()
{
    --sp;
    pc = stack[sp];
}

void Chip8::OP_1nnn()
{
    uint16_t address = opcode & 0x0FFFu;

    pc = address;
}

void Chip8::OP_2nnn()
{
    uint16_t address = opcode & 0x0FFFu;

    stack[sp] = pc;
    ++sp;
    pc = address;
}

void Chip8::OP_3xkk()
{
    uint8_t Vx = (opcode & 0x0F00u) >> 8u;
    uint8_t byte = opcode & 0x00FFu;

    if (registers[Vx] == byte)
    {
        pc += 2;
    }
}

void Chip8::OP_4xkk()
{
    uint8_t Vx = (opcode & 0x0F00u) >> 8u;
    uint8_t byte = opcode & 0x00FFu;

    if (registers[Vx] != byte)
    {
        pc += 2;
    }
}

void Chip8::OP_5xy0()
{
    uint8_t Vx = (opcode & 0x0F00u) >> 8u;
    uint8_t Vy = (opcode & 0x00F0u) >> 4u;

    if (registers[Vx] == registers[Vy])
    {
        pc += 2;
    }
}

void Chip8::OP_6xkk()
{
    uint8_t Vx = (opcode & 0x0F00u) >> 8u;
    uint8_t byte = opcode & 0x00FFu;

    registers[Vx] = byte;
}

void Chip8::OP_7xkk()
{
    uint8_t Vx = (opcode & 0x0F00u) >> 8u;
    uint8_t byte = opcode & 0x00FFu;

    registers[Vx] += byte;
}

void Chip8::OP_8xy0()
{
    uint8_t Vx = (opcode & 0x0F00u) >> 8u;
    uint8_t Vy = (opcode & 0x00F0u) >> 4u;

    registers[Vx] = registers[Vy];
}

void Chip8::OP_8xy1()
{
    uint8_t Vx = (opcode & 0x0F00u) >> 8u;
    uint8_t Vy = (opcode & 0x00F0u) >> 4u;

    registers[Vx] |= registers[Vy];
}

void Chip8::OP_8xy2()
{
    uint8_t Vx = (opcode & 0x0F00u) >> 8u;
    uint8_t Vy = (opcode & 0x00F0u) >> 4u;

    registers[Vx] &= registers[Vy];
}

void Chip8::OP_8xy3()
{
    uint8_t Vx = (opcode & 0x0F00u) >> 8u;
    uint8_t Vy = (opcode & 0x00F0u) >> 4u;

    registers[Vx] ^= registers[Vy];
}

void Chip8::OP_8xy4()
{
    uint8_t Vx = (opcode & 0x0F00u) >> 8u;
    uint8_t Vy = (opcode & 0x00F0u) >> 4u;

    uint16_t sum = registers[Vx] + registers[Vy];

    if (sum > 255U)
    {
        registers[0xF] = 1;
    }
    else
    {
        registers[0xF] = 0;
    }

    registers[Vx] = sum & 0xFFu;
}

void Chip8::OP_8xy5()
{
    uint8_t Vx = (opcode & 0x0F00u) >> 8u;
    uint8_t Vy = (opcode & 0x00F0u) >> 4u;

    if (registers[Vx] > registers[Vy])
    {
        registers[0xF] = 1;
    }
    else
    {
        registers[0xF] = 0;
    }

    registers[Vx] -= registers[Vy];
}

void Chip8::OP_8xy6()
{
    uint8_t Vx = (opcode & 0x0F00u) >> 8u;

    // Save LSB in VF
    registers[0xF] = (registers[Vx] & 0x1u);

    registers[Vx] >>= 1;
}

void Chip8::OP_8xy7()
{
    uint8_t Vx = (opcode & 0x0F00u) >> 8u;
    uint8_t Vy = (opcode & 0x00F0u) >> 4u;

    if (registers[Vy] > registers[Vx])
    {
        registers[0xF] = 1;
    }
    else
    {
        registers[0xF] = 0;
    }

    registers[Vx] = registers[Vy] - registers[Vx];
}

void Chip8::OP_8xyE()
{
    uint8_t Vx = (opcode & 0x0F00u) >> 8u;

    // Save MSB in VF
    registers[0xF] = (registers[Vx] & 0x80u) >> 7u;

    registers[Vx] <<= 1;
}

void Chip8::OP_9xy0()
{
    uint8_t Vx = (opcode & 0x0F00u) >> 8u;
    uint8_t Vy = (opcode & 0x00F0u) >> 4u;

    if (registers[Vx] != registers[Vy])
    {
        pc += 2;
    }
}

void Chip8::OP_Annn()
{
    uint16_t address = opcode & 0x0FFFu;

    index = address;
}

void Chip8::OP_Bnnn()
{
    uint16_t address = opcode & 0x0FFFu;

    pc = registers[0] + address;
}

void Chip8::OP_Cxkk()
{
    uint8_t Vx = (opcode & 0x0F00u) >> 8u;
    uint8_t byte = opcode & 0x00FFu;

    registers[Vx] = randByte(randGen) & byte;
}

void Chip8::OP_Dxyn()
{
    uint8_t Vx = (opcode & 0x0F00u) >> 8u;
    uint8_t Vy = (opcode & 0x00F0u) >> 4u;
    uint8_t height = opcode & 0x000Fu;

    // Wrap if going beyond screen boundaries
    uint8_t xPos = registers[Vx] % VIDEO_WIDTH;
    uint8_t yPos = registers[Vy] % VIDEO_HEIGHT;

    registers[0xF] = 0;

    for (unsigned int row = 0; row < height; ++row)
    {
        uint8_t spriteByte = memory[index + row];

        for (unsigned int col = 0; col < 8; ++col)
        {
            uint8_t spritePixel = spriteByte & (0x80u >> col);
            uint32_t *screenPixel = &video[(yPos + row) * VIDEO_WIDTH + (xPos + col)];

            // Sprite pixel is on
            if (spritePixel)
            {
                // Screen pixel also on - collision
                if (*screenPixel == 0xFFFFFFFF)
                {
                    registers[0xF] = 1;
                }

                // Effectively XOR with the sprite pixel
                *screenPixel ^= 0xFFFFFFFF;
            }
        }
    }
}

void Chip8::OP_Ex9E()
{
    uint8_t Vx = (opcode & 0x0F00u) >> 8u;

    uint8_t key = registers[Vx];

    if (keypad[key])
    {
        pc += 2;
    }
}

void Chip8::OP_ExA1()
{
    uint8_t Vx = (opcode & 0x0F00u) >> 8u;

    uint8_t key = registers[Vx];

    if (!keypad[key])
    {
        pc += 2;
    }
}

void Chip8::OP_Fx07()
{
    uint8_t Vx = (opcode & 0x0F00u) >> 8u;

    registers[Vx] = delayTimer;
}

void Chip8::OP_Fx0A()
{
    uint8_t Vx = (opcode & 0x0F00u) >> 8u;

    if (keypad[0])
    {
        registers[Vx] = 0;
    }
    else if (keypad[1])
    {
        registers[Vx] = 1;
    }
    else if (keypad[2])
    {
        registers[Vx] = 2;
    }
    else if (keypad[3])
    {
        registers[Vx] = 3;
    }
    else if (keypad[4])
    {
        registers[Vx] = 4;
    }
    else if (keypad[5])
    {
        registers[Vx] = 5;
    }
    else if (keypad[6])
    {
        registers[Vx] = 6;
    }
    else if (keypad[7])
    {
        registers[Vx] = 7;
    }
    else if (keypad[8])
    {
        registers[Vx] = 8;
    }
    else if (keypad[9])
    {
        registers[Vx] = 9;
    }
    else if (keypad[10])
    {
        registers[Vx] = 10;
    }
    else if (keypad[11])
    {
        registers[Vx] = 11;
    }
    else if (keypad[12])
    {
        registers[Vx] = 12;
    }
    else if (keypad[13])
    {
        registers[Vx] = 13;
    }
    else if (keypad[14])
    {
        registers[Vx] = 14;
    }
    else if (keypad[15])
    {
        registers[Vx] = 15;
    }
    else
    {
        pc -= 2;
    }
}

void Chip8::OP_Fx15()
{
    uint8_t Vx = (opcode & 0x0F00u) >> 8u;

    delayTimer = registers[Vx];
}

void Chip8::OP_Fx18()
{
    uint8_t Vx = (opcode & 0x0F00u) >> 8u;

    soundTimer = registers[Vx];
}

void Chip8::OP_Fx1E()
{
    uint8_t Vx = (opcode & 0x0F00u) >> 8u;

    index += registers[Vx];
}

void Chip8::OP_Fx29()
{
    uint8_t Vx = (opcode & 0x0F00u) >> 8u;
    uint8_t digit = registers[Vx];

    index = FONTSET_START_ADDRESS + (5 * digit);
}

void Chip8::OP_Fx33()
{
    uint8_t Vx = (opcode & 0x0F00u) >> 8u;
    uint8_t value = registers[Vx];

    // Ones-place
    memory[index + 2] = value % 10;
    value /= 10;

    // Tens-place
    memory[index + 1] = value % 10;
    value /= 10;

    // Hundreds-place
    memory[index] = value % 10;
}

void Chip8::OP_Fx55()
{
    uint8_t Vx = (opcode & 0x0F00u) >> 8u;

    for (uint8_t i = 0; i <= Vx; ++i)
    {
        memory[index + i] = registers[i];
    }
}

void Chip8::OP_Fx65()
{
    uint8_t Vx = (opcode & 0x0F00u) >> 8u;

    for (uint8_t i = 0; i <= Vx; ++i)
    {
        registers[i] = memory[index + i];
    }
}
