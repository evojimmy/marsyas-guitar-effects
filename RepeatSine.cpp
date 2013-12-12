#include "RepeatSine.h"

using namespace std;
using namespace Marsyas;
using namespace MarsyasGuitarEffects;

RepeatSine::RepeatSine (mrs_string name): MarSystem("RepeatSine", name)
{
  amount_ = 0;
  addControls();
}


RepeatSine::~RepeatSine (void)
{
}

MarSystem* RepeatSine::clone (void) const
{
  return new RepeatSine(*this);
}

void RepeatSine::addControls (void)
{
  addctrl("mrs_natural/amount", 0, ctrl_amount_);

  setctrlState("mrs_natural/amount", true);
}

void RepeatSine::myUpdate (MarControlPtr sender)
{
  (void) sender;
  amount_ = ctrl_amount_->to<mrs_natural>();
}

void RepeatSine::myProcess (realvec& in, realvec& out)
{
  mrs_natural t, o, i;

  for (o = 0; o < inObservations_; o++ ) {

    mrs_real max(0.0001);  // in case input is silent
    for (t = 0; t < inSamples_; t++ ) {
      mrs_real comp = abs(in(o, t));
      if (comp > max) {
        max = comp;
      }
    }
    //mrs_real norm(0.0);
    //for (t = 0; t < inSamples_; t++ ) {
    //  norm += out(o, t) * out(o, t);
    //}
    //norm = sqrt(norm);

    for (t = 0; t < inSamples_; t++ ) {
      out(o, t) = in(o, t) / max;
      for (i = 0; i < amount_; i++ ) {
        out(o, t) = sin(out(o, t));
      }
    }

    for (t = 0; t < inSamples_; t++ ) {
      out(o, t) *= max;
    }
  }
}
