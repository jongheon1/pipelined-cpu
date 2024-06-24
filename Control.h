#ifndef __CONTROL_H__
#define __CONTROL_H__

#include "DigitalCircuit.h"

class Control : public DigitalCircuit {

  public:

    Control(const Wire<6> *iOpcode,
            Wire<1> *oRegDst,
            Wire<1> *oALUSrc,
            Wire<1> *oMemToReg,
            Wire<1> *oRegWrite,
            Wire<1> *oMemRead,
            Wire<1> *oMemWrite,
            Wire<1> *oBranch,
            Wire<2> *oALUOp) : DigitalCircuit("Control") {
      _iOpcode = iOpcode;
      _oRegDst = oRegDst;
      _oALUSrc = oALUSrc;
      _oMemToReg = oMemToReg;
      _oRegWrite = oRegWrite;
      _oMemRead = oMemRead;
      _oMemWrite = oMemWrite;
      _oBranch = oBranch;
      _oALUOp = oALUOp;
    }

    virtual void advanceCycle() {
          // Implement truth table
          // Instruction    RegDst  ALUSrc  MemtoReg    RegWrite    MemRead MemWrite    Branch  ALUOp1  ALUOp0
          // R-format         1       0        0           1         0        0         0       1       0
          //   lw             0       1        1           1         1        0         0       0       0
          //   sw             X       1        X           0         0        1         0       0       0
          //  beq             X       0        X           0         0        0         1       0       1

          _oRegDst->reset();
          _oALUSrc->reset();
          _oMemToReg->reset();
          _oRegWrite->reset();
          _oMemRead->reset();
          _oMemWrite->reset();
          _oBranch->reset();
          _oALUOp->reset();        

          std::bitset<6> opcode = *_iOpcode;

        switch (opcode.to_ulong()) {
            case 0b000000:  // R-format (add, sub, and, or, nor, slt)
                _oRegDst->set();
                _oRegWrite->set();
                _oALUOp->set(1);
                break;
            case 0b100011:  // lw
                _oALUSrc->set();
                _oMemToReg->set();
                _oRegWrite->set();
                _oMemRead->set();
                break;
            case 0b101011:  // sw
                _oALUSrc->set();
                _oMemWrite->set();
                break;
            case 0b000100:  // beq
                _oBranch->set();
                _oALUOp->set(0);
                break;
            case 0b001000:  // addi
                _oALUSrc->set();
                _oRegWrite->set();
                break;
        }
      }
    

  private:

    const Wire<6> *_iOpcode;
    Wire<1> *_oRegDst;
    Wire<1> *_oALUSrc;
    Wire<1> *_oMemToReg;
    Wire<1> *_oRegWrite;
    Wire<1> *_oMemRead;
    Wire<1> *_oMemWrite;
    Wire<1> *_oBranch;
    Wire<2> *_oALUOp;

};

#endif

