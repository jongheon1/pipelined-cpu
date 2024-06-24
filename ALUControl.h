#ifndef __ALU_CONTROL_H__
#define __ALU_CONTROL_H__

#include "DigitalCircuit.h"

#include <cassert>

class ALUControl : public DigitalCircuit {

  public:

    ALUControl(const Wire<2> *iALUOp,
               const Wire<6> *iFunct,
               Wire<4> *oOperation) : DigitalCircuit("ALUControl") {
      _iALUOp = iALUOp;
      _iFunct = iFunct;
      _oOperation = oOperation;
    }

    virtual void advanceCycle() {
      // ALUOp         Funct field         Operation
      // ALUOp1 ALUOp0 F5 F4 F3 F2 F1 F0
      //   0      0    X  X  X  X  X  X    0010
      //   X      1    X  X  X  X  X  X    0110
      //   1      X    X  X  0  0  0  0    0010
      //   1      X    X  X  0  0  1  0    0110
      //   1      X    X  X  0  1  0  0    0000
      //   1      X    X  X  0  1  0  1    0001
      //   1      X    X  X  1  0  1  0    0111
      _oOperation->reset();

      bool ALUOp0 = _iALUOp->test(0);
      bool ALUOp1 = _iALUOp->test(1);

      if (!ALUOp1 && !ALUOp0) {
        *_oOperation = 0b0010;
      } else if (ALUOp0) {
        *_oOperation = 0b0110;
      } else if (ALUOp1) {
        std::bitset<4> funct = _iFunct->to_ulong() & 0b001111;
        switch (funct.to_ulong()) {
        case 0b0000:
          *_oOperation = 0b0010;
          break;
        case 0b0010:
          *_oOperation = 0b0110;
          break;
        case 0b0100:
          *_oOperation = 0b0000;
          break;
        case 0b0101:
          *_oOperation = 0b0001;
          break;
        case 0b1010:
          *_oOperation = 0b0111;
          break;
        default:
          break;
        }
      }

    }

  private:

    const Wire<2> *_iALUOp;
    const Wire<6> *_iFunct;
    Wire<4> *_oOperation;

};

#endif

