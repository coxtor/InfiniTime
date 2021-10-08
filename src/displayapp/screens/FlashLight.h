#pragma once

#include <cstdint>
#include "Screen.h"
#include <lvgl/lvgl.h>
#include "systemtask/SystemTask.h"
#include "components/brightness/BrightnessController.h"
#include <displayapp/Colors.h>
namespace Pinetime {

  namespace Applications {
    namespace Screens {

      class FlashLight : public Screen {
      public:
        FlashLight(DisplayApp* app, System::SystemTask& systemTask, Controllers::BrightnessController& brightness, Controllers::Settings &settingsController);
        ~FlashLight() override;

        bool OnTouchEvent(Pinetime::Applications::TouchEvents event) override;

      private:
        Pinetime::System::SystemTask& systemTask;
        Controllers::BrightnessController& brightness;
        Controllers::Settings& settingsController;

        lv_obj_t* backgroundAction;
        Colors torchColors[11] = {Colors::White,                              
                                  Colors::Gray,
                                  Colors::Red,
                                  Colors::Yellow,
                                  Colors::Green,
                                  Colors::Cyan,
                                  Colors::Teal,
                                  Colors::Navy,
                                  Colors::Magenta,
                                  Colors::Orange,
                                  Colors::Black};
        int8_t currentColorIndex;
      };
    }
  }
}
