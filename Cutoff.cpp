#include "Cutoff.h"

using namespace std;
using namespace Marsyas;
using namespace MarsyasGuitarEffects;

Cutoff::Cutoff (mrs_string name): MarSystem("Cutoff", name)
{
  amount_ = 0.0;
  addControls();
}


Cutoff::~Cutoff (void)
{
}

MarSystem* Cutoff::clone (void) const
{
  return new Cutoff(*this);
}

void Cutoff::addControls (void)
{
  addctrl("mrs_real/amount", 0.0, ctrl_amount_);

  setctrlState("mrs_real/amount", true);
}

void Cutoff::myUpdate (MarControlPtr sender)
{
  amount_ = ctrl_amount_->to<mrs_real>();
  MarSystem::myUpdate(sender);
}

void Cutoff::myProcess (realvec& in, realvec& out)
{
  mrs_natural t, o;

  for (o = 0; o < inObservations_; o++ ) {
    mrs_real norm(0.0);
    for (t = 0; t < inSamples_; t++ ) {
      norm += in(o, t) * in(o, t);
    }
    norm = sqrt(norm);
    mrs_real cut = (1 - amount_) / 100 * norm;
    mrs_real minuscut = -cut;
    for (t = 0; t < inSamples_; t++ ) {
      mrs_real temp = in(o, t);
      if (temp > cut) {
        out(o, t) = cut;
      } else if (temp < minuscut) {
        out(o, t) = minuscut;
      } else {
        out(o, t) = in(o, t);
      }
    }
  }
}
