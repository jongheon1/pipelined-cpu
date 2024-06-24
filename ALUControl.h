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
      /* FIXME */
    }

  private:

    const Wire<2> *_iALUOp;
    const Wire<6> *_iFunct;
    Wire<4> *_oOperation;

};

#endif

