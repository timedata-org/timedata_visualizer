# cython: embedsignature=True
# cython: infer_types=True
#
# See http://docs.cython.org/en/latest/src/reference/compilation.html

include "src/timedata_visualizer/base/base.pyx"
include "src/timedata_visualizer/base/callbacks.pyx"
include "src/timedata_visualizer/base/stl.pyx"
include "src/timedata_visualizer/base/has_return.pyx"
include "src/timedata_visualizer/base/timestamp.pyx"
include "src/timedata_visualizer/base/wrapper.pyx"
include "src/timedata_visualizer/juce/ProcessGlobal.pyx"
include "src/timedata_visualizer/juce/CallPython.pyx"
include "src/timedata_visualizer/juce/commands.pyx"

include "build/genfiles/timedata_visualizer/genfiles.pyx"

include "src/timedata_visualizer/component/LightWindow.pyx"
include "src/timedata_visualizer/juce/JuceApplication.pyx"
include "src/timedata_visualizer/juce/proxy.pyx"

print_startup_message()
