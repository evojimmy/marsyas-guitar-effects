# your files
SOURCES = main.cpp
HEADERS += Cutoff.h
SOURCES += Cutoff.cpp
HEADERS += RepeatSine.h
SOURCES += RepeatSine.cpp
HEADERS += ApproachSquare.h
SOURCES += ApproachSquare.cpp

MARSYAS_INSTALL_DIR = /home/jimmy/mir/marsyas/build
#INCLUDEPATH += /home/jimmy/mir/marsyas/src/marsyas/
LIBPATH += /home/jimmy/mir/marsyas/build/lib/

### if installed elsewhere
#MARSYAS_INSTALL_DIR = /usr/local
#MARSYAS_INSTALL_DIR = ${HOME}/usr/
#INCLUDEPATH += $$MARSYAS_INSTALL_DIR/marsyas/
#LIBPATH += $$MARSYAS_INSTALL_DIR/lib/
### basic OS stuff; do not change!
win32-msvc2005:LIBS += marsyas.lib
unix:LIBS += -lmarsyas -L$$MARSYAS_INSTALL_DIR/lib -ljack
!macx:LIBS += -lasound
macx:LIBS += -framework CoreAudio -framework CoreMidi -framework CoreFoundation
