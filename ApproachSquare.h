#ifndef MARSYAS_GUITAR_EFFECTS_APPROACHSQUARE_H
#define MARSYAS_GUITAR_EFFECTS_APPROACHSQUARE_H

#include <marsyas/system/MarSystem.h>

using namespace Marsyas;

namespace MarsyasGuitarEffects
{
/**
        \class ApproachSquare
        \ingroup Distortion
        \brief Let wave be more likely to square wave.
        \input wave samples
        \output wave samples
        \control mrs_natural/amount 0~+Infinity: higher amount => more distortion
*/


  class ApproachSquare : public MarSystem
  {
  private:
    mrs_natural amount_;

    MarControlPtr ctrl_amount_;

    void addControls (void);
    void myUpdate (MarControlPtr);

    mrs_natural _amount_;

  public:
    ApproachSquare (std::string name);
    ~ApproachSquare (void);

    MarSystem* clone (void) const;

    void myProcess (realvec& in, realvec& out);

  };

} // namespace

#endif
