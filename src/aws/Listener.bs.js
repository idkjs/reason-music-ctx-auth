

import * as React from "react";
import * as Hub$ReasonMusicCtx from "./Hub.bs.js";
import * as Auth$ReasonMusicCtx from "./Auth.bs.js";

function logger(str) {
  console.log(str);
  return /* () */0;
}

function useListerner(param) {
  var listener = function (data) {
    console.log("listener_hubCallback", data);
    var $$event = Hub$ReasonMusicCtx.eventFromString(data.payload.event);
    console.log("listener_hubCallback_event", $$event);
    switch ($$event) {
      case /* SignIn */0 :
          console.log("profile_logger_msg: user signed in");
          return /* () */0;
      case /* SignUp */1 :
          console.log("profile_logger_msg: user signed up");
          return /* () */0;
      case /* SignOut */2 :
          console.log("profile_logger_msg: user signed out");
          return /* () */0;
      case /* SignIn_failure */3 :
          console.log("profile_logger_msg: user sign in failed");
          return /* () */0;
      case /* Configured */4 :
          console.log("profile_logger_msg: the Auth module is configured");
          return /* () */0;
      case /* Unknown */5 :
          console.log("unknown error");
          return /* () */0;
      
    }
  };
  React.useEffect((function () {
          Auth$ReasonMusicCtx.checkUser(/* () */0);
          Hub$ReasonMusicCtx.listen(/* Auth */1, listener);
          return (function (param) {
                    return Hub$ReasonMusicCtx.remove(/* Auth */1, listener);
                  });
        }), /* array */[]);
  return /* () */0;
}

export {
  logger ,
  useListerner ,
  
}
/* react Not a pure module */
