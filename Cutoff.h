#ifndef MARSYAS_GUITAR_EFFECTS_CUTOFF_H
#define MARSYAS_GUITAR_EFFECTS_CUTOFF_H

#include <marsyas/system/MarSystem.h>

using namespace Marsyas;

namespace MarsyasGuitarEffects
{
/**
        \class Cutoff
        \ingroup Distortion
        \brief Set up threshold and cut input signals.
        \input wave samples
        \output wave samples
        \control mrs_real/amount -Infinity~+Infinity: higher amount => more distortion
*/


  class Cutoff : public MarSystem
  {
  private:
    mrs_real amount_;

    MarControlPtr ctrl_amount_;

    void addControls (void);
    void myUpdate (MarControlPtr);

  public:
    Cutoff (std::string name);
    ~Cutoff (void);

    MarSystem* clone (void) const;

    void myProcess (realvec& in, realvec& out);

  };

} // namespace

#endif
