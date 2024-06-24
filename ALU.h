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
      // 0b0000: AND
      // 0b0001: OR
      // 0b0010: ADD
      // 0b0110: SUB
      // 0b0111: SLT
      // 0b1100: NOR
      // set _oOutput and _oZero
      // set _oZero to 1 if the output is zero
      _oOutput->reset();
      _oZero->reset();
      switch (_iALUControl->to_ulong())
      {
      case 0b0000:
        *_oOutput = (*_iInput0) & (*_iInput1);
        if (_oOutput->none()) 
          _oZero->set();
        break;
      case 0b0001:
        *_oOutput = (*_iInput0) | (*_iInput1);
        if (_oOutput->none()) 
          _oZero->set();
        break;
      case 0b0010:
        *_oOutput = _iInput0->to_ulong() + _iInput1->to_ulong();
        if (_oOutput->none()) 
          _oZero->set();
        break;
      case 0b0110:
        *_oOutput = _iInput0->to_ulong() - _iInput1->to_ulong();
        if (_oOutput->none()) 
          _oZero->set();
        break;
      case 0b0111:
        *_oOutput = _iInput0->to_ulong() < _iInput1->to_ulong() ? 1 : 0;
        if (_oOutput->none()) 
          _oZero->set();
        break;
      case 0b1100:
        *_oOutput = ~((*_iInput0) | (*_iInput1));
        if (_oOutput->none()) 
          _oZero->set();
        break;
      default:
        assert(false);
      }

    }

  private:

    const Wire<4> *_iALUControl;
    const Wire<32> *_iInput0;
    const Wire<32> *_iInput1;
    Wire<32> *_oOutput;
    Wire<1> *_oZero;

};

#endif

