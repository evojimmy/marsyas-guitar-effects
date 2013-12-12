#include <marsyas/system/MarSystemManager.h>
#include "Cutoff.h"
#include "RepeatSine.h"
#include "ApproachSquare.h"

using namespace std;
using namespace Marsyas;
using namespace MarsyasGuitarEffects;

void sfplay (string name, mrs_real amount) {
  MarSystemManager mng;

  MarSystem* net = mng.create("Series", "net");
  net->updControl("mrs_real/israte", 48000.0);

  //net->addMarSystem(mng.create("SoundFileSource", "src"));
  //net->updctrl("SoundFileSource/src/mrs_string/filename", sfName);
  net->addMarSystem(mng.create("AudioSource", "src"));
  net->updControl("AudioSource/src/mrs_bool/initAudio", true);
  //net->updControl("AudioSource/src/mrs_natural/nChannels", 1);

  if (name == "Cutoff") {
    MarSystem* distortion = new Cutoff("distortion");
    distortion->updctrl("mrs_real/amount", amount);
    net->addMarSystem(distortion);
  } else if (name == "RepeatSine") {
    MarSystem* distortion = new RepeatSine("distortion");
    distortion->updctrl("mrs_natural/amount", (mrs_natural)amount);
    net->addMarSystem(distortion);
  } else if (name == "ApproachSquare") {
    MarSystem* distortion = new ApproachSquare("distortion");
    distortion->updctrl("mrs_natural/amount", (mrs_natural)amount);
    net->addMarSystem(distortion);
  }


  net->addMarSystem(mng.create("AudioSink", "dest"));
  //net->addMarSystem(mng.create("SoundFileSink", "dest"));

  net->updctrl("AudioSink/dest/mrs_bool/initAudio", true);
  //net->updctrl("SoundFileSink/dest/mrs_string/filename", "out.wav");

  //while (net->getctrl("SoundFileSource/src/mrs_bool/hasData")->to<mrs_bool>() ) {
  while (true) {
    net->tick();
  }
  delete net;
}


int main (int argc, const char **argv) {

  string name = argv[1];
  mrs_real amount = atof(argv[2]);

  sfplay(name, amount);
  exit(0);
}
