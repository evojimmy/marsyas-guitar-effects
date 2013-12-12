#include "ApproachSquare.h"

using namespace std;
using namespace Marsyas;
using namespace MarsyasGuitarEffects;

ApproachSquare::ApproachSquare (mrs_string name): MarSystem("ApproachSquare", name)
{
  amount_ = 0;
  addControls();
}


ApproachSquare::~ApproachSquare (void)
{
}

MarSystem* ApproachSquare::clone (void) const
{
  return new ApproachSquare(*this);
}

void ApproachSquare::addControls (void)
{
  addctrl("mrs_natural/amount", 0, ctrl_amount_);

  setctrlState("mrs_natural/amount", true);
}

void ApproachSquare::myUpdate (MarControlPtr sender)
{
  (void) sender;
  amount_ = ctrl_amount_->to<mrs_natural>();
  _amount_ = amount_ * 2 + 2;
}

void ApproachSquare::myProcess (realvec& in, realvec& out)
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

    for (t = 0; t < inSamples_; t++) {
      mrs_real inter_value = (in(o, t) / max);
      inter_value = asin(inter_value);

      mrs_real out_value(0.0);
      for (i = 1; i < _amount_; i += 2) {
        out_value += sin(i * inter_value) / i;
      }
      out(o, t) = out_value * max * 2.0 / PI;
    }

  }
}
