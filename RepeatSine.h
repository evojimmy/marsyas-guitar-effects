#ifndef MARSYAS_GUITAR_EFFECTS_REPEATSINE_H
#define MARSYAS_GUITAR_EFFECTS_REPEATSINE_H

#include <marsyas/system/MarSystem.h>

using namespace Marsyas;

namespace MarsyasGuitarEffects
{
/**
        \class RepeatSine
        \ingroup Distortion
        \brief A slight overdrive.
        \input wave samples
        \output wave samples
        \control mrs_natural/amount 0~+Infinity: higher amount => more distortion. Recommend value: 75~100.
*/


  class RepeatSine : public MarSystem
  {
  private:
    mrs_natural amount_;

    MarControlPtr ctrl_amount_;

    void addControls (void);
    void myUpdate (MarControlPtr);

  public:
    RepeatSine (std::string name);
    ~RepeatSine (void);

    MarSystem* clone (void) const;

    void myProcess (realvec& in, realvec& out);

  };

} // namespace

#endif
