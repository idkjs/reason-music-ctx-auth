

import * as Curry from "bs-platform/lib/es6/curry.js";
import * as React from "react";
import * as Hub$ReasonMusicCtx from "./aws/Hub.bs.js";
import * as Home$ReasonMusicCtx from "./auth/Home.bs.js";
import * as Logger$ReasonMusicCtx from "./aws/Logger.bs.js";
import * as UserContext$ReasonMusicCtx from "./auth/UserContext.bs.js";

function reducer(param, action) {
  if (action) {
    return /* record */[/* user : LoggedIn */[action[0]]];
  } else {
    return /* record */[/* user : Anonymous */0];
  }
}

function App(Props) {
  var match = React.useReducer(reducer, /* record */[/* user : Anonymous */0]);
  var dispatch = match[1];
  var logger = Logger$ReasonMusicCtx.createLogger("UserProvider", /* Info */2, /* () */0);
  var listener = function (data) {
    Logger$ReasonMusicCtx.log(logger, /* Info */2, "listening for auth events...");
    var message = data.payload.message;
    logger.info("listening for auth events...");
    var userJs = data.payload.data;
    var $$event = Hub$ReasonMusicCtx.eventFromString(data.payload.event);
    switch ($$event) {
      case /* SignIn */0 :
          Logger$ReasonMusicCtx.logO(logger, /* Info */2, message);
          var userData_001 = /* username */userJs.username;
          var userData_002 = /* id */userJs.attributes.sub;
          var userData_003 = /* email */userJs.attributes.email;
          var userData = /* record */[
            /* isLoggedIn */true,
            userData_001,
            userData_002,
            userData_003
          ];
          return Curry._1(dispatch, /* UserLoggedIn */[userData]);
      case /* SignOut */2 :
          Logger$ReasonMusicCtx.logO(logger, /* Info */2, message);
          return Curry._1(dispatch, /* UserLoggedOut */0);
      case /* SignUp */1 :
      case /* SignIn_failure */3 :
      case /* Configured */4 :
          return Logger$ReasonMusicCtx.logO(logger, /* Info */2, message);
      case /* Unknown */5 :
          console.log("unknown error", data);
          return /* () */0;
      
    }
  };
  React.useEffect((function () {
          Hub$ReasonMusicCtx.listen(/* Auth */1, listener);
          return (function (param) {
                    return Hub$ReasonMusicCtx.remove(/* Auth */1, listener);
                  });
        }), /* array */[]);
  return React.createElement(UserContext$ReasonMusicCtx.Provider.make, UserContext$ReasonMusicCtx.Provider.makeProps(/* tuple */[
                  match[0][/* user */0],
                  dispatch
                ], React.createElement(Home$ReasonMusicCtx.make, { }), /* () */0));
}

var make = App;

export {
  reducer ,
  make ,
  
}
/* react Not a pure module */
