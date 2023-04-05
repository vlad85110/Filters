cmake_minimum_required(VERSION 3.24)
project(filters)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")

set(CMAKE_PREFIX_PATH "/Users/vladkirilov/Qt/6.4.2/macos/lib/cmake:/Users/vladkirilov/CLionProjects/filters/src")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

include_directories("src")

add_executable(filters src/main.cpp src/ui/MainWindow.cpp src/ui/MainWindow.h src/instrument/Instrument.h src/canvas/Canvas.cpp src/canvas/Canvas.h src/ui/button/instrument/FilterAction.cpp src/ui/button/instrument/FilterAction.h src/ui/button/ToolBarAction.cpp src/ui/button/ToolBarAction.h src/instrument/single_pixel/gray_scale/GrayScaleFilter.cpp src/instrument/single_pixel/gray_scale/GrayScaleFilter.h src/ui/navigation/ToolBarWidget.cpp src/ui/navigation/ToolBarWidget.h src/instrument/factory/InstrumentFactory.cpp src/instrument/factory/InstrumentFactory.h src/types.h src/instrument/factory/InstrumentCreator.h src/instrument/single_pixel/SinglePixelFilter.cpp src/instrument/single_pixel/SinglePixelFilter.h src/instrument/single_pixel/negative/NegativeFilter.cpp src/instrument/single_pixel/negative/NegativeFilter.h src/canvas/CanvasState.h src/instrument/matrix/AbstractMatrixFilter.cpp src/instrument/matrix/AbstractMatrixFilter.h src/instrument/matrix/smoothing/SmoothingFilter.cpp src/instrument/matrix/smoothing/SmoothingFilter.h src/instrument/matrix/sharpness/SharpnessFilter.cpp src/instrument/matrix/sharpness/SharpnessFilter.h src/ui/menu/MenuWidget.cpp src/ui/menu/MenuWidget.h src/ui/config/InstrumentForm.cpp src/ui/config/InstrumentForm.h src/ui/config/gray_scale/GrayScaleFilterForm.cpp src/ui/config/gray_scale/GrayScaleFilterForm.h src/ui/navigation/filter/FilterGroup.cpp src/ui/navigation/filter/FilterGroup.h src/ui/config/input/DoubleWithErrorLabel.cpp src/ui/config/input/DoubleInputWithErrorLabel.h src/ui/config/input/DoubleNumSlider.cpp src/ui/config/input/DoubleNumSlider.h src/ui/navigation/rendering/RenderingGroup.cpp src/ui/navigation/rendering/RenderingGroup.h src/instrument/matrix/embossing/EmbossingFilter.cpp src/instrument/matrix/embossing/EmbossingFilter.h src/instrument/single_pixel/gamma/GammaFilter.cpp src/instrument/single_pixel/gamma/GammaFilter.h src/instrument/AbstractFilter.cpp src/instrument/AbstractFilter.h src/instrument/highlight/roberts/RobertsFilter.cpp src/instrument/highlight/roberts/RobertsFilter.h src/instrument/highlight/sobel/SobelFilter.cpp src/instrument/highlight/sobel/SobelFilter.h src/canvas/ImageSizeState.h src/ui/navigation/resize/ResizeGroup.cpp src/ui/navigation/resize/ResizeGroup.h src/ui/button/resize/ResizeAction.cpp src/ui/button/resize/ResizeAction.h src/ui/config/gamma/GammaFilterForm.cpp src/ui/config/gamma/GammaFilterForm.h src/ui/navigation/AbstractActionGroup.cpp src/ui/navigation/AbstractActionGroup.h src/instrument/matrix/watercolor/WatercolorFilter.cpp src/instrument/matrix/watercolor/WatercolorFilter.h src/instrument/matrix/median/MedianFilter.cpp src/instrument/matrix/median/MedianFilter.h src/instrument/dither/FloydSteinbergDither.cpp src/instrument/dither/FloydSteinbergDither.h src/ui/config/input/InputWithErrorLabel.cpp src/ui/config/input/InputWithErrorLabel.h src/ui/config/smoothing/SmoothingFilterForm.cpp src/ui/config/smoothing/SmoothingFilterForm.h src/ui/config/embossing/EmbossingFilterForm.cpp src/ui/config/embossing/EmbossingFilterForm.h src/instrument/highlight/HighlightFilter.cpp src/instrument/highlight/HighlightFilter.h src/ui/config/highlight/HighlightFilterForm.cpp src/ui/config/highlight/HighlightFilterForm.h src/instrument/dither/AbstractDither.cpp src/instrument/dither/AbstractDither.h src/ui/config/dither/DitherForm.cpp src/ui/config/dither/DitherForm.h src/instrument/dither/OrderedDither.cpp src/instrument/dither/OrderedDither.h src/instrument/rotation/ImageRotation.cpp src/instrument/rotation/ImageRotation.h src/ui/config/rotation/ImageRotationForm.cpp src/ui/config/rotation/ImageRotationForm.h src/instrument/vertical/VerticalPhotoFilter.cpp src/instrument/vertical/VerticalPhotoFilter.h src/ui/CentralWidget.cpp src/ui/CentralWidget.h src/ui/navigation/file/FileGroup.cpp src/ui/navigation/file/FileGroup.h src/ui/button/file/FileAction.cpp src/ui/button/file/FileAction.h src/ui/button/file/open/OpenFileAction.cpp src/ui/button/file/open/OpenFileAction.h src/ui/button/file/save/SaveFileAction.cpp src/ui/button/file/save/SaveFileAction.h src/ui/button/about/AboutAction.cpp src/ui/button/about/AboutAction.h src/ui/navigation/help/HelpGroup.cpp src/ui/navigation/help/HelpGroup.h src/instrument/matrix/radian_blur/RadianBlur.cpp src/instrument/matrix/radian_blur/RadianBlur.h src/ui/config/vertical/VerticalPhotoForm.cpp src/ui/config/vertical/VerticalPhotoForm.h src/ui/button/transform/TransformAction.cpp src/ui/button/transform/TransformAction.h src/ui/navigation/transform/TransformGroup.cpp src/ui/navigation/transform/TransformGroup.h)
target_link_libraries(filters
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )
