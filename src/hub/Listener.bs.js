

import * as React from "react";
import * as Hub$ReasonMusicCtx from "./Hub.bs.js";
import * as Auth$ReasonMusicCtx from "../aws/Auth.bs.js";

function logger(str) {
  console.log(str);
  return /* () */0;
}

function useListerner(param) {
  var listener = function (data) {
    console.log("listener_hubCallback", data);
    var payload = data.payload;
    console.log("payload", payload.event);
    var $$event = payload.event;
    console.log("listener_hubCallback_event", $$event);
    switch ($$event) {
      case "configured" :
          console.log("profile_logger_msg: the Auth module is configured");
          return /* () */0;
      case "signIn" :
          console.log("profile_logger_msg: user signed in");
          return /* () */0;
      case "signIn_failure" :
          console.log("profile_logger_msg: user sign in failed");
          return /* () */0;
      case "signOut" :
          console.log("profile_logger_msg: user signed out");
          return /* () */0;
      case "signUp" :
          console.log("profile_logger_msg: user signed up");
          return /* () */0;
      default:
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
