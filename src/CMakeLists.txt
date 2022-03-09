add_library (oo_amxx SHARED 
"../sdk/amxxmodule.cpp" "../sdk/amxxmodule.h"
"../sdk/moduleconfig.h"
"oo_amxx.cpp" "oo_amxx.h"
 "oo_data.h")


target_include_directories(oo_amxx PUBLIC "../sdk")

set_target_properties (oo_amxx PROPERTIES CMAKE_CXX_STANDARD 20)