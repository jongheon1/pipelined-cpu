#ifndef __ALU_H__
#define __ALU_H__

#include "DigitalCircuit.h"

#include <cassert>

class ALU : public DigitalCircuit {

  public:

    ALU(const Wire<4> *iALUControl,
        const Wire<32> *iInput0,
        const Wire<32> *iInput1,
        Wire<32> *oOutput,
        Wire<1> *oZero) : DigitalCircuit("ALU") {
      _iALUControl = iALUControl;
      _iInput0 = iInput0;
      _iInput1 = iInput1;
      _oOutput = oOutput;
      _oZero = oZero;
    }

    virtual void advanceCycle() {
      /* FIXME */
    }

  private:

    const Wire<4> *_iALUControl;
    const Wire<32> *_iInput0;
    const Wire<32> *_iInput1;
    Wire<32> *_oOutput;
    Wire<1> *_oZero;

};

#endif

