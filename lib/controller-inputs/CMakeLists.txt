add_library(AnalogBusIn STATIC)
target_sources(AnalogBusIn PRIVATE src/AnalogBusIn.cpp)
target_include_directories(AnalogBusIn PUBLIC include)
target_set_mbed_dependency(AnalogBusIn)

add_library(AnalogInputGroup STATIC)
target_sources(AnalogInputGroup PRIVATE src/AnalogInputGroup.cpp)
target_include_directories(AnalogInputGroup PUBLIC include)
target_link_libraries(AnalogInputGroup PRIVATE AnalogBusIn)
target_set_mbed_dependency(AnalogInputGroup)

add_library(DigitalInputGroup STATIC)
target_sources(DigitalInputGroup PRIVATE src/DigitalInputGroup.cpp)
target_include_directories(DigitalInputGroup PUBLIC include)
target_link_libraries(DigitalInputGroup PRIVATE AnalogBusIn)
target_set_mbed_dependency(DigitalInputGroup)

add_library(FrameController STATIC)
target_sources(FrameController PRIVATE src/FrameController.cpp)
target_include_directories(FrameController PUBLIC include)
target_link_libraries(FrameController PRIVATE AnalogInputGroup DigitalInputGroup)
target_set_mbed_dependency(FrameController)

