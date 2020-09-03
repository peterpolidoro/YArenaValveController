// ----------------------------------------------------------------------------
// YArenaValveController.h
//
//
// Authors:
// Peter Polidoro peterpolidoro@gmail.com
// ----------------------------------------------------------------------------
#ifndef Y_ARENA_VALVE_CONTROLLER_H
#define Y_ARENA_VALVE_CONTROLLER_H
#include <ArduinoJson.h>
#include <JsonStream.h>
#include <Array.h>
#include <Vector.h>
#include <ConstantVariable.h>
#include <Functor.h>

#include <ModularServer.h>
#include <ModularDeviceBase.h>

#include "YArenaValveController/Constants.h"


class YArenaValveController : public ModularDeviceBase
{
public:
  YArenaValveController();
  virtual void setup();

  void setValve(size_t arm,
    size_t valve);

private:
  modular_server::Pin pins_[y_arena_valve_controller::constants::PIN_COUNT_MAX];

  modular_server::Property properties_[y_arena_valve_controller::constants::PROPERTY_COUNT_MAX];
  modular_server::Parameter parameters_[y_arena_valve_controller::constants::PARAMETER_COUNT_MAX];
  modular_server::Function functions_[y_arena_valve_controller::constants::FUNCTION_COUNT_MAX];
  modular_server::Callback callbacks_[y_arena_valve_controller::constants::CALLBACK_COUNT_MAX];

  void setValveOff(size_t arm,
    size_t valve);
  void setValveOn(size_t arm,
    size_t valve);
  void setAllValvesOff(size_t arm);
  void setValves(ArduinoJson::JsonArray & valves);

  // Handlers
  void setValvesHandler();

};

#endif
