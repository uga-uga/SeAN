find_package(ROOT REQUIRED)
find_package(GSL REQUIRED)

add_library(lib_ExcitedState ExcitedState.cc)

add_library(lib_Grid Grid.cc)
target_link_libraries(lib_Grid ${ROOT_LIBRARIES})

add_library(lib_Integrator Integrator.cc)
target_link_libraries(lib_Integrator ${GSL_LIBRARIES})

add_library(lib_Nucleus Nucleus.cc)
target_link_libraries(lib_Nucleus ${ROOT_LIBRARIES})
target_link_libraries(lib_Nucleus lib_Grid)
target_link_libraries(lib_Nucleus lib_VoigtProfile)

add_library(lib_Target Target.cc)

add_library(lib_VoigtProfile VoigtProfile.cc)
target_link_libraries(lib_VoigtProfile ${ROOT_LIBRARIES})